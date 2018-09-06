#include "stdafx.h"
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
		vector<string> row = csv_read_row(file, ',');

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

vector<string> FileManager::csv_read_row(istream &file, char delimiter)
{
	stringstream ss;
	bool inquotes = false;
	vector<string> row;//relying on RVO

	while (file.good())
	{
		char c = file.get();
		if (!inquotes && c == '"')
		{
			inquotes = true;
		}
		else if (inquotes && c == '"')
		{
			if (file.peek() == '"')
			{
				ss << (char)file.get();
			}
			else
			{
				inquotes = false;
			}
		}
		else if (!inquotes && c == delimiter)
		{
			row.push_back(ss.str());
			ss.str("");
		}
		else if (!inquotes && (c == '\r' || c == '\n'))
		{
			if (file.peek() == '\n') { file.get(); }
			row.push_back(ss.str());
			return row;
		}
		else
		{
			ss << c;
		}
	}

	return row;
}
