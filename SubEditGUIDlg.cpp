// SubEditGUIDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "PhoneBookGUI.h"
#include "SubEditGUIDlg.h"
#include "afxdialogex.h"
#include "PhoneBook.h"


// SubEditGUIDlg 대화 상자

IMPLEMENT_DYNAMIC(SubEditGUIDlg, CDialogEx)

SubEditGUIDlg::SubEditGUIDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PHONEBOOKGUI_EDIT_DLG, pParent)
{

}

SubEditGUIDlg::~SubEditGUIDlg()
{
}

void SubEditGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL SubEditGUIDlg::OnInitDialog()
{
	CString strId;
	CString strName;
	CString strPhoneNumber;
	CString strTitle;
	CString strJob;
	CString strToken[5];

	str.Replace(_T(" "), NULL); //공백제거

	if (nType == 1)
	{
		for (int i = 0; i < 5; i++) {
			AfxExtractSubString(strToken[i], str, i, '.'); // 고유번호
		}
		SetDlgItemText(IDC_PHONEBOOKGUI_NAME_EDT, strToken[1]);
		SetDlgItemText(IDC_PHONEBOOKGUI_PHONENUMBER_EDT, strToken[2]);
		SetDlgItemText(IDC_PHONEBOOKGUI_AGE_EDT, strToken[3]);
		SetDlgItemText(IDC_PHONEBOOKGUI_JOB_EDT, strToken[4]);
	}
	return TRUE;
}


BEGIN_MESSAGE_MAP(SubEditGUIDlg, CDialogEx)
	ON_BN_CLICKED(IDC_PHONEBOOKGUI_EDITCOMPLETE_BTN, &SubEditGUIDlg::OnBnClickedPhonebookguiEditcompleteBtn)
//	ON_WM_PAINT()
//	ON_WM_CREATE()
END_MESSAGE_MAP()


// SubEditGUIDlg 메시지 처리기
void SubEditGUIDlg::OnBnClickedPhonebookguiEditcompleteBtn()
{
	CString strId;
	CString strName;
	CString strPhoneNumber;
	CString strTitle;
	CString strJob;
	CString strToken[5];

	if (nType == 0)
	{
		GetDlgItemText(IDC_PHONEBOOKGUI_NAME_EDT, strName);
		GetDlgItemText(IDC_PHONEBOOKGUI_PHONENUMBER_EDT, strPhoneNumber);
		GetDlgItemText(IDC_PHONEBOOKGUI_AGE_EDT, strTitle);
		GetDlgItemText(IDC_PHONEBOOKGUI_JOB_EDT, strJob);


		if (!strName.Compare(L"") || !strPhoneNumber.Compare(L"") || !strTitle.Compare(L"") || !strJob.Compare(L""))
		{
			MessageBox(L"모두 정확하게 입력해주세요.");
		}
		else
		{
			PhoneBook *CPhoneBook = PhoneBook::getInstance();
			CPhoneBook->m_CaPerson.push_back(new Person(CPhoneBook->m_AutoIncId++, strName, strPhoneNumber, strTitle, strJob));
			// 다이얼로그 종료
			this->EndDialog(IDD_PHONEBOOKGUI_EDIT_DLG);
			MessageBox(L"추가 되었습니다.");
		}
	}
	else
	{
		int nId = -1;

		str.Replace(_T(" "), NULL); //공백제거

		for (int i = 0; i <5 ; i++) 
		{
			AfxExtractSubString(strToken[i], str, i, '.'); // 고유번호
		}

		nId = _ttoi(strToken[0]);

		/// 기존 삭제
		PhoneBook *CPhoneBook = PhoneBook::getInstance();
		CPhoneBook->Delete(nId);

		/// 입력한 값으로 삽입
		GetDlgItemText(IDC_PHONEBOOKGUI_NAME_EDT, strName);
		GetDlgItemText(IDC_PHONEBOOKGUI_PHONENUMBER_EDT, strPhoneNumber);
		GetDlgItemText(IDC_PHONEBOOKGUI_AGE_EDT, strTitle);
		GetDlgItemText(IDC_PHONEBOOKGUI_JOB_EDT, strJob);
		CPhoneBook->m_CaPerson.push_back(new Person(nId, strName, strPhoneNumber, strTitle, strJob));

		// 다이얼로그 종료
		this->EndDialog(IDD_PHONEBOOKGUI_EDIT_DLG);
		MessageBox(L"편집 되었습니다.");
	}
}

void SubEditGUIDlg::SetType(int nType)
{
	this->nType = nType;
}

void SubEditGUIDlg::SetString(CString str)
{
	this->str = str;
}
