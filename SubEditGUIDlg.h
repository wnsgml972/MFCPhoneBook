#pragma once


// SubEditGUIDlg 대화 상자

class SubEditGUIDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SubEditGUIDlg)

public:
	SubEditGUIDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SubEditGUIDlg();
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PHONEBOOKGUI_EDIT_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

/// 구현입니다.
public:
	afx_msg void OnBnClickedPhonebookguiEditcompleteBtn();
	void SetType(int nType);
	void SetString(CString str);

private:
	int nType;
	CString str;
};
