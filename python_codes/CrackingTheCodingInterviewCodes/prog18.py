#return nth to the last element of linked List
class Node():
	def __init__(self,data=None):
		self.data=data
		self.next=None


class Solution():
	def __init__(self):
		self.count=0

	def addNode(self,head,newNode):
		if(head==None):
			head=newNode
			head.next=None
		elif(head.next==None):
			head.next=newNode
		else:
			p=head
			while p.next!=None:
				p=p.next
			p.next=newNode
		return head		
	
	def findCount(self,head):
		if(head==None):
			return 0
		elif head.next==None:
			return 1
		else:
			temp=0
			p=head
			while p.next!=None:
				p=p.next
				temp+=1	
			temp+=1
			return temp

	def display(self,head):
		current = head
		while current:
			print(current.data,end=' ')
			current = current.next
		print(" ") 		

	def findNode(self,head,n):
		self.count=self.findCount(head)
		if self.count==0:
			raise ValueError("the list is empty")
		elif self.count<n:
			raise ValueError("the list is not that long")	
		else:
			current=head
			for i in range(self.count-n):
				current=current.next
			return current.data	


			
def main():

	head=None
	for i in range(6):	
		s=Solution()
		a=Node(i*5)
		head=s.addNode(head,a)
	
	s.display(head)	
	data=0
	try:
		data=s.findNode(head,2)	
	except ValueError as e:
		print(e)

	print(data)
if __name__=="__main__":main()	