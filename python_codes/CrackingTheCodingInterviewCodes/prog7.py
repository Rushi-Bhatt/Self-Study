#Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
#column is set to 0.

import sys
from sys import argv
def main():

	m=int(input("enter size: m "))
	n=int(input("enter size: n "))

	matrix=[[0 for i in range(n)] for j in range(m)]
	print(matrix)
	for i in range(m):
		for j in range(n):
			matrix[i][j]=int(input("M[{}][{}]:".format(i,j)))
	rows=[]
	cols=[]
	for i in range(m):
		for j in range(n):
			if matrix[i][j]== 0:
				print("zero for ",i,j)
				rows.append(i)
				cols.append(j)
	sr=set(rows)
	sc=set(cols)
	for i in sr:
		for j in  range(0,n):
			matrix[i][j]=0
	for j in sc:
		for i in range(0,m):	
			matrix[i][j]=0				

	print(matrix)
if __name__=="__main__":main()		