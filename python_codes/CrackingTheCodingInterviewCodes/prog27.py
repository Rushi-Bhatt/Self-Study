#BST
class Node():
	def __init__(self,value=None):
		self.val=value
		self.l=None
		self.r=None
class BST():
	def __init__(self):
		self.root=None

	def add(self,value):
		if self.root==None:
			self.root=Node(value)
		else:
			self._add(value,self.root)

	def _add(self,val,node):
		if val<node.val:
			if node.l!=None:
				self._add(val,node.l)
			else:
				node.l=Node(val)
		else:
			if node.r!=None:
				self._add(val,node.r)
			else:
				node.r=Node(val)
	
	def find(self,value):
		if self.root==None:
			return None
		else:
			self._find(value,self.root)

	def _find(self,val,node):
		if val==node.val:
			return node
		elif val<node.val and node.l!=None:
			self._find(val,node.l)
		elif val>node.val and node.r!=None:
			self._find(val,node.r)
		else: return None
		
			
									