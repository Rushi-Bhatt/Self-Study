#To check if the tree is balanced or not
import math
class Node():
	def __init__(self,value=None,dist=0):
		self.val=value
		self.left=None
		self.right=None
		self.dist=dist
class BST():
	def __init__(self):
		self.root=None
		self.count=-1

	def getRoot(self):
		return self.root

	def setRoot(self,value):
		self.root=value

	def add(self,value):
		if self.root==None:
			self.root=Node(value,0)

		else:
			self._add(value,self.root)

	def _add(self,value,node):
		self.count+=1
		if value<node.val:
			if node.left!=None:
				self._add(value,node.left)
			else:
				node.left=Node(value,self.count)
				self.count=0	
		else:
			if node.right!=None:
				self._add(value,node.right)
			else:
				node.right=Node(value,self.count)
				self.count=0

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
				print("{} {}".format(node.val,node.dist))
				self._print(node.left,mode)
				self._print(node.right,mode)
			elif mode==1:
				self._print(node.left,mode)
				print("{} {}".format(node.val,node.dist))
				self._print(node.right,mode)
			elif mode==3:
				self._print(node.left,mode)
				self._print(node.right,mode)
				print("{} {}".format(node.val,node.dist))
																			
	
	def maxDepth(self):
		if self.root==None:
			return 0
		return self._maxDepth(self.root)

	def _maxDepth(self,node):
		if node==None:
			return 0
		else:
			return 1+max(self._maxDepth(node.left),self._maxDepth(node.right))	

	
	def minDepth(self):
		if self.root==None:
			return 0
		return self._minDepth(self.root)
	
	def _minDepth(self,node):
		if node==None:
			return 0
		else:
			return 1+min(self._minDepth(node.left),self._minDepth(node.right))	
		
	def isBalanced(self):
		#simple idea- differnece between Max depth and min depth of tree should not be >1
		if self.root==None:
			return True
		else:
			#print(self.maxDepth() , self.minDepth())
			if abs(self.maxDepth() - self.minDepth())>2:
				return False
			else:
				return True	

	def makeMinTree(self,array,start,end):
		
		if end<=start:
			return None
		else:
			mid=int(math.floor((start+end)/2))
			print(mid)
			self.add(array[mid])	
			self.makeMinTree(array,start,mid-1)
			self.makeMinTree(array,mid+1,end)						

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
	print(tree.isBalanced())
	array1=[1,2,3,4,5,6,7,8,9]

	tree=BST()
	tree.makeMinTree(array1,0,len(array1)-1)
	print("Done")
	tree.printTree(2)

if __name__=="__main__":main()		