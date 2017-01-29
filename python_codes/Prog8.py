def main():
#Even though the OS doesnt differentiate between binary and text files, python does. So there are different methods to read/write both	
############### TEXT FILES ################################################################################################################
	infile=open("Test1.txt")   #OPENS THE FILE IN READ MODE  'r' - read, 'w' - write , 'a' - append(Cursor at the end)
						  #  'r+' - read and write in the same file handle object, 'rt' - text file mode, 'rb' - binary file mode	
	for line in infile:		  #f.readlines() - works same as f- iterator object	
		print(line,end=" ")
	print("Done...lets print in the file")

	#copying line by line
	outfile=open("new.txt",'w')
	infile=open("Test1.txt")
	for line in infile:
		print(line,file=outfile,end=" ")    #SPECIFY THE FILE HANDLE IN PRINT
	print("done..check the file")	

	#copying  buffer mode
	buffersize=5000
	outfile=open("new1.txt",'w')
	infile=open("Test1.txt")
	buffer1=infile.read(buffersize)   #READ method on infile is not iterable-  so use while
	while len(buffer1):
		outfile.write(buffer1)
		print(".",end=" ")
		buffer1=infile.read(buffersize)
	print("DONE")	

############### BINARY FILES ################################################################################################################
	infile=open("test.jpg",'rb')   	#OPENS THE FILE IN READ BINARY MODE since not a text file, if you dont specify the mode, it will give error  		 	
	outfile=open("new.jpg",'wb')    #OPENS THE FILE IN WRITE BINARY MODE
	buffersize=50000
	buffer1=infile.read(buffersize)
	while len(buffer1):
		outfile.write(buffer1)
		print("..",end=" ")
		buffer1=infile.read(buffersize)
	print("Done...see the file")

if __name__=="__main__":main()	