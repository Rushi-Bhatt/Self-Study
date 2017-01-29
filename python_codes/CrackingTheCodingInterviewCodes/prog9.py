#print odd and even ocharacters f strings

import sys
inputArray=[]
for line in sys.stdin:
    inputArray.append(line)
A=[]
n=int(inputArray[0])
for i in range(1,len(inputArray)):
    A.append(inputArray[i].rstrip("\n"))

for each in A:
    even=""
    odd=""
    for i,c in enumerate(each):
        if(i % 2==0):
            even+=c
        else:
            odd+=c    
    print("{} {}".format(even,odd))