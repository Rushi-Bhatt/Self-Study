#Queue using two stacks

class MyQueue(object):
    def __init__(self):
        self.s1=[]
        self.s2=[]
        self.element=None
        self.popHappened=False
    def peek(self):    
        if(self.popHappened==False and self.element!=None):
            return self.element
        else:
            if(len(self.s1)==0):
                raise ValueError("Queue is empty")
            else: 
                while len(self.s1)>1:
                    self.s2.append(self.s1.pop())
                self.element = self.s1.pop()
                self.s2.append(self.element)
                while len(self.s2)!=0:
                    self.s1.append(self.s2.pop())
                self.popHappened=False    
                return self.element
        
    def pop(self):
        if(len(self.s1)==0):
            raise ValueError("Queue is empty")
        else:    
            self.popHappened=True 
            while len(self.s1)>1:
                self.s2.append(self.s1.pop())
            self.element = self.s1.pop()
            while len(self.s2)!=0:
                self.s1.append(self.s2.pop())
       
    def put(self, value):
        self.s1.append(value)

queue = MyQueue()
t = int(input())
for line in range(t):
    values = map(int, input().split())
    values = list(values)
    if values[0] == 1:
        queue.put(values[1])        
    elif values[0] == 2:
        queue.pop()
    else:
        print(queue.peek())
        
