// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "travel.h"

#include "MainFrm.h"
#include "ConfigurationDlg.h"
#include "Toegang.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_USERS, OnUsers)
	ON_COMMAND(ID_VAT, OnVat)
	ON_COMMAND(ID_VOUCHERS, OnVouchers)
	ON_COMMAND(ID_RESTAURANTS, OnRestaurants)
	ON_COMMAND(ID_HOTELS, OnHotels)
	ON_COMMAND(ID_GUIDES, OnGuides)
	ON_COMMAND(ID_GRPOVZ, OnGrpovz)
	ON_COMMAND(ID_GROUPS, OnGroups)
	ON_COMMAND(ID_FITOVZ, OnFitovz)
	ON_COMMAND(ID_FITINV, OnFitinv)
	ON_COMMAND(ID_COACHES, OnCoaches)
	ON_COMMAND(ID_CNVEXACT6, OnCnvexact6)
	ON_COMMAND(ID_BOOKINGS, OnBookings)
	ON_COMMAND(ID_ALLOTMENTS, OnAllotments)
	ON_COMMAND(ID_AGENTS, OnAgents)
	ON_COMMAND(ID_INVOICES, OnInvoices)
	ON_COMMAND(ID_PROFORMA, OnProforma)
	ON_COMMAND(ID_BEHEER_CONFIGURATION, OnBeheerConfiguration)
	ON_UPDATE_COMMAND_UI(ID_INVOICES, OnUpdateInvoices)
	ON_UPDATE_COMMAND_UI(ID_FITINV, OnUpdateFitinv)
	ON_COMMAND(ID_INVOICES_PRINTSERIES, OnInvoicesPrintseries)
	ON_UPDATE_COMMAND_UI(ID_INVOICES_PRINTSERIES, OnUpdateInvoicesPrintseries)
	ON_UPDATE_COMMAND_UI(ID_AGENTS, OnUpdateAgents)
	ON_UPDATE_COMMAND_UI(ID_ALLOTMENTS, OnUpdateAllotments)
	ON_UPDATE_COMMAND_UI(ID_BEHEER_CONFIGURATION, OnUpdateBeheerConfiguration)
	ON_UPDATE_COMMAND_UI(ID_BOOKINGS, OnUpdateBookings)
	ON_UPDATE_COMMAND_UI(ID_CNVEXACT6, OnUpdateCnvexact6)
	ON_UPDATE_COMMAND_UI(ID_COACHES, OnUpdateCoaches)
	ON_UPDATE_COMMAND_UI(ID_FITOVZ, OnUpdateFitovz)
	ON_UPDATE_COMMAND_UI(ID_GROUPS, OnUpdateGroups)
	ON_UPDATE_COMMAND_UI(ID_GRPOVZ, OnUpdateGrpovz)
	ON_UPDATE_COMMAND_UI(ID_GUIDES, OnUpdateGuides)
	ON_UPDATE_COMMAND_UI(ID_HOTELS, OnUpdateHotels)
	ON_UPDATE_COMMAND_UI(ID_PROFORMA, OnUpdateProforma)
	ON_UPDATE_COMMAND_UI(ID_RESTAURANTS, OnUpdateRestaurants)
	ON_UPDATE_COMMAND_UI(ID_USERS, OnUpdateUsers)
	ON_UPDATE_COMMAND_UI(ID_VAT, OnUpdateVat)
	ON_UPDATE_COMMAND_UI(ID_VOUCHERS, OnUpdateVouchers)
	ON_COMMAND(ID_TOEGANG, OnToegang)
	ON_UPDATE_COMMAND_UI(ID_TOEGANG, OnUpdateToegang)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

extern CTravelApp theApp;

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	CToegang m_settoegang;
	CString  m_zoekwaarde;
	CString  m_groep;

	if (theApp.groep == -1)
	{
		m_agents = TRUE;
		m_allotment = TRUE;
		m_cnvexact6 = TRUE;
		m_coaches = TRUE;
		m_configuration = TRUE;
		m_fit = TRUE;
		m_fitinv = TRUE;
		m_groups = TRUE;
		m_guides = TRUE;
		m_hotels = TRUE;
		m_invoices = TRUE;
		m_printseries = TRUE;
		m_proforma = TRUE;
		m_restaurants = TRUE;
		m_toegang = TRUE;
		m_users = TRUE;
		m_vat = TRUE;
		m_vouchers = TRUE;
	}
	else
	{
		m_groep.Format("%d", theApp.groep);

		m_zoekwaarde = "groep = " + m_groep;
		m_settoegang.m_strSort   = "functie";
		m_settoegang.m_strFilter = m_zoekwaarde;
		m_settoegang.Open();

		m_agents = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_allotment = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_cnvexact6 = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_coaches = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_configuration = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_fit = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_fitinv = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_groups = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_guides = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_hotels = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_invoices = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_printseries = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_proforma = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_restaurants = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_toegang = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_users = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_vat = m_settoegang.m_tonen;
		m_settoegang.MoveNext();
		m_vouchers = m_settoegang.m_tonen;

		m_settoegang.Close();
	}

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

//	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
//		| WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_MAXIMIZE;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnUsers() 
{
	if (!theApp.usersview)
	{
		theApp.usersview = TRUE;
		theApp.ShowView( "CUsersView");	
	}
}

void CMainFrame::OnVat() 
{
	// TODO: Add your command handler code here
	if (!theApp.vatview)
	{
		theApp.vatview = TRUE;
		theApp.ShowView( "CVatView");
	}
}

void CMainFrame::OnVouchers() 
{
	// TODO: Add your command handler code here
	if (!theApp.vouchersview)
	{
		theApp.vouchersview = TRUE;
		theApp.ShowView( "CVouchersView");	
	}
}

void CMainFrame::OnRestaurants() 
{
	// TODO: Add your command handler code here
	if (!theApp.restaurantsview)
	{
		theApp.restaurantsview = TRUE;
		theApp.ShowView( "CRestaurantsView");	
	}
}

void CMainFrame::OnProforma() 
{
	// TODO: Add your command handler code here
	if (!theApp.proformaview)
	{
		theApp.proformaview = TRUE;
		theApp.ShowView( "CProformaView");	
	}
}

void CMainFrame::OnHotels() 
{
	// TODO: Add your command handler code here
	if (!theApp.hotelsview)
	{
		theApp.hotelsview = TRUE;
		theApp.ShowView( "CHotelsView");	
	}
}

void CMainFrame::OnGuides() 
{
	// TODO: Add your command handler code here
	if (!theApp.guidesview)
	{
		theApp.guidesview = TRUE;
		theApp.ShowView( "CGuidesView");	
	}
}

void CMainFrame::OnGrpovz() 
{
	// TODO: Add your command handler code here
	if (!theApp.groupsoverviewsview)
	{
		theApp.groupsoverviewsview = TRUE;
		theApp.ShowView( "CGrpovzView");	
	}
}

void CMainFrame::OnGroups() 
{
	// TODO: Add your command handler code here
	if (!theApp.groupsbookingsview)
	{
		theApp.groupsbookingsview = TRUE;
		theApp.ShowView( "CGroupsView");	
	}
}

void CMainFrame::OnFitovz() 
{
	// TODO: Add your command handler code here
	if (!theApp.fitoverviewsview)
	{
		theApp.fitoverviewsview = TRUE;
		theApp.ShowView( "CFitovzView");
	}
}

void CMainFrame::OnFitinv() 
{
	// TODO: Add your command handler code here
	if (!theApp.invoicefromfitview)
	{
		theApp.invoicefromfitview = TRUE;
		theApp.ShowView( "CFitinvView");	
	}
}

void CMainFrame::OnCoaches() 
{
	// TODO: Add your command handler code here
	if (!theApp.coachesview)
	{
		theApp.coachesview = TRUE;
		theApp.ShowView( "CCoachesView");	
	}
}

void CMainFrame::OnCnvexact6() 
{
	// TODO: Add your command handler code here
	if (!theApp.cnvexact6view)
	{
		theApp.cnvexact6view = TRUE;
		theApp.ShowView("CCnvexact6View");
	}
}

void CMainFrame::OnBookings() 
{
	// TODO: Add your command handler code here
	if (!theApp.fitbookingsview)
	{
		theApp.fitbookingsview = TRUE;
		theApp.ShowView( "CBookingsView");
	}
}

void CMainFrame::OnAllotments() 
{
	// TODO: Add your command handler code here
	if (!theApp.allotmentview)
	{
		theApp.allotmentview = TRUE;
		theApp.ShowView( "CAllotmentsView");	
	}
}

void CMainFrame::OnAgents() 
{
	// TODO: Add your command handler code here
	if (!theApp.agentsview)
	{
		theApp.agentsview = TRUE;
		theApp.ShowView( "CAgentsView");
	}
}

void CMainFrame::OnInvoices() 
{
	// TODO: Add your command handler code here
	if (!theApp.invoicesview)
	{
		theApp.invoicesview = TRUE;
		theApp.ShowView( "CInvoicesView");	
	}
}

void CMainFrame::OnBeheerConfiguration() 
{
	// TODO: Add your command handler code here
	
	CConfigurationDlg m_dlg;
	m_dlg.DoModal();
}

void CMainFrame::OnInvoicesPrintseries() 
{
	// TODO: Add your command handler code here
	if (!theApp.invprintseriesview)
	{
		theApp.invprintseriesview = TRUE;
		theApp.ShowView("CInvprintseriesView");
	}
}

void CMainFrame::OnUpdateInvoices(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_invoices)    // theApp.gebruiker == "Elly")
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateFitinv(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_fitinv)      // theApp.gebruiker == "Elly")
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateInvoicesPrintseries(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_printseries)    // theApp.gebruiker == "Elly")
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateAgents(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_agents)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateAllotments(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_allotment)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateBeheerConfiguration(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_configuration)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateBookings(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_fit)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateCnvexact6(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_cnvexact6)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateCoaches(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_coaches)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateFitovz(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_fit)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateGroups(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_groups)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateGrpovz(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_groups)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateGuides(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_guides)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateHotels(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_hotels)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateProforma(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_proforma)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateRestaurants(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_restaurants)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateUsers(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_users)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateVat(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_vat)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnUpdateVouchers(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_vouchers)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CMainFrame::OnToegang() 
{
	// TODO: Add your command handler code here
	
	if (!theApp.toegangsview)
	{
		theApp.toegangsview = TRUE;
		theApp.ShowView("CToegangsView");	
	}
}

void CMainFrame::OnUpdateToegang(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_toegang)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}
