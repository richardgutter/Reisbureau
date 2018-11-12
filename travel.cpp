// travel.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "travel.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "travelDoc.h"

#include "PasswordDlg.h"
#include "TrialDlg.h"
#include "Instellingen.h"

#include "UsersView.h"
#include "ToegangsView.h"
#include "AgentsView.h"
#include "CoachesView.h"
#include "GuidesView.h"
#include "HotelsView.h"
#include "VatView.h"
#include "AllotmentsView.h"
#include "BookingsView.h"
#include "Cnvexact6View.h"
#include "FitinvView.h"
#include "FitovzView.h"
#include "GeventsView.h"
#include "GexcursionsView.h"
#include "GguidesView.h"
#include "GhotelsView.h"
#include "GmealsView.h"
#include "GothersView.h"
#include "GroupsView.h"
#include "InvovzView.h"
#include "InvoicesView.h"
#include "InvprintseriesView.h"
#include "GrpovzView.h"
#include "MenusView.h"
#include "ProformaView.h"
#include "RemarksView.h"
#include "RestaurantsView.h"
#include "ServicesView.h"
#include "VouchersView.h"

#include "FithotelView.h"
#include "FitagentView.h"
#include "FithotelallView.h"
#include "FitagentallView.h"
#include "FitcancelView.h"
#include "FitnamelistView.h"
#include "FitbookingdateView.h"
#include "FitallotmentView.h"
#include "FittransferView.h"
#include "FitexcursionView.h"
#include "FitcarrentalView.h"
#include "FitvouchernrView.h"
#include "FitvouchernameView.h"
#include "GrpbyarrivalView.h"
#include "GrpbynameView.h"
#include "GrpbyagentView.h"
#include "GrpbycancelView.h"
#include "GrphotelView.h"
#include "GrphoteloptionView.h"
#include "GrpeventsView.h"
#include "GrpguidesView.h"
#include "GrprestaurantView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTravelApp

BEGIN_MESSAGE_MAP(CTravelApp, CWinApp)
	//{{AFX_MSG_MAP(CTravelApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTravelApp construction

CTravelApp::CTravelApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTravelApp object

CTravelApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTravelApp initialization

#define REGISTER_VIEW( view_id, view_name)\
	pDocTemplate = new CMultiDocTemplate(\
		view_id,\
		RUNTIME_CLASS(CTravelDoc),\
		RUNTIME_CLASS(CChildFrame),\
		RUNTIME_CLASS(view_name));\
	AddDocTemplate(pDocTemplate);


BOOL CTravelApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Van Hoorn"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CMultiDocTemplate* pDocTemplate;
	REGISTER_VIEW(IDR_AGENTS, CAgentsView) // register CAgentsView
	REGISTER_VIEW(IDR_COACHES, CCoachesView) // register CCoachesView
	REGISTER_VIEW(IDR_GUIDES, CGuidesView) // register CGuidesView
	REGISTER_VIEW(IDR_HOTELS, CHotelsView) // register CHotelsView
	REGISTER_VIEW(IDR_USERS, CUsersView) // register CUsersView
	REGISTER_VIEW(IDR_TOEGANG, CToegangsView) // register CToegangsView
	REGISTER_VIEW(IDR_VAT, CVatView) // register CVatView
	REGISTER_VIEW(IDR_ALLOTMENTS, CAllotmentsView) // register CAgentsView
	REGISTER_VIEW(IDR_BOOKINGS, CBookingsView) // register CAgentsView
	REGISTER_VIEW(IDR_FITOVZ, CFitovzView) // register CAgentsView
	REGISTER_VIEW(IDR_FITINV, CFitinvView) // register CAgentsView
	REGISTER_VIEW(IDR_GEVENTS, CGeventsView) // register CAgentsView
	REGISTER_VIEW(IDR_GEXCURSIONS, CGexcursionsView) // register CAgentsView
	REGISTER_VIEW(IDR_GGUIDES, CGguidesView) // register CAgentsView
	REGISTER_VIEW(IDR_GHOTELS, CGhotelsView) // register CAgentsView
	REGISTER_VIEW(IDR_GMEALS, CGmealsView) // register CAgentsView
	REGISTER_VIEW(IDR_GOTHERS, CGothersView) // register CAgentsView
	REGISTER_VIEW(IDR_GROUPS, CGroupsView) // register CAgentsView
	REGISTER_VIEW(IDR_INVOVZ, CInvovzView) // register CAgentsView
	REGISTER_VIEW(IDR_INVOICES, CInvoicesView) // register CAgentsView
	REGISTER_VIEW(IDR_CNVEXACT6, CCnvexact6View) // register CAgentsView
	REGISTER_VIEW(IDR_INVPRINTSERIES, CInvprintseriesView) // register CAgentsView
	REGISTER_VIEW(IDR_GRPOVZ, CGrpovzView) // register CAgentsView
	REGISTER_VIEW(IDR_MENUS, CMenusView) // register CAgentsView
	REGISTER_VIEW(IDR_PROFORMA, CProformaView) // register CAgentsView
	REGISTER_VIEW(IDR_REMARKS, CRemarksView) // register CAgentsView
	REGISTER_VIEW(IDR_RESTAURANTS, CRestaurantsView) // register CAgentsView
	REGISTER_VIEW(IDR_SERVICES, CServicesView) // register CAgentsView
	REGISTER_VIEW(IDR_VOUCHERS, CVouchersView) // register CAgentsView
	REGISTER_VIEW(IDR_FITHOTEL, CFithotelView) // register COverView
	REGISTER_VIEW(IDR_FITAGENT, CFitagentView) // register CHtmlOverView
	REGISTER_VIEW(IDR_FITHOTELALL, CFithotelallView) // register COverView
	REGISTER_VIEW(IDR_FITAGENTALL, CFitagentallView) // register CHtmlOverView
	REGISTER_VIEW(IDR_FITCANCEL, CFitcancelView) // register CHtmlOverView
	REGISTER_VIEW(IDR_FITNAMELIST, CFitnamelistView) // register CHtmlOverView
	REGISTER_VIEW(IDR_FITBOOKINGDATE, CFitbookingdateView) // register CHtmlOverView
	REGISTER_VIEW(IDR_FITALLOTMENT, CFitallotmentView) // register CHtmlOverView
	REGISTER_VIEW(IDR_FITTRANSFER, CFittransferView) // register CHtmlOverView
	REGISTER_VIEW(IDR_FITEXCURSION, CFitexcursionView) // register CHtmlOverView
	REGISTER_VIEW(IDR_FITCARRENTAL, CFitcarrentalView) // register CHtmlOverView
	REGISTER_VIEW(IDR_FITVOUCHERNR, CFitvouchernrView) // register CHtmlOverView
	REGISTER_VIEW(IDR_FITVOUCHERNAME, CFitvouchernameView) // register CHtmlOverView
	REGISTER_VIEW(IDR_GRPBYARRIVAL, CGrpbyarrivalView) // register CHtmlOverView
	REGISTER_VIEW(IDR_GRPBYNAME, CGrpbynameView) // register CHtmlOverView
	REGISTER_VIEW(IDR_GRPBYAGENT, CGrpbyagentView) // register CHtmlOverView
	REGISTER_VIEW(IDR_GRPBYCANCEL, CGrpbycancelView) // register CHtmlOverView
	REGISTER_VIEW(IDR_GRPHOTEL, CGrphotelView) // register CHtmlOverView
	REGISTER_VIEW(IDR_GRPHOTELOPTION, CGrphoteloptionView) // register CHtmlOverView
	REGISTER_VIEW(IDR_GRPEVENTS, CGrpeventsView) // register CHtmlOverView
	REGISTER_VIEW(IDR_GRPGUIDES, CGrpguidesView) // register CHtmlOverView
	REGISTER_VIEW(IDR_GRPRESTAURANT, CGrprestaurantView) // register CHtmlOverView

/*
	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
*/

//	COleDateTime m_vandaag, m_grens;
//	m_vandaag = COleDateTime::GetCurrentTime();
//	m_grens.SetDate(2000, 12, 10);
//	if (m_vandaag > m_grens)
//	{
//		CTrialDlg m_dlg;
//		m_dlg.DoModal();
//		return false;
//	}

	CPasswordDlg login;

	if (IDOK != login.DoModal())
		return false;

	CInstellingen m_setinstellingen;

//	m_setinstellingen.Open();
//	dateformat = m_setinstellingen.m_dateformat;
//	m_setinstellingen.Close();

//	if (dateformat == "")
		dateformat = "dd-mm-jjjj";

	theApp.usersview = FALSE;
	theApp.toegangsview = FALSE;
	theApp.agentsview = FALSE;
	theApp.allotmentview = FALSE;
	theApp.hotelsview = FALSE;
	theApp.coachesview = FALSE;
	theApp.guidesview = FALSE;
	theApp.restaurantsview = FALSE;
	theApp.menusview = FALSE;
	theApp.vatview = FALSE;
	theApp.fitbookingsview = FALSE;
	theApp.fitoverviewsview = FALSE;
	theApp.groupsbookingsview = FALSE;
	theApp.groupshotelsview = FALSE;
	theApp.groupsexcursionsview = FALSE;
	theApp.groupsguidesview = FALSE;
	theApp.groupseventsview = FALSE;
	theApp.groupsmealsview = FALSE;
	theApp.groupsothersview = FALSE;
	theApp.groupsoverviewsview = FALSE;
	theApp.invoicesview = FALSE;
	theApp.proformaview = FALSE;
	theApp.invoicefromfitview = FALSE;
	theApp.cnvexact6view = FALSE;
	theApp.invprintseriesview = FALSE;
	theApp.vouchersview = FALSE;

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// The main window has been initialized, so show and update it.
//	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->ShowWindow(SW_SHOWMAXIMIZED);
	pMainFrame->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CTravelApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CTravelApp message handlers

CView * CTravelApp::ShowView(const char *pszViewName)
{
	CString strTypeName;

	POSITION pos = m_pDocManager->GetFirstDocTemplatePosition();
	while (pos != NULL)
	{
		CDocTemplate* pTemplate = (CDocTemplate*)m_pDocManager->GetNextDocTemplate( pos);
		
		strTypeName = "";
		if (pTemplate->GetDocString(strTypeName, CDocTemplate::fileNewName) &&
		   !strTypeName.IsEmpty()
		   && strTypeName.CompareNoCase(pszViewName) == 0)
		{
			// we have found what we're looking for, so open it
			CDocument * pDoc = pTemplate->OpenDocumentFile(NULL);
			POSITION viewPos = pDoc->GetFirstViewPosition();
			return pDoc->GetNextView(viewPos);
		}
	}

	// if we come here there is a fault
	TRACE1("Error: ViewName '%s' is not known.\n", pszViewName);
	ASSERT(FALSE);
	return 0;
}

