#Assume you have a method isSubstring which checks if one word is a substring of
#another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
#only one call to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).
import sys
from sys import argv
def main():

	m=input("enter string 1")
	n=input("enter string 2")

	new_m=m+m
	if n in new_m:     # To check if the string is part of another string #very important
		print("Yes, rotation applies")
	else:
		print("No")
if __name__=="__main__":main()		
