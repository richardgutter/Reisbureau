// AgentsView.cpp : implementation file
//

#include "stdafx.h"
#include "travel.h"
#include "AgentsView.h"

#include "Agents.h"
#include "Toegang.h"
#include "Languages.h"
#include "ZkagentDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAgentsView

IMPLEMENT_DYNCREATE(CAgentsView, CFormView)

CAgentsView::CAgentsView()
	: CFormView(CAgentsView::IDD)
{
	//{{AFX_DATA_INIT(CAgentsView)
	m_address1 = _T("");
	m_address2 = _T("");
	m_code = _T("");
	m_department = _T("");
	m_fax = _T("");
	m_naam = _T("");
	m_tel = _T("");
	m_vat = _T("");
	m_pricecat1 = -1;
	m_remark = _T("");
	m_city = _T("");
	m_country = _T("");
	m_email = _T("");
	m_zipcode = _T("");
	m_number = _T("");
	m_language = _T("");
	//}}AFX_DATA_INIT
}

CAgentsView::~CAgentsView()
{
}

void CAgentsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAgentsView)
	DDX_Control(pDX, IDC_LANGUAGE_COMBO, m_language_cntrl);
	DDX_Control(pDX, IDC_ZIPCODE_EDIT, m_zipcode_cntrl);
	DDX_Control(pDX, IDC_VAT_EDIT, m_vat_cntrl);
	DDX_Control(pDX, IDC_TEL_EDIT, m_tel_cntrl);
	DDX_Control(pDX, IDC_REMARK_EDIT, m_remark_cntrl);
	DDX_Control(pDX, IDC_PRICECAT1_RADIO, m_pricecat1_cntrl);
	DDX_Control(pDX, IDC_NUMBER_EDIT, m_number_cntrl);
	DDX_Control(pDX, IDC_NAAM_EDIT, m_naam_cntrl);
	DDX_Control(pDX, IDC_FAX_EDIT, m_fax_cntrl);
	DDX_Control(pDX, IDC_EMAIL_EDIT, m_email_cntrl);
	DDX_Control(pDX, IDC_DEPARTMENT_EDIT, m_department_cntrl);
	DDX_Control(pDX, IDC_COUNTRY_EDIT, m_country_cntrl);
	DDX_Control(pDX, IDC_CODE_EDIT, m_code_cntrl);
	DDX_Control(pDX, IDC_CITY_EDIT, m_city_cntrl);
	DDX_Control(pDX, IDC_ADDRESS2_EDIT, m_address2_cntrl);
	DDX_Control(pDX, IDC_ADDRESS1_EDIT, m_address1_cntrl);
	DDX_Text(pDX, IDC_ADDRESS1_EDIT, m_address1);
	DDV_MaxChars(pDX, m_address1, 30);
	DDX_Text(pDX, IDC_ADDRESS2_EDIT, m_address2);
	DDV_MaxChars(pDX, m_address2, 30);
	DDX_Text(pDX, IDC_CODE_EDIT, m_code);
	DDV_MaxChars(pDX, m_code, 3);
	DDX_Text(pDX, IDC_DEPARTMENT_EDIT, m_department);
	DDV_MaxChars(pDX, m_department, 30);
	DDX_Text(pDX, IDC_FAX_EDIT, m_fax);
	DDV_MaxChars(pDX, m_fax, 15);
	DDX_Text(pDX, IDC_NAAM_EDIT, m_naam);
	DDV_MaxChars(pDX, m_naam, 30);
	DDX_Text(pDX, IDC_TEL_EDIT, m_tel);
	DDV_MaxChars(pDX, m_tel, 15);
	DDX_Text(pDX, IDC_VAT_EDIT, m_vat);
	DDV_MaxChars(pDX, m_vat, 11);
	DDX_Radio(pDX, IDC_PRICECAT1_RADIO, m_pricecat1);
	DDX_Text(pDX, IDC_REMARK_EDIT, m_remark);
	DDV_MaxChars(pDX, m_remark, 50);
	DDX_Text(pDX, IDC_CITY_EDIT, m_city);
	DDV_MaxChars(pDX, m_city, 30);
	DDX_Text(pDX, IDC_COUNTRY_EDIT, m_country);
	DDV_MaxChars(pDX, m_country, 30);
	DDX_Text(pDX, IDC_EMAIL_EDIT, m_email);
	DDV_MaxChars(pDX, m_email, 30);
	DDX_Text(pDX, IDC_ZIPCODE_EDIT, m_zipcode);
	DDV_MaxChars(pDX, m_zipcode, 10);
	DDX_Text(pDX, IDC_NUMBER_EDIT, m_number);
	DDV_MaxChars(pDX, m_number, 5);
	DDX_CBString(pDX, IDC_LANGUAGE_COMBO, m_language);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAgentsView, CFormView)
	//{{AFX_MSG_MAP(CAgentsView)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_VERWIJDEREN_BUTTON, OnVerwijderenButton)
	ON_BN_CLICKED(IDC_VOLGENDE_BUTTON, OnVolgendeButton)
	ON_BN_CLICKED(IDC_VORIGE_BUTTON, OnVorigeButton)
	ON_BN_CLICKED(IDC_WIJZIGEN_BUTTON, OnWijzigenButton)
	ON_BN_CLICKED(IDC_OPSLAAN_BUTTON, OnOpslaanButton)
	ON_BN_CLICKED(IDC_NIEUW_BUTTON, OnNieuwButton)
	ON_BN_CLICKED(IDC_NIETOPSLAAN_BUTTON, OnNietopslaanButton)
	ON_BN_CLICKED(IDC_CODE_BUTTON, OnCodeButton)
	ON_EN_KILLFOCUS(IDC_CODE_EDIT, OnKillfocusCodeEdit)
	ON_UPDATE_COMMAND_UI(IDC_VOLGENDE_BUTTON, OnUpdateVolgendeButton)
	ON_UPDATE_COMMAND_UI(IDC_VORIGE_BUTTON, OnUpdateVorigeButton)
	ON_UPDATE_COMMAND_UI(IDC_OPSLAAN_BUTTON, OnUpdateOpslaanButton)
	ON_UPDATE_COMMAND_UI(IDC_NIETOPSLAAN_BUTTON, OnUpdateNietopslaanButton)
	ON_BN_CLICKED(IDC_TONEN_BUTTON, OnTonenButton)
	ON_UPDATE_COMMAND_UI(IDC_VERWIJDEREN_BUTTON, OnUpdateVerwijderenButton)
	ON_WM_DESTROY()
	ON_UPDATE_COMMAND_UI(IDC_WIJZIGEN_BUTTON, OnUpdateWijzigenButton)
	ON_UPDATE_COMMAND_UI(IDC_TONEN_BUTTON, OnUpdateTonenButton)
	ON_UPDATE_COMMAND_UI(IDC_NIEUW_BUTTON, OnUpdateNieuwButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAgentsView diagnostics

#ifdef _DEBUG
void CAgentsView::AssertValid() const
{
	CFormView::AssertValid();
}

void CAgentsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAgentsView message handlers

extern CTravelApp theApp;

void CAgentsView::OnInitialUpdate() 
{
	CLanguages m_setlanguages;

	BeginWaitCursor();
	GetDocument()->SetTitle("Agents - SHOW");

	CFormView::OnInitialUpdate();
	
	// change our size to a nice size :)
	ResizeParentToFit(false);

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

		m_zoekwaarde = "functie = 'agents' AND groep = " + m_groep;
		m_toegang.m_strFilter = m_zoekwaarde;
		m_toegang.Open();
		m_toegang_tonen       = m_toegang.m_tonen;
		m_toegang_toevoegen   = m_toegang.m_nieuw;
		m_toegang_wijzigen    = m_toegang.m_wijzigen;
		m_toegang_verwijderen = m_toegang.m_verwijderen;
		m_toegang.Close();
	}

	m_setagents.Open();
	if (!m_setagents.IsEOF())
		OnTonenButton();
	else
		OnNieuwButton();

	m_setlanguages.Open();
	while (!m_setlanguages.IsEOF())
	{
		m_language_cntrl.AddString(m_setlanguages.m_language);
		m_setlanguages.MoveNext();
	}
	m_setlanguages.Close();

	EndWaitCursor();
}

void CAgentsView::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	m_setagents.Close();

	CFormView::OnClose();
}

void CAgentsView::OnTonenButton() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->SetTitle("Agents - SHOW");

	m_tonen       = TRUE;
	m_nieuw       = FALSE;
	m_wijzigen    = FALSE;
	m_verwijderen = FALSE;

	GetDlgItem(IDC_CODE_BUTTON)->ShowWindow(SW_SHOW);

	veldenediten(FALSE);
	if (!m_setagents.IsEOF())
		recordweergeven();
	else
		veldenleegmaken();
}

void CAgentsView::OnNieuwButton() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->SetTitle("Agents - ADD");

	m_tonen       = FALSE;
	m_nieuw       = TRUE;
	m_wijzigen    = FALSE;
	m_verwijderen = FALSE;

	GetDlgItem(IDC_CODE_BUTTON)->ShowWindow(SW_HIDE);

	veldenediten(TRUE);
	veldenleegmaken();
}

void CAgentsView::OnWijzigenButton() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->SetTitle("Agents - CHANGE");

	m_tonen       = FALSE;
	m_nieuw       = FALSE;
	m_wijzigen    = TRUE;
	m_verwijderen = FALSE;

	GetDlgItem(IDC_CODE_BUTTON)->ShowWindow(SW_SHOW);

	veldenediten(TRUE);
	if (!m_setagents.IsEOF())
		recordweergeven();
	else
		veldenleegmaken();
}

void CAgentsView::OnVerwijderenButton() 
{
	// TODO: Add your control notification handler code here
	GetDocument()->SetTitle("Agents - DELETE");

	m_tonen       = FALSE;
	m_nieuw       = FALSE;
	m_wijzigen    = FALSE;
	m_verwijderen = TRUE;

	GetDlgItem(IDC_CODE_BUTTON)->ShowWindow(SW_SHOW);

	veldenediten(FALSE);
	if (!m_setagents.IsEOF())
		recordweergeven();
	else
		veldenleegmaken();
}

void CAgentsView::OnNietopslaanButton() 
{
	// TODO: Add your control notification handler code here
	recordweergeven();
}

void CAgentsView::OnOpslaanButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (OpslaanCheck())
	{
		if (m_nieuw)
		{
			m_setagents.AddNew();
			inhoudopslaan();
			m_setagents.Update();
			m_setagents.Requery();
			veldenleegmaken();
		}
		else if (m_wijzigen)
		{
			m_setagents.Edit();
			inhoudopslaan();
			m_setagents.Update();
		}
		else if (m_verwijderen)
		{
			m_setagents.Delete();
			if (m_setagents.IsEOF())
				veldenleegmaken();
			else
			{
				m_setagents.MoveFirst();
				recordweergeven();
			}
		}
	}
}

BOOL CAgentsView::OpslaanCheck() 
{
	if (m_nieuw)
		if (MessageBox("Are you sure, you want to add this data?",
			"Update data", MB_OKCANCEL  + MB_ICONEXCLAMATION) != IDOK)
			return FALSE;

	if ((m_wijzigen || m_verwijderen) && m_setagents.IsEOF())
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

	if (m_code == "" || m_naam == "" || m_number == "")
	{
		MessageBox("Agentcode, name and clientnumber must be filled both !\n",
			"Update data", MB_OK + MB_ICONSTOP);

		return FALSE;
	}

	if (m_nieuw && aanwezig())
	{	
			MessageBox("The agentcode already exists !\n",
				"Update data", MB_OK + MB_ICONSTOP);

		return FALSE;
	}

	return TRUE;
}

void CAgentsView::OnVorigeButton() 
{
	// TODO: Add your control notification handler code here
	if (!m_setagents.IsBOF())
	{
		m_setagents.MovePrev();
		if (m_setagents.IsBOF())
			m_setagents.MoveNext();
		recordweergeven();
	}
}

void CAgentsView::OnVolgendeButton() 
{
	// TODO: Add your control notification handler code here
	if (!m_setagents.IsEOF())
	{
		m_setagents.MoveNext();
		if (m_setagents.IsEOF())
			m_setagents.MovePrev();
		recordweergeven();
	}
}

void CAgentsView::OnKillfocusCodeEdit() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (!m_nieuw && m_code != ""
		&& m_setagents.m_ag_code != m_code
		&& !m_setagents.IsEOF())
	{
		SetCursor(LoadCursor(NULL, IDC_WAIT));

		if (m_setagents.m_ag_code.CompareNoCase(m_code) < 0)
		{
			while (m_setagents.m_ag_code.CompareNoCase(m_code) < 0
					&& !m_setagents.IsEOF())		
				m_setagents.MoveNext();
			if (m_setagents.IsEOF())
				m_setagents.MovePrev();
		}
		else
		{
			m_setagents.MoveFirst();
			while (m_setagents.m_ag_code.CompareNoCase(m_code) < 0
					&& !m_setagents.IsEOF())
				m_setagents.MoveNext();
		}

		recordweergeven();
		SetCursor(LoadCursor(NULL, IDC_ARROW));
	}
}

BOOL CAgentsView::aanwezig()
{
	BOOL aanwezig;

	if (!m_setagents.IsEOF())
	{
		m_setagents.MoveFirst();
		while (!m_setagents.IsEOF() 
				&& m_setagents.m_ag_code.CompareNoCase(m_code) < 0)
			m_setagents.MoveNext();

		if (m_setagents.m_ag_code.CompareNoCase(m_code) == 0)
			aanwezig = TRUE;
		else
			aanwezig = FALSE;
	}
	else 
		aanwezig = FALSE;

	return aanwezig;
}

void CAgentsView::veldenediten(BOOL edit)
{
	m_address1_cntrl.SetReadOnly(!edit);
	m_address2_cntrl.SetReadOnly(!edit);
	m_department_cntrl.SetReadOnly(!edit);
	m_fax_cntrl.SetReadOnly(!edit);
	m_naam_cntrl.SetReadOnly(!edit);
	m_tel_cntrl.SetReadOnly(!edit);
	m_vat_cntrl.SetReadOnly(!edit);
	m_remark_cntrl.SetReadOnly(!edit);
	m_city_cntrl.SetReadOnly(!edit);
	m_country_cntrl.SetReadOnly(!edit);
	m_email_cntrl.SetReadOnly(!edit);
	m_zipcode_cntrl.SetReadOnly(!edit);
	m_number_cntrl.SetReadOnly(!edit);

	GetDlgItem(IDC_PRICECAT1_RADIO)->EnableWindow(edit);
	GetDlgItem(IDC_PRICECAT2_RADIO)->EnableWindow(edit);
	GetDlgItem(IDC_LANGUAGE_COMBO)->EnableWindow(edit);
}

void CAgentsView::recordweergeven()
{
	m_code         = m_setagents.m_ag_code;
	m_naam         = m_setagents.m_ag_name;
	m_address1     = m_setagents.m_ag_addr1;
	m_address2     = m_setagents.m_ag_addr2;
	m_zipcode      = m_setagents.m_ag_zipcode;
	m_city         = m_setagents.m_ag_city;
	m_country      = m_setagents.m_ag_country;
	m_email        = m_setagents.m_ag_email;
	m_department   = m_setagents.m_ag_departm;
	m_tel          = m_setagents.m_ag_tel;
	m_fax          = m_setagents.m_ag_fax;
	m_number       = m_setagents.m_ag_number;
	m_vat          = m_setagents.m_ag_vatnr;
	m_remark       = m_setagents.m_ag_remark;
	m_language     = m_setagents.m_ag_lang;

	if (m_setagents.m_ag_price == "1")
		m_pricecat1 = 0;
	else
		m_pricecat1 = 1;

	UpdateData(FALSE);
}

void CAgentsView::veldenleegmaken()
{
	m_code         = "";
	m_naam         = "";
	m_address1     = "";
	m_address2     = "";
	m_zipcode      = "";
	m_city         = "";
	m_country      = "";
	m_department   = "";
	m_tel          = "";
	m_fax          = "";
	m_email        = "";
	m_number       = "";
	m_vat          = "";
	m_pricecat1    = 0;
	m_remark       = "";
	m_language     = "";

	UpdateData(FALSE);
}

void CAgentsView::inhoudopslaan()
{
	if (m_nieuw)
		m_setagents.m_ag_code    = m_code;
	m_setagents.m_ag_name    = m_naam;
	m_setagents.m_ag_addr1   = m_address1;
	m_setagents.m_ag_addr2   = m_address2;
	m_setagents.m_ag_zipcode = m_zipcode;
	m_setagents.m_ag_city    = m_city;
	m_setagents.m_ag_country = m_country;
	m_setagents.m_ag_email   = m_email;
	m_setagents.m_ag_departm = m_department;
	m_setagents.m_ag_tel     = m_tel;
	m_setagents.m_ag_fax     = m_fax;
	m_setagents.m_ag_number  = m_number;
	m_setagents.m_ag_vatnr   = m_vat;
	m_setagents.m_ag_remark  = m_remark;
	m_setagents.m_ag_lang    = m_language;

	if (m_pricecat1 == 0)
		m_setagents.m_ag_price = "1";
	else
		m_setagents.m_ag_price = "2";
}

void CAgentsView::OnCodeButton() 
{
	// TODO: Add your control notification handler code here
	CZkagentDlg dlg;
	dlg.DoModal();
	if (dlg.m_code != "")
	{
		m_code = dlg.m_code;
		UpdateData(FALSE);
		OnKillfocusCodeEdit();
	}
}

void CAgentsView::OnUpdateVolgendeButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (!m_nieuw)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CAgentsView::OnUpdateVorigeButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (!m_nieuw)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CAgentsView::OnUpdateOpslaanButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (!m_tonen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CAgentsView::OnUpdateNietopslaanButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (!m_tonen && !m_verwijderen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CAgentsView::OnUpdateVerwijderenButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_toegang_verwijderen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CAgentsView::OnDestroy() 
{
	CFormView::OnDestroy();
	
	// TODO: Add your message handler code here
	theApp.agentsview = FALSE;
}

void CAgentsView::OnUpdateWijzigenButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_setagents.GetRecordCount() > 0 && m_toegang_wijzigen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CAgentsView::OnUpdateTonenButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_setagents.GetRecordCount() > 0 && m_toegang_tonen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}

void CAgentsView::OnUpdateNieuwButton(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	if (m_toegang_toevoegen)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);
}
