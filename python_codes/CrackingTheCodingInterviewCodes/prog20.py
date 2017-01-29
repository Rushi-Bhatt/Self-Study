#You have two numbers represented by a linked list, where each node contains a single
#digit. The digits are stored in reverse order, such that the 1’s digit is at the head of
#the list. Write a function that adds the two numbers and returns the sum as a linked
#list.
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

	def display(self,head):
		current = head
		while current:
			print(current.data,end=' ')
			current = current.next
		print(" ") 		

	def sumNode(self,head1,head2):
		
		if head1==None:
			head=head2
		elif head2==None:
			head=head1
		else:
			h1=head1
			h2=head2
			head=None
			temp=0
			while h1!=None and h2!=None:
				
				total=0
				total=h1.data+h2.data+temp
				if total<10:
					data=total
					temp=0
				else:
					data=total-10
					temp=1
				
				newNode=Node(data)
				s=Solution()
				head=s.addNode(head,newNode)		
				h1=h1.next
				h2=h2.next
		
			if h1==None:
				while h2!=None:
					total=temp+h2.data
					if(total<10):
						temp=0
						data=total
					else:
						data=total-10
						temp=1	
					
					newNode=Node(data)
					s=Solution()
					head=s.addNode(head,newNode)		
					h2=h2.next


			else: #h2==None	
				while h1!=None:
					total=temp+h1.data
					if(total<10):
						temp=0
						data=total
					else:
						data=total-10
						temp=1	
					
					newNode=Node(data)
					s=Solution()
					head=s.addNode(head,newNode)		
					h1=h1.next
		
		if temp!=0:
			newNode=Node(1)
			s=Solution()
			head=s.addNode(head,newNode)		
		return head		
								
			
def main():

	head1=None
	for i in range(3):	
		s=Solution()
		a=Node(i+7)
		head1=s.addNode(head1,a)
	
	head2=None
	s=Solution()
	a=Node(8)
	b=Node(0)
	c=Node(3)
	d=Node(9)
	e=Node(9)
	head2=s.addNode(head2,a)
	head2=s.addNode(head2,b)
	head2=s.addNode(head2,c)
	head2=s.addNode(head2,d)
	head2=s.addNode(head2,e)

	s.display(head1)	
	s.display(head2)	
	head=None
	try:
		head=s.sumNode(head1,head2)	
	except ValueError as e:
		print(e)

	s.display(head)	
if __name__=="__main__":main()	