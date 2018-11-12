// BookingsView.cpp : implementation file
//

#include "stdafx.h"
#include "travel.h"
#include "BookingsView.h"

#include "hotels.h"
#include "Toegang.h"
#include "agents.h"
#include "zkhoteldlg.h"
#include "zkagentdlg.h"
#include "zkbookingdlg.h"
#include <stdlib.h>
#include "allotment.h"
#include "math.h"
#include "datecnv.h"
#include "vouchers.h"
#include "users.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookingsView

IMPLEMENT_DYNCREATE(CBookingsView, CFormView)

CBookingsView::CBookingsView()
	: CFormView(CBookingsView::IDD)
{
	//{{AFX_DATA_INIT(CBookingsView)
	m_tourref = _T("");
	m_alghotelcode = _T("");
	m_algpassenger = _T("");
	m_algpax    = 0;
	m_algbookedby = _T("");
	m_algconfirmedby = _T("");
	m_agreference = _T("");
	m_agagentcode = _T("");
	m_ronormal = -1;
	m_robb = -1;
	m_prmagent = _T("");
	m_prmhotel = _T("");
	m_prcancellation = FALSE;
	m_prdocket = FALSE;
	m_prreconfirmation = FALSE;
	m_prvoucher = FALSE;
	m_algarrivaldate = _T("");
	m_algdepartdate = _T("");
	m_strcsingles = _T("");
	m_stradoubles = _T("");
	m_stramultiples = _T("");
	m_straquads = _T("");
	m_strasingles = _T("");
	m_stratriples = _T("");
	m_stratwins = _T("");
	m_stratwinsingles = _T("");
	m_strcdoubles = _T("");
	m_strcmultiples = _T("");
	m_strcquads = _T("");
	m_strctriples = _T("");
	m_strctwins = _T("");
	m_strctwinsingles = _T("");
	m_stredoubles = _T("");
	m_stremultiples = _T("");
	m_strequads = _T("");
	m_stresingles = _T("");
	m_stretriples = _T("");
	m_stretwins = _T("");
	m_stretwinsingles = _T("");
	m_bookingdate = _T("");
	m_user = _T("");
	m_canceltext = _T("");
	m_date_text = _T("");
	m_alghotelnaam = _T("");
	m_algnights = _T("");
	m_algdepartday = _T("");
	m_algarrivalday = _T("");
	m_agagentname = _T("");
	m_remarks = _T("");
	m_remcarrental = FALSE;
	m_remexcursion = FALSE;
	m_remtransfer = FALSE;
	m_roperiode1 = FALSE;
	m_roperiode2 = FALSE;
	m_roperiode3 = FALSE;
	m_roperiode4 = FALSE;
	m_roperiode5 = FALSE;
	m_robuttonnr = _T("");
	m_roperiode6 = FALSE;
	m_roperiode7 = FALSE;
	m_roperiode8 = FALSE;
	m_roperiode9 = FALSE;
	m_roperiode10 = FALSE;
	//}}AFX_DATA_INIT
}

CBookingsView::~CBookingsView()
{
}

void CBookingsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBookingsView)
	DDX_Control(pDX, IDC_REMARKS_EDIT, m_remarks_cntrl);
	DDX_Control(pDX, IDC_ROETWINSINGLES_EDIT, m_stretwinsingles_cntrl);
	DDX_Control(pDX, IDC_ROETWINS_EDIT, m_stretwins_cntrl);
	DDX_Control(pDX, IDC_ROETRIPLES_EDIT, m_stretriples_cntrl);
	DDX_Control(pDX, IDC_ROESINGLES_EDIT, m_stresingles_cntrl);
	DDX_Control(pDX, IDC_ROEQUADS_EDIT, m_strequads_cntrl);
	DDX_Control(pDX, IDC_ROEMULTIPLES_EDIT, m_stremultiples_cntrl);
	DDX_Control(pDX, IDC_ROEDOUBLES_EDIT, m_stredoubles_cntrl);
	DDX_Control(pDX, IDC_ROCTWINSINGLES_EDIT, m_strctwinsingles_cntrl);
	DDX_Control(pDX, IDC_ROCTWINS_EDIT, m_strctwins_cntrl);
	DDX_Control(pDX, IDC_ROCTRIPLES_EDIT, m_strctriples_cntrl);
	DDX_Control(pDX, IDC_ROCSINGLES_EDIT, m_strcsingles_cntrl);
	DDX_Control(pDX, IDC_ROCQUADS_EDIT, m_strcquads_cntrl);
	DDX_Control(pDX, IDC_ROCMULTIPLES_EDIT, m_strcmultiples_cntrl);
	DDX_Control(pDX, IDC_ROCDOUBLES_EDIT, m_strcdoubles_cntrl);
	DDX_Control(pDX, IDC_ROATWINSINGLES_EDIT, m_stratwinsingles_cntrl);
	DDX_Control(pDX, IDC_ROATWINS_EDIT, m_stratwins_cntrl);
	DDX_Control(pDX, IDC_ROATRIPLES_EDIT, m_stratriples_cntrl);
	DDX_Control(pDX, IDC_ROASINGLES_EDIT, m_strasingles_cntrl);
	DDX_Control(pDX, IDC_ROAQUADS_EDIT, m_straquads_cntrl);
	DDX_Control(pDX, IDC_ROAMULTIPLES_EDIT, m_stramultiples_cntrl);
	DDX_Control(pDX, IDC_ROADOUBLES_EDIT, m_stradoubels_cntrl);
	DDX_Control(pDX, IDC_TOURREF_EDIT, m_tourref_cntrl);
	DDX_Control(pDX, IDC_PRVOUCHER_CHECK, m_prvoucher_cntrl);
	DDX_Control(pDX, IDC_PRRECONFIRMATION_CHECK, m_prreconfirmation_cntrl);
	DDX_Control(pDX, IDC_PRMHOTEL_EDIT, m_prmhotel_cntrl);
	DDX_Control(pDX, IDC_PRMAGENT_EDIT, m_prmagent_cntrl);
	DDX_Control(pDX, IDC_PRDOCKET_CHECK, m_prdocket_cntrl);
	DDX_Control(pDX, IDC_PRCANCELLATION_CHECK, m_prcancellation_cntrl);
	DDX_Control(pDX, IDC_ALGPAX_EDIT, m_algpax_cntrl);
	DDX_Control(pDX, IDC_ALGPASSENGER_EDIT, m_algpassenger_cntrl);
	DDX_Control(pDX, IDC_ALGHOTELCODE_EDIT, m_alghotelcode_cntrl);
	DDX_Control(pDX, IDC_ALGDEPARTDATE_EDIT, m_algdepartdate_cntrl);
	DDX_Control(pDX, IDC_ALGCONFIRMEDBY_EDIT, m_algconfirmedby_cntrl);
	DDX_Control(pDX, IDC_ALGBOOKEDBY_EDIT, m_algbookedby_cntrl);
	DDX_Control(pDX, IDC_ALGARRIVALDATE_EDIT, m_algarrivaldate_cntrl);
	DDX_Control(pDX, IDC_AGREFERENCE_EDIT, m_agreference_cntrl);
	DDX_Control(pDX, IDC_AGAGENTCODE_EDIT, m_agagentcode_cntrl);
	DDX_Control(pDX, IDC_BOOKING_TAB, m_tab);
	DDX_Text(pDX, IDC_TOURREF_EDIT, m_tourref);
	DDV_MaxChars(pDX, m_tourref, 11);
	DDX_Text(pDX, IDC_ALGHOTELCODE_EDIT, m_alghotelcode);
	DDV_MaxChars(pDX, m_alghotelcode, 3);
	DDX_Text(pDX, IDC_ALGPASSENGER_EDIT, m_algpassenger);
	DDV_MaxChars(pDX, m_algpassenger, 60);
	DDX_Text(pDX, IDC_ALGPAX_EDIT, m_algpax);
	DDX_Text(pDX, IDC_ALGBOOKEDBY_EDIT, m_algbookedby);
	DDV_MaxChars(pDX, m_algbookedby, 20);
	DDX_Text(pDX, IDC_ALGCONFIRMEDBY_EDIT, m_algconfirmedby);
	DDV_MaxChars(pDX, m_algconfirmedby, 20);
	DDX_Text(pDX, IDC_AGREFERENCE_EDIT, m_agreference);
	DDV_MaxChars(pDX, m_agreference, 11);
	DDX_Text(pDX, IDC_AGAGENTCODE_EDIT, m_agagentcode);
	DDV_MaxChars(pDX, m_agagentcode, 3);
	DDX_Radio(pDX, IDC_RONORMAL_RADIO, m_ronormal);
	DDX_Radio(pDX, IDC_ROBB_RADIO, m_robb);
	DDX_Text(pDX, IDC_PRMAGENT_EDIT, m_prmagent);
	DDV_MaxChars(pDX, m_prmagent, 200);
	DDX_Text(pDX, IDC_PRMHOTEL_EDIT, m_prmhotel);
	DDV_MaxChars(pDX, m_prmhotel, 200);
	DDX_Check(pDX, IDC_PRCANCELLATION_CHECK, m_prcancellation);
	DDX_Check(pDX, IDC_PRDOCKET_CHECK, m_prdocket);
	DDX_Check(pDX, IDC_PRRECONFIRMATION_CHECK, m_prreconfirmation);
	DDX_Check(pDX, IDC_PRVOUCHER_CHECK, m_prvoucher);
	DDX_Text(pDX, IDC_ALGARRIVALDATE_EDIT, m_algarrivaldate);
	DDV_MaxChars(pDX, m_algarrivaldate, 10);
	DDX_Text(pDX, IDC_ALGDEPARTDATE_EDIT, m_algdepartdate);
	DDV_MaxChars(pDX, m_algdepartdate, 10);
	DDX_Text(pDX, IDC_ROCSINGLES_EDIT, m_strcsingles);
	DDV_MaxChars(pDX, m_strcsingles, 2);
	DDX_Text(pDX, IDC_ROADOUBLES_EDIT, m_stradoubles);
	DDV_MaxChars(pDX, m_stradoubles, 2);
	DDX_Text(pDX, IDC_ROAMULTIPLES_EDIT, m_stramultiples);
	DDV_MaxChars(pDX, m_stramultiples, 2);
	DDX_Text(pDX, IDC_ROAQUADS_EDIT, m_straquads);
	DDV_MaxChars(pDX, m_straquads, 2);
	DDX_Text(pDX, IDC_ROASINGLES_EDIT, m_strasingles);
	DDV_MaxChars(pDX, m_strasingles, 2);
	DDX_Text(pDX, IDC_ROATRIPLES_EDIT, m_stratriples);
	DDV_MaxChars(pDX, m_stratriples, 2);
	DDX_Text(pDX, IDC_ROATWINS_EDIT, m_stratwins);
	DDV_MaxChars(pDX, m_stratwins, 2);
	DDX_Text(pDX, IDC_ROATWINSINGLES_EDIT, m_stratwinsingles);
	DDV_MaxChars(pDX, m_stratwinsingles, 2);
	DDX_Text(pDX, IDC_ROCDOUBLES_EDIT, m_strcdoubles);
	DDV_MaxChars(pDX, m_strcdoubles, 2);
	DDX_Text(pDX, IDC_ROCMULTIPLES_EDIT, m_strcmultiples);
	DDV_MaxChars(pDX, m_strcmultiples, 2);
	DDX_Text(pDX, IDC_ROCQUADS_EDIT, m_strcquads);
	DDV_MaxChars(pDX, m_strcquads, 2);
	DDX_Text(pDX, IDC_ROCTRIPLES_EDIT, m_strctriples);
	DDV_MaxChars(pDX, m_strctriples, 2);
	DDX_Text(pDX, IDC_ROCTWINS_EDIT, m_strctwins);
	DDV_MaxChars(pDX, m_strctwins, 2);
	DDX_Text(pDX, IDC_ROCTWINSINGLES_EDIT, m_strctwinsingles);
	DDV_MaxChars(pDX, m_strctwinsingles, 2);
	DDX_Text(pDX, IDC_ROEDOUBLES_EDIT, m_stredoubles);
	DDV_MaxChars(pDX, m_stredoubles, 2);
	DDX_Text(pDX, IDC_ROEMULTIPLES_EDIT, m_stremultiples);
	DDV_MaxChars(pDX, m_stremultiples, 2);
	DDX_Text(pDX, IDC_ROEQUADS_EDIT, m_strequads);
	DDV_MaxChars(pDX, m_strequads, 2);
	DDX_Text(pDX, IDC_ROESINGLES_EDIT, m_stresingles);
	DDV_MaxChars(pDX, m_stresingles, 2);
	DDX_Text(pDX, IDC_ROETRIPLES_EDIT, m_stretriples);
	DDV_MaxChars(pDX, m_stretriples, 2);
	DDX_Text(pDX, IDC_ROETWINS_EDIT, m_stretwins);
	DDV_MaxChars(pDX, m_stretwins, 2);
	DDX_Text(pDX, IDC_ROETWINSINGLES_EDIT, m_stretwinsingles);
	DDX_Text(pDX, IDC_BOOKINGDATE_TEXT, m_bookingdate);
	DDX_Text(pDX, IDC_USER_TEXT, m_user);
	DDX_Text(pDX, IDC_CANCEL_TEXT, m_canceltext);
	DDX_Text(pDX, IDC_BOOKINGDATE_STATIC, m_date_text);
	DDX_Text(pDX, IDC_ALGHOTELNAAM_TEXT, m_alghotelnaam);
	DDX_Text(pDX, IDC_ALGNIGHTS_TEXT, m_algnights);
	DDX_Text(pDX, IDC_ALGDEPARTDAY_TEXT, m_algdepartday);
	DDX_Text(pDX, IDC_ALGARRIVALDAY_TEXT, m_algarrivalday);
	DDX_Text(pDX, IDC_AGAGENTNAAM_TEXT, m_agagentname);
	DDX_Text(pDX, IDC_REMARKS_EDIT, m_remarks);
	DDV_MaxChars(pDX, m_remarks, 600);
	DDX_Check(pDX, IDC_REMCARRENTAL_CHECK, m_remcarrental);
	DDX_Check(pDX, IDC_REMEXCURSION_CHECK, m_remexcursion);
	DDX_Check(pDX, IDC_REMTRANSFER_CHECK, m_remtransfer);
	DDX_Check(pDX, IDC_ROPERIODE1_CHECK, m_roperiode1);
	DDX_Check(pDX, IDC_ROPERIODE2_CHECK, m_roperiode2);
	DDX_Check(pDX, IDC_ROPERIODE3_CHECK, m_roperiode3);
	DDX_Check(pDX, IDC_ROPERIODE4_CHECK, m_roperiode4);
	DDX_Check(pDX, IDC_ROPERIODE5_CHECK, m_roperiode5);
	DDX_Text(pDX, IDC_ROBUTTONNR_STATIC, m_robuttonnr);
	DDX_Check(pDX, IDC_ROPERIODE6_CHECK, m_roperiode6);
	DDX_Check(pDX, IDC_ROPERIODE7_CHECK, m_roperiode7);
	DDX_Check(pDX, IDC_ROPERIODE8_CHECK, m_roperiode8);
	DDX_Check(pDX, IDC_ROPERIODE9_CHECK, m_roperiode9);
	DDX_Check(pDX, IDC_ROPERIODE10_CHECK, m_roperiode10);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBookingsView, CFormView)
	//{{AFX_MSG_MAP(CBookingsView)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_WIJZIGEN_BUTTON, OnWijzigenButton)
	ON_BN_CLICKED(IDC_VORIGE_BUTTON, OnVorigeButton)
	ON_BN_CLICKED(IDC_VOLGENDE_BUTTON, OnVolgendeButton)
	ON_BN_CLICKED(IDC_VERWIJDEREN_BUTTON, OnVerwijderenButton)
	ON_BN_CLICKED(IDC_TOURREF_BUTTON, OnTourrefButton)
	ON_BN_CLICKED(IDC_TONEN_BUTTON, OnTonenButton)
	ON_BN_CLICKED(IDC_PRIVALLOTMENT_BUTTON, OnPrivallotmentButton)
	ON_BN_CLICKED(IDC_OPSLAAN_BUTTON, OnOpslaanButton)
	ON_BN_CLICKED(IDC_NIEUW_BUTTON, OnNieuwButton)
	ON_BN_CLICKED(IDC_NIETOPSLAAN_BUTTON, OnNietopslaanButton)
	ON_BN_CLICKED(IDC_CANCEL_BUTTON, OnCancelButton)
	ON_BN_CLICKED(IDC_ALGHOTEL_BUTTON, OnAlghotelButton)
	ON_BN_CLICKED(IDC_AGAGENT_BUTTON, OnAgagentButton)
	ON_EN_KILLFOCUS(IDC_AGAGENTCODE_EDIT, OnKillfocusAgagentcodeEdit)
	ON_EN_KILLFOCUS(IDC_ALGHOTELCODE_EDIT, OnKillfocusAlghotelcodeEdit)
	ON_EN_KILLFOCUS(IDC_ALGARRIVALDATE_EDIT, OnKillfocusAlgarrivaldateEdit)
	ON_EN_KILLFOCUS(IDC_ALGDEPARTDATE_EDIT, OnKillfocusAlgdepartdateEdit)
	ON_EN_KILLFOCUS(IDC_TOURREF_EDIT, OnKillfocusTourrefEdit)
	ON_NOTIFY(TCN_SELCHANGE, IDC_BOOKING_TAB, OnSelchangeBookingTab)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT, OnUpdateFilePrint)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_DIRECT, OnUpdateFilePrintDirect)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_PREVIEW, OnUpdateFilePrintPreview)
	ON_UPDATE_COMMAND_UI(IDC_VOLGENDE_BUTTON, OnUpdateVolgendeButton)
	ON_UPDATE_COMMAND_UI(IDC_VORIGE_BUTTON, OnUpdateVorigeButton)
	ON_UPDATE_COMMAND_UI(IDC_OPSLAAN_BUTTON, OnUpdateOpslaanButton)
	ON_UPDATE_COMMAND_UI(IDC_NIETOPSLAAN_BUTTON, OnUpdateNietopslaanButton)
	ON_UPDATE_COMMAND_UI(IDC_VERWIJDEREN_BUTTON, OnUpdateVerwijderenButton)
	ON_WM_DESTROY()
	ON_COMMAND(ID_ACCEL32806, OnAccel32806)
	ON_BN_CLICKED(IDC_ROPERIODE1_BUTTON, OnRoperiode1Button)
	ON_BN_CLICKED(IDC_ROPERIODE2_BUTTON, OnRoperiode2Button)
	ON_BN_CLICKED(IDC_ROPERIODE3_BUTTON, OnRoperiode3Button)
	ON_BN_CLICKED(IDC_ROPERIODE4_BUTTON, OnRoperiode4Button)
	ON_BN_CLICKED(IDC_ROPERIODE5_BUTTON, OnRoperiode5Button)
	ON_UPDATE_COMMAND_UI(IDC_TONEN_BUTTON, OnUpdateTonenButton)
	ON_UPDATE_COMMAND_UI(IDC_WIJZIGEN_BUTTON, OnUpdateWijzigenButton)
	ON_UPDATE_COMMAND_UI(IDC_CANCEL_BUTTON, OnUpdateCancelButton)
	ON_UPDATE_COMMAND_UI(IDC_NIEUW_BUTTON, OnUpdateNieuwButton)
	ON_BN_CLICKED(IDC_ROPERIODE0_BUTTON, OnRoperiode0Button)
	ON_BN_CLICKED(IDC_ROINPUT_BUTTON, OnRoinputButton)
	ON_BN_CLICKED(IDC_ROPERIODE10_BUTTON, OnRoperiode10Button)
	ON_BN_CLICKED(IDC_ROPERIODE6_BUTTON, OnRoperiode6Button)
	ON_BN_CLICKED(IDC_ROPERIODE7_BUTTON, OnRoperiode7Button)
	ON_BN_CLICKED(IDC_ROPERIODE8_BUTTON, OnRoperiode8Button)
	ON_BN_CLICKED(IDC_ROPERIODE9_BUTTON, OnRoperiode9Button)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookingsView diagnostics

#ifdef _DEBUG
void CBookingsView::AssertValid() const
{
	CFormView::AssertValid();
}

void CBookingsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBookingsView message handlers

extern CTravelApp theApp;

void CBookingsView::OnSelchangeBookingTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int selectie = m_tab.GetCurSel();

	switch(selectie)
	{
	case 0: f_tab1();
			m_tabkeuze = 1;
		break;
	case 1: f_tab2();
			m_tabkeuze = 2;
		break;
	case 2: f_tab3();
			m_tabkeuze = 3;
		break;
	case 3: f_tab4();
			m_tabkeuze = 4;
		break;
	}
	
	*pResult = 0;
}

void CBookingsView::OnInitialUpdate() 
{
	CString m_zoekwaarde;

	BeginWaitCursor();
	GetDocument()->SetTitle("FIT booking - ADD");

	CFormView::OnInitialUpdate();
	
	// change our size to a nice size :)
	ResizeParentToFit(false);

	m_gebruiker = theApp.gebruiker;

	TC_ITEM TabCtrlItem;

	TabCtrlItem.mask = TCIF_TEXT;
	TabCtrlItem.pszText = "General";
	m_tab.InsertItem(0, &TabCtrlItem );
	TabCtrlItem.pszText = "Service";
	m_tab.InsertItem(1, &TabCtrlItem );
	TabCtrlItem.pszText = "Printen";
	m_tab.InsertItem(2, &TabCtrlItem );
	TabCtrlItem.pszText = "Remarks";
	m_tab.InsertItem(3, &TabCtrlItem );

//	GetDlgItem(IDC_PRIVALLOTMENT_BUTTON)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_TOURREF_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TOURREF_EDIT)->EnableWindow(FALSE);

	GetDlgItem(IDC_ALGHOTEL_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENT_BUTTON)->ShowWindow(SW_HIDE);

	if (theApp.groep == -1)
	{
		m_toegang_tonen       = TRUE;
		m_toegang_toevoegen   = TRUE;
		m_toegang_wijzigen    = TRUE;
		m_toegang_verwijderen = TRUE;
		m_toegang_cancellen   = TRUE;
	}
	else
	{
		CToegang m_toegang;
		CString  m_zoekwaarde;
		CString  m_groep;

		m_groep.Format("%d", theApp.groep);

		m_zoekwaarde = "functie = 'fit' AND groep = " + m_groep;
		m_toegang.m_strFilter = m_zoekwaarde;
		m_toegang.Open();
		m_toegang_tonen       = m_toegang.m_tonen;
		m_toegang_toevoegen   = m_toegang.m_nieuw;
		m_toegang_wijzigen    = m_toegang.m_wijzigen;
		m_toegang_verwijderen = m_toegang.m_verwijderen;
		m_toegang_cancellen   = m_toegang.m_cancellen;
		m_toegang.Close();
	}

	m_setbooking.Open();

	m_zoekwaarde = "bo_tourref = '" + m_setbooking.m_bo_tourref + "'";
	m_setperioden.m_strFilter = m_zoekwaarde;
	m_setperioden.Open();

	m_periode = 0;

	if (m_toegang_toevoegen)
		OnNieuwButton();
	else
		OnTonenButton();

	m_printdirect = FALSE;
	m_buttoncheck = FALSE;
	EndWaitCursor();
}

void CBookingsView::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	m_setbooking.Close();
	m_setperioden.Close();
	CFormView::OnClose();
}

void CBookingsView::OnTonenButton() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->SetTitle("FIT booking - SHOW");

	m_tonen       = TRUE;
	m_nieuw       = FALSE;
	m_wijzigen    = FALSE;
	m_verwijderen = FALSE;
	m_cancel      = FALSE;
	m_privallotment = FALSE;

	GetDlgItem(IDC_TOURREF_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TOURREF_EDIT)->EnableWindow(TRUE);

	GetDlgItem(IDC_ALGHOTEL_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENT_BUTTON)->ShowWindow(SW_HIDE);

	veldenediten(FALSE);
	if (!m_setbooking.IsEOF())
		recordweergeven();
	else
		veldenleegmaken();

	m_tab.SetCurSel(0);
	f_tab1();
	m_tabkeuze = 1;
}

void CBookingsView::OnNieuwButton() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->SetTitle("FIT booking - ADD");

	m_tonen       = FALSE;
	m_nieuw       = TRUE;
	m_wijzigen    = FALSE;
	m_verwijderen = FALSE;
	m_cancel      = FALSE;
	m_privallotment = FALSE;

	m_tab.SetCurSel(0);
	f_tab1();
	m_tabkeuze = 1;

	GetDlgItem(IDC_TOURREF_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TOURREF_EDIT)->EnableWindow(FALSE);

	veldenediten(TRUE);
	veldenleegmaken();
}

void CBookingsView::OnWijzigenButton() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->SetTitle("FIT booking - CHANGE");

	m_tonen       = FALSE;
	m_nieuw       = FALSE;
	m_wijzigen    = TRUE;
	m_verwijderen = FALSE;
	m_cancel      = FALSE;
	m_privallotment = FALSE;

	GetDlgItem(IDC_TOURREF_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TOURREF_EDIT)->EnableWindow(TRUE);

	veldenediten(TRUE);
	if (!m_setbooking.IsEOF())
		recordweergeven();
	else
		veldenleegmaken();

	m_tab.SetCurSel(0);
	f_tab1();
	m_tabkeuze = 1;
}

void CBookingsView::OnVerwijderenButton() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->SetTitle("FIT booking - DELETE");

	m_tonen       = FALSE;
	m_nieuw       = FALSE;
	m_wijzigen    = FALSE;
	m_verwijderen = TRUE;
	m_cancel      = FALSE;
	m_privallotment = FALSE;

	GetDlgItem(IDC_TOURREF_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TOURREF_EDIT)->EnableWindow(TRUE);

	GetDlgItem(IDC_ALGHOTEL_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENT_BUTTON)->ShowWindow(SW_HIDE);

	veldenediten(FALSE);
	if (!m_setbooking.IsEOF())
		recordweergeven();
	else
		veldenleegmaken();

	m_tab.SetCurSel(0);
	f_tab1();
	m_tabkeuze = 1;
}

void CBookingsView::OnCancelButton() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->SetTitle("FIT booking - CANCEL");

	m_tonen       = FALSE;
	m_nieuw       = FALSE;
	m_wijzigen    = FALSE;
	m_verwijderen = FALSE;
	m_cancel      = TRUE;
	m_privallotment = FALSE;

	GetDlgItem(IDC_TOURREF_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TOURREF_EDIT)->EnableWindow(TRUE);

	GetDlgItem(IDC_ALGHOTEL_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENT_BUTTON)->ShowWindow(SW_HIDE);

	veldenediten(FALSE);
	if (!m_setbooking.IsEOF())
		recordweergeven();
	else
		veldenleegmaken();

	m_tab.SetCurSel(0);
	f_tab1();
	m_tabkeuze = 1;
}

void CBookingsView::OnPrivallotmentButton() 
{
	// TODO: Add your control notification handler code here
	m_tonen       = FALSE;
	m_nieuw       = FALSE;
	m_wijzigen    = FALSE;
	m_verwijderen = FALSE;
	m_cancel      = FALSE;
	m_privallotment = TRUE;

	GetDlgItem(IDC_TOURREF_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TOURREF_EDIT)->EnableWindow(TRUE);

	GetDlgItem(IDC_ALGHOTEL_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENT_BUTTON)->ShowWindow(SW_HIDE);

	veldenediten(FALSE);
	if (!m_setbooking.IsEOF())
		recordweergeven();
	else
		veldenleegmaken();

	m_tab.SetCurSel(0);
	f_tab1();
	m_tabkeuze = 1;
}

void CBookingsView::OnNietopslaanButton() 
{
	// TODO: Add your control notification handler code here
	recordweergeven();
}

void CBookingsView::OnOpslaanButton() 
{
	// TODO: Add your control notification handler code here

	COleDateTime m_vandaag;
	m_vandaag = COleDateTime::GetCurrentTime();

	char invoer[4], invoer2[4];

	CEdit *invoerveld = (CEdit *) GetDlgItem(IDC_ROCSINGLES_EDIT);
	invoerveld->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld2 = (CEdit *) GetDlgItem(IDC_ROASINGLES_EDIT);
	invoerveld2->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roasingles[m_periode] = atoi(invoer);

	CEdit *invoerveld3 = (CEdit *) GetDlgItem(IDC_ROESINGLES_EDIT);
	invoerveld3->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roesingles[m_periode] = atoi(invoer);

	CEdit *invoerveld4 = (CEdit *) GetDlgItem(IDC_ROATWINSINGLES_EDIT);
	invoerveld4->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld5 = (CEdit *) GetDlgItem(IDC_ROETWINSINGLES_EDIT);
	invoerveld5->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld6 = (CEdit *) GetDlgItem(IDC_ROCTWINSINGLES_EDIT);
	invoerveld6->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld7 = (CEdit *) GetDlgItem(IDC_ROATWINS_EDIT);
	invoerveld7->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwins[m_periode] = atoi(invoer);

	CEdit *invoerveld8 = (CEdit *) GetDlgItem(IDC_ROETWINS_EDIT);
	invoerveld8->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwins[m_periode] = atoi(invoer);

	CEdit *invoerveld9 = (CEdit *) GetDlgItem(IDC_ROCTWINS_EDIT);
	invoerveld9->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwins[m_periode] = atoi(invoer);

	CEdit *invoerveld10 = (CEdit *) GetDlgItem(IDC_ROADOUBLES_EDIT);
	invoerveld10->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roadoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld11 = (CEdit *) GetDlgItem(IDC_ROEDOUBLES_EDIT);
	invoerveld11->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roedoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld12 = (CEdit *) GetDlgItem(IDC_ROCDOUBLES_EDIT);
	invoerveld12->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocdoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld13 = (CEdit *) GetDlgItem(IDC_ROATRIPLES_EDIT);
	invoerveld13->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatriples[m_periode] = atoi(invoer);

	CEdit *invoerveld14 = (CEdit *) GetDlgItem(IDC_ROETRIPLES_EDIT);
	invoerveld14->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetriples[m_periode] = atoi(invoer);

	CEdit *invoerveld15 = (CEdit *) GetDlgItem(IDC_ROCTRIPLES_EDIT);
	invoerveld15->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctriples[m_periode] = atoi(invoer);

	CEdit *invoerveld16 = (CEdit *) GetDlgItem(IDC_ROAQUADS_EDIT);
	invoerveld16->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roaquads[m_periode] = atoi(invoer);

	CEdit *invoerveld17 = (CEdit *) GetDlgItem(IDC_ROEQUADS_EDIT);
	invoerveld17->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roequads[m_periode] = atoi(invoer);

	CEdit *invoerveld18 = (CEdit *) GetDlgItem(IDC_ROCQUADS_EDIT);
	invoerveld18->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocquads[m_periode] = atoi(invoer);

	CEdit *invoerveld19 = (CEdit *) GetDlgItem(IDC_ROAMULTIPLES_EDIT);
	invoerveld19->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roamultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld20 = (CEdit *) GetDlgItem(IDC_ROEMULTIPLES_EDIT);
	invoerveld20->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roemultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld21 = (CEdit *) GetDlgItem(IDC_ROCMULTIPLES_EDIT);
	invoerveld21->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocmultiples[m_periode] = atoi(invoer);

	
	UpdateData(TRUE);

	if (OpslaanCheck())
	{
		if (m_nieuw)
		{
			bepaal_tourref();
			m_setbooking.AddNew();
			inhoudopslaan();
			m_setbooking.Update();
			MessageBox("Tourref: " + m_tourref,
				"Update data", MB_OK  + MB_ICONEXCLAMATION);
			if (m_prdocket || m_prvoucher || m_prreconfirmation)
			{
				m_printdirect = TRUE;
				CFormView::OnFilePrint();
				m_printdirect = FALSE;
			}
			m_setbooking.Requery();
			veldenleegmaken();
		}
		else if (m_wijzigen)
		{
			m_setbooking.Edit();
			inhoudopslaan();
			m_setbooking.Update();
			if (m_prdocket || m_prvoucher || m_prreconfirmation)
			{
				m_printdirect = TRUE;
				CFormView::OnFilePrint();
				m_printdirect = FALSE;
			}
		}
		else if (m_verwijderen)
		{
			if (m_setbooking.m_bo_cancel == "0")
				DeleteRooms();

			m_setperioden.MoveFirst();
			while (!m_setperioden.IsBOF())
			{
				m_setperioden.Delete();
				m_setperioden.MoveFirst();
			}

			m_setbooking.Delete();
			if (m_setbooking.IsEOF())
				veldenleegmaken();
			else
			{
				m_setbooking.MoveFirst();
				recordweergeven();
			}
		}
		else if (m_cancel 
			&& m_setbooking.m_bo_cancel == "0")
		{
			DeleteRooms();
			m_setbooking.Edit();
			m_setbooking.m_bo_cancel = m_vandaag.Format("%Y%m%d");
			m_setbooking.m_us_naam    = m_gebruiker;
			m_setbooking.m_bo_privall = FALSE;

			m_setbooking.m_bo_prconfirm = FALSE;
			m_setbooking.m_bo_prdocket = FALSE;
			m_setbooking.m_bo_prvoucher = FALSE;
			m_setbooking.m_bo_prcancel = TRUE;

			m_setbooking.Update();

			m_date_text  = "Canceldate:";
			m_canceltext = "CANCELLED";
			GetDlgItem(IDC_CANCEL_TEXT)->ShowWindow(SW_SHOW);

			m_prdocket = FALSE;
			m_prvoucher = FALSE;
			m_prreconfirmation = FALSE;
			m_prcancellation = TRUE;

			UpdateData(FALSE);

			m_printdirect = TRUE;
			CFormView::OnFilePrint();
			m_printdirect = FALSE;
		}
		else if (m_privallotment && !m_setbooking.m_bo_privall
			&& m_setbooking.m_bo_cancel == "0")
		{
			m_setbooking.Edit();
			m_setbooking.m_bo_privall = TRUE;
			m_setbooking.Update();
		}
		else if (m_privallotment && m_setbooking.m_bo_privall)
		{
			m_setbooking.Edit();
			m_setbooking.m_bo_privall = FALSE;
			m_setbooking.Update();
		}

		f_tab1();
		m_tabkeuze = 1;
		m_tab.SetCurSel(0);
	}
}

BOOL CBookingsView::OpslaanCheck() 
{
	COleDateTime m_begindatum, m_einddatum;
	BOOL nietingevuld = FALSE;
	CString velden = "";
	CDatecnv     m_datecnv;
	COleDateTime m_vandaag;

	m_vandaag = COleDateTime::GetCurrentTime();

	if (m_nieuw)
		if (MessageBox("Are you sure, you want to add this data?",
			"Update data", MB_OKCANCEL  + MB_ICONEXCLAMATION) != IDOK)
			return FALSE;

	if ((m_wijzigen || m_verwijderen || m_privallotment || m_cancel)
		&& m_setbooking.IsEOF())
		return FALSE;

	if (m_wijzigen)
		if (MessageBox("Are you sure, you want to save the changes?",
			"Update data", MB_OKCANCEL  + MB_ICONEXCLAMATION) != IDOK)
		{
			recordweergeven();
			return FALSE;
		}

	if (m_verwijderen)
		if (MessageBox("Are you sure, you want to delete this data?",
			"Update data", MB_OKCANCEL  + MB_ICONEXCLAMATION) != IDOK)
			return FALSE;

	if (m_cancel)
		if (MessageBox("Are you sure, you want to cancel this data?",
			"Update data", MB_OKCANCEL  + MB_ICONEXCLAMATION) != IDOK)
			return FALSE;

	if (m_wijzigen && m_setbooking.m_bo_cancel != "0")
	{
		MessageBox("You can't change a cancelled booking !\n",
			"Update data", MB_OK + MB_ICONSTOP);
		return FALSE;
	}

	if (m_wijzigen && m_setbooking.m_bo_privall)
	{
		MessageBox("You can't change a private allotment !\n",
			"Update data", MB_OK + MB_ICONSTOP);
		return FALSE;
	}

	if (m_nieuw || m_wijzigen)
	{
	if (m_algarrivaldate != "")
	{
		m_begindatum.ParseDateTime(m_algarrivaldate, VAR_DATEVALUEONLY);
		if (m_begindatum.m_dt == 0)
		{
			MessageBox("The arrivaldate isn't correct !\n",
				"Update data", MB_OK + MB_ICONSTOP);
			return FALSE;
		}
		else if (m_begindatum < m_vandaag)
		{
			if (MessageBox("WARNING!!! The arrivaldate is before today ! Toch opslaan?\n",
				"Update data", MB_OKCANCEL + MB_ICONSTOP) != IDOK)
				return FALSE;
		}
	}
	else
	{
		velden += "the arrivaldate\n";
		nietingevuld = TRUE;
	}

	if (m_algdepartdate != "")
	{
		m_einddatum.ParseDateTime(m_algdepartdate, VAR_DATEVALUEONLY);
		if (m_einddatum.m_dt == 0)
		{
			MessageBox("The departdate isn't correct !\n",
				"Update data", MB_OK + MB_ICONSTOP);
			return FALSE;
		}
		else if (m_einddatum < m_vandaag)
		{
			if (MessageBox("WARNING!!! The departdate is before today ! Toch opslaan?\n",
				"Update data", MB_OKCANCEL + MB_ICONSTOP) != IDOK)
				return FALSE;
		}
	}
	else
	{
		velden += "the departdate\n";
		nietingevuld = TRUE;
	}

	if (m_einddatum < m_begindatum)
	{
		MessageBox("The departdate is before the arrivaldate !\n",
			"Update data", MB_OK + MB_ICONSTOP);
		return FALSE;
	}
	
	if (m_alghotelcode == "")
	{
		velden += "the hotelcode\n";
		nietingevuld = TRUE;
	}

	if (m_algpassenger == "")
	{
		velden += "the passengers name\n";
		nietingevuld = TRUE;
	}

/*	if (m_algpax == 0)
	{
		velden += "the pax is zero\n";
		nietingevuld = TRUE;
	}
*/
	int totaalaantal;
	int i;

	totaalaantal = 0;
	for (i = 0; i < 10; i++)
	{
		totaalaantal += m_roasingles[i];
		totaalaantal += m_roatwinsingles[i];
		totaalaantal += m_roatwins[i];
		totaalaantal += m_roadoubles[i];
		totaalaantal += m_roatriples[i];
		totaalaantal += m_roaquads[i];
		totaalaantal += m_roamultiples[i];
		totaalaantal += m_roesingles[i];
		totaalaantal += m_roetwinsingles[i];
		totaalaantal += m_roetwins[i]  ;
		totaalaantal += m_roedoubles[i];
		totaalaantal += m_roetriples[i];
		totaalaantal += m_roequads[i];
		totaalaantal += m_roemultiples[i];
		totaalaantal += m_rocsingles[i];
		totaalaantal += m_roctwinsingles[i];
		totaalaantal += m_roctwins[i]  ;
		totaalaantal += m_rocdoubles[i];
		totaalaantal += m_roctriples[i];
		totaalaantal += m_rocquads[i];
		totaalaantal += m_rocmultiples[i];
	}

	if (totaalaantal == 0)
	{
		velden += "the total of rooms is zero\n";
		nietingevuld = TRUE;
	}

	if (nietingevuld)
	{
		MessageBox("The following isn't filled:\n" + velden,
			"Update data", MB_OK + MB_ICONEXCLAMATION);
		return FALSE;
	}

	int singles[10], tsu[10], twins[10];
	int doubles[10], triples[10], quads[10], multiples[10];
	BOOL correct;

	for (i = 0; i < 10; i++)
	{
		singles[i]   = 0;
		tsu[i]       = 0;
		twins[i]     = 0;
		doubles[i]   = 0;
		triples[i]   = 0;
		quads[i]     = 0;
		multiples[i] = 0;
	}
	for (i = 0; i < 10; i++)
	{
		singles[i]   = m_roasingles[i] + m_roesingles[i] + m_rocsingles[i];
		tsu[i]       = m_roatwinsingles[i] + m_roetwinsingles[i] + m_roctwinsingles[i];
		twins[i]     = m_roatwins[i] + m_roetwins[i] + m_roctwins[i];
		doubles[i]   = m_roadoubles[i] + m_roedoubles[i] + m_rocdoubles[i];
		triples[i]   = m_roatriples[i] + m_roetriples[i] + m_roctriples[i];
		quads[i]     = m_roaquads[i] + m_roequads[i] + m_rocquads[i];
		multiples[i] = m_roamultiples[i] + m_roemultiples[i] + m_rocmultiples[i];
	}

	correct = TRUE;
	if ((singles[0] != singles[1] && m_startdates[1] != "") || 
		(singles[0] != singles[2] && m_startdates[2] != "") || 
		(singles[0] != singles[3] && m_startdates[3] != "") || 
		(singles[0] != singles[4] && m_startdates[4] != "") ||
		(singles[0] != singles[5] && m_startdates[5] != "") || 
		(singles[0] != singles[6] && m_startdates[6] != "") || 
		(singles[0] != singles[7] && m_startdates[7] != "") ||
		(singles[0] != singles[8] && m_startdates[8] != "") || 
		(singles[0] != singles[9] && m_startdates[9] != "")) 

		correct = FALSE;

	else if ((tsu[0] != tsu[1] && m_startdates[1] != "") || 
			 (tsu[0] != tsu[2] && m_startdates[2] != "") || 
			 (tsu[0] != tsu[3] && m_startdates[3] != "") || 
			 (tsu[0] != tsu[4] && m_startdates[4] != "") ||
			 (tsu[0] != tsu[5] && m_startdates[5] != "") || 
			 (tsu[0] != tsu[6] && m_startdates[6] != "") || 
			 (tsu[0] != tsu[7] && m_startdates[7] != "") ||
			 (tsu[0] != tsu[8] && m_startdates[8] != "") || 
			 (tsu[0] != tsu[9] && m_startdates[9] != "")) 

		correct = FALSE;

	else if ((twins[0] != twins[1] && m_startdates[1] != "") || 
			 (twins[0] != twins[2] && m_startdates[2] != "") || 
			 (twins[0] != twins[3] && m_startdates[3] != "") || 
			 (twins[0] != twins[4] && m_startdates[4] != "") ||
			 (twins[0] != twins[5] && m_startdates[5] != "") || 
			 (twins[0] != twins[6] && m_startdates[6] != "") || 
			 (twins[0] != twins[7] && m_startdates[7] != "") ||
			 (twins[0] != twins[8] && m_startdates[8] != "") || 
			 (twins[0] != twins[9] && m_startdates[9] != "")) 

		correct = FALSE;

	else if ((doubles[0] != doubles[1] && m_startdates[1] != "") || 
			 (doubles[0] != doubles[2] && m_startdates[2] != "") || 
			 (doubles[0] != doubles[3] && m_startdates[3] != "") || 
			 (doubles[0] != doubles[4] && m_startdates[4] != "") ||
			 (doubles[0] != doubles[5] && m_startdates[5] != "") || 
			 (doubles[0] != doubles[6] && m_startdates[6] != "") || 
			 (doubles[0] != doubles[7] && m_startdates[7] != "") ||
			 (doubles[0] != doubles[8] && m_startdates[8] != "") || 
			 (doubles[0] != doubles[9] && m_startdates[9] != "")) 

		correct = FALSE;

	else if ((triples[0] != triples[1] && m_startdates[1] != "") || 
			 (triples[0] != triples[2] && m_startdates[2] != "") || 
			 (triples[0] != triples[3] && m_startdates[3] != "") || 
			 (triples[0] != triples[4] && m_startdates[4] != "") ||
			 (triples[0] != triples[5] && m_startdates[5] != "") || 
			 (triples[0] != triples[6] && m_startdates[6] != "") || 
			 (triples[0] != triples[7] && m_startdates[7] != "") ||
			 (triples[0] != triples[8] && m_startdates[8] != "") || 
			 (triples[0] != triples[9] && m_startdates[9] != ""))

		correct = FALSE;

	else if ((quads[0] != quads[1] && m_startdates[1] != "") || 
			 (quads[0] != quads[2] && m_startdates[2] != "") || 
			 (quads[0] != quads[3] && m_startdates[3] != "") || 
			 (quads[0] != quads[4] && m_startdates[4] != "") ||
			 (quads[0] != quads[5] && m_startdates[5] != "") || 
			 (quads[0] != quads[6] && m_startdates[6] != "") || 
			 (quads[0] != quads[7] && m_startdates[7] != "") ||
			 (quads[0] != quads[8] && m_startdates[8] != "") || 
			 (quads[0] != quads[9] && m_startdates[9] != ""))

		correct = FALSE;

	else if ((multiples[0] != multiples[1] && m_startdates[1] != "") || 
			 (multiples[0] != multiples[2] && m_startdates[2] != "") || 
			 (multiples[0] != multiples[3] && m_startdates[3] != "") || 
			 (multiples[0] != multiples[4] && m_startdates[4] != "") ||
			 (multiples[0] != multiples[5] && m_startdates[5] != "") || 
			 (multiples[0] != multiples[6] && m_startdates[6] != "") || 
			 (multiples[0] != multiples[7] && m_startdates[7] != "") ||
			 (multiples[0] != multiples[8] && m_startdates[8] != "") || 
			 (multiples[0] != multiples[9] && m_startdates[9] != ""))

		correct = FALSE;


	if (!correct && !m_nuldeperiode)
	{
			MessageBox("The number of rooms is not correct",
				"Update data", MB_OK + MB_ICONEXCLAMATION);
			return FALSE;
	}

	if (m_nieuw && (totaalaantal > 0))
	{
		if (!AllocateRooms())
			return FALSE;
	}
	else if (m_wijzigen)
	{
		if (!ChangeRooms())
			return FALSE;
	}

/*
	COleDateTime      begin, eind, vanaf, tot;
	BOOL              beginseason, eindseason;
	COleDateTimeSpan  verschil;
	CHotels           m_sethotels;
	CString           m_zoekwaarde;

	m_zoekwaarde = "ho_code = '" + m_setbooking.m_ho_code + "'";
	m_sethotels.m_strSort   = "ho_code";
	m_sethotels.m_strFilter = m_zoekwaarde;
	m_sethotels.Open();

	begin.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate), VAR_DATEVALUEONLY);
	eind.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_depdate), VAR_DATEVALUEONLY);

	beginseason = FALSE;
	eindseason  = FALSE;

	if (m_sethotels.m_ho_from1 != "")
	{
	vanaf.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from1), VAR_DATEVALUEONLY);
	tot.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till1), VAR_DATEVALUEONLY);

	if (begin >= vanaf && begin <= tot)
		beginseason = TRUE;

	if (eind >= vanaf && eind <= tot)
		eindseason  = TRUE;
	}

	if (m_sethotels.m_ho_from2 != "")
	{
	vanaf.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from2), VAR_DATEVALUEONLY);
	tot.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till2), VAR_DATEVALUEONLY);

	if (begin >= vanaf && begin <= tot)
		beginseason = TRUE;

	if (eind >= vanaf && eind <= tot)
		eindseason  = TRUE;
	}

	if (m_sethotels.m_ho_from3 != "")
	{
	vanaf.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from3), VAR_DATEVALUEONLY);
	tot.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till3), VAR_DATEVALUEONLY);

	if (begin >= vanaf && begin < vanaf)
		beginseason = TRUE;

	if (eind >= vanaf && eind <= tot)
		eindseason  = TRUE;
	}

	if (m_sethotels.m_ho_from4 != "")
	{
	vanaf.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from4), VAR_DATEVALUEONLY);
	tot.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till4), VAR_DATEVALUEONLY);

	if (begin >= vanaf && begin <= tot)
		beginseason = TRUE;

	if (eind >= vanaf && eind <= tot)
		eindseason  = TRUE;
	}

	if (m_sethotels.m_ho_from5 != "")
	{
	vanaf.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from5), VAR_DATEVALUEONLY);
	tot.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till5), VAR_DATEVALUEONLY);

	if (begin >= vanaf && begin <= tot)
		beginseason = TRUE;

	if (eind >= vanaf && eind <= tot)
		eindseason  = TRUE;
	}

	if (m_sethotels.m_ho_from6 != "")
	{
	vanaf.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from6), VAR_DATEVALUEONLY);
	tot.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till6), VAR_DATEVALUEONLY);

	if (begin >= vanaf && begin <= tot)
		beginseason = TRUE;

	if (eind >= vanaf && eind <= tot)
		eindseason  = TRUE;
	}

	if (!beginseason || !eindseason)
		MessageBox("WARNING !!! The price of the stay can't be calcullated! \n See the hotels maintenance.",
			"Update data", MB_OK + MB_ICONEXCLAMATION);

	m_sethotels.Close();
*/
	}

	return TRUE;
}

void CBookingsView::OnVorigeButton() 
{
	// TODO: Add your control notification handler code here

	if (!m_setbooking.IsBOF())
	{
		m_setbooking.MovePrev();
		if (m_setbooking.IsBOF())
			m_setbooking.MoveNext();

		recordweergeven();
	}
}

void CBookingsView::OnVolgendeButton() 
{
	// TODO: Add your control notification handler code here

	if (!m_setbooking.IsEOF())
	{
		m_setbooking.MoveNext();
		if (m_setbooking.IsEOF())
			m_setbooking.MovePrev();

		recordweergeven();
	}
}

void CBookingsView::OnKillfocusTourrefEdit() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (!m_nieuw && m_tourref != "" 
		&& m_setbooking.m_bo_tourref != m_tourref
		&& !m_setbooking.IsEOF())
	{
		SetCursor(LoadCursor(NULL, IDC_WAIT));

		if (m_setbooking.m_bo_tourref.CompareNoCase(m_tourref) < 0)
		{
			while (m_setbooking.m_bo_tourref.CompareNoCase(m_tourref) < 0
						&& !m_setbooking.IsEOF())
				m_setbooking.MoveNext();
			if (m_setbooking.IsEOF())
				m_setbooking.MovePrev();
		}
		else
		{
			m_setbooking.MoveFirst();
			while (m_setbooking.m_bo_tourref.CompareNoCase(m_tourref) < 0)
				m_setbooking.MoveNext();
		}

		recordweergeven();
		SetCursor(LoadCursor(NULL, IDC_ARROW));
	}
}

void CBookingsView::bepaal_tourref()
{
	COleDateTime m_datum;
	char volgnr_char[4];

	m_datum.ParseDateTime(m_algarrivaldate, VAR_DATEVALUEONLY);
	if (m_datum.m_dt != 0)
	{
		m_jmmdd = m_datum.Format("%Y%m%d");
		m_jmmdd = m_jmmdd.Right(5);
		if (m_setbooking.IsEOF())
			m_volgnr = 1;
		else
		{
			m_setbooking.MoveFirst();
			while (!m_setbooking.IsEOF() &&
					 m_setbooking.m_bo_periode <= m_jmmdd)
				m_setbooking.MoveNext();
			if (m_setbooking.m_bo_periode > m_jmmdd)
				m_setbooking.MovePrev();
			if (m_setbooking.m_bo_periode == m_jmmdd)
			{
				m_volgnr = m_setbooking.m_bo_volgnr;
				m_volgnr++;
			}
			else
				m_volgnr = 1;
		}

		itoa(m_volgnr, volgnr_char, 10);
		if (m_volgnr < 10)
		{
			volgnr_char[3] = '\0';
			volgnr_char[2] = volgnr_char[0];
			volgnr_char[1] = '0';
			volgnr_char[0] = '0';
		}
		else if (m_volgnr < 100)
		{
			volgnr_char[3] = '\0';
			volgnr_char[2] = volgnr_char[1];
			volgnr_char[1] = volgnr_char[0];
			volgnr_char[0] = '0';
		}

		m_tourref = m_jmmdd + (CString) volgnr_char;
	}
}

void CBookingsView::veldenediten(BOOL edit)
{
	m_stretwinsingles_cntrl.SetReadOnly(!edit);
	m_stretwins_cntrl.SetReadOnly(!edit);
	m_stretriples_cntrl.SetReadOnly(!edit);
	m_stresingles_cntrl.SetReadOnly(!edit);
	m_strequads_cntrl.SetReadOnly(!edit);
	m_stremultiples_cntrl.SetReadOnly(!edit);
	m_stredoubles_cntrl.SetReadOnly(!edit);
	m_strctwinsingles_cntrl.SetReadOnly(!edit);
	m_strctwins_cntrl.SetReadOnly(!edit);
	m_strctriples_cntrl.SetReadOnly(!edit);
	m_strcsingles_cntrl.SetReadOnly(!edit);
	m_strcquads_cntrl.SetReadOnly(!edit);
	m_strcmultiples_cntrl.SetReadOnly(!edit);
	m_strcdoubles_cntrl.SetReadOnly(!edit);
	m_stratwinsingles_cntrl.SetReadOnly(!edit);
	m_stratwins_cntrl.SetReadOnly(!edit);
	m_stratriples_cntrl.SetReadOnly(!edit);
	m_strasingles_cntrl.SetReadOnly(!edit);
	m_straquads_cntrl.SetReadOnly(!edit);
	m_stramultiples_cntrl.SetReadOnly(!edit);
	m_stradoubels_cntrl.SetReadOnly(!edit);
	m_prmhotel_cntrl.SetReadOnly(!edit);
	m_prmagent_cntrl.SetReadOnly(!edit);
	m_algpax_cntrl.SetReadOnly(!edit);
	m_algpassenger_cntrl.SetReadOnly(!edit);
	m_alghotelcode_cntrl.SetReadOnly(!edit);
	m_algdepartdate_cntrl.SetReadOnly(!edit);
	m_algconfirmedby_cntrl.SetReadOnly(!edit);
	m_algbookedby_cntrl.SetReadOnly(!edit);
	m_algarrivaldate_cntrl.SetReadOnly(!edit);
	m_agreference_cntrl.SetReadOnly(!edit);
	m_agagentcode_cntrl.SetReadOnly(!edit);
	m_remarks_cntrl.SetReadOnly(!edit);

	GetDlgItem(IDC_RONORMAL_RADIO)->EnableWindow(edit);
	GetDlgItem(IDC_ROLATE_RADIO)->EnableWindow(edit);
	GetDlgItem(IDC_ROEARLY_RADIO)->EnableWindow(edit);
	GetDlgItem(IDC_ROBB_RADIO)->EnableWindow(edit);
	GetDlgItem(IDC_RORO_RADIO)->EnableWindow(edit);
	GetDlgItem(IDC_ROHB_RADIO)->EnableWindow(edit);
	GetDlgItem(IDC_ROPERIODE1_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_ROPERIODE2_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_ROPERIODE3_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_ROPERIODE4_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_ROPERIODE5_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_ROPERIODE6_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_ROPERIODE7_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_ROPERIODE8_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_ROPERIODE9_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_ROPERIODE10_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_PRCANCELLATION_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_PRDOCKET_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_PRRECONFIRMATION_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_PRVOUCHER_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_REMTRANSFER_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_REMEXCURSION_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_REMCARRENTAL_CHECK)->EnableWindow(edit);
}

void CBookingsView::recordweergeven()
{
	COleDateTime m_datum;
	CDatecnv   m_datecnv;
	CString text1, text2, text3, text4, text5;
	CString text6, text7, text8, text9, text10;

	if (m_setbooking.m_bo_privall || m_setbooking.m_bo_cancel != "0")
		GetDlgItem(IDC_CANCEL_TEXT)->ShowWindow(SW_SHOW);
	else
		GetDlgItem(IDC_CANCEL_TEXT)->ShowWindow(SW_HIDE);

	if (m_setbooking.m_bo_cancel == "0")
	{
		m_date_text   = "Bookingdate:";
		m_bookingdate = m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_date);
		m_canceltext  = "";

		GetDlgItem(IDC_PRCANCELLATION_CHECK)->ShowWindow(SW_HIDE);
	}
	else
	{
		m_date_text   = "Canceldate:";
		m_bookingdate = m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_cancel);
		m_canceltext  = "CANCELLED";

		if (m_tabkeuze == 3)
			GetDlgItem(IDC_PRCANCELLATION_CHECK)->ShowWindow(SW_SHOW);
	}

	if (m_setbooking.m_bo_privall)
		m_canceltext = "PRIVATE ALLOTMENT";

	m_tourref          = m_setbooking.m_bo_tourref;
	m_user             = m_setbooking.m_us_naam;
	m_algdepartdate    = m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_depdate);
	m_algarrivaldate   = m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate);
	m_alghotelcode     = m_setbooking.m_ho_code;
	m_alghotelnaam     = m_setbooking.m_ho_name;
	m_algnights        = MaakStr(m_setbooking.m_bo_nights);
	m_algpassenger     = m_setbooking.m_bo_passn;
	m_algpax           = m_setbooking.m_bo_pax;
	m_algbookedby      = m_setbooking.m_bo_bkdby;
	m_algconfirmedby   = m_setbooking.m_bo_cnfmdby;

	m_datum.ParseDateTime(m_algarrivaldate, VAR_DATEVALUEONLY);
	m_algarrivalday    = m_datum.Format("%A");

	m_datum.ParseDateTime(m_algdepartdate, VAR_DATEVALUEONLY);
	m_algdepartday     = m_datum.Format("%A");

	m_agreference      = m_setbooking.m_bo_agentrf;
	m_agagentcode      = m_setbooking.m_ag_code;
	m_agagentname      = m_setbooking.m_ag_name;
	m_agagentcode      = m_setbooking.m_ag_code;

	if      (m_setbooking.m_bo_service == "Bed and breakfast")
		m_robb = 0;
	else if (m_setbooking.m_bo_service == "Room Only")
		m_robb = 1;
	else // HB
		m_robb = 2;

	if      (m_setbooking.m_bo_arrival == "Normal")
		m_ronormal = 0;
	else if (m_setbooking.m_bo_arrival == "Late")
		m_ronormal = 1;
	else // Early
		m_ronormal = 2;

	m_roperiode1 = FALSE;
	m_roperiode2 = FALSE;
	m_roperiode3 = FALSE;
	m_roperiode4 = FALSE;
	m_roperiode5 = FALSE;
	m_roperiode6 = FALSE;
	m_roperiode7 = FALSE;
	m_roperiode8 = FALSE;
	m_roperiode9 = FALSE;
	m_roperiode10 = FALSE;

	text1 = "";
	text2 = "";
	text3 = "";
	text4 = "";
	text5 = "";
	text6 = "";
	text7 = "";
	text8 = "";
	text9 = "";
	text10 = "";

	int i;

	for (i = 0; i < 10; i++)
	{
		m_startdates[i] = "";
		m_enddates[i]   = "";
		m_allotment[i]  = 0;
		m_extra[i]      = 0;
		m_roasingles[i] = 0;
		m_roatwinsingles[i] = 0;
		m_roatwins[i] = 0;
		m_roadoubles[i] = 0;
		m_roatriples[i] = 0;
		m_roaquads[i] = 0;
		m_roamultiples[i] = 0;
		m_roesingles[i] = 0;
		m_roetwinsingles[i] = 0;
		m_roetwins[i]   = 0;
		m_roedoubles[i] = 0;
		m_roetriples[i] = 0;
		m_roequads[i] = 0;
		m_roemultiples[i] = 0;
		m_rocsingles[i] = 0;
		m_roctwinsingles[i] = 0;
		m_roctwins[i]   = 0;
		m_rocdoubles[i] = 0;
		m_roctriples[i] = 0;
		m_rocquads[i] = 0;
		m_rocmultiples[i] = 0;
	}

	CString getalstr;
	CString m_zoekwaarde;

	m_setperioden.Close();
	m_zoekwaarde = "bo_tourref = '" + m_setbooking.m_bo_tourref + "'";
	m_setperioden.m_strFilter = m_zoekwaarde;
	m_setperioden.Open();

	m_periode = 0;
	if (!m_setperioden.IsEOF())
	{
	m_setperioden.MoveFirst();
	i = 0;

	m_startdates[i] = m_datecnv.Datetoddmmjjjj(m_setperioden.m_bo_startdate);
	m_enddates[i]   = m_datecnv.Datetoddmmjjjj(m_setperioden.m_bo_enddate);
	m_allotment[i]  = m_setperioden.m_bo_allotment;
	m_extra[i]      = m_setperioden.m_bo_extra;
	m_roadoubles[i] = m_setperioden.m_bo_adbls;
	m_roaquads[i]   = m_setperioden.m_bo_aqds;
	m_roasingles[i] = m_setperioden.m_bo_asngls;
	m_roatriples[i] = m_setperioden.m_bo_atrpls;
	m_roamultiples[i] = m_setperioden.m_bo_amltpls;
	m_roatwins[i]   = m_setperioden.m_bo_atwns;
	m_roatwinsingles[i]   = m_setperioden.m_bo_atwnsngls;
	m_roedoubles[i] = m_setperioden.m_bo_edbls;
	m_roequads[i]   = m_setperioden.m_bo_eqds;
	m_roesingles[i] = m_setperioden.m_bo_esngls;
	m_roemultiples[i] = m_setperioden.m_bo_emltpls;
	m_roetriples[i] = m_setperioden.m_bo_etrpls;
	m_roetwins[i]   = m_setperioden.m_bo_etwns;
	m_roetwinsingles[i]   = m_setperioden.m_bo_etwnsngls;
	m_roctwinsingles[i]   = m_setperioden.m_bo_rtwnsngls;
	m_roctwins[i]   = m_setperioden.m_bo_rtwns;
	m_rocdoubles[i] = m_setperioden.m_bo_rdbls;
	m_rocquads[i] = m_setperioden.m_bo_rqds;
	m_rocsingles[i] = m_setperioden.m_bo_rsngls;
	m_rocmultiples[i] = m_setperioden.m_bo_rmltpls;
	m_roctriples[i] = m_setperioden.m_bo_rtrpls;

	m_oldstartdates[i] = m_datecnv.Datetoddmmjjjj(m_setperioden.m_bo_startdate);
	m_oldenddates[i]   = m_datecnv.Datetoddmmjjjj(m_setperioden.m_bo_enddate);
	m_oldallotment[i]  = m_setperioden.m_bo_allotment;
	m_oldextra[i]      = m_setperioden.m_bo_extra;
	m_oldadoubles[i] = m_setperioden.m_bo_adbls;
	m_oldaquads[i]   = m_setperioden.m_bo_aqds;
	m_oldasingles[i] = m_setperioden.m_bo_asngls;
	m_oldatriples[i] = m_setperioden.m_bo_atrpls;
	m_oldamultiples[i] = m_setperioden.m_bo_amltpls;
	m_oldatwins[i]   = m_setperioden.m_bo_atwns;
	m_oldatwinsingles[i]   = m_setperioden.m_bo_atwnsngls;
	m_oldedoubles[i] = m_setperioden.m_bo_edbls;
	m_oldequads[i]   = m_setperioden.m_bo_eqds;
	m_oldesingles[i] = m_setperioden.m_bo_esngls;
	m_oldemultiples[i] = m_setperioden.m_bo_emltpls;
	m_oldetriples[i] = m_setperioden.m_bo_etrpls;
	m_oldetwins[i]   = m_setperioden.m_bo_etwns;
	m_oldetwinsingles[i]   = m_setperioden.m_bo_etwnsngls;
	m_oldctwinsingles[i]   = m_setperioden.m_bo_rtwnsngls;
	m_oldctwins[i]   = m_setperioden.m_bo_rtwns;
	m_oldcdoubles[i] = m_setperioden.m_bo_rdbls;
	m_oldcquads[i] = m_setperioden.m_bo_rqds;
	m_oldcsingles[i] = m_setperioden.m_bo_rsngls;
	m_oldcmultiples[i] = m_setperioden.m_bo_rmltpls;
	m_oldctriples[i] = m_setperioden.m_bo_rtrpls;

	if (m_setperioden.m_bo_adbls != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_adbls);
		m_stradoubles = getalstr;
	}
	else
		m_stradoubles = "";

	if (m_setperioden.m_bo_aqds != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_aqds);
		m_straquads  = getalstr;
	}
	else
		m_straquads  = "";
	
	if (m_setperioden.m_bo_asngls != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_asngls);
		m_strasingles = getalstr;
	}
	else
		m_strasingles = "";
	
	if (m_setperioden.m_bo_atrpls != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_atrpls);
		m_stratriples = getalstr;
	}
	else
		m_stratriples = "";
	
	if (m_setperioden.m_bo_amltpls != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_amltpls);
		m_stramultiples = getalstr;
	}
	else
		m_stramultiples = "";
	
	if (m_setperioden.m_bo_atwns != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_atwns);
		m_stratwins = getalstr;
	}
	else
		m_stratwins = "";
	
	if (m_setperioden.m_bo_atwnsngls != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_atwnsngls);
		m_stratwinsingles = getalstr;
	}
	else
		m_stratwinsingles = "";
	
	if (m_setperioden.m_bo_edbls != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_edbls);
		m_stredoubles = getalstr;
	}
	else
		m_stredoubles = "";
	
	if (m_setperioden.m_bo_eqds != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_eqds);
		m_strequads = getalstr;
	}
	else
		m_strequads = "";
	
	if (m_setperioden.m_bo_esngls != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_esngls);
		m_stresingles = getalstr;
	}
	else
		m_stresingles = "";
	
	if (m_setperioden.m_bo_etrpls != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_etrpls);
		m_stretriples = getalstr;
	}
	else
		m_stretriples = "";
	
	if (m_setperioden.m_bo_emltpls != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_emltpls);
		m_stremultiples = getalstr;
	}
	else
		m_stremultiples = "";
	
	if (m_setperioden.m_bo_etwns != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_etwns);
		m_stretwins = getalstr;
	}
	else
		m_stretwins = "";
	
	if (m_setperioden.m_bo_etwnsngls != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_etwnsngls);
		m_stretwinsingles = getalstr;
	}
	else
		m_stretwinsingles = "";
	
	if (m_setperioden.m_bo_rtwnsngls != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_rtwnsngls);
		m_strctwinsingles = getalstr;
	}
	else
		m_strctwinsingles = "";
	
	if (m_setperioden.m_bo_rtwns != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_rtwns);
		m_strctwins = getalstr;
	}
	else
		m_strctwins = "";
	
	if (m_setperioden.m_bo_rdbls != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_rdbls);
		m_strcdoubles = getalstr;
	}
	else
		m_strcdoubles = "";
	
	if (m_setperioden.m_bo_rqds != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_rqds);
		m_strcquads = getalstr;
	}
	else
		m_strcquads = "";

	if (m_setperioden.m_bo_rsngls != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_rsngls);
		m_strcsingles = getalstr;
	}
	else
		m_strcsingles = "";
	
	if (m_setperioden.m_bo_rmltpls != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_rmltpls);
		m_strcmultiples = getalstr;
	}
	else
		m_strcmultiples = "";

	if (m_setperioden.m_bo_rtrpls != 0)
	{
		getalstr.Format("%d", m_setperioden.m_bo_rtrpls);
		m_strctriples = getalstr;
	}
	else
		m_strctriples = "";

	m_setperioden.MoveNext();
	i = 1;

	while (!m_setperioden.IsEOF())
	{
		m_startdates[i] = m_datecnv.Datetoddmmjjjj(m_setperioden.m_bo_startdate);
		m_enddates[i]   = m_datecnv.Datetoddmmjjjj(m_setperioden.m_bo_enddate);
		m_allotment[i]  = m_setperioden.m_bo_allotment;
		m_extra[i]      = m_setperioden.m_bo_extra;
		m_roadoubles[i] = m_setperioden.m_bo_adbls;
		m_roaquads[i]   = m_setperioden.m_bo_aqds;
		m_roasingles[i] = m_setperioden.m_bo_asngls;
		m_roatriples[i] = m_setperioden.m_bo_atrpls;
		m_roamultiples[i] = m_setperioden.m_bo_amltpls;
		m_roatwins[i]   = m_setperioden.m_bo_atwns;
		m_roatwinsingles[i]   = m_setperioden.m_bo_atwnsngls;
		m_roedoubles[i] = m_setperioden.m_bo_edbls;
		m_roequads[i]   = m_setperioden.m_bo_eqds;
		m_roesingles[i] = m_setperioden.m_bo_esngls;
		m_roemultiples[i] = m_setperioden.m_bo_emltpls;
		m_roetriples[i] = m_setperioden.m_bo_etrpls;
		m_roetwins[i]   = m_setperioden.m_bo_etwns;
		m_roetwinsingles[i]   = m_setperioden.m_bo_etwnsngls;
		m_roctwinsingles[i]   = m_setperioden.m_bo_rtwnsngls;
		m_roctwins[i]   = m_setperioden.m_bo_rtwns;
		m_rocdoubles[i] = m_setperioden.m_bo_rdbls;
		m_rocquads[i] = m_setperioden.m_bo_rqds;
		m_rocsingles[i] = m_setperioden.m_bo_rsngls;
		m_rocmultiples[i] = m_setperioden.m_bo_rmltpls;
		m_roctriples[i] = m_setperioden.m_bo_rtrpls;

		m_oldstartdates[i] = m_datecnv.Datetoddmmjjjj(m_setperioden.m_bo_startdate);
		m_oldenddates[i]   = m_datecnv.Datetoddmmjjjj(m_setperioden.m_bo_enddate);
		m_oldallotment[i]  = m_setperioden.m_bo_allotment;
		m_oldextra[i]      = m_setperioden.m_bo_extra;
		m_oldadoubles[i] = m_setperioden.m_bo_adbls;
		m_oldaquads[i]   = m_setperioden.m_bo_aqds;
		m_oldasingles[i] = m_setperioden.m_bo_asngls;
		m_oldatriples[i] = m_setperioden.m_bo_atrpls;
		m_oldamultiples[i] = m_setperioden.m_bo_amltpls;
		m_oldatwins[i]   = m_setperioden.m_bo_atwns;
		m_oldatwinsingles[i]   = m_setperioden.m_bo_atwnsngls;
		m_oldedoubles[i] = m_setperioden.m_bo_edbls;
		m_oldequads[i]   = m_setperioden.m_bo_eqds;
		m_oldesingles[i] = m_setperioden.m_bo_esngls;
		m_oldetriples[i] = m_setperioden.m_bo_etrpls;
		m_oldemultiples[i] = m_setperioden.m_bo_emltpls;
		m_oldetwins[i]   = m_setperioden.m_bo_etwns;
		m_oldetwinsingles[i]   = m_setperioden.m_bo_etwnsngls;
		m_oldctwinsingles[i]   = m_setperioden.m_bo_rtwnsngls;
		m_oldctwins[i]   = m_setperioden.m_bo_rtwns;
		m_oldcdoubles[i] = m_setperioden.m_bo_rdbls;
		m_oldcquads[i] = m_setperioden.m_bo_rqds;
		m_oldcsingles[i] = m_setperioden.m_bo_rsngls;
		m_oldcmultiples[i] = m_setperioden.m_bo_rmltpls;
		m_oldctriples[i] = m_setperioden.m_bo_rtrpls;

		i++;
		m_setperioden.MoveNext();
	}

	text1 = "Van   " + m_startdates[0] + "   t/m   " + m_enddates[0] + "    " + 
				MaakStr2(m_allotment[0]) + "    " + MaakStr2(m_extra[0]);
	m_periodes = 1;

	if (m_startdates[1] != "")
	{
		text2 = "Van   " + m_startdates[1] + "   t/m   " + m_enddates[1] + "    " + 
					MaakStr2(m_allotment[1]) + "    " + MaakStr2(m_extra[1]);
		m_periodes = 2;
	}
	if (m_startdates[2] != "")
	{
		text3 = "Van   " + m_startdates[2] + "   t/m   " + m_enddates[2] + "    " + 
					MaakStr2(m_allotment[2]) + "    " + MaakStr2(m_extra[2]);
		m_periodes = 3;
	}
	if (m_startdates[3] != "")
	{
		text4 = "Van   " + m_startdates[3] + "   t/m   " + m_enddates[3] + "    " + 
					MaakStr2(m_allotment[3]) + "    " + MaakStr2(m_extra[3]);
		m_periodes = 4;
	}
	if (m_startdates[4] != "")
	{
		text5 = "Van   " + m_startdates[4] + "   t/m   " + m_enddates[4] + "    " + 
					MaakStr2(m_allotment[4]) + "    " + MaakStr2(m_extra[4]);
		m_periodes = 5;
	}
	if (m_startdates[5] != "")
	{
		text6 = "Van   " + m_startdates[5] + "   t/m   " + m_enddates[5] + "    " + 
					MaakStr2(m_allotment[5]) + "    " + MaakStr2(m_extra[5]);
		m_periodes = 6;
	}
	if (m_startdates[6] != "")
	{
		text7 = "Van   " + m_startdates[6] + "   t/m   " + m_enddates[6] + "    " + 
					MaakStr2(m_allotment[6]) + "    " + MaakStr2(m_extra[6]);
		m_periodes = 7;
	}
	if (m_startdates[7] != "")
	{
		text8 = "Van   " + m_startdates[7] + "   t/m   " + m_enddates[7] + "    " + 
					MaakStr2(m_allotment[7]) + "    " + MaakStr2(m_extra[7]);
		m_periodes = 8;
	}
	if (m_startdates[8] != "")
	{
		text9 = "Van   " + m_startdates[8] + "   t/m   " + m_enddates[8] + "    " + 
					MaakStr2(m_allotment[8]) + "    " + MaakStr2(m_extra[8]);
		m_periodes = 9;
	}
	if (m_startdates[9] != "")
	{
		text10 = "Van   " + m_startdates[9] + "   t/m   " + m_enddates[9] + "    " + 
					MaakStr2(m_allotment[9]) + "    " + MaakStr2(m_extra[9]);
		m_periodes = 10;
	}
	}

	CStatic *periode1 = (CStatic *) GetDlgItem(IDC_ROPERIODE1_STATIC);
	CStatic *periode2 = (CStatic *) GetDlgItem(IDC_ROPERIODE2_STATIC);
	CStatic *periode3 = (CStatic *) GetDlgItem(IDC_ROPERIODE3_STATIC);
	CStatic *periode4 = (CStatic *) GetDlgItem(IDC_ROPERIODE4_STATIC);
	CStatic *periode5 = (CStatic *) GetDlgItem(IDC_ROPERIODE5_STATIC);
	CStatic *periode6 = (CStatic *) GetDlgItem(IDC_ROPERIODE6_STATIC);
	CStatic *periode7 = (CStatic *) GetDlgItem(IDC_ROPERIODE7_STATIC);
	CStatic *periode8 = (CStatic *) GetDlgItem(IDC_ROPERIODE8_STATIC);
	CStatic *periode9 = (CStatic *) GetDlgItem(IDC_ROPERIODE9_STATIC);
	CStatic *periode10 = (CStatic *) GetDlgItem(IDC_ROPERIODE10_STATIC);

	periode1->SetWindowText(text1);
	periode2->SetWindowText(text2);
	periode3->SetWindowText(text3);
	periode4->SetWindowText(text4);
	periode5->SetWindowText(text5);
	periode6->SetWindowText(text6);
	periode7->SetWindowText(text7);
	periode8->SetWindowText(text8);
	periode9->SetWindowText(text9);
	periode10->SetWindowText(text10);

	if (m_tabkeuze == 2)
	{
		if (text2 != "")
		{
			GetDlgItem(IDC_ROPERIODE0_BUTTON)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_ROPERIODE1_BUTTON)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_ROPERIODE2_BUTTON)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_ROPERIODE1_CHECK)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_ROPERIODE2_CHECK)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_ROINPUT_BUTTON)->ShowWindow(SW_SHOW);
			m_robuttonnr = "1";
		}
		else
		{
			GetDlgItem(IDC_ROPERIODE0_BUTTON)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_ROPERIODE1_BUTTON)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_ROPERIODE2_BUTTON)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_ROPERIODE1_CHECK)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_ROPERIODE2_CHECK)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_ROINPUT_BUTTON)->ShowWindow(SW_HIDE);
			m_robuttonnr = "";
		}

		if (text3 != "")
		{
			GetDlgItem(IDC_ROPERIODE3_BUTTON)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_ROPERIODE3_CHECK)->ShowWindow(SW_SHOW);
		}
		else
		{
			GetDlgItem(IDC_ROPERIODE3_BUTTON)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_ROPERIODE3_CHECK)->ShowWindow(SW_HIDE);
		}
		
		if (text4 != "")
		{
			GetDlgItem(IDC_ROPERIODE4_BUTTON)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_ROPERIODE4_CHECK)->ShowWindow(SW_SHOW);
		}
		else
		{
			GetDlgItem(IDC_ROPERIODE4_BUTTON)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_ROPERIODE4_CHECK)->ShowWindow(SW_HIDE);
		}
		
		if (text5 != "")
		{
			GetDlgItem(IDC_ROPERIODE5_BUTTON)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_ROPERIODE5_CHECK)->ShowWindow(SW_SHOW);
		}
		else
		{
			GetDlgItem(IDC_ROPERIODE5_BUTTON)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_ROPERIODE5_CHECK)->ShowWindow(SW_HIDE);
		}

		if (text6 != "")
		{
			GetDlgItem(IDC_ROPERIODE6_BUTTON)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_ROPERIODE6_CHECK)->ShowWindow(SW_SHOW);
		}
		else
		{
			GetDlgItem(IDC_ROPERIODE6_BUTTON)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_ROPERIODE6_CHECK)->ShowWindow(SW_HIDE);
		}
		
		if (text7 != "")
		{
			GetDlgItem(IDC_ROPERIODE7_BUTTON)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_ROPERIODE7_CHECK)->ShowWindow(SW_SHOW);
		}
		else
		{
			GetDlgItem(IDC_ROPERIODE7_BUTTON)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_ROPERIODE7_CHECK)->ShowWindow(SW_HIDE);
		}
		
		if (text8 != "")
		{
			GetDlgItem(IDC_ROPERIODE8_BUTTON)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_ROPERIODE8_CHECK)->ShowWindow(SW_SHOW);
		}
		else
		{
			GetDlgItem(IDC_ROPERIODE8_BUTTON)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_ROPERIODE8_CHECK)->ShowWindow(SW_HIDE);
		}
		
		if (text9 != "")
		{
			GetDlgItem(IDC_ROPERIODE9_BUTTON)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_ROPERIODE9_CHECK)->ShowWindow(SW_SHOW);
		}
		else
		{
			GetDlgItem(IDC_ROPERIODE9_BUTTON)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_ROPERIODE9_CHECK)->ShowWindow(SW_HIDE);
		}
		
		if (text10 != "")
		{
			GetDlgItem(IDC_ROPERIODE10_BUTTON)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_ROPERIODE10_CHECK)->ShowWindow(SW_SHOW);
		}
		else
		{
			GetDlgItem(IDC_ROPERIODE10_BUTTON)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_ROPERIODE10_CHECK)->ShowWindow(SW_HIDE);
		}
	}

	m_prmagent   = m_setbooking.m_bo_magent;
	m_prmhotel   = m_setbooking.m_bo_mhotel;
	m_remarks    = m_setbooking.m_bo_remark1 
					+ m_setbooking.m_bo_remark2 
					+ m_setbooking.m_bo_remark3;
	m_prcancellation   = m_setbooking.m_bo_prcancel;
	m_prdocket         = m_setbooking.m_bo_prdocket;
	m_prreconfirmation = m_setbooking.m_bo_prconfirm;
	m_prvoucher        = m_setbooking.m_bo_prvoucher;
	m_remtransfer      = m_setbooking.m_bo_transfer;
	m_remexcursion     = m_setbooking.m_bo_excursion;
	m_remcarrental     = m_setbooking.m_bo_carrental;

	UpdateData(FALSE);

//	if (m_tabkeuze == 3)
//		BerekenAvailable();
}

void CBookingsView::veldenleegmaken()
{
	CDatecnv m_datecnv;

	m_tourref = "";
	m_date_text = "Bookingdate:";
	m_canceltext = "";
	m_bookingdate = m_datecnv.Vandaag();
	m_user = m_gebruiker;
	m_algdepartdate  = "";
	m_algarrivaldate = "";
	m_alghotelcode = "";
	m_alghotelnaam = "";
	m_nights        = 0;
	m_algnights     = "";
	m_algpassenger = "";
	m_algpax = 0;
	m_algbookedby = "";
	m_algconfirmedby = "";
	m_algarrivalday  = "";
	m_algdepartday   = "";
	m_agreference = "";
	m_agagentcode = "";
	m_agagentname = "";

	int i;

	for (i = 0; i < 10; i++)
	{
		m_roasingles[i] = 0;
		m_roatwinsingles[i] = 0;
		m_roatwins[i] = 0;
		m_roadoubles[i] = 0;
		m_roatriples[i] = 0;
		m_roaquads[i] = 0;
		m_roamultiples[i] = 0;
		m_roesingles[i] = 0;
		m_roetwinsingles[i] = 0;
		m_roetwins[i]   = 0;
		m_roedoubles[i] = 0;
		m_roetriples[i] = 0;
		m_roequads[i] = 0;
		m_roemultiples[i] = 0;
		m_rocsingles[i] = 0;
		m_roctwinsingles[i] = 0;
		m_roctwins[i]   = 0;
		m_rocdoubles[i] = 0;
		m_roctriples[i] = 0;
		m_rocquads[i] = 0;
		m_rocmultiples[i] = 0;
	}
	m_strasingles = "";
	m_stratwinsingles = "";
	m_stratwins   = "";
	m_stradoubles = "";
	m_stratriples = "";
	m_straquads = "";
	m_stramultiples = "";
	m_stresingles = "";
	m_stretwinsingles = "";
	m_stretwins   = "";
	m_stredoubles = "";
	m_stretriples = "";
	m_strequads = "";
	m_stremultiples = "";
	m_strcsingles = "";
	m_strctwinsingles = "";
	m_strctwins   = "";
	m_strcdoubles = "";
	m_strctriples = "";
	m_strcquads = "";
	m_strcmultiples = "";
	m_ronormal = 0;
	m_robb = 0;
	m_roperiode1 = FALSE;
	m_roperiode2 = FALSE;
	m_roperiode3 = FALSE;
	m_roperiode4 = FALSE;
	m_roperiode5 = FALSE;
	m_roperiode6 = FALSE;
	m_roperiode7 = FALSE;
	m_roperiode8 = FALSE;
	m_roperiode9 = FALSE;
	m_roperiode10 = FALSE;
	m_robuttonnr = "";
	m_prmagent  = "";
	m_prmhotel  = "";
	m_remarks  = "";
	m_prcancellation = FALSE;
	m_prdocket = TRUE;
	m_prreconfirmation = TRUE;
	m_prvoucher = FALSE;
	m_remtransfer  = FALSE;
	m_remexcursion = FALSE;
	m_remcarrental = FALSE;

	m_periode = 0;

	UpdateData(FALSE);
}

void CBookingsView::inhoudopslaan()
{
	COleDateTimeSpan verschil;
	int aantalnachten;
	COleDateTime m_arrival, m_depart;
	CDatecnv m_datecnv;

	if (m_agagentcode == "")
	{
		m_agagentcode = "ZZZ";
		m_agagentname = "Direct booking";
	}

	if (m_nieuw)
	{
		m_setbooking.m_bo_tourref = m_tourref;
		m_setbooking.m_bo_periode = m_jmmdd;
		m_setbooking.m_bo_volgnr  = m_volgnr;

		m_setbooking.m_bo_cancel  = "0";
	}

	m_setbooking.m_bo_date    = m_datecnv.Datetojjjjmmdd(m_bookingdate);
	m_setbooking.m_us_naam    = m_gebruiker;
	m_setbooking.m_bo_depdate = m_datecnv.Datetojjjjmmdd(m_algdepartdate);
	m_setbooking.m_bo_arrdate = m_datecnv.Datetojjjjmmdd(m_algarrivaldate);
	m_setbooking.m_ho_code    = m_alghotelcode;
	m_setbooking.m_ho_name    = m_alghotelnaam;
//
//	if (m_nights == 0)
//	{
//		m_arrival.ParseDateTime(m_algarrivaldate, VAR_DATEVALUEONLY);
//		m_depart.ParseDateTime(m_algdepartdate, VAR_DATEVALUEONLY);
//
//		verschil = m_depart - m_arrival;
//		m_nights = (int) verschil.GetTotalDays();
//	}
//	
	m_setbooking.m_bo_nights  = m_nights;
	m_setbooking.m_bo_passn   = m_algpassenger;
	m_setbooking.m_bo_pax     = m_algpax;
	m_setbooking.m_bo_bkdby   = m_algbookedby;
	m_setbooking.m_bo_cnfmdby = m_algconfirmedby;
	m_setbooking.m_bo_agentrf = m_agreference;
	m_setbooking.m_ag_code    = m_agagentcode;
	m_setbooking.m_ag_name    = m_agagentname;

	if  (m_robb == 0)    
		m_setbooking.m_bo_service = "Bed and breakfast";
	else if (m_robb == 1)
		m_setbooking.m_bo_service = "Room only";
	else // m_robb == 2
		m_setbooking.m_bo_service = "Half board";

	if      (m_ronormal == 0)    
		m_setbooking.m_bo_arrival = "Normal";
	else if (m_ronormal == 1)
		m_setbooking.m_bo_arrival = "Late";
	else // m_ronormal = 2;
		m_setbooking.m_bo_arrival = "Early";

	m_setbooking.m_bo_asngls    = m_roasingles[0] + m_roesingles[0] + m_rocsingles[0];
	m_setbooking.m_bo_atwnsngls = m_roatwinsingles[0] + m_roetwinsingles[0] + m_roctwinsingles[0];
	m_setbooking.m_bo_atwns     = m_roatwins[0] + m_roetwins[0] + m_roctwins[0];
	m_setbooking.m_bo_adbls     = m_roadoubles[0] + m_roedoubles[0] + m_rocdoubles[0];
	m_setbooking.m_bo_atrpls    = m_roatriples[0] + m_roetriples[0] +  m_roctriples[0];
	m_setbooking.m_bo_aqds      = m_roaquads[0] + m_roequads[0] + m_rocquads[0];
	m_setbooking.m_bo_amltpls   = m_roamultiples[0] + m_roemultiples[0] + m_rocmultiples[0];
	m_setbooking.m_bo_magent    = m_prmagent;
	m_setbooking.m_bo_mhotel    = m_prmhotel;
	m_setbooking.m_bo_remark1   = m_remarks.Left(250);
	if (m_remarks.GetLength() > 250)
		m_setbooking.m_bo_remark2   = m_remarks.Mid(250, 250);
	else
		m_setbooking.m_bo_remark2   = "";
	if (m_remarks.GetLength() > 500)
		m_setbooking.m_bo_remark3   = m_remarks.Mid(500, 100);
	else
		m_setbooking.m_bo_remark3   = " ";
	m_setbooking.m_bo_prcancel  = m_prcancellation;
	m_setbooking.m_bo_prdocket  = m_prdocket;
	m_setbooking.m_bo_prconfirm = m_prreconfirmation;
	m_setbooking.m_bo_prvoucher = m_prvoucher;
	m_setbooking.m_bo_invoice   = FALSE;
	m_setbooking.m_bo_transfer  = m_remtransfer;
	m_setbooking.m_bo_excursion = m_remexcursion;
	m_setbooking.m_bo_carrental = m_remcarrental;

	int i;

	if (m_periodes > 1 && m_nuldeperiode)
	{
		m_enddates[0]  = m_enddates[m_periodes - 1];
		m_allotment[0] = 0;
		m_extra[0]     = 0;

		for (i = 1; i < 10; i++)
		{
			m_startdates[i] = "";
			m_enddates[i]   = "";
			m_allotment[i]  = 0;
			m_extra[i]      = 0;
		}
	}

	if (m_nieuw)
	{
		for (i = 0; i < 10; i++)
		{
			m_setperioden.AddNew();
			m_setperioden.m_bo_tourref = m_tourref;
			m_setperioden.m_bo_startdate = m_datecnv.Datetojjjjmmdd(m_startdates[i]);
			m_setperioden.m_bo_enddate =  m_datecnv.Datetojjjjmmdd(m_enddates[i]);
			m_setperioden.m_bo_allotment = m_allotment[i];
			m_setperioden.m_bo_extra = m_extra[i];
			m_setperioden.m_bo_periode = i;
			m_setperioden.m_bo_asngls = m_roasingles[i];
			m_setperioden.m_bo_atwnsngls = m_roatwinsingles[i];
			m_setperioden.m_bo_atwns  = m_roatwins[i];
			m_setperioden.m_bo_adbls  = m_roadoubles[i];
			m_setperioden.m_bo_atrpls = m_roatriples[i];
			m_setperioden.m_bo_aqds   = m_roaquads[i];
			m_setperioden.m_bo_amltpls = m_roamultiples[i];
			m_setperioden.m_bo_esngls = m_roesingles[i];
			m_setperioden.m_bo_etwnsngls = m_roetwinsingles[i];
			m_setperioden.m_bo_etwns  = m_roetwins[i];
			m_setperioden.m_bo_edbls  = m_roedoubles[i];
			m_setperioden.m_bo_etrpls = m_roetriples[i];
			m_setperioden.m_bo_eqds   = m_roequads[i];
			m_setperioden.m_bo_emltpls = m_roemultiples[i];
			m_setperioden.m_bo_rsngls = m_rocsingles[i];
			m_setperioden.m_bo_rtwnsngls = m_roctwinsingles[i];
			m_setperioden.m_bo_rtwns  = m_roctwins[i];
			m_setperioden.m_bo_rdbls  = m_rocdoubles[i];
			m_setperioden.m_bo_rtrpls = m_roctriples[i];
			m_setperioden.m_bo_rqds   = m_rocquads[i];
			m_setperioden.m_bo_rmltpls = m_rocmultiples[i];
			m_setperioden.Update();
		}
//		m_setperioden.Requery();
//		m_setperioden.Close();
//		m_setperioden.Open();
	}
	else if (m_wijzigen)
	{
		m_setperioden.MoveFirst();

		for (i = 0; i < 10; i++)
		{
			m_setperioden.Edit();
			m_setperioden.m_bo_tourref = m_tourref;
			m_setperioden.m_bo_startdate =  m_datecnv.Datetojjjjmmdd(m_startdates[i]);
			m_setperioden.m_bo_enddate =  m_datecnv.Datetojjjjmmdd(m_enddates[i]);
			m_setperioden.m_bo_allotment = m_allotment[i];
			m_setperioden.m_bo_extra = m_extra[i];
			m_setperioden.m_bo_periode = i;
			m_setperioden.m_bo_asngls = m_roasingles[i];
			m_setperioden.m_bo_atwnsngls = m_roatwinsingles[i];
			m_setperioden.m_bo_atwns  = m_roatwins[i];
			m_setperioden.m_bo_adbls  = m_roadoubles[i];
			m_setperioden.m_bo_atrpls = m_roatriples[i];
			m_setperioden.m_bo_aqds   = m_roaquads[i];
			m_setperioden.m_bo_amltpls = m_roamultiples[i];
			m_setperioden.m_bo_esngls = m_roesingles[i];
			m_setperioden.m_bo_etwnsngls = m_roetwinsingles[i];
			m_setperioden.m_bo_etwns  = m_roetwins[i];
			m_setperioden.m_bo_edbls  = m_roedoubles[i];
			m_setperioden.m_bo_etrpls = m_roetriples[i];
			m_setperioden.m_bo_eqds   = m_roequads[i];
			m_setperioden.m_bo_emltpls = m_roemultiples[i];
			m_setperioden.m_bo_rsngls = m_rocsingles[i];
			m_setperioden.m_bo_rtwnsngls = m_roctwinsingles[i];
			m_setperioden.m_bo_rtwns  = m_roctwins[i];
			m_setperioden.m_bo_rdbls  = m_rocdoubles[i];
			m_setperioden.m_bo_rtrpls = m_roctriples[i];
			m_setperioden.m_bo_rqds   = m_rocquads[i];
			m_setperioden.m_bo_rmltpls = m_rocmultiples[i];
			m_setperioden.Update();

			m_setperioden.MoveNext();
		}

		for (i = 0; i < 10; i++)
		{
			m_oldstartdates[i] = m_startdates[i];
			m_oldenddates[i]   = m_enddates[i];
			m_oldallotment[i]  = m_allotment[i];
			m_oldextra[i]      = m_extra[i];
			m_oldadoubles[i] = m_roadoubles[i];
			m_oldaquads[i]   = m_roaquads[i];
			m_oldasingles[i] = m_roasingles[i];
			m_oldatriples[i] = m_roatriples[i];
			m_oldamultiples[i] = m_roamultiples[i];
			m_oldatwins[i]   = m_roatwins[i];
			m_oldatwinsingles[i]   = m_roatwinsingles[i];
			m_oldedoubles[i] = m_roedoubles[i];
			m_oldequads[i]   = m_roequads[i];
			m_oldesingles[i] = m_roesingles[i];
			m_oldetriples[i] = m_roetriples[i];
			m_oldemultiples[i] = m_roemultiples[i];
			m_oldetwins[i]   = m_roetwins[i];
			m_oldetwinsingles[i]   = m_roetwinsingles[i];	
			m_oldctwinsingles[i]   = m_roctwinsingles[i];	
			m_oldctwins[i]   = m_roctwins[i];	
			m_oldcdoubles[i] = m_rocdoubles[i];
			m_oldcquads[i] = m_rocquads[i];
			m_oldcsingles[i] = m_rocsingles[i];
			m_oldcmultiples[i] = m_rocmultiples[i];
			m_oldctriples[i] = m_roctriples[i];
		}
	}
}

void CBookingsView::f_tab1()
{
	GetDlgItem(IDC_ALGDEPARTDATE_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGARRIVALDATE_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGHOTELCODE_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGHOTELNAAM_TEXT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGNIGHTS_TEXT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGPASSENGER_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGBOOKEDBY_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGCONFIRMEDBY_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGARRIVALDAY_TEXT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGDEPARTDAY_TEXT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGDEPARTDATE_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGARRIVALDATE_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGHOTEL_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGHOTEL_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGHOTELNAAM_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGNIGHTS_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGPASSENGER_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGBOOKEDBY_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGCONFIRMED_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGDAG1_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGDAG2_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_AGREFERENCE_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_AGAGENTCODE_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_AGAGENT_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_AGAGENTNAAM_TEXT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_AGREFERENCE_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_AGAGENT_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_AGNAAM2_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROPERIODE1_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE2_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE3_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE4_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE5_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE6_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE7_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE8_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE9_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE10_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROBUTTONNR_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE0_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE1_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE2_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE3_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE4_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE5_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE6_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE7_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE8_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE9_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE10_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE1_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE2_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE3_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE4_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE5_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE6_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE7_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE8_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE9_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE10_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROINPUT_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROADOUBLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROAQUADS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROASINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROATWINS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROATWINSINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROATRIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROAMULTIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCMULTIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROMULTIPLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCTWINS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCDOUBLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCQUADS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCSINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCTRIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROBB_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_RORO_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROHB_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROLATE_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROEARLY_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_RONORMAL_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_RODOUBLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROQUADS_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROSINGLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROTRIPLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROTWINS_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROHEAD_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROA_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROC_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROARRIVAL_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROSERVICE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRMAGENT_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRMHOTEL_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRCANCELLATION_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRDOCKET_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRRECONFIRMATION_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRVOUCHER_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRMAGENT_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRMHOTEL_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_REMARKS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_REMTRANSFER_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_REMEXCURSION_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_REMCARRENTAL_CHECK)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_ALGPAX_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ALGPAX_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROEDOUBLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROEQUADS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROESINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROETWINS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROETWINSINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROETRIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROEMULTIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROATWINSINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCTWINSINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROTWINSINGLES_STATIC)->ShowWindow(SW_HIDE);

	if (m_wijzigen || m_nieuw)
	{
		GetDlgItem(IDC_ALGHOTEL_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_AGAGENT_BUTTON)->ShowWindow(SW_SHOW);
	}
	else
	{
		GetDlgItem(IDC_ALGHOTEL_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_AGAGENT_BUTTON)->ShowWindow(SW_HIDE);
	}
}

void CBookingsView::f_tab2()
{
	int totaalaantal;
	int i;
	CDatecnv   m_datecnv;

	UpdateData(TRUE);
	totaalaantal = 0;
	for (i = 0; i < 5; i++)
	{
		totaalaantal += m_roasingles[i];
		totaalaantal += m_roatwinsingles[i];
		totaalaantal += m_roatwins[i];
		totaalaantal += m_roadoubles[i];
		totaalaantal += m_roatriples[i];
		totaalaantal += m_roaquads[i];
		totaalaantal += m_roamultiples[i];
		totaalaantal += m_roesingles[i];
		totaalaantal += m_roetwinsingles[i];
		totaalaantal += m_roetwins[i]  ;
		totaalaantal += m_roedoubles[i];
		totaalaantal += m_roetriples[i];
		totaalaantal += m_roequads[i];
		totaalaantal += m_roemultiples[i];
		totaalaantal += m_rocsingles[i];
		totaalaantal += m_roctwinsingles[i];
		totaalaantal += m_roctwins[i]  ;
		totaalaantal += m_rocdoubles[i];
		totaalaantal += m_roctriples[i];
		totaalaantal += m_rocquads[i];
		totaalaantal += m_rocmultiples[i];
	}

	if (m_nieuw && totaalaantal == 0)
		BerekenAvailable();
	else if (m_wijzigen) // && 
//			(m_algdepartdate != m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_depdate) ||
//			 m_algarrivaldate != m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate) ||
//			 m_alghotelcode != m_setbooking.m_ho_code))
		ChangeAvailable();


	GetDlgItem(IDC_ALGDEPARTDATE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGARRIVALDATE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGHOTELCODE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGHOTEL_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGHOTELNAAM_TEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGNIGHTS_TEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGPASSENGER_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGBOOKEDBY_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGCONFIRMEDBY_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGARRIVALDAY_TEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGDEPARTDAY_TEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGDEPARTDATE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGARRIVALDATE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGHOTEL_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGHOTELNAAM_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGNIGHTS_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGPASSENGER_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGBOOKEDBY_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGCONFIRMED_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGDAG1_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGDAG2_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGREFERENCE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENTCODE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENT_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENTNAAM_TEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGREFERENCE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENT_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGNAAM2_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE1_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROPERIODE2_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROPERIODE3_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROPERIODE4_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROPERIODE5_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROPERIODE6_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROPERIODE7_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROPERIODE8_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROPERIODE9_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROPERIODE10_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROBUTTONNR_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROPERIODE0_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROINPUT_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROADOUBLES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROAQUADS_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROASINGLES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROATRIPLES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROATWINS_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROCTWINS_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROCDOUBLES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROCQUADS_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROCSINGLES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROCTRIPLES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROAMULTIPLES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROCMULTIPLES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROMULTIPLES_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROBB_RADIO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_RORO_RADIO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROHB_RADIO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROLATE_RADIO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROEARLY_RADIO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_RONORMAL_RADIO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_RODOUBLES_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROQUADS_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROSINGLES_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROTRIPLES_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROTWINS_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROHEAD_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROA_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROC_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROARRIVAL_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROSERVICE_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PRCANCELLATION_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRDOCKET_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRRECONFIRMATION_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRVOUCHER_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRMAGENT_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRMHOTEL_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRMAGENT_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRMHOTEL_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_REMARKS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_REMTRANSFER_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_REMEXCURSION_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_REMCARRENTAL_CHECK)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_ALGPAX_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGPAX_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROE_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROEDOUBLES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROEQUADS_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROESINGLES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROETWINS_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROETWINSINGLES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROETRIPLES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROEMULTIPLES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROATWINSINGLES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROCTWINSINGLES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ROTWINSINGLES_STATIC)->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_ALGHOTEL_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENT_BUTTON)->ShowWindow(SW_HIDE);

	if (m_startdates[1] != "")
	{
		GetDlgItem(IDC_ROPERIODE0_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE1_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE2_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE1_CHECK)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE2_CHECK)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROINPUT_BUTTON)->ShowWindow(SW_SHOW);
		m_robuttonnr = "1";
	}
	else
	{
		GetDlgItem(IDC_ROPERIODE0_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ROPERIODE1_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ROPERIODE2_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ROPERIODE1_CHECK)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ROPERIODE2_CHECK)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ROINPUT_BUTTON)->ShowWindow(SW_HIDE);
		m_robuttonnr = "";
	}

	if (m_startdates[2] != "")
	{
		GetDlgItem(IDC_ROPERIODE3_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE3_CHECK)->ShowWindow(SW_SHOW);
	}
	else
	{
		GetDlgItem(IDC_ROPERIODE3_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ROPERIODE3_CHECK)->ShowWindow(SW_HIDE);
	}
		
	if (m_startdates[3] != "")
	{
		GetDlgItem(IDC_ROPERIODE4_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE4_CHECK)->ShowWindow(SW_SHOW);
	}
	else
	{
		GetDlgItem(IDC_ROPERIODE4_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ROPERIODE4_CHECK)->ShowWindow(SW_HIDE);
	}
		
	if (m_startdates[4] != "")
	{
		GetDlgItem(IDC_ROPERIODE5_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE5_CHECK)->ShowWindow(SW_SHOW);
	}
	else
	{
		GetDlgItem(IDC_ROPERIODE5_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ROPERIODE5_CHECK)->ShowWindow(SW_HIDE);
	}

	if (m_startdates[5] != "")
	{
		GetDlgItem(IDC_ROPERIODE6_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE6_CHECK)->ShowWindow(SW_SHOW);
	}
	else
	{
		GetDlgItem(IDC_ROPERIODE6_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ROPERIODE6_CHECK)->ShowWindow(SW_HIDE);
	}
		
	if (m_startdates[6] != "")
	{
		GetDlgItem(IDC_ROPERIODE7_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE7_CHECK)->ShowWindow(SW_SHOW);
	}
	else
	{
		GetDlgItem(IDC_ROPERIODE7_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ROPERIODE7_CHECK)->ShowWindow(SW_HIDE);
	}
		
	if (m_startdates[7] != "")
	{
		GetDlgItem(IDC_ROPERIODE8_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE8_CHECK)->ShowWindow(SW_SHOW);
	}
	else
	{
		GetDlgItem(IDC_ROPERIODE8_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ROPERIODE8_CHECK)->ShowWindow(SW_HIDE);
	}

	if (m_startdates[8] != "")
	{
		GetDlgItem(IDC_ROPERIODE9_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE9_CHECK)->ShowWindow(SW_SHOW);
	}
	else
	{
		GetDlgItem(IDC_ROPERIODE9_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ROPERIODE9_CHECK)->ShowWindow(SW_HIDE);
	}
		
	if (m_startdates[9] != "")
	{
		GetDlgItem(IDC_ROPERIODE10_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE10_CHECK)->ShowWindow(SW_SHOW);
	}
	else
	{
		GetDlgItem(IDC_ROPERIODE10_BUTTON)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ROPERIODE10_CHECK)->ShowWindow(SW_HIDE);
	}
	UpdateData(FALSE);
}

void CBookingsView::f_tab3()
{
	GetDlgItem(IDC_ALGDEPARTDATE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGARRIVALDATE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGHOTELCODE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGHOTEL_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGHOTELNAAM_TEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGNIGHTS_TEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGPASSENGER_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGBOOKEDBY_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGCONFIRMEDBY_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGARRIVALDAY_TEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGDEPARTDAY_TEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGDEPARTDATE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGARRIVALDATE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGHOTEL_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGHOTELNAAM_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGNIGHTS_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGPASSENGER_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGBOOKEDBY_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGCONFIRMED_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGDAG1_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGDAG2_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGREFERENCE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENTCODE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENT_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENTNAAM_TEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGREFERENCE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENT_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGNAAM2_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE1_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE2_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE3_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE4_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE5_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE6_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE7_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE8_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE9_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE10_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROBUTTONNR_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE0_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE1_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE2_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE3_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE4_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE5_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE6_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE7_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE8_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE9_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE10_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE1_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE2_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE3_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE4_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE5_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE6_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE7_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE8_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE9_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE10_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROINPUT_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROADOUBLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROAQUADS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROASINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROATRIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROATWINS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCTWINS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCDOUBLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCQUADS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCSINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCTRIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROAMULTIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCMULTIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROMULTIPLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROBB_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_RORO_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROHB_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROLATE_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROEARLY_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_RONORMAL_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_RODOUBLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROQUADS_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROSINGLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROTRIPLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROTWINS_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROHEAD_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROA_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROC_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROARRIVAL_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROSERVICE_STATIC)->ShowWindow(SW_HIDE);

	if (m_prcancellation)
		GetDlgItem(IDC_PRCANCELLATION_CHECK)->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_PRDOCKET_CHECK)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PRRECONFIRMATION_CHECK)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PRVOUCHER_CHECK)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PRMAGENT_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PRMHOTEL_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PRMAGENT_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PRMHOTEL_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_REMARKS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_REMTRANSFER_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_REMEXCURSION_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_REMCARRENTAL_CHECK)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_ALGPAX_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGPAX_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROEDOUBLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROEQUADS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROESINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROETWINS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROETWINSINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROETRIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROEMULTIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROATWINSINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCTWINSINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROTWINSINGLES_STATIC)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_ALGHOTEL_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENT_BUTTON)->ShowWindow(SW_HIDE);
}

void CBookingsView::f_tab4()
{
	GetDlgItem(IDC_ALGDEPARTDATE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGARRIVALDATE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGHOTELCODE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGHOTEL_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGHOTELNAAM_TEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGNIGHTS_TEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGPASSENGER_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGBOOKEDBY_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGCONFIRMEDBY_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGARRIVALDAY_TEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGDEPARTDAY_TEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGDEPARTDATE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGARRIVALDATE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGHOTEL_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGHOTELNAAM_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGNIGHTS_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGPASSENGER_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGBOOKEDBY_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGCONFIRMED_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGDAG1_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGDAG2_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGREFERENCE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENTCODE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENT_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENTNAAM_TEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGREFERENCE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENT_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGNAAM2_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE1_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE2_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE3_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE4_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE5_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE6_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE7_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE8_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE9_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE10_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROBUTTONNR_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE0_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE1_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE2_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE3_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE4_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE5_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE6_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE7_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE8_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE9_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE10_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE1_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE2_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE3_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE4_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE5_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE6_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE7_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE8_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE9_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROPERIODE10_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROINPUT_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROADOUBLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROAQUADS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROASINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROATRIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROATWINS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCTWINS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCDOUBLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCQUADS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCSINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCTRIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROAMULTIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCMULTIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROMULTIPLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROBB_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_RORO_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROHB_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROLATE_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROEARLY_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_RONORMAL_RADIO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_RODOUBLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROQUADS_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROSINGLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROTRIPLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROTWINS_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROHEAD_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROA_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROC_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROARRIVAL_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROSERVICE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRCANCELLATION_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRDOCKET_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRRECONFIRMATION_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRVOUCHER_CHECK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRMAGENT_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRMHOTEL_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRMAGENT_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PRMHOTEL_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_REMARKS_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_REMTRANSFER_CHECK)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_REMEXCURSION_CHECK)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_REMCARRENTAL_CHECK)->ShowWindow(SW_SHOW);

	GetDlgItem(IDC_ALGPAX_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ALGPAX_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROEDOUBLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROEQUADS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROESINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROETWINS_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROETWINSINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROETRIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROEMULTIPLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROATWINSINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROCTWINSINGLES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ROTWINSINGLES_STATIC)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_ALGHOTEL_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AGAGENT_BUTTON)->ShowWindow(SW_HIDE);
}

void CBookingsView::OnAlghotelButton() 
{
	// TODO: Add your control notification handler code here
	CZkhotelDlg dlg;
	dlg.DoModal();
	if (dlg.m_code != "")
	{
		UpdateData(TRUE);
		m_alghotelcode = dlg.m_code;
		m_alghotelnaam = dlg.m_name; // + " te " + dlg.m_city;
		UpdateData(FALSE);
	}
}

void CBookingsView::OnAgagentButton() 
{
	// TODO: Add your control notification handler code here
	CZkagentDlg dlg;
	dlg.DoModal();
	if (dlg.m_code != "")
	{
		UpdateData(TRUE);
		m_agagentcode = dlg.m_code;
		m_agagentname = dlg.m_name; // + " te " + dlg.m_city;
		UpdateData(FALSE);
	}
}

void CBookingsView::OnTourrefButton() 
{
	// TODO: Add your control notification handler code here
	CZkbookingDlg dlg;
	dlg.m_fit = FALSE;
	dlg.DoModal();
	if (dlg.m_tourref != "")
	{
		m_tourref = dlg.m_tourref;
		UpdateData(FALSE);
		OnKillfocusTourrefEdit();
	}
}

void CBookingsView::OnKillfocusAlgarrivaldateEdit() 
{
	// TODO: Add your control notification handler code here
	COleDateTimeSpan verschil;
	int aantalnachten;
	COleDateTime m_arrival, m_depart;
	CString aankomstdatum;
	CDatecnv m_datecnv;

	UpdateData(TRUE);

	if (m_algarrivaldate != "")
	{
		if (m_algarrivaldate.GetLength() == 6)
			m_algarrivaldate = m_datecnv.Datecontrole(m_algarrivaldate); //aankomstdatum;

		m_arrival.ParseDateTime(m_algarrivaldate, VAR_DATEVALUEONLY);
		m_depart.ParseDateTime(m_algdepartdate, VAR_DATEVALUEONLY);
		if (m_arrival.m_dt == 0)
		{
			m_algarrivalday = "";
			m_nights        = 0;
			m_algnights     = "";
			MessageBox("The arrivaldate isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
//			GetDlgItem(IDC_ALGARRIVALDATE_EDIT)->SetFocus();
		}
		else
		{
			m_algarrivalday    = m_arrival.Format("%A");

			if (m_depart.m_dt != 0 && m_algdepartdate != "")
			{
				verschil = m_depart - m_arrival;
				aantalnachten = (int) verschil.GetTotalDays();
				m_nights = aantalnachten;
				m_algnights = MaakStr(aantalnachten);
				if (aantalnachten <= 0)
					MessageBox("The arrivaldate is before today !\n",
						"Update data", MB_OK + MB_ICONSTOP);
			}
		}
	}
	else
	{
		m_algarrivalday = "";
		m_nights        = 0;
		m_algnights     = "";
	}
	UpdateData(FALSE);
}

void CBookingsView::OnKillfocusAlgdepartdateEdit() 
{
	// TODO: Add your control notification handler code here
	COleDateTimeSpan verschil;
	int aantalnachten;
	COleDateTime m_arrival, m_depart;
	CString vertrekdatum;
	CDatecnv m_datecnv;

	UpdateData(TRUE);

	if (m_algdepartdate != "")
	{
		if (m_algdepartdate.GetLength() == 6)
			m_algdepartdate = m_datecnv.Datecontrole(m_algdepartdate); //vertrekdatum;

		m_depart.ParseDateTime(m_algdepartdate, VAR_DATEVALUEONLY);
		m_arrival.ParseDateTime(m_algarrivaldate, VAR_DATEVALUEONLY);
		if (m_depart.m_dt == 0)
		{
			m_algdepartday = "";
			m_nights        = 0;
			m_algnights     = "";
			MessageBox("The departdate isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			GetDlgItem(IDC_ALGDEPARTDATE_EDIT)->SetFocus();
		}
		else
		{
			m_algdepartday    = m_depart.Format("%A");

			if (m_arrival.m_dt != 0 && m_algarrivaldate != "")
			{
				verschil = m_depart - m_arrival;
				aantalnachten = (int) verschil.GetTotalDays();
				m_nights = aantalnachten;
				m_algnights = MaakStr(aantalnachten);
				if (aantalnachten <= 0)
					MessageBox("The departdate is before arrivaldate !\n",
						"Update data", MB_OK + MB_ICONSTOP);
			}
		}
	}
	else
	{
		m_algdepartday = "";
		m_nights        = 0;
		m_algnights     = "";

		if (m_algarrivaldate == "")
			GetDlgItem(IDC_ALGARRIVALDATE_EDIT)->SetFocus();
		else if (m_algdepartdate == "")
			GetDlgItem(IDC_ALGDEPARTDATE_EDIT)->SetFocus();
	}
	UpdateData(FALSE);
}

void CBookingsView::OnKillfocusAlghotelcodeEdit() 
{
	// TODO: Add your control notification handler code here
	CHotels m_sethotels;
	CString m_zoekwaarde;

	UpdateData(TRUE);
	if (m_alghotelcode != "")
	{
		m_zoekwaarde = "ho_code = '" + m_alghotelcode + "'";
		m_sethotels.m_strFilter = m_zoekwaarde;
		m_sethotels.Open();
		if (!m_sethotels.IsEOF())
			m_alghotelnaam = m_sethotels.m_ho_name;
		else
		{
			MessageBox("This hotelcode doesn't exist !",
			"Searching hotelname", MB_OK + MB_ICONSTOP);
			m_alghotelcode = "";
			m_alghotelnaam = "";
			GetDlgItem(IDC_ALGHOTELCODE_EDIT)->SetFocus();
		}
	}
	else
		m_alghotelnaam = "";

	UpdateData(FALSE);
}

void CBookingsView::OnKillfocusAgagentcodeEdit() 
{
	// TODO: Add your control notification handler code here
	CAgents m_setagents;
	CString m_zoekwaarde;

	UpdateData(TRUE);

	if (m_agagentcode != "")
	{
		m_zoekwaarde = "ag_code = '" + m_agagentcode + "'";
		m_setagents.m_strFilter = m_zoekwaarde;
		m_setagents.Open();
		if (!m_setagents.IsEOF())
			m_agagentname = m_setagents.m_ag_name;
		else
		{
			MessageBox("This agentcode doesn't exist !\n",
			"Searching agentname", MB_OK + MB_ICONSTOP);
			m_agagentcode = "";
			m_agagentname = "";
			GetDlgItem(IDC_AGAGENTCODE_EDIT)->SetFocus();
		}
	}
	else
		m_agagentname = "";

	UpdateData(FALSE);
}

BOOL CBookingsView::AllocateRooms() 
{
	CAllotment m_setallotment;
	CString    m_begin, m_einde;
	CString    m_zoekwaarde;
	int allotment;
	int extra;
	CString datum;
	COleDateTime datum2;
	BOOL voldoende;
	CString dag, jaar, maand;
	CString jjjjmmdd;
	int tot_a[10], tot_e[10], tot_c[10];
	int i;
	CDatecnv   m_datecnv;
	COleDateTimeSpan m_release, m_extra_release, verschil;
	COleDateTime m_vandaag;
	CString m_dateformat;

	m_dateformat = theApp.dateformat;
	m_vandaag = COleDateTime::GetCurrentTime();

	COleDateTime m_arrivaldate, m_departdate;

	m_arrivaldate.ParseDateTime(m_algarrivaldate, VAR_DATEVALUEONLY);
	m_departdate.ParseDateTime(m_algdepartdate, VAR_DATEVALUEONLY);

	UpdateData(TRUE);
	for (i = 0; i < 10; i++)
	{
		tot_a[i] = 0;
		tot_e[i] = 0;
		tot_c[i] = 0;
	}
	for (i = 0; i < 10; i++)
	{
		tot_a[i] += m_roasingles[i];
		tot_a[i] += m_roatwinsingles[i];
		tot_a[i] += m_roatwins[i];
		tot_a[i] += m_roadoubles[i];
		tot_a[i] += m_roatriples[i];
		tot_a[i] += m_roaquads[i];
		tot_a[i] += m_roamultiples[i];
		tot_e[i] += m_roesingles[i];
		tot_e[i] += m_roetwinsingles[i];
		tot_e[i] += m_roetwins[i];
		tot_e[i] += m_roedoubles[i];
		tot_e[i] += m_roetriples[i];
		tot_e[i] += m_roequads[i];
		tot_e[i] += m_roemultiples[i];
		tot_c[i] += m_rocsingles[i];
		tot_c[i] += m_roctwinsingles[i];
		tot_c[i] += m_roctwins[i];
		tot_c[i] += m_rocdoubles[i];
		tot_c[i] += m_roctriples[i];
		tot_c[i] += m_rocquads[i];
		tot_c[i] += m_rocmultiples[i];
	}


	m_begin = m_arrivaldate.Format("%Y%m%d");
	m_einde = m_departdate.Format("%Y%m%d");

	voldoende = TRUE;

	m_zoekwaarde = "ho_code = '" + m_alghotelcode + "'" +
		"and yyyymm >= '" + m_begin.Left(6) + "'";
	m_setallotment.m_strFilter = m_zoekwaarde;
	m_setallotment.Open();

	if (!m_setallotment.IsEOF())
	{
		if (m_setallotment.m_yyyymm == m_begin.Left(6))
		{
			dag = m_arrivaldate.Format("%d");
			while (!m_setallotment.IsEOF() && m_setallotment.m_dag < dag)
				m_setallotment.MoveNext();
		}

		jaar   = m_setallotment.m_yyyymm[0];
		jaar  += m_setallotment.m_yyyymm[1];
		jaar  += m_setallotment.m_yyyymm[2];
		jaar  += m_setallotment.m_yyyymm[3];
		maand  = m_setallotment.m_yyyymm[4];
		maand += m_setallotment.m_yyyymm[5];

		datum = jaar + maand + m_setallotment.m_dag;

		for (i = 0; i < 10 && voldoende; i++)
		{
			jjjjmmdd = m_datecnv.Datetojjjjmmdd(m_enddates[i]);
			while (!m_setallotment.IsEOF() && datum <= jjjjmmdd && voldoende)
			{
				allotment = m_setallotment.m_allocation - 
								m_setallotment.m_utilised;
				extra     = m_setallotment.m_extra_allocation - 
								m_setallotment.m_extra_utilised;

				if (m_dateformat == "dd-mm-jjjj")
					datum2.ParseDateTime(m_setallotment.m_dag + "-" + maand + "-" + jaar, VAR_DATEVALUEONLY);
				else
					datum2.ParseDateTime(maand + "-" + m_setallotment.m_dag + "-" + jaar, VAR_DATEVALUEONLY);

				verschil = datum2 - m_vandaag;
				
				m_release.SetDateTimeSpan(m_setallotment.m_release, 0, 0, 0);
				if (verschil < m_release)
					allotment = 0;

				m_extra_release.SetDateTimeSpan(m_setallotment.m_extra_release, 0, 0, 0);
				if (verschil < m_extra_release)
					extra = 0;

				if (allotment < tot_a[i] || extra < tot_e[i])
					voldoende = FALSE;

				m_setallotment.MoveNext();

				jaar   = m_setallotment.m_yyyymm[0];
				jaar  += m_setallotment.m_yyyymm[1];
				jaar  += m_setallotment.m_yyyymm[2];
				jaar  += m_setallotment.m_yyyymm[3];
				maand  = m_setallotment.m_yyyymm[4];
				maand += m_setallotment.m_yyyymm[5];

				datum = jaar + maand + m_setallotment.m_dag;
			}
		}

		if (voldoende)
		{
		m_setallotment.MoveFirst();

		if (m_setallotment.m_yyyymm == m_begin.Left(6))
		{
			dag = m_arrivaldate.Format("%d");
			while (!m_setallotment.IsEOF() && m_setallotment.m_dag < dag)
				m_setallotment.MoveNext();
		}

		jaar   = m_setallotment.m_yyyymm[0];
		jaar  += m_setallotment.m_yyyymm[1];
		jaar  += m_setallotment.m_yyyymm[2];
		jaar  += m_setallotment.m_yyyymm[3];
		maand  = m_setallotment.m_yyyymm[4];
		maand += m_setallotment.m_yyyymm[5];

		datum = jaar + maand + m_setallotment.m_dag;

		for (i = 0; i < 10; i++)
		{
			jjjjmmdd = m_datecnv.Datetojjjjmmdd(m_enddates[i]);
			while (!m_setallotment.IsEOF() && datum <= jjjjmmdd)
			{
				m_setallotment.Edit();
				m_setallotment.m_confirmed         += tot_c[i];
				m_setallotment.m_utilised          += tot_a[i];
				m_setallotment.m_singles           += m_roasingles[i];
				m_setallotment.m_twinsingles       += m_roatwinsingles[i];
				m_setallotment.m_twins             += m_roatwins[i];
				m_setallotment.m_doubles           += m_roadoubles[i];
				m_setallotment.m_triples           += m_roatriples[i];
				m_setallotment.m_quads             += m_roaquads[i];
				m_setallotment.m_multiples         += m_roamultiples[i];
				m_setallotment.m_extra_utilised    += tot_e[i];
				m_setallotment.m_extra_singles     += m_roesingles[i];
				m_setallotment.m_extra_twinsingles += m_roetwinsingles[i];
				m_setallotment.m_extra_twins       += m_roetwins[i];
				m_setallotment.m_extra_doubles     += m_roedoubles[i];
				m_setallotment.m_extra_triples     += m_roetriples[i];
				m_setallotment.m_extra_quads       += m_roequads[i];
				m_setallotment.m_extra_multiples   += m_roemultiples[i];
				m_setallotment.Update();

				m_setallotment.MoveNext();

				jaar   = m_setallotment.m_yyyymm[0];
				jaar  += m_setallotment.m_yyyymm[1];
				jaar  += m_setallotment.m_yyyymm[2];
				jaar  += m_setallotment.m_yyyymm[3];
				maand  = m_setallotment.m_yyyymm[4];
				maand += m_setallotment.m_yyyymm[5];

				datum = jaar + maand + m_setallotment.m_dag;
			}
		}
		}
	}
	m_setallotment.Close();

	if (!voldoende)
		MessageBox("The allotment for this period is not sufficient !\n",
			"Update data", MB_OK + MB_ICONSTOP);

	return voldoende;
}

BOOL CBookingsView::ChangeRooms()
{
	COleDateTime m_old_arrdate, m_old_depdate;
	COleDateTime m_new_arrdate, m_new_depdate;
	COleDateTime m_begin, m_eind;
	CDatecnv     m_datecnv;

	CAllotment m_setallotment;
	CString    m_strbegin;
	CString    m_zoekwaarde;
	int allotment;
	int extra;
	BOOL voldoende;
	CString dag, jaar, maand;
	CString jjjjmmdd;
	int tot_a[300], tot_e[300], tot_c[300];
	COleDateTimeSpan m_release, m_extra_release;
	COleDateTime m_vandaag;
	CString m_dateformat;


	COleDateTime m_dag[300];
	int m_csingles[300][3];
	int m_asingles[300][3];
	int m_esingles[300][3];
	int m_atwinsingles[300][3];
	int m_etwinsingles[300][3];
	int m_ctwinsingles[300][3];
	int m_atwins[300][3];
	int m_etwins[300][3];
	int m_ctwins[300][3];
	int m_adoubles[300][3];
	int m_edoubles[300][3];
	int m_cdoubles[300][3];
	int m_atriples[300][3];
	int m_etriples[300][3];
	int m_ctriples[300][3];
	int m_aquads[300][3];
	int m_equads[300][3];
	int m_cquads[300][3];
	int m_amultiples[300][3];
	int m_emultiples[300][3];
	int m_cmultiples[300][3];
	int aantal;

	COleDateTimeSpan verschil;
	COleDateTime datum;
	int teller, i;

	m_old_arrdate.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate), VAR_DATEVALUEONLY);
	m_old_depdate.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_depdate), VAR_DATEVALUEONLY);

	m_new_arrdate.ParseDateTime(m_algarrivaldate, VAR_DATEVALUEONLY);
	m_new_depdate.ParseDateTime(m_algdepartdate, VAR_DATEVALUEONLY);

	if (m_new_arrdate > m_old_depdate || m_new_depdate < m_old_arrdate ||
		m_alghotelcode != m_setbooking.m_ho_code)
	{
		DeleteRooms();
		if (!AllocateRooms())
			return FALSE;
		return TRUE;
	}

	if (m_new_arrdate < m_old_arrdate)
		m_begin = m_new_arrdate;
	else
		m_begin = m_old_arrdate;

	if (m_new_depdate > m_old_depdate)
		m_eind = m_new_depdate;
	else
		m_eind = m_old_depdate;

	teller = 0;
	datum = m_begin;
	while (datum <= m_eind)
	{
		m_dag[teller] = datum;

		verschil.SetDateTimeSpan(1, 0, 0, 0);
		datum = datum + verschil;
		teller++;
	}
	aantal = teller - 1;


	for (i = 0; i < 300; i++)
	{
		for (teller = 0; teller < 3; teller++)
		{
			m_csingles[i][teller] = 0;
			m_asingles[i][teller] = 0;
			m_esingles[i][teller] = 0;
			m_atwinsingles[i][teller] = 0;
			m_etwinsingles[i][teller] = 0;
			m_ctwinsingles[i][teller] = 0;
			m_atwins[i][teller] = 0;
			m_etwins[i][teller] = 0;
			m_ctwins[i][teller] = 0;
			m_adoubles[i][teller] = 0;
			m_edoubles[i][teller] = 0;
			m_cdoubles[i][teller] = 0;
			m_atriples[i][teller] = 0;
			m_etriples[i][teller] = 0;
			m_ctriples[i][teller] = 0;
			m_aquads[i][teller] = 0;
			m_equads[i][teller] = 0;
			m_cquads[i][teller] = 0;
			m_amultiples[i][teller] = 0;
			m_emultiples[i][teller] = 0;
			m_cmultiples[i][teller] = 0;
		}
	}

	datum = m_new_arrdate;
	teller = 0;
	while (m_dag[teller] < datum)
		teller++;

	for (i = 0; i < 10; i++)
	{
		if (m_enddates[i] != "")
			datum.ParseDateTime(m_enddates[i], VAR_DATEVALUEONLY);
		while (teller <= aantal && m_dag[teller] <= datum)
		{
			m_csingles[teller][0] = m_rocsingles[i];
			m_asingles[teller][0] = m_roasingles[i];
			m_esingles[teller][0] = m_roesingles[i];
			m_atwinsingles[teller][0] = m_roatwinsingles[i];
			m_etwinsingles[teller][0] = m_roetwinsingles[i];
			m_ctwinsingles[teller][0] = m_roctwinsingles[i];
			m_atwins[teller][0] = m_roatwins[i];
			m_etwins[teller][0] = m_roetwins[i];
			m_ctwins[teller][0] = m_roctwins[i];
			m_adoubles[teller][0] = m_roadoubles[i];
			m_edoubles[teller][0] = m_roedoubles[i];
			m_cdoubles[teller][0] = m_rocdoubles[i];
			m_atriples[teller][0] = m_roatriples[i];
			m_etriples[teller][0] = m_roetriples[i];
			m_ctriples[teller][0] = m_roctriples[i];
			m_aquads[teller][0] = m_roaquads[i];
			m_equads[teller][0] = m_roequads[i];
			m_cquads[teller][0] = m_rocquads[i];
			m_amultiples[teller][0] = m_roamultiples[i];
			m_emultiples[teller][0] = m_roemultiples[i];
			m_cmultiples[teller][0] = m_rocmultiples[i];

			teller++;
		}
	}

	datum = m_old_arrdate;
	teller = 0;
	while (m_dag[teller] < datum)
		teller++;

	for (i = 0; i < 10; i++)
	{
		if (m_oldenddates[i] != "")
			datum.ParseDateTime(m_oldenddates[i], VAR_DATEVALUEONLY);
		while (teller <= aantal && m_dag[teller] <= datum)
		{
			m_csingles[teller][1] = m_oldcsingles[i];
			m_asingles[teller][1] = m_oldasingles[i];
			m_esingles[teller][1] = m_oldesingles[i];
			m_atwinsingles[teller][1] = m_oldatwinsingles[i];
			m_etwinsingles[teller][1] = m_oldetwinsingles[i];
			m_ctwinsingles[teller][1] = m_oldctwinsingles[i];
			m_atwins[teller][1] = m_oldatwins[i];
			m_etwins[teller][1] = m_oldetwins[i];
			m_ctwins[teller][1] = m_oldctwins[i];
			m_adoubles[teller][1] = m_oldadoubles[i];
			m_edoubles[teller][1] = m_oldedoubles[i];
			m_cdoubles[teller][1] = m_oldcdoubles[i];
			m_atriples[teller][1] = m_oldatriples[i];
			m_etriples[teller][1] = m_oldetriples[i];
			m_ctriples[teller][1] = m_oldctriples[i];
			m_aquads[teller][1] = m_oldaquads[i];
			m_equads[teller][1] = m_oldequads[i];
			m_cquads[teller][1] = m_oldcquads[i];
			m_amultiples[teller][1] = m_oldamultiples[i];
			m_emultiples[teller][1] = m_oldemultiples[i];
			m_cmultiples[teller][1] = m_oldcmultiples[i];

			teller++;
		}
	}

	teller = 0;
	while (teller <= aantal)
	{
		m_csingles[teller][2] = m_csingles[teller][0] - m_csingles[teller][1];
		m_asingles[teller][2] = m_asingles[teller][0] - m_asingles[teller][1];
		m_esingles[teller][2] = m_esingles[teller][0] - m_esingles[teller][1];
		m_atwinsingles[teller][2] = m_atwinsingles[teller][0] - m_atwinsingles[teller][1];
		m_etwinsingles[teller][2] = m_etwinsingles[teller][0] - m_etwinsingles[teller][1];
		m_ctwinsingles[teller][2] = m_ctwinsingles[teller][0] - m_ctwinsingles[teller][1];
		m_atwins[teller][2] = m_atwins[teller][0] - m_atwins[teller][1];
		m_etwins[teller][2] = m_etwins[teller][0] - m_etwins[teller][1];
		m_ctwins[teller][2] = m_ctwins[teller][0] - m_ctwins[teller][1];
		m_adoubles[teller][2] = m_adoubles[teller][0] - m_adoubles[teller][1];
		m_edoubles[teller][2] = m_edoubles[teller][0] - m_edoubles[teller][1];
		m_cdoubles[teller][2] = m_cdoubles[teller][0] - m_cdoubles[teller][1];
		m_atriples[teller][2] = m_atriples[teller][0] - m_atriples[teller][1];
		m_etriples[teller][2] = m_etriples[teller][0] - m_etriples[teller][1];
		m_ctriples[teller][2] = m_ctriples[teller][0] - m_ctriples[teller][1];
		m_aquads[teller][2] = m_aquads[teller][0] - m_aquads[teller][1];
		m_equads[teller][2] = m_equads[teller][0] - m_equads[teller][1];
		m_cquads[teller][2] = m_cquads[teller][0] - m_cquads[teller][1];
		m_amultiples[teller][2] = m_amultiples[teller][0] - m_amultiples[teller][1];
		m_emultiples[teller][2] = m_emultiples[teller][0] - m_emultiples[teller][1];
		m_cmultiples[teller][2] = m_cmultiples[teller][0] - m_cmultiples[teller][1];

		teller++;
	}


	m_dateformat = theApp.dateformat;
	m_vandaag = COleDateTime::GetCurrentTime();

	for (i = 0; i < aantal; i++)
	{
		tot_a[i] = 0;
		tot_e[i] = 0;
		tot_c[i] = 0;
	}
	for (i = 0; i < aantal; i++)
	{
		tot_a[i] += m_asingles[i][2];
		tot_a[i] += m_atwinsingles[i][2];
		tot_a[i] += m_atwins[i][2];
		tot_a[i] += m_adoubles[i][2];
		tot_a[i] += m_atriples[i][2];
		tot_a[i] += m_aquads[i][2];
		tot_a[i] += m_amultiples[i][2];
		tot_e[i] += m_esingles[i][2];
		tot_e[i] += m_etwinsingles[i][2];
		tot_e[i] += m_etwins[i][2];
		tot_e[i] += m_edoubles[i][2];
		tot_e[i] += m_etriples[i][2];
		tot_e[i] += m_equads[i][2];
		tot_e[i] += m_emultiples[i][2];
		tot_c[i] += m_csingles[i][2];
		tot_c[i] += m_ctwinsingles[i][2];
		tot_c[i] += m_ctwins[i][2];
		tot_c[i] += m_cdoubles[i][2];
		tot_c[i] += m_ctriples[i][2];
		tot_c[i] += m_cquads[i][2];
		tot_c[i] += m_cmultiples[i][2];
	}


	m_strbegin = m_dag[0].Format("%Y%m%d");

	m_zoekwaarde = "ho_code = '" + m_alghotelcode + "'" +
		"and yyyymm >= '" + m_strbegin.Left(6) + "'";
	m_setallotment.m_strFilter = m_zoekwaarde;
	m_setallotment.Open();

	if (!m_setallotment.IsEOF())
	{
		if (m_setallotment.m_yyyymm == m_strbegin.Left(6))
		{
			dag = m_dag[0].Format("%d");
			while (!m_setallotment.IsEOF() && m_setallotment.m_dag < dag)
				m_setallotment.MoveNext();
		}

		for (i = 0; i < aantal && voldoende && !m_setallotment.IsEOF(); i++)
		{
			allotment = m_setallotment.m_allocation - 
							m_setallotment.m_utilised;
			extra     = m_setallotment.m_extra_allocation - 
							m_setallotment.m_extra_utilised;

			jaar   = m_setallotment.m_yyyymm[0];
			jaar  += m_setallotment.m_yyyymm[1];
			jaar  += m_setallotment.m_yyyymm[2];
			jaar  += m_setallotment.m_yyyymm[3];
			maand  = m_setallotment.m_yyyymm[4];
			maand += m_setallotment.m_yyyymm[5];

			if (m_dateformat == "dd-mm-jjjj")
				datum.ParseDateTime(m_setallotment.m_dag + "-" + maand + "-" + jaar, VAR_DATEVALUEONLY);
			else
				datum.ParseDateTime(maand + "-" + m_setallotment.m_dag + "-" + jaar, VAR_DATEVALUEONLY);

			verschil = datum - m_vandaag;
				
			m_release.SetDateTimeSpan(m_setallotment.m_release, 0, 0, 0);
			if (verschil < m_release)
				allotment = 0;

			m_extra_release.SetDateTimeSpan(m_setallotment.m_extra_release, 0, 0, 0);
			if (verschil < m_extra_release)
				extra = 0;

			voldoende = TRUE;
			if (allotment < tot_a[i] || extra < tot_e[i])
				voldoende = FALSE;

			m_setallotment.MoveNext();
		}

		if (voldoende)
		{
			m_setallotment.MoveFirst();

			if (m_setallotment.m_yyyymm == m_strbegin.Left(6))
			{
				dag = m_dag[0].Format("%d");
				while (!m_setallotment.IsEOF() && m_setallotment.m_dag < dag)
					m_setallotment.MoveNext();
			}

			for (i = 0; i < aantal && !m_setallotment.IsEOF(); i++)
			{
				m_setallotment.Edit();
				m_setallotment.m_confirmed         += tot_c[i];
				m_setallotment.m_utilised          += tot_a[i];
				m_setallotment.m_singles           += m_asingles[i][2];
				m_setallotment.m_twinsingles       += m_atwinsingles[i][2];
				m_setallotment.m_twins             += m_atwins[i][2];
				m_setallotment.m_doubles           += m_adoubles[i][2];
				m_setallotment.m_triples           += m_atriples[i][2];
				m_setallotment.m_quads             += m_aquads[i][2];
				m_setallotment.m_multiples         += m_amultiples[i][2];
				m_setallotment.m_extra_utilised    += tot_e[i];
				m_setallotment.m_extra_singles     += m_esingles[i][2];
				m_setallotment.m_extra_twinsingles += m_etwinsingles[i][2];
				m_setallotment.m_extra_twins       += m_etwins[i][2];
				m_setallotment.m_extra_doubles     += m_edoubles[i][2];
				m_setallotment.m_extra_triples     += m_etriples[i][2];
				m_setallotment.m_extra_quads       += m_equads[i][2];
				m_setallotment.m_extra_multiples   += m_emultiples[i][2];
				m_setallotment.Update();

				m_setallotment.MoveNext();
			}
		}
	}
	m_setallotment.Close();

	if (!voldoende)
		MessageBox("The allotment for this period is not sufficient !\n",
			"Update data", MB_OK + MB_ICONSTOP);

	return voldoende;
}

void CBookingsView::DeleteRooms() 
{
	COleDateTime m_arrivaldate, m_departdate;
	int tot_a[10], tot_e[10], tot_c[10];
	int i;
	CDatecnv   m_datecnv;
	CAllotment m_setallotment;
	CString    m_begin, m_einde;
	CString    m_zoekwaarde;
//	int allotment;
//	int extra;
	CString datum;
	CString dag, jaar, maand;
	CString jjjjmmdd;

	for (i = 0; i < 10; i++)
	{
		tot_a[i] = 0;
		tot_e[i] = 0;
		tot_c[i] = 0;
	}
	m_setperioden.MoveFirst();

	m_arrivaldate.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_setperioden.m_bo_startdate), VAR_DATEVALUEONLY);
	m_departdate.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_setperioden.m_bo_enddate), VAR_DATEVALUEONLY);

	i = 0;
	while (!m_setperioden.IsEOF())
	{
		tot_a[i] += m_setperioden.m_bo_adbls;
		tot_a[i] += m_setperioden.m_bo_aqds;
		tot_a[i] += m_setperioden.m_bo_asngls;
		tot_a[i] += m_setperioden.m_bo_atrpls;
		tot_a[i] += m_setperioden.m_bo_amltpls;
		tot_a[i] += m_setperioden.m_bo_atwns;
		tot_a[i] += m_setperioden.m_bo_atwnsngls;
		tot_e[i] += m_setperioden.m_bo_edbls;
		tot_e[i] += m_setperioden.m_bo_eqds;
		tot_e[i] += m_setperioden.m_bo_esngls;
		tot_e[i] += m_setperioden.m_bo_etrpls;
		tot_e[i] += m_setperioden.m_bo_emltpls;
		tot_e[i] += m_setperioden.m_bo_etwns;
		tot_e[i] += m_setperioden.m_bo_etwnsngls;
		tot_c[i] += m_setperioden.m_bo_rtwnsngls;
		tot_c[i] += m_setperioden.m_bo_rtwns;
		tot_c[i] += m_setperioden.m_bo_rdbls;
		tot_c[i] += m_setperioden.m_bo_rqds;
		tot_c[i] += m_setperioden.m_bo_rsngls;
		tot_c[i] += m_setperioden.m_bo_rmltpls;
		tot_c[i] += m_setperioden.m_bo_rtrpls;

		i++;
		m_setperioden.MoveNext();
	}
	
	m_begin = m_arrivaldate.Format("%Y%m%d");
	m_einde = m_departdate.Format("%Y%m%d");

	m_zoekwaarde = "ho_code = '" + m_alghotelcode + "'" +
		"and yyyymm >= '" + m_begin.Left(6) + "'";
	m_setallotment.m_strFilter = m_zoekwaarde;
	m_setallotment.Open();

	if (!m_setallotment.IsEOF())
	{
		if (m_setallotment.m_yyyymm == m_begin.Left(6))
		{
			dag = m_arrivaldate.Format("%d");
			while (!m_setallotment.IsEOF() && m_setallotment.m_dag < dag)
				m_setallotment.MoveNext();
		}

		m_setperioden.MoveFirst();
		if (!m_setallotment.IsEOF())
		{
			jaar   = m_setallotment.m_yyyymm[0];
			jaar  += m_setallotment.m_yyyymm[1];
			jaar  += m_setallotment.m_yyyymm[2];
			jaar  += m_setallotment.m_yyyymm[3];
			maand  = m_setallotment.m_yyyymm[4];
			maand += m_setallotment.m_yyyymm[5];

			datum = jaar + maand + m_setallotment.m_dag;
		}
		for (i = 0; i < 10; i++)
		{
			jjjjmmdd = m_setperioden.m_bo_enddate;
		while (!m_setallotment.IsEOF() && datum <= jjjjmmdd)
		{
			m_setallotment.Edit();
			m_setallotment.m_confirmed         -= tot_c[i];
			m_setallotment.m_utilised          -= tot_a[i];
			m_setallotment.m_singles           -= m_setperioden.m_bo_asngls;
			m_setallotment.m_twinsingles       -= m_setperioden.m_bo_atwnsngls;
			m_setallotment.m_twins             -= m_setperioden.m_bo_atwns;
			m_setallotment.m_doubles           -= m_setperioden.m_bo_adbls;
			m_setallotment.m_triples           -= m_setperioden.m_bo_atrpls;
			m_setallotment.m_quads             -= m_setperioden.m_bo_aqds;
			m_setallotment.m_multiples         -= m_setperioden.m_bo_amltpls;
			m_setallotment.m_extra_utilised    -= tot_e[i];
			m_setallotment.m_extra_singles     -= m_setperioden.m_bo_esngls;
			m_setallotment.m_extra_twinsingles -= m_setperioden.m_bo_etwnsngls;
			m_setallotment.m_extra_twins       -= m_setperioden.m_bo_etwns;
			m_setallotment.m_extra_doubles     -= m_setperioden.m_bo_edbls;
			m_setallotment.m_extra_triples     -= m_setperioden.m_bo_etrpls;
			m_setallotment.m_extra_quads       -= m_setperioden.m_bo_eqds;
			m_setallotment.m_extra_multiples   -= m_setperioden.m_bo_emltpls;
			m_setallotment.Update();

			m_setallotment.MoveNext();

			jaar   = m_setallotment.m_yyyymm[0];
			jaar  += m_setallotment.m_yyyymm[1];
			jaar  += m_setallotment.m_yyyymm[2];
			jaar  += m_setallotment.m_yyyymm[3];
			maand  = m_setallotment.m_yyyymm[4];
			maand += m_setallotment.m_yyyymm[5];

			datum = jaar + maand + m_setallotment.m_dag;
		}
		m_setperioden.MoveNext();
		}
	}
	m_setallotment.Close();
}

void CBookingsView::BerekenAvailable()
{
	CDatecnv   m_datecnv;
	CAllotment m_setallotment;
	CString    m_begin, m_einde;
	CString    m_laatstedag;
	CString    m_zoekwaarde;
	COleDateTime m_arrivaldate, m_departdate, datum2;
	COleDateTimeSpan m_release, m_extra_release, verschil;
	int i;
	int allotment;
	int extra;
	CString datum;
	BOOL volgende;
	int aantal, aantal_extra;
	CString dag, jaar, maand;
	CString vorige_dag;

	COleDateTime m_vandaag;
	CString m_dateformat;

	m_dateformat = theApp.dateformat;
	m_vandaag = COleDateTime::GetCurrentTime();

	UpdateData(TRUE);

	m_arrivaldate.ParseDateTime(m_algarrivaldate, VAR_DATEVALUEONLY);
	m_departdate.ParseDateTime(m_algdepartdate, VAR_DATEVALUEONLY);
	verschil.SetDateTimeSpan(1, 0, 0, 0);
	datum2 = m_departdate - verschil;

	if (m_dateformat == "dd-mm-jjjj")
		m_laatstedag = datum2.Format("%d-%m-%Y");
	else
		m_laatstedag = datum2.Format("%m-%d-%Y");

	m_begin = m_arrivaldate.Format("%Y%m%d");
	m_einde = datum2.Format("%Y%m%d");

	for (i = 0; i < 100; i++)
	{
		m_allotment[i]  = 0;
		m_extra[i]      = 0;
		m_startdates[i] = "";
		m_enddates[i]   = "";
	}

	m_startdates[0] = m_algarrivaldate;
	m_enddates[0]   = m_laatstedag;

	if (m_algarrivaldate != "" && m_laatstedag != ""
		&& m_alghotelcode != "")
	{
		m_zoekwaarde = "ho_code = '" + m_alghotelcode + "'" +
			"and yyyymm >= '" + m_begin.Left(6) + "'";
		m_setallotment.m_strFilter = m_zoekwaarde;
		m_setallotment.Open();

		if (!m_setallotment.IsEOF())
		{
			jaar   = m_setallotment.m_yyyymm[0];
			jaar  += m_setallotment.m_yyyymm[1];
			jaar  += m_setallotment.m_yyyymm[2];
			jaar  += m_setallotment.m_yyyymm[3];
			maand  = m_setallotment.m_yyyymm[4];
			maand += m_setallotment.m_yyyymm[5];

			datum = jaar + maand + m_setallotment.m_dag;
		}

		if (!m_setallotment.IsEOF() && datum <= m_einde)
		{
			i = 0;
			if (m_setallotment.m_yyyymm == m_begin.Left(6))
			{
				dag = m_arrivaldate.Format("%d");
				while (!m_setallotment.IsEOF() && m_setallotment.m_dag < dag)
					m_setallotment.MoveNext();
			}
			else if (m_setallotment.m_yyyymm > m_begin.Left(6))
			{
				jaar   = m_setallotment.m_yyyymm[0];
				jaar  += m_setallotment.m_yyyymm[1];
				jaar  += m_setallotment.m_yyyymm[2];
				jaar  += m_setallotment.m_yyyymm[3];
				maand  = m_setallotment.m_yyyymm[4];
				maand += m_setallotment.m_yyyymm[5];

				if (m_dateformat == "dd-mm-jjjj")
					datum = m_setallotment.m_dag + "-" + maand + "-" + jaar;
				else
					datum = maand + "-" + m_setallotment.m_dag + "-" + jaar;

				datum2.ParseDateTime(datum, VAR_DATEVALUEONLY);
				verschil.SetDateTimeSpan(1, 0, 0, 0);
				datum2 = datum2 - verschil;

				if (m_dateformat == "dd-mm-jjjj")
					m_enddates[0] = datum2.Format("%d-%m-%Y");
				else
					m_enddates[0] = datum2.Format("%m-%d-%Y");

				i++;
			}

			jaar   = m_setallotment.m_yyyymm[0];
			jaar  += m_setallotment.m_yyyymm[1];
			jaar  += m_setallotment.m_yyyymm[2];
			jaar  += m_setallotment.m_yyyymm[3];
			maand  = m_setallotment.m_yyyymm[4];
			maand += m_setallotment.m_yyyymm[5];

			datum = jaar + maand + m_setallotment.m_dag;

			while (!m_setallotment.IsEOF() && datum <= m_einde)
			{
				jaar   = m_setallotment.m_yyyymm[0];
				jaar  += m_setallotment.m_yyyymm[1];
				jaar  += m_setallotment.m_yyyymm[2];
				jaar  += m_setallotment.m_yyyymm[3];
				maand  = m_setallotment.m_yyyymm[4];
				maand += m_setallotment.m_yyyymm[5];

				if (m_dateformat == "dd-mm-jjjj")
					m_startdates[i] = m_setallotment.m_dag + "-" + maand + "-" + jaar;
				else
					m_startdates[i] = maand + "-" + m_setallotment.m_dag + "-" + jaar;

				allotment = m_setallotment.m_allocation - 
								m_setallotment.m_utilised;
				extra     = m_setallotment.m_extra_allocation - 
								m_setallotment.m_extra_utilised;

				if (m_dateformat == "dd-mm-jjjj")
					datum2.ParseDateTime(m_setallotment.m_dag + "-" + maand + "-" + jaar, VAR_DATEVALUEONLY);
				else
					datum2.ParseDateTime(maand + "-" + m_setallotment.m_dag + "-" + jaar, VAR_DATEVALUEONLY);

				verschil = datum2 - m_vandaag;
				
				m_release.SetDateTimeSpan(m_setallotment.m_release, 0, 0, 0);
				if (verschil < m_release)
					allotment = 0;

				m_extra_release.SetDateTimeSpan(m_setallotment.m_extra_release, 0, 0, 0);
				if (verschil < m_extra_release)
					extra = 0;

				volgende = FALSE;
				while (!m_setallotment.IsEOF() && datum <= m_einde && !volgende)
				{
					aantal       = m_setallotment.m_allocation - 
										m_setallotment.m_utilised;
					aantal_extra = m_setallotment.m_extra_allocation - 
										m_setallotment.m_extra_utilised;

					if (m_dateformat == "dd-mm-jjjj")
						datum2.ParseDateTime(m_setallotment.m_dag + "-" + maand + "-" + jaar, VAR_DATEVALUEONLY);
					else
						datum2.ParseDateTime(maand + "-" + m_setallotment.m_dag + "-" + jaar, VAR_DATEVALUEONLY);

					verschil = datum2 - m_vandaag;

					m_release.SetDateTimeSpan(m_setallotment.m_release, 0, 0, 0);
					if (verschil < m_release)
						aantal = 0;

					m_extra_release.SetDateTimeSpan(m_setallotment.m_extra_release, 0, 0, 0);
					if (verschil < m_extra_release)
						aantal_extra = 0;

					if (allotment != aantal || extra != aantal_extra)
					{
						m_enddates[i]  = vorige_dag;
						m_allotment[i] = allotment;
						m_extra[i++]   = extra;
						allotment = aantal;
						extra     = aantal_extra;
						volgende = TRUE;
					}

					jaar   = m_setallotment.m_yyyymm[0];
					jaar  += m_setallotment.m_yyyymm[1];
					jaar  += m_setallotment.m_yyyymm[2];
					jaar  += m_setallotment.m_yyyymm[3];
					maand  = m_setallotment.m_yyyymm[4];
					maand += m_setallotment.m_yyyymm[5];

					if (m_dateformat == "dd-mm-jjjj")
						vorige_dag = m_setallotment.m_dag + "-" + maand + "-" + jaar;
					else
						vorige_dag = maand + "-" + m_setallotment.m_dag + "-" + jaar;

					m_setallotment.MoveNext();

					jaar   = m_setallotment.m_yyyymm[0];
					jaar  += m_setallotment.m_yyyymm[1];
					jaar  += m_setallotment.m_yyyymm[2];
					jaar  += m_setallotment.m_yyyymm[3];
					maand  = m_setallotment.m_yyyymm[4];
					maand += m_setallotment.m_yyyymm[5];

					datum = jaar + maand + m_setallotment.m_dag;
				}
				if (!m_setallotment.IsEOF())
					m_setallotment.MovePrev();
			}

			m_allotment[i] = allotment;
			m_extra[i]     = extra;
	
			if (datum < m_einde)
			{
				m_enddates[i] = vorige_dag;
				i++;

				jaar   = m_setallotment.m_yyyymm[0];
				jaar  += m_setallotment.m_yyyymm[1];
				jaar  += m_setallotment.m_yyyymm[2];
				jaar  += m_setallotment.m_yyyymm[3];
				maand  = m_setallotment.m_yyyymm[4];
				maand += m_setallotment.m_yyyymm[5];

				if (m_dateformat == "dd-mm-jjjj")
					datum = m_setallotment.m_dag + "-" + maand + "-" + jaar;
				else
					datum = maand + "-" + m_setallotment.m_dag + "-" + jaar;

				datum2.ParseDateTime(datum, VAR_DATEVALUEONLY);
				verschil.SetDateTimeSpan(1, 0, 0, 0);
				datum2 = datum2 + verschil;

				if (m_dateformat == "dd-mm-jjjj")
					m_startdates[i] = datum2.Format("%d-%m-%Y");
				else
					m_startdates[i] = datum2.Format("%m-%d-%Y");

				m_enddates[i] = m_laatstedag;
			}
			else
			{
				m_enddates[i] = m_laatstedag;
				if (m_startdates[i] == "")
					m_startdates[i] = m_laatstedag;
			}
			m_setallotment.Close();
		}
	}

	if (i > 9)
	{
		m_enddates[9] = m_laatstedag;
		BerekenMax();
	}

	CStatic *periode1 = (CStatic *) GetDlgItem(IDC_ROPERIODE1_STATIC);
	CStatic *periode2 = (CStatic *) GetDlgItem(IDC_ROPERIODE2_STATIC);
	CStatic *periode3 = (CStatic *) GetDlgItem(IDC_ROPERIODE3_STATIC);
	CStatic *periode4 = (CStatic *) GetDlgItem(IDC_ROPERIODE4_STATIC);
	CStatic *periode5 = (CStatic *) GetDlgItem(IDC_ROPERIODE5_STATIC);
	CStatic *periode6 = (CStatic *) GetDlgItem(IDC_ROPERIODE6_STATIC);
	CStatic *periode7 = (CStatic *) GetDlgItem(IDC_ROPERIODE7_STATIC);
	CStatic *periode8 = (CStatic *) GetDlgItem(IDC_ROPERIODE8_STATIC);
	CStatic *periode9 = (CStatic *) GetDlgItem(IDC_ROPERIODE9_STATIC);
	CStatic *periode10 = (CStatic *) GetDlgItem(IDC_ROPERIODE10_STATIC);

	CString text1, text2, text3, text4, text5;
	CString text6, text7, text8, text9, text10;

	m_robuttonnr = "";

	text1 = "Van   " + m_startdates[0] + "   t/m   " + m_enddates[0] + "    " + 
				MaakStr2(m_allotment[0]) + "   " + MaakStr2(m_extra[0]);
	m_periodes = 1;

	if (m_startdates[1] != "")
	{
		m_robuttonnr = "1";
		text2 = "Van   " + m_startdates[1] + "   t/m   " + m_enddates[1] + "    " + 
					MaakStr2(m_allotment[1]) + "   " + MaakStr2(m_extra[1]);
		GetDlgItem(IDC_ROPERIODE0_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE1_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE2_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE1_CHECK)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE2_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 2;
	}
	if (m_startdates[2] != "")
	{
		text3 = "Van   " + m_startdates[2] + "   t/m   " + m_enddates[2] + "    " + 
					MaakStr2(m_allotment[2]) + "   " + MaakStr2(m_extra[2]);
		GetDlgItem(IDC_ROPERIODE3_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE3_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 3;
	}
	if (m_startdates[3] != "")
	{
		text4 = "Van   " + m_startdates[3] + "   t/m   " + m_enddates[3] + "    " + 
					MaakStr2(m_allotment[3]) + "   " + MaakStr2(m_extra[3]);
		GetDlgItem(IDC_ROPERIODE4_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE4_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 4;
	}
	if (m_startdates[4] != "")
	{
		text5 = "Van   " + m_startdates[4] + "   t/m   " + m_enddates[4] + "    " + 
					MaakStr2(m_allotment[4]) + "   " + MaakStr2(m_extra[4]);
		GetDlgItem(IDC_ROPERIODE5_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE5_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 5;
	}
	if (m_startdates[5] != "")
	{
		text6 = "Van   " + m_startdates[5] + "   t/m   " + m_enddates[5] + "    " + 
					MaakStr2(m_allotment[5]) + "   " + MaakStr2(m_extra[5]);
		GetDlgItem(IDC_ROPERIODE6_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE6_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 6;
	}
	if (m_startdates[6] != "")
	{
		text7 = "Van   " + m_startdates[6] + "   t/m   " + m_enddates[6] + "    " + 
					MaakStr2(m_allotment[6]) + "   " + MaakStr2(m_extra[6]);
		GetDlgItem(IDC_ROPERIODE7_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE7_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 7;
	}
	if (m_startdates[7] != "")
	{
		text8 = "Van   " + m_startdates[7] + "   t/m   " + m_enddates[7] + "    " + 
					MaakStr2(m_allotment[7]) + "   " + MaakStr2(m_extra[7]);
		GetDlgItem(IDC_ROPERIODE8_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE8_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 8;
	}
	if (m_startdates[8] != "")
	{
		text9 = "Van   " + m_startdates[8] + "   t/m   " + m_enddates[8] + "    " + 
					MaakStr2(m_allotment[8]) + "   " + MaakStr2(m_extra[8]);
		GetDlgItem(IDC_ROPERIODE9_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE9_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 9;
	}
	if (m_startdates[9] != "")
	{
		text10 = "Van   " + m_startdates[9] + "   t/m   " + m_enddates[9] + "    " + 
					MaakStr2(m_allotment[9]) + "   " + MaakStr2(m_extra[9]);
		GetDlgItem(IDC_ROPERIODE10_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE10_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 10;
	}

	periode1->SetWindowText(text1);
	periode2->SetWindowText(text2);
	periode3->SetWindowText(text3);
	periode4->SetWindowText(text4);
	periode5->SetWindowText(text5);
	periode6->SetWindowText(text6);
	periode7->SetWindowText(text7);
	periode8->SetWindowText(text8);
	periode9->SetWindowText(text9);
	periode10->SetWindowText(text10);

	if (m_wijzigen)
		OnRoperiode1Button();
	m_periode = 0;

	UpdateData(FALSE);
}

void CBookingsView::ChangeAvailable()
{
	COleDateTime m_old_arrdate, m_old_depdate;
	COleDateTime m_new_arrdate, m_new_depdate;
//	COleDateTime m_begin, m_eind;
	CDatecnv     m_datecnv;

	CAllotment m_setallotment;
	CString    m_strbegin;
	CString    m_zoekwaarde;
	int allotment;
	int extra;
	CString dag, jaar, maand;
	CString jjjjmmdd;
//	int tot_a[300], tot_e[300], tot_c[300];
	COleDateTimeSpan m_release, m_extra_release;
	COleDateTime m_vandaag;
	CString m_dateformat;


	COleDateTime m_dag[300];
	int m_allotm[300];
	int m_extra_allotm[300];
	int m_oude_periode[300];
	int m_nieuwe_periode[300];
	int oude, nieuwe;
	int aantal;

	COleDateTimeSpan verschil;
	COleDateTime datum;
	int teller, i;

	UpdateData(TRUE);

	m_old_arrdate.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate), VAR_DATEVALUEONLY);
	m_old_depdate.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_depdate), VAR_DATEVALUEONLY);

	m_new_arrdate.ParseDateTime(m_algarrivaldate, VAR_DATEVALUEONLY);
	m_new_depdate.ParseDateTime(m_algdepartdate, VAR_DATEVALUEONLY);

	if (m_new_arrdate > m_old_depdate || m_new_depdate < m_old_arrdate ||
		m_alghotelcode != m_setbooking.m_ho_code)
	{
		BerekenAvailable();
		return;
	}

	teller = 0;
	datum = m_new_arrdate;
	while (datum <= m_new_depdate)
	{
		m_dag[teller] = datum;

		verschil.SetDateTimeSpan(1, 0, 0, 0);
		datum = datum + verschil;
		teller++;
	}
	aantal = teller - 1;

	for (i = 0; i < 300; i++)
	{
		m_allotm[i] = 0;
		m_extra_allotm[i] = 0;
		m_oude_periode[i] = 0;
		m_nieuwe_periode[i] = 0;
	}


	m_dateformat = theApp.dateformat;

	m_strbegin = m_dag[0].Format("%Y%m%d");

	m_zoekwaarde = "ho_code = '" + m_alghotelcode + "'" +
		"and yyyymm >= '" + m_strbegin.Left(6) + "'";
	m_setallotment.m_strFilter = m_zoekwaarde;
	m_setallotment.Open();

	if (!m_setallotment.IsEOF())
	{
		if (m_setallotment.m_yyyymm == m_strbegin.Left(6))
		{
			dag = m_dag[0].Format("%d");
			while (!m_setallotment.IsEOF() && m_setallotment.m_dag < dag)
				m_setallotment.MoveNext();
		}

		for (i = 0; i < aantal && !m_setallotment.IsEOF(); i++)
		{
			allotment = m_setallotment.m_allocation - 
							m_setallotment.m_utilised;
			extra     = m_setallotment.m_extra_allocation - 
							m_setallotment.m_extra_utilised;

			jaar   = m_setallotment.m_yyyymm[0];
			jaar  += m_setallotment.m_yyyymm[1];
			jaar  += m_setallotment.m_yyyymm[2];
			jaar  += m_setallotment.m_yyyymm[3];
			maand  = m_setallotment.m_yyyymm[4];
			maand += m_setallotment.m_yyyymm[5];

			if (m_dateformat == "dd-mm-jjjj")
				datum.ParseDateTime(m_setallotment.m_dag + "-" + maand + "-" + jaar, VAR_DATEVALUEONLY);
			else
				datum.ParseDateTime(maand + "-" + m_setallotment.m_dag + "-" + jaar, VAR_DATEVALUEONLY);

			verschil = datum - m_vandaag;
				
			m_release.SetDateTimeSpan(m_setallotment.m_release, 0, 0, 0);
			if (verschil < m_release)
				allotment = 0;

			m_extra_release.SetDateTimeSpan(m_setallotment.m_extra_release, 0, 0, 0);
			if (verschil < m_extra_release)
				extra = 0;

			m_allotm[i] = allotment;
			m_extra_allotm[i] = extra;

			m_setallotment.MoveNext();
		}

	}
	m_setallotment.Close();
	
	datum = m_old_arrdate;
	teller = 0;
	while (m_dag[teller] < datum)
		teller++;

	for (i = 0; i < 10; i++)
	{
		if (m_oldenddates[i] != "")
			datum.ParseDateTime(m_oldenddates[i], VAR_DATEVALUEONLY);
		while (teller <= aantal && m_dag[teller] <= datum)
		{
			m_oude_periode[teller] = i;
			teller++;
		}
	}
	
	teller = 0;
	i = 0;
	allotment = m_allotm[0];
	extra     = m_extra_allotm[0];
	oude      = m_oude_periode[0];
	while (teller <= aantal)
	{
		if (allotment != m_allotm[teller] || 
					extra != m_extra_allotm[teller] ||
					oude  != m_oude_periode[teller])
		{
			allotment = m_allotm[teller];
			extra     = m_extra_allotm[teller];
			oude      = m_oude_periode[teller];
			i++;
		}
		m_nieuwe_periode[teller] = i;
		teller++;
	}

	for (i = 0; i < 100; i++)
	{
		m_allotment[i]  = 0;
		m_extra[i]      = 0;
		m_startdates[i] = "";
		m_enddates[i]   = "";
	}

	for (i = 0; i < 10; i++)
	{
		m_startdates[i] = "";
		m_enddates[i]   = "";
		m_allotment[i]  = 0;
		m_extra[i]      = 0;
		m_roasingles[i] = 0;
		m_roatwinsingles[i] = 0;
		m_roatwins[i] = 0;
		m_roadoubles[i] = 0;
		m_roatriples[i] = 0;
		m_roaquads[i] = 0;
		m_roamultiples[i] = 0;
		m_roesingles[i] = 0;
		m_roetwinsingles[i] = 0;
		m_roetwins[i]   = 0;
		m_roedoubles[i] = 0;
		m_roetriples[i] = 0;
		m_roequads[i] = 0;
		m_roemultiples[i] = 0;
		m_rocsingles[i] = 0;
		m_roctwinsingles[i] = 0;
		m_roctwins[i]   = 0;
		m_rocdoubles[i] = 0;
		m_roctriples[i] = 0;
		m_rocquads[i] = 0;
		m_rocmultiples[i] = 0;
	}
	
	
	teller = 0;
	m_startdates[0] = m_algarrivaldate;
	nieuwe = 0;
	while (teller <= aantal)
	{
		if (m_nieuwe_periode[teller] != nieuwe)
		{
			oude = m_oude_periode[teller-1];

			m_rocsingles[nieuwe] = m_oldcsingles[oude];
			m_roasingles[nieuwe] = m_oldasingles[oude];
			m_roesingles[nieuwe] = m_oldesingles[oude];
			m_roatwinsingles[nieuwe] = m_oldatwinsingles[oude];
			m_roetwinsingles[nieuwe] = m_oldetwinsingles[oude];
			m_roctwinsingles[nieuwe] = m_oldctwinsingles[oude];
			m_roatwins[nieuwe] = m_oldatwins[oude];
			m_roetwins[nieuwe] = m_oldetwins[oude];
			m_roctwins[nieuwe] = m_oldctwins[oude];
			m_roadoubles[nieuwe] = m_oldadoubles[oude];
			m_roedoubles[nieuwe] = m_oldedoubles[oude];
			m_rocdoubles[nieuwe] = m_oldcdoubles[oude];
			m_roatriples[nieuwe] = m_oldatriples[oude];
			m_roetriples[nieuwe] = m_oldetriples[oude];
			m_roctriples[nieuwe] = m_oldctriples[oude];
			m_roaquads[nieuwe] = m_oldaquads[oude];
			m_roequads[nieuwe] = m_oldequads[oude];
			m_rocquads[nieuwe] = m_oldcquads[oude];
			m_roamultiples[nieuwe] = m_oldamultiples[oude];
			m_roemultiples[nieuwe] = m_oldemultiples[oude];
			m_rocmultiples[nieuwe] = m_oldcmultiples[oude];

			m_enddates[nieuwe] = m_dag[teller-1].Format("%d-%m-%Y");
			nieuwe++;
			m_startdates[nieuwe] = m_dag[teller].Format("%d-%m-%Y");
		}
		teller++;
	}
	m_enddates[nieuwe] = m_dag[teller-1].Format("%d-%m-%Y");

	
	
	
	
/*	
	CDatecnv   m_datecnv;
	CAllotment m_setallotment;
	CString    m_begin, m_einde;
	CString    m_laatstedag;
	CString    m_zoekwaarde;
	COleDateTime m_arrivaldate, m_departdate, datum2;
	COleDateTimeSpan m_release, m_extra_release, verschil;
	int i;
	int allotment;
	int extra;
	CString datum;
	BOOL volgende;
	int aantal, aantal_extra;
	CString dag, jaar, maand;
	CString vorige_dag;

	COleDateTime m_vandaag;
	CString m_dateformat;

	m_dateformat = theApp.dateformat;
	m_vandaag = COleDateTime::GetCurrentTime();

	UpdateData(TRUE);

	m_arrivaldate.ParseDateTime(m_algarrivaldate, VAR_DATEVALUEONLY);
	m_departdate.ParseDateTime(m_algdepartdate, VAR_DATEVALUEONLY);
	verschil.SetDateTimeSpan(1, 0, 0, 0);
	datum2 = m_departdate - verschil;

	if (m_dateformat == "dd-mm-jjjj")
		m_laatstedag = datum2.Format("%d-%m-%Y");
	else
		m_laatstedag = datum2.Format("%m-%d-%Y");

	m_begin = m_arrivaldate.Format("%Y%m%d");
	m_einde = datum2.Format("%Y%m%d");

	for (i = 0; i < 100; i++)
	{
		m_allotment[i]  = 0;
		m_extra[i]      = 0;
		m_startdates[i] = "";
		m_enddates[i]   = "";
	}

	m_startdates[0] = m_algarrivaldate;
	m_enddates[0]   = m_laatstedag;

	if (m_algarrivaldate != "" && m_laatstedag != ""
		&& m_alghotelcode != "")
	{
		m_zoekwaarde = "ho_code = '" + m_alghotelcode + "'" +
			"and yyyymm >= '" + m_begin.Left(6) + "'";
		m_setallotment.m_strFilter = m_zoekwaarde;
		m_setallotment.Open();

		if (!m_setallotment.IsEOF())
		{
			jaar   = m_setallotment.m_yyyymm[0];
			jaar  += m_setallotment.m_yyyymm[1];
			jaar  += m_setallotment.m_yyyymm[2];
			jaar  += m_setallotment.m_yyyymm[3];
			maand  = m_setallotment.m_yyyymm[4];
			maand += m_setallotment.m_yyyymm[5];

			datum = jaar + maand + m_setallotment.m_dag;
		}

		if (!m_setallotment.IsEOF() && datum <= m_einde)
		{
			i = 0;
			if (m_setallotment.m_yyyymm == m_begin.Left(6))
			{
				dag = m_arrivaldate.Format("%d");
				while (!m_setallotment.IsEOF() && m_setallotment.m_dag < dag)
					m_setallotment.MoveNext();
			}
			else if (m_setallotment.m_yyyymm > m_begin.Left(6))
			{
				jaar   = m_setallotment.m_yyyymm[0];
				jaar  += m_setallotment.m_yyyymm[1];
				jaar  += m_setallotment.m_yyyymm[2];
				jaar  += m_setallotment.m_yyyymm[3];
				maand  = m_setallotment.m_yyyymm[4];
				maand += m_setallotment.m_yyyymm[5];

				if (m_dateformat == "dd-mm-jjjj")
					datum = m_setallotment.m_dag + "-" + maand + "-" + jaar;
				else
					datum = maand + "-" + m_setallotment.m_dag + "-" + jaar;

				datum2.ParseDateTime(datum, VAR_DATEVALUEONLY);
				verschil.SetDateTimeSpan(1, 0, 0, 0);
				datum2 = datum2 - verschil;

				if (m_dateformat == "dd-mm-jjjj")
					m_enddates[0] = datum2.Format("%d-%m-%Y");
				else
					m_enddates[0] = datum2.Format("%m-%d-%Y");

				i++;
			}

			jaar   = m_setallotment.m_yyyymm[0];
			jaar  += m_setallotment.m_yyyymm[1];
			jaar  += m_setallotment.m_yyyymm[2];
			jaar  += m_setallotment.m_yyyymm[3];
			maand  = m_setallotment.m_yyyymm[4];
			maand += m_setallotment.m_yyyymm[5];

			datum = jaar + maand + m_setallotment.m_dag;

			while (!m_setallotment.IsEOF() && datum <= m_einde)
			{
				jaar   = m_setallotment.m_yyyymm[0];
				jaar  += m_setallotment.m_yyyymm[1];
				jaar  += m_setallotment.m_yyyymm[2];
				jaar  += m_setallotment.m_yyyymm[3];
				maand  = m_setallotment.m_yyyymm[4];
				maand += m_setallotment.m_yyyymm[5];

				if (m_dateformat == "dd-mm-jjjj")
					m_startdates[i] = m_setallotment.m_dag + "-" + maand + "-" + jaar;
				else
					m_startdates[i] = maand + "-" + m_setallotment.m_dag + "-" + jaar;

				allotment = m_setallotment.m_allocation - 
								m_setallotment.m_utilised;
				extra     = m_setallotment.m_extra_allocation - 
								m_setallotment.m_extra_utilised;

				if (m_dateformat == "dd-mm-jjjj")
					datum2.ParseDateTime(m_setallotment.m_dag + "-" + maand + "-" + jaar, VAR_DATEVALUEONLY);
				else
					datum2.ParseDateTime(maand + "-" + m_setallotment.m_dag + "-" + jaar, VAR_DATEVALUEONLY);

				verschil = datum2 - m_vandaag;
				
				m_release.SetDateTimeSpan(m_setallotment.m_release, 0, 0, 0);
				if (verschil < m_release)
					allotment = 0;

				m_extra_release.SetDateTimeSpan(m_setallotment.m_extra_release, 0, 0, 0);
				if (verschil < m_extra_release)
					extra = 0;

				volgende = FALSE;
				while (!m_setallotment.IsEOF() && datum <= m_einde && !volgende)
				{
					aantal       = m_setallotment.m_allocation - 
										m_setallotment.m_utilised;
					aantal_extra = m_setallotment.m_extra_allocation - 
										m_setallotment.m_extra_utilised;

					if (m_dateformat == "dd-mm-jjjj")
						datum2.ParseDateTime(m_setallotment.m_dag + "-" + maand + "-" + jaar, VAR_DATEVALUEONLY);
					else
						datum2.ParseDateTime(maand + "-" + m_setallotment.m_dag + "-" + jaar, VAR_DATEVALUEONLY);

					verschil = datum2 - m_vandaag;

					m_release.SetDateTimeSpan(m_setallotment.m_release, 0, 0, 0);
					if (verschil < m_release)
						aantal = 0;

					m_extra_release.SetDateTimeSpan(m_setallotment.m_extra_release, 0, 0, 0);
					if (verschil < m_extra_release)
						aantal_extra = 0;

					if (allotment != aantal || extra != aantal_extra)
					{
						m_enddates[i]  = vorige_dag;
						m_allotment[i] = allotment;
						m_extra[i++]   = extra;
						allotment = aantal;
						extra     = aantal_extra;
						volgende = TRUE;
					}

					jaar   = m_setallotment.m_yyyymm[0];
					jaar  += m_setallotment.m_yyyymm[1];
					jaar  += m_setallotment.m_yyyymm[2];
					jaar  += m_setallotment.m_yyyymm[3];
					maand  = m_setallotment.m_yyyymm[4];
					maand += m_setallotment.m_yyyymm[5];

					if (m_dateformat == "dd-mm-jjjj")
						vorige_dag = m_setallotment.m_dag + "-" + maand + "-" + jaar;
					else
						vorige_dag = maand + "-" + m_setallotment.m_dag + "-" + jaar;

					m_setallotment.MoveNext();

					jaar   = m_setallotment.m_yyyymm[0];
					jaar  += m_setallotment.m_yyyymm[1];
					jaar  += m_setallotment.m_yyyymm[2];
					jaar  += m_setallotment.m_yyyymm[3];
					maand  = m_setallotment.m_yyyymm[4];
					maand += m_setallotment.m_yyyymm[5];

					datum = jaar + maand + m_setallotment.m_dag;
				}
				if (!m_setallotment.IsEOF())
					m_setallotment.MovePrev();
			}

			m_allotment[i] = allotment;
			m_extra[i]     = extra;
	
			if (datum < m_einde)
			{
				m_enddates[i] = vorige_dag;
				i++;

				jaar   = m_setallotment.m_yyyymm[0];
				jaar  += m_setallotment.m_yyyymm[1];
				jaar  += m_setallotment.m_yyyymm[2];
				jaar  += m_setallotment.m_yyyymm[3];
				maand  = m_setallotment.m_yyyymm[4];
				maand += m_setallotment.m_yyyymm[5];

				if (m_dateformat == "dd-mm-jjjj")
					datum = m_setallotment.m_dag + "-" + maand + "-" + jaar;
				else
					datum = maand + "-" + m_setallotment.m_dag + "-" + jaar;

				datum2.ParseDateTime(datum, VAR_DATEVALUEONLY);
				verschil.SetDateTimeSpan(1, 0, 0, 0);
				datum2 = datum2 + verschil;

				if (m_dateformat == "dd-mm-jjjj")
					m_startdates[i] = datum2.Format("%d-%m-%Y");
				else
					m_startdates[i] = datum2.Format("%m-%d-%Y");

				m_enddates[i] = m_laatstedag;
			}
			else
			{
				m_enddates[i] = m_laatstedag;
				if (m_startdates[i] == "")
					m_startdates[i] = m_laatstedag;
			}
			m_setallotment.Close();
		}
	}

	if (i > 9)
	{
		m_enddates[9] = m_laatstedag;
		BerekenMax();
	}
*/
	CStatic *periode1 = (CStatic *) GetDlgItem(IDC_ROPERIODE1_STATIC);
	CStatic *periode2 = (CStatic *) GetDlgItem(IDC_ROPERIODE2_STATIC);
	CStatic *periode3 = (CStatic *) GetDlgItem(IDC_ROPERIODE3_STATIC);
	CStatic *periode4 = (CStatic *) GetDlgItem(IDC_ROPERIODE4_STATIC);
	CStatic *periode5 = (CStatic *) GetDlgItem(IDC_ROPERIODE5_STATIC);
	CStatic *periode6 = (CStatic *) GetDlgItem(IDC_ROPERIODE6_STATIC);
	CStatic *periode7 = (CStatic *) GetDlgItem(IDC_ROPERIODE7_STATIC);
	CStatic *periode8 = (CStatic *) GetDlgItem(IDC_ROPERIODE8_STATIC);
	CStatic *periode9 = (CStatic *) GetDlgItem(IDC_ROPERIODE9_STATIC);
	CStatic *periode10 = (CStatic *) GetDlgItem(IDC_ROPERIODE10_STATIC);

	CString text1, text2, text3, text4, text5;
	CString text6, text7, text8, text9, text10;

	m_robuttonnr = "";

	text1 = "Van   " + m_startdates[0] + "   t/m   " + m_enddates[0] + "    " + 
				MaakStr2(m_allotment[0]) + "   " + MaakStr2(m_extra[0]);
	m_periodes = 1;

	if (m_startdates[1] != "")
	{
		m_robuttonnr = "1";
		text2 = "Van   " + m_startdates[1] + "   t/m   " + m_enddates[1] + "    " + 
					MaakStr2(m_allotment[1]) + "   " + MaakStr2(m_extra[1]);
		GetDlgItem(IDC_ROPERIODE0_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE1_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE2_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE1_CHECK)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE2_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 2;
	}
	if (m_startdates[2] != "")
	{
		text3 = "Van   " + m_startdates[2] + "   t/m   " + m_enddates[2] + "    " + 
					MaakStr2(m_allotment[2]) + "   " + MaakStr2(m_extra[2]);
		GetDlgItem(IDC_ROPERIODE3_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE3_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 3;
	}
	if (m_startdates[3] != "")
	{
		text4 = "Van   " + m_startdates[3] + "   t/m   " + m_enddates[3] + "    " + 
					MaakStr2(m_allotment[3]) + "   " + MaakStr2(m_extra[3]);
		GetDlgItem(IDC_ROPERIODE4_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE4_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 4;
	}
	if (m_startdates[4] != "")
	{
		text5 = "Van   " + m_startdates[4] + "   t/m   " + m_enddates[4] + "    " + 
					MaakStr2(m_allotment[4]) + "   " + MaakStr2(m_extra[4]);
		GetDlgItem(IDC_ROPERIODE5_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE5_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 5;
	}
	if (m_startdates[5] != "")
	{
		text6 = "Van   " + m_startdates[5] + "   t/m   " + m_enddates[5] + "    " + 
					MaakStr2(m_allotment[5]) + "   " + MaakStr2(m_extra[5]);
		GetDlgItem(IDC_ROPERIODE6_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE6_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 6;
	}
	if (m_startdates[6] != "")
	{
		text7 = "Van   " + m_startdates[6] + "   t/m   " + m_enddates[6] + "    " + 
					MaakStr2(m_allotment[6]) + "   " + MaakStr2(m_extra[6]);
		GetDlgItem(IDC_ROPERIODE7_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE7_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 7;
	}
	if (m_startdates[7] != "")
	{
		text8 = "Van   " + m_startdates[7] + "   t/m   " + m_enddates[7] + "    " + 
					MaakStr2(m_allotment[7]) + "   " + MaakStr2(m_extra[7]);
		GetDlgItem(IDC_ROPERIODE8_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE8_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 8;
	}
	if (m_startdates[8] != "")
	{
		text9 = "Van   " + m_startdates[8] + "   t/m   " + m_enddates[8] + "    " + 
					MaakStr2(m_allotment[8]) + "   " + MaakStr2(m_extra[8]);
		GetDlgItem(IDC_ROPERIODE9_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE9_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 9;
	}
	if (m_startdates[9] != "")
	{
		text10 = "Van   " + m_startdates[9] + "   t/m   " + m_enddates[9] + "    " + 
					MaakStr2(m_allotment[9]) + "   " + MaakStr2(m_extra[9]);
		GetDlgItem(IDC_ROPERIODE10_BUTTON)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_ROPERIODE10_CHECK)->ShowWindow(SW_SHOW);
		m_periodes = 10;
	}

	periode1->SetWindowText(text1);
	periode2->SetWindowText(text2);
	periode3->SetWindowText(text3);
	periode4->SetWindowText(text4);
	periode5->SetWindowText(text5);
	periode6->SetWindowText(text6);
	periode7->SetWindowText(text7);
	periode8->SetWindowText(text8);
	periode9->SetWindowText(text9);
	periode10->SetWindowText(text10);

	OnRoperiode1Button();
	m_periode = 0;

	UpdateData(FALSE);
}

CString CBookingsView::MaakStr2(int getal)
{
	char getal_char[4];

	itoa(getal, getal_char, 10);

	if (getal < 10)
		return "  " + (CString) getal_char;
	else
		return (CString) getal_char;
}

void CBookingsView::BerekenMax()
{
	int i, max, max_extra;

	max = m_allotment[9];
	max_extra = m_extra[9];
	i = 10;
	while (m_startdates[i] != "")
	{
		if (m_allotment[i] < max)
			max = m_allotment[i];

		if (m_extra[i] < max_extra)
			max_extra = m_extra[i];

		i++;
	}

	m_allotment[9] = max;
	m_extra[9]     = max_extra;
}

BOOL CBookingsView::OnPreparePrinting(CPrintInfo* pInfo) 
{
	// TODO: call DoPreparePrinting to invoke the Print dialog box
//	UpdateData(TRUE);
	m_pages = 0;

	if (m_nieuw)
		m_setbooking.MoveLast();

	if (m_prdocket)
		m_pages++;
	if (m_prvoucher)
	{
		MakeVoucher();
		m_pages++;
	}
	if (m_prreconfirmation)
		m_pages++;
	if (m_prcancellation)
		m_pages++;

	pInfo->SetMaxPage(m_pages);

	if (m_printdirect)
		pInfo->m_bDirect = TRUE;
	
	return DoPreparePrinting(pInfo);
}

void CBookingsView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	m_pages = 0;

	if (m_prdocket)
		m_pages++;
	if (m_prvoucher)
		m_pages++;
	if (m_prreconfirmation)
		m_pages++;
	if (m_prcancellation)
		m_pages++;

	pInfo->SetMaxPage(m_pages);

	if (m_printdirect)
		pInfo->m_bDirect = TRUE;
	
	CFormView::OnBeginPrinting(pDC, pInfo);
}

void CBookingsView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	int paginahoogte = pDC->GetDeviceCaps(VERTRES);
	int begin        = paginahoogte * (pInfo->m_nCurPage - 1);

	pDC->SetViewportOrg(0, -begin);

	CFormView::OnPrint(pDC, pInfo);
}

void CBookingsView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CFormView::OnEndPrinting(pDC, pInfo);
}

void CBookingsView::OnUpdateFilePrint(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if ((m_prdocket || m_prvoucher 
		|| m_prreconfirmation || m_prcancellation) 
		&& !m_nieuw)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CBookingsView::OnUpdateFilePrintDirect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if ((m_prdocket || m_prvoucher 
		|| m_prreconfirmation || m_prcancellation) 
		&& !m_nieuw)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CBookingsView::OnUpdateFilePrintPreview(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if ((m_prdocket || m_prvoucher 
		|| m_prreconfirmation || m_prcancellation) 
		&& !m_nieuw)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CBookingsView::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	LOGFONT m_logfont;

	if (pDC->IsPrinting())
	{
		m_logfont.lfCharSet = ANSI_CHARSET;
		m_logfont.lfHeight  = 100;
		m_logfont.lfWidth = 0;
		m_logfont.lfEscapement = 0;
		m_logfont.lfOrientation = 0;
		m_logfont.lfWeight = FW_NORMAL;
		m_logfont.lfItalic = 0;
		m_logfont.lfUnderline = 0;
		m_logfont.lfStrikeOut = 0;
		m_logfont.lfOutPrecision = OUT_DEFAULT_PRECIS;
		m_logfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
		m_logfont.lfQuality = PROOF_QUALITY;
		m_logfont.lfPitchAndFamily = VARIABLE_PITCH |FF_ROMAN;
		strcpy(m_logfont.lfFaceName, "Times New Roman");

		CFont* m_font = new CFont();
		m_font->CreateFontIndirect(&m_logfont);
		CFont* m_oldfont = pDC->SelectObject(m_font);

		prnt_fit(pDC);
	}
}

void CBookingsView::prnt_fit(CDC* pDC)
{
	int paginahoogte = pDC->GetDeviceCaps(VERTRES);
	int begin;

	m_pages = 0;
	if (m_prdocket)
	{
		begin = m_pages * paginahoogte;
		prnt_fitdocket(pDC, begin);
		m_pages++;
	}
	if (m_prvoucher)
	{
		begin = m_pages * paginahoogte;
		prnt_voucher(pDC, begin);
		m_pages++;
	}
	if (m_prreconfirmation)
	{
		begin = m_pages * paginahoogte;
		prnt_confirmation(pDC, begin);
		m_pages++;
	}
	if (m_prcancellation)
	{
		begin = m_pages * paginahoogte;
		prnt_fitcancellation(pDC, begin);
		m_pages++;
	}
}

void CBookingsView::prnt_fitdocket(CDC* pDC,  int start)
{
	int y = 40;
	CString m_date;
	CString m_zoekwaarde;
	CString m_service;
	CDatecnv m_datecnv;
	char kamersoort[7][6];
	int  kamers[7];
	int  teller = 0;
	int  som_singles, som_tsu, som_doubles, som_twins, som_triples;
	int  som_quads, som_multiples;

//	char waarde_char[10];

	CAgents  m_setagents;

	m_zoekwaarde = "ag_code = '" + m_setbooking.m_ag_code + "'";
	m_setagents.m_strSort   = "ag_code";
	m_setagents.m_strFilter = m_zoekwaarde;
	m_setagents.Open();

	som_singles = m_setbooking.m_bo_asngls + m_setbooking.m_bo_esngls + m_setbooking.m_bo_rsngls;
	if (som_singles)
	{
		kamers[teller] = som_singles;
		strcpy(kamersoort[teller], "SGL");
		teller++;
	}
	som_tsu = m_setbooking.m_bo_atwnsngls + m_setbooking.m_bo_etwnsngls + m_setbooking.m_bo_rtwnsngls;
	if (som_tsu)
	{
		kamers[teller] = som_tsu;
		strcpy(kamersoort[teller], "TSU");
		teller++;
	}
	som_twins = m_setbooking.m_bo_atwns + m_setbooking.m_bo_etwns + m_setbooking.m_bo_rtwns;
	if (som_twins)
	{
		kamers[teller] = som_twins;
		strcpy(kamersoort[teller], "TWN");
		teller++;
	}
	som_doubles = m_setbooking.m_bo_adbls + m_setbooking.m_bo_edbls + m_setbooking.m_bo_rdbls;
	if (som_doubles)
	{
		kamers[teller] = som_doubles;
		strcpy(kamersoort[teller], "DBL");
		teller++;
	}
	som_triples = m_setbooking.m_bo_atrpls + m_setbooking.m_bo_etrpls + m_setbooking.m_bo_rtrpls;
	if (som_triples)
	{
		kamers[teller] = som_triples;
		strcpy(kamersoort[teller], "TRPL");
		teller++;
	}
	som_quads = m_setbooking.m_bo_aqds + m_setbooking.m_bo_eqds + m_setbooking.m_bo_rqds;
	if (som_quads)
	{
		kamers[teller] = som_quads;
		strcpy(kamersoort[teller], "QUAD");
		teller++;
	}
	som_multiples = m_setbooking.m_bo_amltpls + m_setbooking.m_bo_emltpls + m_setbooking.m_bo_rmltpls;
	if (som_multiples)
	{
		kamers[teller] = som_multiples;
		strcpy(kamersoort[teller], "MLTPL");
		teller++;
	}

	teller--;

	pDC->TextOut(1500,  y + start, "HOTEL  RESERVATION  DOCKET");
	y += 360;

	// eerste blok:
	// verticale lijnen:
	pDC->MoveTo(50,  600 + start);
	pDC->LineTo(50, 1800 + start);
	pDC->MoveTo(2900, 400 + start);
	pDC->LineTo(2900, 600 + start);
	pDC->MoveTo(4500, 400 + start);
	pDC->LineTo(4500, 1800 + start);

	// horizontale lijnen:
	pDC->MoveTo(2900, y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	pDC->TextOut(3000, y + start, "Booking date:");
	pDC->TextOut(3725, y + start, m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_date));
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	pDC->TextOut(140, y + start, "Operator:");
	pDC->TextOut(650, y + start, m_setbooking.m_us_naam);
	pDC->TextOut(1500, y + start, "Reference:");
	pDC->TextOut(2050, y + start, m_setbooking.m_bo_tourref);
	pDC->TextOut(3000, y + start, "Arrival date:");
	pDC->TextOut(3725, y + start, m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate));
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	pDC->TextOut(140, y + start, "Names:");
	y += 100;
//	pDC->MoveTo(50,   y + start);
//	pDC->LineTo(4500, y + start);
	pDC->TextOut(1000, y + start, m_setbooking.m_bo_passn);
	y += 260;
//	pDC->MoveTo(50,   y + start);
//	pDC->LineTo(4500, y + start);
	y += 40;

//	VIATRAVEL gebruikt geen "BOOKED VIA":
//
//	pDC->TextOut(140, y + start, "Booked through:");
//	pDC->TextOut(1000, y + start, m_setbooking.m_ag_namevia);

	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	pDC->TextOut(140, y + start, "Agent:");
	pDC->TextOut(1000, y + start, m_setbooking.m_ag_name);
	pDC->TextOut(3000, y + start, "Ref:");
	pDC->TextOut(3250, y + start, m_setbooking.m_bo_agentrf);
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	pDC->TextOut(140, y + start, "Booked by:");
	pDC->TextOut(750, y + start, m_setbooking.m_bo_bkdby);
	pDC->TextOut(1750, y + start, "Tel:");
	pDC->TextOut(2000, y + start, m_setagents.m_ag_tel);
	pDC->TextOut(3000, y + start, "Fax:");
	pDC->TextOut(3250, y + start, m_setagents.m_ag_fax);
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);

	y += 400;

	// tweede blok:
	// horizontale lijnen:
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	pDC->TextOut(140,  y + start, "HOTEL");
	pDC->TextOut(2000, y + start, "IN");
	pDC->TextOut(2700, y + start, "OUT");
	pDC->TextOut(3300, y + start, "NTS");
	pDC->TextOut(3550, y + start, "RMS");
	pDC->TextOut(3900, y + start, "SERVICE");
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	pDC->TextOut(140, y + start, m_setbooking.m_ho_name);
	pDC->TextOut(2000, y + start, m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate));
	pDC->TextOut(2700, y + start, m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_depdate));
	pDC->TextOut(3375, y + start, MaakStr(m_setbooking.m_bo_nights));
	pDC->TextOut(3600, y + start, MaakStr(kamers[0]));
	pDC->TextOut(3900, y + start, (CString) kamersoort[0]);

	if (m_setbooking.m_bo_service == "Room only")
		m_service = "RO";
	else if (m_setbooking.m_bo_service == "Bed and breakfast")
		m_service = "BB";
	else
		m_service = "HB";

	pDC->TextOut(4300, y + start, m_service);
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	if (teller >= 1)
	{
		pDC->TextOut(3600, y + start, MaakStr(kamers[1]));
		pDC->TextOut(3900, y + start, (CString) kamersoort[1]);
		pDC->TextOut(4300, y + start, m_service);
	}
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	if (teller >= 2)
	{
		pDC->TextOut(3600, y + start, MaakStr(kamers[2]));
		pDC->TextOut(3900, y + start, (CString) kamersoort[2]);
		pDC->TextOut(4300, y + start, m_service);
	}
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	if (teller >= 3)
	{
		pDC->TextOut(3600, y + start, MaakStr(kamers[3]));
		pDC->TextOut(3900, y + start, (CString) kamersoort[3]);
		pDC->TextOut(4300, y + start, m_service);
	}
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	if (teller >= 4)
	{
		pDC->TextOut(3600, y + start, MaakStr(kamers[4]));
		pDC->TextOut(3900, y + start, (CString) kamersoort[4]);
		pDC->TextOut(4300, y + start, m_service);
	}
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
//	if (teller >= 5)
//	{
//		pDC->TextOut(3600, y + start, MaakStr(kamers[5]));
//		pDC->TextOut(3900, y + start, (CString) kamersoort[5]);
//		pDC->TextOut(4200, y + start, m_service);
//	}
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	pDC->TextOut(2700, y + start, "Confirmed by:");
	pDC->TextOut(3450, y + start, m_setbooking.m_bo_cnfmdby);
	y += 160;
	pDC->MoveTo(2650, y + start);
	pDC->LineTo(4500, y + start);

	// verticale lijnen:
	pDC->MoveTo(50, 2200 + start);
	pDC->LineTo(50, 3600 + start);
	pDC->MoveTo(1950, 2200 + start);
	pDC->LineTo(1950, 3600 + start);
	pDC->MoveTo(2650, 2200 + start);
	pDC->LineTo(2650, 3800 + start);
	pDC->MoveTo(3275, 2200 + start);
	pDC->LineTo(3275, 3600 + start);
	pDC->MoveTo(3525, 2200 + start);
	pDC->LineTo(3525, 3600 + start);
	pDC->MoveTo(3850, 2200 + start);
	pDC->LineTo(3850, 3600 + start);
	pDC->MoveTo(4500, 2200 + start);
	pDC->LineTo(4500, 3800 + start);

	y += 400;

	// derde blok:
	y += 25;

	y -= 165;

	CString m_somremark;
	int i;

	m_somremark = "";
	for (i = 0; i < m_remarks.GetLength(); i++)
		if (m_remarks[i] != '\n' && m_remarks[i] != '\r')
			m_somremark += m_remarks[i];
		else if (m_remarks[i] != '\n')
			m_somremark += ' ';

	pDC->TextOut(100,  y + start, m_somremark.Left(70));
	y += 110;
	if (m_somremark.GetLength() > 70)
		pDC->TextOut(100,  y + start, m_somremark.Mid(70, 70));
	y += 110;
	if (m_somremark.GetLength() > 140)
		pDC->TextOut(100,  y + start, m_somremark.Mid(140, 70));
	y += 110;
	if (m_somremark.GetLength() > 210)
		pDC->TextOut(100,  y + start, m_somremark.Mid(210, 70));
	y += 110;
	if (m_somremark.GetLength() > 280)
		pDC->TextOut(100,  y + start, m_somremark.Mid(280, 70));
	y += 110;
	if (m_somremark.GetLength() > 350)
		pDC->TextOut(100,  y + start, m_somremark.Mid(350, 70));
	y += 110;
	if (m_somremark.GetLength() > 420)
		pDC->TextOut(100,  y + start, m_somremark.Mid(420, 70));
	y += 110;
	if (m_somremark.GetLength() > 490)
		pDC->TextOut(100,  y + start, m_somremark.Mid(490, 70));
	y += 110;
	if (m_somremark.GetLength() > 560)
		pDC->TextOut(100,  y + start, m_somremark.Mid(560, 40));

	y -= 165;

	y += 25;

/*	// verticale lijnen:
	// lengte : 600

	pDC->MoveTo(50, 4200 + start);
	pDC->LineTo(50, 4800 + start);
	pDC->MoveTo(4500, 4200 + start);
	pDC->LineTo(4500, 4800 + start);

	// horizontale lijnen:
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	pDC->TextOut(140, y + start, "OTHERS:");
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 200;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 200;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
*/

	y += 400;

	// vierde blok:
	// verticale lijnen:
	pDC->MoveTo(50, 5400 + start);
	pDC->LineTo(50, 6000 + start);
	pDC->MoveTo(700, 5200 + start);
	pDC->LineTo(700, 6000 + start);
	pDC->MoveTo(1400, 5200 + start);
	pDC->LineTo(1400, 6000 + start);
	pDC->MoveTo(2100, 5200 + start);
	pDC->LineTo(2100, 6000 + start);
	pDC->MoveTo(2800, 5200 + start);
	pDC->LineTo(2800, 6000 + start);
	pDC->MoveTo(3500, 5200 + start);
	pDC->LineTo(3500, 6200 + start);
	pDC->MoveTo(4500, 5200 + start);
	pDC->LineTo(4500, 6200 + start);


// Berekening bedrag:
	
	CHotels  m_sethotels;

	m_zoekwaarde = "ho_code = '" + m_setbooking.m_ho_code + "'";
	m_sethotels.m_strSort   = "ho_code";
	m_sethotels.m_strFilter = m_zoekwaarde;
	m_sethotels.Open();


	COleDateTime      begin, eind, vanaf, tot;
	int               periode[6];
	BOOL              nachten;
	int               beginseason, eindseason;
	COleDateTimeSpan  verschil;

	periode[0] = 0;
	periode[1] = 0;
	periode[2] = 0;
	periode[3] = 0;
	periode[4] = 0;
	periode[5] = 0;

	nachten = FALSE;
	beginseason = 0;
	eindseason  = 0;

	begin.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate), VAR_DATEVALUEONLY);
	eind.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_depdate), VAR_DATEVALUEONLY);

	if (begin.GetMonth() > eind.GetMonth())
		nachten = TRUE;

	if (m_sethotels.m_ho_from1 != "")
	{
	vanaf.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from1), VAR_DATEVALUEONLY);
	tot.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till1), VAR_DATEVALUEONLY);

	if (begin >= vanaf && begin <= tot)
	{
		nachten = TRUE;
		verschil      = tot - begin;
		periode[0]    = (int) verschil.GetTotalDays() + 1;
		beginseason   = 1;
	}

	if (eind >= vanaf && eind <= tot)
	{
		if (beginseason == 1)
			periode[0] = m_setbooking.m_bo_nights;
		else
		{
			verschil   = eind - vanaf;
			periode[0] = (int) verschil.GetTotalDays();
		}
		eindseason   = 1;
		nachten = FALSE;
	}

	if (beginseason != 1 && eindseason != 1 && nachten)
	{
		verschil   = tot - vanaf;
		periode[0] = (int) verschil.GetTotalDays() + 1;
	}
	}

	if (m_sethotels.m_ho_from2 != "")
	{
	vanaf.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from2), VAR_DATEVALUEONLY);
	tot.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till2), VAR_DATEVALUEONLY);

	if (begin >= vanaf && begin <= tot)
	{
		nachten = TRUE;
		verschil      = tot - begin;
		periode[1]    = (int) verschil.GetTotalDays() + 1;
		beginseason   = 2;
	}

	if (eind >= vanaf && eind <= tot)
	{
		if (beginseason == 2)
			periode[1] = m_setbooking.m_bo_nights;
		else
		{
			verschil   = eind - vanaf;
			periode[1] = (int) verschil.GetTotalDays();
		}
		eindseason   = 2;
		nachten = FALSE;
	}

	if (beginseason != 2 && eindseason != 2 && nachten)
	{
		verschil   = tot - vanaf;
		periode[1] = (int) verschil.GetTotalDays() + 1;
	}
	}


	if (m_sethotels.m_ho_from3 != "")
	{
	vanaf.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from3), VAR_DATEVALUEONLY);
	tot.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till3), VAR_DATEVALUEONLY);

	if (begin >= vanaf && begin < vanaf)
	{
		nachten = TRUE;
		verschil      = tot - begin;
		periode[2]    = (int) verschil.GetTotalDays() + 1;
		beginseason   = 3;
	}

	if (eind >= vanaf && eind <= tot)
	{
		if (beginseason == 3)
			periode[2] = m_setbooking.m_bo_nights;
		else
		{
			verschil   = eind - vanaf;
			periode[2] = (int) verschil.GetTotalDays();
		}
		eindseason   = 3;
		nachten = FALSE;
	}

	if (beginseason != 3 && eindseason != 3 && nachten)
	{
		verschil   = tot - vanaf;
		periode[2] = (int) verschil.GetTotalDays() + 1;
	}
	}


	if (m_sethotels.m_ho_from4 != "")
	{
	vanaf.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from4), VAR_DATEVALUEONLY);
	tot.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till4), VAR_DATEVALUEONLY);

	if (begin >= vanaf && begin <= tot)
	{
		nachten = TRUE;
		verschil      = tot - begin;
		periode[3]    = (int) verschil.GetTotalDays() + 1;
		beginseason   = 4;
	}

	if (eind >= vanaf && eind <= tot)
	{
		if (beginseason == 4)
			periode[3] = m_setbooking.m_bo_nights;
		else
		{
			verschil   = eind - vanaf;
			periode[3] = (int) verschil.GetTotalDays();
		}
		eindseason   = 4;
		nachten = FALSE;
	}

	if (beginseason != 4 && eindseason != 4 && nachten)
	{
		verschil   = tot - vanaf;
		periode[3] = (int) verschil.GetTotalDays() + 1;
	}
	}


	if (m_sethotels.m_ho_from5 != "")
	{
	vanaf.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from5), VAR_DATEVALUEONLY);
	tot.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till5), VAR_DATEVALUEONLY);

	if (begin >= vanaf && begin <= tot)
	{
		nachten = TRUE;
		verschil      = tot - begin;
		periode[4]    = (int) verschil.GetTotalDays() + 1;
		beginseason   = 5;
	}

	if (eind >= vanaf && eind <= tot)
	{
		if (beginseason == 5)
			periode[4] = m_setbooking.m_bo_nights;
		else
		{
			verschil   = eind - vanaf;
			periode[4] = (int) verschil.GetTotalDays();
		}
		eindseason   = 5;
		nachten = FALSE;
	}

	if (beginseason != 5 && eindseason != 5 && nachten)
	{
		verschil   = tot - vanaf;
		periode[4] = (int) verschil.GetTotalDays() + 1;
	}
	}


	if (m_sethotels.m_ho_from6 != "")
	{
	vanaf.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from6), VAR_DATEVALUEONLY);
	tot.ParseDateTime(m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till6), VAR_DATEVALUEONLY);

	if (begin >= vanaf && begin <= tot)
	{
		nachten = TRUE;
		verschil      = tot - begin;
		periode[5]    = (int) verschil.GetTotalDays() + 1;
		beginseason   = 6;
	}

	if (eind >= vanaf && eind <= tot)
	{
		if (beginseason == 6)
			periode[5] = m_setbooking.m_bo_nights;
		else
		{
			verschil   = eind - vanaf;
			periode[5] = (int) verschil.GetTotalDays();
		}
		eindseason   = 6;
		nachten = FALSE;
	}

	if (beginseason != 6 && eindseason != 6 && nachten)
	{
		verschil   = tot - vanaf;
		periode[5] = (int) verschil.GetTotalDays() + 1;
	}
	}


	double total = 0;
	CString strtotal;

	if (beginseason > 0 && eindseason > 0)
	{
		if (som_singles)
		{
			if (periode[0])
				total += periode[0] * m_sethotels.m_ho_sngls1;
			if (periode[1])
				total += periode[1] * m_sethotels.m_ho_sngls2;
			if (periode[2])
				total += periode[2] * m_sethotels.m_ho_sngls3;
			if (periode[3])
				total += periode[3] * m_sethotels.m_ho_sngls4;
			if (periode[4])
				total += periode[4] * m_sethotels.m_ho_sngls5;
			if (periode[5])
				total += periode[5] * m_sethotels.m_ho_sngls6;
		}

		if (som_tsu)
		{
			if (periode[0])
				total += periode[0] * m_sethotels.m_ho_tsu1;
			if (periode[1])
				total += periode[1] * m_sethotels.m_ho_tsu2;
			if (periode[2])
				total += periode[2] * m_sethotels.m_ho_tsu3;
			if (periode[3])
				total += periode[3] * m_sethotels.m_ho_tsu4;
			if (periode[4])
				total += periode[4] * m_sethotels.m_ho_tsu5;
			if (periode[5])
				total += periode[5] * m_sethotels.m_ho_tsu6;
		}
	
		if (som_doubles)
		{
			if (periode[0])
				total += periode[0] * m_sethotels.m_ho_dbls1;
			if (periode[1])
				total += periode[1] * m_sethotels.m_ho_dbls2;
			if (periode[2])
				total += periode[2] * m_sethotels.m_ho_dbls3;
			if (periode[3])
				total += periode[3] * m_sethotels.m_ho_dbls4;
			if (periode[4])
				total += periode[4] * m_sethotels.m_ho_dbls5;
			if (periode[5])
				total += periode[5] * m_sethotels.m_ho_dbls6;
		}

		if (som_twins)
		{
			if (periode[0])
				total += periode[0] * m_sethotels.m_ho_twns1;
			if (periode[1])
				total += periode[1] * m_sethotels.m_ho_twns2;
			if (periode[2])
				total += periode[2] * m_sethotels.m_ho_twns3;
			if (periode[3])
				total += periode[3] * m_sethotels.m_ho_twns4;
			if (periode[4])
				total += periode[4] * m_sethotels.m_ho_twns5;
			if (periode[5])
				total += periode[5] * m_sethotels.m_ho_twns6;
		}

		if (som_triples)
		{
			if (periode[0])
				total += periode[0] * m_sethotels.m_ho_trpls1;
			if (periode[1])
				total += periode[1] * m_sethotels.m_ho_trpls2;
			if (periode[2])
				total += periode[2] * m_sethotels.m_ho_trpls3;
			if (periode[3])
				total += periode[3] * m_sethotels.m_ho_trpls4;
			if (periode[4])
				total += periode[4] * m_sethotels.m_ho_trpls5;	
			if (periode[5])
				total += periode[5] * m_sethotels.m_ho_trpls6;
		}

		if (som_quads)
		{
			if (periode[0])
				total += periode[0] * m_sethotels.m_ho_qds1;
			if (periode[1])
				total += periode[1] * m_sethotels.m_ho_qds2;
			if (periode[2])
				total += periode[2] * m_sethotels.m_ho_qds3;
			if (periode[3])
				total += periode[3] * m_sethotels.m_ho_qds4;
			if (periode[4])
				total += periode[4] * m_sethotels.m_ho_qds5;
			if (periode[5])
				total += periode[5] * m_sethotels.m_ho_qds6;
		}

		if (som_multiples)
		{
			if (periode[0])
				total += periode[0] * m_sethotels.m_ho_mltpls1;
			if (periode[1])
				total += periode[1] * m_sethotels.m_ho_mltpls2;
			if (periode[2])
				total += periode[2] * m_sethotels.m_ho_mltpls3;
			if (periode[3])
				total += periode[3] * m_sethotels.m_ho_mltpls4;
			if (periode[4])
				total += periode[4] * m_sethotels.m_ho_mltpls5;
			if (periode[5])
				total += periode[5] * m_sethotels.m_ho_mltpls6;
		}
		strtotal.Format("%.2f", total);
	}
	else
		strtotal = "";


	// horizontale lijnen:
	pDC->MoveTo(700,  y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	pDC->TextOut(50, y + start, "Accounting");
	pDC->TextOut(3640, y + start, "TOTAL");
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	pDC->TextOut(140, y + start, "Hotel");
	pDC->TextOut(3640, y + start, strtotal);
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	pDC->TextOut(140, y + start, "Others");
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 40;
	pDC->TextOut(140, y + start, "Others");
	y += 160;
	pDC->MoveTo(50,   y + start);
	pDC->LineTo(4500, y + start);
	y += 200;
	pDC->MoveTo(3500, y + start);
	pDC->LineTo(4500, y + start);

//	m_setbooking.Close();
	m_setagents.Close();
	m_sethotels.Close();
}

void CBookingsView::prnt_confirmation(CDC* pDC,  int begin)
{
	int y = 40;
	CString m_date;
	CString m_zoekwaarde;
	CDatecnv m_datecnv;
	char kamersoort[7][20];
	int  kamers[7];
	int  teller = 0;
	int  som;
	CString m_sommessage;
	int i;

//	char waarde_char[10];


//	CBooking m_setbooking;
	CHotels  m_sethotels;
	CAgents  m_setagents;

//	m_zoekwaarde = "bo_tourref = '" + m_tourref + "'";
//	m_setbooking.m_strSort   = "bo_tourref";
//	m_setbooking.m_strFilter = m_zoekwaarde;
//	m_setbooking.Open();

	m_zoekwaarde = "ho_code = '" + m_setbooking.m_ho_code + "'";
	m_sethotels.m_strSort   = "ho_code";
	m_sethotels.m_strFilter = m_zoekwaarde;
	m_sethotels.Open();

	m_zoekwaarde = "ag_code = '" + m_setbooking.m_ag_code + "'";
	m_setagents.m_strSort   = "ag_code";
	m_setagents.m_strFilter = m_zoekwaarde;
	m_setagents.Open();


	som = m_setbooking.m_bo_asngls + m_setbooking.m_bo_esngls + m_setbooking.m_bo_rsngls;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Single");
		teller++;
	}
	som = m_setbooking.m_bo_atwnsngls + m_setbooking.m_bo_etwnsngls + m_setbooking.m_bo_rtwnsngls;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Twin-single use");
		teller++;
	}
	som = m_setbooking.m_bo_atwns + m_setbooking.m_bo_etwns + m_setbooking.m_bo_rtwns;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Twin");
		teller++;
	}
	som = m_setbooking.m_bo_adbls + m_setbooking.m_bo_edbls + m_setbooking.m_bo_rdbls;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Double");
		teller++;
	}
	som = m_setbooking.m_bo_atrpls + m_setbooking.m_bo_etrpls + m_setbooking.m_bo_rtrpls;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Triple");
		teller++;
	}
	som = m_setbooking.m_bo_aqds + m_setbooking.m_bo_eqds + m_setbooking.m_bo_rqds;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Quad");
		teller++;
	}
	som = m_setbooking.m_bo_amltpls + m_setbooking.m_bo_emltpls + m_setbooking.m_bo_rmltpls;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Multiple");
		teller++;
	}
	
	teller--;


	int tot_a[10], tot_e[10], tot_r[10];
	int tot_allotm, tot_allotm_cnfrmd, tot_req;
	int start, einde;


	if (m_startdates[1] != "")
	{
		for (i = 0; i < 10; i++)
		{
			m_xstartdates[i]     = m_startdates[i];
			m_xenddates[i]       = m_enddates[i];  
			m_xallotment[i]      = m_allotment[i];
			m_xextra[i]          = m_extra[i];
			m_xasingles[i]     = m_roasingles[i];  
			m_xatwinsingles[i] = m_roatwinsingles[i];  
			m_xatwins[i]       = m_roatwins[i];  
			m_xadoubles[i]     = m_roadoubles[i];  
			m_xatriples[i]     = m_roatriples[i];  
			m_xaquads[i]       = m_roaquads[i];  
			m_xamultiples[i]   = m_roamultiples[i];  
			m_xesingles[i]     = m_roesingles[i];  
			m_xetwinsingles[i] = m_roetwinsingles[i];  
			m_xetwins[i]       = m_roetwins[i];  
			m_xedoubles[i]     = m_roedoubles[i];  
			m_xetriples[i]     = m_roetriples[i];  
			m_xequads[i]       = m_roequads[i];  
			m_xemultiples[i]   = m_roemultiples[i];  
			m_xcsingles[i]     = m_rocsingles[i];  
			m_xctwinsingles[i] = m_roctwinsingles[i];  
			m_xctwins[i]       = m_roctwins[i];  
			m_xcdoubles[i]     = m_rocdoubles[i];  
			m_xctriples[i]     = m_roctriples[i];  
			m_xcquads[i]       = m_rocquads[i];  
			m_xcmultiples[i]   = m_rocmultiples[i];  
		}

		for (i = 0; i < 10; i++)
		{
			tot_a[i] = 0;
			tot_e[i] = 0;
		}
		for (i = 0; i < 10; i++)
		{
			tot_a[i] += m_xasingles[i];
			tot_a[i] += m_xatwinsingles[i];
			tot_a[i] += m_xatwins[i];
			tot_a[i] += m_xadoubles[i];
			tot_a[i] += m_xatriples[i];
			tot_a[i] += m_xaquads[i];
			tot_a[i] += m_xamultiples[i];
			tot_e[i] += m_xesingles[i];
			tot_e[i] += m_xetwinsingles[i];
			tot_e[i] += m_xetwins[i];
			tot_e[i] += m_xedoubles[i];
			tot_e[i] += m_xetriples[i];
			tot_e[i] += m_xequads[i];
			tot_e[i] += m_xemultiples[i];
		}

		start = 0;
		einde  = m_periodes - 1;
		while (start < einde)
		{
		if (tot_a[start] == tot_a[start+1] && tot_e[start] == tot_e[start+1])
		{
			m_xenddates[start]       = m_xenddates[start+1];

			for (i = start + 1; i < einde; i++)
			{
				tot_a[i]            = tot_a[i+1];
				tot_e[i]            = tot_e[i+1];

				m_xstartdates[i]     = m_xstartdates[i+1];
				m_xenddates[i]       = m_xenddates[i+1];  
				m_xallotment[i]      = m_xallotment[i+1];
				m_xextra[i]          = m_xextra[i+1];
				m_xasingles[i]     = m_xasingles[i+1];  
				m_xatwinsingles[i] = m_xatwinsingles[i+1];  
				m_xatwins[i]       = m_xatwins[i+1];  
				m_xadoubles[i]     = m_xadoubles[i+1];  
				m_xatriples[i]     = m_xatriples[i+1];  
				m_xaquads[i]       = m_xaquads[i+1];  
				m_xamultiples[i]   = m_xamultiples[i+1];  
				m_xesingles[i]     = m_xesingles[i+1];  
				m_xetwinsingles[i] = m_xetwinsingles[i+1];  
				m_xetwins[i]       = m_xetwins[i+1];  
				m_xedoubles[i]     = m_xedoubles[i+1];  
				m_xetriples[i]     = m_xetriples[i+1];  
				m_xequads[i]       = m_xequads[i+1];  
				m_xemultiples[i]   = m_xemultiples[i+1];  
				m_xcsingles[i]     = m_xcsingles[i+1];  
				m_xctwinsingles[i] = m_xctwinsingles[i+1];  
				m_xctwins[i]       = m_xctwins[i+1];  
				m_xcdoubles[i]     = m_xcdoubles[i+1];  
				m_xctriples[i]     = m_xctriples[i+1];  
				m_xcquads[i]       = m_xcquads[i+1];  
				m_xcmultiples[i]   = m_xcmultiples[i+1];  
			}

			m_xstartdates[i] = "";
			m_xenddates[i] = "";  
			m_xallotment[i] = 0;
			m_xextra[i] = 0;
			m_xasingles[i] = 0;  
			m_xatwinsingles[i] = 0;  
			m_xatwins[i] = 0;  
			m_xadoubles[i] = 0;  
			m_xatriples[i] = 0;  
			m_xaquads[i] = 0;  
			m_xamultiples[i] = 0;  
			m_xesingles[i] = 0;  
			m_xetwinsingles[i] = 0;  
			m_xetwins[i] = 0;  
			m_xedoubles[i] = 0;  
			m_xetriples[i] = 0;  
			m_xequads[i] = 0;  
			m_xemultiples[i] = 0;  
			m_xcsingles[i] = 0;  
			m_xctwinsingles[i] = 0;  
			m_xctwins[i] = 0;  
			m_xcdoubles[i] = 0;  
			m_xctriples[i] = 0;  
			m_xcquads[i] = 0;  
			m_xcmultiples[i] = 0;  

			einde--;
		}
		else
			start++;
		}
	}

	for (i = 0; i < 10; i++)
	{
		tot_a[i] = 0;
		tot_e[i] = 0;
		tot_r[i] = 0;
	}
	tot_allotm = 0;
	tot_allotm_cnfrmd = 0;
	for (i = 0; i < 10; i++)
	{
		tot_a[i] += m_xatwinsingles[i];
		tot_a[i] += m_xatwins[i];
		tot_a[i] += m_xadoubles[i];
		tot_allotm += m_xatwinsingles[i];
		tot_allotm += m_xatwins[i];
		tot_allotm += m_xadoubles[i];
		tot_a[i] += m_xasingles[i];
		tot_a[i] += m_xatriples[i];
		tot_a[i] += m_xaquads[i];
		tot_a[i] += m_xamultiples[i];
		tot_allotm_cnfrmd += m_xasingles[i];
		tot_allotm_cnfrmd += m_xatriples[i];
		tot_allotm_cnfrmd += m_xaquads[i];
		tot_allotm_cnfrmd += m_xamultiples[i];
		tot_e[i] += m_xetwinsingles[i];
		tot_e[i] += m_xetwins[i];
		tot_e[i] += m_xedoubles[i];
		tot_allotm += m_xetwinsingles[i];
		tot_allotm += m_xetwins[i];
		tot_allotm += m_xedoubles[i];
		tot_e[i] += m_xesingles[i];
		tot_e[i] += m_xetriples[i];
		tot_e[i] += m_xequads[i];
		tot_e[i] += m_xemultiples[i];
		tot_allotm_cnfrmd += m_xesingles[i];
		tot_allotm_cnfrmd += m_xetriples[i];
		tot_allotm_cnfrmd += m_xequads[i];
		tot_allotm_cnfrmd += m_xemultiples[i];
		tot_r[i] += m_xcsingles[i];
		tot_r[i] += m_xctwinsingles[i];
		tot_r[i] += m_xctwins[i];
		tot_r[i] += m_xcdoubles[i];
		tot_r[i] += m_xctriples[i];
		tot_r[i] += m_xcquads[i];
		tot_r[i] += m_xcmultiples[i];
	}

	tot_req       = tot_r[0] + tot_r[1] + tot_r[2] + tot_r[3] + tot_r[4];
	tot_req      += tot_r[5] + tot_r[6] + tot_r[7] + tot_r[8] + tot_r[9];

	CString service     = "";
	CString type_kamers = "";

	for (i = 0; i <= teller; i++)
		service += MaakStr(kamers[i]) + "  " + kamersoort[i] + " room(s)" + ",   ";
	service += m_setbooking.m_bo_service;		

	pDC->TextOut(140,  y + begin, "VIA  TRAVEL");
	pDC->TextOut(3250, y + begin, "Tel:  +3120 665 8919");
	y += 110;
	pDC->TextOut(140,  y + begin, "2e Boerhaavestraat 78");
	pDC->TextOut(3250, y + begin, "Fax:  +3120 694 4179");
	y += 110;
	pDC->TextOut(140,  y + begin, "1091  AR    Amsterdam, Holland");
	pDC->TextOut(3250, y + begin, "Email:  fit@viatravel.com");

	y += 220;
	pDC->MoveTo(50,   y + begin);
	pDC->LineTo(4500, y + begin);

	y += 220;
	pDC->TextOut(140,  y + begin, "To:  " + m_setbooking.m_ho_name);
	pDC->TextOut(3250, y + begin, "Fax: " + m_sethotels.m_ho_fax);
	y += 110;
	pDC->TextOut(3250,  y + begin, "Date: " + m_datecnv.Vandaag());

	y += 220;
	pDC->TextOut(750,  y + begin, "C O N F I R M A T I O N    O F    R E S E R V A T I O N");
	
	y += 330;
	pDC->TextOut(140,  y + begin, "We confirm the following reservation: ");
	pDC->TextOut(3250,  y + begin, "Our Ref:  " + m_setbooking.m_bo_tourref);
	y += 220;
	pDC->TextOut(140,  y + begin, "Passenger name:  " + m_setbooking.m_bo_passn);
	y += 110;

	pDC->TextOut(140,  y + begin, service);
	y += 110;

	CString arrival = "";

	if (m_setbooking.m_bo_arrival == "Early")
		arrival = "Early arrival";
	else if (m_setbooking.m_bo_arrival == "Late")
		arrival = "Late arrival";

	pDC->TextOut(140,  y + begin, "In:  " + m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate) + ".  Out:  " 
		+ m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_depdate)
		+ "   -   " + MaakStr(m_setbooking.m_bo_nights) + "  nights. " + arrival);
	y += 110;


	COleDateTime     datum_eind;
	COleDateTimeSpan verschil;
	CString          str_datum;
	int              tweede_kolom;

	tweede_kolom = y;
	if (m_xstartdates[1] != "")
	{
		type_kamers = "";
		if (tot_a[0] !=0)
			type_kamers += MaakStr2(tot_a[0]) + "  allotment  ";
		if (tot_e[0] !=0)
			type_kamers += MaakStr2(tot_e[0]) + "  extra  ";
		if (tot_r[0] !=0)
			type_kamers += MaakStr2(tot_r[0]) + "  request";

		datum_eind.ParseDateTime(m_xenddates[0], VAR_DATEVALUEONLY);
		verschil.SetDateTimeSpan(1, 0, 0, 0);
		datum_eind = datum_eind + verschil;
		str_datum = datum_eind.Format("%d-%m-%Y");
	
		pDC->TextOut(140,  y + begin, m_xstartdates[0] + "  -  " + str_datum + " " + 
			type_kamers);

		y += 110;

		if (m_xstartdates[1] != "")
		{
			type_kamers = "";
			if (tot_a[1] !=0)
				type_kamers += MaakStr2(tot_a[1]) + "  allotment  ";
			if (tot_e[1] !=0)
				type_kamers += MaakStr2(tot_e[1]) + "  extra  ";
			if (tot_r[1] !=0)
				type_kamers += MaakStr2(tot_r[1]) + "  request";

			datum_eind.ParseDateTime(m_xenddates[1], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(140,  y + begin, m_xstartdates[1] + "  -  " + str_datum + " " + 
				type_kamers);

			y += 110;
		}

		if (m_xstartdates[2] != "")
		{
			type_kamers = "";
			if (tot_a[2] !=0)
				type_kamers += MaakStr2(tot_a[2]) + "  allotment  ";
			if (tot_e[2] !=0)
				type_kamers += MaakStr2(tot_e[2]) + "  extra  ";
			if (tot_r[2] !=0)
				type_kamers += MaakStr2(tot_r[2]) + "  request";

			datum_eind.ParseDateTime(m_xenddates[2], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");

			pDC->TextOut(140,  y + begin, m_xstartdates[2] + "  -  " + str_datum + " " + 
				type_kamers);

			y += 110;
		}

		if (m_xstartdates[3] != "")
		{
			type_kamers = "";
			if (tot_a[3] !=0)
				type_kamers += MaakStr2(tot_a[3]) + "  allotment  ";
			if (tot_e[3] !=0)
				type_kamers += MaakStr2(tot_e[3]) + "  extra  ";
			if (tot_r[3] !=0)
				type_kamers += MaakStr2(tot_r[3]) + "  request";

			datum_eind.ParseDateTime(m_xenddates[3], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(140,  y + begin, m_xstartdates[3] + "  -  " + str_datum + " " + 
				type_kamers);

			y += 110;
		}

		if (m_xstartdates[4] != "")
		{
			type_kamers = "";
			if (tot_a[4] !=0)
				type_kamers += MaakStr2(tot_a[4]) + "  allotment  ";
			if (tot_e[4] !=0)
				type_kamers += MaakStr2(tot_e[4]) + "  extra  ";
			if (tot_r[4] !=0)
				type_kamers += MaakStr2(tot_r[4]) + "  request";

			datum_eind.ParseDateTime(m_xenddates[4], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(140,  y + begin, m_xstartdates[4] + "  -  " + str_datum + " " + 
				type_kamers);

			y += 110;
		}

		if (m_xstartdates[5] != "")
		{
			type_kamers = "";
			if (tot_a[5] !=0)
				type_kamers += MaakStr2(tot_a[5]) + "  allotment  ";
			if (tot_e[5] !=0)
				type_kamers += MaakStr2(tot_e[5]) + "  extra  ";
			if (tot_r[5] !=0)
				type_kamers += MaakStr2(tot_r[5]) + "  request";

			datum_eind.ParseDateTime(m_xenddates[5], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(2500,  tweede_kolom + begin, m_xstartdates[5] + "  -  " + str_datum + " " + 
				type_kamers);

			tweede_kolom += 110;
		}

		if (m_xstartdates[6] != "")
		{
			type_kamers = "";
			if (tot_a[6] !=0)
				type_kamers += MaakStr2(tot_a[6]) + "  allotment  ";
			if (tot_e[6] !=0)
				type_kamers += MaakStr2(tot_e[6]) + "  extra  ";
			if (tot_r[6] !=0)
				type_kamers += MaakStr2(tot_r[6]) + "  request";

			datum_eind.ParseDateTime(m_xenddates[6], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");

			pDC->TextOut(2500,  tweede_kolom + begin, m_xstartdates[6] + "  -  " + str_datum + " " + 
				type_kamers);

			tweede_kolom += 110;
		}

		if (m_xstartdates[7] != "")
		{
			type_kamers = "";
			if (tot_a[7] !=0)
				type_kamers += MaakStr2(tot_a[7]) + "  allotment  ";
			if (tot_e[7] !=0)
				type_kamers += MaakStr2(tot_e[7]) + "  extra  ";
			if (tot_r[7] !=0)
				type_kamers += MaakStr2(tot_r[7]) + "  request";

			datum_eind.ParseDateTime(m_xenddates[7], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(2500,  tweede_kolom + begin, m_xstartdates[3] + "  -  " + str_datum + " " + 
				type_kamers);

			tweede_kolom += 110;
		}

		if (m_xstartdates[8] != "")
		{
			type_kamers = "";
			if (tot_a[8] !=0)
				type_kamers += MaakStr2(tot_a[8]) + "  allotment  ";
			if (tot_e[8] !=0)
				type_kamers += MaakStr2(tot_e[8]) + "  extra  ";
			if (tot_r[8] !=0)
				type_kamers += MaakStr2(tot_r[8]) + "  request";

			datum_eind.ParseDateTime(m_xenddates[8], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(2500,  tweede_kolom + begin, m_xstartdates[8] + "  -  " + str_datum + " " + 
				type_kamers);

			tweede_kolom += 110;
		}

		if (m_xstartdates[9] != "")
		{
			type_kamers = "";
			if (tot_a[9] !=0)
				type_kamers += MaakStr2(tot_a[9]) + "  allotment  ";
			if (tot_e[9] !=0)
				type_kamers += MaakStr2(tot_e[9]) + "  extra  ";
			if (tot_r[9] !=0)
				type_kamers += MaakStr2(tot_r[9]) + "  request";

			datum_eind.ParseDateTime(m_xenddates[1], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(2500,  tweede_kolom + begin, m_xstartdates[1] + "  -  " + str_datum + " " + 
				type_kamers);

			tweede_kolom += 110;
		}
	}

	if (tot_req != 0)
	{
		pDC->TextOut(140,  y + begin, "On request as confirmed on " + m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_date) 
			+ " by " + m_setbooking.m_bo_cnfmdby);
		y += 110;
	}
	if (tot_allotm != 0 && tot_allotm_cnfrmd != 0)
	{
		pDC->TextOut(140,  y + begin, "Allotment room(s) and from allotment confirmed on " + 
			m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_date) + ".");
		y += 110;
	}
	else if (tot_allotm != 0 && tot_allotm_cnfrmd == 0)
	{
		pDC->TextOut(140,  y + begin, "Allotment room(s).");
		y += 110;
	}
	else if (tot_allotm == 0 && tot_allotm_cnfrmd != 0)
	{
		pDC->TextOut(140,  y + begin, "From allotment confirmed on " + 
			m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_date) + ".");
		y += 110;
	}
	y += 110;
	pDC->TextOut(140,  y + begin, "Passenger(s) will be arriving with voucher.");
	y += 220;
	pDC->TextOut(140,  y + begin, "Please invoice us for these services according to our contract rates.");
	y += 110;
	pDC->TextOut(140,  y + begin, "All other extras should be paid directly to you by the client(s).");
	y += 220;
	m_sommessage = "";
	for (i = 0; i < m_setbooking.m_bo_mhotel.GetLength(); i++)
		if (m_setbooking.m_bo_mhotel[i] != '\n' && 
				m_setbooking.m_bo_mhotel[i] != '\r')
			m_sommessage += m_setbooking.m_bo_mhotel[i];
		else if (m_setbooking.m_bo_mhotel[i] != '\n')
			m_sommessage += ' ';

	if (m_sommessage.GetLength() <= 68)
		pDC->TextOut(140,  y + begin, m_sommessage);
	else if(m_sommessage.GetLength() <= 136)
	{
		pDC->TextOut(140,  y + begin, m_sommessage.Left(68));
		y += 110;
		pDC->TextOut(140,  y + begin, m_sommessage.Mid(68,68));
	}
	else
	{
		pDC->TextOut(140,  y + begin, m_sommessage.Left(68));
		y += 110;
		pDC->TextOut(140,  y + begin, m_sommessage.Mid(68,68));
		y += 110;
		pDC->TextOut(140,  y + begin, m_sommessage.Mid(136,65));
	}

	y += 220;
	pDC->TextOut(140,  y + begin, "With the best regards");
	y += 110;
	pDC->TextOut(140,  y + begin, m_setbooking.m_us_naam);

	y += 440; // ipv y+= 990;ipv y+= 550;
	
	pDC->TextOut(140,  y + begin, "VIA  TRAVEL");
	pDC->TextOut(3250, y + begin, "Tel:  +3120 665 8919");
	y += 110;
	pDC->TextOut(140,  y + begin, "2e Boerhaavestraat 78");
	pDC->TextOut(3250, y + begin, "Fax:  +3120 694 4179");
	y += 110;
	pDC->TextOut(140,  y + begin, "1091   AR    Amsterdam, Holland");
	pDC->TextOut(3250, y + begin, "Email:  fit@viatravel.com");

	y += 220;
	pDC->MoveTo(50,   y + begin);
	pDC->LineTo(4500, y + begin);

	y += 220;
	pDC->TextOut(140,  y + begin, "To  :  " + m_setbooking.m_ag_name);
	pDC->TextOut(3250, y + begin, "Fax: " + m_setagents.m_ag_fax);
	y += 110;
	pDC->TextOut(140,  y + begin, "Attn:  " + m_setbooking.m_bo_bkdby);
	pDC->TextOut(3250,  y + begin, "Date: " + m_datecnv.Vandaag());

	y += 220;
	pDC->TextOut(750,  y + begin, "C O N F I R M A T I O N    O F    R E S E R V A T I O N");
	
	y += 330;
	pDC->TextOut(140,  y + begin, "We confirm the following reservation: ");
	pDC->TextOut(3250,  y + begin, "Our Ref:  " + m_setbooking.m_bo_tourref);
	y += 220;
	pDC->TextOut(140,  y + begin, "Passenger name:  " + m_setbooking.m_bo_passn);
	pDC->TextOut(3250,  y + begin, "Your Ref:  " + m_setbooking.m_bo_agentrf);
	y += 110;
	pDC->TextOut(140,  y + begin, "Hotel:  " + m_setbooking.m_ho_name + "   In:  " + m_sethotels.m_ho_city);
	y += 110;
	pDC->TextOut(140,  y + begin, service);
	y += 110;
	pDC->TextOut(140,  y + begin, "In:  " + m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate) + ".   Out:  " 
		+ m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_depdate)
		+ "   -   " + MaakStr(m_setbooking.m_bo_nights) + "  nights.");
	y += 220;
	m_sommessage = "";
	for (i = 0; i < m_setbooking.m_bo_magent.GetLength(); i++)
		if (m_setbooking.m_bo_magent[i] != '\n' && 
				m_setbooking.m_bo_magent[i] != '\r')
			m_sommessage += m_setbooking.m_bo_magent[i];
		else if (m_setbooking.m_bo_magent[i] != '\n')
			m_sommessage += ' ';

	if (m_sommessage.GetLength() <= 68)
		pDC->TextOut(140,  y + begin, m_sommessage);
	else if(m_sommessage.GetLength() <= 136)
	{
		pDC->TextOut(140,  y + begin, m_sommessage.Left(68));
		y += 110;
		pDC->TextOut(140,  y + begin, m_sommessage.Mid(68,68));
	}
	else
	{
		pDC->TextOut(140,  y + begin, m_sommessage.Left(68));
		y += 110;
		pDC->TextOut(140,  y + begin, m_sommessage.Mid(68,68));
		y += 110;
		pDC->TextOut(140,  y + begin, m_sommessage.Mid(136,65));
	}

	y += 220;
	pDC->TextOut(140,  y + begin, "With the best regards");
	y += 110;
	pDC->TextOut(140,  y + begin, m_setbooking.m_us_naam);

//	m_setbooking.Close();
	m_sethotels.Close();
	m_setagents.Close();
}

void CBookingsView::prnt_fitcancellation(CDC* pDC,  int begin)
{
	int y = 40;
	CString m_date;
	CString m_zoekwaarde;
	CDatecnv m_datecnv;
	char kamersoort[7][20];
	int  kamers[7];
	int  teller = 0;
	int  som;
//	char waarde_char[10];

//	CBooking m_setbooking;
	CHotels  m_sethotels;
	CAgents  m_setagents;

//	m_zoekwaarde = "bo_tourref = '" + m_tourref + "'";
//	m_setbooking.m_strSort   = "bo_tourref";
//	m_setbooking.m_strFilter = m_zoekwaarde;
//	m_setbooking.Open();

	m_zoekwaarde = "ho_code = '" + m_setbooking.m_ho_code + "'";
	m_sethotels.m_strSort   = "ho_code";
	m_sethotels.m_strFilter = m_zoekwaarde;
	m_sethotels.Open();

	m_zoekwaarde = "ag_code = '" + m_setbooking.m_ag_code + "'";
	m_setagents.m_strSort   = "ag_code";
	m_setagents.m_strFilter = m_zoekwaarde;
	m_setagents.Open();

	som = m_setbooking.m_bo_asngls + m_setbooking.m_bo_esngls + m_setbooking.m_bo_rsngls;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Single");
		teller++;
	}
	som = m_setbooking.m_bo_atwnsngls + m_setbooking.m_bo_etwnsngls + m_setbooking.m_bo_rtwnsngls;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Twin-single use");
		teller++;
	}
	som = m_setbooking.m_bo_atwns + m_setbooking.m_bo_etwns + m_setbooking.m_bo_rtwns;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Twin");
		teller++;
	}
	som = m_setbooking.m_bo_adbls + m_setbooking.m_bo_edbls + m_setbooking.m_bo_rdbls;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Double");
		teller++;
	}
	som = m_setbooking.m_bo_atrpls + m_setbooking.m_bo_etrpls + m_setbooking.m_bo_rtrpls;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Triple");
		teller++;
	}
	som = m_setbooking.m_bo_aqds + m_setbooking.m_bo_eqds + m_setbooking.m_bo_rqds;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Quad");
		teller++;
	}
	som = m_setbooking.m_bo_amltpls + m_setbooking.m_bo_emltpls + m_setbooking.m_bo_rmltpls;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Multiple");
		teller++;
	}
	
	teller--;



	int tot_a[10], totaal, i;

	for (i = 0; i < 10; i++)
	{
		tot_a[i] = 0;
	}
	totaal = 0;
	for (i = 0; i < 10; i++)
	{
		tot_a[i] += m_roasingles[i];
		tot_a[i] += m_roatwinsingles[i];
		tot_a[i] += m_roatwins[i];
		tot_a[i] += m_roadoubles[i];
		tot_a[i] += m_roatriples[i];
		tot_a[i] += m_roaquads[i];
		tot_a[i] += m_roamultiples[i];
		totaal   += tot_a[i];
	}

	CString service = "";

	for (i = 0; i <= teller; i++)
		service += MaakStr(kamers[i]) + "  " + kamersoort[i] + " room(s)" + ",   ";
	service += m_setbooking.m_bo_service;		

	pDC->TextOut(140,  y + begin, "VIA  TRAVEL");
	pDC->TextOut(3250, y + begin, "Tel:  +3120 665 8919");
	y += 110;
	pDC->TextOut(140,  y + begin, "2e Boerhaavestraat 78");
	pDC->TextOut(3250, y + begin, "Fax:  +3120 694 4179");
	y += 110;
	pDC->TextOut(140,  y + begin, "1091   AR    Amsterdam, Holland");
	pDC->TextOut(3250, y + begin, "Email:  fit@viatravel.com");

	y += 220;
	pDC->MoveTo(50,   y + begin);
	pDC->LineTo(4500, y + begin);

	y += 220;
	pDC->TextOut(140,  y + begin, "To:  " + m_setbooking.m_ho_name);
	pDC->TextOut(3250, y + begin, "Fax: " + m_sethotels.m_ho_fax);
	y += 110;
	pDC->TextOut(3250,  y + begin, "Date: " + m_datecnv.Vandaag());

	y += 220;
	pDC->TextOut(750,  y + begin, "C A N C E L L A T I O N    O F    R E S E R V A T I O N");
	
	y += 330;
	pDC->TextOut(140,  y + begin, "Please cancell the following reservation: ");
	pDC->TextOut(3250,  y + begin, "Our Ref:  " + m_setbooking.m_bo_tourref);
	y += 220;
	pDC->TextOut(140,  y + begin, "Passenger name:  " + m_setbooking.m_bo_passn);
	y += 220;

	pDC->TextOut(140,  y + begin, service);
	y += 110;

	CString arrival = "";

	if (m_setbooking.m_bo_arrival == "Early")
		arrival = "Early arrival";
	else if (m_setbooking.m_bo_arrival == "Late")
		arrival = "Late arrival";

	pDC->TextOut(140,  y + begin, "In:  " + m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate) + ".  Out:  " 
		+ m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_depdate)	+ "   -   " + MaakStr(m_setbooking.m_bo_nights) + "  nights.  " + arrival);
	y += 110;


	COleDateTime     datum_eind;
	COleDateTimeSpan verschil;
	CString          str_datum;
	int              tweede_kolom;


	if (m_startdates[1] != "" && totaal > 0)
		pDC->TextOut(140,  y + begin, "Please correct the allotment accordingly. As follows:"); 
	else if (totaal > 0)
		pDC->TextOut(140,  y + begin, "Please correct the allotment accordingly.");
	y += 110;

	tweede_kolom = y;
	if (m_startdates[1] != "" && totaal > 0)
	{
		if (tot_a[0] !=0)
		{
			datum_eind.ParseDateTime(m_enddates[0], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(140,  y + begin, m_startdates[0] + "  -  " + str_datum);
			y += 110;
		}

		if (m_startdates[1] != "" && tot_a[1] !=0)
		{
			datum_eind.ParseDateTime(m_enddates[1], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(140,  y + begin, m_startdates[1] + "  -  " + str_datum);
			y += 110;
		}

		if (m_startdates[2] != "" && tot_a[2] !=0)
		{
			datum_eind.ParseDateTime(m_enddates[2], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(140,  y + begin, m_startdates[2] + "  -  " + str_datum);
			y += 110;
		}

		if (m_startdates[3] != "" && tot_a[3] !=0)
		{
			datum_eind.ParseDateTime(m_enddates[3], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(140,  y + begin, m_startdates[3] + "  -  " + str_datum);
			y += 110;
		}

		if (m_startdates[4] != "" && tot_a[4] !=0)
		{
			datum_eind.ParseDateTime(m_enddates[4], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(140,  y + begin, m_startdates[4] + "  -  " + str_datum);
			y += 110;
		}

		if (m_startdates[5] != "" && tot_a[5] !=0)
		{
			datum_eind.ParseDateTime(m_enddates[5], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(2500,  tweede_kolom + begin, m_startdates[5] + "  -  " + str_datum);
			tweede_kolom += 110;
		}

		if (m_startdates[6] != "" && tot_a[6] !=0)
		{
			datum_eind.ParseDateTime(m_enddates[6], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(2500,  tweede_kolom + begin, m_startdates[6] + "  -  " + str_datum);
			tweede_kolom += 110;
		}

		if (m_startdates[7] != "" && tot_a[7] !=0)
		{
			datum_eind.ParseDateTime(m_enddates[7], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(2500,  tweede_kolom + begin, m_startdates[7] + "  -  " + str_datum);
			tweede_kolom += 110;
		}

		if (m_startdates[8] != "" && tot_a[8] !=0)
		{
			datum_eind.ParseDateTime(m_enddates[8], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(2500,  tweede_kolom + begin, m_startdates[8] + "  -  " + str_datum);
			tweede_kolom += 110;
		}

		if (m_startdates[9] != "" && tot_a[9] !=0)
		{
			datum_eind.ParseDateTime(m_enddates[9], VAR_DATEVALUEONLY);
			verschil.SetDateTimeSpan(1, 0, 0, 0);
			datum_eind = datum_eind + verschil;
			str_datum = datum_eind.Format("%d-%m-%Y");
	
			pDC->TextOut(2500,  tweede_kolom + begin, m_startdates[9] + "  -  " + str_datum);
			tweede_kolom += 110;
		}
	}

	
	y += 220;
	pDC->TextOut(140,  y + begin, "With the best regards");
	y += 110;
	pDC->TextOut(140,  y + begin, m_setbooking.m_us_naam);

	y += 880;
	
	pDC->TextOut(140,  y + begin, "VIA  TRAVEL");
	pDC->TextOut(3250, y + begin, "Tel:  +3120 665 8919");
	y += 110;
	pDC->TextOut(140,  y + begin, "2e Boerhaavestraat 78");
	pDC->TextOut(3250, y + begin, "Fax:  +3120 694 4179");
	y += 110;
	pDC->TextOut(140,  y + begin, "1091   AR    Amsterdam, Holland");
	pDC->TextOut(3250, y + begin, "Email:  fit@viatravel.com");

	y += 220;
	pDC->MoveTo(50,   y + begin);
	pDC->LineTo(4500, y + begin);

	y += 220;
	pDC->TextOut(140,  y + begin, "To  :  " + m_setbooking.m_ag_name);
	pDC->TextOut(3250, y + begin, "Fax: " + m_setagents.m_ag_fax);
	y += 110;
	pDC->TextOut(140,  y + begin, "Attn:  " + m_setbooking.m_bo_bkdby);
	pDC->TextOut(3250,  y + begin, "Date: " + m_datecnv.Vandaag());

	y += 220;
	pDC->TextOut(750,  y + begin, "C A N C E L L A T I O N    O F    R E S E R V A T I O N");
	
	y += 330;
	pDC->TextOut(140,  y + begin, "We have cancelled the following reservation: ");
	pDC->TextOut(3250,  y + begin, "Our Ref:  " + m_setbooking.m_bo_tourref);
	y += 220;
	pDC->TextOut(140,  y + begin, "Passenger name: " + m_setbooking.m_bo_passn);
	pDC->TextOut(3250,  y + begin, "Your Ref:  " + m_setbooking.m_bo_agentrf);
	y += 220;
	pDC->TextOut(140,  y + begin, "Hotel:  " + m_setbooking.m_ho_name + "   In: " + m_sethotels.m_ho_city);
	y += 110;
	pDC->TextOut(140,  y + begin, service);
	y += 110;
	pDC->TextOut(140,  y + begin, "In: " + m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate) + ".  Out:  " 
		+ m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_depdate)
		+ "   -   " + MaakStr(m_setbooking.m_bo_nights) + "  nights.");
	y += 220;
	pDC->TextOut(140,  y + begin, "With the best regards");
	y += 110;
	pDC->TextOut(140,  y + begin, m_setbooking.m_us_naam);

//	m_setbooking.Close();
	m_sethotels.Close();
	m_setagents.Close();
}

void CBookingsView::MakeVoucher() 
{
	// TODO: Add your control notification handler code here
	CVouchers m_setvoucher;
	COleDateTime m_vandaag;
	CHotels m_sethotels;
	CString m_zoekwaarde;
	CString m_date;
	CDatecnv m_datecnv;
	char kamersoort[7][20];
	int  kamers[7];
	int  teller = 0;
	int  som;
	int  i;
	CString m_servicerequest1 = "";
	CString m_servicerequest2 = "";
	CString m_servicerequest3 = "";
	CString m_servicerequest4 = "";
	CString m_services;

	m_vandaag = COleDateTime::GetCurrentTime();

//	UpdateData(TRUE);

	m_zoekwaarde = "ho_code = '" + m_setbooking.m_ho_code + "'";
	m_sethotels.m_strFilter = m_zoekwaarde;
	m_sethotels.Open();

	som = m_setbooking.m_bo_asngls + m_setbooking.m_bo_esngls + m_setbooking.m_bo_rsngls;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Single");
		teller++;
	}
	som = m_setbooking.m_bo_atwnsngls + m_setbooking.m_bo_etwnsngls + m_setbooking.m_bo_rtwnsngls;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Twin-single use");
		teller++;
	}
	som = m_setbooking.m_bo_atwns + m_setbooking.m_bo_etwns + m_setbooking.m_bo_rtwns;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Twin");
		teller++;
	}
	som = m_setbooking.m_bo_adbls + m_setbooking.m_bo_edbls + m_setbooking.m_bo_rdbls;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Double");
		teller++;
	}
	som = m_setbooking.m_bo_atrpls + m_setbooking.m_bo_etrpls + m_setbooking.m_bo_rtrpls;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Triple");
		teller++;
	}
	som = m_setbooking.m_bo_aqds + m_setbooking.m_bo_eqds + m_setbooking.m_bo_rqds;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Quad");
		teller++;
	}
	som = m_setbooking.m_bo_amltpls + m_setbooking.m_bo_emltpls + m_setbooking.m_bo_rmltpls;
	if (som)
	{
		kamers[teller] = som;
		strcpy(kamersoort[teller], "Multiple");
		teller++;
	}

	teller--;

	for (i = 0; i <= 2 && i <= teller; i++)
		m_servicerequest1 += MaakStr(kamers[i]) + "  " + kamersoort[i] + " room(s)" + ", ";

	for (i = 3; i <= teller; i++)
		m_servicerequest2 += MaakStr(kamers[i]) + "  " + kamersoort[i] + " room(s)" + ", ";

	if (m_servicerequest2 == "")
		m_servicerequest2 = "In:  " + m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate) + ".  Out :  " 
			+ m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_depdate)
			+ "   -   " + MaakStr(m_setbooking.m_bo_nights) + "  nights.";
	else
		m_servicerequest3 = "In:  " + m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate) + ".  Out :  " 
			+ m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_depdate)
			+ "   -   " + MaakStr(m_setbooking.m_bo_nights) + "  nights.";

	if (m_servicerequest3 == "")
		m_servicerequest3 = "On  " + m_setbooking.m_bo_service + "  basis.";
	else
		m_servicerequest4 = "On  " + m_setbooking.m_bo_service + "  basis.";

	m_services = m_servicerequest1 + "\r\n" + m_servicerequest2 + "\r\n" +
				m_servicerequest3 + "\r\n" + m_servicerequest4;

	m_setvoucher.Open();
	if (!m_setvoucher.IsEOF())
	{
		m_setvoucher.MoveLast();
		m_vouchernr = m_setvoucher.m_number + 1;
	}
	else
		m_vouchernr = 1;

	m_setvoucher.AddNew();

	m_setvoucher.m_number   = m_vouchernr;
	m_setvoucher.m_type     = "hotel";
	m_setvoucher.m_us_name  = m_gebruiker;
	m_setvoucher.m_address1 = m_sethotels.m_ho_addr1;
	m_setvoucher.m_address2 = m_sethotels.m_ho_addr2;
	m_setvoucher.m_zipcode  = m_sethotels.m_ho_zipcode;
	m_setvoucher.m_city     = m_sethotels.m_ho_city;
	m_setvoucher.m_country  = m_sethotels.m_ho_country;
	m_setvoucher.m_email    = m_sethotels.m_ho_email;
	m_setvoucher.m_supplier = m_sethotels.m_ho_code;
	m_setvoucher.m_date     = m_vandaag.Format("%Y%m%d");
	m_setvoucher.m_name     = m_sethotels.m_ho_name;
	m_setvoucher.m_tel      = m_sethotels.m_ho_tel;
	m_setvoucher.m_names    = m_setbooking.m_bo_passn;
	m_setvoucher.m_pax      = m_setbooking.m_bo_pax;
	m_setvoucher.m_service1 = m_services.Left(250);
	if (m_services.GetLength() > 250)
		m_setvoucher.m_service2 = m_services.Mid(250,250);
	else
		m_setvoucher.m_service2 = "";
		
	m_setvoucher.Update();

	m_sethotels.Close();
	m_setvoucher.Close();
}

void CBookingsView::prnt_voucher(CDC* pDC,  int begin)
{
	int y = 40;
	CString m_date;
	CString m_zoekwaarde;
	CDatecnv m_datecnv;
//	char waarde_char[10];

	CVouchers m_setvoucher;
//	CUsers   m_setusers;

	m_zoekwaarde = "number = " + MaakStr(m_vouchernr) + "";
	m_setvoucher.m_strSort   = "number";
	m_setvoucher.m_strFilter = m_zoekwaarde;
	m_setvoucher.Open();

//	m_zoekwaarde = "us_naam = '" + m_setvoucher.m_us_name + "'";
//	m_setusers.m_strSort   = "us_naam";
//	m_setusers.m_strFilter = m_zoekwaarde;
//	m_setusers.Open();

	CString m_service;
	CString m_serviceregel1;
	CString m_serviceregel2;
	CString m_serviceregel3;
	CString m_serviceregel4;
	CString m_serviceregel5;
	CString m_serviceregel6;
	CString m_serviceregel7;
	CString m_serviceregel8;

	int i, j, regelnr;
	char regels[8][251];

	m_serviceregel1 = "";
	m_serviceregel2 = "";
	m_serviceregel3 = "";
	m_serviceregel4 = "";
	m_serviceregel5 = "";
	m_serviceregel6 = "";
	m_serviceregel7 = "";
	m_serviceregel8 = "";

	m_service = m_setvoucher.m_service1 + m_setvoucher.m_service2;

	regels[0][0] = '\0';
	regels[1][0] = '\0';
	regels[2][0] = '\0';
	regels[3][0] = '\0';
	regels[4][0] = '\0';
	regels[5][0] = '\0';
	regels[6][0] = '\0';
	regels[7][0] = '\0';

	regelnr = 0;
	j = 0;
	for (i = 0; i < m_service.GetLength(); i++)
	{
		if (m_service[i] == '\n')
		{
			regels[regelnr][--j] = '\0';
			j = 0;
			regelnr++;
		}
		else
			regels[regelnr][j++] = m_service[i];
	}
	regels[regelnr][j++] = '\0';
	regelnr++;

	m_serviceregel1 = (CString) regels[0];
	m_serviceregel2 = (CString) regels[1];
	m_serviceregel3 = (CString) regels[2];
	m_serviceregel4 = (CString) regels[3];
	m_serviceregel5 = (CString) regels[4];
	m_serviceregel6 = (CString) regels[5];
	m_serviceregel7 = (CString) regels[6];
	m_serviceregel8 = (CString) regels[7];

	pDC->Rectangle(40,  120 + begin,1750,600 + begin);
	pDC->Rectangle(2400,120 + begin,4500,840 + begin);

	y += 160;
	pDC->TextOut(140,  y + begin, "VOUCHER  NO:");
	pDC->TextOut(1100,  y + begin, MaakStr(m_setvoucher.m_number));
	pDC->TextOut(2500, y + begin, m_setvoucher.m_name);
	y += 120;
	pDC->TextOut(2500, y + begin, m_setvoucher.m_address1);
	y += 120;
	pDC->TextOut(140,  y + begin, "ISSUED ON      :");
	pDC->TextOut(1100, y + begin, m_datecnv.Vandaag());
	pDC->TextOut(2500, y + begin, m_setvoucher.m_zipcode + "  " + m_setvoucher.m_city);
	y += 120;
	pDC->TextOut(2500,  y + begin, "Tel:");
	pDC->TextOut(2750,  y + begin, m_setvoucher.m_tel);

	y += 360;

	pDC->TextOut(140,  y + begin, "CLIENT(S)  NAME(S):");
	pDC->TextOut(1600,  y + begin, m_setvoucher.m_names);
	y += 120;
	pDC->TextOut(140,  y + begin, "NUMBER  OF  PERSONS:");
	pDC->TextOut(1600, y + begin, MaakStr(m_setvoucher.m_pax));
	if (m_setvoucher.m_frees)
		pDC->TextOut(1700,  y + begin, " + " + MaakStr(m_setvoucher.m_frees));

	y += 360;

	pDC->Rectangle(40,  1440 + begin, 3500, 1680 + begin);
	pDC->TextOut(140,  y + begin, "IN  EXCHANGE  OF  THIS  VOUCHER  PLEASE  PROVIDE:");


	y += 240;
	
	pDC->TextOut(140,  y + begin, m_serviceregel1);
	y += 120;
	pDC->TextOut(140,  y + begin, m_serviceregel2);
	y += 120;
	pDC->TextOut(140,  y + begin, m_serviceregel3);
	y += 120;
	pDC->TextOut(140,  y + begin, m_serviceregel4);
	y += 120;
	pDC->TextOut(140,  y + begin, m_serviceregel5);
	y += 120;
	pDC->TextOut(140,  y + begin, m_serviceregel6);
	y += 120;
	pDC->TextOut(140,  y + begin, m_serviceregel7);
	y += 120;
	pDC->TextOut(140,  y + begin, m_serviceregel8);
	y += 360;

	pDC->TextOut(2500,  y + begin, "For  Via Travel");
	y += 120;
	pDC->TextOut(2500,  y + begin, m_setvoucher.m_us_name);


	// Tweede keer:

	y += 300; // 1500;
	
	pDC->Rectangle(40,  3460 + begin,1750,3940 + begin);
	pDC->Rectangle(2400,3460 + begin,4500,4180 + begin);

	y += 160;
	pDC->TextOut(140,  y + begin, "VOUCHER  NO:");
	pDC->TextOut(1100, y + begin, MaakStr(m_setvoucher.m_number));
	pDC->TextOut(2500, y + begin, m_setvoucher.m_name);
	y += 120;
	pDC->TextOut(2500, y + begin, m_setvoucher.m_address1);
	y += 120;
	pDC->TextOut(140,  y + begin, "ISSUED ON      :");
	pDC->TextOut(1100, y + begin, m_datecnv.Vandaag());
	pDC->TextOut(2500, y + begin, m_setvoucher.m_zipcode + "  " + m_setvoucher.m_city);
	y += 120;
	pDC->TextOut(2500,  y + begin, "Tel:");
	pDC->TextOut(2750,  y + begin, m_setvoucher.m_tel);

	y += 360;

	pDC->TextOut(140,  y + begin, "CLIENT(S)  NAME(S):");
	pDC->TextOut(1600,  y + begin, m_setvoucher.m_names);
	y += 120;
	pDC->TextOut(140,  y + begin, "NUMBER  OF  PERSONS:");
	pDC->TextOut(1600,  y + begin, MaakStr(m_setvoucher.m_pax));
	if (m_setvoucher.m_frees)
		pDC->TextOut(1700,  y + begin, " + " + MaakStr(m_setvoucher.m_frees));

	y += 360;

	pDC->Rectangle(40, 4780 + begin, 3500, 5020 + begin);
	pDC->TextOut(140,  y + begin, "IN  EXCHANGE  OF  THIS  VOUCHER  PLEASE  PROVIDE:");


	y += 240;
	
	pDC->TextOut(140,  y + begin, m_serviceregel1);
	y += 120;
	pDC->TextOut(140,  y + begin, m_serviceregel2);
	y += 120;
	pDC->TextOut(140,  y + begin, m_serviceregel3);
	y += 120;
	pDC->TextOut(140,  y + begin, m_serviceregel4);
	y += 120;
	pDC->TextOut(140,  y + begin, m_serviceregel5);
	y += 120;
	pDC->TextOut(140,  y + begin, m_serviceregel6);
	y += 120;
	pDC->TextOut(140,  y + begin, m_serviceregel7);
	y += 120;
	pDC->TextOut(140,  y + begin, m_serviceregel8);
	y += 360;

	pDC->TextOut(2500,  y + begin, "For  Via  Travel");
	y += 120;
	pDC->TextOut(2500,  y + begin, m_setvoucher.m_us_name);

	m_setvoucher.Close();
//	m_setusers.Close();
}

CString CBookingsView::MaakStr(int getal)
{
	char getal_char[4];

	if (getal == 0 || getal > 1000)
		return "0";
	else
		itoa(getal, getal_char, 10);

	return (CString) getal_char;
}

CString CBookingsView::MaakStr(double getal)
{
	int i, j;
	char getal_char[6];
	int x1;

	x1 = getal * 100;

	itoa(x1, getal_char, 10);
	for (i = 0; getal_char[i] != '\0'; i++);
	for (j = i+1; j >= i - 1; j--)
		getal_char[j] = getal_char[j-1];
	getal_char[j] = '.';

	return (CString) getal_char;
}

void CBookingsView::OnAccel32806() 
{
	// TODO: Add your command handler code here
	int selectie = m_tab.GetCurSel();

	switch(selectie)
	{
	case 0: f_tab2();
			m_tabkeuze = 2;
			m_tab.SetCurSel(1);
		break;
	case 1: f_tab3();
			m_tabkeuze = 3;
			m_tab.SetCurSel(2);
		break;
	case 2: f_tab4();
			m_tabkeuze = 4;
			m_tab.SetCurSel(3);
		break;
	case 3: f_tab1();
			m_tabkeuze = 1;
			m_tab.SetCurSel(0);
		break;
	}
}

void CBookingsView::OnRoperiode0Button() 
{
	// TODO: Add your control notification handler code here
	
	int i;

	m_buttoncheck = FALSE;

	for (i = 0; i < 10; i++)
	{
		m_roasingles[i] = 0;
		m_roatwinsingles[i] = 0;
		m_roatwins[i] = 0;
		m_roadoubles[i] = 0;
		m_roatriples[i] = 0;
		m_roaquads[i] = 0;
		m_roamultiples[i] = 0;
		m_roesingles[i] = 0;
		m_roetwinsingles[i] = 0;
		m_roetwins[i] = 0;
		m_roedoubles[i] = 0;
		m_roetriples[i] = 0;
		m_roequads[i] = 0;
		m_roemultiples[i] = 0;
		m_rocsingles[i] = 0;
		m_roctwinsingles[i] = 0;
		m_roctwins[i] = 0;
		m_rocdoubles[i] = 0;
		m_roctriples[i] = 0;
		m_rocquads[i] = 0;
		m_rocmultiples[i] = 0;
	}

	CString getalstr;

	UpdateData(TRUE);

	m_roperiode1 = FALSE;
	m_roperiode2 = FALSE;
	m_roperiode3 = FALSE;
	m_roperiode4 = FALSE;
	m_roperiode5 = FALSE;
	m_roperiode6 = FALSE;
	m_roperiode7 = FALSE;
	m_roperiode8 = FALSE;
	m_roperiode9 = FALSE;
	m_roperiode10 = FALSE;

	m_robuttonnr = "0";

	if (m_roadoubles[0] != 0)
	{
		getalstr.Format("%d", m_roadoubles[0]);
		m_stradoubles = getalstr;
	}
	else
		m_stradoubles = "";

	if (m_roaquads[0] != 0)
	{
		getalstr.Format("%d", m_roaquads[0]);
		m_straquads  = getalstr;
	}
	else
		m_straquads  = "";
	
	if (m_roasingles[0] != 0)
	{
		getalstr.Format("%d", m_roasingles[0]);
		m_strasingles = getalstr;
	}
	else
		m_strasingles = "";
	
	if (m_roatriples[0] != 0)
	{
		getalstr.Format("%d", m_roatriples[0]);
		m_stratriples = getalstr;
	}
	else
		m_stratriples = "";
	
	if (m_roamultiples[0] != 0)
	{
		getalstr.Format("%d", m_roamultiples[0]);
		m_stramultiples = getalstr;
	}
	else
		m_stramultiples = "";
	
	if (m_roatwins[0] != 0)
	{
		getalstr.Format("%d", m_roatwins[0]);
		m_stratwins = getalstr;
	}
	else
		m_stratwins = "";
	
	if (m_roatwinsingles[0] != 0)
	{
		getalstr.Format("%d", m_roatwinsingles[0]);
		m_stratwinsingles = getalstr;
	}
	else
		m_stratwinsingles = "";
	
	if (m_roedoubles[0] != 0)
	{
		getalstr.Format("%d", m_roedoubles[0]);
		m_stredoubles = getalstr;
	}
	else
		m_stredoubles = "";
	
	if (m_roequads[0] != 0)
	{
		getalstr.Format("%d", m_roequads[0]);
		m_strequads = getalstr;
	}
	else
		m_strequads = "";
	
	if (m_roesingles[0] != 0)
	{
		getalstr.Format("%d", m_roesingles[0]);
		m_stresingles = getalstr;
	}
	else
		m_stresingles = "";
	
	if (m_roetriples[0] != 0)
	{
		getalstr.Format("%d", m_roetriples[0]);
		m_stretriples = getalstr;
	}
	else
		m_stretriples = "";
	
	if (m_roemultiples[0] != 0)
	{
		getalstr.Format("%d", m_roemultiples[0]);
		m_stremultiples = getalstr;
	}
	else
		m_stremultiples = "";
	
	if (m_roetwins[0] != 0)
	{
		getalstr.Format("%d", m_roetwins[0]);
		m_stretwins = getalstr;
	}
	else
		m_stretwins = "";
	
	if (m_roetwinsingles[0] != 0)
	{
		getalstr.Format("%d", m_roetwinsingles[0]);
		m_stretwinsingles = getalstr;
	}
	else
		m_stretwinsingles = "";
	
	if (m_roctwinsingles[0] != 0)
	{
		getalstr.Format("%d", m_roctwinsingles[0]);
		m_strctwinsingles = getalstr;
	}
	else
		m_strctwinsingles = "";
	
	if (m_roctwins[0] != 0)
	{
		getalstr.Format("%d", m_roctwins[0]);
		m_strctwins = getalstr;
	}
	else
		m_strctwins = "";
	
	if (m_rocdoubles[0] != 0)
	{
		getalstr.Format("%d", m_rocdoubles[0]);
		m_strcdoubles = getalstr;
	}
	else
		m_strcdoubles = "";
	
	if (m_rocquads[0] != 0)
	{
		getalstr.Format("%d", m_rocquads[0]);
		m_strcquads = getalstr;
	}
	else
		m_strcquads = "";

	if (m_rocsingles[0] != 0)
	{
		getalstr.Format("%d", m_rocsingles[0]);
		m_strcsingles = getalstr;
	}
	else
		m_strcsingles = "";
	
	if (m_rocmultiples[0] != 0)
	{
		getalstr.Format("%d", m_rocmultiples[0]);
		m_strcmultiples = getalstr;
	}
	else
		m_strcmultiples = "";

	if (m_roctriples[0] != 0)
	{
		getalstr.Format("%d", m_roctriples[0]);
		m_strctriples = getalstr;
	}
	else
		m_strctriples = "";

	m_periode = 0;
	m_nuldeperiode = TRUE;

	UpdateData(FALSE);
}

void CBookingsView::OnRoperiode1Button() 
{
	// TODO: Add your control notification handler code here

	char invoer[4], invoer2[4];

	if (!m_buttoncheck)
	{
	CEdit *invoerveld = (CEdit *) GetDlgItem(IDC_ROCSINGLES_EDIT);
	invoerveld->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld2 = (CEdit *) GetDlgItem(IDC_ROASINGLES_EDIT);
	invoerveld2->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roasingles[m_periode] = atoi(invoer);

	CEdit *invoerveld3 = (CEdit *) GetDlgItem(IDC_ROESINGLES_EDIT);
	invoerveld3->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roesingles[m_periode] = atoi(invoer);

	CEdit *invoerveld4 = (CEdit *) GetDlgItem(IDC_ROATWINSINGLES_EDIT);
	invoerveld4->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld5 = (CEdit *) GetDlgItem(IDC_ROETWINSINGLES_EDIT);
	invoerveld5->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld6 = (CEdit *) GetDlgItem(IDC_ROCTWINSINGLES_EDIT);
	invoerveld6->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld7 = (CEdit *) GetDlgItem(IDC_ROATWINS_EDIT);
	invoerveld7->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwins[m_periode] = atoi(invoer);

	CEdit *invoerveld8 = (CEdit *) GetDlgItem(IDC_ROETWINS_EDIT);
	invoerveld8->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwins[m_periode] = atoi(invoer);

	CEdit *invoerveld9 = (CEdit *) GetDlgItem(IDC_ROCTWINS_EDIT);
	invoerveld9->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwins[m_periode] = atoi(invoer);

	CEdit *invoerveld10 = (CEdit *) GetDlgItem(IDC_ROADOUBLES_EDIT);
	invoerveld10->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roadoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld11 = (CEdit *) GetDlgItem(IDC_ROEDOUBLES_EDIT);
	invoerveld11->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roedoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld12 = (CEdit *) GetDlgItem(IDC_ROCDOUBLES_EDIT);
	invoerveld12->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocdoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld13 = (CEdit *) GetDlgItem(IDC_ROATRIPLES_EDIT);
	invoerveld13->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatriples[m_periode] = atoi(invoer);

	CEdit *invoerveld14 = (CEdit *) GetDlgItem(IDC_ROETRIPLES_EDIT);
	invoerveld14->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetriples[m_periode] = atoi(invoer);

	CEdit *invoerveld15 = (CEdit *) GetDlgItem(IDC_ROCTRIPLES_EDIT);
	invoerveld15->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctriples[m_periode] = atoi(invoer);

	CEdit *invoerveld16 = (CEdit *) GetDlgItem(IDC_ROAQUADS_EDIT);
	invoerveld16->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roaquads[m_periode] = atoi(invoer);

	CEdit *invoerveld17 = (CEdit *) GetDlgItem(IDC_ROEQUADS_EDIT);
	invoerveld17->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roequads[m_periode] = atoi(invoer);

	CEdit *invoerveld18 = (CEdit *) GetDlgItem(IDC_ROCQUADS_EDIT);
	invoerveld18->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocquads[m_periode] = atoi(invoer);

	CEdit *invoerveld19 = (CEdit *) GetDlgItem(IDC_ROAMULTIPLES_EDIT);
	invoerveld19->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roamultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld20 = (CEdit *) GetDlgItem(IDC_ROEMULTIPLES_EDIT);
	invoerveld20->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roemultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld21 = (CEdit *) GetDlgItem(IDC_ROCMULTIPLES_EDIT);
	invoerveld21->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocmultiples[m_periode] = atoi(invoer);
	}

	m_buttoncheck = FALSE;

	CString getalstr;

	UpdateData(TRUE);

	m_roperiode1 = FALSE;
	m_roperiode2 = FALSE;
	m_roperiode3 = FALSE;
	m_roperiode4 = FALSE;
	m_roperiode5 = FALSE;
	m_roperiode6 = FALSE;
	m_roperiode7 = FALSE;
	m_roperiode8 = FALSE;
	m_roperiode9 = FALSE;
	m_roperiode10 = FALSE;

	m_robuttonnr = "1";

	if (m_roadoubles[0] != 0)
	{
		getalstr.Format("%d", m_roadoubles[0]);
		m_stradoubles = getalstr;
	}
	else
		m_stradoubles = "";

	if (m_roaquads[0] != 0)
	{
		getalstr.Format("%d", m_roaquads[0]);
		m_straquads  = getalstr;
	}
	else
		m_straquads  = "";
	
	if (m_roasingles[0] != 0)
	{
		getalstr.Format("%d", m_roasingles[0]);
		m_strasingles = getalstr;
	}
	else
		m_strasingles = "";
	
	if (m_roatriples[0] != 0)
	{
		getalstr.Format("%d", m_roatriples[0]);
		m_stratriples = getalstr;
	}
	else
		m_stratriples = "";
	
	if (m_roamultiples[0] != 0)
	{
		getalstr.Format("%d", m_roamultiples[0]);
		m_stramultiples = getalstr;
	}
	else
		m_stramultiples = "";
	
	if (m_roatwins[0] != 0)
	{
		getalstr.Format("%d", m_roatwins[0]);
		m_stratwins = getalstr;
	}
	else
		m_stratwins = "";
	
	if (m_roatwinsingles[0] != 0)
	{
		getalstr.Format("%d", m_roatwinsingles[0]);
		m_stratwinsingles = getalstr;
	}
	else
		m_stratwinsingles = "";
	
	if (m_roedoubles[0] != 0)
	{
		getalstr.Format("%d", m_roedoubles[0]);
		m_stredoubles = getalstr;
	}
	else
		m_stredoubles = "";
	
	if (m_roequads[0] != 0)
	{
		getalstr.Format("%d", m_roequads[0]);
		m_strequads = getalstr;
	}
	else
		m_strequads = "";
	
	if (m_roesingles[0] != 0)
	{
		getalstr.Format("%d", m_roesingles[0]);
		m_stresingles = getalstr;
	}
	else
		m_stresingles = "";
	
	if (m_roetriples[0] != 0)
	{
		getalstr.Format("%d", m_roetriples[0]);
		m_stretriples = getalstr;
	}
	else
		m_stretriples = "";
	
	if (m_roemultiples[0] != 0)
	{
		getalstr.Format("%d", m_roemultiples[0]);
		m_stremultiples = getalstr;
	}
	else
		m_stremultiples = "";
	
	if (m_roetwins[0] != 0)
	{
		getalstr.Format("%d", m_roetwins[0]);
		m_stretwins = getalstr;
	}
	else
		m_stretwins = "";
	
	if (m_roetwinsingles[0] != 0)
	{
		getalstr.Format("%d", m_roetwinsingles[0]);
		m_stretwinsingles = getalstr;
	}
	else
		m_stretwinsingles = "";
	
	if (m_roctwinsingles[0] != 0)
	{
		getalstr.Format("%d", m_roctwinsingles[0]);
		m_strctwinsingles = getalstr;
	}
	else
		m_strctwinsingles = "";
	
	if (m_roctwins[0] != 0)
	{
		getalstr.Format("%d", m_roctwins[0]);
		m_strctwins = getalstr;
	}
	else
		m_strctwins = "";
	
	if (m_rocdoubles[0] != 0)
	{
		getalstr.Format("%d", m_rocdoubles[0]);
		m_strcdoubles = getalstr;
	}
	else
		m_strcdoubles = "";
	
	if (m_rocquads[0] != 0)
	{
		getalstr.Format("%d", m_rocquads[0]);
		m_strcquads = getalstr;
	}
	else
		m_strcquads = "";

	if (m_rocsingles[0] != 0)
	{
		getalstr.Format("%d", m_rocsingles[0]);
		m_strcsingles = getalstr;
	}
	else
		m_strcsingles = "";
	
	if (m_rocmultiples[0] != 0)
	{
		getalstr.Format("%d", m_rocmultiples[0]);
		m_strcmultiples = getalstr;
	}
	else
		m_strcmultiples = "";

	if (m_roctriples[0] != 0)
	{
		getalstr.Format("%d", m_roctriples[0]);
		m_strctriples = getalstr;
	}
	else
		m_strctriples = "";

	m_periode = 0;
	m_nuldeperiode = FALSE;

	UpdateData(FALSE);
}

void CBookingsView::OnRoperiode2Button() 
{
	// TODO: Add your control notification handler code here
	
	char invoer[4], invoer2[4];

	if (!m_buttoncheck)
	{
	CEdit *invoerveld = (CEdit *) GetDlgItem(IDC_ROCSINGLES_EDIT);
	invoerveld->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld2 = (CEdit *) GetDlgItem(IDC_ROASINGLES_EDIT);
	invoerveld2->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roasingles[m_periode] = atoi(invoer);

	CEdit *invoerveld3 = (CEdit *) GetDlgItem(IDC_ROESINGLES_EDIT);
	invoerveld3->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roesingles[m_periode] = atoi(invoer);

	CEdit *invoerveld4 = (CEdit *) GetDlgItem(IDC_ROATWINSINGLES_EDIT);
	invoerveld4->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld5 = (CEdit *) GetDlgItem(IDC_ROETWINSINGLES_EDIT);
	invoerveld5->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld6 = (CEdit *) GetDlgItem(IDC_ROCTWINSINGLES_EDIT);
	invoerveld6->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld7 = (CEdit *) GetDlgItem(IDC_ROATWINS_EDIT);
	invoerveld7->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwins[m_periode] = atoi(invoer);

	CEdit *invoerveld8 = (CEdit *) GetDlgItem(IDC_ROETWINS_EDIT);
	invoerveld8->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwins[m_periode] = atoi(invoer);

	CEdit *invoerveld9 = (CEdit *) GetDlgItem(IDC_ROCTWINS_EDIT);
	invoerveld9->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwins[m_periode] = atoi(invoer);

	CEdit *invoerveld10 = (CEdit *) GetDlgItem(IDC_ROADOUBLES_EDIT);
	invoerveld10->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roadoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld11 = (CEdit *) GetDlgItem(IDC_ROEDOUBLES_EDIT);
	invoerveld11->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roedoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld12 = (CEdit *) GetDlgItem(IDC_ROCDOUBLES_EDIT);
	invoerveld12->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocdoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld13 = (CEdit *) GetDlgItem(IDC_ROATRIPLES_EDIT);
	invoerveld13->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatriples[m_periode] = atoi(invoer);

	CEdit *invoerveld14 = (CEdit *) GetDlgItem(IDC_ROETRIPLES_EDIT);
	invoerveld14->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetriples[m_periode] = atoi(invoer);

	CEdit *invoerveld15 = (CEdit *) GetDlgItem(IDC_ROCTRIPLES_EDIT);
	invoerveld15->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctriples[m_periode] = atoi(invoer);

	CEdit *invoerveld16 = (CEdit *) GetDlgItem(IDC_ROAQUADS_EDIT);
	invoerveld16->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roaquads[m_periode] = atoi(invoer);

	CEdit *invoerveld17 = (CEdit *) GetDlgItem(IDC_ROEQUADS_EDIT);
	invoerveld17->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roequads[m_periode] = atoi(invoer);

	CEdit *invoerveld18 = (CEdit *) GetDlgItem(IDC_ROCQUADS_EDIT);
	invoerveld18->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocquads[m_periode] = atoi(invoer);

	CEdit *invoerveld19 = (CEdit *) GetDlgItem(IDC_ROAMULTIPLES_EDIT);
	invoerveld19->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roamultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld20 = (CEdit *) GetDlgItem(IDC_ROEMULTIPLES_EDIT);
	invoerveld20->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roemultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld21 = (CEdit *) GetDlgItem(IDC_ROCMULTIPLES_EDIT);
	invoerveld21->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocmultiples[m_periode] = atoi(invoer);
	}

	m_buttoncheck = FALSE;

	CString getalstr;
	CDatecnv   m_datecnv;

	UpdateData(TRUE);

	m_roperiode1 = FALSE;
	m_roperiode2 = FALSE;
	m_roperiode3 = FALSE;
	m_roperiode4 = FALSE;
	m_roperiode5 = FALSE;
	m_roperiode6 = FALSE;
	m_roperiode7 = FALSE;
	m_roperiode8 = FALSE;
	m_roperiode9 = FALSE;
	m_roperiode10 = FALSE;

	m_robuttonnr = "2";

	if (m_roadoubles[1] != 0)
	{
		getalstr.Format("%d", m_roadoubles[1]);
		m_stradoubles = getalstr;
	}
	else
		m_stradoubles = "";

	if (m_roaquads[1] != 0)
	{
		getalstr.Format("%d", m_roaquads[1]);
		m_straquads  = getalstr;
	}
	else
		m_straquads  = "";
	
	if (m_roasingles[1] != 0)
	{
		getalstr.Format("%d", m_roasingles[1]);
		m_strasingles = getalstr;
	}
	else
		m_strasingles = "";
	
	if (m_roatriples[1] != 0)
	{
		getalstr.Format("%d", m_roatriples[1]);
		m_stratriples = getalstr;
	}
	else
		m_stratriples = "";
	
	if (m_roamultiples[1] != 0)
	{
		getalstr.Format("%d", m_roamultiples[1]);
		m_stramultiples = getalstr;
	}
	else
		m_stramultiples = "";
	
	if (m_roatwins[1] != 0)
	{
		getalstr.Format("%d", m_roatwins[1]);
		m_stratwins = getalstr;
	}
	else
		m_stratwins = "";
	
	if (m_roatwinsingles[1] != 0)
	{
		getalstr.Format("%d", m_roatwinsingles[1]);
		m_stratwinsingles = getalstr;
	}
	else
		m_stratwinsingles = "";
	
	if (m_roedoubles[1] != 0)
	{
		getalstr.Format("%d", m_roedoubles[1]);
		m_stredoubles = getalstr;
	}
	else
		m_stredoubles = "";
	
	if (m_roequads[1] != 0)
	{
		getalstr.Format("%d", m_roequads[1]);
		m_strequads = getalstr;
	}
	else
		m_strequads = "";
	
	if (m_roesingles[1] != 0)
	{
		getalstr.Format("%d", m_roesingles[1]);
		m_stresingles = getalstr;
	}
	else
		m_stresingles = "";
	
	if (m_roetriples[1] != 0)
	{
		getalstr.Format("%d", m_roetriples[1]);
		m_stretriples = getalstr;
	}
	else
		m_stretriples = "";
	
	if (m_roemultiples[1] != 0)
	{
		getalstr.Format("%d", m_roemultiples[1]);
		m_stremultiples = getalstr;
	}
	else
		m_stremultiples = "";
	
	if (m_roetwins[1] != 0)
	{
		getalstr.Format("%d", m_roetwins[1]);
		m_stretwins = getalstr;
	}
	else
		m_stretwins = "";
	
	if (m_roetwinsingles[1] != 0)
	{
		getalstr.Format("%d", m_roetwinsingles[1]);
		m_stretwinsingles = getalstr;
	}
	else
		m_stretwinsingles = "";
	
	if (m_roctwinsingles[1] != 0)
	{
		getalstr.Format("%d", m_roctwinsingles[1]);
		m_strctwinsingles = getalstr;
	}
	else
		m_strctwinsingles = "";
	
	if (m_roctwins[1] != 0)
	{
		getalstr.Format("%d", m_roctwins[1]);
		m_strctwins = getalstr;
	}
	else
		m_strctwins = "";
	
	if (m_rocdoubles[1] != 0)
	{
		getalstr.Format("%d", m_rocdoubles[1]);
		m_strcdoubles = getalstr;
	}
	else
		m_strcdoubles = "";
	
	if (m_rocquads[1] != 0)
	{
		getalstr.Format("%d", m_rocquads[1]);
		m_strcquads = getalstr;
	}
	else
		m_strcquads = "";

	if (m_rocsingles[1] != 0)
	{
		getalstr.Format("%d", m_rocsingles[1]);
		m_strcsingles = getalstr;
	}
	else
		m_strcsingles = "";
	
	if (m_rocmultiples[1] != 0)
	{
		getalstr.Format("%d", m_rocmultiples[1]);
		m_strcmultiples = getalstr;
	}
	else
		m_strcmultiples = "";

	if (m_roctriples[1] != 0)
	{
		getalstr.Format("%d", m_roctriples[1]);
		m_strctriples = getalstr;
	}
	else
		m_strctriples = "";

	m_periode = 1;
	m_nuldeperiode = FALSE;

	UpdateData(FALSE);
}

void CBookingsView::OnRoperiode3Button() 
{
	// TODO: Add your control notification handler code here

	char invoer[4], invoer2[4];

	if(!m_buttoncheck)
	{
	CEdit *invoerveld = (CEdit *) GetDlgItem(IDC_ROCSINGLES_EDIT);
	invoerveld->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld2 = (CEdit *) GetDlgItem(IDC_ROASINGLES_EDIT);
	invoerveld2->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roasingles[m_periode] = atoi(invoer);

	CEdit *invoerveld3 = (CEdit *) GetDlgItem(IDC_ROESINGLES_EDIT);
	invoerveld3->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roesingles[m_periode] = atoi(invoer);

	CEdit *invoerveld4 = (CEdit *) GetDlgItem(IDC_ROATWINSINGLES_EDIT);
	invoerveld4->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld5 = (CEdit *) GetDlgItem(IDC_ROETWINSINGLES_EDIT);
	invoerveld5->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld6 = (CEdit *) GetDlgItem(IDC_ROCTWINSINGLES_EDIT);
	invoerveld6->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld7 = (CEdit *) GetDlgItem(IDC_ROATWINS_EDIT);
	invoerveld7->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwins[m_periode] = atoi(invoer);

	CEdit *invoerveld8 = (CEdit *) GetDlgItem(IDC_ROETWINS_EDIT);
	invoerveld8->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwins[m_periode] = atoi(invoer);

	CEdit *invoerveld9 = (CEdit *) GetDlgItem(IDC_ROCTWINS_EDIT);
	invoerveld9->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwins[m_periode] = atoi(invoer);

	CEdit *invoerveld10 = (CEdit *) GetDlgItem(IDC_ROADOUBLES_EDIT);
	invoerveld10->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roadoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld11 = (CEdit *) GetDlgItem(IDC_ROEDOUBLES_EDIT);
	invoerveld11->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roedoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld12 = (CEdit *) GetDlgItem(IDC_ROCDOUBLES_EDIT);
	invoerveld12->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocdoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld13 = (CEdit *) GetDlgItem(IDC_ROATRIPLES_EDIT);
	invoerveld13->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatriples[m_periode] = atoi(invoer);

	CEdit *invoerveld14 = (CEdit *) GetDlgItem(IDC_ROETRIPLES_EDIT);
	invoerveld14->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetriples[m_periode] = atoi(invoer);

	CEdit *invoerveld15 = (CEdit *) GetDlgItem(IDC_ROCTRIPLES_EDIT);
	invoerveld15->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctriples[m_periode] = atoi(invoer);

	CEdit *invoerveld16 = (CEdit *) GetDlgItem(IDC_ROAQUADS_EDIT);
	invoerveld16->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roaquads[m_periode] = atoi(invoer);

	CEdit *invoerveld17 = (CEdit *) GetDlgItem(IDC_ROEQUADS_EDIT);
	invoerveld17->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roequads[m_periode] = atoi(invoer);

	CEdit *invoerveld18 = (CEdit *) GetDlgItem(IDC_ROCQUADS_EDIT);
	invoerveld18->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocquads[m_periode] = atoi(invoer);

	CEdit *invoerveld19 = (CEdit *) GetDlgItem(IDC_ROAMULTIPLES_EDIT);
	invoerveld19->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roamultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld20 = (CEdit *) GetDlgItem(IDC_ROEMULTIPLES_EDIT);
	invoerveld20->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roemultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld21 = (CEdit *) GetDlgItem(IDC_ROCMULTIPLES_EDIT);
	invoerveld21->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocmultiples[m_periode] = atoi(invoer);
	}

	m_buttoncheck = FALSE;

	CString getalstr;

	UpdateData(TRUE);

	m_roperiode1 = FALSE;
	m_roperiode2 = FALSE;
	m_roperiode3 = FALSE;
	m_roperiode4 = FALSE;
	m_roperiode5 = FALSE;
	m_roperiode6 = FALSE;
	m_roperiode7 = FALSE;
	m_roperiode8 = FALSE;
	m_roperiode9 = FALSE;
	m_roperiode10 = FALSE;

	m_robuttonnr = "3";

	if (m_roadoubles[2] != 0)
	{
		getalstr.Format("%d", m_roadoubles[2]);
		m_stradoubles = getalstr;
	}
	else
		m_stradoubles = "";

	if (m_roaquads[2] != 0)
	{
		getalstr.Format("%d", m_roaquads[2]);
		m_straquads  = getalstr;
	}
	else
		m_straquads  = "";
	
	if (m_roasingles[2] != 0)
	{
		getalstr.Format("%d", m_roasingles[2]);
		m_strasingles = getalstr;
	}
	else
		m_strasingles = "";
	
	if (m_roatriples[2] != 0)
	{
		getalstr.Format("%d", m_roatriples[2]);
		m_stratriples = getalstr;
	}
	else
		m_stratriples = "";
	
	if (m_roamultiples[2] != 0)
	{
		getalstr.Format("%d", m_roamultiples[2]);
		m_stramultiples = getalstr;
	}
	else
		m_stramultiples = "";
	
	if (m_roatwins[2] != 0)
	{
		getalstr.Format("%d", m_roatwins[2]);
		m_stratwins = getalstr;
	}
	else
		m_stratwins = "";
	
	if (m_roatwinsingles[2] != 0)
	{
		getalstr.Format("%d", m_roatwinsingles[2]);
		m_stratwinsingles = getalstr;
	}
	else
		m_stratwinsingles = "";
	
	if (m_roedoubles[2] != 0)
	{
		getalstr.Format("%d", m_roedoubles[2]);
		m_stredoubles = getalstr;
	}
	else
		m_stredoubles = "";
	
	if (m_roequads[2] != 0)
	{
		getalstr.Format("%d", m_roequads[2]);
		m_strequads = getalstr;
	}
	else
		m_strequads = "";
	
	if (m_roesingles[2] != 0)
	{
		getalstr.Format("%d", m_roesingles[2]);
		m_stresingles = getalstr;
	}
	else
		m_stresingles = "";
	
	if (m_roetriples[2] != 0)
	{
		getalstr.Format("%d", m_roetriples[2]);
		m_stretriples = getalstr;
	}
	else
		m_stretriples = "";
	
	if (m_roemultiples[2] != 0)
	{
		getalstr.Format("%d", m_roemultiples[2]);
		m_stremultiples = getalstr;
	}
	else
		m_stremultiples = "";
	
	if (m_roetwins[2] != 0)
	{
		getalstr.Format("%d", m_roetwins[2]);
		m_stretwins = getalstr;
	}
	else
		m_stretwins = "";
	
	if (m_roetwinsingles[2] != 0)
	{
		getalstr.Format("%d", m_roetwinsingles[2]);
		m_stretwinsingles = getalstr;
	}
	else
		m_stretwinsingles = "";
	
	if (m_roctwinsingles[2] != 0)
	{
		getalstr.Format("%d", m_roctwinsingles[2]);
		m_strctwinsingles = getalstr;
	}
	else
		m_strctwinsingles = "";
	
	if (m_roctwins[2] != 0)
	{
		getalstr.Format("%d", m_roctwins[2]);
		m_strctwins = getalstr;
	}
	else
		m_strctwins = "";
	
	if (m_rocdoubles[2] != 0)
	{
		getalstr.Format("%d", m_rocdoubles[2]);
		m_strcdoubles = getalstr;
	}
	else
		m_strcdoubles = "";
	
	if (m_rocquads[2] != 0)
	{
		getalstr.Format("%d", m_rocquads[2]);
		m_strcquads = getalstr;
	}
	else
		m_strcquads = "";

	if (m_rocsingles[2] != 0)
	{
		getalstr.Format("%d", m_rocsingles[2]);
		m_strcsingles = getalstr;
	}
	else
		m_strcsingles = "";
	
	if (m_rocmultiples[2] != 0)
	{
		getalstr.Format("%d", m_rocmultiples[2]);
		m_strcmultiples = getalstr;
	}
	else
		m_strcmultiples = "";

	if (m_roctriples[2] != 0)
	{
		getalstr.Format("%d", m_roctriples[2]);
		m_strctriples = getalstr;
	}
	else
		m_strctriples = "";

	m_periode = 2;
	m_nuldeperiode = FALSE;

	UpdateData(FALSE);
}

void CBookingsView::OnRoperiode4Button() 
{
	// TODO: Add your control notification handler code here
	
	char invoer[4], invoer2[4];

	if(!m_buttoncheck)
	{
	CEdit *invoerveld = (CEdit *) GetDlgItem(IDC_ROCSINGLES_EDIT);
	invoerveld->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld2 = (CEdit *) GetDlgItem(IDC_ROASINGLES_EDIT);
	invoerveld2->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roasingles[m_periode] = atoi(invoer);

	CEdit *invoerveld3 = (CEdit *) GetDlgItem(IDC_ROESINGLES_EDIT);
	invoerveld3->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roesingles[m_periode] = atoi(invoer);

	CEdit *invoerveld4 = (CEdit *) GetDlgItem(IDC_ROATWINSINGLES_EDIT);
	invoerveld4->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld5 = (CEdit *) GetDlgItem(IDC_ROETWINSINGLES_EDIT);
	invoerveld5->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld6 = (CEdit *) GetDlgItem(IDC_ROCTWINSINGLES_EDIT);
	invoerveld6->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld7 = (CEdit *) GetDlgItem(IDC_ROATWINS_EDIT);
	invoerveld7->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwins[m_periode] = atoi(invoer);

	CEdit *invoerveld8 = (CEdit *) GetDlgItem(IDC_ROETWINS_EDIT);
	invoerveld8->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwins[m_periode] = atoi(invoer);

	CEdit *invoerveld9 = (CEdit *) GetDlgItem(IDC_ROCTWINS_EDIT);
	invoerveld9->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwins[m_periode] = atoi(invoer);

	CEdit *invoerveld10 = (CEdit *) GetDlgItem(IDC_ROADOUBLES_EDIT);
	invoerveld10->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roadoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld11 = (CEdit *) GetDlgItem(IDC_ROEDOUBLES_EDIT);
	invoerveld11->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roedoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld12 = (CEdit *) GetDlgItem(IDC_ROCDOUBLES_EDIT);
	invoerveld12->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocdoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld13 = (CEdit *) GetDlgItem(IDC_ROATRIPLES_EDIT);
	invoerveld13->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatriples[m_periode] = atoi(invoer);

	CEdit *invoerveld14 = (CEdit *) GetDlgItem(IDC_ROETRIPLES_EDIT);
	invoerveld14->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetriples[m_periode] = atoi(invoer);

	CEdit *invoerveld15 = (CEdit *) GetDlgItem(IDC_ROCTRIPLES_EDIT);
	invoerveld15->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctriples[m_periode] = atoi(invoer);

	CEdit *invoerveld16 = (CEdit *) GetDlgItem(IDC_ROAQUADS_EDIT);
	invoerveld16->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roaquads[m_periode] = atoi(invoer);

	CEdit *invoerveld17 = (CEdit *) GetDlgItem(IDC_ROEQUADS_EDIT);
	invoerveld17->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roequads[m_periode] = atoi(invoer);

	CEdit *invoerveld18 = (CEdit *) GetDlgItem(IDC_ROCQUADS_EDIT);
	invoerveld18->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocquads[m_periode] = atoi(invoer);

	CEdit *invoerveld19 = (CEdit *) GetDlgItem(IDC_ROAMULTIPLES_EDIT);
	invoerveld19->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roamultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld20 = (CEdit *) GetDlgItem(IDC_ROEMULTIPLES_EDIT);
	invoerveld20->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roemultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld21 = (CEdit *) GetDlgItem(IDC_ROCMULTIPLES_EDIT);
	invoerveld21->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocmultiples[m_periode] = atoi(invoer);
	}

	m_buttoncheck = FALSE;

	CString getalstr;

	UpdateData(TRUE);

	m_roperiode1 = FALSE;
	m_roperiode2 = FALSE;
	m_roperiode3 = FALSE;
	m_roperiode4 = FALSE;
	m_roperiode5 = FALSE;
	m_roperiode6 = FALSE;
	m_roperiode7 = FALSE;
	m_roperiode8 = FALSE;
	m_roperiode9 = FALSE;
	m_roperiode10 = FALSE;

	m_robuttonnr = "4";

	if (m_roadoubles[3] != 0)
	{
		getalstr.Format("%d", m_roadoubles[3]);
		m_stradoubles = getalstr;
	}
	else
		m_stradoubles = "";

	if (m_roaquads[3] != 0)
	{
		getalstr.Format("%d", m_roaquads[3]);
		m_straquads  = getalstr;
	}
	else
		m_straquads  = "";
	
	if (m_roasingles[3] != 0)
	{
		getalstr.Format("%d", m_roasingles[3]);
		m_strasingles = getalstr;
	}
	else
		m_strasingles = "";
	
	if (m_roatriples[3] != 0)
	{
		getalstr.Format("%d", m_roatriples[3]);
		m_stratriples = getalstr;
	}
	else
		m_stratriples = "";
	
	if (m_roamultiples[3] != 0)
	{
		getalstr.Format("%d", m_roamultiples[3]);
		m_stramultiples = getalstr;
	}
	else
		m_stramultiples = "";
	
	if (m_roatwins[3] != 0)
	{
		getalstr.Format("%d", m_roatwins[3]);
		m_stratwins = getalstr;
	}
	else
		m_stratwins = "";
	
	if (m_roatwinsingles[3] != 0)
	{
		getalstr.Format("%d", m_roatwinsingles[3]);
		m_stratwinsingles = getalstr;
	}
	else
		m_stratwinsingles = "";
	
	if (m_roedoubles[3] != 0)
	{
		getalstr.Format("%d", m_roedoubles[3]);
		m_stredoubles = getalstr;
	}
	else
		m_stredoubles = "";
	
	if (m_roequads[3] != 0)
	{
		getalstr.Format("%d", m_roequads[3]);
		m_strequads = getalstr;
	}
	else
		m_strequads = "";
	
	if (m_roesingles[3] != 0)
	{
		getalstr.Format("%d", m_roesingles[3]);
		m_stresingles = getalstr;
	}
	else
		m_stresingles = "";
	
	if (m_roetriples[3] != 0)
	{
		getalstr.Format("%d", m_roetriples[3]);
		m_stretriples = getalstr;
	}
	else
		m_stretriples = "";
	
	if (m_roemultiples[3] != 0)
	{
		getalstr.Format("%d", m_roemultiples[3]);
		m_stremultiples = getalstr;
	}
	else
		m_stremultiples = "";
	
	if (m_roetwins[3] != 0)
	{
		getalstr.Format("%d", m_roetwins[3]);
		m_stretwins = getalstr;
	}
	else
		m_stretwins = "";
	
	if (m_roetwinsingles[3] != 0)
	{
		getalstr.Format("%d", m_roetwinsingles[3]);
		m_stretwinsingles = getalstr;
	}
	else
		m_stretwinsingles = "";
	
	if (m_roctwinsingles[3] != 0)
	{
		getalstr.Format("%d", m_roctwinsingles[3]);
		m_strctwinsingles = getalstr;
	}
	else
		m_strctwinsingles = "";
	
	if (m_roctwins[3] != 0)
	{
		getalstr.Format("%d", m_roctwins[3]);
		m_strctwins = getalstr;
	}
	else
		m_strctwins = "";
	
	if (m_rocdoubles[3] != 0)
	{
		getalstr.Format("%d", m_rocdoubles[3]);
		m_strcdoubles = getalstr;
	}
	else
		m_strcdoubles = "";
	
	if (m_rocquads[3] != 0)
	{
		getalstr.Format("%d", m_rocquads[3]);
		m_strcquads = getalstr;
	}
	else
		m_strcquads = "";

	if (m_rocsingles[3] != 0)
	{
		getalstr.Format("%d", m_rocsingles[3]);
		m_strcsingles = getalstr;
	}
	else
		m_strcsingles = "";
	
	if (m_rocmultiples[3] != 0)
	{
		getalstr.Format("%d", m_rocmultiples[3]);
		m_strcmultiples = getalstr;
	}
	else
		m_strcmultiples = "";

	if (m_roctriples[3] != 0)
	{
		getalstr.Format("%d", m_roctriples[3]);
		m_strctriples = getalstr;
	}
	else
		m_strctriples = "";

	m_periode = 3;
	m_nuldeperiode = FALSE;

	UpdateData(FALSE);
}

void CBookingsView::OnRoperiode5Button() 
{
	// TODO: Add your control notification handler code here
	
	char invoer[4], invoer2[4];

	if(!m_buttoncheck)
	{
	CEdit *invoerveld = (CEdit *) GetDlgItem(IDC_ROCSINGLES_EDIT);
	invoerveld->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld2 = (CEdit *) GetDlgItem(IDC_ROASINGLES_EDIT);
	invoerveld2->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roasingles[m_periode] = atoi(invoer);

	CEdit *invoerveld3 = (CEdit *) GetDlgItem(IDC_ROESINGLES_EDIT);
	invoerveld3->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roesingles[m_periode] = atoi(invoer);

	CEdit *invoerveld4 = (CEdit *) GetDlgItem(IDC_ROATWINSINGLES_EDIT);
	invoerveld4->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld5 = (CEdit *) GetDlgItem(IDC_ROETWINSINGLES_EDIT);
	invoerveld5->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld6 = (CEdit *) GetDlgItem(IDC_ROCTWINSINGLES_EDIT);
	invoerveld6->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld7 = (CEdit *) GetDlgItem(IDC_ROATWINS_EDIT);
	invoerveld7->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwins[m_periode] = atoi(invoer);

	CEdit *invoerveld8 = (CEdit *) GetDlgItem(IDC_ROETWINS_EDIT);
	invoerveld8->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwins[m_periode] = atoi(invoer);

	CEdit *invoerveld9 = (CEdit *) GetDlgItem(IDC_ROCTWINS_EDIT);
	invoerveld9->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwins[m_periode] = atoi(invoer);

	CEdit *invoerveld10 = (CEdit *) GetDlgItem(IDC_ROADOUBLES_EDIT);
	invoerveld10->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roadoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld11 = (CEdit *) GetDlgItem(IDC_ROEDOUBLES_EDIT);
	invoerveld11->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roedoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld12 = (CEdit *) GetDlgItem(IDC_ROCDOUBLES_EDIT);
	invoerveld12->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocdoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld13 = (CEdit *) GetDlgItem(IDC_ROATRIPLES_EDIT);
	invoerveld13->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatriples[m_periode] = atoi(invoer);

	CEdit *invoerveld14 = (CEdit *) GetDlgItem(IDC_ROETRIPLES_EDIT);
	invoerveld14->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetriples[m_periode] = atoi(invoer);

	CEdit *invoerveld15 = (CEdit *) GetDlgItem(IDC_ROCTRIPLES_EDIT);
	invoerveld15->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctriples[m_periode] = atoi(invoer);

	CEdit *invoerveld16 = (CEdit *) GetDlgItem(IDC_ROAQUADS_EDIT);
	invoerveld16->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roaquads[m_periode] = atoi(invoer);

	CEdit *invoerveld17 = (CEdit *) GetDlgItem(IDC_ROEQUADS_EDIT);
	invoerveld17->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roequads[m_periode] = atoi(invoer);

	CEdit *invoerveld18 = (CEdit *) GetDlgItem(IDC_ROCQUADS_EDIT);
	invoerveld18->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocquads[m_periode] = atoi(invoer);

	CEdit *invoerveld19 = (CEdit *) GetDlgItem(IDC_ROAMULTIPLES_EDIT);
	invoerveld19->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roamultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld20 = (CEdit *) GetDlgItem(IDC_ROEMULTIPLES_EDIT);
	invoerveld20->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roemultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld21 = (CEdit *) GetDlgItem(IDC_ROCMULTIPLES_EDIT);
	invoerveld21->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocmultiples[m_periode] = atoi(invoer);
	}

	m_buttoncheck = FALSE;

	CString getalstr;

	UpdateData(TRUE);

	m_roperiode1 = FALSE;
	m_roperiode2 = FALSE;
	m_roperiode3 = FALSE;
	m_roperiode4 = FALSE;
	m_roperiode5 = FALSE;
	m_roperiode6 = FALSE;
	m_roperiode7 = FALSE;
	m_roperiode8 = FALSE;
	m_roperiode9 = FALSE;
	m_roperiode10 = FALSE;

	m_robuttonnr = "5";

	if (m_roadoubles[4] != 0)
	{
		getalstr.Format("%d", m_roadoubles[4]);
		m_stradoubles = getalstr;
	}
	else
		m_stradoubles = "";

	if (m_roaquads[4] != 0)
	{
		getalstr.Format("%d", m_roaquads[4]);
		m_straquads  = getalstr;
	}
	else
		m_straquads  = "";
	
	if (m_roasingles[4] != 0)
	{
		getalstr.Format("%d", m_roasingles[4]);
		m_strasingles = getalstr;
	}
	else
		m_strasingles = "";
	
	if (m_roatriples[4] != 0)
	{
		getalstr.Format("%d", m_roatriples[4]);
		m_stratriples = getalstr;
	}
	else
		m_stratriples = "";
	
	if (m_roamultiples[4] != 0)
	{
		getalstr.Format("%d", m_roamultiples[4]);
		m_stramultiples = getalstr;
	}
	else
		m_stramultiples = "";
	
	if (m_roatwins[4] != 0)
	{
		getalstr.Format("%d", m_roatwins[4]);
		m_stratwins = getalstr;
	}
	else
		m_stratwins = "";
	
	if (m_roatwinsingles[4] != 0)
	{
		getalstr.Format("%d", m_roatwinsingles[4]);
		m_stratwinsingles = getalstr;
	}
	else
		m_stratwinsingles = "";
	
	if (m_roedoubles[4] != 0)
	{
		getalstr.Format("%d", m_roedoubles[4]);
		m_stredoubles = getalstr;
	}
	else
		m_stredoubles = "";
	
	if (m_roequads[4] != 0)
	{
		getalstr.Format("%d", m_roequads[4]);
		m_strequads = getalstr;
	}
	else
		m_strequads = "";
	
	if (m_roesingles[4] != 0)
	{
		getalstr.Format("%d", m_roesingles[4]);
		m_stresingles = getalstr;
	}
	else
		m_stresingles = "";
	
	if (m_roetriples[4] != 0)
	{
		getalstr.Format("%d", m_roetriples[4]);
		m_stretriples = getalstr;
	}
	else
		m_stretriples = "";
	
	if (m_roemultiples[4] != 0)
	{
		getalstr.Format("%d", m_roemultiples[4]);
		m_stremultiples = getalstr;
	}
	else
		m_stremultiples = "";
	
	if (m_roetwins[4] != 0)
	{
		getalstr.Format("%d", m_roetwins[4]);
		m_stretwins = getalstr;
	}
	else
		m_stretwins = "";
	
	if (m_roetwinsingles[4] != 0)
	{
		getalstr.Format("%d", m_roetwinsingles[4]);
		m_stretwinsingles = getalstr;
	}
	else
		m_stretwinsingles = "";
	
	if (m_roctwinsingles[4] != 0)
	{
		getalstr.Format("%d", m_roctwinsingles[4]);
		m_strctwinsingles = getalstr;
	}
	else
		m_strctwinsingles = "";
	
	if (m_roctwins[4] != 0)
	{
		getalstr.Format("%d", m_roctwins[4]);
		m_strctwins = getalstr;
	}
	else
		m_strctwins = "";
	
	if (m_rocdoubles[4] != 0)
	{
		getalstr.Format("%d", m_rocdoubles[4]);
		m_strcdoubles = getalstr;
	}
	else
		m_strcdoubles = "";
	
	if (m_rocquads[4] != 0)
	{
		getalstr.Format("%d", m_rocquads[4]);
		m_strcquads = getalstr;
	}
	else
		m_strcquads = "";

	if (m_rocsingles[4] != 0)
	{
		getalstr.Format("%d", m_rocsingles[4]);
		m_strcsingles = getalstr;
	}
	else
		m_strcsingles = "";
	
	if (m_rocmultiples[4] != 0)
	{
		getalstr.Format("%d", m_rocmultiples[4]);
		m_strcmultiples = getalstr;
	}
	else
		m_strcmultiples = "";

	if (m_roctriples[4] != 0)
	{
		getalstr.Format("%d", m_roctriples[4]);
		m_strctriples = getalstr;
	}
	else
		m_strctriples = "";

	m_periode = 4;
	m_nuldeperiode = FALSE;

	UpdateData(FALSE);
}

void CBookingsView::OnRoperiode6Button() 
{
	// TODO: Add your control notification handler code here
	
	char invoer[4], invoer2[4];

	if(!m_buttoncheck)
	{
	CEdit *invoerveld = (CEdit *) GetDlgItem(IDC_ROCSINGLES_EDIT);
	invoerveld->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld2 = (CEdit *) GetDlgItem(IDC_ROASINGLES_EDIT);
	invoerveld2->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roasingles[m_periode] = atoi(invoer);

	CEdit *invoerveld3 = (CEdit *) GetDlgItem(IDC_ROESINGLES_EDIT);
	invoerveld3->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roesingles[m_periode] = atoi(invoer);

	CEdit *invoerveld4 = (CEdit *) GetDlgItem(IDC_ROATWINSINGLES_EDIT);
	invoerveld4->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld5 = (CEdit *) GetDlgItem(IDC_ROETWINSINGLES_EDIT);
	invoerveld5->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld6 = (CEdit *) GetDlgItem(IDC_ROCTWINSINGLES_EDIT);
	invoerveld6->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld7 = (CEdit *) GetDlgItem(IDC_ROATWINS_EDIT);
	invoerveld7->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwins[m_periode] = atoi(invoer);

	CEdit *invoerveld8 = (CEdit *) GetDlgItem(IDC_ROETWINS_EDIT);
	invoerveld8->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwins[m_periode] = atoi(invoer);

	CEdit *invoerveld9 = (CEdit *) GetDlgItem(IDC_ROCTWINS_EDIT);
	invoerveld9->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwins[m_periode] = atoi(invoer);

	CEdit *invoerveld10 = (CEdit *) GetDlgItem(IDC_ROADOUBLES_EDIT);
	invoerveld10->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roadoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld11 = (CEdit *) GetDlgItem(IDC_ROEDOUBLES_EDIT);
	invoerveld11->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roedoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld12 = (CEdit *) GetDlgItem(IDC_ROCDOUBLES_EDIT);
	invoerveld12->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocdoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld13 = (CEdit *) GetDlgItem(IDC_ROATRIPLES_EDIT);
	invoerveld13->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatriples[m_periode] = atoi(invoer);

	CEdit *invoerveld14 = (CEdit *) GetDlgItem(IDC_ROETRIPLES_EDIT);
	invoerveld14->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetriples[m_periode] = atoi(invoer);

	CEdit *invoerveld15 = (CEdit *) GetDlgItem(IDC_ROCTRIPLES_EDIT);
	invoerveld15->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctriples[m_periode] = atoi(invoer);

	CEdit *invoerveld16 = (CEdit *) GetDlgItem(IDC_ROAQUADS_EDIT);
	invoerveld16->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roaquads[m_periode] = atoi(invoer);

	CEdit *invoerveld17 = (CEdit *) GetDlgItem(IDC_ROEQUADS_EDIT);
	invoerveld17->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roequads[m_periode] = atoi(invoer);

	CEdit *invoerveld18 = (CEdit *) GetDlgItem(IDC_ROCQUADS_EDIT);
	invoerveld18->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocquads[m_periode] = atoi(invoer);

	CEdit *invoerveld19 = (CEdit *) GetDlgItem(IDC_ROAMULTIPLES_EDIT);
	invoerveld19->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roamultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld20 = (CEdit *) GetDlgItem(IDC_ROEMULTIPLES_EDIT);
	invoerveld20->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roemultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld21 = (CEdit *) GetDlgItem(IDC_ROCMULTIPLES_EDIT);
	invoerveld21->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocmultiples[m_periode] = atoi(invoer);
	}

	m_buttoncheck = FALSE;

	CString getalstr;

	UpdateData(TRUE);

	m_roperiode1 = FALSE;
	m_roperiode2 = FALSE;
	m_roperiode3 = FALSE;
	m_roperiode4 = FALSE;
	m_roperiode5 = FALSE;
	m_roperiode6 = FALSE;
	m_roperiode7 = FALSE;
	m_roperiode8 = FALSE;
	m_roperiode9 = FALSE;
	m_roperiode10 = FALSE;

	m_robuttonnr = "6";

	if (m_roadoubles[5] != 0)
	{
		getalstr.Format("%d", m_roadoubles[5]);
		m_stradoubles = getalstr;
	}
	else
		m_stradoubles = "";

	if (m_roaquads[5] != 0)
	{
		getalstr.Format("%d", m_roaquads[5]);
		m_straquads  = getalstr;
	}
	else
		m_straquads  = "";
	
	if (m_roasingles[5] != 0)
	{
		getalstr.Format("%d", m_roasingles[5]);
		m_strasingles = getalstr;
	}
	else
		m_strasingles = "";
	
	if (m_roatriples[5] != 0)
	{
		getalstr.Format("%d", m_roatriples[5]);
		m_stratriples = getalstr;
	}
	else
		m_stratriples = "";
	
	if (m_roamultiples[5] != 0)
	{
		getalstr.Format("%d", m_roamultiples[5]);
		m_stramultiples = getalstr;
	}
	else
		m_stramultiples = "";
	
	if (m_roatwins[5] != 0)
	{
		getalstr.Format("%d", m_roatwins[5]);
		m_stratwins = getalstr;
	}
	else
		m_stratwins = "";
	
	if (m_roatwinsingles[5] != 0)
	{
		getalstr.Format("%d", m_roatwinsingles[5]);
		m_stratwinsingles = getalstr;
	}
	else
		m_stratwinsingles = "";
	
	if (m_roedoubles[5] != 0)
	{
		getalstr.Format("%d", m_roedoubles[5]);
		m_stredoubles = getalstr;
	}
	else
		m_stredoubles = "";
	
	if (m_roequads[5] != 0)
	{
		getalstr.Format("%d", m_roequads[5]);
		m_strequads = getalstr;
	}
	else
		m_strequads = "";
	
	if (m_roesingles[5] != 0)
	{
		getalstr.Format("%d", m_roesingles[5]);
		m_stresingles = getalstr;
	}
	else
		m_stresingles = "";
	
	if (m_roetriples[5] != 0)
	{
		getalstr.Format("%d", m_roetriples[5]);
		m_stretriples = getalstr;
	}
	else
		m_stretriples = "";
	
	if (m_roemultiples[5] != 0)
	{
		getalstr.Format("%d", m_roemultiples[5]);
		m_stremultiples = getalstr;
	}
	else
		m_stremultiples = "";
	
	if (m_roetwins[5] != 0)
	{
		getalstr.Format("%d", m_roetwins[5]);
		m_stretwins = getalstr;
	}
	else
		m_stretwins = "";
	
	if (m_roetwinsingles[5] != 0)
	{
		getalstr.Format("%d", m_roetwinsingles[5]);
		m_stretwinsingles = getalstr;
	}
	else
		m_stretwinsingles = "";
	
	if (m_roctwinsingles[5] != 0)
	{
		getalstr.Format("%d", m_roctwinsingles[5]);
		m_strctwinsingles = getalstr;
	}
	else
		m_strctwinsingles = "";
	
	if (m_roctwins[5] != 0)
	{
		getalstr.Format("%d", m_roctwins[5]);
		m_strctwins = getalstr;
	}
	else
		m_strctwins = "";
	
	if (m_rocdoubles[5] != 0)
	{
		getalstr.Format("%d", m_rocdoubles[5]);
		m_strcdoubles = getalstr;
	}
	else
		m_strcdoubles = "";
	
	if (m_rocquads[5] != 0)
	{
		getalstr.Format("%d", m_rocquads[5]);
		m_strcquads = getalstr;
	}
	else
		m_strcquads = "";

	if (m_rocsingles[5] != 0)
	{
		getalstr.Format("%d", m_rocsingles[5]);
		m_strcsingles = getalstr;
	}
	else
		m_strcsingles = "";
	
	if (m_rocmultiples[5] != 0)
	{
		getalstr.Format("%d", m_rocmultiples[5]);
		m_strcmultiples = getalstr;
	}
	else
		m_strcmultiples = "";

	if (m_roctriples[5] != 0)
	{
		getalstr.Format("%d", m_roctriples[5]);
		m_strctriples = getalstr;
	}
	else
		m_strctriples = "";

	m_periode = 5;
	m_nuldeperiode = FALSE;

	UpdateData(FALSE);
}

void CBookingsView::OnRoperiode7Button() 
{
	// TODO: Add your control notification handler code here
	
	char invoer[4], invoer2[4];

	if(!m_buttoncheck)
	{
	CEdit *invoerveld = (CEdit *) GetDlgItem(IDC_ROCSINGLES_EDIT);
	invoerveld->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld2 = (CEdit *) GetDlgItem(IDC_ROASINGLES_EDIT);
	invoerveld2->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roasingles[m_periode] = atoi(invoer);

	CEdit *invoerveld3 = (CEdit *) GetDlgItem(IDC_ROESINGLES_EDIT);
	invoerveld3->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roesingles[m_periode] = atoi(invoer);

	CEdit *invoerveld4 = (CEdit *) GetDlgItem(IDC_ROATWINSINGLES_EDIT);
	invoerveld4->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld5 = (CEdit *) GetDlgItem(IDC_ROETWINSINGLES_EDIT);
	invoerveld5->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld6 = (CEdit *) GetDlgItem(IDC_ROCTWINSINGLES_EDIT);
	invoerveld6->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld7 = (CEdit *) GetDlgItem(IDC_ROATWINS_EDIT);
	invoerveld7->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwins[m_periode] = atoi(invoer);

	CEdit *invoerveld8 = (CEdit *) GetDlgItem(IDC_ROETWINS_EDIT);
	invoerveld8->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwins[m_periode] = atoi(invoer);

	CEdit *invoerveld9 = (CEdit *) GetDlgItem(IDC_ROCTWINS_EDIT);
	invoerveld9->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwins[m_periode] = atoi(invoer);

	CEdit *invoerveld10 = (CEdit *) GetDlgItem(IDC_ROADOUBLES_EDIT);
	invoerveld10->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roadoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld11 = (CEdit *) GetDlgItem(IDC_ROEDOUBLES_EDIT);
	invoerveld11->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roedoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld12 = (CEdit *) GetDlgItem(IDC_ROCDOUBLES_EDIT);
	invoerveld12->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocdoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld13 = (CEdit *) GetDlgItem(IDC_ROATRIPLES_EDIT);
	invoerveld13->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatriples[m_periode] = atoi(invoer);

	CEdit *invoerveld14 = (CEdit *) GetDlgItem(IDC_ROETRIPLES_EDIT);
	invoerveld14->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetriples[m_periode] = atoi(invoer);

	CEdit *invoerveld15 = (CEdit *) GetDlgItem(IDC_ROCTRIPLES_EDIT);
	invoerveld15->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctriples[m_periode] = atoi(invoer);

	CEdit *invoerveld16 = (CEdit *) GetDlgItem(IDC_ROAQUADS_EDIT);
	invoerveld16->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roaquads[m_periode] = atoi(invoer);

	CEdit *invoerveld17 = (CEdit *) GetDlgItem(IDC_ROEQUADS_EDIT);
	invoerveld17->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roequads[m_periode] = atoi(invoer);

	CEdit *invoerveld18 = (CEdit *) GetDlgItem(IDC_ROCQUADS_EDIT);
	invoerveld18->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocquads[m_periode] = atoi(invoer);

	CEdit *invoerveld19 = (CEdit *) GetDlgItem(IDC_ROAMULTIPLES_EDIT);
	invoerveld19->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roamultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld20 = (CEdit *) GetDlgItem(IDC_ROEMULTIPLES_EDIT);
	invoerveld20->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roemultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld21 = (CEdit *) GetDlgItem(IDC_ROCMULTIPLES_EDIT);
	invoerveld21->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocmultiples[m_periode] = atoi(invoer);
	}

	m_buttoncheck = FALSE;

	CString getalstr;

	UpdateData(TRUE);

	m_roperiode1 = FALSE;
	m_roperiode2 = FALSE;
	m_roperiode3 = FALSE;
	m_roperiode4 = FALSE;
	m_roperiode5 = FALSE;
	m_roperiode6 = FALSE;
	m_roperiode7 = FALSE;
	m_roperiode8 = FALSE;
	m_roperiode9 = FALSE;
	m_roperiode10 = FALSE;

	m_robuttonnr = "7";

	if (m_roadoubles[6] != 0)
	{
		getalstr.Format("%d", m_roadoubles[6]);
		m_stradoubles = getalstr;
	}
	else
		m_stradoubles = "";

	if (m_roaquads[6] != 0)
	{
		getalstr.Format("%d", m_roaquads[6]);
		m_straquads  = getalstr;
	}
	else
		m_straquads  = "";
	
	if (m_roasingles[6] != 0)
	{
		getalstr.Format("%d", m_roasingles[6]);
		m_strasingles = getalstr;
	}
	else
		m_strasingles = "";
	
	if (m_roatriples[6] != 0)
	{
		getalstr.Format("%d", m_roatriples[6]);
		m_stratriples = getalstr;
	}
	else
		m_stratriples = "";
	
	if (m_roamultiples[6] != 0)
	{
		getalstr.Format("%d", m_roamultiples[6]);
		m_stramultiples = getalstr;
	}
	else
		m_stramultiples = "";
	
	if (m_roatwins[6] != 0)
	{
		getalstr.Format("%d", m_roatwins[6]);
		m_stratwins = getalstr;
	}
	else
		m_stratwins = "";
	
	if (m_roatwinsingles[6] != 0)
	{
		getalstr.Format("%d", m_roatwinsingles[6]);
		m_stratwinsingles = getalstr;
	}
	else
		m_stratwinsingles = "";
	
	if (m_roedoubles[6] != 0)
	{
		getalstr.Format("%d", m_roedoubles[6]);
		m_stredoubles = getalstr;
	}
	else
		m_stredoubles = "";
	
	if (m_roequads[6] != 0)
	{
		getalstr.Format("%d", m_roequads[6]);
		m_strequads = getalstr;
	}
	else
		m_strequads = "";
	
	if (m_roesingles[6] != 0)
	{
		getalstr.Format("%d", m_roesingles[6]);
		m_stresingles = getalstr;
	}
	else
		m_stresingles = "";
	
	if (m_roetriples[6] != 0)
	{
		getalstr.Format("%d", m_roetriples[6]);
		m_stretriples = getalstr;
	}
	else
		m_stretriples = "";
	
	if (m_roemultiples[6] != 0)
	{
		getalstr.Format("%d", m_roemultiples[6]);
		m_stremultiples = getalstr;
	}
	else
		m_stremultiples = "";
	
	if (m_roetwins[6] != 0)
	{
		getalstr.Format("%d", m_roetwins[6]);
		m_stretwins = getalstr;
	}
	else
		m_stretwins = "";
	
	if (m_roetwinsingles[6] != 0)
	{
		getalstr.Format("%d", m_roetwinsingles[6]);
		m_stretwinsingles = getalstr;
	}
	else
		m_stretwinsingles = "";
	
	if (m_roctwinsingles[6] != 0)
	{
		getalstr.Format("%d", m_roctwinsingles[6]);
		m_strctwinsingles = getalstr;
	}
	else
		m_strctwinsingles = "";
	
	if (m_roctwins[6] != 0)
	{
		getalstr.Format("%d", m_roctwins[6]);
		m_strctwins = getalstr;
	}
	else
		m_strctwins = "";
	
	if (m_rocdoubles[6] != 0)
	{
		getalstr.Format("%d", m_rocdoubles[6]);
		m_strcdoubles = getalstr;
	}
	else
		m_strcdoubles = "";
	
	if (m_rocquads[6] != 0)
	{
		getalstr.Format("%d", m_rocquads[6]);
		m_strcquads = getalstr;
	}
	else
		m_strcquads = "";

	if (m_rocsingles[6] != 0)
	{
		getalstr.Format("%d", m_rocsingles[6]);
		m_strcsingles = getalstr;
	}
	else
		m_strcsingles = "";
	
	if (m_rocmultiples[6] != 0)
	{
		getalstr.Format("%d", m_rocmultiples[6]);
		m_strcmultiples = getalstr;
	}
	else
		m_strcmultiples = "";

	if (m_roctriples[6] != 0)
	{
		getalstr.Format("%d", m_roctriples[6]);
		m_strctriples = getalstr;
	}
	else
		m_strctriples = "";

	m_periode = 6;
	m_nuldeperiode = FALSE;

	UpdateData(FALSE);
}

void CBookingsView::OnRoperiode8Button() 
{
	// TODO: Add your control notification handler code here
	
	char invoer[4], invoer2[4];

	if(!m_buttoncheck)
	{
	CEdit *invoerveld = (CEdit *) GetDlgItem(IDC_ROCSINGLES_EDIT);
	invoerveld->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld2 = (CEdit *) GetDlgItem(IDC_ROASINGLES_EDIT);
	invoerveld2->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roasingles[m_periode] = atoi(invoer);

	CEdit *invoerveld3 = (CEdit *) GetDlgItem(IDC_ROESINGLES_EDIT);
	invoerveld3->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roesingles[m_periode] = atoi(invoer);

	CEdit *invoerveld4 = (CEdit *) GetDlgItem(IDC_ROATWINSINGLES_EDIT);
	invoerveld4->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld5 = (CEdit *) GetDlgItem(IDC_ROETWINSINGLES_EDIT);
	invoerveld5->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld6 = (CEdit *) GetDlgItem(IDC_ROCTWINSINGLES_EDIT);
	invoerveld6->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld7 = (CEdit *) GetDlgItem(IDC_ROATWINS_EDIT);
	invoerveld7->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwins[m_periode] = atoi(invoer);

	CEdit *invoerveld8 = (CEdit *) GetDlgItem(IDC_ROETWINS_EDIT);
	invoerveld8->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwins[m_periode] = atoi(invoer);

	CEdit *invoerveld9 = (CEdit *) GetDlgItem(IDC_ROCTWINS_EDIT);
	invoerveld9->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwins[m_periode] = atoi(invoer);

	CEdit *invoerveld10 = (CEdit *) GetDlgItem(IDC_ROADOUBLES_EDIT);
	invoerveld10->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roadoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld11 = (CEdit *) GetDlgItem(IDC_ROEDOUBLES_EDIT);
	invoerveld11->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roedoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld12 = (CEdit *) GetDlgItem(IDC_ROCDOUBLES_EDIT);
	invoerveld12->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocdoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld13 = (CEdit *) GetDlgItem(IDC_ROATRIPLES_EDIT);
	invoerveld13->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatriples[m_periode] = atoi(invoer);

	CEdit *invoerveld14 = (CEdit *) GetDlgItem(IDC_ROETRIPLES_EDIT);
	invoerveld14->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetriples[m_periode] = atoi(invoer);

	CEdit *invoerveld15 = (CEdit *) GetDlgItem(IDC_ROCTRIPLES_EDIT);
	invoerveld15->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctriples[m_periode] = atoi(invoer);

	CEdit *invoerveld16 = (CEdit *) GetDlgItem(IDC_ROAQUADS_EDIT);
	invoerveld16->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roaquads[m_periode] = atoi(invoer);

	CEdit *invoerveld17 = (CEdit *) GetDlgItem(IDC_ROEQUADS_EDIT);
	invoerveld17->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roequads[m_periode] = atoi(invoer);

	CEdit *invoerveld18 = (CEdit *) GetDlgItem(IDC_ROCQUADS_EDIT);
	invoerveld18->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocquads[m_periode] = atoi(invoer);

	CEdit *invoerveld19 = (CEdit *) GetDlgItem(IDC_ROAMULTIPLES_EDIT);
	invoerveld19->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roamultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld20 = (CEdit *) GetDlgItem(IDC_ROEMULTIPLES_EDIT);
	invoerveld20->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roemultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld21 = (CEdit *) GetDlgItem(IDC_ROCMULTIPLES_EDIT);
	invoerveld21->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocmultiples[m_periode] = atoi(invoer);
	}

	m_buttoncheck = FALSE;

	CString getalstr;

	UpdateData(TRUE);

	m_roperiode1 = FALSE;
	m_roperiode2 = FALSE;
	m_roperiode3 = FALSE;
	m_roperiode4 = FALSE;
	m_roperiode5 = FALSE;
	m_roperiode6 = FALSE;
	m_roperiode7 = FALSE;
	m_roperiode8 = FALSE;
	m_roperiode9 = FALSE;
	m_roperiode10 = FALSE;

	m_robuttonnr = "8";

	if (m_roadoubles[7] != 0)
	{
		getalstr.Format("%d", m_roadoubles[7]);
		m_stradoubles = getalstr;
	}
	else
		m_stradoubles = "";

	if (m_roaquads[7] != 0)
	{
		getalstr.Format("%d", m_roaquads[7]);
		m_straquads  = getalstr;
	}
	else
		m_straquads  = "";
	
	if (m_roasingles[7] != 0)
	{
		getalstr.Format("%d", m_roasingles[7]);
		m_strasingles = getalstr;
	}
	else
		m_strasingles = "";
	
	if (m_roatriples[7] != 0)
	{
		getalstr.Format("%d", m_roatriples[7]);
		m_stratriples = getalstr;
	}
	else
		m_stratriples = "";
	
	if (m_roamultiples[7] != 0)
	{
		getalstr.Format("%d", m_roamultiples[7]);
		m_stramultiples = getalstr;
	}
	else
		m_stramultiples = "";
	
	if (m_roatwins[7] != 0)
	{
		getalstr.Format("%d", m_roatwins[7]);
		m_stratwins = getalstr;
	}
	else
		m_stratwins = "";
	
	if (m_roatwinsingles[7] != 0)
	{
		getalstr.Format("%d", m_roatwinsingles[7]);
		m_stratwinsingles = getalstr;
	}
	else
		m_stratwinsingles = "";
	
	if (m_roedoubles[7] != 0)
	{
		getalstr.Format("%d", m_roedoubles[7]);
		m_stredoubles = getalstr;
	}
	else
		m_stredoubles = "";
	
	if (m_roequads[7] != 0)
	{
		getalstr.Format("%d", m_roequads[7]);
		m_strequads = getalstr;
	}
	else
		m_strequads = "";
	
	if (m_roesingles[7] != 0)
	{
		getalstr.Format("%d", m_roesingles[7]);
		m_stresingles = getalstr;
	}
	else
		m_stresingles = "";
	
	if (m_roetriples[7] != 0)
	{
		getalstr.Format("%d", m_roetriples[7]);
		m_stretriples = getalstr;
	}
	else
		m_stretriples = "";
	
	if (m_roemultiples[7] != 0)
	{
		getalstr.Format("%d", m_roemultiples[7]);
		m_stremultiples = getalstr;
	}
	else
		m_stremultiples = "";
	
	if (m_roetwins[7] != 0)
	{
		getalstr.Format("%d", m_roetwins[7]);
		m_stretwins = getalstr;
	}
	else
		m_stretwins = "";
	
	if (m_roetwinsingles[7] != 0)
	{
		getalstr.Format("%d", m_roetwinsingles[7]);
		m_stretwinsingles = getalstr;
	}
	else
		m_stretwinsingles = "";
	
	if (m_roctwinsingles[7] != 0)
	{
		getalstr.Format("%d", m_roctwinsingles[7]);
		m_strctwinsingles = getalstr;
	}
	else
		m_strctwinsingles = "";
	
	if (m_roctwins[7] != 0)
	{
		getalstr.Format("%d", m_roctwins[7]);
		m_strctwins = getalstr;
	}
	else
		m_strctwins = "";
	
	if (m_rocdoubles[7] != 0)
	{
		getalstr.Format("%d", m_rocdoubles[7]);
		m_strcdoubles = getalstr;
	}
	else
		m_strcdoubles = "";
	
	if (m_rocquads[7] != 0)
	{
		getalstr.Format("%d", m_rocquads[7]);
		m_strcquads = getalstr;
	}
	else
		m_strcquads = "";

	if (m_rocsingles[7] != 0)
	{
		getalstr.Format("%d", m_rocsingles[7]);
		m_strcsingles = getalstr;
	}
	else
		m_strcsingles = "";
	
	if (m_rocmultiples[7] != 0)
	{
		getalstr.Format("%d", m_rocmultiples[7]);
		m_strcmultiples = getalstr;
	}
	else
		m_strcmultiples = "";

	if (m_roctriples[7] != 0)
	{
		getalstr.Format("%d", m_roctriples[7]);
		m_strctriples = getalstr;
	}
	else
		m_strctriples = "";

	m_periode = 7;
	m_nuldeperiode = FALSE;

	UpdateData(FALSE);
}

void CBookingsView::OnRoperiode9Button() 
{
	// TODO: Add your control notification handler code here
	
	char invoer[4], invoer2[4];

	if(!m_buttoncheck)
	{
	CEdit *invoerveld = (CEdit *) GetDlgItem(IDC_ROCSINGLES_EDIT);
	invoerveld->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld2 = (CEdit *) GetDlgItem(IDC_ROASINGLES_EDIT);
	invoerveld2->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roasingles[m_periode] = atoi(invoer);

	CEdit *invoerveld3 = (CEdit *) GetDlgItem(IDC_ROESINGLES_EDIT);
	invoerveld3->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roesingles[m_periode] = atoi(invoer);

	CEdit *invoerveld4 = (CEdit *) GetDlgItem(IDC_ROATWINSINGLES_EDIT);
	invoerveld4->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld5 = (CEdit *) GetDlgItem(IDC_ROETWINSINGLES_EDIT);
	invoerveld5->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld6 = (CEdit *) GetDlgItem(IDC_ROCTWINSINGLES_EDIT);
	invoerveld6->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld7 = (CEdit *) GetDlgItem(IDC_ROATWINS_EDIT);
	invoerveld7->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwins[m_periode] = atoi(invoer);

	CEdit *invoerveld8 = (CEdit *) GetDlgItem(IDC_ROETWINS_EDIT);
	invoerveld8->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwins[m_periode] = atoi(invoer);

	CEdit *invoerveld9 = (CEdit *) GetDlgItem(IDC_ROCTWINS_EDIT);
	invoerveld9->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwins[m_periode] = atoi(invoer);

	CEdit *invoerveld10 = (CEdit *) GetDlgItem(IDC_ROADOUBLES_EDIT);
	invoerveld10->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roadoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld11 = (CEdit *) GetDlgItem(IDC_ROEDOUBLES_EDIT);
	invoerveld11->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roedoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld12 = (CEdit *) GetDlgItem(IDC_ROCDOUBLES_EDIT);
	invoerveld12->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocdoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld13 = (CEdit *) GetDlgItem(IDC_ROATRIPLES_EDIT);
	invoerveld13->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatriples[m_periode] = atoi(invoer);

	CEdit *invoerveld14 = (CEdit *) GetDlgItem(IDC_ROETRIPLES_EDIT);
	invoerveld14->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetriples[m_periode] = atoi(invoer);

	CEdit *invoerveld15 = (CEdit *) GetDlgItem(IDC_ROCTRIPLES_EDIT);
	invoerveld15->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctriples[m_periode] = atoi(invoer);

	CEdit *invoerveld16 = (CEdit *) GetDlgItem(IDC_ROAQUADS_EDIT);
	invoerveld16->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roaquads[m_periode] = atoi(invoer);

	CEdit *invoerveld17 = (CEdit *) GetDlgItem(IDC_ROEQUADS_EDIT);
	invoerveld17->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roequads[m_periode] = atoi(invoer);

	CEdit *invoerveld18 = (CEdit *) GetDlgItem(IDC_ROCQUADS_EDIT);
	invoerveld18->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocquads[m_periode] = atoi(invoer);

	CEdit *invoerveld19 = (CEdit *) GetDlgItem(IDC_ROAMULTIPLES_EDIT);
	invoerveld19->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roamultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld20 = (CEdit *) GetDlgItem(IDC_ROEMULTIPLES_EDIT);
	invoerveld20->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roemultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld21 = (CEdit *) GetDlgItem(IDC_ROCMULTIPLES_EDIT);
	invoerveld21->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocmultiples[m_periode] = atoi(invoer);
	}

	m_buttoncheck = FALSE;

	CString getalstr;

	UpdateData(TRUE);

	m_roperiode1 = FALSE;
	m_roperiode2 = FALSE;
	m_roperiode3 = FALSE;
	m_roperiode4 = FALSE;
	m_roperiode5 = FALSE;
	m_roperiode6 = FALSE;
	m_roperiode7 = FALSE;
	m_roperiode8 = FALSE;
	m_roperiode9 = FALSE;
	m_roperiode10 = FALSE;

	m_robuttonnr = "9";

	if (m_roadoubles[8] != 0)
	{
		getalstr.Format("%d", m_roadoubles[8]);
		m_stradoubles = getalstr;
	}
	else
		m_stradoubles = "";

	if (m_roaquads[8] != 0)
	{
		getalstr.Format("%d", m_roaquads[8]);
		m_straquads  = getalstr;
	}
	else
		m_straquads  = "";
	
	if (m_roasingles[8] != 0)
	{
		getalstr.Format("%d", m_roasingles[8]);
		m_strasingles = getalstr;
	}
	else
		m_strasingles = "";
	
	if (m_roatriples[8] != 0)
	{
		getalstr.Format("%d", m_roatriples[8]);
		m_stratriples = getalstr;
	}
	else
		m_stratriples = "";
	
	if (m_roamultiples[8] != 0)
	{
		getalstr.Format("%d", m_roamultiples[8]);
		m_stramultiples = getalstr;
	}
	else
		m_stramultiples = "";
	
	if (m_roatwins[8] != 0)
	{
		getalstr.Format("%d", m_roatwins[8]);
		m_stratwins = getalstr;
	}
	else
		m_stratwins = "";
	
	if (m_roatwinsingles[8] != 0)
	{
		getalstr.Format("%d", m_roatwinsingles[8]);
		m_stratwinsingles = getalstr;
	}
	else
		m_stratwinsingles = "";
	
	if (m_roedoubles[8] != 0)
	{
		getalstr.Format("%d", m_roedoubles[8]);
		m_stredoubles = getalstr;
	}
	else
		m_stredoubles = "";
	
	if (m_roequads[8] != 0)
	{
		getalstr.Format("%d", m_roequads[8]);
		m_strequads = getalstr;
	}
	else
		m_strequads = "";
	
	if (m_roesingles[8] != 0)
	{
		getalstr.Format("%d", m_roesingles[8]);
		m_stresingles = getalstr;
	}
	else
		m_stresingles = "";
	
	if (m_roetriples[8] != 0)
	{
		getalstr.Format("%d", m_roetriples[8]);
		m_stretriples = getalstr;
	}
	else
		m_stretriples = "";
	
	if (m_roemultiples[8] != 0)
	{
		getalstr.Format("%d", m_roemultiples[8]);
		m_stremultiples = getalstr;
	}
	else
		m_stremultiples = "";
	
	if (m_roetwins[8] != 0)
	{
		getalstr.Format("%d", m_roetwins[8]);
		m_stretwins = getalstr;
	}
	else
		m_stretwins = "";
	
	if (m_roetwinsingles[8] != 0)
	{
		getalstr.Format("%d", m_roetwinsingles[8]);
		m_stretwinsingles = getalstr;
	}
	else
		m_stretwinsingles = "";
	
	if (m_roctwinsingles[8] != 0)
	{
		getalstr.Format("%d", m_roctwinsingles[8]);
		m_strctwinsingles = getalstr;
	}
	else
		m_strctwinsingles = "";
	
	if (m_roctwins[8] != 0)
	{
		getalstr.Format("%d", m_roctwins[8]);
		m_strctwins = getalstr;
	}
	else
		m_strctwins = "";
	
	if (m_rocdoubles[8] != 0)
	{
		getalstr.Format("%d", m_rocdoubles[8]);
		m_strcdoubles = getalstr;
	}
	else
		m_strcdoubles = "";
	
	if (m_rocquads[8] != 0)
	{
		getalstr.Format("%d", m_rocquads[8]);
		m_strcquads = getalstr;
	}
	else
		m_strcquads = "";

	if (m_rocsingles[8] != 0)
	{
		getalstr.Format("%d", m_rocsingles[8]);
		m_strcsingles = getalstr;
	}
	else
		m_strcsingles = "";
	
	if (m_rocmultiples[8] != 0)
	{
		getalstr.Format("%d", m_rocmultiples[8]);
		m_strcmultiples = getalstr;
	}
	else
		m_strcmultiples = "";

	if (m_roctriples[8] != 0)
	{
		getalstr.Format("%d", m_roctriples[8]);
		m_strctriples = getalstr;
	}
	else
		m_strctriples = "";

	m_periode = 8;
	m_nuldeperiode = FALSE;

	UpdateData(FALSE);
}

void CBookingsView::OnRoperiode10Button() 
{
	// TODO: Add your control notification handler code here
	
	char invoer[4], invoer2[4];

	if(!m_buttoncheck)
	{
	CEdit *invoerveld = (CEdit *) GetDlgItem(IDC_ROCSINGLES_EDIT);
	invoerveld->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld2 = (CEdit *) GetDlgItem(IDC_ROASINGLES_EDIT);
	invoerveld2->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roasingles[m_periode] = atoi(invoer);

	CEdit *invoerveld3 = (CEdit *) GetDlgItem(IDC_ROESINGLES_EDIT);
	invoerveld3->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roesingles[m_periode] = atoi(invoer);

	CEdit *invoerveld4 = (CEdit *) GetDlgItem(IDC_ROATWINSINGLES_EDIT);
	invoerveld4->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld5 = (CEdit *) GetDlgItem(IDC_ROETWINSINGLES_EDIT);
	invoerveld5->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld6 = (CEdit *) GetDlgItem(IDC_ROCTWINSINGLES_EDIT);
	invoerveld6->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwinsingles[m_periode] = atoi(invoer);

	CEdit *invoerveld7 = (CEdit *) GetDlgItem(IDC_ROATWINS_EDIT);
	invoerveld7->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatwins[m_periode] = atoi(invoer);

	CEdit *invoerveld8 = (CEdit *) GetDlgItem(IDC_ROETWINS_EDIT);
	invoerveld8->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetwins[m_periode] = atoi(invoer);

	CEdit *invoerveld9 = (CEdit *) GetDlgItem(IDC_ROCTWINS_EDIT);
	invoerveld9->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctwins[m_periode] = atoi(invoer);

	CEdit *invoerveld10 = (CEdit *) GetDlgItem(IDC_ROADOUBLES_EDIT);
	invoerveld10->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roadoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld11 = (CEdit *) GetDlgItem(IDC_ROEDOUBLES_EDIT);
	invoerveld11->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roedoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld12 = (CEdit *) GetDlgItem(IDC_ROCDOUBLES_EDIT);
	invoerveld12->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocdoubles[m_periode] = atoi(invoer);

	CEdit *invoerveld13 = (CEdit *) GetDlgItem(IDC_ROATRIPLES_EDIT);
	invoerveld13->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roatriples[m_periode] = atoi(invoer);

	CEdit *invoerveld14 = (CEdit *) GetDlgItem(IDC_ROETRIPLES_EDIT);
	invoerveld14->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roetriples[m_periode] = atoi(invoer);

	CEdit *invoerveld15 = (CEdit *) GetDlgItem(IDC_ROCTRIPLES_EDIT);
	invoerveld15->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roctriples[m_periode] = atoi(invoer);

	CEdit *invoerveld16 = (CEdit *) GetDlgItem(IDC_ROAQUADS_EDIT);
	invoerveld16->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roaquads[m_periode] = atoi(invoer);

	CEdit *invoerveld17 = (CEdit *) GetDlgItem(IDC_ROEQUADS_EDIT);
	invoerveld17->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roequads[m_periode] = atoi(invoer);

	CEdit *invoerveld18 = (CEdit *) GetDlgItem(IDC_ROCQUADS_EDIT);
	invoerveld18->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocquads[m_periode] = atoi(invoer);

	CEdit *invoerveld19 = (CEdit *) GetDlgItem(IDC_ROAMULTIPLES_EDIT);
	invoerveld19->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roamultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld20 = (CEdit *) GetDlgItem(IDC_ROEMULTIPLES_EDIT);
	invoerveld20->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_roemultiples[m_periode] = atoi(invoer);

	CEdit *invoerveld21 = (CEdit *) GetDlgItem(IDC_ROCMULTIPLES_EDIT);
	invoerveld21->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	m_rocmultiples[m_periode] = atoi(invoer);
	}

	m_buttoncheck = FALSE;

	CString getalstr;

	UpdateData(TRUE);

	m_roperiode1 = FALSE;
	m_roperiode2 = FALSE;
	m_roperiode3 = FALSE;
	m_roperiode4 = FALSE;
	m_roperiode5 = FALSE;
	m_roperiode6 = FALSE;
	m_roperiode7 = FALSE;
	m_roperiode8 = FALSE;
	m_roperiode9 = FALSE;
	m_roperiode10 = FALSE;

	m_robuttonnr = "10";

	if (m_roadoubles[9] != 0)
	{
		getalstr.Format("%d", m_roadoubles[9]);
		m_stradoubles = getalstr;
	}
	else
		m_stradoubles = "";

	if (m_roaquads[9] != 0)
	{
		getalstr.Format("%d", m_roaquads[9]);
		m_straquads  = getalstr;
	}
	else
		m_straquads  = "";
	
	if (m_roasingles[9] != 0)
	{
		getalstr.Format("%d", m_roasingles[9]);
		m_strasingles = getalstr;
	}
	else
		m_strasingles = "";
	
	if (m_roatriples[9] != 0)
	{
		getalstr.Format("%d", m_roatriples[9]);
		m_stratriples = getalstr;
	}
	else
		m_stratriples = "";
	
	if (m_roamultiples[9] != 0)
	{
		getalstr.Format("%d", m_roamultiples[9]);
		m_stramultiples = getalstr;
	}
	else
		m_stramultiples = "";
	
	if (m_roatwins[9] != 0)
	{
		getalstr.Format("%d", m_roatwins[9]);
		m_stratwins = getalstr;
	}
	else
		m_stratwins = "";
	
	if (m_roatwinsingles[9] != 0)
	{
		getalstr.Format("%d", m_roatwinsingles[9]);
		m_stratwinsingles = getalstr;
	}
	else
		m_stratwinsingles = "";
	
	if (m_roedoubles[9] != 0)
	{
		getalstr.Format("%d", m_roedoubles[9]);
		m_stredoubles = getalstr;
	}
	else
		m_stredoubles = "";
	
	if (m_roequads[9] != 0)
	{
		getalstr.Format("%d", m_roequads[9]);
		m_strequads = getalstr;
	}
	else
		m_strequads = "";
	
	if (m_roesingles[9] != 0)
	{
		getalstr.Format("%d", m_roesingles[9]);
		m_stresingles = getalstr;
	}
	else
		m_stresingles = "";
	
	if (m_roetriples[9] != 0)
	{
		getalstr.Format("%d", m_roetriples[9]);
		m_stretriples = getalstr;
	}
	else
		m_stretriples = "";
	
	if (m_roemultiples[9] != 0)
	{
		getalstr.Format("%d", m_roemultiples[9]);
		m_stremultiples = getalstr;
	}
	else
		m_stremultiples = "";
	
	if (m_roetwins[9] != 0)
	{
		getalstr.Format("%d", m_roetwins[9]);
		m_stretwins = getalstr;
	}
	else
		m_stretwins = "";
	
	if (m_roetwinsingles[9] != 0)
	{
		getalstr.Format("%d", m_roetwinsingles[9]);
		m_stretwinsingles = getalstr;
	}
	else
		m_stretwinsingles = "";
	
	if (m_roctwinsingles[9] != 0)
	{
		getalstr.Format("%d", m_roctwinsingles[9]);
		m_strctwinsingles = getalstr;
	}
	else
		m_strctwinsingles = "";
	
	if (m_roctwins[9] != 0)
	{
		getalstr.Format("%d", m_roctwins[9]);
		m_strctwins = getalstr;
	}
	else
		m_strctwins = "";
	
	if (m_rocdoubles[9] != 0)
	{
		getalstr.Format("%d", m_rocdoubles[9]);
		m_strcdoubles = getalstr;
	}
	else
		m_strcdoubles = "";
	
	if (m_rocquads[9] != 0)
	{
		getalstr.Format("%d", m_rocquads[9]);
		m_strcquads = getalstr;
	}
	else
		m_strcquads = "";

	if (m_rocsingles[9] != 0)
	{
		getalstr.Format("%d", m_rocsingles[9]);
		m_strcsingles = getalstr;
	}
	else
		m_strcsingles = "";
	
	if (m_rocmultiples[9] != 0)
	{
		getalstr.Format("%d", m_rocmultiples[9]);
		m_strcmultiples = getalstr;
	}
	else
		m_strcmultiples = "";

	if (m_roctriples[9] != 0)
	{
		getalstr.Format("%d", m_roctriples[9]);
		m_strctriples = getalstr;
	}
	else
		m_strctriples = "";

	m_periode = 9;
	m_nuldeperiode = FALSE;

	UpdateData(FALSE);
}

void CBookingsView::OnDestroy() 
{
	CFormView::OnDestroy();
	
	// TODO: Add your message handler code here
	theApp.fitbookingsview = FALSE;
}

void CBookingsView::OnUpdateOpslaanButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (!m_tonen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CBookingsView::OnUpdateNietopslaanButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_wijzigen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CBookingsView::OnUpdateVolgendeButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (!m_nieuw)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CBookingsView::OnUpdateVorigeButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (!m_nieuw)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CBookingsView::OnUpdateTonenButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_setbooking.GetRecordCount() > 0 && m_toegang_tonen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CBookingsView::OnUpdateWijzigenButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_setbooking.GetRecordCount() > 0 && m_toegang_wijzigen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CBookingsView::OnUpdateCancelButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_setbooking.GetRecordCount() > 0 && m_toegang_cancellen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CBookingsView::OnUpdateNieuwButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_toegang_toevoegen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CBookingsView::OnUpdateVerwijderenButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_toegang_verwijderen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CBookingsView::OnRoinputButton() 
{
	// TODO: Add your control notification handler code here
	
	char invoer[4], invoer2[4];

	UpdateData(TRUE);

	m_robuttonnr = "";
	m_buttoncheck = TRUE;

	CEdit *invoerveld = (CEdit *) GetDlgItem(IDC_ROCSINGLES_EDIT);
	invoerveld->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
		m_rocsingles[0] = atoi(invoer);
	if (m_roperiode2)
		m_rocsingles[1] = atoi(invoer);
	if (m_roperiode3)
		m_rocsingles[2] = atoi(invoer);
	if (m_roperiode4)
		m_rocsingles[3] = atoi(invoer);
	if (m_roperiode5)
		m_rocsingles[4] = atoi(invoer);
	if (m_roperiode6)
		m_rocsingles[5] = atoi(invoer);
	if (m_roperiode7)
		m_rocsingles[6] = atoi(invoer);
	if (m_roperiode8)
		m_rocsingles[7] = atoi(invoer);
	if (m_roperiode9)
		m_rocsingles[8] = atoi(invoer);
	if (m_roperiode10)
		m_rocsingles[9] = atoi(invoer);

	CEdit *invoerveld2 = (CEdit *) GetDlgItem(IDC_ROASINGLES_EDIT);
	invoerveld2->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roasingles[0] = atoi(invoer);
	if (m_roperiode2)
	m_roasingles[1] = atoi(invoer);
	if (m_roperiode3)
	m_roasingles[2] = atoi(invoer);
	if (m_roperiode4)
	m_roasingles[3] = atoi(invoer);
	if (m_roperiode5)
	m_roasingles[4] = atoi(invoer);
	if (m_roperiode6)
	m_roasingles[5] = atoi(invoer);
	if (m_roperiode7)
	m_roasingles[6] = atoi(invoer);
	if (m_roperiode8)
	m_roasingles[7] = atoi(invoer);
	if (m_roperiode9)
	m_roasingles[8] = atoi(invoer);
	if (m_roperiode10)
	m_roasingles[9] = atoi(invoer);

	CEdit *invoerveld3 = (CEdit *) GetDlgItem(IDC_ROESINGLES_EDIT);
	invoerveld3->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roesingles[0] = atoi(invoer);
	if (m_roperiode2)
	m_roesingles[1] = atoi(invoer);
	if (m_roperiode3)
	m_roesingles[2] = atoi(invoer);
	if (m_roperiode4)
	m_roesingles[3] = atoi(invoer);
	if (m_roperiode5)
	m_roesingles[4] = atoi(invoer);
	if (m_roperiode6)
	m_roesingles[5] = atoi(invoer);
	if (m_roperiode7)
	m_roesingles[6] = atoi(invoer);
	if (m_roperiode8)
	m_roesingles[7] = atoi(invoer);
	if (m_roperiode9)
	m_roesingles[8] = atoi(invoer);
	if (m_roperiode10)
	m_roesingles[9] = atoi(invoer);

	CEdit *invoerveld4 = (CEdit *) GetDlgItem(IDC_ROATWINSINGLES_EDIT);
	invoerveld4->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roatwinsingles[0] = atoi(invoer);
	if (m_roperiode2)
	m_roatwinsingles[1] = atoi(invoer);
	if (m_roperiode3)
	m_roatwinsingles[2] = atoi(invoer);
	if (m_roperiode4)
	m_roatwinsingles[3] = atoi(invoer);
	if (m_roperiode5)
	m_roatwinsingles[4] = atoi(invoer);
	if (m_roperiode6)
	m_roatwinsingles[5] = atoi(invoer);
	if (m_roperiode7)
	m_roatwinsingles[6] = atoi(invoer);
	if (m_roperiode8)
	m_roatwinsingles[7] = atoi(invoer);
	if (m_roperiode9)
	m_roatwinsingles[8] = atoi(invoer);
	if (m_roperiode10)
	m_roatwinsingles[9] = atoi(invoer);

	CEdit *invoerveld5 = (CEdit *) GetDlgItem(IDC_ROETWINSINGLES_EDIT);
	invoerveld5->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roetwinsingles[0] = atoi(invoer);
	if (m_roperiode2)
	m_roetwinsingles[1] = atoi(invoer);
	if (m_roperiode3)
	m_roetwinsingles[2] = atoi(invoer);
	if (m_roperiode4)
	m_roetwinsingles[3] = atoi(invoer);
	if (m_roperiode5)
	m_roetwinsingles[4] = atoi(invoer);
	if (m_roperiode6)
	m_roetwinsingles[5] = atoi(invoer);
	if (m_roperiode7)
	m_roetwinsingles[6] = atoi(invoer);
	if (m_roperiode8)
	m_roetwinsingles[7] = atoi(invoer);
	if (m_roperiode9)
	m_roetwinsingles[8] = atoi(invoer);
	if (m_roperiode10)
	m_roetwinsingles[9] = atoi(invoer);

	CEdit *invoerveld6 = (CEdit *) GetDlgItem(IDC_ROCTWINSINGLES_EDIT);
	invoerveld6->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roctwinsingles[0] = atoi(invoer);
	if (m_roperiode2)
	m_roctwinsingles[1] = atoi(invoer);
	if (m_roperiode3)
	m_roctwinsingles[2] = atoi(invoer);
	if (m_roperiode4)
	m_roctwinsingles[3] = atoi(invoer);
	if (m_roperiode5)
	m_roctwinsingles[4] = atoi(invoer);
	if (m_roperiode6)
	m_roctwinsingles[5] = atoi(invoer);
	if (m_roperiode7)
	m_roctwinsingles[6] = atoi(invoer);
	if (m_roperiode8)
	m_roctwinsingles[7] = atoi(invoer);
	if (m_roperiode9)
	m_roctwinsingles[8] = atoi(invoer);
	if (m_roperiode10)
	m_roctwinsingles[9] = atoi(invoer);

	CEdit *invoerveld7 = (CEdit *) GetDlgItem(IDC_ROATWINS_EDIT);
	invoerveld7->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roatwins[0] = atoi(invoer);
	if (m_roperiode2)
	m_roatwins[1] = atoi(invoer);
	if (m_roperiode3)
	m_roatwins[2] = atoi(invoer);
	if (m_roperiode4)
	m_roatwins[3] = atoi(invoer);
	if (m_roperiode5)
	m_roatwins[4] = atoi(invoer);
	if (m_roperiode6)
	m_roatwins[5] = atoi(invoer);
	if (m_roperiode7)
	m_roatwins[6] = atoi(invoer);
	if (m_roperiode8)
	m_roatwins[7] = atoi(invoer);
	if (m_roperiode9)
	m_roatwins[8] = atoi(invoer);
	if (m_roperiode10)
	m_roatwins[9] = atoi(invoer);

	CEdit *invoerveld8 = (CEdit *) GetDlgItem(IDC_ROETWINS_EDIT);
	invoerveld8->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roetwins[0] = atoi(invoer);
	if (m_roperiode2)
	m_roetwins[1] = atoi(invoer);
	if (m_roperiode3)
	m_roetwins[2] = atoi(invoer);
	if (m_roperiode4)
	m_roetwins[3] = atoi(invoer);
	if (m_roperiode5)
	m_roetwins[4] = atoi(invoer);
	if (m_roperiode6)
	m_roetwins[5] = atoi(invoer);
	if (m_roperiode7)
	m_roetwins[6] = atoi(invoer);
	if (m_roperiode8)
	m_roetwins[7] = atoi(invoer);
	if (m_roperiode9)
	m_roetwins[8] = atoi(invoer);
	if (m_roperiode10)
	m_roetwins[9] = atoi(invoer);

	CEdit *invoerveld9 = (CEdit *) GetDlgItem(IDC_ROCTWINS_EDIT);
	invoerveld9->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roctwins[0] = atoi(invoer);
	if (m_roperiode2)
	m_roctwins[1] = atoi(invoer);
	if (m_roperiode3)
	m_roctwins[2] = atoi(invoer);
	if (m_roperiode4)
	m_roctwins[3] = atoi(invoer);
	if (m_roperiode5)
	m_roctwins[4] = atoi(invoer);
	if (m_roperiode6)
	m_roctwins[5] = atoi(invoer);
	if (m_roperiode7)
	m_roctwins[6] = atoi(invoer);
	if (m_roperiode8)
	m_roctwins[7] = atoi(invoer);
	if (m_roperiode9)
	m_roctwins[8] = atoi(invoer);
	if (m_roperiode10)
	m_roctwins[9] = atoi(invoer);

	CEdit *invoerveld10 = (CEdit *) GetDlgItem(IDC_ROADOUBLES_EDIT);
	invoerveld10->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roadoubles[0] = atoi(invoer);
	if (m_roperiode2)
	m_roadoubles[1] = atoi(invoer);
	if (m_roperiode3)
	m_roadoubles[2] = atoi(invoer);
	if (m_roperiode4)
	m_roadoubles[3] = atoi(invoer);
	if (m_roperiode5)
	m_roadoubles[4] = atoi(invoer);
	if (m_roperiode6)
	m_roadoubles[5] = atoi(invoer);
	if (m_roperiode7)
	m_roadoubles[6] = atoi(invoer);
	if (m_roperiode8)
	m_roadoubles[7] = atoi(invoer);
	if (m_roperiode9)
	m_roadoubles[8] = atoi(invoer);
	if (m_roperiode10)
	m_roadoubles[9] = atoi(invoer);

	CEdit *invoerveld11 = (CEdit *) GetDlgItem(IDC_ROEDOUBLES_EDIT);
	invoerveld11->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roedoubles[0] = atoi(invoer);
	if (m_roperiode2)
	m_roedoubles[1] = atoi(invoer);
	if (m_roperiode3)
	m_roedoubles[2] = atoi(invoer);
	if (m_roperiode4)
	m_roedoubles[3] = atoi(invoer);
	if (m_roperiode5)
	m_roedoubles[4] = atoi(invoer);
	if (m_roperiode6)
	m_roedoubles[5] = atoi(invoer);
	if (m_roperiode7)
	m_roedoubles[6] = atoi(invoer);
	if (m_roperiode8)
	m_roedoubles[7] = atoi(invoer);
	if (m_roperiode9)
	m_roedoubles[8] = atoi(invoer);
	if (m_roperiode10)
	m_roedoubles[9] = atoi(invoer);

	CEdit *invoerveld12 = (CEdit *) GetDlgItem(IDC_ROCDOUBLES_EDIT);
	invoerveld12->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_rocdoubles[0] = atoi(invoer);
	if (m_roperiode2)
	m_rocdoubles[1] = atoi(invoer);
	if (m_roperiode3)
	m_rocdoubles[2] = atoi(invoer);
	if (m_roperiode4)
	m_rocdoubles[3] = atoi(invoer);
	if (m_roperiode5)
	m_rocdoubles[4] = atoi(invoer);
	if (m_roperiode6)
	m_rocdoubles[5] = atoi(invoer);
	if (m_roperiode7)
	m_rocdoubles[6] = atoi(invoer);
	if (m_roperiode8)
	m_rocdoubles[7] = atoi(invoer);
	if (m_roperiode9)
	m_rocdoubles[8] = atoi(invoer);
	if (m_roperiode10)
	m_rocdoubles[9] = atoi(invoer);

	CEdit *invoerveld13 = (CEdit *) GetDlgItem(IDC_ROATRIPLES_EDIT);
	invoerveld13->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roatriples[0] = atoi(invoer);
	if (m_roperiode2)
	m_roatriples[1] = atoi(invoer);
	if (m_roperiode3)
	m_roatriples[2] = atoi(invoer);
	if (m_roperiode4)
	m_roatriples[3] = atoi(invoer);
	if (m_roperiode5)
	m_roatriples[4] = atoi(invoer);
	if (m_roperiode6)
	m_roatriples[5] = atoi(invoer);
	if (m_roperiode7)
	m_roatriples[6] = atoi(invoer);
	if (m_roperiode8)
	m_roatriples[7] = atoi(invoer);
	if (m_roperiode9)
	m_roatriples[8] = atoi(invoer);
	if (m_roperiode10)
	m_roatriples[9] = atoi(invoer);

	CEdit *invoerveld14 = (CEdit *) GetDlgItem(IDC_ROETRIPLES_EDIT);
	invoerveld14->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roetriples[0] = atoi(invoer);
	if (m_roperiode2)
	m_roetriples[1] = atoi(invoer);
	if (m_roperiode3)
	m_roetriples[2] = atoi(invoer);
	if (m_roperiode4)
	m_roetriples[3] = atoi(invoer);
	if (m_roperiode5)
	m_roetriples[4] = atoi(invoer);
	if (m_roperiode6)
	m_roetriples[5] = atoi(invoer);
	if (m_roperiode7)
	m_roetriples[6] = atoi(invoer);
	if (m_roperiode8)
	m_roetriples[7] = atoi(invoer);
	if (m_roperiode9)
	m_roetriples[8] = atoi(invoer);
	if (m_roperiode10)
	m_roetriples[9] = atoi(invoer);

	CEdit *invoerveld15 = (CEdit *) GetDlgItem(IDC_ROCTRIPLES_EDIT);
	invoerveld15->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roctriples[0] = atoi(invoer);
	if (m_roperiode2)
	m_roctriples[1] = atoi(invoer);
	if (m_roperiode3)
	m_roctriples[2] = atoi(invoer);
	if (m_roperiode4)
	m_roctriples[3] = atoi(invoer);
	if (m_roperiode5)
	m_roctriples[4] = atoi(invoer);
	if (m_roperiode6)
	m_roctriples[5] = atoi(invoer);
	if (m_roperiode7)
	m_roctriples[6] = atoi(invoer);
	if (m_roperiode8)
	m_roctriples[7] = atoi(invoer);
	if (m_roperiode9)
	m_roctriples[8] = atoi(invoer);
	if (m_roperiode10)
	m_roctriples[9] = atoi(invoer);

	CEdit *invoerveld16 = (CEdit *) GetDlgItem(IDC_ROAQUADS_EDIT);
	invoerveld16->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roaquads[0] = atoi(invoer);
	if (m_roperiode2)
	m_roaquads[1] = atoi(invoer);
	if (m_roperiode3)
	m_roaquads[2] = atoi(invoer);
	if (m_roperiode4)
	m_roaquads[3] = atoi(invoer);
	if (m_roperiode5)
	m_roaquads[4] = atoi(invoer);
	if (m_roperiode6)
	m_roaquads[5] = atoi(invoer);
	if (m_roperiode7)
	m_roaquads[6] = atoi(invoer);
	if (m_roperiode8)
	m_roaquads[7] = atoi(invoer);
	if (m_roperiode9)
	m_roaquads[8] = atoi(invoer);
	if (m_roperiode10)
	m_roaquads[9] = atoi(invoer);

	CEdit *invoerveld17 = (CEdit *) GetDlgItem(IDC_ROEQUADS_EDIT);
	invoerveld17->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roequads[0] = atoi(invoer);
	if (m_roperiode2)
	m_roequads[1] = atoi(invoer);
	if (m_roperiode3)
	m_roequads[2] = atoi(invoer);
	if (m_roperiode4)
	m_roequads[3] = atoi(invoer);
	if (m_roperiode5)
	m_roequads[4] = atoi(invoer);
	if (m_roperiode6)
	m_roequads[5] = atoi(invoer);
	if (m_roperiode7)
	m_roequads[6] = atoi(invoer);
	if (m_roperiode8)
	m_roequads[7] = atoi(invoer);
	if (m_roperiode9)
	m_roequads[8] = atoi(invoer);
	if (m_roperiode10)
	m_roequads[9] = atoi(invoer);

	CEdit *invoerveld18 = (CEdit *) GetDlgItem(IDC_ROCQUADS_EDIT);
	invoerveld18->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_rocquads[0] = atoi(invoer);
	if (m_roperiode2)
	m_rocquads[1] = atoi(invoer);
	if (m_roperiode3)
	m_rocquads[2] = atoi(invoer);
	if (m_roperiode4)
	m_rocquads[3] = atoi(invoer);
	if (m_roperiode5)
	m_rocquads[4] = atoi(invoer);
	if (m_roperiode6)
	m_rocquads[5] = atoi(invoer);
	if (m_roperiode7)
	m_rocquads[6] = atoi(invoer);
	if (m_roperiode8)
	m_rocquads[7] = atoi(invoer);
	if (m_roperiode9)
	m_rocquads[8] = atoi(invoer);
	if (m_roperiode10)
	m_rocquads[9] = atoi(invoer);

	CEdit *invoerveld19 = (CEdit *) GetDlgItem(IDC_ROAMULTIPLES_EDIT);
	invoerveld19->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roamultiples[0] = atoi(invoer);
	if (m_roperiode2)
	m_roamultiples[1] = atoi(invoer);
	if (m_roperiode3)
	m_roamultiples[2] = atoi(invoer);
	if (m_roperiode4)
	m_roamultiples[3] = atoi(invoer);
	if (m_roperiode5)
	m_roamultiples[4] = atoi(invoer);
	if (m_roperiode6)
	m_roamultiples[5] = atoi(invoer);
	if (m_roperiode7)
	m_roamultiples[6] = atoi(invoer);
	if (m_roperiode8)
	m_roamultiples[7] = atoi(invoer);
	if (m_roperiode9)
	m_roamultiples[8] = atoi(invoer);
	if (m_roperiode10)
	m_roamultiples[9] = atoi(invoer);

	CEdit *invoerveld20 = (CEdit *) GetDlgItem(IDC_ROEMULTIPLES_EDIT);
	invoerveld20->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_roemultiples[0] = atoi(invoer);
	if (m_roperiode2)
	m_roemultiples[1] = atoi(invoer);
	if (m_roperiode3)
	m_roemultiples[2] = atoi(invoer);
	if (m_roperiode4)
	m_roemultiples[3] = atoi(invoer);
	if (m_roperiode5)
	m_roemultiples[4] = atoi(invoer);
	if (m_roperiode6)
	m_roemultiples[5] = atoi(invoer);
	if (m_roperiode7)
	m_roemultiples[6] = atoi(invoer);
	if (m_roperiode8)
	m_roemultiples[7] = atoi(invoer);
	if (m_roperiode9)
	m_roemultiples[8] = atoi(invoer);
	if (m_roperiode10)
	m_roemultiples[9] = atoi(invoer);

	CEdit *invoerveld21 = (CEdit *) GetDlgItem(IDC_ROCMULTIPLES_EDIT);
	invoerveld21->GetWindowText(invoer, 3);
	sscanf(invoer, "%s", &invoer2);
	if (m_roperiode1)
	m_rocmultiples[0] = atoi(invoer);
	if (m_roperiode2)
	m_rocmultiples[1] = atoi(invoer);
	if (m_roperiode3)
	m_rocmultiples[2] = atoi(invoer);
	if (m_roperiode4)
	m_rocmultiples[3] = atoi(invoer);
	if (m_roperiode5)
	m_rocmultiples[4] = atoi(invoer);
	if (m_roperiode6)
	m_rocmultiples[5] = atoi(invoer);
	if (m_roperiode7)
	m_rocmultiples[6] = atoi(invoer);
	if (m_roperiode8)
	m_rocmultiples[7] = atoi(invoer);
	if (m_roperiode9)
	m_rocmultiples[8] = atoi(invoer);
	if (m_roperiode10)
	m_rocmultiples[9] = atoi(invoer);

	if (m_roperiode1)
	GetDlgItem(IDC_ROPERIODE1_CHECK)->EnableWindow(FALSE);
	if (m_roperiode2)
	GetDlgItem(IDC_ROPERIODE2_CHECK)->EnableWindow(FALSE);
	if (m_roperiode3)
	GetDlgItem(IDC_ROPERIODE3_CHECK)->EnableWindow(FALSE);
	if (m_roperiode4)
	GetDlgItem(IDC_ROPERIODE4_CHECK)->EnableWindow(FALSE);
	if (m_roperiode5)
	GetDlgItem(IDC_ROPERIODE5_CHECK)->EnableWindow(FALSE);
	if (m_roperiode6)
	GetDlgItem(IDC_ROPERIODE6_CHECK)->EnableWindow(FALSE);
	if (m_roperiode7)
	GetDlgItem(IDC_ROPERIODE7_CHECK)->EnableWindow(FALSE);
	if (m_roperiode8)
	GetDlgItem(IDC_ROPERIODE8_CHECK)->EnableWindow(FALSE);
	if (m_roperiode9)
	GetDlgItem(IDC_ROPERIODE9_CHECK)->EnableWindow(FALSE);
	if (m_roperiode10)
	GetDlgItem(IDC_ROPERIODE10_CHECK)->EnableWindow(FALSE);

	m_roperiode1 = FALSE;
	m_roperiode2 = FALSE;
	m_roperiode3 = FALSE;
	m_roperiode4 = FALSE;
	m_roperiode5 = FALSE;
	m_roperiode6 = FALSE;
	m_roperiode7 = FALSE;
	m_roperiode8 = FALSE;
	m_roperiode9 = FALSE;
	m_roperiode10 = FALSE;

	UpdateData(FALSE);
}

