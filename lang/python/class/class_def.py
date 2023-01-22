class Person(object):
    'Person class'
    # this variable is like a static var in cpp, it is shared
    # by all instances of Person class.
    personCount = 0
    ## This is a constructor
    def __init__(self, first, last):
        print ("Person() created.")
        Person.personCount += 1
        self.first = first
        self.last = last

    ## This is a desctructor
    def __del__(self):
        print("Person() is destroyed")
        print( self.__class__.__name__)
        Person.personCount -= 1

    def getFullname(self):
        return '{} {}'.format(self.first, self.last)
    def setAge(self, myage):
        self.age = myage

    def getAge(self):
        return self.age

if __name__ == "__main__":
    person = Person("aarav", "singh")
    person.setAge(10)
    print ("person age is: {} ", person.getAge())

    person2 = Person("ami", "singh")
    Person3 = Person("avi", "singh")

    print( "total persons are: {} ", Person.personCount)
    # prints the class doc
    print (Person.__doc__)
    print (Person.__name__)
    print (Person.__module__)
    print (Person.__bases__)
    print (Person.__dict__)

    del person
    del person2
    del Person3
