#-------------------------------菜单项如下: 1. 求五个数的和; 2. 求五个数的平均值; ... (X). 退出------------------
#-------------------------------由用户输入选择, 程序执行相应的功能----------------------
import os
import time

#接收五个数字-1
def fiveN():
    print("Please Enter Five Number:")
    num = 0
    i = 0
    while i<5:
        num+=int(input())
        i+=1
    return num
#接收五个数字-2
def fiven():
    #raw_input()是定义在python2中的python3不兼容
    s = input("Please Enter Five number:")
    l = []
    ls = s.split(" ")
    i = 0
    print(len(ls))
    while i <= len(ls)+2:
        print(l)
        print(i)
        l.append(int(ls.pop()))
        i+=1
    i = 0
    num = 0
    while i <= len(l)+1:
        num+=l[i]
        i+=1
    return num

while True:
    print("*****************************************************")
    print("***************    1. 求五个数的和     ***************")
    print("***************    2. 求五个数的平均值 ***************")
    print("***************    x. 退出             **************")
    print("*****************************************************")
    n = input("请选择：")
    if n == '1':
        num = fiven()
        print("五个数的和为："+str(num))
        time.sleep(1)        
        os.system("cls")
    elif n == '2':
        num = fiven()
        print("这五个数的平均值为："+str(num/5))
        time.sleep(0.5)        
        os.system("cls")
    elif n=='x':
        print("Bye Bye!")
        time.sleep(1)                
        os.system("cls")
        break
    else:
        n = input("Sorry Enter Error,Enter Again:")
        time.sleep(1)        
        os.system("cls")
        continue
    