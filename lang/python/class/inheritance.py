class Parent:
    # data hiding
    __notvisibleoutside = 0
    def __init__(self):
        print "Parent constructor"
    def parentMethod(self):
        print "Parent method is called"
    def callme(self):
        print "parent callme called"

class Child(Parent):
    def __init__(self):
        print "Child constructor"
    # going to override parent function callme()
    def callme(self):
        print "child callme() called"

if __name__ == "__main__":
    child = Child()
    child.parentMethod()
    child.callme()
     # this will throw error
    # print Parent.__notvisibleoutside
