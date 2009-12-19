// ATLWin.cpp

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MAIN
#include <windows.h>
#include <tchar.h>
#include <atlbase.h>
#include <atlwin.h>

class CMainWnd : public CWindowImpl<CMainWnd>
{
public:
	BEGIN_MSG_MAP(CMainWnd)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
	END_MSG_MAP()

private:
	LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&)
	{
		::PostQuitMessage(0);
		return 0;
	}
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	RECT rect = { 0, 0, 300, 200 };
	CMainWnd wnd;
	wnd.Create(NULL, rect, _T("Test"), WS_OVERLAPPEDWINDOW);
	wnd.CenterWindow();
	wnd.ShowWindow(SW_SHOW);
	wnd.UpdateWindow();

	MSG msg;
	while (::GetMessage(&msg, NULL, 0, 0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
	return msg.wParam;
}
