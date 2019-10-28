'''
lst = []
str = "1 2 3 4 5"
lstl = str.split(" ")
print(type(lstl))
print(type(lst))
i = 0
while i <= len(lstl)+1:
    lst.append(int(lstl.pop()))
    print(lst)
    i+=1
'''
'''
print(hello ,
     RC);print("Hello ")
'''
'''
s = 1
def func():
    s = 2
    print(s)
func()
'''
'''
def _add():
    return 1
print(_add())
'''

import calc
print(calc.add(1,2))
print(calc.add.__doc__)