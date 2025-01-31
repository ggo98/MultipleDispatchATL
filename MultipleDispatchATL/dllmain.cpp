// dllmain.cpp : Implementation of DllMain.

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "MultipleDispatchATL_i.h"
#include "dllmain.h"

CMultipleDispatchATLModule _AtlModule;

class CMultipleDispatchATLApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CMultipleDispatchATLApp, CWinApp)
END_MESSAGE_MAP()

CMultipleDispatchATLApp theApp;

BOOL CMultipleDispatchATLApp::InitInstance()
{
	return CWinApp::InitInstance();
}

int CMultipleDispatchATLApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
