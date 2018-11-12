#if !defined(AFX_HOTELS_H__13821880_8A8A_11D4_BC1C_006097638FC1__INCLUDED_)
#define AFX_HOTELS_H__13821880_8A8A_11D4_BC1C_006097638FC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Hotels.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHotels recordset

class CHotels : public CRecordset
{
public:
	CHotels(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CHotels)

// Field/Param Data
	//{{AFX_FIELD(CHotels, CRecordset)
	CString	m_ho_code;
	CString	m_ho_name;
	CString	m_ho_addr1;
	CString	m_ho_addr2;
	CString	m_ho_zipcode;
	CString	m_ho_city;
	CString	m_ho_country;
	CString	m_ho_tel;
	CString	m_ho_telres;
	CString	m_ho_fax;
	CString	m_ho_email;
	CString	m_ho_from1;
	CString	m_ho_from2;
	CString	m_ho_from3;
	CString	m_ho_from4;
	CString	m_ho_from5;
	CString	m_ho_from6;
	CString	m_ho_till1;
	CString	m_ho_till2;
	CString	m_ho_till3;
	CString	m_ho_till4;
	CString	m_ho_till5;
	CString	m_ho_till6;
	double	m_ho_sngls1;
	double	m_ho_sngls2;
	double	m_ho_sngls3;
	double	m_ho_sngls4;
	double	m_ho_sngls5;
	double	m_ho_sngls6;
	double	m_ho_tsu1;
	double	m_ho_tsu2;
	double	m_ho_tsu3;
	double	m_ho_tsu4;
	double	m_ho_tsu5;
	double	m_ho_tsu6;
	double	m_ho_dbls1;
	double	m_ho_dbls2;
	double	m_ho_dbls3;
	double	m_ho_dbls4;
	double	m_ho_dbls5;
	double	m_ho_dbls6;
	double	m_ho_twns1;
	double	m_ho_twns2;
	double	m_ho_twns3;
	double	m_ho_twns4;
	double	m_ho_twns5;
	double	m_ho_twns6;
	double	m_ho_trpls1;
	double	m_ho_trpls2;
	double	m_ho_trpls3;
	double	m_ho_trpls4;
	double	m_ho_trpls5;
	double	m_ho_trpls6;
	double	m_ho_qds1;
	double	m_ho_qds2;
	double	m_ho_qds3;
	double	m_ho_qds4;
	double	m_ho_qds5;
	double	m_ho_qds6;
	double	m_ho_mltpls1;
	double	m_ho_mltpls2;
	double	m_ho_mltpls3;
	double	m_ho_mltpls4;
	double	m_ho_mltpls5;
	double	m_ho_mltpls6;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHotels)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOTELS_H__13821880_8A8A_11D4_BC1C_006097638FC1__INCLUDED_)
