'''
import os #导入模块
print(id(os),type(os))
print(os.__doc__) # 查看文档
help(os) # 查看文档
'''
'''
import sys

for path in sys.path:
    print(path)
'''
# ----添加模块路径
# sys.path.append(r'..................')

# --------------模块也是一个对象，也有生命周期和使用范围
#---------------import是导入整个模块
#---------------from import是导入模块中指定的名字的部分
'''
from os.path import exists
exists("f:/test.txt")
'''

#---------------多次import同一个模块，只会导入一次
#---------------导入一次模块，相当于执行一次模块

#模块的内置变量
#print(globals())

#------------------------------------------------------包---------------------------------
# 所谓的包就是一个特殊的目录
# 包里面必须包含一个 __init__.py 文件
# 这个文件间负责对包进行初始化
'''
import sys
print(sys.argv)
print(len(sys.argv))
print(sys.executable)
print(sys.platform)
'''
import os
#print(os.getenv("PATH"))
print(os.uname())