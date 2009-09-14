// winres.h
//
// This is part of FFC (Free Foundation Classes).
//
// Anthor: Linlin Yan (yanlinlin82[at]gmail.com).
//
// Any sugguestion is welcome.

#ifndef __WINRES_H__
#define __WINRES_H__
///////////////////////////////////////////////////////////////////////////

#include <windows.h>

///////////////////////////////////////////////////////////////////////////

// operation messages sent to DLGINIT
#ifndef LB_ADDSTRING
#define LB_ADDSTRING (WM_USER + 1)
#endif
#ifndef CB_ADDSTRING
#define CB_ADDSTRING (WM_USER + 3)
#endif

#ifdef APSTUDIO_INVOKED
#undef APSTUDIO_HIDDEN_SYMBOLS
#endif

#ifdef IDC_STATIC
#undef IDC_STATIC
#endif
#define IDC_STATIC (-1)

///////////////////////////////////////////////////////////////////////////
#endif//__WINRES_H__

