// Dialog.cpp

#include "../Include/afxwin.h"

///////////////////////////////////////////////////////////////////////////

CDialog::CDialog()
{
}

CDialog::CDialog(LPCTSTR /*lpszTemplateName*/, CWnd* /*pParentWnd*/)
{
}

CDialog::CDialog(UINT /*nIDTemplate*/, CWnd* /*pParentWnd*/)
{
}

///////////////////////////////////////////////////////////////////////////

BOOL CDialog::OnInitDialog()
{
	return TRUE;
}

INT_PTR CDialog::DoModal()
{
	return 0;
}

LRESULT CDialog::WindowProc(UINT msg, WPARAM w, LPARAM l)
{
	if (msg == WM_INITDIALOG)
	{
		return OnInitDialog();
	}
	return CWnd::WindowProc(msg, w, l);
}

///////////////////////////////////////////////////////////////////////////

