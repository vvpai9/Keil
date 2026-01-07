// LEDSwitch.h : main header file for the LEDSWITCH application
//

#if !defined(AFX_LEDSWITCH_H__96B64FC0_797C_48C6_BF60_8652A585681E__INCLUDED_)
#define AFX_LEDSWITCH_H__96B64FC0_797C_48C6_BF60_8652A585681E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
  #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"   // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLEDSwitchApp:
// See LEDSwitch.cpp for the implementation of this class
//

class CLEDSwitchApp : public CWinApp
{
public:
  CLEDSwitchApp();

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CLEDSwitchApp)
  public:
  virtual BOOL InitInstance();
  //}}AFX_VIRTUAL

// Implementation

  //{{AFX_MSG(CLEDSwitchApp)
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEDSWITCH_H__96B64FC0_797C_48C6_BF60_8652A585681E__INCLUDED_)
