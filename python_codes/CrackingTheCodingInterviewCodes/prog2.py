#Write code to reverse a C-Style String. (C-String means that “abcd” is represented as
#!ve characters, including the null character

import sys
from sys import argv
def main():
	a=input("Enter C style string")
	a+="$"
	print(a)
	a=a[0:len(a)-1]
	newString=""
	for i in reversed(a):
		newString+=i
	newString1="$"+newString	
	print(newString1)


if __name__=="__main__":main()		