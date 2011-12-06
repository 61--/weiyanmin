#include "stdafx.h"
#include "DataHandler.h"



CDataHandler::CDataHandler(void)
{
}

CDataHandler::~CDataHandler(void)
{
}

BOOL CDataHandler::ToValidXmlString(CString& cValue)
{
	cValue.Replace(_T("<"),_T("&lt;")); 
	cValue.Replace(_T("<"),_T("&gt;"));
	cValue.Replace(_T("&"),_T("&amp;"));
	cValue.Replace(_T("&"),_T("&amp;"));
	cValue.Replace(_T("\""),_T("&quot;"));
	cValue.Replace(_T("'"),_T("&apos;"));
	return TRUE;
}

int CDataHandler::StringToInt(/*[in]*/const CString& str)
{
	return _ttoi(str);
}
BOOL CDataHandler::StringToVariant(const CString& str,VARTYPE vt,VARIANT* var)
{
	_ASSERT(var != NULL);
	TCHAR* stop = NULL;
	VariantInit(var);
	var->vt = vt;
	switch(vt)
	{
	case VT_EMPTY:
	case VT_NULL:
		break;
	case VT_BOOL:
		if( str.CompareNoCase(_T("yes")) == 0 || 
			str.CompareNoCase(_T("1")) == 0 ||
			str.CompareNoCase(_T("true")) == 0 ||
			str.CompareNoCase(_T("-1")) == 0)
			var->boolVal = VARIANT_TRUE;
		else 
			var->boolVal = VARIANT_FALSE;
		break;
	case VT_I2:
		var->iVal = (short)_tcstol((LPCTSTR)str,&stop,10);
		break;
	case VT_I4:
		var->lVal = _tcstol((LPCTSTR)str,&stop,10);
		break;
	case VT_I8:
		var->lVal = _tcstol((LPCTSTR)str,&stop,10);
		break;
	case VT_INT:
		var->intVal = _tcstol((LPCTSTR)str,&stop,10);
		break;
	case VT_UINT:
		var->uintVal = (UINT)_tcstol((LPCTSTR)str,&stop,10);
		break;
	case VT_R4:
		var->fltVal = (float)_tcstod((LPCTSTR)str,&stop);
		break;
	case VT_R8:
		var->dblVal = _tcstod((LPCTSTR)str,&stop);
		break;
	case VT_DATE:
		try 
		{
			COleDateTime dt;
			if(!dt.ParseDateTime(str))
			{
				return FALSE;
			}
			var->date = (DATE)dt;
		} 
		catch(CException *e)
		{
			e->Delete();
			return FALSE;
		}
		break;
	case VT_BSTR:
		var->bstrVal = str.AllocSysString();
		break;
	case VT_UI1:
		var->bVal = (BYTE)_tcstol((LPCTSTR)str,&stop,10);
		break;
	case VT_CY:
		var->cyVal.int64 = _ttoi64((LPCTSTR)str);
		break;
	case VT_DECIMAL:
		var->decVal = (DECIMAL)_variant_t(_bstr_t((LPCTSTR)str));
	default:
		return FALSE;
	}
	return TRUE;
}

BOOL CDataHandler::OleDateTimeToVariant(const COleDateTime& dt,VARIANT* _val)
{
	_val->vt = VT_DATE;
	_val->date = dt;
	return TRUE;
}

CString CDataHandler::VariantToString(const CComVariant& var)
{
	CString str(_T(""));
	switch(var.vt)
	{
	case VT_EMPTY:
	case VT_NULL:
		str = _T("");
		break;
	case VT_I2:
	case VT_I4:
	case VT_I8:
	case VT_UI4:
	case VT_UI2:
	case VT_INT:
	case VT_UINT:
		str.Format(_T("%d"),(long)_variant_t(var));
		break;
	case VT_R4:
		str.Format(_T("%.3f"),var.fltVal);
		break;
	case VT_R8:
		str.Format(_T("%.3f"),var.dblVal);
		break;
		//VT_CY              = 6,
	case VT_DATE://            = 7,
		{
			if (var.date != 0)
			{
				COleDateTime od(var.date);
				//str = od.Format(YD_DATE_FORMAT);

			}
			break;
		}
	case VT_BSTR://= 8,
		str = (BSTR)((_bstr_t)var);
		break;
	case VT_BOOL:
		if (var.boolVal) {
			str = _T("YES");
		}
		else{
			str = _T("NO");
		}
		break;
	case VT_DECIMAL:
		if (var.decVal.scale ==0)
		{
			str = (LPCTSTR)(_bstr_t)var;
		}
		else
		{
			double dblValue = (double)_variant_t(var);
			CString strFormat;
			strFormat.Format(_T("%d"), var.decVal.scale);
			strFormat = _T("%.")+strFormat+_T("f");
			str.Format(strFormat, dblValue);
		}
	default:
		break;
	}
	return str;
}

long CDataHandler::VariantToLong(const CComVariant &var)
{
	switch(var.vt)
	{
	case VT_NULL:
		return 0l;
	case VT_BSTR:
		return (long)_ttoi(var.bstrVal);
	default:
		return (long)_variant_t(var);
	}
}

BOOL CDataHandler::VariantToBool(const CComVariant &var)
{
	switch(var.vt)
	{
	case VT_NULL:
		return FALSE;
	default:
		return (bool)_variant_t(var)?TRUE:FALSE;
	}
}

/****************************************
函数名：BSTRCompare
参数：  BSTR strA
	    BSTR strB
	    BOOL bCaseSens 是否区分大小写；TRUE区分 FALSE不区分；
返回值：
		StrA小于strB返回<0
		StrA大于于strB返回>0
		StrA大于于strB返回0；
说明：  比较两个字符串；
****************************************/

int CDataHandler::BSTRCompare(BSTR strA, BSTR strB, BOOL bCaseSens)
{
	if (NULL == strA)
	{
		if (NULL == strB)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	else if (NULL == strB)
	{
		return 1;
	}

	if (bCaseSens)
	{
		return _tcscmp(strA, strB);
	}
	else
	{
		return _tcsicmp(strA, strB);
	}
}

/*************************************************
函数名：SplitString
参数：  const CString& str   str待拆分的字符串；
	    TCHAR split_char     split_char拆分的字符；
	    CStringArray& arr	 arr拆分后的字符串数组
返回值：void
说明：  拆分字符串，将数组拆分后存入字符串数组中；
***************************************************/
void CDataHandler::SplitString(const CString& str,TCHAR split_char,CStringArray& arr)
{
	if(str.IsEmpty()) return;
	LPCTSTR p = (LPCTSTR)str;
	int n=0,n1=0;
	while(*p != 0)
	{
		if(*p == split_char)
		{
			arr.Add(str.Mid(n1,n-n1));
			n1 = n+1; 
		}
		p++;
		n++;
	}
	if(n > n1)
	{
		arr.Add(str.Mid(n1,n-n1));
	}
}
/**********************************************
函数名：TrimString
参数：CString& str
返回值：
说明：去除字符串前后的空格
**********************************************/
void CDataHandler::TrimString(CString& str)
{
	if(str.IsEmpty()) return;
	while(!str.IsEmpty()&&str[0]==_T(' '))
		str.Delete(0);
	while(!str.IsEmpty()&&str[str.GetLength()-1]==_T(' '))
		str.Delete(str.GetLength()-1);
	str.TrimLeft();
	str.TrimRight();
}

/**********************************************
函数名：TrimStringAll
参数：CString& str
返回值：
说明：去除字符串中的空格
**********************************************/
void CDataHandler::TrimStringAll(CString& str)
{
	if(str.IsEmpty()) return;
	while (1) {
		int i = str.Find(_T(' '));
		if (i >= 0) {
			str.Delete(i,1);
		}
		else break;
	}	
}

CString CDataHandler::LoadString(UINT nID)
{
 	CString str(_T(""));
	str.LoadString(nID);
	return str;
}

//根据给定的variant来创建相应的DB type
// BOOL CDataHandler::VarTypeToDBType(VARIANT* var,ADODB::DataTypeEnum& type,int& size)
// 
// {
// 	type = ADODB::adEmpty;
// 	size = 0;
// 	switch(var->vt) {
// 	case VT_EMPTY:
// 	case VT_NULL:
// 		type = adEmpty;
// 		size = 0;
// 		break;
// 	case VT_BOOL:
// 		type = adBoolean;
// 		size = sizeof(VARIANT_BOOL);
// 		break;
// 	case VT_UI1:
// 		type = adTinyInt;
// 		size = sizeof(BYTE);
// 		break;
// 	case VT_I2:
// 		type = adSmallInt;
// 		size = sizeof(short);
// 		break;
// 	case VT_UI2:
// 	case VT_UI4:
// 	case VT_INT:
// 	case VT_UINT:
// 	case VT_I4:
// 		type = adInteger;
// 		size = sizeof(int);
// 		break;
// 	case VT_R4:
// 	case VT_UI8:
// 		type = adSingle;
// 		size = sizeof(float);
// 		break;
// 	case VT_R8:
// 		type = adDouble;
// 		size = sizeof(double);
// 		break;
// 	case VT_DATE:
// 		type = adDBTimeStamp;
// 		{
// 			COleDateTime dt = var->date;
// 			CString str = dt.Format(_T("%Y-%m-%d %H:%M:%S"));
// 			var->vt = VT_BSTR;
// 			var->bstrVal = str.AllocSysString();
// 			size = (str.GetLength()+1)*sizeof(TCHAR);
// 		}
// 		break;
// 	case VT_BSTR:
// 		type = adVarChar;
// 		{
// 			_bstr_t str(var->bstrVal);
// 			size = (str.length()+1)*sizeof(wchar_t);
// 			if(size <= 0) size = 1*sizeof(wchar_t);
// 			if(size >250)
// 			{
// 				//ACCESS数据库，如果是备注型的，字符串长度超过255时，使用adVarChar会出错
// 				type = adLongVarWChar;
// 			}
// 		}
// 		break;
// 	case VT_DECIMAL:
// 		type = adDecimal;
// 		size = sizeof(DECIMAL);
// 		break;
// 	case VT_BLOB:
// 		type = adBinary;
// 	default:
// 		_ASSERT(FALSE);
// 		return FALSE;
// 	}
// 	return TRUE;
// }

int CDataHandler::String2Hex(CString str, char *SendOut)
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
TCHAR CDataHandler::ConvertHexData(TCHAR ch)
{
	if((ch>='0')&&(ch<='9'))
		return ch-0x30;
	if((ch>='A')&&(ch<='F'))
		return ch-'A'+10;
	if((ch>='a')&&(ch<='f'))
		return ch-'a'+10;
	else return(-1);
}

CString CDataHandler::DectoHexstr(int iDec)
{
	if(iDec >= 65535)
		iDec = 0;
	CString str;
	str.Format(_T("%x"),iDec);
	//	sprintf(hex, _T("%x"), iDec);
	return str;
}
/**********************************
函数名：formatlength
参数：strHexMaclength(16进制地址串长度)
返回值：指令中标准的地址长度
说明：指令中地址长度格式为"xx xx" 通过转换过来的地址长度，进行标准化
***********************************/
CString CDataHandler::FormatLength(CString strHexMaclength)
{
	CString ret = _T("");
	if(strHexMaclength == _T("0"))
		return _T("00 00 ");
	int i = strHexMaclength.GetLength();
	switch(i)
	{
	case 0:
		ret = _T("00 00 ");
		return ret;
		break;
	case 1:
		ret = _T("00 0") + strHexMaclength + _T(" ");
		return ret;
		break;
	case 2:
		ret = _T("00 ") + strHexMaclength + _T(" ");
		return ret;
	case 3:
		strHexMaclength.Insert(0, _T("0"));
		strHexMaclength.Insert(2, _T(" "));
		strHexMaclength.Insert(5, _T(" "));
		ret = strHexMaclength;
		return ret;
		break;
	case 4:
		strHexMaclength.Insert(2, _T(" "));
		strHexMaclength.Insert(5, _T(" "));
		ret = strHexMaclength;
		return ret;
		break;
	default:
		return ret;
		break;
	}
}
/************************************
函数名：formatNO
参数：strNO(16进制题号长度字符串)
返回值：指令中标准的题号长度
说明：
************************************/
CString CDataHandler::FormatNO(CString strNO)
{
	int iLength = strNO.GetLength();
	if(iLength == 2)
	{
		strNO = strNO+_T(" ");
	}
	else if(iLength == 1)
	{
		//if(strNO == "0")
		//	strNO = "ff ";
		//	else
		strNO = _T("0") + strNO+ _T(" ");
	}
	else 
		strNO = _T("ff ");

	return strNO;
}

CString CDataHandler::DateTimeToStr(COleDateTime dt,int _iType)
{
	CString str;
	if(_iType == 0)
	{
		//str = dt.Format(YD_DATE_FORMAT);
	}
	else if(_iType == 1)
	{
		str.Format(_T("%04d-%02d-%02d"),dt.GetYear(),dt.GetMonth(),dt.GetDay());
	}
	else if(_iType == 2)
	{
		str.Format(_T("%02d:%02d:%02d"),dt.GetHour(),dt.GetMinute(),dt.GetSecond());
	}
	else 
	{
		ASSERT(FALSE);
	}
	return str;
}

BOOL CDataHandler::StringIsDigit(CString _str)
{
	if(_str.IsEmpty())
	{
		return FALSE;
	}
	for(int i = 0; i < _str.GetLength();i++)
	{
		TCHAR ch = _str.GetAt(i);
		if(ch != _T('-') &&
			ch != _T('.') &&
			!isdigit(ch))
		{
			return FALSE;
		}
	}
	return TRUE;
}