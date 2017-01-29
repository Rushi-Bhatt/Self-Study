import re 						#for regex
def main():
								#reg exp with re module
	file1=open("Test1.txt")
	for line in file1.readlines():
		match=re.search('is(n|N)',line)  # match object... 
		if match:
			print(line,end="")	
			print(match.group())	        # to print the match object
	print()		
#To replace only the matched places, we can do as follows:

	file3=open("Test1.txt")
	pattern=re.compile('is(n|N)')           #re.compile- precompile the pattern so that you can use that variable instead of regex
	for line in file3.readlines():						
		match=re.search(pattern,line)  		# match object... 
		if match:
			print(line.replace(match.group(),"***"),end="")	
			print(match.group())	        # to print the match object
	print()		

#if we just want to replace in entire file ...
	file2=open("Test1.txt")
	pattern=re.compile('is(n)',re.IGNORECASE)     #re.IGNORECASE- to ignore case
	for line in file2.readlines():
		print(re.sub(pattern,'***',line))  #search and replace by re.sub
	print()	

	try:
		file4=open("Tes1.txt")
	except IOError as e:
		print("Could not find the file",e) 
	else:
		print("file opened successfully.")
		for line in file4.readlines():
			print(line.strip())             #strip() - automatically strip any trailling space and \n characters. same as end=" " 

	try:
		for eachLine in readFile("Test1.doc"):
			print(eachLine.strip()) 
	except IOError as e:
		print("Could not find file",e)			
	except ValueError as  e:
		print("only txt s are allowed")	

def readFile(filename):
		if(filename.endswith(".txt")):
			file5=open(filename)
			return file5.readlines()
		else: 
			raise ValueError("Only text files are allowed dude")	


if __name__=="__main__":main()	