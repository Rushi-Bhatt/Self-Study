""" Composite pattern:  The composite design pattern maintains a tree data structure to represent part-whole relationships. 
Here we like to build a recursive tree data structure so that an element of the tree can have its own sub-elements. 
Our solution consists of three major elements. The first one is component, the second one is child, and the third one is composite. 
The component element is an abstract class. A concrete class called child inherits from this component class. And then we have
another concrete class called composite, which is also inheriting from the component class. Finally, our composite class maintains child 
objects by adding and removing them to a tree data structure.
Decorator, iterator, and visitor are related to the composite design pattern."""

class Component(object): 
    """ Abstract class """
    def __init__(self,*args,**kwargs):
        pass
    def component_func(self):
        pass

class Child(Component):
    """ Concrete child class"""
    def __init__(self,*args,**kargs):
        Component.__init__(self,*args,**kargs)
        self.name = args[0]

    def component_func(self):
        print("{}".format(self.name))

class Composite(Component):
        """ Concrete class and maintain the tree recursive structure"""
        def __init__(self,*args,**kwargs):
            Component.__init__(self,*args,**kwargs)
            self.name = args[0]

            #child items
            self.childern = []
        
        def append_child(self,child):
            self.childern.append(child)
        def remove_child(self,child):
            self.childern.remove(child)

        def component_func(self):
            #print the name of the composite object
            print("{}".format(self.name))

            #Print the names of every child object
            for i in self.childern:
                i.component_func()
#build a composite submenu1
sub1 = Composite("Submenu1")
sub11 = Child("Submenu11")
sub12 = Child("Submenu12")
sub1.append_child(sub11)
sub1.append_child(sub12)

#build simple submenu 2
sub2 = Child("Submenu2")

#Build top level composite menu
top = Composite("MainMenu")
top.append_child(sub1)
top.append_child(sub2)

#Lets check 
top.component_func()