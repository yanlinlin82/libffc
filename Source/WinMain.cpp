// WinMain.cpp

#include "../Include/afxwin.h"

///////////////////////////////////////////////////////////////////////////

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	AfxWinInit(hInst, hPrevInst, lpCmdLine, nCmdShow);

	CWinApp* pApp = AfxGetApp();
	if ( ! pApp->InitInstance())
	{
		return 1;
	}
	int result = pApp->Run();
	pApp->ExitInstance();
	return result;
}

///////////////////////////////////////////////////////////////////////////

