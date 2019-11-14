# 1.不要二
'''
import sys
x,y = list(map(int,sys.stdin.readline().split()))
if x%4==0 or y%4==0 : print(int(x*y//2))
elif x%2==0 and y%2==0 : print(((x*y)//2+1)+1)
else: print(x*y//2+1) 
'''

# 2.把字符串转成整数

# -*- coding:utf-8 -*-
class Solution:
    def StrToInt(self, s):
        # write code here
        if(len(s)==0):
            return 0
        if(len(s)==1):
            if(s[0]<'0' or s[0]>'9'):
                return 0
        i = 1
        l = len(s)
        while i<l:
            if(s[i]<'0' or s[i] >'9'):
                return 0
            i+=1
        return int(s)

# 方法二
# -*- coding:utf-8 -*-
class Solution:
    def StrToInt(self, s):
        # write code here
        try:
            return int(s)
        except:
            return 0