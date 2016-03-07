#!/usr/bin/python

# store key-values pair

boards = {'ami':3765, 'aarav': 1, 'pooja': 2}

print boards

print boards.keys()

print 'ami rank is: ', boards['ami']

boards['pooja'] = 3
print boards

# how to create an empty dict

addresses = {} # an empty dict
# or
addresses2 = dict() # an empty dict
