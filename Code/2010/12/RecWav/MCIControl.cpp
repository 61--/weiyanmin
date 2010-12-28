// MCIControl.cpp: implementation of the CMCIControl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RecWav.h"
#include "MCIControl.h"
#include <Vfw.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMCIControl::CMCIControl()
{
	m_hWndMCIWnd = NULL;
}

CMCIControl::~CMCIControl()
{
	Close();
}

HRESULT CMCIControl::OpenFile(BSTR _bstrFile)
{
	HRESULT hr = E_FAIL;
	CString strFile = _bstrFile;
	hr = Init(strFile);
	if(FAILED(hr))
	{
		return hr;
	}
	if(MCIWndCanPlay(m_hWndMCIWnd))    //这里判断有没有可以播放的东西
	{
		MCIWndSeek(m_hWndMCIWnd,0);    //说一下这里吧,这里是确定从哪里开始播放.没有也可以就是从头开始播放.里面的m_Int是用来传入播放开始点的,比如从滑动条上接收一个数字,传到这里,就从这里开始播放了.但这个方法是笨方法!
		if(MCIWndPlay(m_hWndMCIWnd))
		{
			AfxMessageBox(_T("播放出错!"));
		}
		Sleep(1000);
	}
	else
		AfxMessageBox("error no wave");
	return S_OK;
}

HRESULT CMCIControl::Close()
{
	if(m_hWndMCIWnd != NULL)
	{
		MCIWndClose(m_hWndMCIWnd);    
	}
	return S_OK;
}

HRESULT CMCIControl::Init(CString _strFile)
{
	HRESULT hr = E_FAIL;
	hr = Close();
	if(FAILED(hr))
	{
		return hr;
	}
	m_hWndMCIWnd = MCIWndCreate(NULL,NULL,WS_CAPTION,_strFile);    //创建句柄要说的是最后一个参数,如果是NULL,就新建一个,如果是一个文件的路径,就打开它.但是都要使用下面的MCIWndNew来开内存
	if(_strFile.IsEmpty())
	{
		if(MCIWndNew(m_hWndMCIWnd,"waveaudio"))
		{
			AfxMessageBox(_T("MCIWndNew 出错！"));	
		}
	}
	return S_OK;
}