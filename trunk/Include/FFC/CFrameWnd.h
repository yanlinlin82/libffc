// CFrameWnd.h
#ifndef __CFRAMEWND_H__
#define __CFRAMEWND_H__
///////////////////////////////////////////////////////////////////////////

#include "CWnd.h"
#include "CControlBar.h"

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
	DECLARE_MESSAGE_MAP()

protected:
	afx_msg void OnNcDestroy();
};

///////////////////////////////////////////////////////////////////////////

class CMDIChildWnd : public CFrameWnd
{
};

///////////////////////////////////////////////////////////////////////////

class CMDIFrameWnd : public CFrameWnd
{
};

///////////////////////////////////////////////////////////////////////////

class CMiniFrameWnd : public CFrameWnd
{
};

///////////////////////////////////////////////////////////////////////////

class COleIPFrameWnd : public CFrameWnd
{
};

///////////////////////////////////////////////////////////////////////////
#endif//__CFRAMEWND_H__

