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
		MCIWndClose(m_hWndMCIWnd);    //�����Ϊ�˴�һ��������֮ǰ�ر���ǰ������,Ӧ���ȼ�һ���жϺ���.
	}
	m_hWndMCIWnd = MCIWndCreate(this->m_hWnd,::AfxGetApp()->m_hInstance,WS_CAPTION,m_strFile);    //�������Ҫ˵�������һ������,�����NULL,���½�һ��,�����һ���ļ���·��,�ʹ���.���Ƕ�Ҫʹ�������MCIWndNew�����ڴ�
	if(m_strFile.IsEmpty())
	{
		if(MCIWndNew(m_hWndMCIWnd,"waveaudio"))
		{
			AfxMessageBox(_T("MCIWndNew ����"));	
		}
	}
	
}

void CRecWavDlg::OnButtonRec() 
{
	// TODO: Add your control notification handler code here
	if(MCIWndCanRecord(m_hWndMCIWnd))    //�������ж��Ƿ����¼��
	{ 
		MCIWndRecord(m_hWndMCIWnd);    //¼�����������,�ܼ�
	}
	else
	{
		AfxMessageBox("error #01");    //������󱨸��������,��������,���������û�����.
	}

}

void CRecWavDlg::OnButtonStop() 
{
	// TODO: Add your control notification handler code here
	MCIWndStop(m_hWndMCIWnd);    //����,����ô��
	//���ֹͣ��������ֻ��������¼����,����¼��ʱҲ����ʹ������ֹͣ.

}

void CRecWavDlg::OnButtonPlay() 
{
	// TODO: Add your control notification handler code here
	if(MCIWndCanPlay(m_hWndMCIWnd))    //�����ж���û�п��Բ��ŵĶ���
	{
		MCIWndSeek(m_hWndMCIWnd,m_Int);    //˵һ�������,������ȷ�������￪ʼ����.û��Ҳ���Ծ��Ǵ�ͷ��ʼ����.�����m_Int���������벥�ſ�ʼ���,����ӻ������Ͻ���һ������,��������,�ʹ����￪ʼ������.����������Ǳ�����!
		if(MCIWndPlay(m_hWndMCIWnd))
		{
			AfxMessageBox(_T("���ų���!"));
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
		MCIWndSave(m_hWndMCIWnd, "a");    //�����е�����Ҫ˵˵��,MSDN����д,���MCIWndSave����ֱ�ӱ����ļ�,�ڶ�����������һ��-1�ͻ��Զ��򿪱���������ѡ��,����������N�ö�û�㶨,(Ҳ����ֿ���,˭�㶨��mail����һ��)�����򿪱�������,���Ƿ���һ���ɹ�ֵ!��~!����ֱ�ӱ���Ϊ�ļ�,�ļ���ֻҪ����һλ��������,����������������һ��Ȧ,�ȱ����һ��a,��������ΪҪ������ļ���,����ڽ�������ɾ�������a.
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
