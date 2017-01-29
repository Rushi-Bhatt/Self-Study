def main():

##############################################################################################
	# Everything in python is an object - variable, function etc.
	# Every object has 3 attributes: 1)ID 2)TYPE 3)VALUE
	x=4
	print("ID of X:{}".format(id(x)))
	print("ID of 4:{}".format(id(4)))  #see that it will return the same id value - So 4 itself is an object of type integer
	y=4
	print("ID of Y:{}".format(id(y)))  #see that it will return the same id value as x and 4
	print(x==y)                        #true as the value is equal --- == compares the value   
	print (x is y) 					   #true as the ID is equal  --- is compares the ID	
	print("Type of X:{}".format(type(x)))
	print("Value of X:{}".format(x))

	
	x=4
	print("X={}, ID of X:{}".format(x,id(x)))
	x=5
	print("X={}, ID of X:{}".format(x,id(x)))
	x=4
	print("X={}, ID of X:{}".format(x,id(x)))
	print("Notice how ID 1 and 3 are same as the values are same but ID 2 is different as the value of x is different")
#####################################################################################################################################
#Objects- Mutable (May change values - lists,dict), Immutable(No change in value - numbers, strings, tuples,bool)
#Mutable - same content variable will have same ID   x=42,y=42  x==y : True   x is y : True    x is not y : False
#immutable - same content variable will have differnt ID  x=dict(a=23),y=dict(a=23)    x==y :True    x is y:False    x is not y:True
####################################################################################################################################
	a="shrf"
	print(type(a),a)            # type(a) -  to check the type of variable - Number 1)int 2)float
								#											 str,tuple	
								#											 bool - True, False
								#											 dict, list											 
	a,b=0,1
	print(a,b)
	a,b=b,a                     # swapping in 1 line without using any other varible
	print(a,b)

	a=(0,1,2,3,4,5)  			#tuples/set/aggregate type
	b=[1,2,3,4,5]				# list
	a,b=0,1
	s="less than" if a<b else "Not less than"
	print(s)

	num=42/8          
	print (type(num),num)       #Returns float 
	num1= 42//8					# // will devide and return the int part only, not rounded up.. just integer - will return 4
	print(type(num1),num1)		#returns int
	num2=round(42/8)            # will return 5
	print(num2)
	num2=round(42/8,2)			# will return 5.25
	print(num2)

	s="string"
	print(s,type(s),s[3],s[3:5])      #String can be treated as list of characters -So u can use s[3] -i . s[3:5] - in 
									  # notice - s[3:5] will give in and not ing. SLICE doesnt return LAST index in python	
	for i in s:
		print(i,end="---")
	print()
		
	s="This is string"				  
	print(s)
	s="This is\nstring"			#Escape sequence	
	print(s)
	s=r"This is \nstring"		#r- raw string	
	print(s)
	s=''' this can be done for several lines    
		  see how I am doing this.''' 
		  												#multiple lines using ''' or """					
	s="""this can also be done for several lines
	     see how this works"""	


	x=(1,2,3)							#tuple - immutable
	print(x,type(x))
	for i in x:
		print(i,end="---")
	print()
	x=[1,2,3,4,8,76,12,33,55,11,43]		#list - mutable
	print(x,type(x))
	x.append(5)
	x.insert(2,7)          				#insert(index,value)
	print(x,type(x))
	print(x[0:6])                      # will return o to 5 only.. as ranges in python are non inclusive
	print(x[2:6])
	x[:]=range(100)
	print(x,end=" - ")
	print()
	print(x[0:100:4],end=" ")
	print()
	x[0:100:30]=(11,11,11,11)         #you can assign values to the slice  
	print(x)
	print(x[0:100:30],end=" ")


	
	d={'one':1,'two':2,'three':3}      #dictionary - Mutable 
	d1= dict(one=1,two=2,three=3,four="four")
	d["Seven"]=7
	d1["Seven"]=7
	print(d)
	print(d1)
	print(d1.get('six',"Other"))   #get six or if not there, print other
	for k in d:
		print(k,d[k])   # return the key - value pair but not in sorted order as it is hash so. 	
	print()					#To get the sorted order: use sorted(d.keys()) 
	for k in sorted(d.keys()):
		print(k,d[k])


	a,b=5,3
	print("{}/{} will give {}".format(a,b,a/b))
	print("{}//{} will give {}".format(a,b,a//b))
	print("divmod({},{}) will give {}".format(a,b,divmod(a,b)))	
	print(True and True)   # &  and | are bitwise operator in python
	print(True or False)   # and ,  or , not  are boolean operators	
	if(a>b or a==b):print("yes")


#################################################################################################################################
	print("This is main script")
	egg(3)						#call before the definition -possible because we have used the line if __name__ == "__main__":main()
	egg()                 		#It will take default argument


########################################################################################################################

print ("This will be executed first as the main() is called after this")

def egg(a=2):
	print("This is egg")
	for q in range(a,10):    #return a to 9..as range doesnt consider the last element
		print(q,end=" ")
	print()	
	for w in range(5):
		print("*",end="")
	print()	

#################################################################################################

if __name__ == "__main__":main()  #important line- Do not remove -This tells that only call main() if it is called as separate 
								  # file and not as any included module. 					
