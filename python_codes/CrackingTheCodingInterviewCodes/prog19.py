# delete a node in the middle of a single linked list, given
#only access to that node.
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

	def deleteNode(self,head,nd):
		current=head
		if current==None:
			raise ValueError("the list is empty")
		elif current.next==None: 
			if current.data!=nd:
				raise ValueError("the element is not in the list")	
			else:
				head=None
				return head
		else:
			current=head
			while current.next!=None:
				if current.next.data==nd:
					if(current.next.next!=None):
						current.next=current.next.next
						break
					else:
						current.next=None	
				else:			
					current=current.next
			return head	

			
def main():

	head=None
	for i in range(6):	
		s=Solution()
		a=Node(i*5)
		head=s.addNode(head,a)
	
	s.display(head)	
	
	try:
		data=s.deleteNode(head,25)	
	except ValueError as e:
		print(e)

	s.display(head)	
if __name__=="__main__":main()	