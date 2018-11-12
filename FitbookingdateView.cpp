// FitbookingdateView.cpp : implementation file
//

#include "stdafx.h"
#include "travel.h"
#include "FitbookingdateView.h"

#include <string.h>
#include "booking.h"
#include "datecnv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFitbookingdateView

IMPLEMENT_DYNCREATE(CFitbookingdateView, CScrollView)

CFitbookingdateView::CFitbookingdateView()
{
}

CFitbookingdateView::~CFitbookingdateView()
{
}


BEGIN_MESSAGE_MAP(CFitbookingdateView, CScrollView)
	//{{AFX_MSG_MAP(CFitbookingdateView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFitbookingdateView drawing

extern CTravelApp theApp;

void CFitbookingdateView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
	GetDocument()->SetTitle("FIT Bookingdate-overview");

	m_selstartcode = theApp.selstartcode;
	m_selstartdate = theApp.selstartdate;
	m_selenddate = theApp.selenddate;
	m_selname = theApp.selname;
	m_selnumberfrom = theApp.selnumberfrom;
	m_selnumberto = theApp.selnumberto;
	m_selclnamefrom = theApp.selclnamefrom;
	m_selclnameto = theApp.selclnameto;
	m_selcancelled = theApp.selcancelled;

	CString m_zoekwaarde;

	m_setbooking.m_strSort  = "bo_passn, bo_date";

	if (m_selcancelled)
		m_zoekwaarde = "bo_cancel > '0'";
	else
		m_zoekwaarde = "bo_cancel = '0'";

	// titel + lege regel
	m_aantal_regels_kop = 2;

	// hotel code
	if (m_selstartcode != "")
	{
		m_zoekwaarde += " and ag_code = '" + m_selstartcode + "'";
		m_aantal_regels_kop++;
	}

	// start datum
	if (m_selstartdate != "19000101")
	{
		m_zoekwaarde += " and bo_arrdate >= '" + m_selstartdate + "'";
		m_aantal_regels_kop++;
	}

	// eind datum
	if (m_selenddate != "20990101")
	{
		if ( !m_zoekwaarde.IsEmpty())
			m_zoekwaarde += " and ";
		m_zoekwaarde += "bo_arrdate <= '" + m_selenddate + "'";
		if (m_selstartdate == "19000101")
			m_aantal_regels_kop++;
	}

	// record header + lege regel
	m_aantal_regels_kop += 2;

	// set filter
	m_setbooking.m_strFilter = m_zoekwaarde;
	m_setbooking.Open();
	
	if (!m_setbooking.IsEOF())
		m_setbooking.MoveFirst();
	int i = 0;
	while (!m_setbooking.IsEOF() && i <= 2000)
	{
		m_setbooking.MoveNext();
		i++;
	}

	if ( m_setbooking.GetRecordCount() == 0)
		MessageBox("No results !");

	if ( m_setbooking.GetRecordCount() > 2000)
	{
		MessageBox("The maximum is 2000 records !");
		m_aantal_regels = 2000 + m_aantal_regels_kop;
	}
	else
		m_aantal_regels = m_setbooking.GetRecordCount() + m_aantal_regels_kop;
}

void CFitbookingdateView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	LOGFONT m_logfont;
	SIZE m_size;
	int paginahoogte = pDC->GetDeviceCaps(VERTRES);
		
	m_logfont.lfCharSet = ANSI_CHARSET;

	if (!pDC->IsPrinting())
		m_logfont.lfHeight  = 15;
	else
		m_logfont.lfHeight  = 100;

	m_logfont.lfWidth = 0;
	m_logfont.lfEscapement = 0;
	m_logfont.lfOrientation = 0;
	m_logfont.lfWeight = FW_NORMAL;
	m_logfont.lfItalic = 0;
	m_logfont.lfUnderline = 0;
	m_logfont.lfStrikeOut = 0;
	m_logfont.lfOutPrecision = OUT_DEFAULT_PRECIS;
	m_logfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	m_logfont.lfQuality = PROOF_QUALITY;
	m_logfont.lfPitchAndFamily = VARIABLE_PITCH |FF_ROMAN;
	strcpy(m_logfont.lfFaceName, "Times New Roman");

	CFont* m_font = new CFont();
	m_font->CreateFontIndirect(&m_logfont);
	CFont* m_oldfont = pDC->SelectObject(m_font);

	if (!pDC->IsPrinting())
	{
		m_p_start_regel = GetScrollPos(1) / 15;
		CRect rc;
		this->GetWindowRect( &rc);
		m_p_aantal_regels = rc.Height() / 15;
		ovz_fitbookingdate(pDC, 1);
	}
	else
		prnt_fitbookingdate(pDC, 0.5);

	pDC->SelectObject(m_oldfont);
	delete m_font;

	m_size.cx = 1200;
	m_size.cy = m_aantal_regels * 15;

	SetScrollSizes(MM_TEXT, m_size);
}

void CFitbookingdateView::ovz_fitbookingdate(CDC* pDC,  double factor)
{
	int y = 5;
	char m_getalchar[10];
	CString m_getalstr;
	CString m_bookingdate;
	CDatecnv m_datecnv;

	if (m_selcancelled)
		pDC->TextOut(factor * 5 ,y, "BOOKING  DATE  STATISTICS  -  CANCELLED  BOOKINGS");
	else
		pDC->TextOut(factor * 5 ,y, "BOOKING  DATE  STATISTICS  -  CONFIRMED  BOOKINGS");
	y += 15;
	if (m_selstartcode != "")
	{
		pDC->TextOut(factor * 5 ,y, m_setbooking.m_ag_name);
		y += 15;
	}
	if (m_selstartdate != "19000101")
	{
		pDC->TextOut(factor * 5 ,y, m_datecnv.Datetoddmmjjjj(m_selstartdate) + "   -");
	}
	if (m_selenddate != "20990101")
	{
		pDC->TextOut(factor * 105 ,y, m_datecnv.Datetoddmmjjjj(m_selenddate));
	}
	if (m_selstartdate != "19000101" || m_selenddate != "20990101")
	{
		y += 15;
	}
	y += 15;

	pDC->TextOut(factor * 5,  y, "bkd on");
//	pDC->TextOut(factor * 5,  y, "agentref");
	pDC->TextOut(factor * 100,y, "passenger");
	pDC->TextOut(factor * 350,y, "tourref");
	pDC->TextOut(factor * 450,y, "hotelname");
	pDC->TextOut(factor * 700,y, "arrivaldate");
	pDC->TextOut(factor * 800,y, "ngts");
	pDC->TextOut(factor * 850,y, "sgl");
	pDC->TextOut(factor * 900,y, "tsu");
	pDC->TextOut(factor * 950,y, "twn");
	pDC->TextOut(factor * 1000,y, "dbl");
	pDC->TextOut(factor * 1050,y, "trp");
	pDC->TextOut(factor * 1100,y, "qds");
	pDC->TextOut(factor * 1150,y, "mltp");
	y += 30;
	
	// spring naar eerste te printen record
	m_setbooking.MoveFirst();
	if ( m_p_start_regel > m_aantal_regels_kop)
	{
		y = m_aantal_regels_kop * 15 + (m_p_start_regel - m_aantal_regels_kop) * 15;
		m_setbooking.Move( m_p_start_regel - m_aantal_regels_kop);
	}
	else
		y = m_aantal_regels_kop * 15 ;

	long rows = m_p_aantal_regels;
	CString tekst, eerste, rest;

	while (!m_setbooking.IsEOF() && rows)
	{
		pDC->TextOut(factor * 5,y, m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_date));

		tekst = m_setbooking.m_bo_passn;
		eerste = tekst.Left(1);
		rest   = tekst.Mid(1);
		rest.MakeLower();
		tekst = eerste + rest;
		pDC->TextOut(factor * 100,y, tekst);
//		pDC->TextOut(factor * 100,y, m_setbooking.m_bo_passn.Left(35));

		pDC->TextOut(factor * 350,y, m_setbooking.m_bo_tourref);


		tekst = m_setbooking.m_ho_name;
		tekst.MakeLower();
		pDC->TextOut(factor * 450,y, tekst);
//		pDC->TextOut(factor * 450,y, m_setbooking.m_ho_name);
		pDC->TextOut(factor * 700,y, m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate));
			
		itoa(m_setbooking.m_bo_nights, m_getalchar, 10);
		m_getalstr = (CString) m_getalchar;
		pDC->TextOut(factor * 800,y, m_getalstr);

		if (m_setbooking.m_bo_asngls)
		{
			itoa(m_setbooking.m_bo_asngls, m_getalchar, 10);
			m_getalstr = (CString) m_getalchar;
			pDC->TextOut(factor * 850,y, m_getalstr);
		}

		if (m_setbooking.m_bo_atwnsngls)
		{
			itoa(m_setbooking.m_bo_atwnsngls, m_getalchar, 10);
			m_getalstr = (CString) m_getalchar;
			pDC->TextOut(factor * 900,y, m_getalstr);
		}
			
		if (m_setbooking.m_bo_atwns)
		{
			itoa(m_setbooking.m_bo_atwns, m_getalchar, 10);
			m_getalstr = (CString) m_getalchar;
			pDC->TextOut(factor * 950,y, m_getalstr);
		}
			
		if (m_setbooking.m_bo_adbls)
		{
			itoa(m_setbooking.m_bo_adbls, m_getalchar, 10);
			m_getalstr = (CString) m_getalchar;
			pDC->TextOut(factor * 1000,y, m_getalstr);
		}
	
		if (m_setbooking.m_bo_atrpls)
		{
			itoa(m_setbooking.m_bo_atrpls, m_getalchar, 10);
			m_getalstr = (CString) m_getalchar;
			pDC->TextOut(factor * 1050,y, m_getalstr);
		}
			
		if (m_setbooking.m_bo_aqds)
		{
			itoa(m_setbooking.m_bo_aqds, m_getalchar, 10);
			m_getalstr = (CString) m_getalchar;
			pDC->TextOut(factor * 1100,y, m_getalstr);
		}
			
		if (m_setbooking.m_bo_amltpls)
		{
			itoa(m_setbooking.m_bo_amltpls, m_getalchar, 10);
			m_getalstr = (CString) m_getalchar;
			pDC->TextOut(factor * 1150,y, m_getalstr);
		}

		y += 15;

		m_setbooking.MoveNext();
		rows--;
	}
}

void CFitbookingdateView::prnt_fitbookingdate(CDC* pDC,  double factor)
{
	int begin_pagina = 0; 
	int end_pagina = pDC->GetDeviceCaps(VERTRES);
	
	int y = 50 + m_begin;
	char m_getalchar[10];
	CString m_getalstr;
	CDatecnv m_datecnv;

	if ( y >= begin_pagina && y < end_pagina)
		if (m_selcancelled)
			pDC->TextOut(factor * 50 ,y-begin_pagina, "BOOKING  DATE  STATISTICS  -  CANCELLED  BOOKINGS");
		else
			pDC->TextOut(factor * 50 ,y-begin_pagina, "BOOKING  DATE  STATISTICS  -  CONFIRMED  BOOKINGS");
	y += 150;
	if (m_selstartcode != "")
	{
		if ( y >= begin_pagina && y < end_pagina)
			pDC->TextOut(factor *50 ,y-begin_pagina, m_setbooking.m_ag_name);
		y += 150;
	}
	if (m_selstartdate != "19000101")
	{
		if ( y >= begin_pagina && y < end_pagina)
			pDC->TextOut(factor *50 ,y-begin_pagina, m_datecnv.Datetoddmmjjjj(m_selstartdate) + "   -");
	}
	if (m_selenddate != "20990101")
	{
		if ( y >= begin_pagina && y < end_pagina)
			pDC->TextOut(factor *1350 ,y-begin_pagina, m_datecnv.Datetoddmmjjjj(m_selenddate));
	}
	if (m_selstartdate != "19000101" || m_selenddate != "20990101")
	{
		y += 150;
	}
	y += 150;

	if ( y >= begin_pagina && y < end_pagina)
	{
		pDC->TextOut(factor * 50,  y-begin_pagina, "bkd on");
		pDC->TextOut(factor * 1250,y-begin_pagina, "passenger");
		pDC->TextOut(factor * 4000,y-begin_pagina, "tourref");
		pDC->TextOut(factor * 5000,y-begin_pagina, "hotel");
		pDC->TextOut(factor * 8000,y-begin_pagina, "arrivaldate");
		pDC->TextOut(factor * 9250,y-begin_pagina, "ngts");
		pDC->TextOut(factor * 9500,y-begin_pagina, "sgl");
		pDC->TextOut(factor * 10000,y-begin_pagina, "tsu");
		pDC->TextOut(factor * 10500,y-begin_pagina, "twn");
		pDC->TextOut(factor * 11000,y-begin_pagina, "dbl");
		pDC->TextOut(factor * 11500,y-begin_pagina, "trp");
		pDC->TextOut(factor * 12000,y-begin_pagina, "qds");
		pDC->TextOut(factor * 12500,y-begin_pagina, "mltp");
	}
	y += 300;

	long rows;

	// spring naar eerste te printen record
	m_setbooking.MoveFirst();
	if ( m_p_start_regel > m_aantal_regels_kop)
	{
		y = 0;//m_aantal_regels_kop * 150 + (m_p_start_regel - m_aantal_regels_kop) * 150 + m_begin;
		//y = m_aantal_regels_kop * 150;
		m_setbooking.Move( m_p_start_regel - m_aantal_regels_kop);
		rows = m_p_aantal_regels;
	}
	else
	{
		y = m_aantal_regels_kop * 150 + m_begin;
		rows = m_p_aantal_regels - m_aantal_regels_kop;
	}

	CString tekst, eerste, rest;

	while (!m_setbooking.IsEOF() && rows)
	{
		pDC->TextOut(factor * 50,y-begin_pagina, m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_date));

		tekst = m_setbooking.m_bo_passn;
		eerste = tekst.Left(1);
		rest   = tekst.Mid(1);
		rest.MakeLower();
		tekst = eerste + rest;
		pDC->TextOut(factor * 1250,y-begin_pagina, tekst);
//		pDC->TextOut(factor * 1250,y-begin_pagina, m_setbooking.m_bo_passn.Left(35));
		pDC->TextOut(factor * 4000,y-begin_pagina, m_setbooking.m_bo_tourref);

		tekst = m_setbooking.m_ho_name;
		tekst.MakeLower();
		pDC->TextOut(factor * 5000,y-begin_pagina, tekst);
//		pDC->TextOut(factor * 5000,y-begin_pagina, m_setbooking.m_ho_name);
		pDC->TextOut(factor * 8000, y-begin_pagina, m_datecnv.Datetoddmmjjjj(m_setbooking.m_bo_arrdate));

		itoa(m_setbooking.m_bo_nights, m_getalchar, 10);
		m_getalstr = (CString) m_getalchar;
		pDC->TextOut(factor * 9250 ,y-begin_pagina, m_getalstr);

		if (m_setbooking.m_bo_asngls)
		{
			itoa(m_setbooking.m_bo_asngls, m_getalchar, 10);
			m_getalstr = (CString) m_getalchar;
			pDC->TextOut(factor * 9500,y-begin_pagina, m_getalstr);
		}

		if (m_setbooking.m_bo_atwnsngls)
		{
			itoa(m_setbooking.m_bo_atwnsngls, m_getalchar, 10);
			m_getalstr = (CString) m_getalchar;
			pDC->TextOut(factor * 10000,y-begin_pagina, m_getalstr);
		}

		if (m_setbooking.m_bo_atwns)
		{
			itoa(m_setbooking.m_bo_atwns, m_getalchar, 10);
			m_getalstr = (CString) m_getalchar;
			pDC->TextOut(factor * 10500,y-begin_pagina, m_getalstr);
		}
			
		if (m_setbooking.m_bo_adbls)
		{
			itoa(m_setbooking.m_bo_adbls, m_getalchar, 10);
			m_getalstr = (CString) m_getalchar;
			pDC->TextOut(factor * 11000,y-begin_pagina, m_getalstr);
		}
		
		if (m_setbooking.m_bo_atrpls)
		{
			itoa(m_setbooking.m_bo_atrpls, m_getalchar, 10);
			m_getalstr = (CString) m_getalchar;
			pDC->TextOut(factor * 11500,y-begin_pagina, m_getalstr);
		}
		
		if (m_setbooking.m_bo_aqds)
		{
			itoa(m_setbooking.m_bo_aqds, m_getalchar, 10);
			m_getalstr = (CString) m_getalchar;
			pDC->TextOut(factor * 12000 ,y-begin_pagina, m_getalstr);
		}
			
		if (m_setbooking.m_bo_amltpls)
		{
			itoa(m_setbooking.m_bo_amltpls, m_getalchar, 10);
			m_getalstr = (CString) m_getalchar;
			pDC->TextOut(factor * 12500 ,y-begin_pagina, m_getalstr);
		}

		y += 150;

		m_setbooking.MoveNext();
		rows--;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CFitbookingdateView diagnostics

#ifdef _DEBUG
void CFitbookingdateView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CFitbookingdateView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFitbookingdateView message handlers

BOOL CFitbookingdateView::OnPreparePrinting(CPrintInfo* pInfo) 
{
	// TODO: call DoPreparePrinting to invoke the Print dialog box
	CDC* pDC;
	pDC = GetDC();

	m_p_aantal_regels = pDC->GetDeviceCaps(VERTRES) / 150;
	m_pages = m_aantal_regels / m_p_aantal_regels + 1;

	pInfo->SetMaxPage(m_pages);

	return DoPreparePrinting(pInfo);
}

void CFitbookingdateView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	int paginahoogte = pDC->GetDeviceCaps(VERTRES);
	m_begin        = -paginahoogte * (pInfo->m_nCurPage - 1);
	
	m_p_aantal_regels = pDC->GetDeviceCaps(VERTRES) / 150;
	m_p_start_regel = (pInfo->m_nCurPage - 1) * m_p_aantal_regels;

	CScrollView::OnPrint(pDC, pInfo);
}

void CFitbookingdateView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	m_p_aantal_regels = pDC->GetDeviceCaps(VERTRES) / 150;
	m_pages = m_aantal_regels / m_p_aantal_regels + 1;

	pInfo->SetMaxPage(m_pages);

	CScrollView::OnBeginPrinting(pDC, pInfo);
}

void CFitbookingdateView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CScrollView::OnEndPrinting(pDC, pInfo);
}

CString CFitbookingdateView::MaakStr(int getal)
{
	char getal_char[4];

	itoa(getal, getal_char, 10);

	return (CString) getal_char;
}

CString CFitbookingdateView::MaakStr(double getal)
{
	int i, j;
	char getal_char[6];
	int x1;

	x1 = getal * 100;

	itoa(x1, getal_char, 10);
	for (i = 0; getal_char[i] != '\0'; i++);
	for (j = i+1; j >= i - 1; j--)
		getal_char[j] = getal_char[j-1];
	getal_char[j] = '.';

	return (CString) getal_char;
}


BOOL CFitbookingdateView::OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll) 
{
	// TODO: Add your specialized code here and/or call the base class
	BOOL result = CScrollView::OnScroll(nScrollCode, nPos, bDoScroll);

	Invalidate();

	return result;
}

BOOL CFitbookingdateView::OnScrollBy(CSize sizeScroll, BOOL bDoScroll) 
{
	// TODO: Add your specialized code here and/or call the base class
	BOOL result = CScrollView::OnScrollBy(sizeScroll, bDoScroll);

	Invalidate();

	return result;
}
