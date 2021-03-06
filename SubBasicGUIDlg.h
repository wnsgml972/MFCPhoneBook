#pragma once


// SubBasicGUIDlg 대화 상자

class SubBasicGUIDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SubBasicGUIDlg)

public:
	SubBasicGUIDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SubBasicGUIDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PHONEBOOKGUI_BASIC_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	DECLARE_MESSAGE_MAP()

// 구현입니다.

public:
	void SetString(CString str);

protected:
	virtual BOOL OnInitDialog();

private:
	CString str;
	CString m_strImagePath;
	CImage m_PngImage;
	CRect m_WinRect;
public:
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
