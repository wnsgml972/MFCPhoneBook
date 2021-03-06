
// PhoneBookGUIDlg.h: 헤더 파일
//

#pragma once

#include "PhoneBook.h"

// CPhoneBookGUIDlg 대화 상자
class CPhoneBookGUIDlg : public CDialogEx
{
// 생성입니다.
public:
	CPhoneBookGUIDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PHONEBOOKGUI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
public:
	afx_msg void OnLbnDblclkPhonebookMenulistLst();
	afx_msg void OnLbnDblclkPhonebookViewLst();
	afx_msg void OnBnClickedPhonebookSearchBtn();
	void repaintViewList();
	void MenuAdd();
	void MenuEdit();
	void MenuDelete();
	void MenuSave();
	void MenuLoad();
	void MenuError();

protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	virtual BOOL PreTranslateMessage(MSG* pMsg);

private:
	CListBox m_MenuList;
	CListBox m_ViewList;
	FileManager m_CFileManager;
};
