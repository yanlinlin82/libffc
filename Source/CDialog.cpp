// Dialog.cpp

#include "../Include/afxwin.h"

///////////////////////////////////////////////////////////////////////////

CDialog::CDialog()
	: m_lpszTemplateName(NULL)
	, m_pParentWnd(NULL)
	, m_pWndProc(NULL)
{
}

CDialog::CDialog(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
	: m_lpszTemplateName(lpszTemplateName)
	, m_pParentWnd(pParentWnd)
	, m_pWndProc(NULL)
{
}

CDialog::CDialog(UINT nIDTemplate, CWnd* pParentWnd)
	: m_lpszTemplateName(MAKEINTRESOURCE(nIDTemplate))
	, m_pParentWnd(pParentWnd)
	, m_pWndProc(NULL)
{
}

///////////////////////////////////////////////////////////////////////////

void CDialog::EndDialog(int nResult)
{
	::EndDialog(m_hWnd, nResult);
}

CDialog* g_pDlg = NULL;

LRESULT CALLBACK CDialog::DialogProcStart(HWND hWnd, UINT msg, WPARAM w, LPARAM l)
{
	CDialog* pDlg = static_cast<CDialog*>(CWnd::FromHandle(hWnd));
	pDlg->WindowProc(msg, w, l);

	WNDPROC proc = pDlg->m_pWndProc;
	if (msg == WM_NCDESTROY)
	{
		pDlg->OnNcDestroy();

		::SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(proc));
		pDlg->m_pWndProc = NULL;
	}
	return ::CallWindowProc(proc, hWnd, msg, w, l);
}

INT_PTR CALLBACK CDialog::_DialogProc(HWND hDlg, UINT msg, WPARAM w, LPARAM)
{
	if (msg == WM_INITDIALOG)
	{
		g_pDlg->Attach(hDlg);
		g_pDlg->m_pWndProc = reinterpret_cast<WNDPROC>(::GetWindowLongPtr(hDlg, GWLP_WNDPROC));
		::SetWindowLongPtr(hDlg, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(DialogProcStart));

		return g_pDlg->OnInitDialog();
	}
	else if (msg == WM_COMMAND)
	{
		CDialog* pDlg = static_cast<CDialog*>(CWnd::FromHandle(hDlg));

		if (LOWORD(w) == IDOK)
		{
			pDlg->OnOK();
			return TRUE;
		}
		else if (LOWORD(w) == IDCANCEL)
		{
			pDlg->OnCancel();
			return TRUE;
		}
	}
	return FALSE;
}

BOOL CDialog::OnInitDialog()
{
	return TRUE;
}

INT_PTR CDialog::DoModal()
{
	g_pDlg = this;

	return ::DialogBox(
		AfxGetResourceHandle(),
		m_lpszTemplateName,
		(m_pParentWnd ? m_pParentWnd->GetSafeHwnd() : NULL),
		_DialogProc);
}

void CDialog::OnOK()
{
	EndDialog(IDOK);
}

void CDialog::OnCancel()
{
	EndDialog(IDCANCEL);
}

///////////////////////////////////////////////////////////////////////////

