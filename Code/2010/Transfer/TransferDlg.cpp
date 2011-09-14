// TransferDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Transfer.h"
#include "TransferDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransferDlg dialog

CTransferDlg::CTransferDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTransferDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTransferDlg)
	m_db1 = 0.0;
	m_db2 = 0.0;
	m_db3 = 0.0;
	m_db4 = 0.0;
	m_db5 = 0.0;
	m_db6 = 0.0;
	m_db7 = 0.0;
	m_db8 = 0.0;
	m_db9 = 0.0;
	m_db10 = 0.0;
	m_db11 = 0.0;
	m_db12 = 0.0;
	m_db13 = 0.0;
	m_db14 = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTransferDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTransferDlg)
	DDX_Text(pDX, IDC_EDIT1, m_db1);
	DDX_Text(pDX, IDC_EDIT2, m_db2);
	DDX_Text(pDX, IDC_EDIT3, m_db3);
	DDX_Text(pDX, IDC_EDIT4, m_db4);
	DDX_Text(pDX, IDC_EDIT5, m_db5);
	DDX_Text(pDX, IDC_EDIT6, m_db6);
	DDX_Text(pDX, IDC_EDIT7, m_db7);
	DDX_Text(pDX, IDC_EDIT8, m_db8);
	DDX_Text(pDX, IDC_EDIT9, m_db9);
	DDX_Text(pDX, IDC_EDIT10, m_db10);
	DDX_Text(pDX, IDC_EDIT11, m_db11);
	DDX_Text(pDX, IDC_EDIT12, m_db12);
	DDX_Text(pDX, IDC_EDIT13, m_db13);
	DDX_Text(pDX, IDC_EDIT14, m_db14);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTransferDlg, CDialog)
	//{{AFX_MSG_MAP(CTransferDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransferDlg message handlers

BOOL CTransferDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTransferDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTransferDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTransferDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTransferDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	//立方米/小时-->升/秒
	UpdateData(TRUE);
	if(m_db1 <= 0)
	{
		AfxMessageBox(_T("请输入一个正数！"));
		return;
	}
	m_db2 = m_db1*1000;
	m_db2 = m_db2 /3600;
	UpdateData(FALSE);
}

void CTransferDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	//升/秒-->立方米/小时
	UpdateData(TRUE);
	if(m_db3 <= 0)
	{
		AfxMessageBox(_T("请输入一个正数！"));
		return;
	}
	m_db4 = m_db3/1000;
	m_db4 = m_db4 * 3600;
	UpdateData(FALSE);
}

void CTransferDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	//帕--->米
	UpdateData(TRUE);
	if(m_db5 <= 0)
	{
		AfxMessageBox(_T("请输入一个正数！"));
		return;
	}
	//P＝ρgh
	m_db6 = m_db5/1000;
	m_db6 = m_db6 /9.8;
	UpdateData(FALSE);
}

void CTransferDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_db7 <= 0)
	{
		AfxMessageBox(_T("请输入一个正数！"));
		return;
	}
	//1马力= 0.735KW
	m_db8 = m_db7*0.735;
	UpdateData(FALSE);
}

void CTransferDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_db9 <= 0)
	{
		AfxMessageBox(_T("请输入一个正数！"));
		return;
	}
	//KW-->马力
	//1马力= 0.735KW
	m_db10 = m_db9/0.735;
	UpdateData(FALSE);
}

void CTransferDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	//升/分钟-->立方米/小时
	UpdateData(TRUE);
	if(m_db11 <= 0)
	{
		AfxMessageBox(_T("请输入一个正数！"));
		return;
	}
	m_db12 = m_db11/1000;
	m_db12 = m_db12 * 60;
	UpdateData(FALSE);
}

void CTransferDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	//立方米/小时-->升/分
	UpdateData(TRUE);
	if(m_db13 <= 0)
	{
		AfxMessageBox(_T("请输入一个正数！"));
		return;
	}
	m_db14 = m_db13*1000;
	m_db14 = m_db14 /60;
	UpdateData(FALSE);
}
