#=====================================================================================
# ----- This is a TcpNet Script file which runs on TcpNet -------
# It allows to change/send a text to on-board LCD Display Module 
#=====================================================================================
t <html><head><title>LCD Control</title></head>
t <body text=#000000 BGCOLOR=#ccddff LINK=#0000FF VLINK=#0000FF ALINK=#FF0000>
t <H2 ALIGN=CENTER>LCD Module Control</H2>
t <FORM ACTION=lcd.cgi METHOD=POST NAME=CGI>
t <INPUT TYPE=HIDDEN VALUE="lcd" NAME=pg>
t <TABLE BORDER=0 WIDTH=99%>
t <TR BGCOLOR=#aaccff>
t <TH WIDTH=40%>Item</TH>
t <TH WIDTH=60%>Setting</TH></TR>
# Here begin data setting which is formatted in HTTP_CGI.C module
t <TR><TD><IMG SRC=pabb.gif>Line 1 Text</TD>
c f 1 <TD><INPUT TYPE=TEXT NAME=lcd1 SIZE=16 MAXLENGTH=16 VALUE="%s"></TD></TR>
t <TR><TD><IMG SRC=pabb.gif>Line 2 Text</TD>
c f 2 <TD><INPUT TYPE=TEXT NAME=lcd2 SIZE=16 MAXLENGTH=16 VALUE="%s"></TD></TR>
t <TR><TD>&nbsp;</TD><TD>&nbsp;</TD></TR><TR><TD></TD><TD align="right">
# Here begin button definitions
t <INPUT TYPE=SUBMIT NAME=set VALUE="Send" id="sbm">
t <INPUT TYPE=RESET VALUE="Undo">
t <INPUT TYPE=BUTTON VALUE="Home" OnClick="location='/index.htm'">
t </TD></TR></FORM>
t <p>This page allows you to change a message displayed on <b>LCD Module</b>. Simply enter
t the text which you want to display on LCD module.
t This Form uses a <b>POST</b> method to send data back to a Web server. You need to click
t on <b>Send</b> button to activate the channges.</p></BODY></HTML>
# This is end of script. It must be closed with period.
.
