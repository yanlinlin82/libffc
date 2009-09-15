// CDialog.h
#ifndef __CDIALOG_H__
#define __CDIALOG_H__
///////////////////////////////////////////////////////////////////////////

#include "CWnd.h"

///////////////////////////////////////////////////////////////////////////

class CDialog : public CWnd
{
public:
	CDialog();
	explicit CDialog(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	explicit CDialog(UINT nIDTemplate, CWnd* pParentWnd = NULL);

public:
	virtual BOOL OnInitDialog();
	virtual INT_PTR DoModal();
	virtual void OnOK();
	virtual void OnCancel();

public:
	void EndDialog(int nResult);

private:
	static LRESULT CALLBACK DialogProcStart(HWND hDlg, UINT msg, WPARAM w, LPARAM l);
	static INT_PTR CALLBACK _DialogProc(HWND hDlg, UINT msg, WPARAM w, LPARAM l);

private:
	LPCTSTR m_lpszTemplateName;
	CWnd*   m_pParentWnd;
	WNDPROC m_pWndProc;
};

///////////////////////////////////////////////////////////////////////////

class CCommonDialog : public CDialog
{
};

///////////////////////////////////////////////////////////////////////////

class CColorDialog : public CCommonDialog
{
};

///////////////////////////////////////////////////////////////////////////

class CFileDialog : public CCommonDialog
{
};

///////////////////////////////////////////////////////////////////////////

class CFindReplaceDialog : public CCommonDialog
{
};

///////////////////////////////////////////////////////////////////////////

class CFontDialog : public CCommonDialog
{
};

///////////////////////////////////////////////////////////////////////////

class COleDialog : public CCommonDialog
{
};

///////////////////////////////////////////////////////////////////////////

class CPageSetupDialog : public CCommonDialog
{
};

///////////////////////////////////////////////////////////////////////////

class CPrintDialog : public CCommonDialog
{
};

///////////////////////////////////////////////////////////////////////////

class CPrintDialogEx : public CCommonDialog
{
};

///////////////////////////////////////////////////////////////////////////

class COlePropertyPage : public CDialog
{
};

///////////////////////////////////////////////////////////////////////////

class CPropertyPage : public CDialog
{
};

///////////////////////////////////////////////////////////////////////////

class CDHtmlDialog : public CDialog
{
};

///////////////////////////////////////////////////////////////////////////
#endif//__CDIALOG_H__

