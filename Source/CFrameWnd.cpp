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
		rectDefault, pParentWnd, 0, WS_EX_CLIENTEDGE, pContext))
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

CWnd* CFrameWnd::CreateView(CCreateContext* pContext, UINT nID)
{
	ASSERT(pContext->m_pNewViewClass->IsDerivedFrom(RUNTIME_CLASS(CView)));
	CView* pView = static_cast<CView*>(pContext->m_pNewViewClass->CreateObject());
	pView->m_pDocument = pContext->m_pCurrentDoc;
	CRect rect;
	GetClientRect(rect);
	TRACE("Create View\n");
	pView->Create(NULL, NULL, WS_CHILD | WS_VISIBLE, rect, this, nID);
	m_ViewList.push_back(pView);
	return pView;
}

///////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CFrameWnd, CWnd)
	ON_WM_SIZE()
	ON_WM_NCDESTROY()
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////////////////////

void CFrameWnd::OnSize(UINT type, int cx, int cy)
{
	CWnd::OnSize(type, cx, cy);
	CView* pView = GetActiveView();
	if (pView)
	{
		pView->MoveWindow(0, 0, cx, cy);
	}
}

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

LRESULT CMDIChildWnd::DefWindowProc(UINT msg, WPARAM w, LPARAM l)
{
	return ::DefMDIChildProc(m_hWnd, msg, w, l);
}

///////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CMDIFrameWnd, CFrameWnd)

BEGIN_MESSAGE_MAP(CMDIFrameWnd, CFrameWnd)
	ON_WM_SIZE()
END_MESSAGE_MAP()

void CMDIFrameWnd::OnSize(UINT, int x, int y)
{
	if (m_MDIClient.GetSafeHwnd())
	{
		m_MDIClient.MoveWindow(0, 0, x, y);
	}
}

LRESULT CMDIFrameWnd::DefWindowProc(UINT msg, WPARAM w, LPARAM l)
{
	return ::DefFrameProc(m_hWnd, m_MDIClient.m_hWnd, msg, w, l);
}

///////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(CMiniFrameWnd, CFrameWnd)

///////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNCREATE(COleIPFrameWnd, CFrameWnd)

///////////////////////////////////////////////////////////////////////////

