""" Adapter pattern: Adapter converts the interface of a class into another one a client is expecting. This time our problem is that the interfaces 
are incompatible between a client and a server"""
class Korean:
    def __init__(self):
        self.name = "korean"
    def speak_korean(self):
        return "Language Korean!"
class British:
    def __init__(self):
        self.name = "british"
    def speak_british(self):
        return "Language English!"

class Adapter:
    """ This changes the generic method  name to  individual method names"""
    def __init__(self,object,**adapted_method):
        self._object = object
        
        #Add new mapping dictionary
        self.__dict__.update(adapted_method)
    
    def __getattr__(self,attr):
        """ Simply return the rest of attrs"""
        return getattr(self._object,attr)

#list to store speaker object
objects = []
korean = Korean()
british =British()
objects.append(Adapter(korean,speak = korean.speak_korean))
objects.append(Adapter(british,speak = british.speak_british))
print(objects)

for obj in objects:
    print("{} says {}".format(obj.name, obj.speak()))