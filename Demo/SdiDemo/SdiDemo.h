// SdiDemo.h : main header file for the SdiDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "Resource.h"       // main symbols


// CSdiDemoApp:
// See SdiDemo.cpp for the implementation of this class
//

class CSdiDemoApp : public CWinApp
{
public:
	CSdiDemoApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSdiDemoApp theApp;
