#if !defined(AFX_TOEGANG_H__660552A0_B7DC_11D4_BC1C_006097638FC1__INCLUDED_)
#define AFX_TOEGANG_H__660552A0_B7DC_11D4_BC1C_006097638FC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Toegang.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CToegang recordset

class CToegang : public CRecordset
{
public:
	CToegang(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CToegang)

// Field/Param Data
	//{{AFX_FIELD(CToegang, CRecordset)
	CString	m_functie;
	int		m_groep;
	BOOL	m_tonen;
	BOOL	m_nieuw;
	BOOL	m_wijzigen;
	BOOL	m_verwijderen;
	BOOL	m_cancellen;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToegang)
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

#endif // !defined(AFX_TOEGANG_H__660552A0_B7DC_11D4_BC1C_006097638FC1__INCLUDED_)
