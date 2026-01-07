// LEDSwitchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LEDSwitch.h"
#include "LEDSwitchDlg.h"
#include "UtilFunc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define DEFPORTNUM  "1001"
#define BOARD_IP    "192.168.0.100"
#define TCP         1
#define UDP         0
#define TRANS_LEN   1
#define BLINKLED    0x01             // Command for blink the leds on board

  BYTE  P2;          // P2 sfr
  BYTE  P2old;       // old value of P2 sfr
  BYTE  check;       // value of selected checkbox
  BYTE  TransPrt;    // Transfer protocol
  WORD  iPort;       // Transfer Port number
  char  BoardIP[50]; // Board IP number

  CSocket *pSocket;

/////////////////////////////////////////////////////////////////////////////
// CLEDSwitchDlg dialog

static CLEDSwitchDlg * pCLEDSwitchDlg;

CLEDSwitchDlg::CLEDSwitchDlg(CWnd* pParent /*=NULL*/)
  : CDialog(CLEDSwitchDlg::IDD, pParent)
{
  //{{AFX_DATA_INIT(CLEDSwitchDlg)
    // NOTE: the ClassWizard will add member initialization here
  //}}AFX_DATA_INIT
  // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
  m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLEDSwitchDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(CLEDSwitchDlg)
    // NOTE: the ClassWizard will add DDX and DDV calls here
  //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLEDSwitchDlg, CDialog)
  //{{AFX_MSG_MAP(CLEDSwitchDlg)
  ON_WM_PAINT()
  ON_WM_QUERYDRAGICON()
  ON_EN_KILLFOCUS(IDC_TRANSFERPORT,  OnKillfocusTransferPort)
  ON_EN_KILLFOCUS(IDC_BOARDIP,       OnKillfocusBoardIp)
  ON_EN_KILLFOCUS(IDC_P2,            OnKillfocusP2)
  ON_BN_CLICKED(IDC_P2_8,  OnP28)
  ON_BN_CLICKED(IDC_P2_9,  OnP29)
  ON_BN_CLICKED(IDC_P2_10, OnP210)
  ON_BN_CLICKED(IDC_P2_11, OnP211)
  ON_BN_CLICKED(IDC_P2_12, OnP212)
  ON_BN_CLICKED(IDC_P2_13, OnP213)
  ON_BN_CLICKED(IDC_P2_14, OnP214)
  ON_BN_CLICKED(IDC_P2_15, OnP215)
  ON_BN_CLICKED(IDC_PROTOCOL_TCP, OnProtocolTcp)
  ON_BN_CLICKED(IDC_PROTOCOL_UDP, OnProtocolUdp)
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLEDSwitchDlg message handlers

BOOL CLEDSwitchDlg::OnInitDialog()
{
  CDialog::OnInitDialog();

  // Set the icon for this dialog.  The framework does this automatically
  //  when the application's main window is not a dialog
  SetIcon(m_hIcon, TRUE);     // Set big icon
  SetIcon(m_hIcon, FALSE);    // Set small icon
  
  // TODO: Add extra initialization here
  CheckRadioButton(IDC_PROTOCOL_TCP, IDC_PROTOCOL_UDP, IDC_PROTOCOL_TCP);
  TransPrt = 1;
  GetDlgItem (IDC_TRANSFERPORT)->SetWindowText (DEFPORTNUM);
  GetDlgItem (IDC_BOARDIP)->SetWindowText (BOARD_IP);
  strcpy(BoardIP, BOARD_IP);
  GetDlgItem (IDC_P2)->SetWindowText ("0x00");
  P2 = 0;
  Update();

  return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLEDSwitchDlg::OnPaint() 
{
  if (IsIconic())
  {
    CPaintDC dc(this); // device context for painting

    SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

    // Center icon in client rectangle
    int cxIcon = GetSystemMetrics(SM_CXICON);
    int cyIcon = GetSystemMetrics(SM_CYICON);
    CRect rect;
    GetClientRect(&rect);
    int x = (rect.Width() - cxIcon + 1) / 2;
    int y = (rect.Height() - cyIcon + 1) / 2;

    // Draw the icon
    dc.DrawIcon(x, y, m_hIcon);
  }
  else
  {
    CDialog::OnPaint();
  }
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLEDSwitchDlg::OnQueryDragIcon()
{
  return (HCURSOR) m_hIcon;
}

static char WSTITLE[]  = "Ethernet Connection Error";
static char WSERROR1[] = "Failed to start Winsocket Connection.\nPlease check the settings of your network interface card!";
static char WSERROR2[] = "Couldn't get a socket\nPlease check the TCP/IP settings of your PC!";
static char WSERROR3[] = "Couldn't connect\nPlease check TCP/IP settings of your PC!";
static char WSERROR4[] = "Couldn't send complete data";

void CLEDSwitchDlg::SendToBoard(char *buf, int len) {
  struct sockaddr_in sin;
  SOCKET  s;
  WSADATA wsaData;
  int retval;

  if (WSAStartup(0x101,&wsaData)) {
    MessageBox(&WSERROR1[0], &WSTITLE[0], MB_OK | MB_ICONSTOP); 
    WSACleanup();
    return;
  }
  sin.sin_addr.S_un.S_addr = inet_addr(BoardIP);   // Embedded Ethernet's IP address
  sin.sin_family = AF_INET; 
  sin.sin_port = htons(iPort);                     // The port that the Basic Stamp program is listening on.
  s = socket(AF_INET, ((TransPrt) ? SOCK_STREAM : SOCK_DGRAM), 0);  // SOCK_STREAM - use TCP, SOCK_DGRAM - use UDP
  if(s == INVALID_SOCKET) {
    MessageBox(&WSERROR2[0], &WSTITLE[0], MB_OK | MB_ICONSTOP); 
    WSACleanup();
    return;
  }
 
  if(connect(s,(struct sockaddr*)&sin,sizeof(sin)) == SOCKET_ERROR) {
    MessageBox(&WSERROR3[0], &WSTITLE[0], MB_OK | MB_ICONSTOP); 
    WSACleanup();
    return;
  }

//  retval = send(s,&buf[0],sizeof(buf),0);          // Send string to Microcontroller
  retval = send(s,&buf[0],len,0);          // Send string to Microcontroller
//  if (retval != sizeof (buf)) {
  if (retval != len) {
    MessageBox(&WSERROR4[0], &WSTITLE[0], MB_OK | MB_ICONSTOP); 
  }
  closesocket(s);
  WSACleanup();
}

void CLEDSwitchDlg::Update (void)  {
  char  tmp[2];

  if (P2old != P2) {
    StringHex2 (GetDlgItem(IDC_P2), P2);
    if ((P2old ^ P2) & 0x01) ((CButton *) GetDlgItem (IDC_P2_8))->SetCheck  ((P2 & 0x01) ? 1 : 0);
    if ((P2old ^ P2) & 0x02) ((CButton *) GetDlgItem (IDC_P2_9))->SetCheck  ((P2 & 0x02) ? 1 : 0);
    if ((P2old ^ P2) & 0x04) ((CButton *) GetDlgItem (IDC_P2_10))->SetCheck ((P2 & 0x04) ? 1 : 0);
    if ((P2old ^ P2) & 0x08) ((CButton *) GetDlgItem (IDC_P2_11))->SetCheck ((P2 & 0x08) ? 1 : 0);
    if ((P2old ^ P2) & 0x10) ((CButton *) GetDlgItem (IDC_P2_12))->SetCheck ((P2 & 0x10) ? 1 : 0);
    if ((P2old ^ P2) & 0x20) ((CButton *) GetDlgItem (IDC_P2_13))->SetCheck ((P2 & 0x20) ? 1 : 0);
    if ((P2old ^ P2) & 0x40) ((CButton *) GetDlgItem (IDC_P2_14))->SetCheck ((P2 & 0x40) ? 1 : 0);
    if ((P2old ^ P2) & 0x80) ((CButton *) GetDlgItem (IDC_P2_15))->SetCheck ((P2 & 0x80) ? 1 : 0);

    tmp[0] = BLINKLED;
    tmp[1] = (char) P2;
    tmp[2] = '\0';
    SendToBoard (tmp, sizeof(tmp));
    P2old = P2;
  }

}

static DWORD P2_ID[8] = { IDC_P2_8,  IDC_P2_9,  IDC_P2_10, IDC_P2_11,
                          IDC_P2_12, IDC_P2_13, IDC_P2_14, IDC_P2_15,
};

void CLEDSwitchDlg::checkbox (BYTE pin) {
  BYTE mask;
  
  mask = 0x01 << pin;
  check = (BYTE) ((CButton *) GetDlgItem (P2_ID[pin]))->GetCheck();
  P2 = check ? (P2 | mask) : (P2 & ~mask);
  Update();
}

void CLEDSwitchDlg::OnP28()  { checkbox(0); }
void CLEDSwitchDlg::OnP29()  { checkbox(1); }
void CLEDSwitchDlg::OnP210() { checkbox(2); }
void CLEDSwitchDlg::OnP211() { checkbox(3); }
void CLEDSwitchDlg::OnP212() { checkbox(4); }
void CLEDSwitchDlg::OnP213() { checkbox(5); }
void CLEDSwitchDlg::OnP214() { checkbox(6); }
void CLEDSwitchDlg::OnP215() { checkbox(7); }

void CLEDSwitchDlg::OnKillfocusP2() {
  long val;
  
  val = HandleByteInput (GetDlgItem(IDC_P2), P2); 
  if (val != 0xFFFF) {
    P2 = (BYTE) val;
    Update();
  }
}

void CLEDSwitchDlg::OnKillfocusTransferPort() {  // Get Transfer port number
  iPort = GetDlgItemInt (IDC_TRANSFERPORT, NULL, TRUE );
}

void CLEDSwitchDlg::OnKillfocusBoardIp() {       // Get Board IP
  memset(BoardIP, 0, sizeof(BoardIP));
  GetDlgItemText (IDC_BOARDIP, BoardIP, 20);
}

void CLEDSwitchDlg::OnProtocolTcp() { TransPrt = TCP; }
void CLEDSwitchDlg::OnProtocolUdp() { TransPrt = UDP; }


void CLEDSwitchDlg::OnOK() 
{
  // do nothing so far
}

void CLEDSwitchDlg::OnCancel() 
{
  CDialog::OnCancel();
}
