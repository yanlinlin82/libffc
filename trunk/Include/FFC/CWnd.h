// CWnd.h
#ifndef __FFC_CWND_H__
#define __FFC_CWND_H__
///////////////////////////////////////////////////////////////////////////

#include "Globals.h"
#include "CCmdTarget.h"
#include "CMenu.h"

///////////////////////////////////////////////////////////////////////////

BOOL AFXAPI AfxRegisterClass(WNDCLASS* lpWndClass);

LPCTSTR AFXAPI AfxRegisterWndClass(UINT classStyle,
	HCURSOR hCursor = NULL, HBRUSH hBrush = NULL, HICON hIcon = NULL);

///////////////////////////////////////////////////////////////////////////

class CDataExchange
{
};

///////////////////////////////////////////////////////////////////////////

class CDocument;
class CDocTemplate;
class CView;
class CFrameWnd;

class CCreateContext
{
public:
	CCreateContext()
		: m_pNewViewClass(NULL)
		, m_pCurrentDoc(NULL)
		, m_pNewDocTemplate(NULL)
		, m_pLastView(NULL)
		, m_pCurrentFrame(NULL)
	{ }

public:
	CRuntimeClass* m_pNewViewClass;
	CDocument*     m_pCurrentDoc;
	CDocTemplate*  m_pNewDocTemplate;
	CView*         m_pLastView;
	CFrameWnd*     m_pCurrentFrame;
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

	void MoveWindow(int x, int y, int w, int h, BOOL repaint = TRUE);
	void MoveWindow(LPCRECT pRect, BOOL repaint = TRUE);
	BOOL SetWindowPos(const CWnd* pWndInsertAfter, int x, int y, int cx, int cy, UINT flags);
	BOOL ShowWindow(int nCmdShow);
	void UpdateWindow();
	void GetWindowRect(LPRECT lpRect) const;
	void GetClientRect(LPRECT lpRect) const;
	void CenterWindow(CWnd* pAlternateOwner = NULL);

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
	virtual BOOL OnCommand(WPARAM w, LPARAM l);

public:
	DECLARE_MESSAGE_MAP()

protected:
	afx_msg int OnCreate(LPCREATESTRUCT);
	afx_msg void OnSize(UINT type, int cx, int cy);
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

CWnd* AFXAPI AfxGetMainWnd();

///////////////////////////////////////////////////////////////////////////

#include "CWnd_inline.h"

///////////////////////////////////////////////////////////////////////////

class CSplitterWnd : public CWnd
{
};

///////////////////////////////////////////////////////////////////////////

class CPropertySheet : public CWnd
{
};

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_CWND_H__

