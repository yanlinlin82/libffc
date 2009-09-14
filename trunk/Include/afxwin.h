// afxwin.h
//
// This is part of FFC (Free Foundation Classes).
//
// Anthor: Linlin Yan (yanlinlin82[at]gmail.com).
//
// Any sugguestion is welcome.

#ifndef __AFXWIN_H__
#define __AFXWIN_H__
///////////////////////////////////////////////////////////////////////////

#include "afx.h"
#include "atltypes.h"
#include "afxres.h"

#include "FFC/CObject.h"
#include "FFC/CException.h"
#include "FFC/CFile.h"
#include "FFC/CCmdTarget.h"
#include "FFC/CWnd.h"
#include "FFC/CFrameWnd.h"
#include "FFC/CDocument.h"
#include "FFC/CDocTemplate.h"
#include "FFC/CView.h"
#include "FFC/CDialog.h"
#include "FFC/CControlBar.h"
#include "FFC/CMenu.h"
#include "FFC/CDC.h"
#include "FFC/CGdiObject.h"
#include "FFC/CWinApp.h"

///////////////////////////////////////////////////////////////////////////

class CSplitterWnd : public CWnd
{
};

///////////////////////////////////////////////////////////////////////////

class CPropertySheet : public CWnd
{
};

///////////////////////////////////////////////////////////////////////////

CWinApp*  AFXAPI AfxGetApp();
HINSTANCE AFXAPI AfxGetInstanceHandle();
HINSTANCE AFXAPI AfxGetResourceHandle();

void AFXAPI AfxEnableControlContainer();

BOOL AFXAPI AfxOleInit();

int AFXAPI AfxMessageBox(LPCTSTR lpszText, UINT nType = MB_OK, UINT nIDHelp = 0);
int AFXAPI AfxMessageBox(UINT nIDPrompt, UINT nType = MB_OK, UINT nIDHelp = (UINT) -1);

///////////////////////////////////////////////////////////////////////////
#endif//__AFXWIN_H__

