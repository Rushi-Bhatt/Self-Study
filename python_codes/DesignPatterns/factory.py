""" Factory encapsulates object creation
The Factory pattern is useful, especially when you're not sure about what type of objects you'll be needing eventually in your system. 
Another possibility is the situation in which your application needs to decide on what class to use at run time.
"""

class Dog:
    def __init__(self,name):
        self._name=name
    def speak(self):
        return "Bow!!"    
class Cat:
    def __init__(self,name):
        self._name=name
    def speak(self):
        return "Meow!!"

def get_pet(pet="dog"):
    """the factory method"""
    pets=dict(dog=Dog("Tommy"),cat=Cat("Minny"))
    return pets[pet]

d = get_pet("dog")            
print(d.speak())
d=get_pet("cat")
print(d.speak())
