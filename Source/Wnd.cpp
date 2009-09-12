// Wnd.cpp

#include <afxwin.h>
#include <map>

///////////////////////////////////////////////////////////////////////////

RECT CWnd::rectDefault =
{
	CW_USEDEFAULT,
	CW_USEDEFAULT,
	CW_USEDEFAULT,
	CW_USEDEFAULT
};

///////////////////////////////////////////////////////////////////////////

std::map<HWND, CWnd*> g_WndMap;

LRESULT CALLBACK WindowProcStart(HWND hWnd, UINT msg, WPARAM w, LPARAM l)
{
	std::map<HWND, CWnd*>::iterator it = g_WndMap.find(hWnd);
	if (it == g_WndMap.end())
	{
		TRACE("HWND(0x%p) not found in WndMap\n", hWnd);
		return ::DefWindowProc(hWnd, msg, w, l);
	}
	CWnd* pWnd = it->second;
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
			g_WndMap.insert(std::pair<HWND, CWnd*>(p->hwnd, g_pWnd));
			g_pWnd->m_hWnd = p->hwnd;
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
	if (lpszClassName == NULL)
	{
		lpszClassName = _T("TestWindow");
	}
	
	WNDCLASS wndClass = { 0 };
	if ( ! ::GetClassInfo(
		AfxGetInstanceHandle(),
		lpszClassName,
		&wndClass))
	{
		wndClass.style         = CS_HREDRAW | CS_VREDRAW;
		wndClass.lpfnWndProc   = ::WindowProcStart;
		wndClass.hInstance     = AfxGetInstanceHandle();
		wndClass.lpszClassName = lpszClassName;
		wndClass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
		wndClass.hCursor       = ::LoadCursor(NULL, IDC_ARROW);
		if ( ! ::RegisterClass(&wndClass))
		{
			TRACE("RegisterClass failed! Error: %lu\n", ::GetLastError());
			return FALSE;
		}
	}
	
	g_hHook = ::SetWindowsHookEx(WH_CALLWNDPROC, CallWndProc, NULL, ::GetCurrentThreadId());
	g_pWnd = this;

	HWND hWnd = ::CreateWindowEx(
		0,
		lpszClassName,
		lpszWindowName,
		dwStyle,
		rect.left,
		rect.top,
		(rect.right == static_cast<int>(CW_USEDEFAULT) ? CW_USEDEFAULT : rect.right - rect.left),
		(rect.bottom == static_cast<int>(CW_USEDEFAULT) ? CW_USEDEFAULT : rect.bottom - rect.top),
		(pParentWnd ? pParentWnd->m_hWnd : NULL),
		reinterpret_cast<HMENU>(nID),
		AfxGetInstanceHandle(),
		pContext);

	ASSERT(hWnd == m_hWnd);
	::UnhookWindowsHookEx(g_hHook);
	g_hHook = NULL;
	g_pWnd = NULL;

	return (m_hWnd != NULL);
}

BOOL CWnd::ShowWindow(int nCmdShow)
{
	return ::ShowWindow(m_hWnd, nCmdShow);
}

void CWnd::GetClientRect(LPRECT lpRect) const
{
	::GetClientRect(m_hWnd, lpRect);
}

INT_PTR CWnd::MessageBox(LPCTSTR text, LPCTSTR title, int type)
{
	return ::MessageBox(m_hWnd, text, title, type);
}

///////////////////////////////////////////////////////////////////////////

LRESULT CWnd::WindowProc(UINT msg, WPARAM w, LPARAM l)
{
	return DefWindowProc(msg, w, l);
}

LRESULT CWnd::DefWindowProc(UINT msg, WPARAM w, LPARAM l)
{
	return ::DefWindowProc(m_hWnd, msg, w, l);
}

void CWnd::PostNcDestroy()
{
}

void CWnd::OnNcDestroy()
{
	PostNcDestroy();
}

///////////////////////////////////////////////////////////////////////////

