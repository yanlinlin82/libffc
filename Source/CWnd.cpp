// Wnd.cpp

#include "../Include/afxwin.h"
#include <map>

///////////////////////////////////////////////////////////////////////////

RECT CWnd::rectDefault =
{
	CW_USEDEFAULT,
	CW_USEDEFAULT,
	CW_USEDEFAULT,
	CW_USEDEFAULT
};

IMPLEMENT_DYNCREATE(CWnd, CCmdTarget)

///////////////////////////////////////////////////////////////////////////

std::map<HWND, CWnd*> g_WndMap;

void CWnd::Attach(HWND hWnd)
{
	ASSERT(m_hWnd == NULL);
	g_WndMap.insert(std::pair<HWND, CWnd*>(hWnd, this));
	m_hWnd = hWnd;
}

HWND CWnd::Detach()
{
	ASSERT(m_hWnd);
	HWND hWnd = m_hWnd;
	m_hWnd = NULL;
	return hWnd;
}

CWnd* CWnd::FromHandle(HWND hWnd)
{
	std::map<HWND, CWnd*>::iterator it = g_WndMap.find(hWnd);
	if (it == g_WndMap.end())
	{
		TRACE("HWND(0x%p) not found in WndMap\n", hWnd);
		return NULL;
	}
	CWnd* pWnd = it->second;
	ASSERT(pWnd);
	return pWnd;
}

LRESULT CALLBACK WindowProcStart(HWND hWnd, UINT msg, WPARAM w, LPARAM l)
{
	CWnd* pWnd = CWnd::FromHandle(hWnd);
	ASSERT(pWnd);
	return pWnd->WindowProc(msg, w, l);
}

HHOOK g_hHook = NULL;
CWnd* g_pWnd = NULL;

LRESULT CALLBACK CallWndProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode == HC_ACTION)
	{
		if (g_pWnd)
		{
			PCWPSTRUCT p = reinterpret_cast<PCWPSTRUCT>(lParam);
			g_pWnd->Attach(p->hwnd);
			g_pWnd = NULL;
		}
	}
	return ::CallNextHookEx(g_hHook, nCode, wParam, lParam);
}

///////////////////////////////////////////////////////////////////////////

CWnd::CWnd() : m_hWnd(NULL)
{
}

BOOL CWnd::Create(
	LPCTSTR lpszClassName,
	LPCTSTR lpszWindowName,
	DWORD dwStyle,
	const RECT& rect,
	CWnd* pParentWnd,
	UINT nID,
	CCreateContext* pContext)
{
	return CreateEx(0, lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

BOOL CWnd::CreateEx(
	DWORD dwExStyle,
	LPCTSTR lpszClassName,
	LPCTSTR lpszWindowName,
	DWORD dwStyle,
	int x,
	int y,
	int nWidth,
	int nHeight,
	HWND hWndParent,
	HMENU nIDorHMenu,
	LPVOID lpParam)
{
	UINT classStyle = CS_HREDRAW | CS_VREDRAW;
	HCURSOR hCursor = ::LoadCursor(NULL, IDC_ARROW);
	HBRUSH  hBrush  = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
	HICON   hIcon   = ::LoadIcon(NULL, IDI_APPLICATION);

	CString className;
	if (lpszClassName == NULL)
	{
		className.Format(_T("Afx:%x:%x:%x:%x:%x"),
			AfxGetInstanceHandle(),
			classStyle,
			hCursor,
			hBrush,
			hIcon);
		lpszClassName = className;
	}
	TRACE(_T("CWnd::CreateEx: %s (%s)\n"), (LPCTSTR)className, GetRuntimeClass()->m_lpszClassName);

	WNDCLASS wndClass;
	ZeroMemory(&wndClass, sizeof(wndClass));
	if ( ! ::GetClassInfo(
		AfxGetInstanceHandle(),
		lpszClassName,
		&wndClass))
	{
		wndClass.style         = classStyle;
		wndClass.lpfnWndProc   = ::WindowProcStart;
		wndClass.hInstance     = AfxGetInstanceHandle();
		wndClass.lpszClassName = lpszClassName;
		wndClass.hbrBackground = hBrush;
		wndClass.hCursor       = hCursor;
		wndClass.hIcon         = hIcon;
		if ( ! ::RegisterClass(&wndClass))
		{
			TRACE("RegisterClass failed! Error: %lu\n", ::GetLastError());
			return FALSE;
		}
	}

	CREATESTRUCT cs;
	ZeroMemory(&cs, sizeof(cs));
	if ( ! PreCreateWindow(cs))
	{
		return FALSE;
	}

	g_hHook = ::SetWindowsHookEx(WH_CALLWNDPROC, CallWndProc, NULL, ::GetCurrentThreadId());
	g_pWnd = this;

#ifdef _DEBUG
	HWND hWnd =
#endif
	::CreateWindowEx(
		dwExStyle,
		lpszClassName,
		lpszWindowName,
		dwStyle,
		x, y, nWidth, nHeight,
		hWndParent,
		nIDorHMenu,
		AfxGetInstanceHandle(),
		lpParam);

	ASSERT(hWnd == m_hWnd);
	::UnhookWindowsHookEx(g_hHook);
	g_hHook = NULL;
	g_pWnd = NULL;

	return (m_hWnd != NULL);
}

BOOL CWnd::CreateEx(
	DWORD dwExStyle,
	LPCTSTR lpszClassName,
	LPCTSTR lpszWindowName,
	DWORD dwStyle,
	const RECT& rect,
	CWnd* pParentWnd,
	UINT nID,
	LPVOID lpParam)
{
	return CreateEx(
		dwExStyle,
		lpszClassName,
		lpszWindowName,
		dwStyle,
		rect.left,
		rect.top,
		(rect.right == static_cast<int>(CW_USEDEFAULT) ? CW_USEDEFAULT : rect.right - rect.left),
		(rect.bottom == static_cast<int>(CW_USEDEFAULT) ? CW_USEDEFAULT : rect.bottom - rect.top),
		(pParentWnd ? pParentWnd->GetSafeHwnd() : NULL),
		reinterpret_cast<HMENU>(nID),
		lpParam);
}

///////////////////////////////////////////////////////////////////////////

BOOL CWnd::IsIconic() const
{
	return ::IsIconic(m_hWnd);
}

BOOL CWnd::ShowWindow(int nCmdShow)
{
	return ::ShowWindow(m_hWnd, nCmdShow);
}

void CWnd::UpdateWindow()
{
	::UpdateWindow(m_hWnd);
}

LRESULT CWnd::SendMessage(UINT msg, WPARAM w, LPARAM l)
{
	return ::SendMessage(m_hWnd, msg, w, l);
}

LRESULT CWnd::PostMessage(UINT msg, WPARAM w, LPARAM l)
{
	return ::PostMessage(m_hWnd, msg, w, l);
}

void CWnd::GetClientRect(LPRECT lpRect) const
{
	::GetClientRect(m_hWnd, lpRect);
}

INT_PTR CWnd::MessageBox(LPCTSTR text, LPCTSTR title, int type)
{
	return ::MessageBox(m_hWnd, text, title, type);
}

CMenu* CWnd::GetSystemMenu(BOOL /*bRevert*/) const
{
	return NULL;
}

HICON CWnd::SetIcon(HICON hIcon, BOOL bBigIcon)
{
	LRESULT r = ::SendMessage(m_hWnd, WM_SETICON,
		(bBigIcon ? ICON_BIG : ICON_SMALL),
		reinterpret_cast<LPARAM>(hIcon));
	return reinterpret_cast<HICON>(r);
}

BOOL CWnd::SetMenu(CMenu* pMenu)
{
	ASSERT(m_hWnd != NULL);
	ASSERT(pMenu != NULL);
	ASSERT(pMenu->m_hMenu != NULL);
	return ::SetMenu(m_hWnd, pMenu->m_hMenu);
}

///////////////////////////////////////////////////////////////////////////

BOOL CWnd::PreCreateWindow(CREATESTRUCT& /*cs*/)
{
	return TRUE;
}

LRESULT CWnd::WindowProc(UINT msg, WPARAM w, LPARAM l)
{
	LRESULT r = 0;
	if ( ! _ProcessMessage(m_hWnd, msg, w, l, r))
	{
		return DefWindowProc(msg, w, l);
	}
	return r;
}

LRESULT CWnd::DefWindowProc(UINT msg, WPARAM w, LPARAM l)
{
	return ::DefWindowProc(m_hWnd, msg, w, l);
}

void CWnd::PostNcDestroy()
{
}

void CWnd::DoDataExchange(CDataExchange* /*pDX*/)
{
}

///////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CWnd, CCmdTarget)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////////////////////

int CWnd::OnCreate(LPCREATESTRUCT)
{
	return 0;
}

void CWnd::OnPaint()
{
	CPaintDC dc(this);
}

void CWnd::OnSysCommand(UINT id, LPARAM l)
{
	::DefWindowProc(m_hWnd, WM_SYSCOMMAND, id, l);
}

void CWnd::OnNcDestroy()
{
	PostNcDestroy();
}

///////////////////////////////////////////////////////////////////////////

