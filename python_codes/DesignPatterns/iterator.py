"""  The iterator pattern allows a client to have sequential access to the elements of an aggregate object without exposing its 
underlying structure. An iterator isolates access and traversal features from an aggregate object. It also provides an interface 
for accessing the elements of an aggregate object. An iterator keeps track of the objects being traversed. One of the recommended 
solutions is to make the aggregate object create an iterator for a client. The composite design pattern is related to the iterator 
pattern.
"""
def count_to(count):
    numbers_in_kannada = ["ondu","eradu","Muru","Nalku","Ayadu"]
    #our built in iterator, creates tuples such as (1,"ondu")
    iterator = zip(range(count),numbers_in_kannada)
    for position, number in iterator:
        yield number

for num in count_to(3):
    print("{}".format(num))