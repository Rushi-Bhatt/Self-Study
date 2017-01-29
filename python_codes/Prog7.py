def main():
	
	####################################### STRINGS #################################################################################################################
	
	#string is an object.. and variable that you store the string in is just a reference.
	s="abcd"
	s.upper()
	"abcd".upper
	"This is a string {}".format(42)  #Python 3 - % is no longer valid . "abcd %r" % 42 - Doesnt work
									  #Python 2 - no format method.It was overloading % operator like C. There you needed to know the type	
	s="this is a string-value {}"
	id(s)                    
	s.format(42)			#new string
	id(s)					#ID CHANGES _ STRINGS ARE IMMUTABLE 
	
	#str.format
	
	a=5,b=42
	s="This is a - {} and this is b - {}".format(a,b)
	#What if you want to swap, or use the same value more than once
	s="This is a - {1} and this is b - {0}, this too is {1}".format(a,b)  #You can pass the position of the variable in the curly braces
	s="This is a - {bob} and this is b - {fred}, this too is {bob}".format(bob=a,fred=b)  #You can pass the name of the variable in the curly braces
	d=dict(bob=a,fred=b)
	s="This is a - {bob} and this is b - {fred}, this too is {bob}".format(**d)  #You can use dictionary with **
	

	#String is immutable, so string doesnt  change.. new string with different ID will be returned
	s.capitalize()  #First letter Capitalize
	s.upper()       #All capitalize
	s.lower()		#All lower
	s.swapcase()    #opposite case
	s.find('is')    #returns the first occurence of 'is'  - 2 in this case
	s.replace('this','that')
	s.strip()        #Strips perticular char from beginning and end of the string.. By default WhiteSpace
	s.rstrip()		 #Strip whitespaces from the right side - i.e end only
	s1="This is a string\n"
	s1.rstrip('\n')	 #Strip new line from end of the string
	s.isalnum()      #Check if the string only has alpha numeric - returns false in this case since we have white space as well
	s.isalpha()      #check for alpha characters
	s.isdigit()		 #check for digits
	s.isprintable()  #check if all the characters are printable

	#spliting and joining strings
	s="This is a   string of words"
	s.split()       #Split the strings based on char- default whitespace(Folding happens-so remove multiple white spaces as well)
					#folding thing wont happen for other characters though
	s.split('i')    #Extra white spaces will be there between a and str
	words=s.split()
	for w in words:
		print(w)
	new=' '.join(words)  #Join the words with space -- You can use any character. Forexp. ':'.join(words)->This:is:a	

	s="abc"
	s.center(10,'*')  #center the string in new 10 char string and fill the rest with *
	##################################################################################################################################################

	######################################### TUPLES and LISTS################################################################################################
	t=1,2,3,4,5      # TUPLES are actually created using comma(,). The parenthsis around it is just a formating
	#or 			 #So if you want to create 1 char tuple, t = (1) wont work.	
	t=(1,2,3,4,5)    
	print t[0],t[4],len(t),min(t),max(t)
	t=(1)
	type(t)       # INT - Not tuple
	t=(1,)
	type(t)       # Tuple
	t=tuple(range(25))
	t[10]=42      #ERROR - Tuple objects are immutable - Cant assign items or change them ---- IMPORTANT

	t=[1,2,3,4,5]    #LIST - Created by Square bracket
	print t[0],t[4],len(t),min(t),max(t)
	t[10] =42     #Done- AS LIST IS MUTABLE   

	t=tuple(range(25))
	10 in t   #returns true
	50 in t   #false
	50 not in t #true
	for i in t:
		print(i)
	t.count(5) #Number of occurences of 5
	t.index(5) #Index of first occurence of 5


	x=list(range(20))
	10 in x   #returns true
	20 in x   #false
	50 not in x #true
	for i in x:
		print(i)
	x.count(5) #Number of occurences of 5
	x.index(5) #Index of first occurence of 5	
	
	t[10]=25   #ERROR
 	x[10]=25   #CAN BE DONE
 	t.append(100)   #ERROR - Tuple object has no attrib append 	
 	x.append(100)   #Can be done. Append will only take 1 argument.. To add more values- use extend 
 	x.extend(range(20))
 	x.insert(2,25)   #index, value

 	x.remove(12)     #REMOVE FIRST OCCURENCE OF VALUE 12	
	del x[12]        #DELETE ELEMENT AT INDEX 12

	s=x.pop()         #REMOVE LAST ELEMENT FROM THE LIST AND RETURN IT
	s=x.pop(0)		  #REMOVE FIRST ELEMENT FROM THE LIST AND RETURN IT

	##################################################################################################################################################

	######################################### DICTIONARIES ################################################################################################
	d1=dict(a=1,b=2,c=3)
	d2={'d':4,'e':5,'f':6}
	d3=dict(g=7,**d1)
	d4=dict(**d1,**d2)
	print(d3)
	print(d4)
	'd' in d2  #returns true
	'a' in d2  #FALSE
	for k in d:
		print(k)
	for key,value in d.items():   #d.items() for both key and values
		print(key,value)
	d1.get('a')	   # 1
	d1.get('d')    #Nothing--
	d1['d']        #ERROR    , So always use .get method for dictionary
	d1.get('d',"DEFAULT") #DEFAULT

	del d1['a']   #delete the value
	val=d1.pop('a')   #Delete and return the value

	##################################################################################################################################################

	######################################### byte and byte array ################################################################################################
	fin=open('utf8.text','r',encoding='utf_8')   #Tells the python, that the file should be read as utf8 file
	fout = open('utf8.html','w')
	outbyte=bytearray()   						#bytearray - Mutable List of bytes, bytes- constructor
	for line in fin:							#bytes, like str, is an immutable sequence of bytes. bytearray is mutable.
		for char in line:
			if ord(c)>127:						# integer equivalent of char - Opposite func- chr(a)
				outbyte+= bytes('&#{:04d};'.format(ord(c)),encoding="utf_8") # += same as appeding, but append more than one objects
			else:
				outbyte.append(ord(c))

	outstr=str(outbyte,encoding="utf_8")
	print(outstr,file=fout)                    #PRINTING IN FILE
	print(outstr)	
	print("Done")
   
if __name__=="__main__":main()	