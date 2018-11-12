// ToegangsView.cpp : implementation file
//

#include "stdafx.h"
#include "travel.h"
#include "ToegangsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToegangsView

IMPLEMENT_DYNCREATE(CToegangsView, CFormView)

CToegangsView::CToegangsView()
	: CFormView(CToegangsView::IDD)
{
	//{{AFX_DATA_INIT(CToegangsView)
	m_add0 = FALSE;
	m_add1 = FALSE;
	m_add2 = FALSE;
	m_add3 = FALSE;
	m_add4 = FALSE;
	m_add5 = FALSE;
	m_cancel0 = FALSE;
	m_cancel1 = FALSE;
	m_cancel2 = FALSE;
	m_cancel3 = FALSE;
	m_cancel4 = FALSE;
	m_cancel5 = FALSE;
	m_change0 = FALSE;
	m_change1 = FALSE;
	m_change2 = FALSE;
	m_change3 = FALSE;
	m_change4 = FALSE;
	m_change5 = FALSE;
	m_delete0 = FALSE;
	m_delete1 = FALSE;
	m_delete2 = FALSE;
	m_delete3 = FALSE;
	m_delete4 = FALSE;
	m_delete5 = FALSE;
	m_show0 = FALSE;
	m_show1 = FALSE;
	m_show2 = FALSE;
	m_show3 = FALSE;
	m_show4 = FALSE;
	m_show5 = FALSE;
	m_show = _T("");
	m_functie = _T("");
	//}}AFX_DATA_INIT
}

CToegangsView::~CToegangsView()
{
}

void CToegangsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CToegangsView)
	DDX_Check(pDX, IDC_ADD0_CHECK, m_add0);
	DDX_Check(pDX, IDC_ADD1_CHECK, m_add1);
	DDX_Check(pDX, IDC_ADD2_CHECK, m_add2);
	DDX_Check(pDX, IDC_ADD3_CHECK, m_add3);
	DDX_Check(pDX, IDC_ADD4_CHECK, m_add4);
	DDX_Check(pDX, IDC_ADD5_CHECK, m_add5);
	DDX_Check(pDX, IDC_CANCEL0_CHECK, m_cancel0);
	DDX_Check(pDX, IDC_CANCEL1_CHECK, m_cancel1);
	DDX_Check(pDX, IDC_CANCEL2_CHECK, m_cancel2);
	DDX_Check(pDX, IDC_CANCEL3_CHECK, m_cancel3);
	DDX_Check(pDX, IDC_CANCEL4_CHECK, m_cancel4);
	DDX_Check(pDX, IDC_CANCEL5_CHECK, m_cancel5);
	DDX_Check(pDX, IDC_CHANGE0_CHECK, m_change0);
	DDX_Check(pDX, IDC_CHANGE1_CHECK, m_change1);
	DDX_Check(pDX, IDC_CHANGE2_CHECK, m_change2);
	DDX_Check(pDX, IDC_CHANGE3_CHECK, m_change3);
	DDX_Check(pDX, IDC_CHANGE4_CHECK, m_change4);
	DDX_Check(pDX, IDC_CHANGE5_CHECK, m_change5);
	DDX_Check(pDX, IDC_DELETE0_CHECK, m_delete0);
	DDX_Check(pDX, IDC_DELETE1_CHECK, m_delete1);
	DDX_Check(pDX, IDC_DELETE2_CHECK, m_delete2);
	DDX_Check(pDX, IDC_DELETE3_CHECK, m_delete3);
	DDX_Check(pDX, IDC_DELETE4_CHECK, m_delete4);
	DDX_Check(pDX, IDC_DELETE5_CHECK, m_delete5);
	DDX_Check(pDX, IDC_SHOW0_CHECK, m_show0);
	DDX_Check(pDX, IDC_SHOW1_CHECK, m_show1);
	DDX_Check(pDX, IDC_SHOW2_CHECK, m_show2);
	DDX_Check(pDX, IDC_SHOW3_CHECK, m_show3);
	DDX_Check(pDX, IDC_SHOW4_CHECK, m_show4);
	DDX_Check(pDX, IDC_SHOW5_CHECK, m_show5);
	DDX_Text(pDX, IDC_SHOW_STATIC, m_show);
	DDX_Text(pDX, IDC_FUNCTIE_STATIC, m_functie);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CToegangsView, CFormView)
	//{{AFX_MSG_MAP(CToegangsView)
	ON_WM_DESTROY()
	ON_COMMAND(IDC_TONEN_BUTTON, OnTonenButton)
	ON_UPDATE_COMMAND_UI(IDC_TONEN_BUTTON, OnUpdateTonenButton)
	ON_COMMAND(IDC_WIJZIGEN_BUTTON, OnWijzigenButton)
	ON_UPDATE_COMMAND_UI(IDC_WIJZIGEN_BUTTON, OnUpdateWijzigenButton)
	ON_COMMAND(IDC_NIETOPSLAAN_BUTTON, OnNietopslaanButton)
	ON_UPDATE_COMMAND_UI(IDC_NIETOPSLAAN_BUTTON, OnUpdateNietopslaanButton)
	ON_COMMAND(IDC_OPSLAAN_BUTTON, OnOpslaanButton)
	ON_UPDATE_COMMAND_UI(IDC_OPSLAAN_BUTTON, OnUpdateOpslaanButton)
	ON_COMMAND(IDC_VOLGENDE_BUTTON, OnVolgendeButton)
	ON_COMMAND(IDC_VORIGE_BUTTON, OnVorigeButton)
	ON_BN_CLICKED(IDC_ADD0_CHECK, OnAdd0Check)
	ON_BN_CLICKED(IDC_ADD1_CHECK, OnAdd1Check)
	ON_BN_CLICKED(IDC_ADD2_CHECK, OnAdd2Check)
	ON_BN_CLICKED(IDC_ADD3_CHECK, OnAdd3Check)
	ON_BN_CLICKED(IDC_ADD4_CHECK, OnAdd4Check)
	ON_BN_CLICKED(IDC_ADD5_CHECK, OnAdd5Check)
	ON_BN_CLICKED(IDC_CANCEL0_CHECK, OnCancel0Check)
	ON_BN_CLICKED(IDC_CANCEL1_CHECK, OnCancel1Check)
	ON_BN_CLICKED(IDC_CANCEL2_CHECK, OnCancel2Check)
	ON_BN_CLICKED(IDC_CANCEL3_CHECK, OnCancel3Check)
	ON_BN_CLICKED(IDC_CANCEL4_CHECK, OnCancel4Check)
	ON_BN_CLICKED(IDC_CANCEL5_CHECK, OnCancel5Check)
	ON_BN_CLICKED(IDC_CHANGE0_CHECK, OnChange0Check)
	ON_BN_CLICKED(IDC_CHANGE1_CHECK, OnChange1Check)
	ON_BN_CLICKED(IDC_CHANGE2_CHECK, OnChange2Check)
	ON_BN_CLICKED(IDC_CHANGE3_CHECK, OnChange3Check)
	ON_BN_CLICKED(IDC_CHANGE4_CHECK, OnChange4Check)
	ON_BN_CLICKED(IDC_CHANGE5_CHECK, OnChange5Check)
	ON_BN_CLICKED(IDC_DELETE0_CHECK, OnDelete0Check)
	ON_BN_CLICKED(IDC_DELETE1_CHECK, OnDelete1Check)
	ON_BN_CLICKED(IDC_DELETE2_CHECK, OnDelete2Check)
	ON_BN_CLICKED(IDC_DELETE3_CHECK, OnDelete3Check)
	ON_BN_CLICKED(IDC_DELETE4_CHECK, OnDelete4Check)
	ON_BN_CLICKED(IDC_DELETE5_CHECK, OnDelete5Check)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToegangsView diagnostics

#ifdef _DEBUG
void CToegangsView::AssertValid() const
{
	CFormView::AssertValid();
}

void CToegangsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CToegangsView message handlers

extern CTravelApp theApp;

void CToegangsView::OnInitialUpdate() 
{
	BeginWaitCursor();

	// change our size to a nice size :)
	ResizeParentToFit(false);

	CFormView::OnInitialUpdate();

	CString  m_zoekwaarde;
	CString  m_groep;

//	m_settoegang.m_strSort   = "functie";

	if (theApp.groep == -1)
	{
		m_toegang_tonen       = TRUE;
		m_toegang_wijzigen    = TRUE;
	}
	else
	{
		m_groep.Format("%d", theApp.groep);

		m_zoekwaarde = "functie = 'toegang' AND groep = " + m_groep;
		m_settoegang.m_strFilter = m_zoekwaarde;
		m_settoegang.Open();
		m_toegang_tonen       = m_settoegang.m_tonen;
		m_toegang_wijzigen    = m_settoegang.m_wijzigen;
		m_settoegang.Close();
	}

	m_settoegang.m_strFilter = "";
	m_settoegang.Open();

	OnTonenButton();

	EndWaitCursor();
}

void CToegangsView::OnDestroy() 
{
	CFormView::OnDestroy();
	
	// TODO: Add your message handler code here
	
	m_settoegang.Close();
	theApp.toegangsview = FALSE;
}

void CToegangsView::OnTonenButton() 
{
	// TODO: Add your command handler code here
	
	GetDocument()->SetTitle("Entrance - SHOW");
	m_tonen = TRUE;
	veldenediten(FALSE);
	recordweergeven();
}

void CToegangsView::OnWijzigenButton() 
{
	// TODO: Add your command handler code here
	
	GetDocument()->SetTitle("Entrance - CHANGE");
	m_tonen = FALSE;
	veldenediten(TRUE);
	recordweergeven();
}

void CToegangsView::OnNietopslaanButton() 
{
	// TODO: Add your command handler code here
	
	recordweergeven();
}

void CToegangsView::OnOpslaanButton() 
{
	// TODO: Add your command handler code here
	
	UpdateData(TRUE);

	m_settoegang.Edit();
	m_settoegang.m_nieuw= m_add0;
	m_settoegang.m_cancellen = m_cancel0;
	m_settoegang.m_wijzigen = m_change0;
	m_settoegang.m_verwijderen = m_delete0;
	m_settoegang.m_tonen = m_show0;
	m_settoegang.Update();

	m_settoegang.MoveNext();
	m_settoegang.Edit();
	m_settoegang.m_nieuw = m_add1;
	m_settoegang.m_cancellen = m_cancel1;
	m_settoegang.m_wijzigen = m_change1;
	m_settoegang.m_verwijderen = m_delete1;
	m_settoegang.m_tonen = m_show1;
	m_settoegang.Update();

	m_settoegang.MoveNext();
	m_settoegang.Edit();
	m_settoegang.m_nieuw = m_add2;
	m_settoegang.m_cancellen = m_cancel2;
	m_settoegang.m_wijzigen = m_change2;
	m_settoegang.m_verwijderen = m_delete2;
	m_settoegang.m_tonen = m_show2;
	m_settoegang.Update();

	m_settoegang.MoveNext();
	m_settoegang.Edit();
	m_settoegang.m_nieuw = m_add3;
	m_settoegang.m_cancellen = m_cancel3;
	m_settoegang.m_wijzigen = m_change3;
	m_settoegang.m_verwijderen = m_delete3;
	m_settoegang.m_tonen = m_show3;
	m_settoegang.Update();

	m_settoegang.MoveNext();
	m_settoegang.Edit();
	m_settoegang.m_verwijderen = m_delete4;
	m_settoegang.m_tonen = m_show4;
	m_settoegang.m_nieuw = m_add4;
	m_settoegang.m_cancellen = m_cancel4;
	m_settoegang.m_wijzigen = m_change4;
	m_settoegang.Update();

	m_settoegang.MoveNext();
	m_settoegang.Edit();
	m_settoegang.m_nieuw = m_add5;
	m_settoegang.m_cancellen = m_cancel5;
	m_settoegang.m_wijzigen = m_change5;
	m_settoegang.m_verwijderen = m_delete5;
	m_settoegang.m_tonen = m_show5;
	m_settoegang.Update();

	int i;

	for (i = 1; i <= 5; i++)
		m_settoegang.MovePrev();
}

void CToegangsView::OnVorigeButton() 
{
	// TODO: Add your command handler code here
	
	int i;

	if (m_settoegang.m_functie != "agents")
	{
		for (i = 0; i <= 5; i++)
			m_settoegang.MovePrev();
		recordweergeven();
	}
}

void CToegangsView::OnVolgendeButton() 
{
	// TODO: Add your command handler code here

	int i;

	if (m_settoegang.m_functie != "vouchers")
	{
		for (i = 0; i <= 5; i++)
			m_settoegang.MoveNext();
		recordweergeven();
	}
}

void CToegangsView::veldenediten(BOOL edit)
{
	GetDlgItem(IDC_ADD0_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_ADD1_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_ADD2_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_ADD3_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_ADD4_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_ADD5_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_CANCEL0_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_CANCEL1_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_CANCEL2_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_CANCEL3_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_CANCEL4_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_CANCEL5_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_CHANGE0_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_CHANGE1_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_CHANGE2_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_CHANGE3_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_CHANGE4_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_CHANGE5_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_DELETE0_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_DELETE1_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_DELETE2_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_DELETE3_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_DELETE4_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_DELETE5_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_SHOW0_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_SHOW1_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_SHOW2_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_SHOW3_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_SHOW4_CHECK)->EnableWindow(edit);
	GetDlgItem(IDC_SHOW5_CHECK)->EnableWindow(edit);
}

void CToegangsView::recordweergeven()
{
	m_functie = m_settoegang.m_functie;

	if (!m_tonen)
	{
		if (m_functie == "toegang"   || m_functie == "cnvexact6" ||
			m_functie == "configuration" || m_functie == "fitinv" ||
			m_functie == "printseries")
		{
			GetDlgItem(IDC_ADD0_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_ADD1_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_ADD2_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_ADD3_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_ADD4_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_ADD5_CHECK)->EnableWindow(FALSE);
		}
		else
		{
			GetDlgItem(IDC_ADD0_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_ADD1_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_ADD2_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_ADD3_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_ADD4_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_ADD5_CHECK)->EnableWindow(TRUE);
		}

		if (m_functie == "cnvexact6" || m_functie == "configuration" || 
			m_functie == "fitinv" || m_functie == "printseries")
		{
			GetDlgItem(IDC_CHANGE0_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_CHANGE1_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_CHANGE2_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_CHANGE3_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_CHANGE4_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_CHANGE5_CHECK)->EnableWindow(FALSE);
		}
		else
		{
			GetDlgItem(IDC_CHANGE0_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_CHANGE1_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_CHANGE2_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_CHANGE3_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_CHANGE4_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_CHANGE5_CHECK)->EnableWindow(TRUE);
		}

		if (m_functie == "allotment" || m_functie == "invoices" ||
			m_functie == "toegang"   || m_functie == "cnvexact6" ||
			m_functie == "configuration" || m_functie == "fitinv" ||
			m_functie == "printseries")
		{
			GetDlgItem(IDC_DELETE0_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_DELETE1_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_DELETE2_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_DELETE3_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_DELETE4_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_DELETE5_CHECK)->EnableWindow(FALSE);
		}
		else
		{
			GetDlgItem(IDC_DELETE0_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_DELETE1_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_DELETE2_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_DELETE3_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_DELETE4_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_DELETE5_CHECK)->EnableWindow(TRUE);
		}
	
		if (m_functie == "fit" || m_functie == "groups")
		{
			GetDlgItem(IDC_CANCEL0_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_CANCEL1_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_CANCEL2_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_CANCEL3_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_CANCEL4_CHECK)->EnableWindow(TRUE);
			GetDlgItem(IDC_CANCEL5_CHECK)->EnableWindow(TRUE);
		}
		else
		{
			GetDlgItem(IDC_CANCEL0_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_CANCEL1_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_CANCEL2_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_CANCEL3_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_CANCEL4_CHECK)->EnableWindow(FALSE);
			GetDlgItem(IDC_CANCEL5_CHECK)->EnableWindow(FALSE);
		}
	}

	if (m_functie == "cnvexact6" || m_functie == "configuration" || 
			m_functie == "fitinv" || m_functie == "printseries")
		m_show = "Use:";
	else
		m_show = "Show:";

	if      (m_functie == "cnvexact6")
		m_functie = "conversie exact6";
	else if (m_functie == "toegang")
		m_functie = "entrance";
	else if (m_functie == "fitinv")
		m_functie = "invoice from fit";
	else if (m_functie == "printseries")
		m_functie = "print series";
	else if (m_functie == "fit")
		m_functie = "fit booking";
	else if (m_functie == "groups")
		m_functie = "groups booking";

	m_add0    = m_settoegang.m_nieuw;
	m_cancel0 = m_settoegang.m_cancellen;
	m_change0 = m_settoegang.m_wijzigen;
	m_delete0 = m_settoegang.m_verwijderen;
	m_show0   = m_settoegang.m_tonen;
	m_settoegang.MoveNext();
	m_add1    = m_settoegang.m_nieuw;
	m_cancel1 = m_settoegang.m_cancellen;
	m_change1 = m_settoegang.m_wijzigen;
	m_delete1 = m_settoegang.m_verwijderen;
	m_show1   = m_settoegang.m_tonen;
	m_settoegang.MoveNext();
	m_add2    = m_settoegang.m_nieuw;
	m_cancel2 = m_settoegang.m_cancellen;
	m_change2 = m_settoegang.m_wijzigen;
	m_delete2 = m_settoegang.m_verwijderen;
	m_show2   = m_settoegang.m_tonen;
	m_settoegang.MoveNext();
	m_add3    = m_settoegang.m_nieuw;
	m_cancel3 = m_settoegang.m_cancellen;
	m_change3 = m_settoegang.m_wijzigen;
	m_delete3 = m_settoegang.m_verwijderen;
	m_show3   = m_settoegang.m_tonen;
	m_settoegang.MoveNext();
	m_add4    = m_settoegang.m_nieuw;
	m_cancel4 = m_settoegang.m_cancellen;
	m_change4 = m_settoegang.m_wijzigen;
	m_delete4 = m_settoegang.m_verwijderen;
	m_show4   = m_settoegang.m_tonen;
	m_settoegang.MoveNext();
	m_add5    = m_settoegang.m_nieuw;
	m_cancel5 = m_settoegang.m_cancellen;
	m_change5 = m_settoegang.m_wijzigen;
	m_delete5 = m_settoegang.m_verwijderen;
	m_show5   = m_settoegang.m_tonen;

	int i;

	for (i = 1; i <= 5; i++)
		m_settoegang.MovePrev();

	UpdateData(FALSE);
}

void CToegangsView::OnUpdateOpslaanButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (!m_tonen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CToegangsView::OnUpdateNietopslaanButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (!m_tonen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CToegangsView::OnUpdateTonenButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_toegang_tonen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CToegangsView::OnUpdateWijzigenButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here

	if (m_toegang_wijzigen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CToegangsView::OnAdd0Check() 
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	if (m_add0)
		m_show0 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnAdd1Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_add1)
		m_show1 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnAdd2Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_add2)
		m_show2 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnAdd3Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_add3)
		m_show3 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnAdd4Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_add4)
		m_show4 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnAdd5Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_add5)
		m_show5 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnCancel0Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_cancel0)
		m_show0 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnCancel1Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_cancel1)
		m_show1 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnCancel2Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_cancel2)
		m_show2 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnCancel3Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_cancel3)
		m_show3 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnCancel4Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_cancel4)
		m_show4 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnCancel5Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_cancel5)
		m_show5 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnChange0Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_change0)
		m_show0 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnChange1Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_change1)
		m_show1 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnChange2Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_change2)
		m_show2 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnChange3Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_change3)
		m_show3 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnChange4Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_change4)
		m_show4 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnChange5Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_change5)
		m_show5 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnDelete0Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_delete0)
		m_show0 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnDelete1Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_delete1)
		m_show1 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnDelete2Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_delete2)
		m_show2 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnDelete3Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_delete3)
		m_show3 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnDelete4Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_delete4)
		m_show4 = TRUE;

	UpdateData(FALSE);
}

void CToegangsView::OnDelete5Check() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	if (m_delete5)
		m_show5 = TRUE;

	UpdateData(FALSE);
}
