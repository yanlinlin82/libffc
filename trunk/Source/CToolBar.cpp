// CToolBar.cpp

#include "../Include/afxwin.h"
#include "../Include/afxcmn.h"

///////////////////////////////////////////////////////////////////////////

BOOL CToolBar::CreateEx(
	CWnd* pParentWnd,
	DWORD dwCtrlStyle,
	DWORD dwStyle,
	CRect rcBorders,
	UINT nID)
{
	ASSERT(pParentWnd != NULL);
	ASSERT(pParentWnd->m_hWnd != NULL);
	m_hWnd = ::CreateWindowEx(0, TOOLBARCLASSNAME, NULL,
		dwCtrlStyle | dwStyle,
		rcBorders.left, rcBorders.top, rcBorders.Width(), rcBorders.Height(),
		pParentWnd->m_hWnd, reinterpret_cast<HMENU>(nID), AfxGetResourceHandle(), NULL);
	return (m_hWnd != NULL);
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

