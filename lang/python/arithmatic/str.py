#!/usr/bin/python

str1 = "hello world!"

replaced_str = str1.replace('world', 'ami')

print replaced_str
print str1

# split string - default delimiter is space

strList = str1.split()
print strList

guests = "Ami, Tom, raster, jpeg"

guestsList = guests.split(",")
print guestsList

#Code to convert an entire string value into uppercase or lowercase:

emailbody = 'Hello Gabbar!'

print 'Upper: ' + emailbody.upper()

print 'Lower: ' + emailbody.lower()

