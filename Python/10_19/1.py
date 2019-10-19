#-----------python是一种动态强类型的编程语言--------------------
'''
num = 10
a = type(num)  #---------type的返回值是一个对象，该对象的类型就是type
print(type(num))
print(a)
print(type(type(num)))
'''
#---------0,"",[],(),{},None的布尔值都是False

#-------------------对象之间值的比较:比较的是两个对象之间的内容
'''
a = '[1,2,3,4]'
b = '[1,2,3,4]'
a1 = {"ip":"127"}
b1 = {"ip":"127"}
        #当多个对象为字符串/整数/元组，并且内容相同时，他们的id相同
        #当多个对象为列表/字典，并且内容相同时，他们的id不同
print(id(a))
print(id(b))
if a==b:            #-------------用==作比较，比较的都是对象的内容
    print('==')
else:
    print("!=")
'''
#--------------------对象之间身份的比较：比较两个对象是不是同一个对象(id)
'''
a = [1,2,3,4]
b = [1,2,3,4]
print(id(a))
print(id(b))
if id(a) == id(b): #这条语句可以用 “if a is b: ”来替换，效果一样（is not 的效果与 is 刚好相反）
    print('==')
else:
    print("!=")
'''
#--------------------对象之间类型的比较:比较两个对象的类型是否相同（type）
'''
import types
a = 100
print(type(a) == type(100))
print(type(a) == types.IntType)
print(isinstance(a,type(100))) #内建函数isinstance()
'''
#-----------------------内置函数----------------
'''
a,b = divmod(10,3) #求商和余数
print(a,b)
a = -1.42
print(abs(a))   #取绝对值

import math
for i in range(0,10):
    print(round(math.pi,i)) #取确定位的整

import random # 随机数
print(random.randint(1,6)) #help(random)可查看random的帮助文档
'''

#---------------python中的函数可以作为参数，返回值。函数体内可以定义函数，这里的函数被称为"可调用对象"

#--------------python的函数参数可以是关键字参数：当函数参数有多个时，可以利用关键字参数的方式为其中的几个不连续参数传参
'''
a = [9,5,2,7]
b = sorted(a)
c = sorted(a,reverse=True)
print(a,b)
print(a,c)
'''
#---------------函数形参名前加上*，表示该形参是一个列表（参数组），可以接受多个不同类型参数
#---------------函数形参名前加上**，表示该形参是一个字典
'''
def log(*data):
    for i in data:
        print(i,end=";")
log(1,2,3,'4',[5,6])

def log(**data):
    for key in data:
        print(key,data[key])
log(x=1,y=2,z=3)
'''
