
// PhoneBookGUIDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "PhoneBookGUI.h"
#include "PhoneBookGUIDlg.h"
#include "SubBasicGUIDlg.h"
#include "SubEditGUIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPhoneBookGUIDlg 대화 상자


CPhoneBookGUIDlg::CPhoneBookGUIDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PHONEBOOKGUI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPhoneBookGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PHONEBOOKGUI_MENULIST_LST, m_MenuList);
	DDX_Control(pDX, IDC_PHONEBOOKGUI_VIEW_LST, m_ViewList);
}

BEGIN_MESSAGE_MAP(CPhoneBookGUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_DBLCLK(IDC_PHONEBOOKGUI_MENULIST_LST, &CPhoneBookGUIDlg::OnLbnDblclkPhonebookMenulistLst)
	ON_LBN_DBLCLK(IDC_PHONEBOOKGUI_VIEW_LST, &CPhoneBookGUIDlg::OnLbnDblclkPhonebookViewLst)
	ON_BN_CLICKED(IDC_PHONEBOOKGUI_SEARCH_BTN, &CPhoneBookGUIDlg::OnBnClickedPhonebookSearchBtn)
END_MESSAGE_MAP()


// CPhoneBookGUIDlg 메시지 처리기

BOOL CPhoneBookGUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.
	
	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	PhoneBook *CPhoneBook = PhoneBook::getInstance();

	//////////////////////////////////////////////////////////////////////////

	/// 메뉴 초기화
	m_MenuList.InsertString(-1, L" 1. 추가하기");
	m_MenuList.InsertString(-1, L" 2. 편집하기");
	m_MenuList.InsertString(-1, L" 3. 삭제하기");
	m_MenuList.InsertString(-1, L" 4. 저장하기");
	m_MenuList.InsertString(-1, L" 5. 불러오기");


#pragma warning(push)
#pragma warning(disable: 4018)

	m_CFileManager.LoadAsCsv();
	/// View( 전화번호부 ) 초기화
	for (int i = 0; i < CPhoneBook->m_CaPerson.size(); i++) 
	{
		m_ViewList.InsertString(-1 ,CPhoneBook->m_CaPerson.at(i)->GetPersonAsListItem());
	}
#pragma warning(pop)
	
	


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CPhoneBookGUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CPhoneBookGUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CPhoneBookGUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//////////////////////////////////////////////////////////////////////////
/// custom event

/// Enter 입력 시 다이얼로그 안 꺼지게 만들기!
// 1. virtual 이용한 변수 선언으로, 오버라이딩 하기
// 2. 밑에와 같은 함수 이용
BOOL CPhoneBookGUIDlg::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN)
		{
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

//////////////////////////////////////////////////////////////////////////
/// event listener
void CPhoneBookGUIDlg::OnBnClickedPhonebookSearchBtn() //search
{
	CString str;
	int nId, nIdx;
	PhoneBook *CPhoneBook = PhoneBook::getInstance();

	// id 가져오기
	GetDlgItemText(IDC_PHONEBOOKGUI_SEARCH_EDT, str);
	nId = _ttoi(str);
	
	if (nId <= 0) // id 입력 오류
	{
		MessageBox(L"올바른 값을 입력해주세요.");
	}
	else 
	{		
		nIdx = CPhoneBook->SearchById(nId);

		if (CPhoneBook->GetPersonById(nId) == NULL)
		{
			MessageBox(L"그러한 사람을 찾을 수 없습니다.");
			SetDlgItemText(IDC_PHONEBOOKGUI_SEARCH_EDT, L"");
			return;
		}
		str = CPhoneBook->GetPersonById(nId)->GetPersonAsListItem();

		SubBasicGUIDlg CSubBasicGUIDlg;
		CSubBasicGUIDlg.SetString(str);
		CSubBasicGUIDlg.DoModal();
	}

	SetDlgItemText(IDC_PHONEBOOKGUI_SEARCH_EDT, L"");
}

void CPhoneBookGUIDlg::OnLbnDblclkPhonebookMenulistLst() //menu dbclick
{
	int nSelIndex = m_MenuList.GetCurSel();

	switch (nSelIndex)
	{
	case 0:
		MenuAdd();
		break;
	case 1:
		MenuEdit();
		break;
	case 2:
		MenuDelete();
		break;
	case 3:
		MenuSave();
		break;
	case 4:
		MenuLoad();
		break;
	default:
		MenuError();
		break;
	}

	repaintViewList();
}
void CPhoneBookGUIDlg::OnLbnDblclkPhonebookViewLst() //view dbclick
{
	int nIdx = -1;
	CString str = NULL;
	nIdx = m_ViewList.GetCurSel();

	if (nIdx < 0)
	{
		MessageBox(L"올바르게 사용해주세요.");
	}
	else
	{
		m_ViewList.GetText(nIdx, str); //선택된 CString
		SubBasicGUIDlg CSubBasicGUIDlg;
		CSubBasicGUIDlg.SetString(str);
		CSubBasicGUIDlg.DoModal();
	}
}

//////////////////////////////////////////////////////////////////////////
/// repaint
void CPhoneBookGUIDlg::repaintViewList()
{
	PhoneBook *CPhoneBook = PhoneBook::getInstance();

	m_ViewList.ResetContent();

#pragma warning(push)
#pragma warning(disable: 4018)
	for (int i = 0; i < CPhoneBook->m_CaPerson.size(); i++)
	{
		m_ViewList.InsertString(-1, CPhoneBook->m_CaPerson.at(i)->GetPersonAsListItem());
	}
#pragma warning(pop)
}


//////////////////////////////////////////////////////////////////////////
/// Menu
void CPhoneBookGUIDlg::MenuAdd()
{
	SubEditGUIDlg CSubEditGUIDlg;

	CSubEditGUIDlg.SetType(0);
	CSubEditGUIDlg.DoModal();
}
void CPhoneBookGUIDlg::MenuEdit()
{
	int nIdx = 0;
	SubEditGUIDlg CSubEditGUIDlg;
	CString str = NULL;

	nIdx = m_ViewList.GetCurSel();
	m_ViewList.GetText(nIdx, str); //선택된 CString

	CSubEditGUIDlg.SetType(1);
	CSubEditGUIDlg.SetString(str);
	CSubEditGUIDlg.DoModal();
}
void CPhoneBookGUIDlg::MenuDelete()
{
	int nIdx = 0;
	SubEditGUIDlg CSubEditGUIDlg;
	PhoneBook *CPhoneBook = PhoneBook::getInstance();
	CString str = NULL;
	CString strToken = NULL;

	nIdx = m_ViewList.GetCurSel();
	m_ViewList.GetText(nIdx, str); //선택된 CString

	AfxExtractSubString(strToken, str, 0, '.'); // 고유번호
	nIdx = _ttoi(strToken); //정수 전환 id 가 됨

	if (nIdx < 0)
	{
		MessageBox(L"삭제할 대상을 클릭해주세요.");
		return;
	}
	else if (nIdx == 1)
	{
		MessageBox(L"삭제할 수 없는 아이템입니다.");
		return;
	}
	CPhoneBook->Delete(nIdx); // id를 넘김

	MessageBox(L"삭제 되었습니다.");
}
void CPhoneBookGUIDlg::MenuSave()
{
	m_CFileManager.SaveAsCsv();
	repaintViewList();
}
void CPhoneBookGUIDlg::MenuLoad()
{
	m_CFileManager.LoadAsCsv();
	repaintViewList();
}
void CPhoneBookGUIDlg::MenuError()
{
	MessageBox(L"오류 발생");
}