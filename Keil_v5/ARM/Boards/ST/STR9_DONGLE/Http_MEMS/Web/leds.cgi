#================================================================
# ----- This is a TcpNet Script file which runs on TcpNet -------
# It controls the on-board LED diodes using the Internet browser.
#================================================================
t <HTML><head><title>LED Control</title>
t <BODY TEXT=#000000 BGCOLOR=#ccddff LINK=#0000FF VLINK=#0000FF ALINK=#FF0000>
t <SCRIPT LANGUAGE=JavaScript> function AllSW(st) {
t   for(i=0;i<document.form1.length;i++) {
t    if(document.form1.elements[i].type=="checkbox"){
t     document.form1.elements[i].checked=st;}}} </SCRIPT></head>
t <H2 ALIGN=CENTER>Control LEDs on the board</H2>
t <FORM ACTION=leds.cgi METHOD=POST NAME=form1>
t <INPUT TYPE=HIDDEN VALUE="led" NAME=pg>
t <TABLE BORDER=0 WIDTH=99%>
t <TR BGCOLOR=#aaccff>
t <TH WIDTH=45%>Item</TH>
t <TH WIDTH=55%>Setting</TH></TR><TR>
t <TD><IMG SRC=pabb.gif>LED control:</TD><TD><SELECT NAME="ctrl">
c b c <OPTION %s>Browser</OPTION><OPTION %s>Running Lights</OPTION><OPTION %s>Board</OPTION></SELECT></TD></TR>
t <TR><TD><IMG SRC=pabb.gif>LED diodes on the output port [3..0]:</TD>
t <TD><table><tr valign="middle">
# Here begin the 'checkbox' definitions
c b 3 <td><input type=checkbox name=led3 %s>3</td>
c b 2 <td><input type=checkbox name=led2 %s>2</td>
c b 1 <td><input type=checkbox name=led1 %s>1</td>
c b 0 <td><input type=checkbox name=led0 %s>0</td>
t <td width="5%"></td>
t </table></TD></TR>
t <TR><TD><IMG SRC=pabb.gif>All LED diodes On or OFF</TD>
t <TD><INPUT TYPE=BUTTON VALUE="&nbsp;&nbsp;ON&nbsp;&nbsp;&nbsp;" ONCLICK="AllSW(true)">
t <INPUT TYPE=BUTTON VALUE="&nbsp;&nbsp;OFF&nbsp;&nbsp;" ONcLICK="AllSW(false)"></TD></TR>
t <TR><TD>&nbsp;</TD><TD>&nbsp;</TD></TR><TR><TD>&nbsp;</TD><TD align="right">
t <INPUT TYPE=SUBMIT NAME=set VALUE="Submit">
t <INPUT TYPE=RESET VALUE="Undo">
t <INPUT TYPE=BUTTON VALUE="Home" OnClick="location='/index.htm'">
t </TD></TR></FORM>
t <p>This page shows you how to use the following http form <b>input</b> objects:
t <b>checkbox</b>, <b>select</b> and <b>button</b>. It uses also a simple <b>Java Script</b>
t function to check/uncheck all checkboxes. This Form uses a <b>POST</b> method to send data
t back to a Web server. You need to click on <b>Submit</b> button to activate the channges.
t </p></BODY></HTML>
# This is end of script. It must be closed with a period.
.

