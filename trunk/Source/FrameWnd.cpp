// FrameWnd.cpp

#include <afxwin.h>

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
	return CWnd::Create(
		lpszClassName,
		lpszWindowName,
		dwStyle,
		rect,
		pParentWnd,
		reinterpret_cast<UINT>(lpszMenuName),
		pContext);
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

