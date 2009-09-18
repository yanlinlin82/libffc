// CStatusBar.cpp

#include "../Include/afxwin.h"
#include "../Include/afxcmn.h"

///////////////////////////////////////////////////////////////////////////

BOOL CStatusBar::Create(
	CWnd* /*pParentWnd*/,
	DWORD /*dwStyle*/,
	UINT /*nID*/)
{
	return TRUE;
}

BOOL CStatusBar::CreateEx(
	CWnd* /*pParentWnd*/,
	DWORD /*dwCtrlStyle*/,
	DWORD /*dwStyle*/,
	UINT /*nID*/)
{
	return TRUE;
}

BOOL CStatusBar::SetIndicators(const UINT* /*lpIDArray*/, int /*nIDCount*/)
{
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////

