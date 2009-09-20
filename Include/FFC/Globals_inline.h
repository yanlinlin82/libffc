// Globals_inline.h
#ifndef __FFC_GLOBALS_INLINE_H__
#define __FFC_GLOBALS_INLINE_H__
///////////////////////////////////////////////////////////////////////////

#include "Globals.h"
#include "CString.h"

///////////////////////////////////////////////////////////////////////////

inline BOOL AFXAPI AfxOleInit()
{
	HRESULT hr = ::CoInitialize(NULL);
	return SUCCEEDED(hr);
}

inline void AFXAPI AfxEnableControlContainer()
{
}

///////////////////////////////////////////////////////////////////////////

inline int AFXAPI AfxMessageBox(LPCTSTR lpszText, UINT nType/* = MB_OK*/, UINT/* nIDHelp = 0*/)
{
	return ::MessageBox(::GetActiveWindow(), lpszText, NULL, nType);
}

inline int AFXAPI AfxMessageBox(UINT nIDPrompt, UINT nType/* = MB_OK*/, UINT nIDHelp/* = (UINT)-1*/)
{
	CString text;
	text.LoadString(nIDPrompt);
	return AfxMessageBox(text, nType, nIDHelp);
}

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_GLOBALS_INLINE_H__

