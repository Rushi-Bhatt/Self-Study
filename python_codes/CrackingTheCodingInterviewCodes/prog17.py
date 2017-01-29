#Remove duplicate from an unsorted linked list

class Node():
    def __init__(self,data):
        self.data=data
        self.next=None

class Solution():

    def __init__(self):
        self.temp=[]

    def add(self,head,newNode):
        if head==None:
            head=newNode
        elif head.next==None:
            head.next=newNode
        else:
            current=head
            while current.next !=None:
                current=current.next
            current.next=newNode
        return head

    def removeDuplicate(self,head):
        if head==None or head.next==None:
            return head
        else:
            current=head 
            while current.next!=None:
                if(current.data not in self.temp): 
                    self.temp.append(current.data)
                
                if(current.next.data not in self.temp):
                    self.temp.append(current.next.data)
                    current=current.next   
                else:   
                    p=current
                    if(p.next!=None):
                        while p.next.data in self.temp:
                            if(p.next!=None):
                                p=p.next
                        if(p.next!=None):
                            current.next=p.next 
                            current=p.next   
                        else:
                            current.next=None                
            return head

    def display(self,head):
        current = head
        while current:
            print(current.data,end=' ')
            current = current.next     
        print(" ")               

def main():
    elems=[]
    n=int(input().strip())
    for j in range(n):
        elems.append(int(input().strip()))
    head=None
    s=Solution()
    for each in elems:
        newNode=Node(each)
        head=s.add(head,newNode)
    s.display(head)    
    head=s.removeDuplicate(head)
    s.display(head)

if __name__=="__main__":main()    