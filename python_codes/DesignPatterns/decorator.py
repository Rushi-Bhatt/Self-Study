""" Decorator pattern:  Our challenge here is to add additional features to an existing object dynamically without using subclassing. 
Patterns such as adapter, composite, and strategy are related to the decorator pattern.""" 

from functools import wraps

def make_blink(function):
    """  Defines the decorator """

    #This makes the decorator transparent in terms of its name and docstring
    @wraps(function)

    #Define the inner function
    def decorator():
        #Grab the return value of the original function
        ret = function()

        #Add new functionality to the original value
        return "<blink>"+ ret +"</blink>"
    
    return decorator

#apply the decorator here
@make_blink
def hello_world():
    """Original function !! """
    return "Hello world!"

#check the result of decorating
print(hello_world())

#check if the function name and docstring is still the same
print(hello_world.__name__)
print(hello_world.__doc__)
