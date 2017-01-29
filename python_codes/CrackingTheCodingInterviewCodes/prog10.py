#!/bin/python3
#HOURGLASS of matrix
import sys
arr = []
for arr_i in range(6):
   arr_t = [int(arr_temp) for arr_temp in input().strip().split(' ')]
   arr.append(arr_t)
fi=0
fj=0    
maxsum=None       
for i in range(0,4):
    for j in range(0,4):
        sum1=0
        for k in range(0,3):
            for l in range(0,3):
                if not( k == 1 and (l == 0 or l == 2)):
                        sum1=sum1+arr[i+k][l+j]
        if maxsum is None:
            maxsum=sum1
        else:
            if sum1>maxsum:
                maxsum=sum1
                fi=i
                fj=j                
print(maxsum)                        
        
