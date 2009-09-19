// CmdTarget.cpp

#include "../Include/afxwin.h"

///////////////////////////////////////////////////////////////////////////

IMPLEMENT_MESSAGE_MAP(CCmdTarget)

IMPLEMENT_DYNCREATE(CCmdTarget, CObject)

BOOL CCmdTarget::OnCmdMsg(UINT nID, int nCode, void* /*pExtra*/, AFX_CMDHANDLERINFO* /*pHandlerInfo*/)
{
	TRACE("CCmdTarget::OnCmdMsg {%s}\n", GetRuntimeClass()->m_lpszClassName);
	if (_ProcessMessage(_Check, NULL, WM_COMMAND, MAKEWPARAM(nID, nCode), 0))
	{
		TRACE("  ProcessMessage{%s}\n", GetRuntimeClass()->m_lpszClassName);
		_ProcessMessage(_Command, NULL, WM_COMMAND, MAKEWPARAM(nID, nCode), 0);
		return TRUE;
	}
	return FALSE;
}

///////////////////////////////////////////////////////////////////////////

