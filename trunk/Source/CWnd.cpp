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

BOOL AFXAPI AfxRegisterClass(WNDCLASS* lpWndClass)
{
	return (::RegisterClass(lpWndClass) != 0);
}

LPCTSTR AFXAPI AfxRegisterWndClass(UINT classStyle, HCURSOR hCursor, HBRUSH hBrush, HICON hIcon)
{
	HINSTANCE hInst = AfxGetInstanceHandle();

	CONST SIZE_T BUFFER_SIZE = 64;
	static TCHAR className[BUFFER_SIZE] = _T("");
	wsprintf(className, _T("Afx:%x:%x:%x:%x:%x"),
		hInst, classStyle, hCursor, hBrush, hIcon);
	TRACE(_T("AfxRegisterWndClass: %s\n"), className);

	WNDCLASS wndClass;
	ZeroMemory(&wndClass, sizeof(wndClass));
	if ( ! ::GetClassInfo(hInst, className, &wndClass))
	{
		wndClass.style         = classStyle;
		wndClass.lpfnWndProc   = ::WindowProcStart;
		wndClass.hInstance     = hInst;
		wndClass.lpszClassName = className;
		wndClass.hbrBackground = (hBrush ? hBrush : reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1));
		wndClass.hCursor       = (hCursor ? hCursor : ::LoadCursor(NULL, IDC_ARROW));
		wndClass.hIcon         = (hIcon ? hIcon : ::LoadIcon(NULL, IDI_APPLICATION));
		if ( ! ::RegisterClass(&wndClass))
		{
			TRACE("RegisterClass failed! Error: %lu\n", ::GetLastError());
			return NULL;
		}
	}
	return className;
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
	CREATESTRUCT cs;
	cs.lpCreateParams = lpParam;
	cs.hInstance      = AfxGetInstanceHandle();
	cs.hMenu          = nIDorHMenu;
	cs.hwndParent     = hWndParent;
	cs.cx             = nWidth;
	cs.cy             = nHeight;
	cs.x              = x;
	cs.y              = y;
	cs.style          = dwStyle;
	cs.dwExStyle      = dwExStyle;
	cs.lpszName       = lpszWindowName;
	cs.lpszClass      = lpszClassName;
	if ( ! PreCreateWindow(cs))
	{
		return FALSE;
	}

	if ( ! cs.lpszClass)
	{
		cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW);
	}

	if (g_hHook)
	{
		::UnhookWindowsHookEx(g_hHook);
		g_hHook = NULL;
	}
	g_hHook = ::SetWindowsHookEx(WH_CALLWNDPROC, CallWndProc, NULL, ::GetCurrentThreadId());
	g_pWnd = this;

#ifdef _DEBUG
	HWND hWnd =
#endif
	::CreateWindowEx(
		cs.dwExStyle,
		cs.lpszClass,
		cs.lpszName,
		cs.style,
		cs.x, cs.y, cs.cx, cs.cy,
		cs.hwndParent,
		cs.hMenu,
		cs.hInstance,
		cs.lpCreateParams);

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

BOOL CWnd::PreCreateWindow(CREATESTRUCT& /*cs*/)
{
	return TRUE;
}

LRESULT CWnd::WindowProc(UINT msg, WPARAM w, LPARAM l)
{
	if (msg == WM_COMMAND)
	{
		return OnCommand(w, l);
	}
	if (_ProcessMessage(_Check, m_hWnd, msg, w, l))
	{
		return _ProcessMessage(_Message, m_hWnd, msg, w, l);
	}
	return DefWindowProc(msg, w, l);
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
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////////////////////

int CWnd::OnCreate(LPCREATESTRUCT)
{
	return 0;
}

void CWnd::OnSize(UINT /*type*/, int /*cx*/, int /*cy*/)
{
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

BOOL CWnd::OnCommand(WPARAM w, LPARAM)
{
	return OnCmdMsg(LOWORD(w), HIWORD(w), NULL, NULL);
}

///////////////////////////////////////////////////////////////////////////

