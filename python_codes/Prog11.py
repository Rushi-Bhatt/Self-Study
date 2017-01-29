	#python library includes a module for unit test
	#unit test you can write once, and run again and again
import unittest
class testSayTime(unittest.TestCase):
	def setUp(self):            #Special method
		self.nums=list(range(5))

	def test_numbers(self):
		words=("oh","one","two","three","four")
		for i,n in enumerate(self.nums):
			self.assertEqual(argument1, words[i]) #assertEqual method - inbuilt for unittest module

if __name__=="__main__":unittest.main()   #It will call the unittest main() method, which will open up the class that inherit 
										  # from unittest