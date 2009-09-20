// Globals.cpp

#include "../Include/FFC/Globals.h"
#include "../Include/FFC/CString.h"

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

///////////////////////////////////////////////////////////////////////////

HINSTANCE AFXAPI AfxGetInstanceHandle()
{
	return g_hInst;
}

HINSTANCE AfxGetResourceHandle()
{
	return ::GetModuleHandle(NULL);
}

///////////////////////////////////////////////////////////////////////////

