#---------------序列：包含若干个元素，元素顺序有意义-----------------------------
'''
a = [1,2,3,4]
b = [5,6,7]
print(10 in a)
print(10 not in a)
print(a + b)        #并没有改变a的内容，而是创建了新的对象
print(a)
a.extend(b) # 这个效率比连接运算符(+)高，改变了a的内容
'''
'''
a = ['aaa','bbb','ccc']
result = ';'.join(a)
print(result)
'''
#-------------切片
'''
a = [0,1,2,3,4]
b = a[1:3]
print(b)
print(a[0:]) 
print(a[::3]) #这个参数为步长，用来确定每次向后移动几个元素
print(a[::-1]) #从后向前遍历
'''
#--------------内建函数
#  min(),max(),len(),sorted(),sum()
#enumerate():同时枚举出序列的下标和值
'''
def find(input_list,x):
    for i,value in enumerate(input_list):
        if value == x:
            return i
    else:
        return None
'''
#zip():"拉链"将多个序列进行组合分组，长度由最短的序列决定（可以构建字典）

