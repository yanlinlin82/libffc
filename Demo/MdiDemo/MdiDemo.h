// MdiDemo.h : main header file for the MdiDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "Resource.h"       // main symbols


// CMdiDemoApp:
// See MdiDemo.cpp for the implementation of this class
//

class CMdiDemoApp : public CWinApp
{
public:
	CMdiDemoApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMdiDemoApp theApp;
