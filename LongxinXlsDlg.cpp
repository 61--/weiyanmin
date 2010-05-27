// LongxinXlsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LongxinXls.h"
#include "LongxinXlsDlg.h"
#include "excel.h"
#include <comutil.h>

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
// CLongxinXlsDlg dialog

CLongxinXlsDlg::CLongxinXlsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLongxinXlsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLongxinXlsDlg)
	m_strXlsFile = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLongxinXlsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLongxinXlsDlg)
	DDX_Text(pDX, IDC_EDIT_FILE_NAME, m_strXlsFile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLongxinXlsDlg, CDialog)
	//{{AFX_MSG_MAP(CLongxinXlsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SEL_FILE, OnButtonSelFile)
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLongxinXlsDlg message handlers

BOOL CLongxinXlsDlg::OnInitDialog()
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
	m_nMin = 1;
	m_nMax = 15;
	InitMinMax();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLongxinXlsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLongxinXlsDlg::OnPaint() 
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
HCURSOR CLongxinXlsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLongxinXlsDlg::OnButtonSelFile() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE,NULL,NULL,NULL,_T("XLS文件(*.XLS)|*.XLS|所有文件(*.*)|*.*")); 
	if(dlg.DoModal() != IDOK)
	{
		return;
	}
	m_strXlsFile = dlg.GetPathName();
	UpdateData(FALSE);
}

void CLongxinXlsDlg::OnButtonStart() 
{
	// TODO: Add your control notification handler code here
	if(m_strXlsFile.IsEmpty())
	{
		AfxMessageBox(_T("请选择一个Excel文件"));
		return ;

	}
	srand(GetTickCount());
	_Application       ExcelApp;     
	Workbooks             wbsMyBooks;     
	_Workbook             wbMyBook;     
	Worksheets           wssMysheets;     
	_Worksheet           wsMysheet;     
	Range                     rgMyRge; 
    COleVariant vResult;
	COleVariant covTrue((short)TRUE), covFalse((short)FALSE),
		covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	
	//创建Excel   2000服务器(启动Excel)     
    
	if   (!ExcelApp.CreateDispatch("Excel.Application",NULL))     
	{     
		AfxMessageBox("创建Excel服务失败!");     
		return;     
	}     
	ExcelApp.SetAlertBeforeOverwriting(FALSE); 
	ExcelApp.SetDisplayAlerts(FALSE);  
	
	wbsMyBooks.AttachDispatch(ExcelApp.GetWorkbooks(),true);     
	wbMyBook.AttachDispatch(wbsMyBooks.Open(m_strXlsFile,covOptional, covOptional, covOptional, covOptional, covOptional,
        covOptional, covOptional, covOptional, covOptional, covOptional,
        covOptional, covOptional,covOptional,covOptional));
    
	//得到Worksheets     
	wssMysheets.AttachDispatch(wbMyBook.GetWorksheets(),true);     
	//得到sheet1     
	wsMysheet.AttachDispatch(wssMysheets.GetItem(_variant_t("sheet1")),true);     
	//得到全部Cells，此时,rgMyRge是cells的集合  
	
	SetRangeVal(wsMysheet,_T("B7"));
	SetRangeVal(wsMysheet,_T("B8"));
	SetRangeVal(wsMysheet,_T("B9"));
	SetRangeVal(wsMysheet,_T("B10"));
	SetRangeVal(wsMysheet,_T("B11"));
	SetRangeVal(wsMysheet,_T("B12"));
	SetRangeVal(wsMysheet,_T("B13"));
	SetRangeVal(wsMysheet,_T("B14"));
	SetRangeVal(wsMysheet,_T("B15"));
	SetRangeVal(wsMysheet,_T("B16"));
	
	SetRangeVal(wsMysheet,_T("C7"));
	SetRangeVal(wsMysheet,_T("C8"));
	SetRangeVal(wsMysheet,_T("C9"));
	SetRangeVal(wsMysheet,_T("C10"));
	SetRangeVal(wsMysheet,_T("C11"));
	SetRangeVal(wsMysheet,_T("C12"));
	SetRangeVal(wsMysheet,_T("C13"));
	SetRangeVal(wsMysheet,_T("C14"));
	SetRangeVal(wsMysheet,_T("C15"));
	SetRangeVal(wsMysheet,_T("C16"));

	SetRangeVal(wsMysheet,_T("E7"));
	SetRangeVal(wsMysheet,_T("E8"));
	SetRangeVal(wsMysheet,_T("E9"));
	SetRangeVal(wsMysheet,_T("E10"));
	SetRangeVal(wsMysheet,_T("E11"));
	SetRangeVal(wsMysheet,_T("E12"));
	SetRangeVal(wsMysheet,_T("E13"));
	SetRangeVal(wsMysheet,_T("E14"));
	SetRangeVal(wsMysheet,_T("E15"));
	SetRangeVal(wsMysheet,_T("E16"));

	SetRangeVal(wsMysheet,_T("F7"));
	SetRangeVal(wsMysheet,_T("F8"));
	SetRangeVal(wsMysheet,_T("F9"));
	SetRangeVal(wsMysheet,_T("F10"));
	SetRangeVal(wsMysheet,_T("F11"));
	SetRangeVal(wsMysheet,_T("F12"));
	SetRangeVal(wsMysheet,_T("F13"));
	SetRangeVal(wsMysheet,_T("F14"));
	SetRangeVal(wsMysheet,_T("F15"));
	SetRangeVal(wsMysheet,_T("F16"));

	SetRangeVal(wsMysheet,_T("I7"));
	SetRangeVal(wsMysheet,_T("I8"));
	SetRangeVal(wsMysheet,_T("I9"));
	SetRangeVal(wsMysheet,_T("I10"));
	SetRangeVal(wsMysheet,_T("I11"));
	SetRangeVal(wsMysheet,_T("I12"));
	SetRangeVal(wsMysheet,_T("I13"));
	SetRangeVal(wsMysheet,_T("I14"));
	SetRangeVal(wsMysheet,_T("I15"));
	SetRangeVal(wsMysheet,_T("I16"));

	SetRangeVal(wsMysheet,_T("J7"));
	SetRangeVal(wsMysheet,_T("J8"));
	SetRangeVal(wsMysheet,_T("J9"));
	SetRangeVal(wsMysheet,_T("J10"));
	SetRangeVal(wsMysheet,_T("J11"));
	SetRangeVal(wsMysheet,_T("J12"));
	SetRangeVal(wsMysheet,_T("J13"));
	SetRangeVal(wsMysheet,_T("J14"));
	SetRangeVal(wsMysheet,_T("J15"));
	SetRangeVal(wsMysheet,_T("J16"));

	SetRangeVal(wsMysheet,_T("L7"));
	SetRangeVal(wsMysheet,_T("L8"));
	SetRangeVal(wsMysheet,_T("L9"));
	SetRangeVal(wsMysheet,_T("L10"));
	SetRangeVal(wsMysheet,_T("L11"));
	SetRangeVal(wsMysheet,_T("L12"));
	SetRangeVal(wsMysheet,_T("L13"));
	SetRangeVal(wsMysheet,_T("L14"));
	SetRangeVal(wsMysheet,_T("L15"));
	SetRangeVal(wsMysheet,_T("L16"));

	SetRangeVal(wsMysheet,_T("M7"));
	SetRangeVal(wsMysheet,_T("M8"));
	SetRangeVal(wsMysheet,_T("M9"));
	SetRangeVal(wsMysheet,_T("M10"));
	SetRangeVal(wsMysheet,_T("M11"));
	SetRangeVal(wsMysheet,_T("M12"));
	SetRangeVal(wsMysheet,_T("M13"));
	SetRangeVal(wsMysheet,_T("M14"));
	SetRangeVal(wsMysheet,_T("M15"));
	SetRangeVal(wsMysheet,_T("M16"));
    
	wbMyBook.SaveAs(_variant_t(m_strXlsFile),covOptional,covOptional,
						covOptional,covOptional,covOptional,
						0,covOptional,covOptional,
						covOptional,covOptional,covOptional); 
	wbMyBook.Close(covOptional, COleVariant(""), covOptional);
    wbsMyBooks.Close();
	
	rgMyRge.ReleaseDispatch();     
	wsMysheet.ReleaseDispatch();     
	wssMysheets.ReleaseDispatch();     
	wbMyBook.ReleaseDispatch();     
	wbsMyBooks.ReleaseDispatch();     
	ExcelApp.ReleaseDispatch();     
	ExcelApp.Quit();   
    
	
	AfxMessageBox(_T("修改Excel文件成功！"));
}

HRESULT CLongxinXlsDlg::SetRangeVal(_Worksheet& workSheet,CString _strLocation)
{
	HRESULT hr = E_FAIL;
	//0.01--0.15
	int iRange = m_nMax - m_nMin;
	int i =  m_nMin + rand() % iRange;
	double  d = i / 100.0;
	Range range   =   workSheet.GetRange(COleVariant(_strLocation),COleVariant(_strLocation));  
	range.SetValue2(COleVariant(d));
	//range.SetValue();   
	return S_OK;
}

HRESULT CLongxinXlsDlg::InitMinMax()//初始化最小和最大值
{
	HRESULT hr = E_FAIL;
//	CString strFileIni = _T("MinMax.ini");
	//GetPrivateProfileString(_T(""),_T("Max"),15
	TCHAR buffer[1024];
	GetModuleFileName(0,buffer,1023);
	CString strFileIni  = buffer;
	strFileIni = strFileIni.Left(strFileIni.ReverseFind('\\'));
	strFileIni += _T("\\MinMax.ini");
	m_nMax = GetPrivateProfileInt(_T("开始"),_T("最大值"),15,strFileIni);
	m_nMin = GetPrivateProfileInt(_T("开始"),_T("最小值"),1,strFileIni);
	return S_OK;
}