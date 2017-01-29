#find all the subsets of set
import itertools
s=set([1,2,3,4])
print(s)
a=set()
for i in range(len(s)+1):
	b=set(itertools.combinations(s,i))
	a=a|b
print(len(a)," - ",a)

a=[2,3,4]
for each in itertools.combinations(a,1):
	print(each," ")

a="stack"
for each in itertools.permutations(a):
	print("".join(each),end=" ")	

#To find all the possible valid permutation of brackets: 
s=[0 for i in range(6)]
count=0
number=3

def combBracket(nl,nr,s,count=0):
	if nl<0 or nr<nl:
		return None
	elif nl==0 and nr==0:
		print("".join(s))
	else:
		if nl>0:
			s[count]="("
			combBracket(nl-1,nr,s,count+1)	
		if nr>nl:
			s[count]=")"			
			combBracket(nl,nr-1,s,count+1)	

combBracket(3,3,s,0)