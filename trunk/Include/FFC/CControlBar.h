// CControlBar.h
#ifndef __FFC_CCONTROLBAR_H__
#define __FFC_CCONTROLBAR_H__
///////////////////////////////////////////////////////////////////////////

#include "Resource.h"
#include "CControls.h"
#include "CRect.h"

///////////////////////////////////////////////////////////////////////////

#ifndef TBSTYLE_FLAT
#define TBSTYLE_FLAT 0x0800
#endif

#ifndef TBSTYLE_LIST
#define TBSTYLE_LIST 0x1000
#endif

///////////////////////////////////////////////////////////////////////////

class CControlBar : public CWnd
{
public:
	void EnableDocking(DWORD dwDockStyle);
};

///////////////////////////////////////////////////////////////////////////

class CDialogBar : public CControlBar
{
};

///////////////////////////////////////////////////////////////////////////

class COleResizeBar : public CControlBar
{
};

///////////////////////////////////////////////////////////////////////////

class CReBar : public CControlBar
{
};

///////////////////////////////////////////////////////////////////////////

class CStatusBar : public CControlBar
{
public:
	BOOL Create(
		CWnd* pParentWnd,
		DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
		UINT nID = AFX_IDW_STATUS_BAR);

	BOOL CreateEx(
		CWnd* pParentWnd,
		DWORD dwCtrlStyle = 0,
		DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
		UINT nID = AFX_IDW_STATUS_BAR);

public:
	BOOL SetIndicators(const UINT* lpIDArray, int nIDCount);
};

///////////////////////////////////////////////////////////////////////////

class CToolBar : public CControlBar
{
public:
	BOOL CreateEx(
		CWnd* pParentWnd,
		DWORD dwCtrlStyle = TBSTYLE_FLAT,
		DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP,
		CRect rcBorders = CRect(0, 0, 0, 0),
		UINT nID = AFX_IDW_TOOLBAR);

public:
	 BOOL LoadToolBar(LPCTSTR lpszResourceName);
	 BOOL LoadToolBar(UINT nIDResource);
};

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_CCONTROLBAR_H__

