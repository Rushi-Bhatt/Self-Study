#Graph traversal 1)BFS, 2)DFS

def main():
	graph=dict(a=["b","e"],b=["f"],c=["a","e"],d=[],e=["d","g"],f=["e"],g=["h"],h=["j"],i=["h"],j=["i"])
	state=dict(a="white",b="white",c="white",d="white",e="white",f="white",g="white",h="white",i="white",j="white")
	parent=dict(a="",b="",c="",d="",e="",f="",g="",h="",i="",j="")
	distance=dict(a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0)
	queue=[]
	vertices=[]
	for key in sorted(graph):
		vertices.append(key)	
	print(vertices)	


	print("BFS")
	#BFS
	#consider each as a source vertex - BFS will give a BFS tree in one traversal
	for each in vertices:
		#set each a source
		if state[each]=="white":
			print("new Tree")
			state[each]="gray"
			distance[each]=0
			parent[each]=each
			queue.append(each)
			while len(queue)>0:
				node=queue.pop(0)
				print(node)
				for child in graph[node]:
					if state[child]=="white":
						state[child]="gray"
						parent[child]=node
						distance[child]=distance[node]+1	
						queue.append(child)
				state[node]="black"	

			

	#reset everything for DFS
	graph=dict(a=["b","e"],b=["f"],c=["a","e"],d=[],e=["d","g"],f=["e"],g=["h"],h=["j"],i=["h"],j=["i"])
	state=dict(a="white",b="white",c="white",d="white",e="white",f="white",g="white",h="white",i="white",j="white")
	parent=dict(a="",b="",c="",d="",e="",f="",g="",h="",i="",j="")
	distance=dict(a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0)
	stack=[]
	timeCounter=0

	print("DFS")
	#DFS
	#we will take each vertex one by one as a source and get the dfs forest
	for each in vertices:
		#set each a source
		
		if state[each]=="white":
			print("new Tree")
			state[each]="gray"
			distance[each]=0
			parent[each]=each
			stack.append(each)
			while len(stack)>0:
				node=stack.pop(-1)
				print(node)

				for child in graph[node]:
					if state[child]=="white":
						state[child]="gray"
						parent[child]=node
						distance[child]=distance[node]+1
						
						stack.append(child)
				state[node]="black"
				





if __name__=="__main__":main()		