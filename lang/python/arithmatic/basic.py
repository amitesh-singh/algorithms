#!/usr/bin/python

a = 10
b = 20

c = a + b;

print 'a+b = ', c

if (c == (a + b)):
   print 'c is equal to (a+b)'
elif (c != 30):
   print 'c is not equal to 30'

count = 0
while (count < 9):
   print ' count is ', count
   count = count + 1;

s1 = "Hello"
s2 = "Ami"
print s1 + s2

print s1 + " " + s2

print s1[0]
print s1[1:] # prints ello
print s1[:2] # prints He

age = 32
if age > 30 or age < 40:
   print "I am a Man"

if age == 32 and age >= 32:
   print "I am a Super Man"
