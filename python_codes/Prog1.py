print ("My name is Rushi")
a,b=0,1
if a<b:
	print("A-{} is less than B-{}".format(a,b))
elif a>b:
	print("A-{} is greater than B-{}".format(a,b))
else: 
	print("A=B")	

s="less than" if a<b else "Not less than"
print("foo" if a<b else "bar")
#python doesnt have a switch case statement for condition, but you can use following code
choices=dict(one=1,two=2,three=3,four=4,five=5)
v='four'
print(choices[v])
v='seven'		 			  #choices[v] will give error for seven 		
print(choices.get(v,"Other")) #so use get method instead and give default selection


while b<50:
	print(b,end=" ")
	a,b=b,a+b
else:
	print("Else for While Loop")


file1=open("Test1.txt")
# for line in file1.readlines():  #readlines, list,tuple,string - any container object will work as an iterator
# 	print(line,end="")

for index,line in enumerate(file1.readlines()):	
	if index==1: continue                       # continue and break works in python
	if index==10: break
	print(index, line)
else:
    print("Else of For Loop")	               # else works for while and For as well - kind of like defult syntax for loop
print()	

abc=[1,2,3]
abc[:]=range(50)
for i in abc[12:48:2]:
	print(i)

#######################################
#sequence generator using yield
def isprime(n):
	dev=False
	for i in range(2,n):
		if n%i == 0:
			dev=True
			return False
			
	if dev==False:
		return True	
				
def primes(n=1):
	while (True):
		if(isprime(n)):
			yield n
		n+=1	

for i in primes():
	if i>100:
		break
	print(i,end=" ")	
#################################
class fibbo():                        #All methods in the class will always have self as the first argument
	def __init__(self,a,b):
		self.a=a
		self.b=b
	def series(self):
		while True:		
			yield self.b
			self.a,self.b=self.b,self.a+self.b
f=fibbo(0,1)
for j in f.series():
	if j>100:
		break		
	print(j,end=" ")	

####################################	
#Inheritence and polymorphism is supported by python 3
class pc():
	def A(self):
		return self.strings['A']
	def B(self):
		return self.strings['B']
	def C(self):
		return self.strings['C']
	def D(self):
		return self.strings['D']

class c1(pc):
	strings=dict(
		A="c1-A",
		B="c1-B",
		C="c1-C",
		D="c1-D"	
		) 		

class c2(pc):
	strings=dict(
		A="c2-A",
		B="c2-B",
		C="c2-C",
		D="c2-D"	
		) 				
f1=c1()
print(f1.A())
f2=c2()
print(f2.C())

#######################################
#Exceptions
try:
	fh=open('xTest1.txt')
	for each in fh.readlines():
		print(each,end="")
except IOError as e:
	print("Error happened: {}".format(e))

print("Next code to execute")	
###########################################

