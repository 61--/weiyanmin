#include "StdAfx.h"
#include "StrTrans.h"


CStrTrans::CStrTrans(void)
{
}


CStrTrans::~CStrTrans(void)
{
}

TCHAR ConvertHexData(TCHAR ch)
{
	if((ch>=_T('0'))&&(ch<=_T('9')))
		return ch-0x30;
	if((ch>=_T('A'))&&(ch<=_T('F')))
		return ch-_T('A')+10;
	if((ch>=_T('a'))&&(ch<=_T('f')))
		return ch-'a'+10;
	else return(-1);
}

int String2Hex(CString str, int *SendOut)
{
	int hexdata,lowhexdata; 
	int hexdatalen=0;
	int len=str.GetLength();
	for(int i=0;i<len;)
	{
		TCHAR lstr,hstr=str[i];
		if(hstr==' '||hstr=='\r'||hstr=='\n')
		{
			i++;
			continue;
		}
		i++;
		if (i>=len)
			break;
		lstr=str[i];
		hexdata=ConvertHexData(hstr);
		lowhexdata=ConvertHexData(lstr);
		if((hexdata==16)||(lowhexdata==16))
			break;
		else
			hexdata=hexdata*16+lowhexdata;
		i++;
		SendOut[hexdatalen]=(char)hexdata;
		hexdatalen++;
	}
	return hexdatalen;
}



//��%D1%91ת��������
CString CStrTrans::TransToString(CString _str)
{
	CString strReturn = _str;
	int iPos = strReturn.Find(_T('%'));
	while( iPos != -1)
	{
		int iRevPos = strReturn.ReverseFind(_T('%'));
		if(iRevPos <= iPos)
		{
			//˵��ֻ��һ��%�ţ��˳�ѭ��
			break;
		}
		if(strReturn.GetLength() <= iPos + 2)
		{
			//������
			break;
		}
		if(strReturn.GetAt(iPos + 3) != _T('%'))
		{
			break;
		}
		CString strUpper = strReturn.Mid(iPos+1,2);
		CString strLower = strReturn.Mid(iPos+4,2);
		int iLower = 0;
		String2Hex(strLower,&iLower);
		int iUpper = 0;
		String2Hex(strUpper,&iUpper);
		CString strTemp;
		strTemp.Format(_T("upper=%xlower=%x"),iUpper,iLower);
		strReturn.Delete(iPos,6);
		TCHAR ch;
		int iiii = (iUpper<<8) & 0xFF00;
		ch = iiii | (iLower & 0xFF);
		strReturn.Insert(iPos,ch);
		iPos = strReturn.Find(_T('%'));
	}
	return strReturn;
}

//�������ַ���ת����%D1%91����ʽ
CString CStrTrans::TransToCode(CString _strCode)
{
	CString strReturn;
	for(int i = 0; i < _strCode.GetLength();i++)
	{
		TCHAR ch = _strCode.GetAt(i);
		if(ch <= _T('9') && ch >= _T('0'))
		{
			//��ֵ����ת
			strReturn += ch;
		}
		else if(ch <= _T('Z') && ch >= _T('A'))
		{
			//��дӢ��Ҳ��ת
			strReturn += ch;
		}
		else if(ch <= _T('z') && ch >= _T('a'))
		{
			//СдӢ�Ĳ�ת
			strReturn += ch;
		}
		else
		{
			//��Ϊ�����ģ�Ҫת��
			CString strTemp;
			int chLower = ch & 0xFF;
			int chUpper = (ch>>8) & 0xFF;
			strTemp.Format(_T("%%%x%%%x"),chUpper,chLower);
			strReturn +=strTemp;
		}
	}
	return strReturn;
}
