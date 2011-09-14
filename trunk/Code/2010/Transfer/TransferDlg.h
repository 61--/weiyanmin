// TransferDlg.h : header file
//

#if !defined(AFX_TRANSFERDLG_H__7CA1F15E_20E6_4445_8F3D_8C4B55ED9542__INCLUDED_)
#define AFX_TRANSFERDLG_H__7CA1F15E_20E6_4445_8F3D_8C4B55ED9542__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTransferDlg dialog

class CTransferDlg : public CDialog
{
// Construction
public:
	CTransferDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTransferDlg)
	enum { IDD = IDD_TRANSFER_DIALOG };
	double	m_db1;
	double	m_db2;
	double	m_db3;
	double	m_db4;
	double	m_db5;
	double	m_db6;
	double	m_db7;
	double	m_db8;
	double	m_db9;
	double	m_db10;
	double	m_db11;
	double	m_db12;
	double	m_db13;
	double	m_db14;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransferDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTransferDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSFERDLG_H__7CA1F15E_20E6_4445_8F3D_8C4B55ED9542__INCLUDED_)
