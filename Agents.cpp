// Agents.cpp : implementation file
//

#include "stdafx.h"
#include "travel.h"
#include "Agents.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAgents

IMPLEMENT_DYNAMIC(CAgents, CRecordset)

CAgents::CAgents(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAgents)
	m_ag_code = _T("");
	m_ag_name = _T("");
	m_ag_addr1 = _T("");
	m_ag_addr2 = _T("");
	m_ag_zipcode = _T("");
	m_ag_city = _T("");
	m_ag_country = _T("");
	m_ag_departm = _T("");
	m_ag_tel = _T("");
	m_ag_fax = _T("");
	m_ag_email = _T("");
	m_ag_lang = _T("");
	m_ag_number = _T("");
	m_ag_vatnr = _T("");
	m_ag_price = _T("");
	m_ag_remark = _T("");
	m_nFields = 16;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CAgents::GetDefaultConnect()
{
	return _T("ODBC;DSN=travel");
}

CString CAgents::GetDefaultSQL()
{
	return _T("[AGENTS]");
}

void CAgents::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAgents)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[ag_code]"), m_ag_code);
	RFX_Text(pFX, _T("[ag_name]"), m_ag_name);
	RFX_Text(pFX, _T("[ag_addr1]"), m_ag_addr1);
	RFX_Text(pFX, _T("[ag_addr2]"), m_ag_addr2);
	RFX_Text(pFX, _T("[ag_zipcode]"), m_ag_zipcode);
	RFX_Text(pFX, _T("[ag_city]"), m_ag_city);
	RFX_Text(pFX, _T("[ag_country]"), m_ag_country);
	RFX_Text(pFX, _T("[ag_departm]"), m_ag_departm);
	RFX_Text(pFX, _T("[ag_tel]"), m_ag_tel);
	RFX_Text(pFX, _T("[ag_fax]"), m_ag_fax);
	RFX_Text(pFX, _T("[ag_email]"), m_ag_email);
	RFX_Text(pFX, _T("[ag_lang]"), m_ag_lang);
	RFX_Text(pFX, _T("[ag_number]"), m_ag_number);
	RFX_Text(pFX, _T("[ag_vatnr]"), m_ag_vatnr);
	RFX_Text(pFX, _T("[ag_price]"), m_ag_price);
	RFX_Text(pFX, _T("[ag_remark]"), m_ag_remark);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAgents diagnostics

#ifdef _DEBUG
void CAgents::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAgents::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
