""" Observer pattern: Observer establishes a one-to-many relationship between a subject and multiple observers. 
Our problem here is that a subject object need to be monitored, and other observer objects need to be notified when there is a 
change in the subject.Singleton is related to the observer design pattern."""

class Subject(object): #represents what is being observed
    def __init__(self):
        self._observers = [] #list of references of all the observers
    def attach(self,observer):
        if observer not in self._observers:
            self._observers.append(observer)
    def detach(self, observer):
        try:
            self._observers.remove(observer)
        except ValueError:
            pass
    def notify(self,modifier = None):
        for observer in self._observers: #For all the observers in the list
            if observer != modifier: #dont notify the observer who is updating the temp
                observer.update(self) #Alert the observer

class Core(Subject):
        def __init__(self,name= ""):
            Subject.__init__(self)
            self._name = name #set the name of the core
            self._temp = 0     #Initialize the temprature of the Core
        
        @property #getter for temp
        def temp(self):
            return self._temp  
        
        @temp.setter #setter for temp
        def temp(self,temp):
            self._temp= temp

#Observer class
class TempViewer:
    def update(self,subject): #invoked when the notify method in the concreate subject is invoked
        print("Temp viewer {} has temp {}".format(self._name, self._temp))

#Create subjects
c1 = Core("Core 1")
c1 = Core("Core 2")

#Lets create observers
t1= TempViewer()
t2 = TempViewer()

#Attach observer to the first core
c1.attach(t1)
c1.attach(t2)

#change the temp of first core
c1.temp =80
c1.temp = 90