// ZkbookingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "travel.h"
#include "ZkbookingDlg.h"

#include "booking.h"
#include "datecnv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZkbookingDlg dialog


CZkbookingDlg::CZkbookingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZkbookingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZkbookingDlg)
	//}}AFX_DATA_INIT
}


void CZkbookingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZkbookingDlg)
	DDX_Control(pDX, IDC_LIJST_LIST, m_lijst);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CZkbookingDlg, CDialog)
	//{{AFX_MSG_MAP(CZkbookingDlg)
	ON_LBN_DBLCLK(IDC_LIJST_LIST, OnDblclkLijstList)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIJST_LIST, OnColumnclickLijstList)
	ON_NOTIFY(NM_DBLCLK, IDC_LIJST_LIST, OnDblclkLijstList)
	ON_NOTIFY(NM_CLICK, IDC_LIJST_LIST, OnClickLijstList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZkbookingDlg message handlers

BOOL CZkbookingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CBooking m_setbooking;
	CString m_zoekwaarde;
	LV_COLUMN m_column;
	LV_ITEM m_tekstitem;
	int i;
	CDatecnv m_datecnv;

	m_column.mask = LVCF_WIDTH | LVCF_TEXT;

	m_column.cx   = 80;
	m_column.pszText  = "Code";
	m_lijst.InsertColumn(0, &m_column);

	m_column.cx   = 150;
	m_column.pszText  = "Hotel";
	m_lijst.InsertColumn(1, &m_column);

	m_column.cx   = 150;
	m_column.pszText  = "Passenger";
	m_lijst.InsertColumn(2, &m_column);

	m_column.cx   = 100;
	m_column.pszText  = "Arrival";
	m_lijst.InsertColumn(3, &m_column);


	m_tekstitem.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
	m_tekstitem.state     = 0;
	m_tekstitem.stateMask = 0;
	m_tekstitem.iImage    = 0;

	i = 0;

	m_setbooking.m_strSort = "bo_tourref";
	if (!m_fit)
	{	
		m_zoekwaarde = "bo_cancel = '0'";
		m_setbooking.m_strFilter = m_zoekwaarde;
		m_setbooking.Open();
	}
	else
	{	
		m_zoekwaarde = "bo_invoice = FALSE AND bo_cancel <= '0'";
		m_setbooking.m_strFilter = m_zoekwaarde;
		m_setbooking.Open();
	}

	while (!m_setbooking.IsEOF())
	{
		m_tekstitem.iItem    = i;
		m_tekstitem.iSubItem = 0;
		m_tekstitem.pszText  = "code";
		m_lijst.InsertItem(&m_tekstitem);
		m_lijst.SetItemText(i, 0, m_setbooking.m_bo_tourref);
		m_tekstitem.iItem    = i;
		m_tekstitem.iSubItem = 1;
		m_tekstitem.pszText  = "hotel";
		m_lijst.InsertItem(&m_tekstitem);
		m_lijst.SetItemText(i, 1, m_setbooking.m_ho_name);
		m_tekstitem.iSubItem = 2;
		m_tekstitem.pszText  = "passenger";
		m_lijst.InsertItem(&m_tekstitem);
		m_lijst.SetItemText(i, 2, m_setbooking.m_bo_passn);
		m_tekstitem.iSubItem = 3;
		m_tekstitem.pszText  = "arrival";
		m_lijst.InsertItem(&m_tekstitem);
		m_lijst.SetItemText(i, 3, m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate));

		i++;
		m_setbooking.MoveNext();
	}
	m_setbooking.Close();

	m_item = -1;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CZkbookingDlg::OnOK() 
{
	// TODO: Add extra validation here
	char m_hotelcode[12];

	if (m_item != -1)
	{
		m_lijst.GetItemText(m_item, 0, m_hotelcode, 12);
		m_tourref = (CString) m_hotelcode;
	}
	else
		m_tourref = "";

	CDialog::OnOK();
}

void CZkbookingDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	m_tourref = "";
	
	CDialog::OnCancel();
}

void CZkbookingDlg::OnDblclkLijstList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	char m_hotelcode[12];

	m_item = pNMListView->iItem;
	if (m_item != -1)
	{
		m_lijst.GetItemText(m_item, 0, m_hotelcode, 12);
		m_tourref = (CString) m_hotelcode;

		CDialog::OnOK();
	}

	*pResult = 0;
}

void CZkbookingDlg::OnColumnclickLijstList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	CBooking m_setbooking;
	LV_ITEM m_tekstitem;
	CString m_zoekwaarde;
	int i;
	int m_kolom;
	CDatecnv m_datecnv;

	m_tekstitem.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
	m_tekstitem.state     = 0;
	m_tekstitem.stateMask = 0;
	m_tekstitem.iImage    = 0;

	m_lijst.DeleteAllItems();

	m_kolom = pNMListView->iSubItem;

	if (m_kolom == 0)
		m_setbooking.m_strSort = "bo_tourref";
	else if (m_kolom == 1)
		m_setbooking.m_strSort = "ho_name";
	else if (m_kolom == 2)
		m_setbooking.m_strSort = "bo_passn";
	else if (m_kolom == 3)
		m_setbooking.m_strSort = "bo_tourref";

	i = 0;
	if (!m_fit)
	{	
		m_zoekwaarde = "bo_cancel = '0'";
		m_setbooking.m_strFilter = m_zoekwaarde;
		m_setbooking.Open();
	}
	else
	{	
		m_zoekwaarde = "bo_invoice = FALSE AND bo_cancel <= '0'";
		m_setbooking.m_strFilter = m_zoekwaarde;
		m_setbooking.Open();
	}

	while (!m_setbooking.IsEOF())
	{
		m_tekstitem.iItem    = i;
		m_tekstitem.iSubItem = 0;
		m_tekstitem.pszText  = "code";
		m_lijst.InsertItem(&m_tekstitem);
		m_lijst.SetItemText(i, 0, m_setbooking.m_bo_tourref);
		m_tekstitem.iItem    = i;
		m_tekstitem.iSubItem = 1;
		m_tekstitem.pszText  = "hotel";
		m_lijst.InsertItem(&m_tekstitem);
		m_lijst.SetItemText(i, 1, m_setbooking.m_ho_name);
		m_tekstitem.iSubItem = 2;
		m_tekstitem.pszText  = "passenger";
		m_lijst.InsertItem(&m_tekstitem);
		m_lijst.SetItemText(i, 2, m_setbooking.m_bo_passn);
		m_tekstitem.iSubItem = 3;
		m_tekstitem.pszText  = "arrival";
		m_lijst.InsertItem(&m_tekstitem);
		m_lijst.SetItemText(i, 3, m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate));

		i++;
		m_setbooking.MoveNext();
	}
	m_setbooking.Close();

	*pResult = 0;
}

void CZkbookingDlg::OnClickLijstList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	
	m_item = pNMListView->iItem;
	
	*pResult = 0;
}
