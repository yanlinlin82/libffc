// AfxApi.cpp

#include "../Include/afx.h"

///////////////////////////////////////////////////////////////////////////

HINSTANCE g_hInst     = NULL;
HINSTANCE g_hResInst  = NULL;
LPTSTR    g_lpCmdLine = NULL;
int       g_nCmdShow  = 0;

///////////////////////////////////////////////////////////////////////////

BOOL AFXAPI AfxWinInit(HINSTANCE hInst, HINSTANCE, LPTSTR lpCmdLine, int nCmdShow)
{
	g_hInst     = hInst;
	g_hResInst  = hInst;
	g_lpCmdLine = lpCmdLine;
	g_nCmdShow  = nCmdShow;
	return TRUE;
}

HINSTANCE AFXAPI AfxGetInstanceHandle()
{
	return g_hInst;
}

void AFXAPI AfxEnableControlContainer()
{
}

HINSTANCE AfxGetResourceHandle()
{
	return ::GetModuleHandle(NULL);
}

///////////////////////////////////////////////////////////////////////////

BOOL AFXAPI AfxOleInit()
{
	HRESULT hr = ::CoInitialize(NULL);
	return SUCCEEDED(hr);
}

int AFXAPI AfxMessageBox(LPCTSTR lpszText, UINT nType, UINT /*nIDHelp*/)
{
	return ::MessageBox(NULL, lpszText, NULL, nType);
}

int AFXAPI AfxMessageBox(UINT nIDPrompt, UINT nType, UINT nIDHelp)
{
	CString text;
	text.LoadString(nIDPrompt);
	return AfxMessageBox(text, nType, nIDHelp);
}

///////////////////////////////////////////////////////////////////////////

