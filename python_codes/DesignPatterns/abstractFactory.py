""" Abstract Factory 
Abstract Factory is especially useful when a client expects to receive a family of related objects at a given time, 
but don't have to know which family it is until run time."""

class Dog:
    """ One of the objects to be returned"""
    def speak(self):
        return "Bow!!"
    def __str__(self):
        return "DOG"

class Cat:
    """ One of the objects to be returned"""
    def speak(self):
        return "MEOWW!!"
    def __str__(self): 
        """ __STR__ : invoked when simple object name is printed on the screen"""   
        return "CAT"

class DogFactory:
    """ Concrete factory """
    def get_pet(self):
        """ returns a dog object"""
        return Dog()
    def get_food(self):
        """  returns a dog food object"""
        return "Dog Food"

class CatFactory:
    """ Concrete factory """
    def get_pet(self):
        """ returns a Cat object"""
        return Cat()
    def get_food(self):
        """  returns a Cat food object"""
        return "Cat Food"

class PetStore:
    """ Houses our abstact factory"""
    def __init__(self, pet_factory=None):
        self._pet_factory = pet_factory
    def show_pet(self):
        pet = self._pet_factory.get_pet()
        pet_food = self._pet_factory.get_food()

        print("Out pet is {}".format(pet))
        print("Out pet says {}".format(pet.speak()))
        print("Out pet eats {}".format(pet_food))
        
#create a concrete factory
factory = DogFactory()

#create an abstract factory
pet_factory = PetStore(factory)

#utility method of abstact factory
pet_factory.show_pet()

#create a concrete factory
factory = CatFactory()

#create an abstract factory
pet_factory = PetStore(factory)

#utility method of abstact factory
pet_factory.show_pet()
