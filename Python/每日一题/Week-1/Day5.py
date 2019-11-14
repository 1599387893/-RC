# 1.判断回文
str1 = str(input())
str2 = str(input())

count = 0
for i in range(len(str1)+1):
    temp1 = str1[0:i]+ str2 + str1[i:len(str1)]
    temp2 = temp1[::-1]
    if temp1 == temp2 :
        count+=1

print(count)


# 2.连续最大和

def func(l):
    up,low=0,0
    flag=l[0]
    for x in l:
        up+=1
        if sum(l[low:up])>flag:
            flag=sum(l[low:up])
        if sum(l[low:up])<0:
            low=up
    return flag
    
n=int(input())
arr=list(map(int,input().split(' ')))
print(func(arr))
