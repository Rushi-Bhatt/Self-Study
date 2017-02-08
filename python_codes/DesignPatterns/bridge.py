""" Bridge pattern: - The bridge pattern helps untangle an unnecessary complicated class hierarchy, especially when 
implementation specific classes are mixed together with implementation-indendent classes. So our problem here is that there are 
two parallel or orthogonal abstractions. One is implementation-specific, and the other one is implementation-independent.
The abstract factory and adaptor patterns are the related patterns to this rich design pattern."""

class DrawingAPIOne(object):
    """ Implementation specific abstraction:Concrete class one"""
    def draw_circle(self,x,y,r):
        print("API 1 is drawing circle with {} {} {}".format(x,y,r))


class DrawingAPITwo(object):
    """ Implementation specific abstraction:Concrete class two"""
    def draw_circle(self,x,y,r):
        print("API 2 is drawing circle with {} {} {}".format(x,y,r))
        
class Circle(object):
    """ Implementation independent abstraction"""
    def __init__(self,x,y,r,drawing_api):
        self._x = x
        self._y = y
        self._r = r
        self._drawing_api = drawing_api
    
    def draw(self):
        """ Implementation specific abstraction taken care of by another class:DrawingAPI"""
        self._drawing_api.draw_circle(self._x,self._y,self._r)
    
    def scale(self,percent):
        """ Implementation independent """
        self._radius *= percent

#Build the circle object using API1
circle1 = Circle(1,2,3,DrawingAPIOne())
circle1.draw()

#Build the circle object using API2
circle2 = Circle(1,3,5,DrawingAPITwo())
circle2.draw()
        