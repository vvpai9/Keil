#=====================================================================================
# ----- This is a TcpNet Script file which runs on TcpNet -------
# It allows to change/send a text to on-board LCD Display Module
#=====================================================================================
t <html><head><title>MEMS Status</title>
t <meta http-equiv="refresh" content="1">
t </head>
t <body text=#000000 BGCOLOR=#ccddff LINK=#0000FF VLINK=#0000FF ALINK=#FF0000>
t <H2 ALIGN=CENTER>MEMS Module</H2>
t <FORM ACTION=lcd.cgi METHOD=POST NAME=CGI>
t <INPUT TYPE=HIDDEN VALUE="lcd" NAME=pg>
t <TABLE BORDER=0 WIDTH=99%>
t <TR BGCOLOR=#aaccff>
t <TH WIDTH=20%>Axis</TH>
t <TH WIDTH=80%>Value</TH></TR>
# Here begin data setting which is formatted in HTTP_CGI.C module
t <TR><TD><IMG SRC=pabb.gif>X Axis</TD>
c m 1 <TD>(%d
c m 2 , %d)<br>
t <table bgcolor="#3399ff" border="3" cellpadding="0" cellspacing="0" width="500">
t <tr>
t <td>
c m x <table width="%d%%" border="0" cellpadding="0" cellspacing="0">
t <tr><td bgcolor="#f74747">&nbsp;</td></tr>
t </table>
t </td>
t </tr>
t </table>
t <table border="0" width="540">
t <tr>
t <td width="14%">8</td>
t <td width="14%">4</td>
t <td width="14%">2</td>
t <td width="14%"><b>0</b></td>
t <td width="14%">-2</td>
t <td width="14%">-4</td>
t <td width="14%">-8</td>
t </tr>
t </table>
t </TD></TR>
t <TR><TD><IMG SRC=pabb.gif>Y Axis</TD>
c m 3 <TD>(%d
c m 4 , %d)<br>
t <table bgcolor="#3399ff" border="3" cellpadding="0" cellspacing="0" width="500">
t <tr>
t <td>
c m y <table width="%d%%" border="0" cellpadding="0" cellspacing="0">
t <tr><td bgcolor="#f74747">&nbsp;</td></tr>
t </table>
t </td>
t </tr>
t </table>
t <table border="0" width="540">
t <tr>
t <td width="14%">8</td>
t <td width="14%">4</td>
t <td width="14%">2</td>
t <td width="14%"><b>0</b></td>
t <td width="14%">-2</td>
t <td width="14%">-4</td>
t <td width="14%">-8</td>
t </tr>
t </table>
t </TD></TR>
t <TR><TD><IMG SRC=pabb.gif>Z Axis</TD>
c m 5 <TD>(%d
c m 6 , %d)<br>
t <table bgcolor="#3399ff" border="3" cellpadding="0" cellspacing="0" width="500">
t <tr>
t <td>
c m z <table width="%d%%" border="0" cellpadding="0" cellspacing="0">
t <tr><td bgcolor="#f74747">&nbsp;</td></tr>
t </table>
t </td>
t </tr>
t </table>
t <table border="0" width="540">
t <tr>
t <td width="14%">8</td>
t <td width="14%">4</td>
t <td width="14%">2</td>
t <td width="14%"><b>0</b></td>
t <td width="14%">-2</td>
t <td width="14%">-4</td>
t <td width="14%">-8</td>
t </tr>
t </table>
t </TD></TR>
t <TR><TD>&nbsp;</TD><TD>&nbsp;</TD></TR><TR><TD></TD><TD align="right">
# Here begin button definitions
t <INPUT TYPE=BUTTON VALUE="Home" OnClick="location='/index.htm'">
t </TD></TR></FORM>
t <p><center>
t This page shows data from the <b>MEMS sensonsor</b> which is connected to <b>STR9 DONGLE</b> board. 
t The page refreshes automatically every second.
t </center></p></BODY></HTML>
# This is end of script. It must be closed with period.
.
