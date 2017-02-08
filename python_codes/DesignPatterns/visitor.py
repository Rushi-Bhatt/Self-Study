"""  The Visitor design pattern allows adding new features to an existing class hierarchy without changing it. It is sometimes 
necessary to add new operations dynamically to existing classes with minimal changes.The visitor pattern represents new 
operations to be performed on the various elements of an existing class hierarchy. Visitors can also provide operations on
 a composite object. """
 
class House(object): #the class being visited
    def accept(self,visitor):#interface to accept the visitor
        #triggger the visiting operation
        visitor.visit(self)
    
    def __str__(self):
        return self.__class__.__name__

    def work_on_hvac(self,hvac_specialist):
        print(self,"Worked on by",hvac_specialist)
    
    def work_on_electricity(self,electrician):
        print(self,"Worked on by",electrician)

class Visitor(object):#abstract visitor class
    def __str__(self):
        """ Simply return the class name when the visitor object is printed"""
        return self.__class__.__name__

class Hvac_specialist(Visitor):
    def visit(self,house):
        house.work_on_hvac(self)

class Electrician(Visitor):
    def visit(self,house):
        house.work_on_electricity(self)

#create the Visitor
hv= Hvac_specialist()
e=Electrician()
#crrate the house 
h=House()

#accept the visitor
h.accept(hv)
h.accept(e)