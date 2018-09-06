// SubBasicGUIDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "PhoneBookGUI.h"
#include "SubBasicGUIDlg.h"
#include "afxdialogex.h"


// SubBasicGUIDlg 대화 상자

IMPLEMENT_DYNAMIC(SubBasicGUIDlg, CDialogEx)

SubBasicGUIDlg::SubBasicGUIDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PHONEBOOKGUI_BASIC_DLG, pParent)
{

}

SubBasicGUIDlg::~SubBasicGUIDlg()
{

}

void SubBasicGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL SubBasicGUIDlg::OnInitDialog()
{
	CString strId;
	CString strName;
	CString strPhoneNumber;
	CString strTitle;
	CString strJob;
	CString strToken[5];

	str.Replace(_T(" "), NULL); //공백제거

	for (int i = 0; i < 5; i++)
	{
		AfxExtractSubString(strToken[i], str, i, '.'); // 고유번호
	}
	SetDlgItemText(IDC_PHONEBOOKGUI_ID_STC, strToken[0]);
	SetDlgItemText(IDC_PHONEBOOKGUI_NAME_STC, strToken[1]);
	SetDlgItemText(IDC_PHONEBOOKGUI_PHONENUMBER_STC, strToken[2]);
	SetDlgItemText(IDC_PHONEBOOKGUI_AGE_STC, strToken[3]);
	SetDlgItemText(IDC_PHONEBOOKGUI_JOB_STC, strToken[4]);

	return TRUE;
}

void SubBasicGUIDlg::SetString(CString str)
{
	this->str = str;
}


BEGIN_MESSAGE_MAP(SubBasicGUIDlg, CDialogEx)
END_MESSAGE_MAP()


// SubBasicGUIDlg 메시지 처리기
