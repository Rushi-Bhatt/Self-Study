#Design an algorithm and write code to remove the duplicate characters in a string
#without using any additional bu#er. NOTE: One or two additional variables are !ne.
#An extra copy of the array is not.

import sys
from sys import argv
def main():
	s=input(">")
	print(set(s))
	x=''.join(list(set(s)))
	print(x)


if __name__=="__main__":main()		