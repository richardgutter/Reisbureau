// Toegang.cpp : implementation file
//

#include "stdafx.h"
#include "travel.h"
#include "Toegang.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToegang

IMPLEMENT_DYNAMIC(CToegang, CRecordset)

CToegang::CToegang(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CToegang)
	m_functie = _T("");
	m_groep = 0;
	m_tonen = FALSE;
	m_nieuw = FALSE;
	m_wijzigen = FALSE;
	m_verwijderen = FALSE;
	m_cancellen = FALSE;
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CToegang::GetDefaultConnect()
{
	return _T("ODBC;DSN=travel");
}

CString CToegang::GetDefaultSQL()
{
	return _T("[TOEGANG]");
}

void CToegang::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CToegang)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[functie]"), m_functie);
	RFX_Int(pFX, _T("[groep]"), m_groep);
	RFX_Bool(pFX, _T("[tonen]"), m_tonen);
	RFX_Bool(pFX, _T("[nieuw]"), m_nieuw);
	RFX_Bool(pFX, _T("[wijzigen]"), m_wijzigen);
	RFX_Bool(pFX, _T("[verwijderen]"), m_verwijderen);
	RFX_Bool(pFX, _T("[cancellen]"), m_cancellen);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CToegang diagnostics

#ifdef _DEBUG
void CToegang::AssertValid() const
{
	CRecordset::AssertValid();
}

void CToegang::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
