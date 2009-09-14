// DC.cpp

#include "../Include/afxwin.h"

///////////////////////////////////////////////////////////////////////////

CDC::CDC()
	: m_hDC(NULL)
{
}

int CDC::DrawText(
	LPCTSTR lpszString,
	int nCount,
	LPRECT lpRect,
	UINT nFormat)
{
	return ::DrawText(m_hDC, lpszString, nCount, lpRect, nFormat);
}

int CDC::DrawText(
	const CString& str,
	LPRECT lpRect,
	UINT nFormat)
{
	return DrawText(str, -1, lpRect, nFormat);
}

BOOL CDC::DrawIcon(int x, int y, HICON hIcon)
{
	return ::DrawIcon(m_hDC, x, y, hIcon);
}

BOOL CDC::DrawIcon(POINT point, HICON hIcon)
{
	return ::DrawIcon(m_hDC, point.x, point.y, hIcon);
}

///////////////////////////////////////////////////////////////////////////

CPaintDC::CPaintDC(CWnd* pWnd)
	: m_hWnd(pWnd ? pWnd->m_hWnd : NULL)
{
	m_hDC = ::BeginPaint(m_hWnd, &m_ps);
}

CPaintDC::~CPaintDC()
{
	::EndPaint(m_hWnd, &m_ps);
}

///////////////////////////////////////////////////////////////////////////

