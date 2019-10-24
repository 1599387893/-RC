#**********************************************************************字符串**********************************************************************
# int/double/float/boolean/str.. 都是不可变对象   好处是“线程安全”
# list/dict 是可变对象
'''
a = 10
print(id(a))
a += 1
print(id(a))
'''

# 格式化操作
'''
a = 10
s = f'a={a}'
print(s)
'''
'''
a = r"Hello \n RC" #原始字符串
print(a)
'''

# 字符串函数
'''
a = "hello RC r-c"
print('[' + a.center(50) + ']') # 字符串居中
print('[' + a.ljust(50) + ']') # 字符串左对齐
print('[' + a.rjust(50) + ']') # 字符串右对齐

#print(a.split(' '))    # 切分
b = a.split(' ')
print(';'.join(b))  # 合并
'''

#**********************************************************************列表**************************************
#列表的常见操作
'''
a = [1,2,3,4]
a.append(5)
a.append([6,7,8]) #整体插入列表
a.extend([6,7,8]) #逐个插入列表中
print(a)

del(a[0]) #按位置删除元素
a.remove(2) #按值删除元素
print(a)

print(3 in a) # 查元素

a1 = [1,2,3]
b1 = [3,2,1]
print(a1 == b1)
'''
'''
a = [2,1,3,5,0]
print(sorted(a))
print(a)
print(a.sort())
print(a)
'''

#利用列表来实现堆栈
'''
a = [1,2,3]
a.append(4)     #压栈
print(a)    
a.pop()         #出栈
print(a)
'''
#利用列表来实现队列
'''
a = [1,2,3]
a.append(4)     #入队列
print(a)
a.pop(0)        #出队列
print(a)
'''

#--python常见都是浅拷贝，使用deepcopy进行深拷贝，但是对于不可变对象，即使使用deepcopy也是进行浅拷贝
'''
import copy
a = [1,2,3]
b = copy.deepcopy(a)
a[1] = 100
print(b)
'''


