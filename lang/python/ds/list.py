#!/usr/bin/python
mylist = [2, 'a', 12.0, "disco dancer"]

print mylist

print mylist[1:]
print mylist[3]
print mylist[:2]
print mylist[1:3]
print mylist[:] #Access all elements
print len(mylist) #no. of elements in mylist LIST

mylist.append(10)
print mylist[:]

#          index value
mylist.insert(0, 'ami')
print mylist

# remove last element and return it
lastElem = mylist.pop()
print 'removed from list: ', lastElem
print mylist


