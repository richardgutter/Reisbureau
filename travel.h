// travel.h : main header file for the TRAVEL application
//

#if !defined(AFX_TRAVEL_H__EB8EA664_F699_11D3_BC1B_006097638FC1__INCLUDED_)
#define AFX_TRAVEL_H__EB8EA664_F699_11D3_BC1B_006097638FC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTravelApp:
// See travel.cpp for the implementation of this class
//

class CTravelApp : public CWinApp
{
public:
	CView * ShowView( const char * pszViewName);
	CTravelApp();


	CString gebruiker;
	int     groep;
	CString dateformat;

	BOOL    usersview;
	BOOL    toegangsview;
	BOOL    agentsview;
	BOOL    allotmentview;
	BOOL    hotelsview;
	BOOL    coachesview;
	BOOL    guidesview;
	BOOL    restaurantsview;
	BOOL    menusview;
	BOOL    vatview;
    BOOL    fitbookingsview;
	BOOL    fitoverviewsview;
	BOOL    groupsbookingsview;
	BOOL    groupshotelsview;
	BOOL    groupsexcursionsview;
	BOOL    groupsguidesview;
	BOOL    groupseventsview;
	BOOL    groupsmealsview;
	BOOL    groupsothersview;
	BOOL    groupsoverviewsview;
	BOOL    invoicesview;
	BOOL    cnvexact6view;
	BOOL    proformaview;
	BOOL    invoicefromfitview;
	BOOL    invprintseriesview;
	BOOL    vouchersview;

	CString status;
	BOOL    cancelled;
	CString tourref;
	int     pax;
	CString restaurantcode;
	int     totaantal;
	CString grpbegindatum;
	CString grpeinddatum;
	CString groupsname;

	CString excitin;
	CString excpickup;
	CString excpickupdate;
	CString excpickuptime;
	CString excdropoff;
	CString excdropoffdate;
	CString excdropofftime;
	CString exccocode;
	CString excconame;

	CString selstartcode;
	CString selstartdate;
	CString selenddate;
	CString selmaand;
	CString seljaar;
	CString selname;
	long    selnumberfrom;
	long    selnumberto;
	CString selclnamefrom;
	CString selclnameto;
	BOOL    selcancelled;

	CString selstatus;
	CString sellanguage;
	CString selgroupsname;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTravelApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTravelApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAVEL_H__EB8EA664_F699_11D3_BC1B_006097638FC1__INCLUDED_)
