// afxwin.h
//
// This is part of FFC (Free Foundation Classes).
//
// Anthor: Linlin Yan (yanlinlin82[at]gmail.com).
//
// Any sugguestion is welcome.

#ifndef __AFX_WIN_H__
#define __AFX_WIN_H__
///////////////////////////////////////////////////////////////////////////

#include "afx.h"
#include "atltypes.h"

///////////////////////////////////////////////////////////////////////////

struct CCreateContext
{
};

///////////////////////////////////////////////////////////////////////////

class CCmdTarget : public CObject
{
};

///////////////////////////////////////////////////////////////////////////

class CWnd;

class CDC : public CObject
{
public:
	CDC();

public:
	virtual int DrawText(
		LPCTSTR lpszString,
		int nCount,
		LPRECT lpRect,
		UINT nFormat);

	int DrawText(
		const CString& str,
		LPRECT lpRect,
		UINT nFormat);

public:
	HDC m_hDC;
};

class CPaintDC : public CDC
{
public:
	explicit CPaintDC(CWnd* pWnd);
	~CPaintDC();

public:
	PAINTSTRUCT m_ps;
	HWND m_hWnd;
};

///////////////////////////////////////////////////////////////////////////

#define afx_msg

///////////////////////////////////////////////////////////////////////////

class CWnd : public CCmdTarget
{
public:
	CWnd();

public:
	virtual BOOL Create(
		LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName,
		DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd,
		UINT nID,
		CCreateContext* pContext = NULL);
	
public:
	BOOL ShowWindow(int nCmdShow);
	void GetClientRect(LPRECT lpRect) const;
	INT_PTR MessageBox(LPCTSTR text, LPCTSTR title = NULL, int type = MB_OK);

public:
	virtual LRESULT WindowProc(UINT msg, WPARAM w, LPARAM l);
	virtual LRESULT DefWindowProc(UINT msg, WPARAM w, LPARAM l);
	virtual void PostNcDestroy();

protected:
	afx_msg void OnNcDestroy();

public:
	HWND m_hWnd;

	static RECT rectDefault;
};

///////////////////////////////////////////////////////////////////////////

#define DECLARE_MESSAGE_MAP() \
	virtual LRESULT WindowProc(UINT msg, WPARAM w, LPARAM l);

#define BEGIN_MESSAGE_MAP(thisClass, baseClass) \
	LRESULT thisClass::WindowProc(UINT msg, WPARAM w, LPARAM l) \
	{ \
		typedef baseClass base;

#define END_MESSAGE_MAP() \
		return base::WindowProc(msg, w, l); \
	}

#define ON_WM_CREATE() \
		if (msg == WM_CREATE) \
		{ \
			return OnCreate(reinterpret_cast<LPCREATESTRUCT>(l)); \
		}

#define ON_WM_PAINT() \
		if (msg == WM_PAINT) \
		{ \
			OnPaint(); \
			return 0; \
		}

#define ON_WM_NCDESTROY() \
		if (msg == WM_NCDESTROY) \
		{ \
			OnNcDestroy(); \
			return 0; \
		}

///////////////////////////////////////////////////////////////////////////

class CFrameWnd : public CWnd
{
public:
	virtual BOOL Create(
		LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName,
		DWORD dwStyle = WS_OVERLAPPEDWINDOW,
		const RECT& rect = rectDefault,
		CWnd* pParentWnd = NULL,
		LPCTSTR lpszMenuName = NULL,
		DWORD dwExStyle = 0,
		CCreateContext* pContext = NULL);

public:
	DECLARE_MESSAGE_MAP()

protected:
	afx_msg void OnNcDestroy();
};

///////////////////////////////////////////////////////////////////////////

class CWinThread : public CCmdTarget
{
};

///////////////////////////////////////////////////////////////////////////

class CWinApp : public CWinThread
{
public:
	CWinApp();

public:
	virtual BOOL InitInstance();
	virtual int Run();
	virtual void ExitInstance();

public:
	CWnd* m_pMainWnd;
};

///////////////////////////////////////////////////////////////////////////

CWinApp*  AFXAPI AfxGetApp();
HINSTANCE AFXAPI AfxGetInstanceHandle();
HINSTANCE AFXAPI AfxGetResourceHandle();

///////////////////////////////////////////////////////////////////////////
#endif//__AFX_WIN_H__

