#Binary search tree implementation python with BFS DFS and linked list of same level nodes
from operator import itemgetter
from itertools import groupby
class Node():
	def __init__(self,value=None,level=-1):
		self.val=value
		self.left=None
		self.right=None
		self.level=-1
class BST():
	def __init__(self):
		self.root=None
		self.linkedList=[]
		self.queue=[]
		self.stack=[]

	def getRoot(self):
		return self.root

	def setRoot(self,value):
		self.root=value

	def add(self,value):
		if self.root==None:
			self.root=Node(value)
		else:
			self._add(value,self.root)

	def _add(self,value,node):
		if value<node.val:
			if node.left!=None:
				self._add(value,node.left)
			else:
				node.left=Node(value)	
		else:
			if node.right!=None:
				self._add(value,node.right)
			else:
				node.right=Node(value)

	def find(self,value):
		if self.root==None:
			return 	None
		else:
			return self._find(value,self.root)

	def _find(self,value,node):
		if value==node.val:
			return node
		elif value<node.val and node.left!=None:
			self._find(value,node.left)
		elif value>node.val and node.right!=None:
			self._find(value,node.right)	
		else:
			return None

	def deleteTree(self):
		self.root=None

	#mode - 1:inorder LVR 2:Preorder VLR 3:Postorder LRV	
	def printTree(self,mode=2):
		if self.root!=None:
			self._print(self.root,mode)

	def _print(self,node,mode=2):
		if(node != None):
			if mode==2:
				print("{} ".format(node.val))
				self._print(node.left,mode)
				self._print(node.right,mode)
			elif mode==1:
				self._print(node.left,mode)
				print("{} ".format(node.val))
				self._print(node.right,mode)
			elif mode==3:
				self._print(node.left,mode)
				self._print(node.right,mode)
				print("{} ".format(node.val))

	def dfs(self):
		self.linkedList=[]
		if self.root==None:
			return None
		else:
			self._dfs(self.root,-1)

	
	def _dfs(self,node,level):
		if node!=None:
			level=level+1
			node.level=level
			print(node.val,node.level)
			self.linkedList.append([node.val,node.level])

			self._dfs(node.left,level)
			self._dfs(node.right,level)	

	def bfs(self):
		self.linkedList=[]
		if self.root==None:
			return None
		else:
			self.root.level=0
			self.queue.append(self.root)
			while len(self.queue)>0:
				node=self.queue.pop(0)	
				if node!=None:
					print(node.val,node.level)
					self.linkedList.append([node.val,node.level])
					if node.left!=None:
						node.left.level=node.level+1
					if node.right!=None:
						node.right.level=node.level+1	
					self.queue.append(node.left)
					self.queue.append(node.right)


	def printLinkedList(self):
		if len(self.linkedList)==0:
			return None
		else:
			self.linkedList.sort(key=itemgetter(1))
			groups=[]
			list1=[]
			groups=groupby(self.linkedList,key=itemgetter(1))
			#print(groups)
			list1=[[item[0] for item in data] for (key,data) in groups]
			print(list1)



def bin(s):
    return str(s) if s<=1 else bin(s>>1) + str(s&1)

def main():
	tree = BST()
	tree.add(3)
	tree.add(4)
	tree.add(0)
	tree.add(8)
	tree.add(2)
	tree.add(9)
	tree.add(10)
	tree.printTree(2)
	#print (tree.find(10).val)
	#print (tree.find(3).val)
	#tree.deleteTree()
	#tree.printTree(2)
	print("BFS")
	tree.bfs()
	tree.printLinkedList()
	print("DFS")
	tree.dfs()
	tree.printLinkedList()

	a= int("00011001",2)
	
	b=a<<4
	print(a,bin(b))
if __name__=="__main__":main()		