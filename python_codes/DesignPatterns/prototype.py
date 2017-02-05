"""Prototype Pattern : - Prototype clones objects according to a prototypical instance.
Prototype is especially useful when creating many identical objects individually.
Create a prototypical instance first and then simply clone it whenever you need a replica.
 One of the patterns related to the prototype pattern is abstract factory. """
import copy
class Prototype:
     def __init__(self):
         self._objects = {}
     def register_object(self, name, obj):
         self._objects[name] =obj

     def unregister_object(self, name):
         del self._objects[name]

     def clone(self,name, **attr):
         obj = copy.deepcopy(self._objects.get(name))
         obj.__dict__.update(attr)  #VIMP: In case some attributes need to be updated 
         return obj
class Car:
    def __init__(self):
        self.name = "Skylark"
        self.color = "Blue"
        self.options = "djf"
    def __str__(self):
        return "{} {} {}".format(self.name,self.color,self.options)
c=Car()
p=Prototype()
p.register_object("Skylark",c)
c1 = p.clone("Skylark")
print(c1)
