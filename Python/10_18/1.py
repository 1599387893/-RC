'''
#格式化字符串
num = 10
s = "num = %d" % num
s1 = 'num = {}'.format(num)
s2 = f'num = {num}'
print(s)
print(s1)
print(s2)
'''
'''
#bool类型
value = True
print(type(value))
print(value+2)
print(type(value+2))
'''
'''
#输入输出函数
s = input("Enter #")
print(s)
print(type(s))
'''

#------------------------操作符
'''
a = 1
b = 2
print(a / b)
print(a // b)
c = 3
print(a < b < c)
'''
'''
#-------python中没有自增和自减运算符
num = 2
print(++num)
print(--num)
#print(num++)
#print(num--)
'''
'''
#-------------列表/元组/字典
#   列表(list)
a = [9,'hehe',['v',45],3,1]
print(a[-2])
print(a)

#   元组
b = (9,5,"hehe",1)
print(b[-2])
print(b)
#error b[1] = 0

#------------------------列表时可变对象，元组是不可变对象(python中大多数都是不可变对象)

#字典 ---底层为哈希表   保存的是键值对
c = {
    'ip' : '127.0.0.1',
    'port' : '8080'
}
print(c['ip'])
print(c['port'])
'''

#python 有垃圾回收机制
'''
a = 'hehe'
b = a
print(id(a))
print(id(b))
'''
'''
result = input("You ready to do this?")
if result == '1':
    print("You will be tried!")
elif result == '2':
    print("It's Ok!")
else:
    print("enter error!")
print("Finish")
'''
#------------------------python 中没有switch/case

#--循环
'''
num = 1
while num <= 10:
    print(num)
    num+=1
'''
'''
for num in range(0,11):
    print(num)

a = [9,2,7]
for num in a:
        print(num)

a = {'ip':"127.0.0.1",'port':"8080"}
for key in a:
    print(key,a[key])
'''
'''
for a in range(1,100):
    if(a%3 == 0):
        continue
    if(a%10 == 0):
        pass
    print(a)
'''
#--pass 占位标记
'''
a = [1,2,3,4]
#b = [int(a)**2]
b = [x ** 2 for x in a]
c = [x ** 2 for x in a if x % 2 == 1]
print(b)
print(c)
'''
#--------------------------------------------函数
#--------------------------------------------函数也是对象
'''
def add(x,y = 1):
    ret = x + y
    return ret
'''
'''
def add(x,y,z):
    ret = x + y + z
    return ret
'''
'''
#----------------------python中没有函数重载，后定义的会覆盖前定义的函数
x = 1
y = 2
print(type(add(x,y)))
'''
'''
def get_point():
    x = 10
    y = 20
    return x,y
#解包
_,y = get_point()
x,y = get_point()
print(x)
print(y)

print(get_point())
print(type(get_point))
print(type(get_point()))
'''
#--------------------------------文件操作
'''
#f = open('f:/test.txt','r')
w = open('f:/test.txt','w')

#for line in f:
#    print(line,end='')

w.write("RC----HER")

#返回值为一个列表
#a = f.readlines() # 一次性读完
#print(a)

#f.close()
w.close()
#print(type(f))
'''
'''
f = open("f:/test.txt",'r')

word_dict = {}
for word in f:
    #strip()函数的功能：去掉字符串头和尾的空白字符（空格，制表符，换行符，翻页符...）
    word = word.strip()
    if word in word_dict:
        word_dict[word] += 1
    else:
        word_dict[word] = 1

f.close()
print(word_dict)

'''

#----------------------------模块(模块也是对象)
'''
#calc.py这个文件必须放在当前目录中，或者系统目录中
import calc

print(calc.add(1,2))
print(type(calc.add(1,2)))
'''
'''
x,y = 1,2
print(x)
print(y)
# -----------多元交换
y,x = x,y
print(x)
print(y)
'''
'''
def func():
    x = 1
    print("func:", locals())
    return x
func()

print("globa",locals())
'''
'''
import calc
#-------------------------查看帮助文档
##print(calc.add.__doc__)
#help(calc.add)
help(calc)
'''
#-----------------------------linux下添加
##！/usr/bin/python3
#print("hehe")
##这样就可以在Linux下按照普通程序的启动方式运行


#-----------------------可以取到id的都是对象 （python下任何类型的值都是一个对象）