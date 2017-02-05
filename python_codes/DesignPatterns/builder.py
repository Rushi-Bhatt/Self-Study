""" Builder pattern: 
Builder is a solution to an Anti-Pattern called Telescoping Constructor. An Anti-Pattern is the opposite of the best practice. 
The Telescoping Constructor Anti-Pattern occurs when a software developer attempts to build a complex object using an excessive number of constructors.
The Builder pattern is trying to solve this problem. 
The Builder partitions the process of building a complex object into the four different roles. 
1)Director - in charge of actually building a product using the builder object. Then, 
2)Abstract Builder - the builder class provides all the necessary interfaces required in building an object. 
3)Concrete Builder - The Concrete Builder class inherits from the Builder class and actually implements the details of the interfaces of the Builder class, 
for a specific type of a product. 
4)Product  - represents an object being built. 
The Builder Pattern does not rely on polymorphism, unlike Factory and Abstract Factory. 
The focus of the Builder Pattern is rather on reducing the complexity of building a complex object through a divide and conquer strategy.
"""

class Director:
    #Director
    def __init__(self,builder):
        self._builder = builder
    def construct_car(self):
        self._builder.creteNewCar()
        self._builder.addTire()
        self._builder.addModel()
        self._builder.addEngine()
    def get_car(self):
        return self._builder.car


class Builder:
    #Abstract Buidler
    def __init__(self):
        self.car = None
    def creteNewCar(self):
        self.car=Car()

class SkylarkBuilder(Builder):
    #concreate Builder
    def addEngine(self):
        self.car.engine = "Turbo V8"
    def addTire(self):
        self.car.tire = "Black"
    def addModel(self):
        self.car.model = "Skylark"


class VeyronBuilder(Builder):
    #concreate Builder
    def addEngine(self):
        self.car.engine = "Turbo V12"
    def addTire(self):
        self.car.tire = "white"
    def addModel(self):
        self.car.model = "Veyron"

class Car:
    #Product
    def __init__(self):
        self.model = None
        self.tire  = None
        self.engine = None

    def __str__(self):
        return "{}|{}|{}".format(self.model,self.engine,self.tire)

builder = SkylarkBuilder()
director = Director(builder)
director.construct_car()
car  = director.get_car()
print(car)
        
builder = VeyronBuilder()
director = Director(builder)
director.construct_car()
car  = director.get_car()
print(car)