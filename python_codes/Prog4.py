def main():
	print("Functions")

# function needs to be defined first before it gets called. Here, to avoid those errors, we are caliing the main() function at last
#So that whatever call we use in function will be executed after the definition
	test(12,13,14,15,16,17,one=1,two=2,three=3)  #remember that the order is important
	stub()
	for j in inclusiveRange(1,26,2):                        #function as an iterative object
		print(j,end=" ")

def test(n1,n2=None,n3=6,*args,**kwargs):	# you can use None if you dont want to pass the default value- if you dont use None, or pass
											# default , then it will create error as it expects 3 argument, you are sending only 1
	print("test function",n1,n2,n3)			#also, default arguments will always be at last test(n1=6,n2=None,n3) will give error
	for i in args:
		print (i,end=" ")					#args-tuple, any argument after n3 will be stored in the tuple - in the passing order
	print("First args",args[0])				
	for k in sorted(kwargs):				#kwargs - keywordarguments - dictionary -in random order as it is  so use sorted
		print(k,kwargs[k])                  #will print all the kwargs - useful when the name is not known on the receiver side   

	print(" Time for keyword atguments",kwargs["one"],kwargs["two"],kwargs["three"])    
	
#also, empty function throws error.you need to have atleast one line in function
#So to create a stub, or function that doesnt do anything, you can use pass statement
def stub():
	pass

def inclusiveRange(*args):	     #generator function - produces inclusive range
	numberOfArgs=len(args)
	if numberOfArgs<1: raise TypeError("Atleast 1 argument please")
	elif numberOfArgs==1:
		start=0
		stop=args[0]           #remember--- here args alone wont work.. you need to specify args[0]
		step=1
	elif numberOfArgs==2:
		start,stop=args        #remember--- here args alone will work.. you dont need to specify args[0], args[1]
		step=1
	elif numberOfArgs ==3:
		start,stop,step=args
	else: raise TypeError("Atmost 3 arguments please, it got {}".format(numberOfArgs))

	i=start
	while i<=stop:
		yield i
		i+=step	

if __name__=="__main__":main()	