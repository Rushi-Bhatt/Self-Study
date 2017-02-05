""" Singleton pattern : An object-oriented way of providing global variables is Singleton. Singleton is the pattern you need when you'd like to allow 
only one object to be instantiated from a class.Modules in Python act as Singletons.
We will be using borg class : Which makes the class Attributes global"""

class Borg:
    _shared_dict = {}  #Attribute dictionary
    def __init__(self):
        self.__dict__  = self._shared_dict #make it an attribute dictionary

class Singleton(Borg):
    def __init__(self,**kwargs):
        #Borg()   #To initiate the attribute dictionary
        #updating the attribute dictionary by adding the new entry
        self._shared_dict.update(kwargs)
        
    
    def __str__(self):
        return str(self._shared_dict)

x=Singleton(HTqP="Hyper text transfer protocol")
print(x)
y=Singleton(SNfP="Simple network management protocol")
print(y)
z=Singleton(ABC="Anybody can dance")
print(y)
    