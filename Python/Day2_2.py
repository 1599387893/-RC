#Demo1
'''
list1 = list(range(100))
print(list1)
str1 = str(list1)
print(str1)
'''

#Demo2
'''
list2 = [55,33,99,112,323,412,7,9,2,1,34]
list2.sort(reverse=False)
list3 = list(reversed(list2))
print(list2)
print(list3)

for i,v in enumerate(list2):
    print("下标为",i,end="\t")
    print("值是",v)
'''

#Demo3
'''
import random

#ist1 = [i*3 for i in range(20)]
#print(list1)

jiage = [10000,20000,30000,40000,50000,60000]
newjiage = [itme * 0.1 for itme in jiage if itme > 30000]
print(newjiage)
'''

#Demo4
'''
untitle = ('python',28,('人生苦短，我用python',22),['爬虫', 123, '云计算', 'Web开发'])
print(untitle)

team = '马刺','火箭','勇士','湖人'
print(team)

print(type(untitle))
print(type(team))

tup1 = ("人生苦短",)
print(tup1)
print(type(tup1))
'''

#Demo5
'''
tup1 = (1,2,3,4,5,6)
tup2 = ("aaa",123,"bbb")
tup3 = tup1+tup2
print(tup3)
'''

#Demo6
'''
str1 = "我爱Python"

print(len(str1))
print(len(str1.encode()))
print(len(str1.encode("GBK")))
print(str1[::-1])
'''

#Demo7
'''
str1 = '人| 生 苦 短 我 用 >>> Python'

print(str1.split("|"))
print(str1.split(">"))
'''

#Demo8
'''
str1 = '@python@扎克伯格@雷军'
print(str1.count("@",3,12))
'''

#Demo9
'''
str1 = '@python @扎克伯格 @雷军'
print(str1.find("#",2,12))
#print(str1.index("#",2,12))
#找不到会抛异常
'''

#Demo10

str1 = 'www.qq.com'

print(str1.startswith("qqq"))
print(str1.endswith("com"))










