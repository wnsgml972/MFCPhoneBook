﻿#include "stdafx.h"
#include "FileManager.h"
#include "PhoneBook.h"
#include "Person.h"



//////////////////////////////////////////////////////////////////////////
// 멤버 함수 아님!
string FileManager::CStringToString(CString cstr)
{
	char cpResult[200];

#pragma warning(push)
#pragma warning(disable: 4996)
	strcpy(cpResult, CT2A(cstr));
	if (cpResult == NULL)
	{
		strcpy(cpResult, "");
	}
	cpResult[strlen(cpResult) + 1] = '\0';
#pragma warning(pop)

	return cpResult;
}

CString FileManager::StringToCString(string str)
{
	CString strResult;

	strResult = str.c_str();
	strResult += '\0';

	return strResult;
}


FileManager::FileManager()
{

}
FileManager::~FileManager()
{

}
void FileManager::SaveAsJson()
{

}
void FileManager::LoadAsJson()
{
	
}

boolean FileManager::SaveAsCsv()
{
	PhoneBook *CPhoneBook = PhoneBook::getInstance();

	CString strPath = _T("C:\\Users\\kjh0121\\source\\repos\\Project1\\PhoneBookGUI\\media\\마이다스주소록_20180214.csv");

	CString strStatus;

	//파일 열기
	ofstream file(strPath);

#pragma warning(push)
#pragma warning(disable: 4018)
	//파일 쓰기

	for (int i = 0; i < CPhoneBook->m_CaPerson.size(); i++)
	{
		if (CPhoneBook->m_CaPerson.at(i) == nullptr)
		{
			continue;
		}
		file << CStringToString(CPhoneBook->m_CaPerson.at(i)->GetName()) << ',' << CStringToString(CPhoneBook->m_CaPerson.at(i)->GetPhoneNumber())
			<< ',' << CStringToString(CPhoneBook->m_CaPerson.at(i)->GetTitle()) << ',' << CStringToString(CPhoneBook->m_CaPerson.at(i)->GetJob());
		file << '\n';
	}
#pragma warning(pop)

	if (file.fail())  //만약 bad() 함수가 실패 하면..
	{
		return FALSE;
	}

	file.close(); //파일 입출력 완료 후 닫아준다.

	return TRUE;
}

boolean FileManager::LoadAsCsv()
{
	PhoneBook *CPhoneBook = PhoneBook::getInstance();

	CString strPath = _T("C:\\Users\\kjh0121\\source\\repos\\Project1\\PhoneBookGUI\\media\\마이다스주소록_20180214.csv");

	CString strName;
	CString strPhoneNumber;
	CString strTitle;
	CString strJob;


	//ifstream은 파일을 읽게 해주는 함수로써 ifstream (파일명 or 경로)
	ifstream file(strPath);

	if (file.fail())  //만약 bad() 함수가 실패 하면..
	{
		return FALSE;
	}

	CPhoneBook->m_CaPerson.clear();

	while (file.good()) //eof, bad, fail 함수가 거짓을 반환할 때까지
	{
		vector<string> row = CsvReadRow(file, ',');

		if (!row[0].find("#")) //만약 csv 파일 안에 # 문자가 있을경우
		{
			continue; //그냥 건너 뛰어라
		}
		else //#문자가 없을 경우
		{
			strName = StringToCString(row[0]);
			strJob = StringToCString(row[1]);
			strTitle = StringToCString(row[2]);
			strPhoneNumber = StringToCString(row[3]);

			CPhoneBook->m_CaPerson.push_back(new Person(CPhoneBook->m_AutoIncId++, strName, strPhoneNumber, strTitle, strJob));
		}
	}

	file.close(); //파일 입출력 완료 후 닫아준다.

	return TRUE;

}

vector<string> FileManager::CsvReadRow(istream &file, char cDelimiter)
{
	stringstream StringStream;
	bool bInquotes = false;  // 인용구, 큰 따옴표 같은 것 제거
	vector<string> row;//relying on RVO

	while (file.good())
	{
		char cGetFileChar = file.get();

		if (!bInquotes && cGetFileChar == '"')
		{
			bInquotes = true;
		}
		else if (bInquotes && cGetFileChar == '"')
		{
			if (file.peek() == '"')
			{
				StringStream << (char)file.get();
			}
			else
			{
				bInquotes = false;
			}
		}
		else if (!bInquotes && cGetFileChar == cDelimiter) // split 문자 만나면 stream 데이터를 벡터에 넣고 초기화
		{
			row.push_back(StringStream.str());
			StringStream.str("");
		}
		else if (!bInquotes && (cGetFileChar == '\r' || cGetFileChar == '\n')) // 다음 줄을 만나도 stream 데이터를 벡터에 넣고 초기화
		{
			if (file.peek() == '\n') { file.get(); }
			row.push_back(StringStream.str());
			return row;
		}
		else
		{
			StringStream << cGetFileChar;
		}
	}

	return row;
}
