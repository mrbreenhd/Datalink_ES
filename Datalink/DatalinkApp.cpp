// Datalink.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "DatalinkApp.h"
#include "EuroScopePlugIn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CDatalinkApp, CWinApp)
END_MESSAGE_MAP()


// CDatalinkApp construction
CDatalinkApp::CDatalinkApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


CDatalinkApp::~CDatalinkApp()
{

}


// The one and only CDatalinkApp object
CDatalinkApp theApp;


// CDatalinkApp initialization

BOOL CDatalinkApp::InitInstance ()
{
	CWinApp::InitInstance();

	return TRUE;
}


CDatalinkPlugin    * gpMyPlugin = NULL;

//---EuroScopePlugInInit-----------------------------------------------
void    __declspec (dllexport)    EuroScopePlugInInit (EuroScopePlugIn::CPlugIn ** ppPlugInInstance)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
#ifdef DEBUG
		AfxEnableMemoryLeakDump(false);
#endif

		// create the instance
		* ppPlugInInstance = gpMyPlugin = new CDatalinkPlugin();
}


//---EuroScopePlugInExit-----------------------------------------------
void    __declspec (dllexport)    EuroScopePlugInExit (void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

		// delete the instance
		delete gpMyPlugin;
}
