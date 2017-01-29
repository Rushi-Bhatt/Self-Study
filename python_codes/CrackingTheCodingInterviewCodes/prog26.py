#Sort algorithms 

import math
import sys
def mergeSort(array):
	result=[]
	if len(array)<2:
		return array 
	mid=len(array)//2
	y=mergeSort(array[:mid])
	z=mergeSort(array[mid:])
	i=0
	j=0
	while i< len(y) and j< len(z):
		if y[i]>z[j]:
			result.append(z[j])
			j+=1
		else:
			result.append(y[i])
			i+=1
	
	result+=y[i:]
	result+=z[j:]			
	return result

def bubbleSort(s):
	for i in range(len(s)):
		swap=0
		for j in range(len(s)-1):
			if s[j]>s[j+1]:
				s[j],s[j+1]=s[j+1],s[j]
				swap+=1
		if swap==0:
			break
	return s		

def selectionSort(array):
	for i in range(len(array)):
		smallest=sys.maxsize
		k=0
		for j in range(i,len(array)):
			if smallest>array[j]:
				smallest=array[j]
				k=j		
		array[i],array[k]=array[k],array[i]	
	return array	

def quickSort(array,p,r):
	if p<r:
		q=partition(array,p,r)
		quickSort(array,p,q-1)
		quickSort(array,q+1,r)
	return array	

def partition(array,p,r):
	if p<r:
		i=p-1
		pivot=array[r]
		for j in range(p,r):
			if array[j]<pivot:
				i+=1
				array[j],array[i]=array[i],array[j]
		array[i+1],array[r]=array[r],array[i+1]	
		return i+1	


def main():

	s=[1,9,4,2,19,23,11,65,20]
	print("bubble sort")
	bs = bubbleSort(s)
	print(bs)

	print("merge sort")
	ms=mergeSort(s)
	print(ms)

	print("selection sort")
	ss=selectionSort(s)
	print(ss)

	print("quickSort sort")
	qs=quickSort(s,0,len(s)-1)
	print(qs)

if __name__=="__main__":main()	