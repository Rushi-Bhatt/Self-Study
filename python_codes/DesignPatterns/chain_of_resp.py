"""Chain of Responsibility opens up various possibilities of processing for a given request. The Chain of Responsibility 
pattern decouples the request and its processing. Our given problem is that many different types of processing needs to be 
done depending on what the request is.  Composite is related to the Chain of Responsibility design pattern."""

class Handler: #Abstract Handler
    def __init__(self,succesor):
        self._successor = succesor
    def handle(self,request):
        handled = self._handle(request)
        if not handled: #if not handled by itself, pass it to successor
            self._successor.handle(request)
    
    def _handle(self,request):
        raise NotImplementedError("Must provide implemetation in subclass!!")

class ConcreteHandler1 (Handler): #Concrete handler
    def _handle(self,request):
        if 0<request<=10:
            print("Request {} is handled by CH1".format(request))
            return True

class ConcreteHandler2 (Handler): #Concrete handler
    def _handle(self,request):
        if 11<request<=20:
            print("Request {} is handled by CH2".format(request))
            return True

class DefaultHandler(Handler):
     def _handle(self,request):
            print("End of chain...Request {} is handled by Default handler".format(request))
            return True
                        
class Client: #using handler
    def __init__(self):
        self.handler = ConcreteHandler1(ConcreteHandler2(DefaultHandler(None)))  #Chain of handler

    def delegate(self,requests):
        for each in requests:
            self.handler.handle(each)

c= Client()
requests = [1,5,12,30]
c.delegate(requests)

