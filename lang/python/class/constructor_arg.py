class Person(object):
    personCount = 0;

    def __init__(self, age, name):
        self.age = age
        self.name = name
        Person.personCount +=1

    def getAge(self):
        return self.age
    def getName(self):
        return self.name

    def print_info(self):
        print self.name, ":", self.age

if __name__ == "__main__":
    p1 = Person(21, "ami")
    p1.print_info()

    p2 = Person(19, "pooja")
    p2.print_info()

    print "total persons are: %d" % Person.personCount
