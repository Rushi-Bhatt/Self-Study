#rotate N*N matrix by 90

import sys
from sys import argv
def main():

	n=int(input("enter size:"))
	matrix=[[0 for i in range(n)] for j in range(n)]
	new_matrix=[[0 for i in range(n)] for j in range(n)]
	
	for i in range(n):
		for j in range(n):
			matrix[i][j]=input("M[{}][{}]:".format(i,j))
	
	for i in range(n):
		for j in range(n):
			new_matrix[n-i-1][j] = matrix[j][i]
	print(new_matrix)
	
	print("In place transformation")
	for x in range(0,int(n/2)):
		for y in range(x,n-x-1):
			temp=matrix[x][y]
			matrix[x][y]=matrix[y][n-1-x]
			matrix[y][n-1-x]=matrix[n-1-x][n-1-y]
			matrix[n-1-x][n-1-y]=matrix[n-1-y][x]
			matrix[n-1-y][x]=temp
	print(matrix)		
if __name__=="__main__":main()		