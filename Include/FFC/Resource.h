// Resource.h
#ifndef __FFC_RESOURCE_H__
#define __FFC_RESOURCE_H__
///////////////////////////////////////////////////////////////////////////

#include <windows.h>

///////////////////////////////////////////////////////////////////////////

#define ID_SEPARATOR 0

///////////////////////////////////////////////////////////////////////////

#ifdef IDC_STATIC
#undef IDC_STATIC
#endif
#define IDC_STATIC (-1)

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
///////////////////////////////////////////////////////////////////////////

#define AFX_IDS_APP_TITLE   0xE000
#define AFX_IDS_IDLEMESSAGE 0xE001

#define AFX_IDW_TOOLBAR     0xE800
#define AFX_IDW_STATUS_BAR  0xE801

#define AFX_IDS_SCSIZE        0xEF00
#define AFX_IDS_SCMOVE        0xEF01
#define AFX_IDS_SCMINIMIZE    0xEF02
#define AFX_IDS_SCMAXIMIZE    0xEF03
#define AFX_IDS_SCNEXTWINDOW  0xEF04
#define AFX_IDS_SCPREVWINDOW  0xEF05
#define AFX_IDS_SCCLOSE       0xEF06
#define AFX_IDS_SCRESTORE     0xEF12
#define AFX_IDS_SCTASKLIST    0xEF13

#define AFX_IDS_MDICHILD      0xEF1F

#define AFX_IDS_DESKACCESSORY 0xEFDA

#define AFX_IDS_PREVIEW_CLOSE 0xF005

///////////////////////////////////////////////////////////////////////////

#define CBRS_ALIGN_LEFT     0x1000L
#define CBRS_ALIGN_TOP      0x2000L
#define CBRS_ALIGN_RIGHT    0x4000L
#define CBRS_ALIGN_BOTTOM   0x8000L
#define CBRS_ALIGN_ANY      0xF000L

#define CBRS_BORDER_LEFT    0x0100L
#define CBRS_BORDER_TOP     0x0200L
#define CBRS_BORDER_RIGHT   0x0400L
#define CBRS_BORDER_BOTTOM  0x0800L
#define CBRS_BORDER_ANY     0x0F00L

#define CBRS_TOOLTIPS       0x0010L
#define CBRS_FLYBY          0x0020L
#define CBRS_FLOAT_MULTI    0x0040L
#define CBRS_BORDER_3D      0x0080L

#define CBRS_FLOATING       0x0001L 
#define CBRS_SIZE_FIXED     0x0002L 
#define CBRS_SIZE_DYNAMIC   0x0004L 
#define CBRS_HIDE_INPLACE   0x0008L
 
#define CBRS_GRIPPER        0x00400000L 

#define CBRS_ORIENT_HORZ    (CBRS_ALIGN_TOP|CBRS_ALIGN_BOTTOM) 
#define CBRS_ORIENT_VERT    (CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT) 
#define CBRS_ORIENT_ANY     (CBRS_ORIENT_HORZ|CBRS_ORIENT_VERT) 
 
#define CBRS_ALL            0x0040FFFFL 

#define CBRS_NOALIGN        0x00000000L
#define CBRS_LEFT           (CBRS_ALIGN_LEFT | CBRS_BORDER_RIGHT)
#define CBRS_TOP            (CBRS_ALIGN_TOP | CBRS_BORDER_BOTTOM)
#define CBRS_RIGHT          (CBRS_ALIGN_RIGHT | CBRS_BORDER_LEFT)
#define CBRS_BOTTOM         (CBRS_ALIGN_BOTTOM | CBRS_BORDER_TOP)

///////////////////////////////////////////////////////////////////////////

#define ID_INDICATOR_EXT  0xE700 // extended selection indicator
#define ID_INDICATOR_CAPS 0xE701 // cap lock indicator
#define ID_INDICATOR_NUM  0xE702 // num lock indicator
#define ID_INDICATOR_SCRL 0xE703 // scroll lock indicator
#define ID_INDICATOR_OVR  0xE704 // overtype mode indicator
#define ID_INDICATOR_REC  0xE705 // record mode indicator
#define ID_INDICATOR_KANA 0xE706 // kana lock indicator

///////////////////////////////////////////////////////////////////////////

// File commands
#define ID_FILE_NEW                     0xE100
#define ID_FILE_OPEN                    0xE101
#define ID_FILE_CLOSE                   0xE102
#define ID_FILE_SAVE                    0xE103
#define ID_FILE_SAVE_AS                 0xE104
#define ID_FILE_PAGE_SETUP              0xE105
#define ID_FILE_PRINT_SETUP             0xE106
#define ID_FILE_PRINT                   0xE107
#define ID_FILE_PRINT_DIRECT            0xE108
#define ID_FILE_PRINT_PREVIEW           0xE109
#define ID_FILE_UPDATE                  0xE10A
#define ID_FILE_SAVE_COPY_AS            0xE10B
#define ID_FILE_SEND_MAIL               0xE10C

// File MRU (Most Recently Used) commands
#define ID_FILE_MRU_FIRST               0xE110
#define ID_FILE_MRU_FILE1               0xE110
#define ID_FILE_MRU_FILE2               0xE111
#define ID_FILE_MRU_FILE3               0xE112
#define ID_FILE_MRU_FILE4               0xE113
#define ID_FILE_MRU_FILE5               0xE114
#define ID_FILE_MRU_FILE6               0xE115
#define ID_FILE_MRU_FILE7               0xE116
#define ID_FILE_MRU_FILE8               0xE117
#define ID_FILE_MRU_FILE9               0xE118
#define ID_FILE_MRU_FILE10              0xE119
#define ID_FILE_MRU_FILE11              0xE11A
#define ID_FILE_MRU_FILE12              0xE11B
#define ID_FILE_MRU_FILE13              0xE11C
#define ID_FILE_MRU_FILE14              0xE11D
#define ID_FILE_MRU_FILE15              0xE11E
#define ID_FILE_MRU_FILE16              0xE11F
#define ID_FILE_MRU_LAST                0xE11F

// Edit commands
#define ID_EDIT_CLEAR                   0xE120
#define ID_EDIT_CLEAR_ALL               0xE121
#define ID_EDIT_COPY                    0xE122
#define ID_EDIT_CUT                     0xE123
#define ID_EDIT_FIND                    0xE124
#define ID_EDIT_PASTE                   0xE125
#define ID_EDIT_PASTE_LINK              0xE126
#define ID_EDIT_PASTE_SPECIAL           0xE127
#define ID_EDIT_REPEAT                  0xE128
#define ID_EDIT_REPLACE                 0xE129
#define ID_EDIT_SELECT_ALL              0xE12A
#define ID_EDIT_UNDO                    0xE12B
#define ID_EDIT_REDO                    0xE12C

// Window commands
#define ID_WINDOW_NEW                   0xE130
#define ID_WINDOW_ARRANGE               0xE131
#define ID_WINDOW_CASCADE               0xE132
#define ID_WINDOW_TILE_HORZ             0xE133
#define ID_WINDOW_TILE_VERT             0xE134
#define ID_WINDOW_SPLIT                 0xE135
#ifndef RC_INVOKED
#define ATL_IDM_WINDOW_FIRST            0xE130
#define ATL_IDM_WINDOW_LAST             0xE13F
#define ATL_IDM_FIRST_MDICHILD          0xFF00  // window list starts here
#endif//!RC_INVOKED

// Help and App commands
#define ID_APP_ABOUT                    0xE140
#define ID_APP_EXIT                     0xE141
#define ID_HELP_INDEX                   0xE142
#define ID_HELP_FINDER                  0xE143
#define ID_HELP_USING                   0xE144
#define ID_CONTEXT_HELP                 0xE145  // Shift-F1
#define ID_HELP                         0xE146  // First attempt for F1
#define ID_DEFAULT_HELP                 0xE147  // Last attempt

// Misc
#define ID_NEXT_PANE                    0xE150
#define ID_PREV_PANE                    0xE151

// View
#define ID_VIEW_TOOLBAR                 0xE801
#define ID_VIEW_STATUS_BAR              0xE802

///////////////////////////////////////////////////////////////////////////

#define AFX_IDW_PANE_FIRST              0xE900 // first pane (256 max) 
#define AFX_IDW_PANE_LAST               0xE9FF

#define AFX_IDW_HSCROLL_FIRST           0xEA00  // first Horz scrollbar (16 max) 
#define AFX_IDW_VSCROLL_FIRST           0xEA10  // first Vert scrollbar (16 max) 
 
#define AFX_IDW_SIZE_BOX                0xEA20  // size box for splitters 
#define AFX_IDW_PANE_SAVE               0xEA21  // to shift AFX_IDW_PANE_FIRST 

///////////////////////////////////////////////////////////////////////////
#endif//__FFC_RESOURCE_H__

