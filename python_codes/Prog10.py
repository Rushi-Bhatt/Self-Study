import sys  #System specific parameters and functions

def main():
	print("Python version {}.{}.{}".format(*sys.version_info))
	print("Platform info {}".format(sys.platform))

	import os           # IMPORT CAN BE DONE IN THE FUNCTION - So, import will only happen for if that function is called.
	print("OS Name:{}".format(os.name))
	print("Environment variable Name:{}".format(os.getenv('PATH')))
	print("CWD {}".format(os.getcwd()))
	print("Random byte string {}".format(os.urandom(23)))

	import urllib.request  
	page=urllib.request.urlopen("http://bw.org")   #iterator for the entire page
	for line in page:
		print(str(line,encoding='utf_8'),end=" ")

	import random
	print(random.randint(1,1000))	
	x=list(range(23))
	print(x)
	random.shuffle(x)    #Shuffle the list
	print(x)

	import datetime
	now=datetime.datetime.now()
	print(now.year,now.month,now.day,now.hour,now.minute,now.second,now.microsecond)

	#Apart from built in modules, theres third party modules as well called PyPI - Pyhton package index
	#just download the module, you will get setup.py script.. with argument install
	#python setup.py install ... will be installed in site-packages directory

if __name__=="__main__":main()	