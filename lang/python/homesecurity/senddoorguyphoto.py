""" Copyright (C) 2016 Amitesh Singh <singh.amitesh at gmail.com> """

import urllib
import time

import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText
from email.MIMEBase import MIMEBase
from email import encoders

""" first dowload the photo"""
urllib.urlretrieve ("http://192.168.0.105:8080/photo.jpg", "/tmp/photo.jpg")
"""note: photoaf.jpg - take focused photo"""
"""Pavel's(ip webcam author) tip: http://ip:8080/shot.jpg, if you want the same resolution as video, and no delay.  """

timeformat = "%H:%M:%S"
dateformat = "%d/%m/%Y"

timelog = time.strftime(timeformat) + " " + time.strftime(dateformat)

fromaddr = "your email id"
toaddr = "to email id"

msg = MIMEMultipart()
msg['From'] = fromaddr
msg['To'] = toaddr
msg['Subject'] = "Someone had visited to your door: " + timelog

body = "Entry time & data:" + timelog

msg.attach(MIMEText(body, 'plain'))

filename = "photo.jpg"
attachment = open("/tmp/photo.jpg", "rb")

part = MIMEBase('application', 'octet-stream')
part.set_payload((attachment).read())
encoders.encode_base64(part)
part.add_header('Content-Disposition', "attachment; filename= %s" % filename)

msg.attach(part)

server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(fromaddr, "your password")
text = msg.as_string()
server.sendmail(fromaddr, toaddr, text)
server.quit()
