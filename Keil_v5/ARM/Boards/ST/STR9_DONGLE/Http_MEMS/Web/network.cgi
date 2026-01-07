#=====================================================================================
# ----- This is a TcpNet Script file which runs on TcpNet -------
# It generates a dynamic page to edit/change IP address, Net mask and Default Gateway
#=====================================================================================
t <html><head><title>Network Settings</title></head>
t <body text=#000000 BGCOLOR=#ccddff LINK=#0000FF VLINK=#0000FF ALINK=#FF0000>
t <H2 ALIGN=CENTER>Network Settings</H2>
t <FORM ACTION=network.cgi METHOD=GET NAME=CGI>
t <INPUT TYPE=HIDDEN VALUE="net" NAME=pg>
t <TABLE BORDER=0 WIDTH=99%>
t <TR BGCOLOR=#aaccff>
t <TH WIDTH=40%>Item</TH>
t <TH WIDTH=60%>Setting</TH></TR>
# Here begin data setting which is formatted in HTTP_CGI.C module
t <TR><TD><IMG SRC=pabb.gif>LAN IP Address</TD>
c a i <TD><INPUT TYPE=TEXT NAME=ip VALUE="%d.%d.%d.%d" SIZE=18 MAXLENGTH=18></TD></TR>
t <TR><TD><IMG SRC=pabb.gif>LAN Net Mask</TD>
c a m <TD><INPUT TYPE=TEXT NAME=msk VALUE="%d.%d.%d.%d" SIZE=18 MAXLENGTH=18></TD></TR>
t <TR><TD><IMG SRC=pabb.gif>Default Gateway</TD>
c a g <TD><INPUT TYPE=TEXT NAME=gw VALUE="%d.%d.%d.%d" SIZE=18 MAXLENGTH=18></TD></TR>
t <TR><TD><IMG SRC=pabb.gif>Primary DNS Server</TD>
c a p <TD><INPUT TYPE=TEXT NAME=pdns VALUE="%d.%d.%d.%d" SIZE=18 MAXLENGTH=18></TD></TR>
t <TR><TD><IMG SRC=pabb.gif>Secondary DNS Server</TD>
c a s <TD><INPUT TYPE=TEXT NAME=sdns VALUE="%d.%d.%d.%d" SIZE=18 MAXLENGTH=18></TD></TR>
t <TR><TD>&nbsp;</TD><TD>&nbsp;</TD></TR><TR><TD></TD><TD align="right">
# Here begin button definitions
t <INPUT TYPE=SUBMIT NAME=set VALUE="Change" id="sbm">
t <INPUT TYPE=RESET VALUE="Undo">
t <INPUT TYPE=BUTTON VALUE="Home" OnClick="location='/index.htm'">
t </TD></TR></FORM>
t <p>This page allows you to change the system <b>IP address</b>, <b>Net Mask</b>,
t <b>Default Gateway</b>, Primary  and Secondary <b>DNS Server</b>. After you 
t have changed the IP address, you need to modify the host IP address in you Internet 
t browser too to be able to connect to your TcpNet target. Make changes with <b>care</b>
t or you may block the <b>TcpNet</b> sysetm. This Form uses a <b>GET</b> method to send 
t data back to a Web server. You need to click on <b>Change</b> button to activate the 
t channges.</p></BODY></HTML>
# This is end of script. It must be closed with period.
.
