// HotelsView.cpp : implementation file
//

#include "stdafx.h"
#include "travel.h"
#include "HotelsView.h"

#include "Hotels.h"
#include "Toegang.h"
#include "ZkhotelDlg.h"
#include "datecnv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHotelsView

IMPLEMENT_DYNCREATE(CHotelsView, CFormView)

CHotelsView::CHotelsView()
	: CFormView(CHotelsView::IDD)
{
	//{{AFX_DATA_INIT(CHotelsView)
	m_tel = _T("");
	m_address1 = _T("");
	m_city = _T("");
	m_code = _T("");
	m_email = _T("");
	m_fax = _T("");
	m_naam = _T("");
	m_address2 = _T("");
	m_telres = _T("");
	m_country = _T("");
	m_zipcode = _T("");
	m_strdoublesseason1 = _T("");
	m_strdoublesseason2 = _T("");
	m_strdoublesseason3 = _T("");
	m_strdoublesseason4 = _T("");
	m_strdoublesseason5 = _T("");
	m_strdoublesseason6 = _T("");
	m_fromseason1 = _T("");
	m_fromseason2 = _T("");
	m_fromseason3 = _T("");
	m_fromseason4 = _T("");
	m_fromseason5 = _T("");
	m_fromseason6 = _T("");
	m_tillseason1 = _T("");
	m_tillseason2 = _T("");
	m_tillseason3 = _T("");
	m_tillseason4 = _T("");
	m_tillseason5 = _T("");
	m_tillseason6 = _T("");
	m_strmultiplesseason1 = _T("");
	m_strmultiplesseason2 = _T("");
	m_strmultiplesseason3 = _T("");
	m_strmultiplesseason4 = _T("");
	m_strmultiplesseason5 = _T("");
	m_strmultiplesseason6 = _T("");
	m_strquadsseason1 = _T("");
	m_strquadsseason2 = _T("");
	m_strquadsseason3 = _T("");
	m_strquadsseason4 = _T("");
	m_strquadsseason5 = _T("");
	m_strquadsseason6 = _T("");
	m_strsinglesseason1 = _T("");
	m_strsinglesseason2 = _T("");
	m_strsinglesseason3 = _T("");
	m_strsinglesseason4 = _T("");
	m_strsinglesseason5 = _T("");
	m_strsinglesseason6 = _T("");
	m_strtriplesseason1 = _T("");
	m_strtriplesseason2 = _T("");
	m_strtriplesseason3 = _T("");
	m_strtriplesseason4 = _T("");
	m_strtriplesseason5 = _T("");
	m_strtriplesseason6 = _T("");
	m_strtwinsseason1 = _T("");
	m_strtwinsseason2 = _T("");
	m_strtwinsseason3 = _T("");
	m_strtwinsseason4 = _T("");
	m_strtwinsseason5 = _T("");
	m_strtwinsseason6 = _T("");
	m_strtsuseason1 = _T("");
	m_strtsuseason2 = _T("");
	m_strtsuseason3 = _T("");
	m_strtsuseason4 = _T("");
	m_strtsuseason5 = _T("");
	m_strtsuseason6 = _T("");
	//}}AFX_DATA_INIT
}

CHotelsView::~CHotelsView()
{
}

void CHotelsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHotelsView)
	DDX_Control(pDX, IDC_ZIPCODE_EDIT, m_zipcode_cntrl);
	DDX_Control(pDX, IDC_TWINSSEASON1_EDIT, m_strtwinsseason1_cntrl);
	DDX_Control(pDX, IDC_TWINSSEASON2_EDIT, m_strtwinsseason2_cntrl);
	DDX_Control(pDX, IDC_TWINSSEASON3_EDIT, m_strtwinsseason3_cntrl);
	DDX_Control(pDX, IDC_TWINSSEASON4_EDIT, m_strtwinsseason4_cntrl);
	DDX_Control(pDX, IDC_TWINSSEASON5_EDIT, m_strtwinsseason5_cntrl);
	DDX_Control(pDX, IDC_TWINSSEASON6_EDIT, m_strtwinsseason6_cntrl);
	DDX_Control(pDX, IDC_TSUSEASON1_EDIT, m_strtsuseason1_cntrl);
	DDX_Control(pDX, IDC_TSUSEASON2_EDIT, m_strtsuseason2_cntrl);
	DDX_Control(pDX, IDC_TSUSEASON3_EDIT, m_strtsuseason3_cntrl);
	DDX_Control(pDX, IDC_TSUSEASON4_EDIT, m_strtsuseason4_cntrl);
	DDX_Control(pDX, IDC_TSUSEASON5_EDIT, m_strtsuseason5_cntrl);
	DDX_Control(pDX, IDC_TSUSEASON6_EDIT, m_strtsuseason6_cntrl);
	DDX_Control(pDX, IDC_TRIPLESSEASON1_EDIT, m_strtriplesseason1_cntrl);
	DDX_Control(pDX, IDC_TRIPLESSEASON2_EDIT, m_strtriplesseason2_cntrl);
	DDX_Control(pDX, IDC_TRIPLESSEASON3_EDIT, m_strtriplesseason3_cntrl);
	DDX_Control(pDX, IDC_TRIPLESSEASON4_EDIT, m_strtriplesseason4_cntrl);
	DDX_Control(pDX, IDC_TRIPLESSEASON5_EDIT, m_strtriplesseason5_cntrl);
	DDX_Control(pDX, IDC_TRIPLESSEASON6_EDIT, m_strtriplesseason6_cntrl);
	DDX_Control(pDX, IDC_TILLSEASON1_EDIT, m_tillseason1_cntrl);
	DDX_Control(pDX, IDC_TILLSEASON2_EDIT, m_tillseason2_cntrl);
	DDX_Control(pDX, IDC_TILLSEASON3_EDIT, m_tillseason3_cntrl);
	DDX_Control(pDX, IDC_TILLSEASON4_EDIT, m_tillseason4_cntrl);
	DDX_Control(pDX, IDC_TILLSEASON5_EDIT, m_tillseason5_cntrl);
	DDX_Control(pDX, IDC_TILLSEASON6_EDIT, m_tillseason6_cntrl);
	DDX_Control(pDX, IDC_TELRES_EDIT, m_telres_cntrl);
	DDX_Control(pDX, IDC_TEL_EDIT, m_tel_cntrl);
	DDX_Control(pDX, IDC_SINGLESSEASON1_EDIT, m_strsinglesseason1_cntrl);
	DDX_Control(pDX, IDC_SINGLESSEASON2_EDIT, m_strsinglesseason2_cntrl);
	DDX_Control(pDX, IDC_SINGLESSEASON3_EDIT, m_strsinglesseason3_cntrl);
	DDX_Control(pDX, IDC_SINGLESSEASON4_EDIT, m_strsinglesseason4_cntrl);
	DDX_Control(pDX, IDC_SINGLESSEASON5_EDIT, m_strsinglesseason5_cntrl);
	DDX_Control(pDX, IDC_SINGLESSEASON6_EDIT, m_strsinglesseason6_cntrl);
	DDX_Control(pDX, IDC_QUADSSEASON1_EDIT, m_strquadsseason1_cntrl);
	DDX_Control(pDX, IDC_QUADSSEASON2_EDIT, m_strquadsseason2_cntrl);
	DDX_Control(pDX, IDC_QUADSSEASON3_EDIT, m_strquadsseason3_cntrl);
	DDX_Control(pDX, IDC_QUADSSEASON4_EDIT, m_strquadsseason4_cntrl);
	DDX_Control(pDX, IDC_QUADSSEASON5_EDIT, m_strquadsseason5_cntrl);
	DDX_Control(pDX, IDC_QUADSSEASON6_EDIT, m_strquadsseason6_cntrl);
	DDX_Control(pDX, IDC_NAAM_EDIT, m_naam_cntrl);
	DDX_Control(pDX, IDC_MULTIPLESSEASON1_EDIT, m_strmultiplesseason1_cntrl);
	DDX_Control(pDX, IDC_MULTIPLESSEASON2_EDIT, m_strmultiplesseason2_cntrl);
	DDX_Control(pDX, IDC_MULTIPLESSEASON3_EDIT, m_strmultiplesseason3_cntrl);
	DDX_Control(pDX, IDC_MULTIPLESSEASON4_EDIT, m_strmultiplesseason4_cntrl);
	DDX_Control(pDX, IDC_MULTIPLESSEASON5_EDIT, m_strmultiplesseason5_cntrl);
	DDX_Control(pDX, IDC_MULTIPLESSEASON6_EDIT, m_strmultiplesseason6_cntrl);
	DDX_Control(pDX, IDC_FROMSEASON1_EDIT, m_fromseason1_cntrl);
	DDX_Control(pDX, IDC_FROMSEASON2_EDIT, m_fromseason2_cntrl);
	DDX_Control(pDX, IDC_FROMSEASON3_EDIT, m_fromseason3_cntrl);
	DDX_Control(pDX, IDC_FROMSEASON4_EDIT, m_fromseason4_cntrl);
	DDX_Control(pDX, IDC_FROMSEASON5_EDIT, m_fromseason5_cntrl);
	DDX_Control(pDX, IDC_FROMSEASON6_EDIT, m_fromseason6_cntrl);
	DDX_Control(pDX, IDC_FAX_EDIT, m_fax_cntrl);
	DDX_Control(pDX, IDC_EMAIL_EDIT, m_email_cntrl);
	DDX_Control(pDX, IDC_DOUBLESSEASON1_EDIT, m_strdoublesseason1_cntrl);
	DDX_Control(pDX, IDC_DOUBLESSEASON2_EDIT, m_strdoublesseason2_cntrl);
	DDX_Control(pDX, IDC_DOUBLESSEASON3_EDIT, m_strdoublesseason3_cntrl);
	DDX_Control(pDX, IDC_DOUBLESSEASON4_EDIT, m_strdoublesseason4_cntrl);
	DDX_Control(pDX, IDC_DOUBLESSEASON5_EDIT, m_strdoublesseason5_cntrl);
	DDX_Control(pDX, IDC_DOUBLESSEASON6_EDIT, m_strdoublesseason6_cntrl);
	DDX_Control(pDX, IDC_COUNTRY_EDIT, m_country_cntrl);
	DDX_Control(pDX, IDC_CODE_EDIT, m_code_cntrl);
	DDX_Control(pDX, IDC_CITY_EDIT, m_city_cntrl);
	DDX_Control(pDX, IDC_ADDRESS2_EDIT, m_address2_cntrl);
	DDX_Control(pDX, IDC_ADDRESS1_EDIT, m_address1_cntrl);
	DDX_Control(pDX, IDC_HOTELS_TAB, m_tab);
	DDX_Text(pDX, IDC_TEL_EDIT, m_tel);
	DDV_MaxChars(pDX, m_tel, 15);
	DDX_Text(pDX, IDC_ADDRESS1_EDIT, m_address1);
	DDV_MaxChars(pDX, m_address1, 30);
	DDX_Text(pDX, IDC_CITY_EDIT, m_city);
	DDV_MaxChars(pDX, m_city, 30);
	DDX_Text(pDX, IDC_CODE_EDIT, m_code);
	DDV_MaxChars(pDX, m_code, 3);
	DDX_Text(pDX, IDC_EMAIL_EDIT, m_email);
	DDV_MaxChars(pDX, m_email, 30);
	DDX_Text(pDX, IDC_FAX_EDIT, m_fax);
	DDV_MaxChars(pDX, m_fax, 15);
	DDX_Text(pDX, IDC_NAAM_EDIT, m_naam);
	DDV_MaxChars(pDX, m_naam, 30);
	DDX_Text(pDX, IDC_ADDRESS2_EDIT, m_address2);
	DDV_MaxChars(pDX, m_address2, 30);
	DDX_Text(pDX, IDC_TELRES_EDIT, m_telres);
	DDV_MaxChars(pDX, m_telres, 15);
	DDX_Text(pDX, IDC_COUNTRY_EDIT, m_country);
	DDV_MaxChars(pDX, m_country, 30);
	DDX_Text(pDX, IDC_ZIPCODE_EDIT, m_zipcode);
	DDV_MaxChars(pDX, m_zipcode, 10);
	DDX_Text(pDX, IDC_DOUBLESSEASON1_EDIT, m_strdoublesseason1);
	DDV_MaxChars(pDX, m_strdoublesseason1, 6);
	DDX_Text(pDX, IDC_DOUBLESSEASON2_EDIT, m_strdoublesseason2);
	DDV_MaxChars(pDX, m_strdoublesseason2, 6);
	DDX_Text(pDX, IDC_DOUBLESSEASON3_EDIT, m_strdoublesseason3);
	DDV_MaxChars(pDX, m_strdoublesseason3, 6);
	DDX_Text(pDX, IDC_DOUBLESSEASON4_EDIT, m_strdoublesseason4);
	DDV_MaxChars(pDX, m_strdoublesseason4, 6);
	DDX_Text(pDX, IDC_DOUBLESSEASON5_EDIT, m_strdoublesseason5);
	DDV_MaxChars(pDX, m_strdoublesseason5, 6);
	DDX_Text(pDX, IDC_DOUBLESSEASON6_EDIT, m_strdoublesseason6);
	DDV_MaxChars(pDX, m_strdoublesseason6, 6);
	DDX_Text(pDX, IDC_FROMSEASON1_EDIT, m_fromseason1);
	DDV_MaxChars(pDX, m_fromseason1, 10);
	DDX_Text(pDX, IDC_FROMSEASON2_EDIT, m_fromseason2);
	DDV_MaxChars(pDX, m_fromseason2, 10);
	DDX_Text(pDX, IDC_FROMSEASON3_EDIT, m_fromseason3);
	DDV_MaxChars(pDX, m_fromseason3, 10);
	DDX_Text(pDX, IDC_FROMSEASON4_EDIT, m_fromseason4);
	DDV_MaxChars(pDX, m_fromseason4, 10);
	DDX_Text(pDX, IDC_FROMSEASON5_EDIT, m_fromseason5);
	DDV_MaxChars(pDX, m_fromseason5, 10);
	DDX_Text(pDX, IDC_FROMSEASON6_EDIT, m_fromseason6);
	DDV_MaxChars(pDX, m_fromseason6, 10);
	DDX_Text(pDX, IDC_TILLSEASON1_EDIT, m_tillseason1);
	DDV_MaxChars(pDX, m_tillseason1, 10);
	DDX_Text(pDX, IDC_TILLSEASON2_EDIT, m_tillseason2);
	DDV_MaxChars(pDX, m_tillseason2, 10);
	DDX_Text(pDX, IDC_TILLSEASON3_EDIT, m_tillseason3);
	DDV_MaxChars(pDX, m_tillseason3, 10);
	DDX_Text(pDX, IDC_TILLSEASON4_EDIT, m_tillseason4);
	DDV_MaxChars(pDX, m_tillseason4, 10);
	DDX_Text(pDX, IDC_TILLSEASON5_EDIT, m_tillseason5);
	DDV_MaxChars(pDX, m_tillseason5, 10);
	DDX_Text(pDX, IDC_TILLSEASON6_EDIT, m_tillseason6);
	DDV_MaxChars(pDX, m_tillseason6, 10);
	DDX_Text(pDX, IDC_MULTIPLESSEASON1_EDIT, m_strmultiplesseason1);
	DDV_MaxChars(pDX, m_strmultiplesseason1, 6);
	DDX_Text(pDX, IDC_MULTIPLESSEASON2_EDIT, m_strmultiplesseason2);
	DDV_MaxChars(pDX, m_strmultiplesseason2, 6);
	DDX_Text(pDX, IDC_MULTIPLESSEASON3_EDIT, m_strmultiplesseason3);
	DDV_MaxChars(pDX, m_strmultiplesseason3, 6);
	DDX_Text(pDX, IDC_MULTIPLESSEASON4_EDIT, m_strmultiplesseason4);
	DDV_MaxChars(pDX, m_strmultiplesseason4, 6);
	DDX_Text(pDX, IDC_MULTIPLESSEASON5_EDIT, m_strmultiplesseason5);
	DDV_MaxChars(pDX, m_strmultiplesseason5, 6);
	DDX_Text(pDX, IDC_MULTIPLESSEASON6_EDIT, m_strmultiplesseason6);
	DDV_MaxChars(pDX, m_strmultiplesseason6, 6);
	DDX_Text(pDX, IDC_QUADSSEASON1_EDIT, m_strquadsseason1);
	DDV_MaxChars(pDX, m_strquadsseason1, 6);
	DDX_Text(pDX, IDC_QUADSSEASON2_EDIT, m_strquadsseason2);
	DDV_MaxChars(pDX, m_strquadsseason2, 6);
	DDX_Text(pDX, IDC_QUADSSEASON3_EDIT, m_strquadsseason3);
	DDV_MaxChars(pDX, m_strquadsseason3, 6);
	DDX_Text(pDX, IDC_QUADSSEASON4_EDIT, m_strquadsseason4);
	DDV_MaxChars(pDX, m_strquadsseason4, 6);
	DDX_Text(pDX, IDC_QUADSSEASON5_EDIT, m_strquadsseason5);
	DDV_MaxChars(pDX, m_strquadsseason5, 6);
	DDX_Text(pDX, IDC_QUADSSEASON6_EDIT, m_strquadsseason6);
	DDV_MaxChars(pDX, m_strquadsseason6, 6);
	DDX_Text(pDX, IDC_SINGLESSEASON1_EDIT, m_strsinglesseason1);
	DDV_MaxChars(pDX, m_strsinglesseason1, 6);
	DDX_Text(pDX, IDC_SINGLESSEASON2_EDIT, m_strsinglesseason2);
	DDV_MaxChars(pDX, m_strsinglesseason2, 6);
	DDX_Text(pDX, IDC_SINGLESSEASON3_EDIT, m_strsinglesseason3);
	DDV_MaxChars(pDX, m_strsinglesseason3, 6);
	DDX_Text(pDX, IDC_SINGLESSEASON4_EDIT, m_strsinglesseason4);
	DDV_MaxChars(pDX, m_strsinglesseason4, 6);
	DDX_Text(pDX, IDC_SINGLESSEASON5_EDIT, m_strsinglesseason5);
	DDV_MaxChars(pDX, m_strsinglesseason5, 6);
	DDX_Text(pDX, IDC_SINGLESSEASON6_EDIT, m_strsinglesseason6);
	DDV_MaxChars(pDX, m_strsinglesseason6, 6);
	DDX_Text(pDX, IDC_TRIPLESSEASON1_EDIT, m_strtriplesseason1);
	DDV_MaxChars(pDX, m_strtriplesseason1, 6);
	DDX_Text(pDX, IDC_TRIPLESSEASON2_EDIT, m_strtriplesseason2);
	DDV_MaxChars(pDX, m_strtriplesseason2, 6);
	DDX_Text(pDX, IDC_TRIPLESSEASON3_EDIT, m_strtriplesseason3);
	DDV_MaxChars(pDX, m_strtriplesseason3, 6);
	DDX_Text(pDX, IDC_TRIPLESSEASON4_EDIT, m_strtriplesseason4);
	DDV_MaxChars(pDX, m_strtriplesseason4, 6);
	DDX_Text(pDX, IDC_TRIPLESSEASON5_EDIT, m_strtriplesseason5);
	DDV_MaxChars(pDX, m_strtriplesseason5, 6);
	DDX_Text(pDX, IDC_TRIPLESSEASON6_EDIT, m_strtriplesseason6);
	DDV_MaxChars(pDX, m_strtriplesseason6, 6);
	DDX_Text(pDX, IDC_TWINSSEASON1_EDIT, m_strtwinsseason1);
	DDV_MaxChars(pDX, m_strtwinsseason1, 6);
	DDX_Text(pDX, IDC_TWINSSEASON2_EDIT, m_strtwinsseason2);
	DDV_MaxChars(pDX, m_strtwinsseason2, 6);
	DDX_Text(pDX, IDC_TWINSSEASON3_EDIT, m_strtwinsseason3);
	DDV_MaxChars(pDX, m_strtwinsseason3, 6);
	DDX_Text(pDX, IDC_TWINSSEASON4_EDIT, m_strtwinsseason4);
	DDV_MaxChars(pDX, m_strtwinsseason4, 6);
	DDX_Text(pDX, IDC_TWINSSEASON5_EDIT, m_strtwinsseason5);
	DDV_MaxChars(pDX, m_strtwinsseason5, 6);
	DDX_Text(pDX, IDC_TWINSSEASON6_EDIT, m_strtwinsseason6);
	DDV_MaxChars(pDX, m_strtwinsseason6, 6);
	DDX_Text(pDX, IDC_TSUSEASON1_EDIT, m_strtsuseason1);
	DDV_MaxChars(pDX, m_strtsuseason1, 6);
	DDX_Text(pDX, IDC_TSUSEASON2_EDIT, m_strtsuseason2);
	DDV_MaxChars(pDX, m_strtsuseason2, 6);
	DDX_Text(pDX, IDC_TSUSEASON3_EDIT, m_strtsuseason3);
	DDV_MaxChars(pDX, m_strtsuseason3, 6);
	DDX_Text(pDX, IDC_TSUSEASON4_EDIT, m_strtsuseason4);
	DDV_MaxChars(pDX, m_strtsuseason4, 6);
	DDX_Text(pDX, IDC_TSUSEASON5_EDIT, m_strtsuseason5);
	DDV_MaxChars(pDX, m_strtsuseason5, 6);
	DDX_Text(pDX, IDC_TSUSEASON6_EDIT, m_strtsuseason6);
	DDV_MaxChars(pDX, m_strtsuseason6, 6);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHotelsView, CFormView)
	//{{AFX_MSG_MAP(CHotelsView)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_WIJZIGEN_BUTTON, OnWijzigenButton)
	ON_BN_CLICKED(IDC_VORIGE_BUTTON, OnVorigeButton)
	ON_BN_CLICKED(IDC_VOLGENDE_BUTTON, OnVolgendeButton)
	ON_BN_CLICKED(IDC_VERWIJDEREN_BUTTON, OnVerwijderenButton)
	ON_BN_CLICKED(IDC_TONEN_BUTTON, OnTonenButton)
	ON_BN_CLICKED(IDC_OPSLAAN_BUTTON, OnOpslaanButton)
	ON_BN_CLICKED(IDC_NIEUW_BUTTON, OnNieuwButton)
	ON_BN_CLICKED(IDC_NIETOPSLAAN_BUTTON, OnNietopslaanButton)
	ON_EN_KILLFOCUS(IDC_CODE_EDIT, OnKillfocusCodeEdit)
	ON_BN_CLICKED(IDC_CODE_BUTTON, OnCodeButton)
	ON_UPDATE_COMMAND_UI(IDC_VOLGENDE_BUTTON, OnUpdateVolgendeButton)
	ON_UPDATE_COMMAND_UI(IDC_VORIGE_BUTTON, OnUpdateVorigeButton)
	ON_UPDATE_COMMAND_UI(IDC_OPSLAAN_BUTTON, OnUpdateOpslaanButton)
	ON_UPDATE_COMMAND_UI(IDC_NIETOPSLAAN_BUTTON, OnUpdateNietopslaanButton)
	ON_UPDATE_COMMAND_UI(IDC_VERWIJDEREN_BUTTON, OnUpdateVerwijderenButton)
	ON_NOTIFY(TCN_SELCHANGE, IDC_HOTELS_TAB, OnSelchangeHotelsTab)
	ON_WM_DESTROY()
	ON_COMMAND(ID_ACCEL32806, OnAccel32806)
	ON_EN_KILLFOCUS(IDC_FROMSEASON1_EDIT, OnKillfocusFromseason1Edit)
	ON_EN_KILLFOCUS(IDC_FROMSEASON2_EDIT, OnKillfocusFromseason2Edit)
	ON_EN_KILLFOCUS(IDC_FROMSEASON3_EDIT, OnKillfocusFromseason3Edit)
	ON_EN_KILLFOCUS(IDC_FROMSEASON4_EDIT, OnKillfocusFromseason4Edit)
	ON_EN_KILLFOCUS(IDC_FROMSEASON5_EDIT, OnKillfocusFromseason5Edit)
	ON_EN_KILLFOCUS(IDC_FROMSEASON6_EDIT, OnKillfocusFromseason6Edit)
	ON_EN_KILLFOCUS(IDC_TILLSEASON1_EDIT, OnKillfocusTillseason1Edit)
	ON_EN_KILLFOCUS(IDC_TILLSEASON2_EDIT, OnKillfocusTillseason2Edit)
	ON_EN_KILLFOCUS(IDC_TILLSEASON3_EDIT, OnKillfocusTillseason3Edit)
	ON_EN_KILLFOCUS(IDC_TILLSEASON4_EDIT, OnKillfocusTillseason4Edit)
	ON_EN_KILLFOCUS(IDC_TILLSEASON5_EDIT, OnKillfocusTillseason5Edit)
	ON_EN_KILLFOCUS(IDC_TILLSEASON6_EDIT, OnKillfocusTillseason6Edit)
	ON_UPDATE_COMMAND_UI(IDC_TONEN_BUTTON, OnUpdateTonenButton)
	ON_UPDATE_COMMAND_UI(IDC_WIJZIGEN_BUTTON, OnUpdateWijzigenButton)
	ON_UPDATE_COMMAND_UI(IDC_NIEUW_BUTTON, OnUpdateNieuwButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHotelsView diagnostics

#ifdef _DEBUG
void CHotelsView::AssertValid() const
{
	CFormView::AssertValid();
}

void CHotelsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHotelsView message handlers

extern CTravelApp theApp;

void CHotelsView::OnInitialUpdate() 
{
	BeginWaitCursor();
	GetDocument()->SetTitle("Hotels - SHOW");

	CFormView::OnInitialUpdate();
	
	// change our size to a nice size :)
	ResizeParentToFit( false);

	TC_ITEM TabCtrlItem;

	TabCtrlItem.mask = TCIF_TEXT;
	TabCtrlItem.pszText = "Algemeen";
	m_tab.InsertItem(0, &TabCtrlItem );
	TabCtrlItem.pszText = "Prices";
	m_tab.InsertItem(1, &TabCtrlItem );

	f_tab1();
	m_tabkeuze = 1;

	if (theApp.groep == -1)
	{
		m_toegang_tonen       = TRUE;
		m_toegang_toevoegen   = TRUE;
		m_toegang_wijzigen    = TRUE;
		m_toegang_verwijderen = TRUE;
	}
	else
	{
		CToegang m_toegang;
		CString  m_zoekwaarde;
		CString  m_groep;

		m_groep.Format("%d", theApp.groep);

		m_zoekwaarde = "functie = 'hotels' AND groep = " + m_groep;
		m_toegang.m_strFilter = m_zoekwaarde;
		m_toegang.Open();
		m_toegang_tonen       = m_toegang.m_tonen;
		m_toegang_toevoegen   = m_toegang.m_nieuw;
		m_toegang_wijzigen    = m_toegang.m_wijzigen;
		m_toegang_verwijderen = m_toegang.m_verwijderen;
		m_toegang.Close();
	}

	m_sethotels.m_strSort = "ho_city";
	m_sethotels.Open();

	if (!m_sethotels.IsEOF())
		OnTonenButton();
	else
		OnNieuwButton();

	EndWaitCursor();
}

void CHotelsView::OnSelchangeHotelsTab(NMHDR* pNMHDR, LRESULT* pResult) 
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
	}
	
	*pResult = 0;
}

void CHotelsView::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	m_sethotels.Close();

	CFormView::OnClose();
}

void CHotelsView::OnTonenButton() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->SetTitle("Hotels - SHOW");

	m_tonen       = TRUE;
	m_nieuw       = FALSE;
	m_wijzigen    = FALSE;
	m_verwijderen = FALSE;

	GetDlgItem(IDC_CODE_BUTTON)->ShowWindow(SW_SHOW);

	veldenediten(FALSE);
	if (!m_sethotels.IsEOF())
		recordweergeven();
	else
		veldenleegmaken();
}

void CHotelsView::OnNieuwButton() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->SetTitle("Hotels - ADD");

	m_tonen       = FALSE;
	m_nieuw       = TRUE;
	m_wijzigen    = FALSE;
	m_verwijderen = FALSE;

	GetDlgItem(IDC_CODE_BUTTON)->ShowWindow(SW_HIDE);

	veldenediten(TRUE);
	veldenleegmaken();
}

void CHotelsView::OnWijzigenButton() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->SetTitle("Hotels - CHANGE");

	m_tonen       = FALSE;
	m_nieuw       = FALSE;
	m_wijzigen    = TRUE;
	m_verwijderen = FALSE;

	GetDlgItem(IDC_CODE_BUTTON)->ShowWindow(SW_SHOW);

	veldenediten(TRUE);
	if (!m_sethotels.IsEOF())
		recordweergeven();
	else
		veldenleegmaken();
}

void CHotelsView::OnVerwijderenButton() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->SetTitle("Hotels - DELETE");

	m_tonen       = FALSE;
	m_nieuw       = FALSE;
	m_wijzigen    = FALSE;
	m_verwijderen = TRUE;

	GetDlgItem(IDC_CODE_BUTTON)->ShowWindow(SW_SHOW);

	veldenediten(FALSE);
	if (!m_sethotels.IsEOF())
		recordweergeven();
	else
		veldenleegmaken();
}

void CHotelsView::OnNietopslaanButton() 
{
	// TODO: Add your control notification handler code here
	recordweergeven();
}

void CHotelsView::OnOpslaanButton() 
{
	// TODO: Add your control notification handler code here
	char invoer[10], invoer2[10];

	CEdit *invoerveld = (CEdit *) GetDlgItem(IDC_DOUBLESSEASON1_EDIT);
	invoerveld->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_doublesseason1 = atof(invoer);

	CEdit *invoerveld2 = (CEdit *) GetDlgItem(IDC_DOUBLESSEASON2_EDIT);
	invoerveld2->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_doublesseason2 = atof(invoer);

	CEdit *invoerveld3 = (CEdit *) GetDlgItem(IDC_DOUBLESSEASON3_EDIT);
	invoerveld3->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_doublesseason3 = atof(invoer);

	CEdit *invoerveld4 = (CEdit *) GetDlgItem(IDC_DOUBLESSEASON4_EDIT);
	invoerveld4->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_doublesseason4 = atof(invoer);

	CEdit *invoerveld5 = (CEdit *) GetDlgItem(IDC_DOUBLESSEASON5_EDIT);
	invoerveld5->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_doublesseason5 = atof(invoer);

	CEdit *invoerveld6 = (CEdit *) GetDlgItem(IDC_DOUBLESSEASON6_EDIT);
	invoerveld6->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_doublesseason6 = atof(invoer);

	CEdit *invoerveld7 = (CEdit *) GetDlgItem(IDC_MULTIPLESSEASON1_EDIT);
	invoerveld7->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_multiplesseason1 = atof(invoer);

	CEdit *invoerveld8 = (CEdit *) GetDlgItem(IDC_MULTIPLESSEASON2_EDIT);
	invoerveld8->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_multiplesseason2 = atof(invoer);

	CEdit *invoerveld9 = (CEdit *) GetDlgItem(IDC_MULTIPLESSEASON3_EDIT);
	invoerveld9->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_multiplesseason3 = atof(invoer);

	CEdit *invoerveld10 = (CEdit *) GetDlgItem(IDC_MULTIPLESSEASON4_EDIT);
	invoerveld10->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_multiplesseason4 = atof(invoer);

	CEdit *invoerveld11 = (CEdit *) GetDlgItem(IDC_MULTIPLESSEASON5_EDIT);
	invoerveld11->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_multiplesseason5 = atof(invoer);

	CEdit *invoerveld12 = (CEdit *) GetDlgItem(IDC_MULTIPLESSEASON6_EDIT);
	invoerveld12->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_multiplesseason6 = atof(invoer);

	CEdit *invoerveld13 = (CEdit *) GetDlgItem(IDC_QUADSSEASON1_EDIT);
	invoerveld13->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_quadsseason1 = atof(invoer);

	CEdit *invoerveld14 = (CEdit *) GetDlgItem(IDC_QUADSSEASON2_EDIT);
	invoerveld14->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_quadsseason2 = atof(invoer);

	CEdit *invoerveld15 = (CEdit *) GetDlgItem(IDC_QUADSSEASON3_EDIT);
	invoerveld15->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_quadsseason3 = atof(invoer);

	CEdit *invoerveld16 = (CEdit *) GetDlgItem(IDC_QUADSSEASON4_EDIT);
	invoerveld16->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_quadsseason4 = atof(invoer);

	CEdit *invoerveld17 = (CEdit *) GetDlgItem(IDC_QUADSSEASON5_EDIT);
	invoerveld17->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_quadsseason5 = atof(invoer);

	CEdit *invoerveld18 = (CEdit *) GetDlgItem(IDC_QUADSSEASON6_EDIT);
	invoerveld18->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_quadsseason6 = atof(invoer);

	CEdit *invoerveld19 = (CEdit *) GetDlgItem(IDC_SINGLESSEASON1_EDIT);
	invoerveld19->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_singlesseason1 = atof(invoer);

	CEdit *invoerveld20 = (CEdit *) GetDlgItem(IDC_SINGLESSEASON2_EDIT);
	invoerveld20->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_singlesseason2 = atof(invoer);

	CEdit *invoerveld21 = (CEdit *) GetDlgItem(IDC_SINGLESSEASON3_EDIT);
	invoerveld21->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_singlesseason3 = atof(invoer);

	CEdit *invoerveld22 = (CEdit *) GetDlgItem(IDC_SINGLESSEASON4_EDIT);
	invoerveld22->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_singlesseason4 = atof(invoer);

	CEdit *invoerveld23 = (CEdit *) GetDlgItem(IDC_SINGLESSEASON5_EDIT);
	invoerveld23->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_singlesseason5 = atof(invoer);

	CEdit *invoerveld24 = (CEdit *) GetDlgItem(IDC_SINGLESSEASON6_EDIT);
	invoerveld24->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_singlesseason6 = atof(invoer);

	CEdit *invoerveld25 = (CEdit *) GetDlgItem(IDC_TRIPLESSEASON1_EDIT);
	invoerveld25->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_triplesseason1 = atof(invoer);

	CEdit *invoerveld26 = (CEdit *) GetDlgItem(IDC_TRIPLESSEASON2_EDIT);
	invoerveld26->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_triplesseason2 = atof(invoer);

	CEdit *invoerveld27 = (CEdit *) GetDlgItem(IDC_TRIPLESSEASON3_EDIT);
	invoerveld27->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_triplesseason3 = atof(invoer);

	CEdit *invoerveld28 = (CEdit *) GetDlgItem(IDC_TRIPLESSEASON4_EDIT);
	invoerveld28->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_triplesseason4 = atof(invoer);

	CEdit *invoerveld29 = (CEdit *) GetDlgItem(IDC_TRIPLESSEASON5_EDIT);
	invoerveld29->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_triplesseason5 = atof(invoer);

	CEdit *invoerveld30 = (CEdit *) GetDlgItem(IDC_TRIPLESSEASON6_EDIT);
	invoerveld30->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_triplesseason6 = atof(invoer);

	CEdit *invoerveld31 = (CEdit *) GetDlgItem(IDC_TWINSSEASON1_EDIT);
	invoerveld31->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_twinsseason1 = atof(invoer);

	CEdit *invoerveld32 = (CEdit *) GetDlgItem(IDC_TWINSSEASON2_EDIT);
	invoerveld32->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_twinsseason2 = atof(invoer);

	CEdit *invoerveld33 = (CEdit *) GetDlgItem(IDC_TWINSSEASON3_EDIT);
	invoerveld33->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_twinsseason3 = atof(invoer);

	CEdit *invoerveld34 = (CEdit *) GetDlgItem(IDC_TWINSSEASON4_EDIT);
	invoerveld34->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_twinsseason4 = atof(invoer);

	CEdit *invoerveld35 = (CEdit *) GetDlgItem(IDC_TWINSSEASON5_EDIT);
	invoerveld35->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_twinsseason5 = atof(invoer);

	CEdit *invoerveld36 = (CEdit *) GetDlgItem(IDC_TWINSSEASON6_EDIT);
	invoerveld36->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_twinsseason6 = atof(invoer);

	CEdit *invoerveld37 = (CEdit *) GetDlgItem(IDC_TSUSEASON1_EDIT);
	invoerveld37->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_tsuseason1 = atof(invoer);

	CEdit *invoerveld38 = (CEdit *) GetDlgItem(IDC_TSUSEASON2_EDIT);
	invoerveld38->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_tsuseason2 = atof(invoer);

	CEdit *invoerveld39 = (CEdit *) GetDlgItem(IDC_TSUSEASON3_EDIT);
	invoerveld39->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_tsuseason3 = atof(invoer);

	CEdit *invoerveld40 = (CEdit *) GetDlgItem(IDC_TSUSEASON4_EDIT);
	invoerveld40->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_tsuseason4 = atof(invoer);

	CEdit *invoerveld41 = (CEdit *) GetDlgItem(IDC_TSUSEASON5_EDIT);
	invoerveld41->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_tsuseason5 = atof(invoer);

	CEdit *invoerveld42 = (CEdit *) GetDlgItem(IDC_TSUSEASON6_EDIT);
	invoerveld42->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_tsuseason6 = atof(invoer);

	CEdit *invoerveld43 = (CEdit *) GetDlgItem(IDC_TSUSEASON1_EDIT);
	invoerveld43->GetWindowText(invoer, 6);
	sscanf(invoer, "%s", &invoer2);
	m_tsuseason1 = atof(invoer);

	UpdateData(TRUE);

	if (OpslaanCheck())
	{
		if (m_nieuw)
		{
			m_sethotels.AddNew();
			inhoudopslaan();
			m_sethotels.Update();
			m_sethotels.Requery();
			veldenleegmaken();
		}
		else if (m_wijzigen)
		{
			m_sethotels.Edit();
			inhoudopslaan();
			m_sethotels.Update();
		}
		else if (m_verwijderen)
		{
			m_sethotels.Delete();
			if (m_sethotels.IsEOF())
				veldenleegmaken();
			else
			{
				m_sethotels.MoveFirst();
				recordweergeven();
			}
		}
	}
}

BOOL CHotelsView::OpslaanCheck() 
{
/*
	m_vandaag = COleDateTime::GetCurrentTime();

	if (m_algarrivaldate != "")
	{
		m_begindatum.ParseDateTime(m_algarrivaldate, VAR_DATEVALUEONLY);
		if (m_begindatum.m_dt == 0)
		{

*/	
	COleDateTime m_date;
	CString m_datum;
	CDatecnv m_datecnv;

	if (m_nieuw)
		if (MessageBox("Are you sure, you want to add this data?",
			"Update data", MB_OKCANCEL  + MB_ICONEXCLAMATION) != IDOK)
			return FALSE;

	if ((m_wijzigen || m_verwijderen) && m_sethotels.IsEOF())
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

	if (m_code == "" || m_naam == "")
	{
		MessageBox("Hotelcode and name must be filled both !\n",
			"Update data", MB_OK + MB_ICONSTOP);

		return FALSE;
	}

	if (m_nieuw && aanwezig())
	{	
			MessageBox("This hotelcode already exists !\n",
				"Update data", MB_OK + MB_ICONSTOP);

		return FALSE;
	}

	if (m_fromseason1 != "")
	{
		if (m_fromseason1.GetLength() == 6)
			m_fromseason1 = m_datecnv.Datecontrole(m_fromseason1);

		m_date.ParseDateTime(m_fromseason1, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("From-season1-date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			return FALSE;
		}
	}

	if (m_fromseason2 != "")
	{
		if (m_fromseason2.GetLength() == 6)
			m_fromseason2 = m_datecnv.Datecontrole(m_fromseason2);

		m_date.ParseDateTime(m_fromseason2, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("From-season2-date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			return FALSE;
		}
	}

	if (m_fromseason3 != "")
	{
		if (m_fromseason3.GetLength() == 6)
			m_fromseason3 = m_datecnv.Datecontrole(m_fromseason3);

		m_date.ParseDateTime(m_fromseason3, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("From-season3-date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			return FALSE;
		}
	}

	if (m_fromseason4 != "")
	{
		if (m_fromseason4.GetLength() == 6)
			m_fromseason4 = m_datecnv.Datecontrole(m_fromseason4);

		m_date.ParseDateTime(m_fromseason4, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("From-season4-date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			return FALSE;
		}
	}

	if (m_fromseason5 != "")
	{
		if (m_fromseason5.GetLength() == 6)
			m_fromseason5 = m_datecnv.Datecontrole(m_fromseason5);

		m_date.ParseDateTime(m_fromseason5, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("From-season5-date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			return FALSE;
		}
	}

	if (m_fromseason6 != "")
	{
		if (m_fromseason6.GetLength() == 6)
			m_fromseason6 = m_datecnv.Datecontrole(m_fromseason6);

		m_date.ParseDateTime(m_fromseason6, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("From-season6-date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			return FALSE;
		}
	}

	if (m_tillseason1 != "")
	{
		if (m_tillseason1.GetLength() == 6)
			m_tillseason1 = m_datecnv.Datecontrole(m_tillseason1);

		m_date.ParseDateTime(m_tillseason1, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("Till-season1-date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			return FALSE;
		}
	}

	if (m_tillseason2 != "")
	{
		if (m_tillseason2.GetLength() == 6)
			m_tillseason2 = m_datecnv.Datecontrole(m_tillseason2);

		m_date.ParseDateTime(m_tillseason2, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("Till-season2-date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			return FALSE;
		}
	}

	if (m_tillseason3 != "")
	{
		if (m_tillseason3.GetLength() == 6)
			m_tillseason3 = m_datecnv.Datecontrole(m_tillseason3);

		m_date.ParseDateTime(m_tillseason3, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("Till-season3-date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			return FALSE;
		}
	}

	if (m_tillseason4 != "")
	{
		if (m_tillseason4.GetLength() == 6)
			m_tillseason4 = m_datecnv.Datecontrole(m_tillseason4);

		m_date.ParseDateTime(m_tillseason4, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("Till-season4-date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			return FALSE;
		}
	}

	if (m_tillseason5 != "")
	{
		if (m_tillseason5.GetLength() == 6)
			m_tillseason5 = m_datecnv.Datecontrole(m_tillseason5);

		m_date.ParseDateTime(m_tillseason5, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("Till-season5-date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			return FALSE;
		}
	}

	if (m_tillseason6 != "")
	{
		if (m_tillseason6.GetLength() == 6)
			m_tillseason6 = m_datecnv.Datecontrole(m_tillseason6);

		m_date.ParseDateTime(m_tillseason6, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("Till-season6-date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			return FALSE;
		}
	}

	return TRUE;
}

void CHotelsView::OnVorigeButton() 
{
	// TODO: Add your control notification handler code here
	if (!m_sethotels.IsBOF())
	{
		m_sethotels.MovePrev();
		if (m_sethotels.IsBOF())
			m_sethotels.MoveNext();
		recordweergeven();
	}
}

void CHotelsView::OnVolgendeButton() 
{
	// TODO: Add your control notification handler code here
	if (!m_sethotels.IsEOF())
	{
		m_sethotels.MoveNext();
		if (m_sethotels.IsEOF())
			m_sethotels.MovePrev();
		recordweergeven();
	}
}

void CHotelsView::OnKillfocusCodeEdit() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (!m_nieuw && m_code != "" 
		&& m_sethotels.m_ho_code != m_code 
		&& !m_sethotels.IsEOF())
	{
		SetCursor(LoadCursor(NULL, IDC_WAIT));

/*		if (m_sethotels.m_ho_code.CompareNoCase(m_code) < 0)
		{
			while (m_sethotels.m_ho_code.CompareNoCase(m_code) < 0
					&& !m_sethotels.IsEOF())		
				m_sethotels.MoveNext();
			if (m_sethotels.IsEOF())
				m_sethotels.MovePrev();
		}
		else
		{
*/			m_sethotels.MoveFirst();
			while (m_sethotels.m_ho_code.CompareNoCase(m_code) != 0
					&& !m_sethotels.IsEOF())
				m_sethotels.MoveNext();
//		}

		recordweergeven();
		SetCursor(LoadCursor(NULL, IDC_ARROW));
	}
}

BOOL CHotelsView::aanwezig()
{
	BOOL aanwezig;

	if (!m_sethotels.IsEOF())
	{
		m_sethotels.MoveFirst();
		while (!m_sethotels.IsEOF() 
				&& m_sethotels.m_ho_code.CompareNoCase(m_code) < 0)
			m_sethotels.MoveNext();

		if (m_sethotels.m_ho_code.CompareNoCase(m_code) == 0)
			aanwezig = TRUE;
		else
			aanwezig = FALSE;
	}
	else 
		aanwezig = FALSE;

	return aanwezig;
}

void CHotelsView::veldenediten(BOOL edit)
{
	m_naam_cntrl.SetReadOnly(!edit);
	m_country_cntrl.SetReadOnly(!edit);
	m_city_cntrl.SetReadOnly(!edit);
	m_address2_cntrl.SetReadOnly(!edit);
	m_address1_cntrl.SetReadOnly(!edit);
	m_fax_cntrl.SetReadOnly(!edit);
	m_email_cntrl.SetReadOnly(!edit);
	m_telres_cntrl.SetReadOnly(!edit);
	m_tel_cntrl.SetReadOnly(!edit);
	m_zipcode_cntrl.SetReadOnly(!edit);
	m_fromseason1_cntrl.SetReadOnly(!edit);
	m_fromseason2_cntrl.SetReadOnly(!edit);
	m_fromseason3_cntrl.SetReadOnly(!edit);
	m_fromseason4_cntrl.SetReadOnly(!edit);
	m_fromseason5_cntrl.SetReadOnly(!edit);
	m_fromseason6_cntrl.SetReadOnly(!edit);
	m_tillseason1_cntrl.SetReadOnly(!edit);
	m_tillseason2_cntrl.SetReadOnly(!edit);
	m_tillseason3_cntrl.SetReadOnly(!edit);
	m_tillseason4_cntrl.SetReadOnly(!edit);
	m_tillseason5_cntrl.SetReadOnly(!edit);
	m_tillseason6_cntrl.SetReadOnly(!edit);
	m_strtwinsseason1_cntrl.SetReadOnly(!edit);
	m_strtwinsseason2_cntrl.SetReadOnly(!edit);
	m_strtwinsseason3_cntrl.SetReadOnly(!edit);
	m_strtwinsseason4_cntrl.SetReadOnly(!edit);
	m_strtwinsseason5_cntrl.SetReadOnly(!edit);
	m_strtwinsseason6_cntrl.SetReadOnly(!edit);
	m_strtsuseason1_cntrl.SetReadOnly(!edit);
	m_strtsuseason2_cntrl.SetReadOnly(!edit);
	m_strtsuseason3_cntrl.SetReadOnly(!edit);
	m_strtsuseason4_cntrl.SetReadOnly(!edit);
	m_strtsuseason5_cntrl.SetReadOnly(!edit);
	m_strtsuseason6_cntrl.SetReadOnly(!edit);
	m_strtriplesseason1_cntrl.SetReadOnly(!edit);
	m_strtriplesseason2_cntrl.SetReadOnly(!edit);
	m_strtriplesseason3_cntrl.SetReadOnly(!edit);
	m_strtriplesseason4_cntrl.SetReadOnly(!edit);
	m_strtriplesseason5_cntrl.SetReadOnly(!edit);
	m_strtriplesseason6_cntrl.SetReadOnly(!edit);
	m_strsinglesseason1_cntrl.SetReadOnly(!edit);
	m_strsinglesseason2_cntrl.SetReadOnly(!edit);
	m_strsinglesseason3_cntrl.SetReadOnly(!edit);
	m_strsinglesseason4_cntrl.SetReadOnly(!edit);
	m_strsinglesseason5_cntrl.SetReadOnly(!edit);
	m_strsinglesseason6_cntrl.SetReadOnly(!edit);
	m_strquadsseason1_cntrl.SetReadOnly(!edit);
	m_strquadsseason2_cntrl.SetReadOnly(!edit);
	m_strquadsseason3_cntrl.SetReadOnly(!edit);
	m_strquadsseason4_cntrl.SetReadOnly(!edit);
	m_strquadsseason5_cntrl.SetReadOnly(!edit);
	m_strquadsseason6_cntrl.SetReadOnly(!edit);
	m_strmultiplesseason1_cntrl.SetReadOnly(!edit);
	m_strmultiplesseason2_cntrl.SetReadOnly(!edit);
	m_strmultiplesseason3_cntrl.SetReadOnly(!edit);
	m_strmultiplesseason4_cntrl.SetReadOnly(!edit);
	m_strmultiplesseason5_cntrl.SetReadOnly(!edit);
	m_strmultiplesseason6_cntrl.SetReadOnly(!edit);
	m_strdoublesseason1_cntrl.SetReadOnly(!edit);
	m_strdoublesseason2_cntrl.SetReadOnly(!edit);
	m_strdoublesseason3_cntrl.SetReadOnly(!edit);
	m_strdoublesseason4_cntrl.SetReadOnly(!edit);
	m_strdoublesseason5_cntrl.SetReadOnly(!edit);
	m_strdoublesseason6_cntrl.SetReadOnly(!edit);
}

void CHotelsView::recordweergeven()
{
	CDatecnv     m_datecnv;

	m_code     = m_sethotels.m_ho_code;
	m_naam     = m_sethotels.m_ho_name;
	m_address1 = m_sethotels.m_ho_addr1;
	m_address2 = m_sethotels.m_ho_addr2;
	m_zipcode  = m_sethotels.m_ho_zipcode;
	m_city     = m_sethotels.m_ho_city;
	m_country  = m_sethotels.m_ho_country;
	m_tel      = m_sethotels.m_ho_tel;
	m_telres   = m_sethotels.m_ho_telres;
	m_fax      = m_sethotels.m_ho_fax;
	m_email    = m_sethotels.m_ho_email;
	m_fromseason1 = m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from1);
	m_fromseason2 = m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from2);
	m_fromseason3 = m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from3);
	m_fromseason4 = m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from4);
	m_fromseason5 = m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from5);
	m_fromseason6 = m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_from6);
	m_tillseason1 = m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till1);
	m_tillseason2 = m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till2);
	m_tillseason3 = m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till3);
	m_tillseason4 = m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till4);
	m_tillseason5 = m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till5);
	m_tillseason6 = m_datecnv.Datetoddmmjjjj(m_sethotels.m_ho_till6);

	CString getalstr;

	if (m_sethotels.m_ho_dbls1 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_dbls1);
		m_strdoublesseason1 = getalstr;
	}
	else
		m_strdoublesseason1 = "";
	m_doublesseason1 = m_sethotels.m_ho_dbls1;

	if (m_sethotels.m_ho_dbls2 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_dbls2);
		m_strdoublesseason2 = getalstr;
	}
	else
		m_strdoublesseason2 = "";
	m_doublesseason2 = m_sethotels.m_ho_dbls2;

	if (m_sethotels.m_ho_dbls3 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_dbls3);
		m_strdoublesseason3 = getalstr;
	}
	else
		m_strdoublesseason3 = "";
	m_doublesseason3 = m_sethotels.m_ho_dbls3;

	if (m_sethotels.m_ho_dbls4 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_dbls4);
		m_strdoublesseason4 = getalstr;
	}
	else
		m_strdoublesseason4 = "";
	m_doublesseason4 = m_sethotels.m_ho_dbls4;

	if (m_sethotels.m_ho_dbls5 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_dbls5);
		m_strdoublesseason5 = getalstr;
	}
	else
		m_strdoublesseason5 = "";
	m_doublesseason5 = m_sethotels.m_ho_dbls5;

	if (m_sethotels.m_ho_dbls6 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_dbls6);
		m_strdoublesseason6 = getalstr;
	}
	else
		m_strdoublesseason6 = "";
	m_doublesseason6 = m_sethotels.m_ho_dbls6;

	if (m_sethotels.m_ho_mltpls1 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_mltpls1);
		m_strmultiplesseason1 = getalstr;
	}
	else
		m_strmultiplesseason1 = "";
	m_multiplesseason1 = m_sethotels.m_ho_mltpls1;

	if (m_sethotels.m_ho_mltpls2 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_mltpls2);
		m_strmultiplesseason2 = getalstr;
	}
	else
		m_strmultiplesseason2 = "";
	m_multiplesseason2 = m_sethotels.m_ho_mltpls2;

	if (m_sethotels.m_ho_mltpls3 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_mltpls3);
		m_strmultiplesseason3 = getalstr;
	}
	else
		m_strmultiplesseason3 = getalstr;
	m_multiplesseason3 = m_sethotels.m_ho_mltpls3;

	if (m_sethotels.m_ho_mltpls4 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_mltpls4);
		m_strmultiplesseason4 = getalstr;
	}
	else
		m_strmultiplesseason4 = "";
	m_multiplesseason4 = m_sethotels.m_ho_mltpls4;

	if (m_sethotels.m_ho_mltpls5 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_mltpls5);
		m_strmultiplesseason5 = getalstr;
	}
	else
		m_strmultiplesseason5 = "";
	m_multiplesseason5 = m_sethotels.m_ho_mltpls5;

	if (m_sethotels.m_ho_mltpls6 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_mltpls6);
		m_strmultiplesseason6 = getalstr;
	}
	else
		m_strmultiplesseason6 = "";
	m_multiplesseason6 = m_sethotels.m_ho_mltpls6;

	if (m_sethotels.m_ho_qds1 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_qds1);
		m_strquadsseason1 = getalstr;
	}
	else
		m_strquadsseason1 = "";
	m_quadsseason1 = m_sethotels.m_ho_qds1;

	if (m_sethotels.m_ho_qds2 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_qds2);
		m_strquadsseason2 = getalstr;
	}
	else
		m_strquadsseason2 = "";
	m_quadsseason2 = m_sethotels.m_ho_qds2;

	if (m_sethotels.m_ho_qds3 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_qds3);
		m_strquadsseason3 = getalstr;
	}
	else
		m_strquadsseason3 = "";
	m_quadsseason3 = m_sethotels.m_ho_qds3;

	if (m_sethotels.m_ho_qds4 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_qds4);
		m_strquadsseason4 = getalstr;
	}
	else
		m_strquadsseason4 = "";
	m_quadsseason4 = m_sethotels.m_ho_qds4;

	if (m_sethotels.m_ho_qds5 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_qds5);
		m_strquadsseason5 = getalstr;
	}
	else
		m_strquadsseason5 = "";
	m_quadsseason5 = m_sethotels.m_ho_qds5;

	if (m_sethotels.m_ho_qds6 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_qds6);
		m_strquadsseason6 = getalstr;
	}
	else
		m_strquadsseason6 = "";
	m_quadsseason6 = m_sethotels.m_ho_qds6;

	if (m_sethotels.m_ho_sngls1 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_sngls1);
		m_strsinglesseason1 = getalstr;
	}
	else
		m_strsinglesseason1 = "";
	m_singlesseason1 = m_sethotels.m_ho_sngls1;

	if (m_sethotels.m_ho_sngls2 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_sngls2);
		m_strsinglesseason2 = getalstr;
	}
	else
		m_strsinglesseason2 = "";
	m_singlesseason2 = m_sethotels.m_ho_sngls2;

	if (m_sethotels.m_ho_sngls3 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_sngls3);
		m_strsinglesseason3 = getalstr;
	}
	else
		m_strsinglesseason3 = "";
	m_singlesseason3 = m_sethotels.m_ho_sngls3;

	if (m_sethotels.m_ho_sngls4 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_sngls4);
		m_strsinglesseason4 = getalstr;
	}
	else
		m_strsinglesseason4 = "";
	m_singlesseason4 = m_sethotels.m_ho_sngls4;

	if (m_sethotels.m_ho_sngls5 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_sngls5);
		m_strsinglesseason5 = getalstr;
	}
	else
		m_strsinglesseason5 = "";
	m_singlesseason5 = m_sethotels.m_ho_sngls5;

	if (m_sethotels.m_ho_sngls6 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_sngls6);
		m_strsinglesseason6 = getalstr;
	}
	else
		m_strsinglesseason6 = "";
	m_singlesseason6 = m_sethotels.m_ho_sngls6;

	if (m_sethotels.m_ho_trpls1 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_trpls1);
		m_strtriplesseason1 = getalstr;
	}
	else
		m_strtriplesseason1 = "";
	m_triplesseason1 = m_sethotels.m_ho_trpls1;

	if (m_sethotels.m_ho_trpls2 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_trpls2);
		m_strtriplesseason2 = getalstr;
	}
	else
		m_strtriplesseason2 = "";
	m_triplesseason2 = m_sethotels.m_ho_trpls2;

	if (m_sethotels.m_ho_trpls3 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_trpls3);
		m_strtriplesseason3 = getalstr;
	}
	else
		m_strtriplesseason3 = "";
	m_triplesseason3 = m_sethotels.m_ho_trpls3;

	if (m_sethotels.m_ho_trpls4 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_trpls4);
		m_strtriplesseason4 = getalstr;
	}
	else
		m_strtriplesseason4 = "";
	m_triplesseason4 = m_sethotels.m_ho_trpls4;

	if (m_sethotels.m_ho_trpls5 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_trpls5);
		m_strtriplesseason5 = getalstr;
	}
	else
		m_strtriplesseason5 = "";
	m_triplesseason5 = m_sethotels.m_ho_trpls5;

	if (m_sethotels.m_ho_trpls6 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_trpls6);
		m_strtriplesseason6 = getalstr;
	}
	else
		m_strtriplesseason6 = "";
	m_triplesseason6 = m_sethotels.m_ho_trpls6;

	if (m_sethotels.m_ho_twns1 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_twns1);
		m_strtwinsseason1 = getalstr;
	}
	else
		m_strtwinsseason1 = "";
	m_twinsseason1 = m_sethotels.m_ho_twns1;

	if (m_sethotels.m_ho_twns2 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_twns2);
		m_strtwinsseason2 = getalstr;
	}
	else
		m_strtwinsseason2 = "";
	m_twinsseason2 = m_sethotels.m_ho_twns2;

	if (m_sethotels.m_ho_twns3 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_twns3);
		m_strtwinsseason3 = getalstr;
	}
	else
		m_strtwinsseason3 = "";
	m_twinsseason3 = m_sethotels.m_ho_twns3;

	if (m_sethotels.m_ho_twns4 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_twns4);
		m_strtwinsseason4 = getalstr;
	}
	else
		m_strtwinsseason4 = "";
	m_twinsseason4 = m_sethotels.m_ho_twns4;

	if (m_sethotels.m_ho_twns5 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_twns5);
		m_strtwinsseason5 = getalstr;
	}
	else
		m_strtwinsseason5 = "";
	m_twinsseason5 = m_sethotels.m_ho_twns5;

	if (m_sethotels.m_ho_twns6 != 0.00)
	{
		getalstr.Format("%.2f", m_sethotels.m_ho_twns6);
		m_strtwinsseason6 = getalstr;
	}
	else
		m_strtwinsseason6 = "";
	m_twinsseason6 = m_sethotels.m_ho_twns6;

	m_tsuseason1 = m_sethotels.m_ho_tsu1;
	if (m_sethotels.m_ho_tsu1 != 0.00)
	{
		getalstr.Format("%.2f", m_tsuseason1);
		m_strtsuseason1 = getalstr;
	}
	else
		m_strtsuseason1 = "";

	m_tsuseason2 = m_sethotels.m_ho_tsu2;
	if (m_sethotels.m_ho_tsu2 != 0.00)
	{
		getalstr.Format("%.2f", m_tsuseason2);
		m_strtsuseason2 = getalstr;
	}
	else
		m_strtsuseason2 = "";

	m_tsuseason3 = m_sethotels.m_ho_tsu3;
	if (m_sethotels.m_ho_tsu3 != 0.00)
	{
		getalstr.Format("%.2f", m_tsuseason3);
		m_strtsuseason3 = getalstr;
	}
	else
		m_strtsuseason3 = "";

	m_tsuseason4 = m_sethotels.m_ho_tsu4;
	if (m_sethotels.m_ho_tsu4 != 0.00)
	{
		getalstr.Format("%.2f", m_tsuseason4);
		m_strtsuseason4 = getalstr;
	}
	else
		m_strtsuseason4 = "";

	m_tsuseason5 = m_sethotels.m_ho_tsu5;
	if (m_sethotels.m_ho_tsu5 != 0.00)
	{
		getalstr.Format("%.2f", m_tsuseason5);
		m_strtsuseason5 = getalstr;
	}
	else
		m_strtsuseason5 = "";

	m_tsuseason6 = m_sethotels.m_ho_tsu6;
	if (m_sethotels.m_ho_tsu6 != 0.00)
	{
		getalstr.Format("%.2f", m_tsuseason6);
		m_strtsuseason6 = getalstr;
	}
	else
		m_strtsuseason6 = "";

	UpdateData(FALSE);
}

void CHotelsView::veldenleegmaken()
{
	m_code     = "";
	m_naam     = "";
	m_address1 = "";
	m_address2 = "";
	m_zipcode  = "";
	m_city     = "";
	m_country  = "";
	m_tel      = "";
	m_telres   = "";
	m_fax      = "";
	m_email    = "";
	m_fromseason1 = "";
	m_fromseason2 = "";
	m_fromseason3 = "";
	m_fromseason4 = "";
	m_fromseason5 = "";
	m_fromseason6 = "";
	m_tillseason1 = "";
	m_tillseason2 = "";
	m_tillseason3 = "";
	m_tillseason4 = "";
	m_tillseason5 = "";
	m_tillseason6 = "";
	m_strdoublesseason1 = "";
	m_strdoublesseason2 = "";
	m_strdoublesseason3 = "";
	m_strdoublesseason4 = "";
	m_strdoublesseason5 = "";
	m_strdoublesseason6 = "";
	m_strmultiplesseason1 = "";
	m_strmultiplesseason2 = "";
	m_strmultiplesseason3 = "";
	m_strmultiplesseason4 = "";
	m_strmultiplesseason5 = "";
	m_strmultiplesseason6 = "";
	m_strquadsseason1 = "";
	m_strquadsseason2 = "";
	m_strquadsseason3 = "";
	m_strquadsseason4 = "";
	m_strquadsseason5 = "";
	m_strquadsseason6 = "";
	m_strsinglesseason1 = "";
	m_strsinglesseason2 = "";
	m_strsinglesseason3 = "";
	m_strsinglesseason4 = "";
	m_strsinglesseason5 = "";
	m_strsinglesseason6 = "";
	m_strtriplesseason1 = "";
	m_strtriplesseason2 = "";
	m_strtriplesseason3 = "";
	m_strtriplesseason4 = "";
	m_strtriplesseason5 = "";
	m_strtriplesseason6 = "";
	m_strtwinsseason1 = "";
	m_strtwinsseason2 = "";
	m_strtwinsseason3 = "";
	m_strtwinsseason4 = "";
	m_strtwinsseason5 = "";
	m_strtwinsseason6 = "";
	m_strtsuseason1 = "";
	m_strtsuseason2 = "";
	m_strtsuseason3 = "";
	m_strtsuseason4 = "";
	m_strtsuseason5 = "";
	m_strtsuseason6 = "";
	m_doublesseason1 = 0.0;
	m_doublesseason2 = 0.0;
	m_doublesseason3 = 0.0;
	m_doublesseason4 = 0.0;
	m_doublesseason5 = 0.0;
	m_doublesseason6 = 0.0;
	m_multiplesseason1 = 0.0;
	m_multiplesseason2 = 0.0;
	m_multiplesseason3 = 0.0;
	m_multiplesseason4 = 0.0;
	m_multiplesseason5 = 0.0;
	m_multiplesseason6 = 0.0;
	m_quadsseason1 = 0.0;
	m_quadsseason2 = 0.0;
	m_quadsseason3 = 0.0;
	m_quadsseason4 = 0.0;
	m_quadsseason5 = 0.0;
	m_quadsseason6 = 0.0;
	m_singlesseason1 = 0.0;
	m_singlesseason2 = 0.0;
	m_singlesseason3 = 0.0;
	m_singlesseason4 = 0.0;
	m_singlesseason5 = 0.0;
	m_singlesseason6 = 0.0;
	m_triplesseason1 = 0.0;
	m_triplesseason2 = 0.0;
	m_triplesseason3 = 0.0;
	m_triplesseason4 = 0.0;
	m_triplesseason5 = 0.0;
	m_triplesseason6 = 0.0;
	m_twinsseason1 = 0.0;
	m_twinsseason2 = 0.0;
	m_twinsseason3 = 0.0;
	m_twinsseason4 = 0.0;
	m_twinsseason5 = 0.0;
	m_twinsseason6 = 0.0;
	m_tsuseason1 = 0.0;
	m_tsuseason2 = 0.0;
	m_tsuseason3 = 0.0;
	m_tsuseason4 = 0.0;
	m_tsuseason5 = 0.0;
	m_tsuseason6 = 0.0;

	UpdateData(FALSE);
}

void CHotelsView::inhoudopslaan()
{
	CDatecnv     m_datecnv;

	if (m_nieuw)
			m_sethotels.m_ho_code   = m_code;
	m_sethotels.m_ho_name   = m_naam;
	m_sethotels.m_ho_addr1  = m_address1;
	m_sethotels.m_ho_addr2  = m_address2;
	m_sethotels.m_ho_zipcode = m_zipcode;
	m_sethotels.m_ho_city    = m_city;
	m_sethotels.m_ho_country = m_country;
	m_sethotels.m_ho_tel    = m_tel;
	m_sethotels.m_ho_telres = m_telres;
	m_sethotels.m_ho_fax    = m_fax;
	m_sethotels.m_ho_email  = m_email;
	m_sethotels.m_ho_from1  = m_datecnv.Datetojjjjmmdd(m_fromseason1);
	m_sethotels.m_ho_from2  = m_datecnv.Datetojjjjmmdd(m_fromseason2);
	m_sethotels.m_ho_from3  = m_datecnv.Datetojjjjmmdd(m_fromseason3);
	m_sethotels.m_ho_from4  = m_datecnv.Datetojjjjmmdd(m_fromseason4);
	m_sethotels.m_ho_from5  = m_datecnv.Datetojjjjmmdd(m_fromseason5);
	m_sethotels.m_ho_from6  = m_datecnv.Datetojjjjmmdd(m_fromseason6);
	m_sethotels.m_ho_till1  = m_datecnv.Datetojjjjmmdd(m_tillseason1);
	m_sethotels.m_ho_till2  = m_datecnv.Datetojjjjmmdd(m_tillseason2);
	m_sethotels.m_ho_till3  = m_datecnv.Datetojjjjmmdd(m_tillseason3);
	m_sethotels.m_ho_till4  = m_datecnv.Datetojjjjmmdd(m_tillseason4);
	m_sethotels.m_ho_till5  = m_datecnv.Datetojjjjmmdd(m_tillseason5);
	m_sethotels.m_ho_till6  = m_datecnv.Datetojjjjmmdd(m_tillseason6);
	m_sethotels.m_ho_sngls1 = m_singlesseason1;
	m_sethotels.m_ho_sngls2 = m_singlesseason2;
	m_sethotels.m_ho_sngls3 = m_singlesseason3;
	m_sethotels.m_ho_sngls4 = m_singlesseason4;
	m_sethotels.m_ho_sngls5 = m_singlesseason5;
	m_sethotels.m_ho_sngls6 = m_singlesseason6;
	m_sethotels.m_ho_dbls1  = m_doublesseason1;
	m_sethotels.m_ho_dbls2  = m_doublesseason2;
	m_sethotels.m_ho_dbls3  = m_doublesseason3;
	m_sethotels.m_ho_dbls4  = m_doublesseason4;
	m_sethotels.m_ho_dbls5  = m_doublesseason5;
	m_sethotels.m_ho_dbls6  = m_doublesseason6;
	m_sethotels.m_ho_twns1  = m_twinsseason1;
	m_sethotels.m_ho_twns2  = m_twinsseason2;
	m_sethotels.m_ho_twns3  = m_twinsseason3;
	m_sethotels.m_ho_twns4  = m_twinsseason4;
	m_sethotels.m_ho_twns5  = m_twinsseason5;
	m_sethotels.m_ho_twns6  = m_twinsseason6;
	m_sethotels.m_ho_trpls1 = m_triplesseason1;
	m_sethotels.m_ho_trpls2 = m_triplesseason2;
	m_sethotels.m_ho_trpls3 = m_triplesseason3;
	m_sethotels.m_ho_trpls4 = m_triplesseason4;
	m_sethotels.m_ho_trpls5 = m_triplesseason5;
	m_sethotels.m_ho_trpls6 = m_triplesseason6;
	m_sethotels.m_ho_qds1   = m_quadsseason1;
	m_sethotels.m_ho_qds2   = m_quadsseason2;
	m_sethotels.m_ho_qds3   = m_quadsseason3;
	m_sethotels.m_ho_qds4   = m_quadsseason4;
	m_sethotels.m_ho_qds5   = m_quadsseason5;
	m_sethotels.m_ho_qds6   = m_quadsseason6;
	m_sethotels.m_ho_mltpls1 = m_multiplesseason1;
	m_sethotels.m_ho_mltpls2 = m_multiplesseason2;
	m_sethotels.m_ho_mltpls3 = m_multiplesseason3;
	m_sethotels.m_ho_mltpls4 = m_multiplesseason4;
	m_sethotels.m_ho_mltpls5 = m_multiplesseason5;
	m_sethotels.m_ho_mltpls6 = m_multiplesseason6;
	m_sethotels.m_ho_tsu1 = m_tsuseason1;
	m_sethotels.m_ho_tsu2 = m_tsuseason2;
	m_sethotels.m_ho_tsu3 = m_tsuseason3;
	m_sethotels.m_ho_tsu4 = m_tsuseason4;
	m_sethotels.m_ho_tsu5 = m_tsuseason5;
	m_sethotels.m_ho_tsu6 = m_tsuseason6;
}

void CHotelsView::f_tab1()
{
	GetDlgItem(IDC_TEL_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ADDRESS1_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_CITY_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EMAIL_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_FAX_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ADDRESS2_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TELRES_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_COUNTRY_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ZIPCODE_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TEL_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ADDRESS_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_CITY_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EMAIL_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_FAX_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_NAME_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TELRES_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_COUNTRY_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_ZIPCODE_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_DOUBLESSEASON1_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_DOUBLESSEASON2_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_DOUBLESSEASON3_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_DOUBLESSEASON4_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_DOUBLESSEASON5_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_DOUBLESSEASON6_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_FROMSEASON1_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_FROMSEASON2_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_FROMSEASON3_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_FROMSEASON4_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_FROMSEASON5_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_FROMSEASON6_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TILLSEASON1_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TILLSEASON2_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TILLSEASON3_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TILLSEASON4_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TILLSEASON5_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TILLSEASON6_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MULTIPLESSEASON1_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MULTIPLESSEASON2_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MULTIPLESSEASON3_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MULTIPLESSEASON4_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MULTIPLESSEASON5_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MULTIPLESSEASON6_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_QUADSSEASON1_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_QUADSSEASON2_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_QUADSSEASON3_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_QUADSSEASON4_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_QUADSSEASON5_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_QUADSSEASON6_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SINGLESSEASON1_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SINGLESSEASON2_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SINGLESSEASON3_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SINGLESSEASON4_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SINGLESSEASON5_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SINGLESSEASON6_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TRIPLESSEASON1_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TRIPLESSEASON2_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TRIPLESSEASON3_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TRIPLESSEASON4_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TRIPLESSEASON5_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TRIPLESSEASON6_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TWINSSEASON1_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TWINSSEASON2_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TWINSSEASON3_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TWINSSEASON4_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TWINSSEASON5_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TWINSSEASON6_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TSUSEASON1_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TSUSEASON2_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TSUSEASON3_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TSUSEASON4_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TSUSEASON5_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TSUSEASON6_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_FROM_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TILL_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SINGLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TSU_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_DOUBLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TWINS_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TRIPLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_QUADS_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MULTIPLES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SEASON1_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SEASON2_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SEASON3_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SEASON4_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SEASON5_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SEASON6_STATIC)->ShowWindow(SW_HIDE);
}

void CHotelsView::f_tab2()
{
	GetDlgItem(IDC_TEL_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ADDRESS1_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CITY_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EMAIL_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_FAX_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ADDRESS2_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TELRES_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COUNTRY_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ZIPCODE_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TEL_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ADDRESS_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CITY_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EMAIL_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_FAX_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_NAME_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TELRES_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COUNTRY_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ZIPCODE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_DOUBLESSEASON1_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_DOUBLESSEASON2_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_DOUBLESSEASON3_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_DOUBLESSEASON4_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_DOUBLESSEASON5_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_DOUBLESSEASON6_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_FROMSEASON1_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_FROMSEASON2_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_FROMSEASON3_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_FROMSEASON4_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_FROMSEASON5_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_FROMSEASON6_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TILLSEASON1_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TILLSEASON2_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TILLSEASON3_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TILLSEASON4_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TILLSEASON5_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TILLSEASON6_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MULTIPLESSEASON1_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MULTIPLESSEASON2_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MULTIPLESSEASON3_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MULTIPLESSEASON4_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MULTIPLESSEASON5_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MULTIPLESSEASON6_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_QUADSSEASON1_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_QUADSSEASON2_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_QUADSSEASON3_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_QUADSSEASON4_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_QUADSSEASON5_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_QUADSSEASON6_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SINGLESSEASON1_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SINGLESSEASON2_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SINGLESSEASON3_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SINGLESSEASON4_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SINGLESSEASON5_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SINGLESSEASON6_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TRIPLESSEASON1_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TRIPLESSEASON2_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TRIPLESSEASON3_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TRIPLESSEASON4_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TRIPLESSEASON5_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TRIPLESSEASON6_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TWINSSEASON1_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TWINSSEASON2_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TWINSSEASON3_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TWINSSEASON4_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TWINSSEASON5_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TWINSSEASON6_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TSUSEASON1_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TSUSEASON2_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TSUSEASON3_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TSUSEASON4_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TSUSEASON5_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TSUSEASON6_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_FROM_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TILL_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SINGLES_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TSU_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_DOUBLES_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TWINS_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TRIPLES_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_QUADS_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MULTIPLES_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SEASON1_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SEASON2_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SEASON3_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SEASON4_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SEASON5_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SEASON6_STATIC)->ShowWindow(SW_SHOW);
}

void CHotelsView::OnCodeButton() 
{
	// TODO: Add your control notification handler code here
	CZkhotelDlg dlg;
	dlg.DoModal();
	if (dlg.m_code != "")
	{
		m_code = dlg.m_code;
		UpdateData(FALSE);
		OnKillfocusCodeEdit();
	}
}

void CHotelsView::OnUpdateVolgendeButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (!m_nieuw)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CHotelsView::OnUpdateVorigeButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (!m_nieuw)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CHotelsView::OnUpdateOpslaanButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (!m_tonen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CHotelsView::OnUpdateNietopslaanButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (!m_tonen && !m_verwijderen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CHotelsView::OnDestroy() 
{
	CFormView::OnDestroy();
	
	// TODO: Add your message handler code here
	theApp.hotelsview = FALSE;
}

void CHotelsView::OnAccel32806() 
{
	// TODO: Add your command handler code here
	
	int selectie = m_tab.GetCurSel();

	switch(selectie)
	{
	case 0: f_tab2();
			m_tabkeuze = 2;
			m_tab.SetCurSel(1);
		break;
	case 1: f_tab1();
			m_tabkeuze = 1;
			m_tab.SetCurSel(0);
		break;
	}
}

void CHotelsView::OnKillfocusFromseason1Edit() 
{
	// TODO: Add your control notification handler code here
	COleDateTime m_date;
	CString m_datum;
	CDatecnv m_datecnv;

	UpdateData(TRUE);

	if (m_fromseason1 != "")
	{
		if (m_fromseason1.GetLength() == 6)
			m_fromseason1 = m_datecnv.Datecontrole(m_fromseason1);

		m_date.ParseDateTime(m_fromseason1, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("This date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			GetDlgItem(IDC_FROMSEASON1_EDIT)->SetFocus();
		}
	}

	UpdateData(FALSE);
}

void CHotelsView::OnKillfocusFromseason2Edit() 
{
	// TODO: Add your control notification handler code here
	
	COleDateTime m_date;
	CString m_datum;
	CDatecnv m_datecnv;

	UpdateData(TRUE);

	if (m_fromseason2 != "")
	{
		if (m_fromseason2.GetLength() == 6)
			m_fromseason2 = m_datecnv.Datecontrole(m_fromseason2);

		m_date.ParseDateTime(m_fromseason2, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("This date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			GetDlgItem(IDC_FROMSEASON2_EDIT)->SetFocus();
		}
	}

	UpdateData(FALSE);
}

void CHotelsView::OnKillfocusFromseason3Edit() 
{
	// TODO: Add your control notification handler code here
	
	COleDateTime m_date;
	CString m_datum;
	CDatecnv m_datecnv;

	UpdateData(TRUE);

	if (m_fromseason3 != "")
	{
		if (m_fromseason3.GetLength() == 6)
			m_fromseason3 = m_datecnv.Datecontrole(m_fromseason3);

		m_date.ParseDateTime(m_fromseason3, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("This date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			GetDlgItem(IDC_FROMSEASON3_EDIT)->SetFocus();
		}
	}

	UpdateData(FALSE);
}

void CHotelsView::OnKillfocusFromseason4Edit() 
{
	// TODO: Add your control notification handler code here
	
	COleDateTime m_date;
	CString m_datum;
	CDatecnv m_datecnv;

	UpdateData(TRUE);

	if (m_fromseason4 != "")
	{
		if (m_fromseason4.GetLength() == 6)
			m_fromseason4 = m_datecnv.Datecontrole(m_fromseason4);

		m_date.ParseDateTime(m_fromseason4, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("This date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			GetDlgItem(IDC_FROMSEASON4_EDIT)->SetFocus();
		}
	}

	UpdateData(FALSE);
}

void CHotelsView::OnKillfocusFromseason5Edit() 
{
	// TODO: Add your control notification handler code here
	
	COleDateTime m_date;
	CString m_datum;
	CDatecnv m_datecnv;

	UpdateData(TRUE);

	if (m_fromseason5 != "")
	{
		if (m_fromseason5.GetLength() == 6)
			m_fromseason5 = m_datecnv.Datecontrole(m_fromseason5);

		m_date.ParseDateTime(m_fromseason5, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("This date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			GetDlgItem(IDC_FROMSEASON5_EDIT)->SetFocus();
		}
	}

	UpdateData(FALSE);
}

void CHotelsView::OnKillfocusFromseason6Edit() 
{
	// TODO: Add your control notification handler code here
	
	COleDateTime m_date;
	CString m_datum;
	CDatecnv m_datecnv;

	UpdateData(TRUE);

	if (m_fromseason6 != "")
	{
		if (m_fromseason6.GetLength() == 6)
			m_fromseason6 = m_datecnv.Datecontrole(m_fromseason6);

		m_date.ParseDateTime(m_fromseason6, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("This date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			GetDlgItem(IDC_FROMSEASON6_EDIT)->SetFocus();
		}
	}

	UpdateData(FALSE);
}

void CHotelsView::OnKillfocusTillseason1Edit() 
{
	// TODO: Add your control notification handler code here
	
	COleDateTime m_date;
	CString m_datum;
	CDatecnv m_datecnv;

	UpdateData(TRUE);

	if (m_tillseason1 != "")
	{
		if (m_tillseason1.GetLength() == 6)
			m_tillseason1 = m_datecnv.Datecontrole(m_tillseason1);

		m_date.ParseDateTime(m_tillseason1, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("This date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			GetDlgItem(IDC_TILLSEASON1_EDIT)->SetFocus();
		}
	}

	UpdateData(FALSE);
}

void CHotelsView::OnKillfocusTillseason2Edit() 
{
	// TODO: Add your control notification handler code here
	
	COleDateTime m_date;
	CString m_datum;
	CDatecnv m_datecnv;

	UpdateData(TRUE);

	if (m_tillseason2 != "")
	{
		if (m_tillseason2.GetLength() == 6)
			m_tillseason2 = m_datecnv.Datecontrole(m_tillseason2);

		m_date.ParseDateTime(m_tillseason2, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("This date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			GetDlgItem(IDC_TILLSEASON2_EDIT)->SetFocus();
		}
	}

	UpdateData(FALSE);
}

void CHotelsView::OnKillfocusTillseason3Edit() 
{
	// TODO: Add your control notification handler code here
	
	COleDateTime m_date;
	CString m_datum;
	CDatecnv m_datecnv;

	UpdateData(TRUE);

	if (m_tillseason3 != "")
	{
		if (m_tillseason3.GetLength() == 6)
			m_tillseason3 = m_datecnv.Datecontrole(m_tillseason3);

		m_date.ParseDateTime(m_tillseason3, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("This date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			GetDlgItem(IDC_TILLSEASON3_EDIT)->SetFocus();
		}
	}

	UpdateData(FALSE);
}

void CHotelsView::OnKillfocusTillseason4Edit() 
{
	// TODO: Add your control notification handler code here
	
	COleDateTime m_date;
	CString m_datum;
	CDatecnv m_datecnv;

	UpdateData(TRUE);

	if (m_tillseason4 != "")
	{
		if (m_tillseason4.GetLength() == 6)
			m_tillseason4 = m_datecnv.Datecontrole(m_tillseason4);

		m_date.ParseDateTime(m_tillseason4, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("This date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			GetDlgItem(IDC_TILLSEASON4_EDIT)->SetFocus();
		}
	}

	UpdateData(FALSE);
}

void CHotelsView::OnKillfocusTillseason5Edit() 
{
	// TODO: Add your control notification handler code here
	
	COleDateTime m_date;
	CString m_datum;
	CDatecnv m_datecnv;

	UpdateData(TRUE);

	if (m_tillseason5 != "")
	{
		if (m_tillseason5.GetLength() == 6)
			m_tillseason5 = m_datecnv.Datecontrole(m_tillseason5);

		m_date.ParseDateTime(m_tillseason5, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("This date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			GetDlgItem(IDC_TILLSEASON5_EDIT)->SetFocus();
		}
	}

	UpdateData(FALSE);
}

void CHotelsView::OnKillfocusTillseason6Edit() 
{
	// TODO: Add your control notification handler code here
	
	COleDateTime m_date;
	CString m_datum;
	CDatecnv m_datecnv;

	UpdateData(TRUE);

	if (m_tillseason6 != "")
	{
		if (m_tillseason6.GetLength() == 6)
			m_tillseason6 = m_datecnv.Datecontrole(m_tillseason6);

		m_date.ParseDateTime(m_tillseason6, VAR_DATEVALUEONLY);
		if (m_date.m_dt == 0)
		{
			MessageBox("This date isn't a correct date !\n",
				"Controle", MB_OK + MB_ICONSTOP);
			GetDlgItem(IDC_TILLSEASON6_EDIT)->SetFocus();
		}
	}

	UpdateData(FALSE);
}

void CHotelsView::OnUpdateVerwijderenButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_toegang_verwijderen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CHotelsView::OnUpdateTonenButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_sethotels.GetRecordCount() > 0 && m_toegang_tonen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CHotelsView::OnUpdateWijzigenButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_sethotels.GetRecordCount() > 0 && m_toegang_wijzigen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CHotelsView::OnUpdateNieuwButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_toegang_toevoegen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}
