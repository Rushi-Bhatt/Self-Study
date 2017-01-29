#To match the brackets and check whether the expression is balanced

def is_matched(expression):
    n=len(expression)
    s=[]
    if(n%2 != 0):
        return False
    else:
        for i in range(0,int(n)):
            if(expression[i]=='(' or expression[i]=='{' or expression[i]=='['):
                s.append(expression[i])
            else:
                if(len(s)<1):
                    return False
                else:
                    ob=s.pop()
                cb=expression[i]
                if ob =='(' and cb != ')':
                    return False
                elif ob =='{' and cb != '}':
                    return False
                elif ob =='[' and cb != ']':
                    return False
                else:
                    pass
        if(len(s)>0):    # to check if there are extra characters in the array.. extra opening brackets
            return False
        else:return True
                

t = int(input().strip())
for a0 in range(t):
    expression = input().strip()
    if is_matched(expression) == True:
        print("YES")
    else:
        print("NO")
