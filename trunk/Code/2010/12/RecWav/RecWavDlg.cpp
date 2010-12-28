// RecWavDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RecWav.h"
#include "RecWavDlg.h"
#include <Vfw.h>
#include "MCIControl.h"

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
// CRecWavDlg dialog

CRecWavDlg::CRecWavDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRecWavDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRecWavDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hWndMCIWnd = NULL;
	m_Int = 0;
	m_strFile = _T("");
}

void CRecWavDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRecWavDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRecWavDlg, CDialog)
	//{{AFX_MSG_MAP(CRecWavDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_INIT, OnButtonInit)
	ON_BN_CLICKED(IDC_BUTTON_REC, OnButtonRec)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, OnButtonOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecWavDlg message handlers

BOOL CRecWavDlg::OnInitDialog()
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

void CRecWavDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRecWavDlg::OnPaint() 
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
HCURSOR CRecWavDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRecWavDlg::OnButtonInit() 
{
	// TODO: Add your control notification handler code here
	if(m_hWndMCIWnd != NULL)
	{
		MCIWndClose(m_hWndMCIWnd);    //这个是为了打开一个声音的之前关闭以前的声音,应该先加一个判断好了.
	}
	m_hWndMCIWnd = MCIWndCreate(this->m_hWnd,::AfxGetApp()->m_hInstance,WS_CAPTION,m_strFile);    //创建句柄要说的是最后一个参数,如果是NULL,就新建一个,如果是一个文件的路径,就打开它.但是都要使用下面的MCIWndNew来开内存
	if(m_strFile.IsEmpty())
	{
		if(MCIWndNew(m_hWndMCIWnd,"waveaudio"))
		{
			AfxMessageBox(_T("MCIWndNew 出错！"));	
		}
	}
	
}

void CRecWavDlg::OnButtonRec() 
{
	// TODO: Add your control notification handler code here
	if(MCIWndCanRecord(m_hWndMCIWnd))    //这里是判断是否可以录音
	{ 
		MCIWndRecord(m_hWndMCIWnd);    //录音就这个函数,很简单
	}
	else
	{
		AfxMessageBox("error #01");    //这个错误报告很垃圾的,不建议用,不过测试用还可以.
	}

}

void CRecWavDlg::OnButtonStop() 
{
	// TODO: Add your control notification handler code here
	MCIWndStop(m_hWndMCIWnd);    //别怀疑,就这么简单
	//这个停止函数不是只可以用在录音的,播放录音时也可以使用它来停止.

}

void CRecWavDlg::OnButtonPlay() 
{
	// TODO: Add your control notification handler code here
	if(MCIWndCanPlay(m_hWndMCIWnd))    //这里判断有没有可以播放的东西
	{
		MCIWndSeek(m_hWndMCIWnd,m_Int);    //说一下这里吧,这里是确定从哪里开始播放.没有也可以就是从头开始播放.里面的m_Int是用来传入播放开始点的,比如从滑动条上接收一个数字,传到这里,就从这里开始播放了.但这个方法是笨方法!
		if(MCIWndPlay(m_hWndMCIWnd))
		{
			AfxMessageBox(_T("播放出错!"));
		}
	}
	else
		AfxMessageBox("error no wave");

}

void CRecWavDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	CString m_Path;
	CFileDialog dlg(FALSE,NULL,NULL,OFN_ALLOWMULTISELECT,"wav File (*.wav)|*.wav");
	if(dlg.DoModal() == IDOK)
	{
		m_Path = dlg.GetPathName();
	}
	else
		return;
	if(MCIWndCanSave(m_hWndMCIWnd))
	{
		MCIWndSave(m_hWndMCIWnd, "a");    //这里有点问题要说说了,MSDN里面写,这个MCIWndSave可以直接保存文件,第二个参数传入一个-1就会自动打开保存框给我们选择,但是我试了N久都没搞定,(也请高手看看,谁搞定了mail给我一份)它不打开保存框给我,但是返回一个成功值!靠~!还有直接保存为文件,文件名只要大于一位就是乱码,所以我在这里绕了一个圈,先保存成一个a,拷贝改名为要保存的文件名,最后在结束里面删除掉这个a.
	//	CopyFile("a",m_Path,FALSE);
	}
	else
		AfxMessageBox("error Can't save");

}

void CRecWavDlg::OnButtonOpen() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,"wav File (*.wav)|*.wav");
	if(dlg.DoModal() != IDOK)
	{
		return ;
	}
	CMCIControl MCIControl;
	MCIControl.OpenFile(CComBSTR(dlg.GetPathName()));
	//m_strFile = dlg.GetPathName();
}
