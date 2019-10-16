#Day1

'''
#1
name = input("输入姓名：")
QQ = input("输入QQ：")
phonenumber = input("输入手机号：")
Adderss = input("输入地址：")

print("姓名：")
print(name)
print(QQ)
print(phonenumber)
print(Adderss)
'''

'''
# 2
name = input("用户名：")
password = input("密码：")
if(name == "RC"):
    if(password == "123"):
        print("登陆成功！")
else:
    print("密码或用户名错误！！！")
'''

'''
#3
for i in range (1,10):
    for j in range (1,10):
        if j>i:
            print(end = '')
        else:
            print(i ,"*", 1, "=", i*1,end=' ')
        if(j == 9):
            print('')
'''


'''
#4

sushu = []
for i in range (100,200):
    for j in range(2,i):
        if i%j == 0:
            break;
    if i == j+1:
        #print(i,end = ' ')
        sushu.append(i)
print(sushu)
'''



















