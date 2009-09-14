// DialogDemo.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "Resource.h"		// main symbols


// CDialogDemoApp:
// See DialogDemo.cpp for the implementation of this class
//

class CDialogDemoApp : public CWinApp
{
public:
	CDialogDemoApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CDialogDemoApp theApp;

