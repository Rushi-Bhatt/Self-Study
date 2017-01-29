class Animal:
	def talk(self):
		print("I have somehing to say")
	def walk(self):
		print("I can walk")
	def clothes(self):
		print("I have clothes")		

class Duck(Animal):                  #duck inherits from animal - Duck is an Animal 
	def __init__(self,**kwargs):     #default value for constructor
		self.variables=kwargs        #here variables is the attrib of object - instance variable
									 #storing object data in dictionary - improves control and encapsulation
	
	def get_variable(self,k):    					 #always good practice to define accessor methods - it gives control over data
		return self.variables.get(k,None)            #None if the value is not assigned
	def set_variable(self,k,v):
		self.variables[k]=v	

	def quack(self):
		print("Quack!!")
	def walk(self):
		super().walk()               # It will incorporate Animal walk method as well 
		print("Walks like a duck")	
	def bark(self):
		print("duck cant")
	def fur(self):
		print("I have white feathers")		
	
class Dog(Animal):
	
	def bark(self):
		print("Boww")
	def fur(self):
		print("I have white and brown fur")		
	def quack(self):
		print("dog cant")
	def walk(self): 
		print("Walks like a dog")	

def main():
	donald=Duck(value=52)
	print(donald.get_variable("value"))
	donald.set_variable("value",47)
	donald.set_variable("color","Blue")
	print(donald.get_variable("value"))
	print(donald.get_variable("color"))
	donald.quack()   					#donald will be passed to the quack method implicitly when we use . operator. 
									    #therefore we have self as first argument in class methods	 - its reference to the object	
	donald.talk()						#talk of animal
										# walk on duck, not animal - Overriding 
	donald.walk()						# if super().walk() then walk on animal and duck both 

	tommy=Dog()
	#Polymorphism -------------------
	for o in (donald,tommy):
		print("This is object instance {}".format(o))
		o.quack()
		o.walk()
		o.bark()
		o.fur()
	def in_the_forest(dog):
		dog.bark()                  #Any object that implemments the method bark and fur can call this method, irrespctive of object type
		dog.fur()					#Be it of type Duck or Dog or any other 
	def in_the_pond(duck):
		duck.walk()					#Any object that implemments the method walk and quack can call this method, irrespctive of object type
		duck.quack()
	
	#if we pass the duck object in in_the_forest or dog object in in_the_pond, it will work as long as it implements the methds			
	#that s the power of polymorphism
	#Python - loosely typed - Doesnt care about the type of object # Its called DUCKTYPING
	#so here dog and duck in the arguments for function definition are just names.. you can use any name
	#What matters is whether the methods are defined for the passed object
	
	in_the_pond(tommy)
	in_the_forest(donald)

if __name__=="__main__":main()	