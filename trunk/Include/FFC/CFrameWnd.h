// CFrameWnd.h
#ifndef __FFC_CFRAMEWND_H__
#define __FFC_CFRAMEWND_H__
///////////////////////////////////////////////////////////////////////////

#include "CWnd.h"
#include "CView.h"
#include "CControlBar.h"
#include <vector>

///////////////////////////////////////////////////////////////////////////

#define FWS_ADDTOTITLE 0x00008000

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
	virtual BOOL LoadFrame(
		UINT nIDResource,
		DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE,
		CWnd* pParentWnd = NULL,
		CCreateContext* pContext = NULL);

public:
	void EnableDocking(DWORD dwDockStyle);
	void DockControlBar(CControlBar* pBar, UINT nDockBarID = 0, LPCRECT lpRect = NULL);

public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

public:
	DECLARE_MESSAGE_MAP()

protected:
	afx_msg void OnNcDestroy();

public:
	DECLARE_DYNCREATE(CFrameWnd)

public:
	CView* GetActiveView() const;

private:
	std::vector<CView*> m_ViewList;
};

///////////////////////////////////////////////////////////////////////////

class CMDIChildWnd : public CFrameWnd
{
public:
	DECLARE_DYNCREATE(CMDIChildWnd)
};

///////////////////////////////////////////////////////////////////////////

class CMDIFrameWnd : public CFrameWnd
{
public:
	DECLARE_DYNCREATE(CMDIFrameWnd)
};

///////////////////////////////////////////////////////////////////////////

class CMiniFrameWnd : public CFrameWnd
{
public:
	DECLARE_DYNCREATE(CMiniFrameWnd)
};

///////////////////////////////////////////////////////////////////////////

class COleIPFrameWnd : public CFrameWnd
{
public:
	DECLARE_DYNCREATE(COleIPFrameWnd)
};

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_CFRAMEWND_H__

