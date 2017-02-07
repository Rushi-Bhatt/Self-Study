""" Proxy pattern: Proxy becomes handy when creating an object that is very resource intensive. The problem we need to solve here is to 
postpone our object creation as long as possible, due to the resource intensive nature of the object we're creating.
Therefore, there is a need for a placeholder which will in turn create the object if its creation is absolutely necessary.
The Proxy object is in charge of creating the resource intensive objects. Adapter and Decorator are related to the Proxy design pattern."""
import time

class Producer:
    """ Resource intensive producer object"""
    def produce(self):
        print("Producer is Busy..!!")
    def meet(self):
        print("Producer is available to meet..!!")

class Proxy:
    """ Less resource intensive proxy object"""
    def __init__(self):
        self.occupied = "No"
        self.producer = None

    def produce(self):
        """ Check if the producer is available"""
        print("Artist checking is the producer is available to meet..")
        if self.occupied =="No":
            #producer is available, create the producer object
            self.producer = Producer()
            time.sleep(2)

            #make the producer meet the artist
            self.producer.meet()

        else:
            #dont isinstantiate the producer
            time.sleep(2)
            print("Producer is busy..!!")
    
#isinstantiate the proxy
p = Proxy()

#make the proxy: artist produce untill producer is available 
p.produce() 

#Change the state to occupied
p.occupied="Yes"

#make the producer produce
p.produce()

