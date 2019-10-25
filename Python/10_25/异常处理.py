#----------------------------------------------捕获异常------------------------
'''
try:           #捕获异常
    a = [1,2,3]
    # prin(a[1])
    # print(a[100])
    print(a)
except IndexError as e:   #处理异常
    print(e)
except NameError as e:
    print(e)
except Exception as e:    #处理所有的异常
    print("Process Except!")
else:           #没有异常时的处理方式
    print("Process Ok!")
'''

#---------------with 本质上就是try except finally 的简化写法
'''
try:
    f = open("f:/testaaa.txt",'r')
    f.write("aaaa")
except Exception as e:
    print("出现异常！")
else:
    print("没有出现异常！")
finally:
    print("无论是否出现异常，还是其他情况，这个语句都会被执行")
    f.close()
'''

#---------------------------------------------------抛出异常(raise)-----------------------------------

def div(x,y):
    if(y == 0):
        raise Exception("divide zero except!")
    return x / y
try:
    div(10,0)
except Exception as e:
    print(e)
