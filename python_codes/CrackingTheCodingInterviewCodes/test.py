import sys
class Node:
	def __init__(self,data=None):
		self.data = data
		self.next = None

class Solution:
	def __init__(self):
		self.count=0

	def add(self,head,newNode):
			if head==None:
				head=newNode
			elif head.next ==None:
				head.next=newNode
			else:
				current=head
				while current.next!=None:
					current=current.next
				current.next=newNode
			return head
	
	def display(self,head):
		current=head
		while current:
			print(current.data,end=" ")
			current=current.next
		print(" ")	

class BSTNode:
	def __init__(self,data=None):
		self.data=data
		self.right=self.left=None		

class BST():
	def __init__(self):
		self.root=None
	
	def add(self,value):
		if self.root==None:
			self.root=BSTNode(value)
		else:
			self._add(self.root,value)

	def _add(self,node,value):
		if node.data<value:
			if node.left!=None:
				self._add(node.left,value)
			else:
				node.left=node	
		else:
			if node.right!=None:
				self._add(node.right,value)
			else:
				node.right=node

	def find(self,value):
		if self.root==None:
			print("Tree is empty")
		else:
			self._find(self.root,value)
	
	def _find(self,node,value):
		if node.data == value:
			print("node found")
			return node

		elif node.data<value:
			if node.left!=None:
				self._find(node.left,value)
			else:
				print("Not found")
				return None	
		else:
			if node.right!=None:
				self._find(node.right,value)
			else:
				print("Not found")
				return None
		return node		



			
def main():
	print("Hello")
	a=Node(11)
	a1=Node(1)
	a2=Node(2)
	a3=Node(3)
	a4=Node(4)
	s=Solution()
	hd=None	
	hd=s.add(hd,a)
	hd=s.add(hd,a1)
	hd=s.add(hd,a2)
	hd=s.add(hd,a3)
	hd=s.add(hd,a4)
	s.display(hd)

if __name__ == "__main__":main()
