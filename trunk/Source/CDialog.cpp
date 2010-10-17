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

extern HHOOK g_hHook;
extern CWnd* g_pWnd;

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
		CDialog* pDlg = static_cast<CDialog*>(CWnd::FromHandle(hDlg));
		return pDlg->OnInitDialog();
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
	CenterWindow();
	return TRUE;
}

LRESULT CALLBACK CallDlgProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode == HC_ACTION)
	{
		if (g_pWnd)
		{
			PCWPSTRUCT p = reinterpret_cast<PCWPSTRUCT>(lParam);
			g_pWnd->Attach(p->hwnd);
			g_pWnd = NULL;
		}
	}
	return ::CallNextHookEx(g_hHook, nCode, wParam, lParam);
}

INT_PTR CDialog::DoModal()
{
	HWND hParentWnd = NULL;
	if (m_pParentWnd)
	{
		hParentWnd = m_pParentWnd->GetSafeHwnd();
	}
	if ( ! hParentWnd)
	{
		hParentWnd = ::GetActiveWindow();
	}

	if (g_hHook)
	{
		::UnhookWindowsHookEx(g_hHook);
		g_hHook = NULL;
	}
	g_hHook = ::SetWindowsHookEx(WH_CALLWNDPROC, CallDlgProc, NULL, ::GetCurrentThreadId());
	g_pWnd = this;

	INT_PTR rtn = ::DialogBox(
		AfxGetResourceHandle(),
		m_lpszTemplateName,
		hParentWnd,
		_DialogProc);
	return rtn;
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

