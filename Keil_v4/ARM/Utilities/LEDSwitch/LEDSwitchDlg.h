// LEDSwitchDlg.h : header file
//

#if !defined(AFX_LEDSWITCHDLG_H__9C3CE574_9F1B_41B0_973C_C4342B802381__INCLUDED_)
#define AFX_LEDSWITCHDLG_H__9C3CE574_9F1B_41B0_973C_C4342B802381__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLEDSwitchDlg dialog

class CLEDSwitchDlg : public CDialog
{
// Construction
public:
  CLEDSwitchDlg(CWnd* pParent = NULL);  // standard constructor

  void Update (void);                  // Update dialog function
  void checkbox (BYTE pin);
  void SendToBoard(char *buf, int len);

// Dialog Data
  //{{AFX_DATA(CLEDSwitchDlg)
  enum { IDD = IDD_LEDSWITCH_DIALOG };
    // NOTE: the ClassWizard will add data members here
  //}}AFX_DATA

  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CLEDSwitchDlg)
  protected:
  virtual void DoDataExchange(CDataExchange* pDX);  // DDX/DDV support
  //}}AFX_VIRTUAL

// Implementation
protected:
  HICON m_hIcon;

  // Generated message map functions
  //{{AFX_MSG(CLEDSwitchDlg)
  virtual BOOL OnInitDialog();
  afx_msg void OnPaint();
  afx_msg HCURSOR OnQueryDragIcon();
  afx_msg void OnKillfocusTransferPort();
  afx_msg void OnKillfocusBoardIp();
  afx_msg void OnKillfocusP2();
  afx_msg void OnP28();
  afx_msg void OnP29();
  afx_msg void OnP210();
  afx_msg void OnP211();
  afx_msg void OnP212();
  afx_msg void OnP213();
  afx_msg void OnP214();
  afx_msg void OnP215();
  afx_msg void OnProtocolTcp();
  afx_msg void OnProtocolUdp();
  virtual void OnOK();
  virtual void OnCancel();
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};

extern CLEDSwitchDlg * pCLEDSwitchDlg;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEDSWITCHDLG_H__9C3CE574_9F1B_41B0_973C_C4342B802381__INCLUDED_)
