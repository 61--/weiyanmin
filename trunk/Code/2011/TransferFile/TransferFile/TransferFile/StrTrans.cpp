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



//将%D1%91转换成中文
CString CStrTrans::TransToString(CString _str)
{
	CString strReturn = _str;
	int iPos = strReturn.Find(_T('%'));
	while( iPos != -1)
	{
		int iRevPos = strReturn.ReverseFind(_T('%'));
		if(iRevPos <= iPos)
		{
			//说明只有一个%号，退出循环
			break;
		}
		if(strReturn.GetLength() <= iPos + 2)
		{
			//结束了
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

//将中文字符串转换成%D1%91的形式
CString CStrTrans::TransToCode(CString _strCode)
{
	CString strReturn;
	for(int i = 0; i < _strCode.GetLength();i++)
	{
		TCHAR ch = _strCode.GetAt(i);
		if(ch <= _T('9') && ch >= _T('0'))
		{
			//数值不用转
			strReturn += ch;
		}
		else if(ch <= _T('Z') && ch >= _T('A'))
		{
			//大写英文也不转
			strReturn += ch;
		}
		else if(ch <= _T('z') && ch >= _T('a'))
		{
			//小写英文不转
			strReturn += ch;
		}
		else
		{
			//认为是中文，要转换
			CString strTemp;
			int chLower = ch & 0xFF;
			int chUpper = (ch>>8) & 0xFF;
			strTemp.Format(_T("%%%x%%%x"),chUpper,chLower);
			strReturn +=strTemp;
		}
	}
	return strReturn;
}
