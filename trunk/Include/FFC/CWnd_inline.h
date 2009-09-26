// CWnd_inline.h
#ifndef __FFC_CWND_INLINE_H__
#define __FFC_CWND_INLINE_H__
///////////////////////////////////////////////////////////////////////////

#include "CWnd.h"
#include "CWinApp.h"

///////////////////////////////////////////////////////////////////////////

inline BOOL CWnd::IsIconic() const
{
	return ::IsIconic(m_hWnd);
}

inline void CWnd::MoveWindow(int x, int y, int w, int h, BOOL repaint)
{
	ASSERT(m_hWnd != NULL);
	::MoveWindow(m_hWnd, x, y, w, h, repaint);
}

inline void CWnd::MoveWindow(LPCRECT pRect, BOOL repaint)
{
	MoveWindow(
		pRect->left,
		pRect->top,
		pRect->right - pRect->left, 
		pRect->bottom - pRect->top,
		repaint);
}

inline BOOL CWnd::SetWindowPos(const CWnd* pWndInsertAfter, int x, int y, int cx, int cy, UINT flags)
{
	ASSERT(m_hWnd != NULL);
	return ::SetWindowPos(m_hWnd,
		(pWndInsertAfter ? pWndInsertAfter->GetSafeHwnd() : NULL),
		x, y, cx, cy, flags);
}

inline BOOL CWnd::ShowWindow(int nCmdShow)
{
	ASSERT(m_hWnd != NULL);
	return ::ShowWindow(m_hWnd, nCmdShow);
}

inline void CWnd::UpdateWindow()
{
	ASSERT(m_hWnd != NULL);
	::UpdateWindow(m_hWnd);
}

inline LRESULT CWnd::SendMessage(UINT msg, WPARAM w, LPARAM l)
{
	ASSERT(m_hWnd != NULL);
	return ::SendMessage(m_hWnd, msg, w, l);
}

inline LRESULT CWnd::PostMessage(UINT msg, WPARAM w, LPARAM l)
{
	ASSERT(m_hWnd != NULL);
	return ::PostMessage(m_hWnd, msg, w, l);
}

inline void CWnd::GetWindowRect(LPRECT lpRect) const
{
	ASSERT(m_hWnd != NULL);
	::GetWindowRect(m_hWnd, lpRect);
}

inline void CWnd::GetClientRect(LPRECT lpRect) const
{
	ASSERT(m_hWnd != NULL);
	::GetClientRect(m_hWnd, lpRect);
}

inline void CWnd::CenterWindow(CWnd* pAlternateOwner)
{
	ASSERT(m_hWnd != NULL);
	RECT parentRect = { 0, 0, 0, 0 };
	if (pAlternateOwner)
	{
		pAlternateOwner->GetWindowRect(&parentRect);
	}
	else
	{
		parentRect.right = ::GetSystemMetrics(SM_CXSCREEN);
		parentRect.bottom = ::GetSystemMetrics(SM_CYSCREEN);
	}

	RECT rect;
	GetWindowRect(&rect);
	int x = parentRect.left + ((parentRect.right - parentRect.left) - (rect.right - rect.left)) / 2;
	int y = parentRect.top + ((parentRect.bottom - parentRect.top) - (rect.bottom - rect.top)) / 2;
	SetWindowPos(NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

inline INT_PTR CWnd::MessageBox(LPCTSTR text, LPCTSTR title, int type)
{
	ASSERT(m_hWnd != NULL);
	return ::MessageBox(m_hWnd, text, title, type);
}

inline CMenu* CWnd::GetSystemMenu(BOOL /*bRevert*/) const
{
	ASSERT(m_hWnd != NULL);
	return NULL;
}

inline HICON CWnd::SetIcon(HICON hIcon, BOOL bBigIcon)
{
	ASSERT(m_hWnd != NULL);
	LRESULT r = ::SendMessage(m_hWnd, WM_SETICON,
		(bBigIcon ? ICON_BIG : ICON_SMALL),
		reinterpret_cast<LPARAM>(hIcon));
	return reinterpret_cast<HICON>(r);
}

inline BOOL CWnd::SetMenu(CMenu* pMenu)
{
	ASSERT(m_hWnd != NULL);
	ASSERT(pMenu != NULL);
	ASSERT(pMenu->m_hMenu != NULL);
	return ::SetMenu(m_hWnd, pMenu->m_hMenu);
}

///////////////////////////////////////////////////////////////////////////

inline CWnd* AFXAPI AfxGetMainWnd()
{
	return AfxGetApp()->m_pMainWnd;
}

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_CWND_INLINE_H__

