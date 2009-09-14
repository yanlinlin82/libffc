// afx.h
//
// This is part of FFC (Free Foundation Classes).
//
// Anthor: Linlin Yan (yanlinlin82[at]gmail.com).
//
// Any sugguestion is welcome.

#ifndef __AFX_H__
#define __AFX_H__
///////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <tchar.h>

#include <cstdio>
#include <cassert>

#include "cstringt.h"

#include "FFC/CObject.h"
#include "FFC/CException.h"
#include "FFC/CFile.h"

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

BOOL AFXAPI AfxWinInit(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine,
	int nCmdShow);

///////////////////////////////////////////////////////////////////////////
#endif//__AFX_H__

