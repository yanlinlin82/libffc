// HelloDemo.cpp

#include <afxwin.h>

///////////////////////////////////////////////////////////////////////////

class CHelloFrameWnd : public CFrameWnd
{
public:
	DECLARE_MESSAGE_MAP()

protected:
	afx_msg void OnPaint();
};

BEGIN_MESSAGE_MAP(CHelloFrameWnd, CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()

void CHelloFrameWnd::OnPaint()
{
	CRect rect;
	GetClientRect(rect);
	CPaintDC dc(this);
	dc.DrawText(_T("Hello, world!"), rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}

///////////////////////////////////////////////////////////////////////////

class CHelloWinApp : public CWinApp
{
private:
	CFrameWnd* wnd;

public:
	virtual BOOL InitInstance()
	{
		wnd = new CHelloFrameWnd;
		wnd->Create(NULL, _T("Hello Demo"));
		wnd->ShowWindow(SW_SHOW);
		m_pMainWnd = wnd;
		return TRUE;
	}
};

///////////////////////////////////////////////////////////////////////////

CHelloWinApp theApp;

/*
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	return 0;
}
*/

///////////////////////////////////////////////////////////////////////////

