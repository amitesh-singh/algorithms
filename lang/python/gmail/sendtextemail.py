import smtplib

server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login("your email address", "email password")
msg = "YOUR MESSAGE!"
server.sendmail("your email address", "to email address", msg)
server.quit()
