#=====================================================================================
# ----- This is a TcpNet Script file which runs on TcpNet -------
# It generates a dynamic page to show the Browser Language Preference.
#=====================================================================================
t <html><head><title>Browser Language Preference</title></head>
t <body text=#000000 BGCOLOR=#ccddff LINK=#0000FF VLINK=#0000FF ALINK=#FF0000>
t <H2 ALIGN=CENTER>Browser Language Preference</H2>
t <FORM ACTION=index.htm METHOD=POST NAME=CGI>
t <INPUT TYPE=HIDDEN VALUE="lang" NAME=pg>
t <TABLE BORDER=0 WIDTH=99%>
t <TR BGCOLOR=#aaccff>
t <TH WIDTH=40%>Item</TH>
t <TH WIDTH=60%>Setting</TH></TR>
# Here begin data setting which is formatted in HTTP_CGI.C module
c e <TR><TD><IMG SRC=pabb.gif>Browser Language</TD><TD><b>%s</b> [%s]</TD></TR>
t <TR><TD>&nbsp;</TD><TD>&nbsp;</TD></TR><TR><TD></TD><TD align="right">
# Here begin button definitions
t <INPUT TYPE=BUTTON VALUE="Home" OnClick="location='/index.htm'">
t </TD></TR></FORM>
t <p>Your browser is sending the following language preference. You may use this information
t to create <b>Multi Language</b> web pages. The language preferences can be set in Internet
t Explorer via <b>Tools / Internet Options... / Languages</b> and in Netscape via <b>Edit /
t Preferences... / Navigator / languages</b>. You may change the setting in your browser
t and reload this page again to check.</p></BODY></HTML>
# This is end of script. It must be closed with period.
.
