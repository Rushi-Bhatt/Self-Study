
import sqlite3  #python library that supports sqlite3
def insert(db,row):
	db.execute("insert into test(t,i) values (?,?)",(row['t'],row['i']))
	db.commit()

def retrieve(db,key):
	cursor=db.execute("select * from test where t=?",(key,))	#NOTE THAT HERE WE NEED TO PASS TUPLE(or list)< EVEN IF ONLY ONE VALUE
	return cursor.fetchone()       #fetchone() - fetch one result 

def update(db,row):
	db.execute("update test set i=? where t=? ",(row['i'],row['t']))
	db.commit()

def delete(db,key):
	db.execute("delete from test where t=?",(key,))	
	db.commit()

def diplay_rows(db):
	cursor =db.execute("select * from test order by t")
	for row in cursor:
		print("{} , {}".format(row['t'],row['i']))

def main():
#databse - Python by default comes with sqlite3 database
#sqlite - doesnt require separate db engine, its self container, server less, 0 configuration, fully transactional
#easy to use
	db=sqlite3.connect('test.db')         
	db.row_factory=sqlite3.Row     #Initialize a row factory - row factory determines how each row is returned
	db.execute("drop table if exists test")
	db.execute("create table test(t text, i int)")
	db.execute("insert into test (t,i) values (?,?)",('One', 1))
	db.execute("insert into test (t,i) values (?,?)",('Two', 2))
	db.execute("insert into test (t,i) values (?,?)",('Three', 3))
	db.execute("insert into test (t,i) values (?,?)",('Four', 4))
	db.execute("insert into test (t,i) values (?,?)",('Five', 5))
	db.commit()

	cursor=db.execute("select * from test order by t")     # each row is returned as tuple
	#for row in cursor:										# but after adding row factory, each row will be returned as row_objects
	#	print(row)											#row objects can be looked at as tuple, or dictionary, or lisy
	
	for row in cursor:
		print(dict(row))									#creating a dictionary from row iterable
		print(row['t'],row['i'])	

	print('create rows')
	insert(db,dict(t="seven",i=7))
	insert(db,dict(t="eight",i=8))
	insert(db,dict(t="nine",i=9))
	insert(db,dict(t="ten",i=10))
	diplay_rows(db)		

	print('retrieve rows')
	print(dict(retrieve(db,"seven")))
	
	print('update rows')
	update(db,dict(t="ten",i=11))
	diplay_rows(db)		

	print('delete rows')
	delete(db,"nine")
	diplay_rows(db)		

if __name__=="__main__":main()	