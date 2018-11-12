// FitovzView.cpp : implementation file
//

#include "stdafx.h"
#include "travel.h"
#include "FitovzView.h"

#include "Datecnv.h"
#include "zkhoteldlg.h"
#include "zkagentdlg.h"
#include "hotels.h"
#include "agents.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFitovzView

IMPLEMENT_DYNCREATE(CFitovzView, CFormView)

CFitovzView::CFitovzView()
	: CFormView(CFitovzView::IDD)
{
	//{{AFX_DATA_INIT(CFitovzView)
	m_clnameto = _T("");
	m_naam = _T("");
	m_clnamefrom = _T("");
	m_codefrom = _T("");
	m_numberfrom = 0;
	m_numberto = 0;
	m_datefrom = _T("");
	m_dateto = _T("");
	m_cancelled = FALSE;
	m_omschrijving = _T("");
	m_maand = 0;
	m_jaar = 0;
	//}}AFX_DATA_INIT
}

CFitovzView::~CFitovzView()
{
}

void CFitovzView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFitovzView)
	DDX_Control(pDX, IDC_KEUZE_LIST, m_keuzelijst);
	DDX_Text(pDX, IDC_CLNAMETO_EDIT, m_clnameto);
	DDV_MaxChars(pDX, m_clnameto, 30);
	DDX_Text(pDX, IDC_NAAM_EDIT, m_naam);
	DDV_MaxChars(pDX, m_naam, 30);
	DDX_Text(pDX, IDC_CLNAMEFROM_EDIT, m_clnamefrom);
	DDV_MaxChars(pDX, m_clnamefrom, 30);
	DDX_Text(pDX, IDC_CODEFROM_EDIT, m_codefrom);
	DDV_MaxChars(pDX, m_codefrom, 3);
	DDX_Text(pDX, IDC_NUMBERFROM_EDIT, m_numberfrom);
	DDV_MinMaxLong(pDX, m_numberfrom, 0, 99999);
	DDX_Text(pDX, IDC_NUMBERTO_EDIT, m_numberto);
	DDV_MinMaxLong(pDX, m_numberto, 0, 99999);
	DDX_Text(pDX, IDC_DATEFROM_EDIT, m_datefrom);
	DDV_MaxChars(pDX, m_datefrom, 10);
	DDX_Text(pDX, IDC_DATETO_EDIT, m_dateto);
	DDV_MaxChars(pDX, m_dateto, 10);
	DDX_Check(pDX, IDC_CANCELLED_CHECK, m_cancelled);
	DDX_Text(pDX, IDC_OMSCHRIJVING_STATIC, m_omschrijving);
	DDX_Text(pDX, IDC_MAAND_EDIT, m_maand);
	DDX_Text(pDX, IDC_JAAR_EDIT, m_jaar);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFitovzView, CFormView)
	//{{AFX_MSG_MAP(CFitovzView)
	ON_LBN_SELCHANGE(IDC_KEUZE_LIST, OnSelchangeKeuzeList)
	ON_BN_CLICKED(IDC_OVERVIEW_BUTTON, OnOverviewButton)
	ON_BN_CLICKED(IDC_ZOEK_BUTTON, OnZoekButton)
	ON_EN_KILLFOCUS(IDC_CODEFROM_EDIT, OnKillfocusCodefromEdit)
	ON_WM_DESTROY()
	ON_LBN_DBLCLK(IDC_KEUZE_LIST, OnDblclkKeuzeList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFitovzView diagnostics

#ifdef _DEBUG
void CFitovzView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFitovzView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFitovzView message handlers

void CFitovzView::OnInitialUpdate() 
{
	BeginWaitCursor();
	GetDocument()->SetTitle("FIT Overviews");

	CFormView::OnInitialUpdate();
	
	// change our size to a nice size :)
	ResizeParentToFit(false);

	m_keuzelijst.InsertString(0, "Hotel statistics");
	m_keuzelijst.InsertString(1, "Agent statistics");
	m_keuzelijst.InsertString(2, "All hotel statistics");
	m_keuzelijst.InsertString(3, "All agent statistics");
	m_keuzelijst.InsertString(4, "Cancellation statistics");
	m_keuzelijst.InsertString(5, "Passenger's name list");
	m_keuzelijst.InsertString(6, "Bookingdate statistics");
	m_keuzelijst.InsertString(7, "Allotment statistics");
	m_keuzelijst.InsertString(8, "Transfer statistics");
	m_keuzelijst.InsertString(9, "Excursion statistics");
	m_keuzelijst.InsertString(10, "Carrental statistics");
	m_keuzelijst.InsertString(11, "Voucher list by number");
	m_keuzelijst.InsertString(12, "Voucher list by clients' name");

	GetDlgItem(IDC_DATEFROM_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_DATETO_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MAAND_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_JAAR_EDIT)->ShowWindow(SW_HIDE);	
	GetDlgItem(IDC_CODEFROM_EDIT)->ShowWindow(SW_HIDE);	
	GetDlgItem(IDC_OMSCHRIJVING_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_NUMBERFROM_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_NUMBERTO_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CLNAMEFROM_EDIT)->ShowWindow(SW_HIDE);	
	GetDlgItem(IDC_CLNAMETO_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CANCELLED_CHECK)->ShowWindow(SW_HIDE);	

	GetDlgItem(IDC_DATE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_DATETO_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SELECTIE_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TO_STATIC)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_ZOEK_BUTTON)->ShowWindow(SW_HIDE);

	EndWaitCursor();
}

void CFitovzView::OnSelchangeKeuzeList() 
{
	// TODO: Add your control notification handler code here
	int index;
	CStatic *date     = (CStatic *) GetDlgItem(IDC_DATE_STATIC);
	CStatic *dateto   = (CStatic *) GetDlgItem(IDC_DATETO_STATIC);
	CStatic *selectie = (CStatic *) GetDlgItem(IDC_SELECTIE_STATIC);
	CStatic *to       = (CStatic *) GetDlgItem(IDC_TO_STATIC);

	GetDlgItem(IDC_SELECTIE_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TO_STATIC)->ShowWindow(SW_SHOW);

	m_codefrom = "";
	m_omschrijving = "";
	UpdateData(FALSE);

	dateto->SetWindowText("to:");
	index = m_keuzelijst.GetCurSel();
	if (index == 0)
	{
		date->SetWindowText("Arrival date:     from:");
		selectie->SetWindowText("Hotelcode:");
		to->SetWindowText("-");

		GetDlgItem(IDC_ZOEK_BUTTON)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_DATE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATEFROM_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MAAND_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_JAAR_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CODEFROM_EDIT)->ShowWindow(SW_SHOW);	
		GetDlgItem(IDC_OMSCHRIJVING_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERFROM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERTO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CLNAMEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CLNAMETO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CANCELLED_CHECK)->ShowWindow(SW_HIDE);	
	}
	else if (index == 1)
	{
		date->SetWindowText("Arrival date:     from:");
		selectie->SetWindowText("Agentcode:");
		to->SetWindowText("-");

		GetDlgItem(IDC_ZOEK_BUTTON)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_DATE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_TO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATEFROM_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MAAND_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_JAAR_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CODEFROM_EDIT)->ShowWindow(SW_SHOW);	
		GetDlgItem(IDC_OMSCHRIJVING_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERFROM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERTO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CLNAMEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CLNAMETO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CANCELLED_CHECK)->ShowWindow(SW_HIDE);	
	}
	else if (index == 2)
	{
		date->SetWindowText("Arrival date:     from");
		selectie->SetWindowText("");
		to->SetWindowText("");

		GetDlgItem(IDC_ZOEK_BUTTON)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_DATE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_TO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATEFROM_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MAAND_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_JAAR_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CODEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_OMSCHRIJVING_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERFROM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERTO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CLNAMEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CLNAMETO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CANCELLED_CHECK)->ShowWindow(SW_HIDE);	
	}
	else if (index == 3)
	{
		date->SetWindowText("Arrival date:     from");
		selectie->SetWindowText("");
		to->SetWindowText("");

		GetDlgItem(IDC_ZOEK_BUTTON)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_DATE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_TO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATEFROM_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MAAND_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_JAAR_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CODEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_OMSCHRIJVING_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERFROM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERTO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CLNAMEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CLNAMETO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CANCELLED_CHECK)->ShowWindow(SW_HIDE);	
	}
	else if (index == 4)
	{
		date->SetWindowText("Arrival date:     from:");
		selectie->SetWindowText("Hotelcode:");
		to->SetWindowText("-");

		GetDlgItem(IDC_ZOEK_BUTTON)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_DATE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_TO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATEFROM_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MAAND_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_JAAR_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CODEFROM_EDIT)->ShowWindow(SW_SHOW);	
		GetDlgItem(IDC_OMSCHRIJVING_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERFROM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERTO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CLNAMEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CLNAMETO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CANCELLED_CHECK)->ShowWindow(SW_HIDE);	
	}
	else if (index == 5)
	{
		date->SetWindowText("Arrival date:     from:");
		selectie->SetWindowText("Passengers name:");
		to->SetWindowText("");

		GetDlgItem(IDC_ZOEK_BUTTON)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_DATE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_TO_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_DATEFROM_EDIT)->ShowWindow(TRUE);
		GetDlgItem(IDC_DATETO_EDIT)->ShowWindow(TRUE);
		GetDlgItem(IDC_MAAND_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_JAAR_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CODEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_OMSCHRIJVING_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(TRUE);
		GetDlgItem(IDC_NUMBERFROM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERTO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CLNAMEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CLNAMETO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CANCELLED_CHECK)->ShowWindow(SW_HIDE);	
	}
	else if (index == 6)
	{
		date->SetWindowText("Booking date:     from:");
		selectie->SetWindowText("Agentcode:");
		to->SetWindowText("-");

		GetDlgItem(IDC_ZOEK_BUTTON)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_DATE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_TO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATEFROM_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MAAND_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_JAAR_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CODEFROM_EDIT)->ShowWindow(SW_SHOW);	
		GetDlgItem(IDC_OMSCHRIJVING_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERFROM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERTO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CLNAMEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CLNAMETO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CANCELLED_CHECK)->ShowWindow(SW_SHOW);	
	}
	else if (index == 7)
	{
		date->SetWindowText("Maand:     ");
		selectie->SetWindowText("Hotelcode:");
		dateto->SetWindowText("Jaar:");

		GetDlgItem(IDC_ZOEK_BUTTON)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_DATE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATEFROM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_DATETO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MAAND_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_JAAR_EDIT)->ShowWindow(SW_SHOW);	
		GetDlgItem(IDC_CODEFROM_EDIT)->ShowWindow(SW_SHOW);	
		GetDlgItem(IDC_OMSCHRIJVING_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERFROM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERTO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CLNAMEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CLNAMETO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CANCELLED_CHECK)->ShowWindow(SW_HIDE);	
	}
	else if (index == 8)
	{
		date->SetWindowText("Arrival date:     from:");
		selectie->SetWindowText("Hotelcode:");
		to->SetWindowText("-");

		GetDlgItem(IDC_ZOEK_BUTTON)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_DATE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATEFROM_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MAAND_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_JAAR_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CODEFROM_EDIT)->ShowWindow(SW_SHOW);	
		GetDlgItem(IDC_OMSCHRIJVING_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERFROM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERTO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CLNAMEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CLNAMETO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CANCELLED_CHECK)->ShowWindow(SW_HIDE);	
	}
	else if (index == 9)
	{
		date->SetWindowText("Arrival date:     from:");
		selectie->SetWindowText("Hotelcode:");
		to->SetWindowText("-");

		GetDlgItem(IDC_ZOEK_BUTTON)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_DATE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATEFROM_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MAAND_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_JAAR_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CODEFROM_EDIT)->ShowWindow(SW_SHOW);	
		GetDlgItem(IDC_OMSCHRIJVING_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERFROM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERTO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CLNAMEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CLNAMETO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CANCELLED_CHECK)->ShowWindow(SW_HIDE);	
	}
	else if (index == 10)
	{
		date->SetWindowText("Arrival date:     from:");
		selectie->SetWindowText("Hotelcode:");
		to->SetWindowText("-");

		GetDlgItem(IDC_ZOEK_BUTTON)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_DATE_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATEFROM_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATETO_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MAAND_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_JAAR_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CODEFROM_EDIT)->ShowWindow(SW_SHOW);	
		GetDlgItem(IDC_OMSCHRIJVING_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERFROM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERTO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CLNAMEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CLNAMETO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CANCELLED_CHECK)->ShowWindow(SW_HIDE);	
	}
	else if (index == 11)
	{
		date->SetWindowText("Arrival date:     from:");
		selectie->SetWindowText("Voucher number:   from:");
		to->SetWindowText("to:");

		GetDlgItem(IDC_ZOEK_BUTTON)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_DATE_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_DATETO_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_TO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATEFROM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_DATETO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MAAND_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_JAAR_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CODEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_OMSCHRIJVING_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERFROM_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_NUMBERTO_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CLNAMEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CLNAMETO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CANCELLED_CHECK)->ShowWindow(SW_HIDE);	
	}
	else if (index == 12)
	{
		date->SetWindowText("Arrival date:     from:");
		selectie->SetWindowText("Clients name:     from:");
		to->SetWindowText("to:");

		GetDlgItem(IDC_ZOEK_BUTTON)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_DATE_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_DATETO_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_TO_STATIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_DATEFROM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_DATETO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MAAND_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_JAAR_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_CODEFROM_EDIT)->ShowWindow(SW_HIDE);	
		GetDlgItem(IDC_OMSCHRIJVING_STATIC)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NAAM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERFROM_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NUMBERTO_EDIT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CLNAMEFROM_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CLNAMETO_EDIT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CANCELLED_CHECK)->ShowWindow(SW_HIDE);	
	}
}

extern CTravelApp theApp;

void CFitovzView::OnOverviewButton() 
{
	// TODO: Add your control notification handler code here
	CString       aankomstdatum, vertrekdatum;
	BOOL          aankomst = FALSE;
	BOOL          vertrek = FALSE;
	BOOL          hotel = FALSE;
	BOOL          maand = FALSE;
	BOOL          jaar  = FALSE;
	int           index;
	CDatecnv      m_datecnv;
	CString       month;
	CString       year;

	index = m_keuzelijst.GetCurSel();


	UpdateData(TRUE);

	if (m_datefrom != "")
	{
		if (m_datefrom.GetLength() == 6)
			m_datefrom = m_datecnv.Datecontrole(m_datefrom);

		m_begin.ParseDateTime(m_datefrom, VAR_DATEVALUEONLY);
		if (m_begin.m_dt == 0)
		{
			m_datefrom = "";
			MessageBox("The startdate isn't correct !\n",
				"Controle", MB_OK + MB_ICONSTOP);
		}
		else
			aankomst = TRUE;
	}
	else
	{
		m_begin.SetDate(1900, 01, 01);
		aankomst   = TRUE;
	}

	if (m_dateto != "")
	{
		if (m_dateto.GetLength() == 6)
			m_dateto = m_datecnv.Datecontrole(m_dateto);

		m_einde.ParseDateTime(m_dateto, VAR_DATEVALUEONLY);
		if (m_einde.m_dt == 0)
		{
			m_dateto = "";
				MessageBox("The enddate isn't correct !\n",
				"Controle", MB_OK + MB_ICONSTOP);
		}
		else
			vertrek = TRUE;
	}
	else
	{
		m_einde.SetDate(2099, 01, 01);
		vertrek = TRUE;
	}

	if (m_codefrom == "" && index == 7)
	{
		MessageBox("No hotelcode has been filled in !\n",
			"Controle", MB_OK + MB_ICONSTOP);
	}
	else
		hotel = TRUE;

	if (m_maand >= 1 && m_maand <= 12 && index == 7)
	{
		if (m_maand < 10)
			month.Format("0%d", m_maand);
		else
			month.Format("%d", m_maand);

		if (month == "" && index == 7)
		{
			MessageBox("No month has been filled in !\n",
				"Controle", MB_OK + MB_ICONSTOP);
		}
		else
			maand = TRUE;
	}
	else if (index == 7)
		MessageBox("This isn't a correct month !\n",
			"Controle", MB_OK + MB_ICONSTOP);
	else
		maand = TRUE;

	year.Format("%d", m_jaar);
	if (year == "" && index == 7)
	{
		MessageBox("No year has been filled in !\n",
			"Controle", MB_OK + MB_ICONSTOP);
	}
	else
		jaar = TRUE;

	UpdateData(FALSE);

	if (aankomst && vertrek && hotel && maand && jaar)
	{
	theApp.selstartcode   = m_codefrom;
	theApp.selstartdate   = m_begin.Format("%Y%m%d");
	theApp.selenddate     = m_einde.Format("%Y%m%d");
	theApp.selmaand       = month;
	theApp.seljaar        = year;
	theApp.selname        = m_naam;
	theApp.selnumberfrom  = m_numberfrom;
	theApp.selnumberto    = m_numberto;
	theApp.selclnamefrom  = m_clnamefrom;
	theApp.selclnameto    = m_clnameto;
	theApp.selcancelled   = m_cancelled;

	if      (index == 0)
		theApp.ShowView("CFithotelView");
	else if (index == 1)
		theApp.ShowView("CFitagentView");
	else if (index == 2)
		theApp.ShowView("CFithotelallView");
	else if (index == 3)
		theApp.ShowView("CFitagentallView");
	else if (index == 4)
		theApp.ShowView("CFitcancelView");
	else if (index == 5)
		theApp.ShowView("CFitnamelistView");
	else if (index == 6)
		theApp.ShowView("CFitbookingdateView");
	else if (index == 7)
		theApp.ShowView("CFitallotmentView");
	else if (index == 8)
		theApp.ShowView("CFittransferView");
	else if (index == 9)
		theApp.ShowView("CFitexcursionView");
	else if (index == 10)
		theApp.ShowView("CFitcarrentalView");
	else if (index == 11)
		theApp.ShowView("CFitvouchernrView");
	else if (index == 12)
		theApp.ShowView("CFitvouchernameView");
	}
}

void CFitovzView::OnZoekButton() 
{
	// TODO: Add your control notification handler code here
	CZkhotelDlg m_zkhoteldlg;
	CZkagentDlg m_zkagentdlg;

	int index;

	index = m_keuzelijst.GetCurSel();

	if (index == 0 || index == 4 || index == 7 || index == 8|| index == 9|| index == 10)
	{
		m_zkhoteldlg.DoModal();
		if (m_zkhoteldlg.m_code != "")
		{
			m_codefrom = m_zkhoteldlg.m_code;
			m_omschrijving = m_zkhoteldlg.m_name;
		}
	}
	else if (index == 1 || index == 6)
	{
		m_zkagentdlg.DoModal();
		if (m_zkagentdlg.m_code != "")
		{
			m_codefrom = m_zkagentdlg.m_code;
			m_omschrijving = m_zkagentdlg.m_name;
		}
	}

	UpdateData(FALSE);
}

void CFitovzView::OnKillfocusCodefromEdit() 
{
	// TODO: Add your control notification handler code here
	
	CHotels m_sethotels;
	CAgents m_setagents;
	CString m_zoekwaarde;
	
	int index;

	UpdateData(TRUE);
	index = m_keuzelijst.GetCurSel();

	if (m_codefrom != "")
	{
		if (index == 0 || index == 4 || index == 7 || index == 8|| index == 9|| index == 10)
		{
			m_zoekwaarde = "ho_code = '" + m_codefrom + "'";
			m_sethotels.m_strFilter = m_zoekwaarde;
			m_sethotels.Open();	

			if (!m_sethotels.IsEOF())
				m_omschrijving = m_sethotels.m_ho_name;
			else
				MessageBox("This hotelcode doesn't exist !\n",
					"Searching hotelname", MB_OK + MB_ICONSTOP);

			m_sethotels.Close();
		}
		else if ((index == 1 || index == 6) && m_codefrom != "ZZZ")
		{
			m_zoekwaarde = "ag_code = '" + m_codefrom + "'";
			m_setagents.m_strFilter = m_zoekwaarde;
			m_setagents.Open();

			if (!m_setagents.IsEOF())
				m_omschrijving = m_setagents.m_ag_name;
			else
				MessageBox("This agentcode doesn't exist !\n",
					"Searching agentname", MB_OK + MB_ICONSTOP);

			m_setagents.Close();
		}
	}

	UpdateData(FALSE);
}

void CFitovzView::OnDestroy() 
{
	CFormView::OnDestroy();
	
	// TODO: Add your message handler code here
	theApp.fitoverviewsview = FALSE;
}

void CFitovzView::OnDblclkKeuzeList() 
{
	// TODO: Add your control notification handler code here
	OnOverviewButton();
}
