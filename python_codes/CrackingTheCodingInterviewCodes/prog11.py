#!/bin/python3
#LINK LIST IN PYTHON
import sys
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None 
class Solution: 
    def display(self,head):
        current = head
        while current:
            print(current.data,end=' ')
            current = current.next
    def insert(self,head,data): 
    #Complete this method
        newNode=Node(data)
        if head is None:
            head=newNode
        else:
            current=head
            while current.next is not None:
                current=current.next
            current.next=newNode
        return head    
    def removeDuplicates(self,head):
        #Write your code here
        if head==None:
            return 
        elif head.next==None:
            return head
        else:
            i=head
            while i.next!=None:
                    q=i
                    while(q.data==q.next.data):
                        q=q.next    
                        if q.next==None:
                            break
                    if q.next==None:    #all the elemets are same    
                        i.next=None
                        break
                    else: 
                        i.next=q.next
                        i=q.next
            return head         
        
mylist= Solution()
T=int(input())
head=None
for i in range(T):
    data=int(input())
    head=mylist.insert(head,data)  
    head=mylist.removeDuplicates(head)  
mylist.display(head);                   