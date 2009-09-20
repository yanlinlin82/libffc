// Globals.h
#ifndef __FFC_GLOBALS_H__
#define __FFC_GLOBALS_H__
///////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <tchar.h>

#include <cstdio>
#include <cassert>

///////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG
#define ASSERT(x) assert(x)
#define ASSERT_VALID(pObj) assert(pObj)
#else
#define ASSERT(x)
#define ASSERT_VALID(pObj)
#endif

#ifndef NDEBUG
#define TRACE(...) printf(__VA_ARGS__)
#define TRACE0(a0)  printf(a0)
#define TRACE1(a0, a1) printf(a0, a1)
#define TRACE2(a0, a1, a2) printf(a0, a1, a2)
#define TRACE3(a0, a1, a2, a3) printf(a0, a1, a2, a3)
#define TRACE4(a0, a1, a2, a3, a4) printf(a0, a1, a2, a3, a4)
#else
#define TRACE(...)
#define TRACE0(a0)
#define TRACE1(a0, a1)
#define TRACE2(a0, a1, a2)
#define TRACE3(a0, a1, a2, a3)
#define TRACE4(a0, a1, a2, a3, a4)
#endif

///////////////////////////////////////////////////////////////////////////

#define AFXAPI
#define DEBUG_NEW new

///////////////////////////////////////////////////////////////////////////

BOOL AFXAPI AfxWinInit(HINSTANCE hInst,	HINSTANCE hPrevInst, LPTSTR cmdLine, int cmdShow);

BOOL AFXAPI AfxOleInit();

void AFXAPI AfxEnableControlContainer();

///////////////////////////////////////////////////////////////////////////

HINSTANCE AFXAPI AfxGetInstanceHandle();
HINSTANCE AFXAPI AfxGetResourceHandle();

///////////////////////////////////////////////////////////////////////////

int AFXAPI AfxMessageBox(LPCTSTR lpszText, UINT nType = MB_OK, UINT nIDHelp = 0);
int AFXAPI AfxMessageBox(UINT nIDPrompt, UINT nType = MB_OK, UINT nIDHelp = (UINT)-1);

///////////////////////////////////////////////////////////////////////////

#include "Globals_inline.h"

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_GLOBALS_H__

