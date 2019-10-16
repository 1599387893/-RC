'''
#1
fruits = ["apple","orange","xigua"]
for temp in fruits:
    print("I like ",temp)
'''

'''
#2
i = 0
for i in range (100):
    print(i*i)
'''
'''
#3

for num in range (100,1000):
    bai = num//100
    shi = num//10%10
    ge = num % 10
    if(bai**3+shi**3+ge**3 == num):
        print(num,end=' ')
'''