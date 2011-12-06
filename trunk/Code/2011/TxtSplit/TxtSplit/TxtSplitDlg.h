
// TxtSplitDlg.h : header file
//

#pragma once
#include <list>

// CTxtSplitDlg dialog
class CTxtSplitDlg : public CDialogEx
{
// Construction
public:
	CTxtSplitDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TXTSPLIT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSplitTxt();
	afx_msg void OnBnClickedButtonSplitDirTxt();
private:
	void ReuseGetFileName(CString _strPath,CString& _strExt,std::list<CString> &_lstTransFileName);
};
