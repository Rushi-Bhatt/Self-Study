#BST - height and insert
import sys
class Node:
    def __init__(self,data):
        self.right=self.left=None
        self.data = data
class Solution:
    def insert(self,root,data):     #Very important method
        if root==None:
            return Node(data)
        else:
            if data<=root.data:
                cur=self.insert(root.left,data)
                root.left=cur
            else:
                cur=self.insert(root.right,data)
                root.right=cur
        return root
    
    def getHeight(self,root):
        #Write your code here
        if root==None:
            return -1                # None , so no node at all,, so height -1, 1 node - height 0, 4 nodes- height 3
        else:
            return 1+max(self.getHeight(root.left),self.getHeight(root.right))
            
          
T=int(input())
myTree=Solution()
root=None
for i in range(T):
    data=int(input())
    root=myTree.insert(root,data)
height=myTree.getHeight(root)
print(height)               
        
