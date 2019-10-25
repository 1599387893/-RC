#---------------------------------------------------------基本操作--------------------------------
#句柄
'''
f = open('f:/test.txt','r')
print(type(f))
f.close() #不及时关闭，可能会造成资源泄漏
'''

#with 语句保证 close 被调用到
#with 语句中的 as 得到的对象，称为“上下文管理器”    可以用于打开文件操作，上锁解锁操作
#with 语句类似于“智能指针”
'''
with open('f:/test.txt','r') as f:
    x = 0
    if(x == 0):
        x = 1 
'''

#文件存储的编码方式（常见为gbk）和代码读取文件的编码方式（常见为Unicode）是不同的，结果就是出现乱码
# 解决方法:就是统一编码方式
'''
with open("f:/test.txt",'r',encoding='utf8') as f:
    for line in f:
        print(line,end=" ")
'''

#读文件----read,readline,readlines（一次读取整个文件）
#          readline和readlines会保留换行符
'''
with open('f:/test.txt','r',encoding='utf8') as f:
    for line in f.readlines():
        print(line.strip())
'''
#写文件----write,writelines

#-------------------------------------------------文件路径操作------------------------------------
'''
import os.path as p

my_path = 'f:/a/b/c/test.txt'
#print(os.path.basename(my_path))
#print(os.path.dirname(my_path))
#print(os.path.split(my_path))
#print(os.path.splitext(my_path)) #分离文件和他的扩展名

print(p.exists(my_path))
print(p.isdir(my_path))
print(p.isfile(my_path))
'''

#------------------------------------------------------文件系统操作-------------------------
import os.path as op
import os 

my_ = 'f:/testaaa'
#print(os.listdir(my_))
#print(os.rename(my_,'f:/testaaa'))

#打印出该目录下的所有文件以及目录
'''
for item in os.walk(my_):
    print(item)
'''
#打印出该目录下所有文件的全路径
for base_path,_,files in os.walk(my_):
    for f in files:
        print(op.join(base_path,f))
