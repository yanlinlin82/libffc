// CWnd.h
#ifndef __CWND_H__
#define __CWND_H__
///////////////////////////////////////////////////////////////////////////

#include "CCmdTarget.h"
#include "CMenu.h"

///////////////////////////////////////////////////////////////////////////

class CDataExchange
{
};

///////////////////////////////////////////////////////////////////////////

struct CCreateContext
{
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
	
	virtual BOOL CreateEx(
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
		LPVOID lpParam = NULL);
	
	virtual BOOL CreateEx(
		DWORD dwExStyle,
		LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName,
		DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd,
		UINT nID,
		LPVOID lpParam = NULL);

public:
	void Attach(HWND hWnd);
	HWND Detach();

public:
	BOOL IsIconic() const;

	BOOL ShowWindow(int nCmdShow);
	void UpdateWindow();
	void GetClientRect(LPRECT lpRect) const;

	LRESULT SendMessage(UINT msg, WPARAM w = 0, LPARAM l = 0);
	LRESULT PostMessage(UINT msg, WPARAM w = 0, LPARAM l = 0);

	INT_PTR MessageBox(LPCTSTR text, LPCTSTR title = NULL, int type = MB_OK);

	CMenu* GetSystemMenu(BOOL bRevert) const;

	HICON SetIcon(HICON hIcon, BOOL bBigIcon);

	BOOL SetMenu(CMenu* pMenu);

public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual LRESULT WindowProc(UINT msg, WPARAM w, LPARAM l);
	virtual LRESULT DefWindowProc(UINT msg, WPARAM w, LPARAM l);
	virtual void PostNcDestroy();
	virtual void DoDataExchange(CDataExchange* pDX);

public:
	DECLARE_MESSAGE_MAP()

protected:
	afx_msg int OnCreate(LPCREATESTRUCT);
	afx_msg void OnPaint();
	afx_msg void OnSysCommand(UINT id, LPARAM l);
	afx_msg void OnNcDestroy();

public:
	DECLARE_DYNCREATE(CWnd)

public:
	HWND GetSafeHwnd() const { return m_hWnd; }
	operator HWND() const { return GetSafeHwnd(); }

	static CWnd* FromHandle(HWND hWnd);

public:
	HWND m_hWnd;

	static RECT rectDefault;
};

///////////////////////////////////////////////////////////////////////////

#define ON_WM_CREATE() \
		if (msg == WM_CREATE) \
		{ \
			r = OnCreate(reinterpret_cast<LPCREATESTRUCT>(l)); \
			return TRUE; \
		}

#define ON_WM_SYSCOMMAND() \
		if (msg == WM_SYSCOMMAND) \
		{ \
			OnSysCommand(w, l); \
			return TRUE; \
		}

#define ON_WM_PAINT() \
		if (msg == WM_PAINT) \
		{ \
			OnPaint(); \
			return TRUE; \
		}

#define ON_WM_QUERYDRAGICON() \
		if (msg == WM_QUERYDRAGICON) \
		{ \
			r = reinterpret_cast<LRESULT>(OnQueryDragIcon()); \
			return TRUE; \
		}

#define ON_WM_NCDESTROY() \
		if (msg == WM_NCDESTROY) \
		{ \
			OnNcDestroy(); \
			return TRUE; \
		}

///////////////////////////////////////////////////////////////////////////
#endif//__CWND_H__

