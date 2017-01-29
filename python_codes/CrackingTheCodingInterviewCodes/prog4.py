#Anagrams

import sys
from sys import argv
def main():
	s1=input(">")
	s2=input(">")
	if(len(s1)!=len(s2)):
		print("Not anagrams")
	else:
		if set(s1)==set(s2):
			print("Anagram")
		else:
			print("Not anagrams")
	
if __name__=="__main__":main()		