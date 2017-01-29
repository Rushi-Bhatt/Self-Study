class inclusive_range():
	def __init__(self,*args):
		numberOfArgs=len(args)
		if numberOfArgs<1: raise TypeError("Atleast 1 argument please")
		elif numberOfArgs==1:
			self.start=0
			self.stop=args[0]           	 #remember--- here args alone wont work.. you need to specify args[0]
			self.step=1
		elif numberOfArgs==2:
			self.start,self.stop=args        #remember--- here args alone will work.. you dont need to specify args[0], args[1]
			self.step=1
		elif numberOfArgs ==3:
			self.start,self.stop,self.step=args
		else: raise TypeError("Atmost 3 arguments please, it got {}".format(numberOfArgs))
	
	def __iter__(self):     #Special method - Enable object to be used as a generator .....  Having range in the function makes it iterable
		i=self.start
		while i<=self.stop:
			yield i
			i+=self.step

class Duck():

	def __init__(self, **kwargs):
		self.properties=kwargs
		print(self.properties)

	def get_property(self,key):
		return self.properties.get(key,None)

	def set_property(self,key,value):
		self.properties[key]=value

	# decorators - functions that return functions, can be used as accessors.. For exp, lets crate color accessor separately			
	# can be used as simple object - Quite easy to use
	@property
	def color(self):
		return self.properties.get('color',None)

	@color.setter
	def color(self,c):
		self.properties["color"]=c	

	@color.deleter
	def color(self):
		del self.properties["color"]	
		
def main():
	
	for i in inclusive_range(0,25,5):
		print(i,end=" ")
	donald=Duck(color="Red", feet=4)
	print (donald.get_property("color"))
	donald.color="Blue"
	print(donald.color)	


if __name__=="__main__":main()
