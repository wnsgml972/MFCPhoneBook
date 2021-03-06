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
	ON_WM_PAINT()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// SubBasicGUIDlg 메시지 처리기

/// 클래스 마법사를 이용하여 함수 생성
void SubBasicGUIDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	m_strImagePath = _T("media\\김준희.jpg");

	m_PngImage.Destroy();
	m_PngImage.Load(m_strImagePath);

	GetWindowRect(m_WinRect);
	m_PngImage.Draw(dc, 260, 40, 120, 150);
}


int SubBasicGUIDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.


	return 0;
}
