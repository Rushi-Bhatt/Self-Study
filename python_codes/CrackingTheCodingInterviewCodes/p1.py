 
nodes="(b,d) (d,e) (a,b) (c,f) (e,g) (a,c)"
parent=[]
child=[]
list1=[]

for index,i in enumerate(nodes):
        if i=="(":
            parent.append(nodes[index+1])
            child.append(nodes[index+3])
            temp=[]
            temp.append(nodes[index+1])
            temp.append(nodes[index+3])
            list1.append(temp)
print(parent)
parent=list(set(parent))
o=dict((el,[]) for el in parent)
print(list1)
print(child)        
for each in parent:
    for i in range(len(list1)):
        if list1[i][0]==each:
            o[each].append(list1[i][1])
            if len(o[each])>2:
                print("E1")               #more than 2 children

print(o)
list2=[list(i) for i in set(tuple(i) for i in list1)]
if len(list1)!=len(list2):
    print("E2")   #edges duplicate

print(o)

 