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
	DWORD dwExStyle,
	CCreateContext* pContext)
{
	return CWnd::CreateEx(
		dwExStyle,
		lpszClassName,
		lpszWindowName,
		dwStyle,
		rect,
		pParentWnd,
		reinterpret_cast<UINT>(lpszMenuName),
		pContext);
}

BOOL CFrameWnd::LoadFrame(
	UINT nIDResource,
	DWORD dwDefaultStyle,
	CWnd* pParentWnd,
	CCreateContext* pContext)
{
	CString title;
	title.LoadString(nIDResource);
	
	if ( ! Create(NULL, title, dwDefaultStyle,
		rectDefault, pParentWnd, 0, 0, pContext))
	{
		return FALSE;
	}

	CMenu menu;
	if ( ! menu.LoadMenu(nIDResource))
	{
		return FALSE;
	}
	SetMenu(&menu);

	return TRUE;
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

IMPLEMENT_DYNCREATE(CFrameWnd, CWnd)

///////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CMDIChildWnd, CFrameWnd)

///////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CMDIFrameWnd, CFrameWnd)

///////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CMiniFrameWnd, CFrameWnd)

///////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(COleIPFrameWnd, CFrameWnd)

///////////////////////////////////////////////////////////////////////////

