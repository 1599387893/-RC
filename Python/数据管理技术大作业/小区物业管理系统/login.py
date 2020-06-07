#-*- coding:utf-8 -*- 
#2020.6.5

import os
import time
from Management import Authentication
from Management import Employee_management
from Management import Owner_management
from Management import Cost_management
from Management import Announcement_management
from Management import Park_management
from Owner_Business import Owner_Pay
from Owner_Business import CheckInfo
from Owner_Business import Check_Announcement_management



def Admin():
    os.system("cls")
    print('欢迎进入管理员界面！'.center(50))
    #管理员身份验证
    for i in range (0,3):
        ID = str(input('请输入管理员ID:'))
        pw = str(input('请输入管理员密码:'))
        if Authentication('Admin',ID,pw) is False:
            if i < 2:
                print('ID或密码错误!!! 请重试：')
                time.sleep(0.5)
                os.system('cls')
            else:
                print('三次输入错误，退出程序!!!')
                return 
        else:
            break
    while True:
        print('功能选择: 1，管理物业员工信息   2. 管理业主信息')
        print('          3，各种费用查看           4. 车位管理')
        print('          5，公告管理           6. 退出')
        chs = int(input('请选择：'))
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
        else:
            break

def Owner():
    '''
    缴纳物业费
    缴纳停车费
    查看信息
    查看公告
    '''
    os.system('cls')
    print('欢迎进入业主界面！'.center(50))
    ID = ''
    #业主身份验证
    for i in range (0,3):
        ID = str(input('请输入业主ID:'))
        if Authentication('Owner',ID,'') is False:
            if i < 2:
                print('查无此人!!! 请重试：')
                time.sleep(0.5)
                os.system('cls')
            else:
                print('三次输入错误，退出程序!!!')
                return 
        else:
            break
    while True:
        time.sleep(0.5)
        os.system('cls')
        print('功能选择: 1.缴纳费用     2.查看个人信息')
        print('         3.查看公告     4.退出')
        chs = int(input('请选择：'))
        if chs is 1 :
            Owner_Pay(ID)            
        elif chs is 2:
            CheckInfo(ID)
        elif chs is 3:
            Check_Announcement_management()
        else:
            break
     
def main():
    '''
    选择身份
    '''
    while True:
        os.system('cls')
        print('身份选择：1，管理员     2. 业主'.center(50))
        print('0: 退出'.center(55))
        id = int(input('请选择：'))
        if id is 1 :
            Admin()
        elif id is 2 :
            Owner()
        else:
            print('See You Next time!!!')
            time.sleep(1)
            os.system('cls')
            break

if __name__ == '__main__':
    main()
