#BFS traversal of BST tree
import sys

class Node:
    def __init__(self,data):
        self.right=self.left=None
        self.data = data
class Solution:
    def insert(self,root,data):
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
    def __init__(self):
        self.queue=[]
        self.count=-1
    
    def levelOrder(self,root):
        #Write your code here
        self.count+=1
        if(self.count==0):
            self.queue.append(root)
        while len(self.queue)>0:
            each=self.queue[0]
            print(each.data,end=" ")
            del self.queue[0]
            if each.left !=None:
                self.queue.append(each.left)
            if each.right!=None:    
                self.queue.append(each.right)
            self.levelOrder(each)

T=int(input())
myTree=Solution()
root=None
for i in range(T):
    data=int(input())
    root=myTree.insert(root,data)
myTree.levelOrder(root)
