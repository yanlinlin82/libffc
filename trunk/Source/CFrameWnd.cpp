// FrameWnd.cpp

#include "../Include/afxwin.h"

///////////////////////////////////////////////////////////////////////////

BOOL CFrameWnd::Create(
	LPCTSTR lpszClassName,
	LPCTSTR lpszWindowName,
	DWORD dwStyle,
	const RECT& rect,
	CWnd* pParentWnd,
	LPCTSTR lpszMenuName,
	DWORD /*dwExStyle*/,
	CCreateContext* pContext)
{
	return CWnd::Create(
		lpszClassName,
		lpszWindowName,
		dwStyle,
		rect,
		pParentWnd,
		reinterpret_cast<UINT>(lpszMenuName),
		pContext);
}

BOOL CFrameWnd::LoadFrame(
	UINT /*nIDResource*/,
	DWORD /*dwDefaultStyle*/,
	CWnd* /*pParentWnd*/,
	CCreateContext* /*pContext*/)
{
	return FALSE;
}

void CFrameWnd::EnableDocking(DWORD /*dwDockStyle*/)
{
}

void CFrameWnd::DockControlBar(CControlBar* /*pBar*/, UINT /*nDockBarID*/, LPCRECT /*lpRect*/)
{
}

///////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CFrameWnd, CWnd)
	ON_WM_NCDESTROY()
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////////////////////

void CFrameWnd::OnNcDestroy()
{
	::PostQuitMessage(0);
	delete this;
}

///////////////////////////////////////////////////////////////////////////

