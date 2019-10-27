'''
s = input("Please Enter a string: ")
print(s)
'''
'''
x = input("Please Enter a number:")
y = input("Please Enter a number:")
print("Result = ",int(x)+int(y))
'''
'''
i = 0
while i<11:
    print(i)
    i+=1
'''
'''
for i in range(0,11):
    print(i)
a=[1,2,3,4,5,6,7,9,10]
for i in a:
    print(i)
'''
'''
s = input("Please Enter a string:")
for i in s:
    print(i+" ")
#l = len(s)
#while int(i)<l:
#    print(s[i]+" ")
'''
'''
n = int(input("Please Enter a number:"))
if(n > 0):
    print("这是正数！")
elif(n == 0):
    print("0!")
else:
    print("这是负数！")
'''
'''
lst = []
str = raw_input("Plase Enter:")
lstl = str.split(" ")
i = 0
while i <= len(lstl)+1:
    lst.append(int(lstl.pop()))
    i+=1
'''
'''
n=input('')
 
b=input().split()
 
sum=0
 
for i in b:
 
    sum=sum+eval(i)
 
print(sum/int(n))
'''


print("1.取五个数的和。")
print("2.取五个数的平均值。")
print("x.退出。")
while True:
    n = input("Please Choose:")
    if n == '1':
        i = 0
        num = 0
        while i < 5:
            num +=int(input("Enter number:"))
            i+=1
        print("这五个数的和为："+str(num))
    elif n == '2':
        i = 0
        num = 0
        while i<5:
            num+=int(input("Plase Enter number:"))
            i+=1
        print("这五个数的平均值为："+str(num/5))
    else :
        print('bye bye!')
        break