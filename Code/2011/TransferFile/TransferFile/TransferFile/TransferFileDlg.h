
// TransferFileDlg.h : header file
//

#pragma once
#include <list>

// CTransferFileDlg dialog
class CTransferFileDlg : public CDialogEx
{
// Construction
public:
	CTransferFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TRANSFERFILE_DIALOG };

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
	CString m_strString;
	CString m_strCode;
	afx_msg void OnBnClickedButtonStr2code();
	afx_msg void OnBnClickedButtonCode2str();
	CString m_strSelPath;
	afx_msg void OnBnClickedButtonSelPath();
	afx_msg void OnBnClickedButtonTransPath();
	void TransFileandPath(CString _strPath,std::list<std::pair<CString,CString>> &_lstTransFileAndPath);
};
