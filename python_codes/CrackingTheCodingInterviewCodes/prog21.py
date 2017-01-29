#Given a circular linked list, implement an algorithm which returns node at the beginning
#of the loop -  simple data appoach.. where I am just checking based on data

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
									
	def pointToCycle(self,head):

		if(head==None):
			raise ValueError("List is empty")
		elif head.next==None:
			raise ValueError("No cycle")
		else:
			current=head
			temp=[]
			node=None
			while current!=None:
				if(len(temp)==0 or len(temp)==1):
					pass
				
				else:	
					for i in range(len(temp)):
						if current.data==temp[i].data:
							node=temp[i]
							print("Found a cycle")	
							return node
						
				temp.append(current)
				if current.next!=None:
						current=current.next
				else:
						return node	
				

def main():

	head=None
	s=Solution()
	a=Node("A")
	b=Node("B")
	c=Node("C")
	d=Node("D")
	e=Node("E")
	f=Node("F")
	g=Node("C")
	h=Node("G")
	
	head=s.addNode(head,a)
	head=s.addNode(head,b)
	head=s.addNode(head,c)
	head=s.addNode(head,d)
	head=s.addNode(head,f)
	head=s.addNode(head,g)
	head=s.addNode(head,h)
	
	s.display(head)	
	try:
		node=s.pointToCycle(head)	
	except ValueError as e:
		print(e)

	print(node.data)
	
if __name__=="__main__":main()	