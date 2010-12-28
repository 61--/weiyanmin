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
	if(MCIWndCanPlay(m_hWndMCIWnd))    //�����ж���û�п��Բ��ŵĶ���
	{
		MCIWndSeek(m_hWndMCIWnd,0);    //˵һ�������,������ȷ�������￪ʼ����.û��Ҳ���Ծ��Ǵ�ͷ��ʼ����.�����m_Int���������벥�ſ�ʼ���,����ӻ������Ͻ���һ������,��������,�ʹ����￪ʼ������.����������Ǳ�����!
		if(MCIWndPlay(m_hWndMCIWnd))
		{
			AfxMessageBox(_T("���ų���!"));
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
	m_hWndMCIWnd = MCIWndCreate(NULL,NULL,WS_CAPTION,_strFile);    //�������Ҫ˵�������һ������,�����NULL,���½�һ��,�����һ���ļ���·��,�ʹ���.���Ƕ�Ҫʹ�������MCIWndNew�����ڴ�
	if(_strFile.IsEmpty())
	{
		if(MCIWndNew(m_hWndMCIWnd,"waveaudio"))
		{
			AfxMessageBox(_T("MCIWndNew ����"));	
		}
	}
	return S_OK;
}