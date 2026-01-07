#=====================================================================================
# ----- This is a TcpNet Script file which runs on TcpNet -------
# It generates a dynamic page to edit/change System Password.
#=====================================================================================
t <html><head><title>System Settings</title></head>
t <body text=#000000 BGCOLOR=#ccddff LINK=#0000FF VLINK=#0000FF ALINK=#FF0000>
t <H2 ALIGN=CENTER>System Settings</H2>
t <FORM ACTION=index.htm METHOD=POST NAME=CGI>
t <INPUT TYPE=HIDDEN VALUE="sys" NAME=pg>
t <TABLE BORDER=0 WIDTH=99%>
t <TR BGCOLOR=#aaccff>
t <TH WIDTH=40%>Item</TH>
t <TH WIDTH=60%>Setting</TH></TR>
# Here begin data setting which is formatted in HTTP_CGI.C module
c d 1 <TR><TD><IMG SRC=pabb.gif>Authentication</TD><TD><b>%s</b></TD></TR>
t <TR><TD><IMG SRC=pabb.gif>Password for user 'admin'</TD>
c d 2 <TD><INPUT TYPE=PASSWORD NAME=pw SIZE=10 MAXLENGTH=10 VALUE="%s"></TD></TR>
t <TR><TD><IMG SRC=pabb.gif>Retype your password</TD>
c d 2 <TD><INPUT TYPE=PASSWORD NAME=pw2 SIZE=10 MAXLENGTH=10 VALUE="%s"></TD></TR>
t <TR><TD>&nbsp;</TD><TD>&nbsp;</TD></TR><TR><TD></TD><TD align="right">
# Here begin button definitions
t <INPUT TYPE=SUBMIT NAME=set VALUE="Change" id="sbm">
t <INPUT TYPE=RESET VALUE="Undo">
t <INPUT TYPE=BUTTON VALUE="Home" OnClick="location='/index.htm'">
t </TD></TR></FORM>
t <p>This page allows you to change the system <b>Password</b>, for the username <b>admin</b>.
t Default <b>realm</b>, <b>user</b> and <b>password</b> can be set in configuraton file.
t This Form uses a <b>POST</b> method to send data back to a Web server. You need to click
t on <b>Change</b> button to activate the channges.</p></BODY></HTML>
# This is end of script. It must be closed with period.
.
