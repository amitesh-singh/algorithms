import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText

fromaddr = "your email id"
toaddr = ["email id 1", "email id 2"]
msg = MIMEMultipart()
msg['From'] = fromaddr
msg['To'] = ", ".join(toaddr)
msg['Subject'] = "Someone is at your door"
 
body = "I cought someone"
msg.attach(MIMEText(body, 'plain'))
 
server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(fromaddr, "your password")
text = msg.as_string()
server.sendmail(fromaddr, toaddr, text)
server.quit()
