#-*- coding:utf-8 -*- 
#2020.6.5

import os
import time
from Management import Authentication
from Management import Employee_management
from Management import Owner_management
from Management import Cost_management
from Management import Announcement_management
from Management import Machine_management


def Admin():
    os.system(ur'cls')
    print(ur'欢迎进入管理员界面！'.center(50))
    #管理员身份验证
    for i in range (0,3):
        ID = str(input(ur'请输入管理员ID:'))
        pw = str(input(ur'请输入管理员密码:'))
        if Authentication('Admin',ID,pw) is False:
            if i < 2:
                print(ur'ID或密码错误!!! 请重试：')
                time.sleep(0.5)
                os.system('cls')
            else:
                print(ur'三次输入错误，退出程序!!!')
                return 
        else:
            break
    while True:
        print(ur'功能选择: 1，管理物业员工信息   2. 管理业主信息')
        print(ur'          3，费用管理           4. 车位管理')
        print(ur'          5，公告管理           6. 设备维修管理')
        print(ur'          7，退出')
        chs = input('请选择：')
        if chs is 1 :
            Employee_management()
        elif chs is 2:
            Owner_management()
        elif chs is 3:
            Cost_management()
        elif chs is 4:
            Park_management()
        elif chs is 5:
            Announcement_management()
        elif chs is 6:
            Machine_management()
        else:
            break

def Owner():
    os.system('cls')
    print(ur'欢迎进入业主界面！'.center(50))
    #业主身份验证
    for i in range (0,3):
        ID = str(input(ur'请输入业主ID:'))
        pw = str(input(ur'请输入业主密码:'))
        if Authentication('Admin',ID,pw) is False:
            if i < 2:
                print(ur'ID或密码错误!!! 请重试：')
                time.sleep(0.5)
                os.system('cls')
            else:
                print(ur'三次输入错误，退出程序!!!')
                return 
        else:
            break
    while True:
        print(ur'功能选择: 1，管理物业员工信息   2. 管理业主信息')
        print(ur'          7，退出')
        chs = input('请选择：')
        if chs is 1 :
            Employee_management()
        elif chs is 2:
            Owner_management()
        elif chs is 3:
            Cost_management()
        elif chs is 4:
            Park_management()
        elif chs is 5:
            Announcement_management()
        elif chs is 6:
            Machine_management()
        else:
            break

        
def main():
    '''
    选择身份
    '''
    while True:
        print(ur'身份选择：1，管理员     2. 业主'.center(50))
        print(ur'0: 退出'.center(55))
        id = input('请选择：')
        if id is 1 :
            Admin()
        elif id is 2 :
            Owner()
        else:
            print(ur'See You Next time!!!')
            time.sleep(1)
            break

if __name__ == '__main__':
    main()
