""" Strategy: - The Strategy pattern offers a family of interchangeable algorithms to a client. The problem we often see is 
that there is a need for dynamically changing the behavior of an object. So we offer our Strategy class with its default behavior. 
When there is a need, we provide another variation of the Strategy class by dynamically replacing its default method with a new one.
Python allows adding methods dynamically by importing the types module."""
import types
class Strategy:
    def __init__(self, function = None):
        self.name = "Default strategy"
        #if a reference to the function is provided, replace execute method with the given function
        if function:
            self.execute = types.MethodType(function,self)
    #default execution
    def execute(self):
        """ default method that prints the name of the strategy being used"""
        print("{} is used!".format(self.name))

def Strategy_one(self):
    print("{} is used to execute method 1".format(self.name))


def Strategy_two(self):
    print("{} is used to execute method 2".format(self.name))

s0=Strategy()
s0.execute()

s1 = Strategy(Strategy_one)
s1.name = "Startegy One"
s1.execute()

s2 = Strategy(Strategy_two)
s2.name = "Startegy Two"
s2.execute()
