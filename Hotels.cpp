// Hotels.cpp : implementation file
//

#include "stdafx.h"
#include "travel.h"
#include "Hotels.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHotels

IMPLEMENT_DYNAMIC(CHotels, CRecordset)

CHotels::CHotels(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CHotels)
	m_ho_code = _T("");
	m_ho_name = _T("");
	m_ho_addr1 = _T("");
	m_ho_addr2 = _T("");
	m_ho_zipcode = _T("");
	m_ho_city = _T("");
	m_ho_country = _T("");
	m_ho_tel = _T("");
	m_ho_telres = _T("");
	m_ho_fax = _T("");
	m_ho_email = _T("");
	m_ho_from1 = _T("");
	m_ho_from2 = _T("");
	m_ho_from3 = _T("");
	m_ho_from4 = _T("");
	m_ho_from5 = _T("");
	m_ho_from6 = _T("");
	m_ho_till1 = _T("");
	m_ho_till2 = _T("");
	m_ho_till3 = _T("");
	m_ho_till4 = _T("");
	m_ho_till5 = _T("");
	m_ho_till6 = _T("");
	m_ho_sngls1 = 0.0;
	m_ho_sngls2 = 0.0;
	m_ho_sngls3 = 0.0;
	m_ho_sngls4 = 0.0;
	m_ho_sngls5 = 0.0;
	m_ho_sngls6 = 0.0;
	m_ho_tsu1 = 0.0;
	m_ho_tsu2 = 0.0;
	m_ho_tsu3 = 0.0;
	m_ho_tsu4 = 0.0;
	m_ho_tsu5 = 0.0;
	m_ho_tsu6 = 0.0;
	m_ho_dbls1 = 0.0;
	m_ho_dbls2 = 0.0;
	m_ho_dbls3 = 0.0;
	m_ho_dbls4 = 0.0;
	m_ho_dbls5 = 0.0;
	m_ho_dbls6 = 0.0;
	m_ho_twns1 = 0.0;
	m_ho_twns2 = 0.0;
	m_ho_twns3 = 0.0;
	m_ho_twns4 = 0.0;
	m_ho_twns5 = 0.0;
	m_ho_twns6 = 0.0;
	m_ho_trpls1 = 0.0;
	m_ho_trpls2 = 0.0;
	m_ho_trpls3 = 0.0;
	m_ho_trpls4 = 0.0;
	m_ho_trpls5 = 0.0;
	m_ho_trpls6 = 0.0;
	m_ho_qds1 = 0.0;
	m_ho_qds2 = 0.0;
	m_ho_qds3 = 0.0;
	m_ho_qds4 = 0.0;
	m_ho_qds5 = 0.0;
	m_ho_qds6 = 0.0;
	m_ho_mltpls1 = 0.0;
	m_ho_mltpls2 = 0.0;
	m_ho_mltpls3 = 0.0;
	m_ho_mltpls4 = 0.0;
	m_ho_mltpls5 = 0.0;
	m_ho_mltpls6 = 0.0;
	m_nFields = 65;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CHotels::GetDefaultConnect()
{
	return _T("ODBC;DSN=travel");
}

CString CHotels::GetDefaultSQL()
{
	return _T("[HOTELS]");
}

void CHotels::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CHotels)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[ho_code]"), m_ho_code);
	RFX_Text(pFX, _T("[ho_name]"), m_ho_name);
	RFX_Text(pFX, _T("[ho_addr1]"), m_ho_addr1);
	RFX_Text(pFX, _T("[ho_addr2]"), m_ho_addr2);
	RFX_Text(pFX, _T("[ho_zipcode]"), m_ho_zipcode);
	RFX_Text(pFX, _T("[ho_city]"), m_ho_city);
	RFX_Text(pFX, _T("[ho_country]"), m_ho_country);
	RFX_Text(pFX, _T("[ho_tel]"), m_ho_tel);
	RFX_Text(pFX, _T("[ho_telres]"), m_ho_telres);
	RFX_Text(pFX, _T("[ho_fax]"), m_ho_fax);
	RFX_Text(pFX, _T("[ho_email]"), m_ho_email);
	RFX_Text(pFX, _T("[ho_from1]"), m_ho_from1);
	RFX_Text(pFX, _T("[ho_from2]"), m_ho_from2);
	RFX_Text(pFX, _T("[ho_from3]"), m_ho_from3);
	RFX_Text(pFX, _T("[ho_from4]"), m_ho_from4);
	RFX_Text(pFX, _T("[ho_from5]"), m_ho_from5);
	RFX_Text(pFX, _T("[ho_from6]"), m_ho_from6);
	RFX_Text(pFX, _T("[ho_till1]"), m_ho_till1);
	RFX_Text(pFX, _T("[ho_till2]"), m_ho_till2);
	RFX_Text(pFX, _T("[ho_till3]"), m_ho_till3);
	RFX_Text(pFX, _T("[ho_till4]"), m_ho_till4);
	RFX_Text(pFX, _T("[ho_till5]"), m_ho_till5);
	RFX_Text(pFX, _T("[ho_till6]"), m_ho_till6);
	RFX_Double(pFX, _T("[ho_sngls1]"), m_ho_sngls1);
	RFX_Double(pFX, _T("[ho_sngls2]"), m_ho_sngls2);
	RFX_Double(pFX, _T("[ho_sngls3]"), m_ho_sngls3);
	RFX_Double(pFX, _T("[ho_sngls4]"), m_ho_sngls4);
	RFX_Double(pFX, _T("[ho_sngls5]"), m_ho_sngls5);
	RFX_Double(pFX, _T("[ho_sngls6]"), m_ho_sngls6);
	RFX_Double(pFX, _T("[ho_tsu1]"), m_ho_tsu1);
	RFX_Double(pFX, _T("[ho_tsu2]"), m_ho_tsu2);
	RFX_Double(pFX, _T("[ho_tsu3]"), m_ho_tsu3);
	RFX_Double(pFX, _T("[ho_tsu4]"), m_ho_tsu4);
	RFX_Double(pFX, _T("[ho_tsu5]"), m_ho_tsu5);
	RFX_Double(pFX, _T("[ho_tsu6]"), m_ho_tsu6);
	RFX_Double(pFX, _T("[ho_dbls1]"), m_ho_dbls1);
	RFX_Double(pFX, _T("[ho_dbls2]"), m_ho_dbls2);
	RFX_Double(pFX, _T("[ho_dbls3]"), m_ho_dbls3);
	RFX_Double(pFX, _T("[ho_dbls4]"), m_ho_dbls4);
	RFX_Double(pFX, _T("[ho_dbls5]"), m_ho_dbls5);
	RFX_Double(pFX, _T("[ho_dbls6]"), m_ho_dbls6);
	RFX_Double(pFX, _T("[ho_twns1]"), m_ho_twns1);
	RFX_Double(pFX, _T("[ho_twns2]"), m_ho_twns2);
	RFX_Double(pFX, _T("[ho_twns3]"), m_ho_twns3);
	RFX_Double(pFX, _T("[ho_twns4]"), m_ho_twns4);
	RFX_Double(pFX, _T("[ho_twns5]"), m_ho_twns5);
	RFX_Double(pFX, _T("[ho_twns6]"), m_ho_twns6);
	RFX_Double(pFX, _T("[ho_trpls1]"), m_ho_trpls1);
	RFX_Double(pFX, _T("[ho_trpls2]"), m_ho_trpls2);
	RFX_Double(pFX, _T("[ho_trpls3]"), m_ho_trpls3);
	RFX_Double(pFX, _T("[ho_trpls4]"), m_ho_trpls4);
	RFX_Double(pFX, _T("[ho_trpls5]"), m_ho_trpls5);
	RFX_Double(pFX, _T("[ho_trpls6]"), m_ho_trpls6);
	RFX_Double(pFX, _T("[ho_qds1]"), m_ho_qds1);
	RFX_Double(pFX, _T("[ho_qds2]"), m_ho_qds2);
	RFX_Double(pFX, _T("[ho_qds3]"), m_ho_qds3);
	RFX_Double(pFX, _T("[ho_qds4]"), m_ho_qds4);
	RFX_Double(pFX, _T("[ho_qds5]"), m_ho_qds5);
	RFX_Double(pFX, _T("[ho_qds6]"), m_ho_qds6);
	RFX_Double(pFX, _T("[ho_mltpls1]"), m_ho_mltpls1);
	RFX_Double(pFX, _T("[ho_mltpls2]"), m_ho_mltpls2);
	RFX_Double(pFX, _T("[ho_mltpls3]"), m_ho_mltpls3);
	RFX_Double(pFX, _T("[ho_mltpls4]"), m_ho_mltpls4);
	RFX_Double(pFX, _T("[ho_mltpls5]"), m_ho_mltpls5);
	RFX_Double(pFX, _T("[ho_mltpls6]"), m_ho_mltpls6);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CHotels diagnostics

#ifdef _DEBUG
void CHotels::AssertValid() const
{
	CRecordset::AssertValid();
}

void CHotels::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
