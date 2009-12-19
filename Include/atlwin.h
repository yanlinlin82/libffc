// atlwin.h
//
// This is part of FFC (Free Foundation Classes).
//
// Anthor: Linlin Yan (yanlinlin82[at]gmail.com).
//
// Any sugguestion is welcome.

#ifndef __ATLWIN_H__
#define __ATLWIN_H__
///////////////////////////////////////////////////////////////////////////

#include <atlbase.h>
#include <tchar.h>

///////////////////////////////////////////////////////////////////////////

#define DECLARE_WND_CLASS_EX(className, classStyle, background)
#define DECLARE_WND_CLASS(className)

///////////////////////////////////////////////////////////////////////////

template <class T>
class CWindowImpl
{
public:
	explicit CWindowImpl(HWND hWnd = NULL)
		: m_hWnd(hWnd)
	{ }

public:
	LRESULT DefWndProc(UINT msg, WPARAM w, LPARAM l)
	{
		return ::DefWindowProc(m_hWnd, msg, w, l);
	}

public:
	BOOL Create(HWND hParentWnd, const RECT& rect, LPCTSTR windowName, DWORD style)
	{
		LPCTSTR className = _T("BUTTON");
		HINSTANCE hInst = ::GetModuleHandle(NULL);
		m_hWnd = ::CreateWindowEx(0, className, windowName, style,
			rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
			hParentWnd, NULL, hInst, NULL);
		return (m_hWnd != NULL);
	}

	BOOL CenterWindow()
	{
		int cx = ::GetSystemMetrics(SM_CXSCREEN);
		int cy = ::GetSystemMetrics(SM_CYSCREEN);
		RECT rect;
		GetWindowRect(m_hWnd, &rect);
		return ::SetWindowPos(m_hWnd, NULL,
			(cx - (rect.right - rect.left)) / 2,
			(cy - (rect.bottom - rect.top)) / 2,
			0, 0, SWP_NOSIZE | SWP_NOZORDER);
	}

	BOOL ShowWindow(int showCmd)
	{
		return ::ShowWindow(m_hWnd, showCmd);
	}

	BOOL UpdateWindow()
	{
		return ::UpdateWindow(m_hWnd);
	}

	BOOL InvalidateRect(const RECT* pRect = NULL, BOOL erase = TRUE)
	{
		return ::InvalidateRect(m_hWnd, pRect, erase);
	}

public:
	HWND m_hWnd;
};

///////////////////////////////////////////////////////////////////////////

#define BEGIN_MSG_MAP(className) \
	LRESULT _WndProc(UINT msg, WPARAM w, LPARAM l) \
	{ \
		BOOL handled = FALSE; \
		LRESULT r = 0;

#define MESSAGE_HANDLER(m, proc) \
		if (msg == m) \
		{ \
			r = proc(msg, w, l, handled); \
		}

#define END_MSG_MAP() \
		if (handled) return r; \
		return DefWndProc(msg, w, l); \
	}

///////////////////////////////////////////////////////////////////////////
#endif//__ATLWIN_H__

