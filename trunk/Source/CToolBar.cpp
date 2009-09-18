// CToolBar.cpp

#include "../Include/afxwin.h"
#include "../Include/afxcmn.h"

///////////////////////////////////////////////////////////////////////////

BOOL CToolBar::CreateEx(
	CWnd* /*pParentWnd*/,
	DWORD /*dwCtrlStyle*/,
	DWORD /*dwStyle*/,
	CRect /*rcBorders*/,
	UINT /*nID*/)
{
	return TRUE;
}

BOOL CToolBar::LoadToolBar(LPCTSTR /*lpszResourceName*/)
{
	return TRUE;
}

BOOL CToolBar::LoadToolBar(UINT nIDResource)
{
	return LoadToolBar(MAKEINTRESOURCE(nIDResource));
}

///////////////////////////////////////////////////////////////////////////

