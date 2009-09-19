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

BOOL CFrameWnd::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	TRACE("CFrameWnd::OnCmdMsg\n");
	CView* pView = GetActiveView();
	TRACE("pView = %p\n", pView);
	if (pView)
	{
		if (pView->OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		{
			return TRUE;
		}
	}

	TRACE("Call CWnd::OnCmdMsg() in {%s}\n", GetRuntimeClass()->m_lpszClassName);
	if (CWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
	{
		TRACE("CWnd::OnCmdMsg() return TRUE;\n");
		return TRUE;
	}

	CWinApp* pApp = AfxGetApp();
	TRACE("pApp = %p\n", pApp);
	if (pApp)
	{
		if (pApp->OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		{
			return TRUE;
		}
	}
	return FALSE;
}

///////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CFrameWnd, CWnd)

///////////////////////////////////////////////////////////////////////////

CView* CFrameWnd::GetActiveView() const
{
	if (m_ViewList.empty())
	{
		return NULL;
	}
	return m_ViewList.front();
}

///////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CMDIChildWnd, CFrameWnd)

///////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CMDIFrameWnd, CFrameWnd)

///////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CMiniFrameWnd, CFrameWnd)

///////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(COleIPFrameWnd, CFrameWnd)

///////////////////////////////////////////////////////////////////////////

