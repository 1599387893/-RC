# -*- coding: utf-8 -*-


import io
import os
import time

def Owner_Pay(ID):
    '''
    缴纳费用
    '''
    n = int(input('请输入缴费类型： 1.物业费   2.停车费: '))
    if n==1 :
        with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner-back.txt','w',encoding='utf-8') as b:
            with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt','r',encoding='utf-8') as f:
                for line in f:
                    line = str(line).split(',')
                    money = str(input('请输入缴费金额：'))
                    if int(money) <= 0:
                        print('缴纳金额错误！！！退出系统')
                        return
                    line[6] = str(int(line[6])-int(money))
                    b.write(line[0]+','+line[1]+','+line[2]+','+line[3]+','+line[4]+','+line[5]+','+line[6]+','+line[7]+','+line[8])
            os.remove('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt')
        os.rename('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner-back.txt','E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt')
        print('缴费成功！')
    elif n==2 :
        with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner-back.txt','w',encoding='utf-8') as b:
            with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt','r',encoding='utf-8') as f:
                for line in f:
                    line = str(line).split(',')
                    money = str(input('请输入缴费金额：'))
                    if int(money) <= 0:
                        print('缴纳金额错误！！！退出系统')
                        return
                    line[8] = str(int(line[8])-int(money))
                    b.write(line[0]+','+line[1]+','+line[2]+','+line[3]+','+line[4]+','+line[5]+','+line[6]+','+line[7]+','+line[8])
            os.remove('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt')
        os.rename('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner-back.txt','E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt')
        print('缴费成功！')
    else:
        return 


def CheckInfo(ID):
    '''
    查看个人信息
    '''
    with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt','r',encoding='utf-8') as f:
        for line in f:
            line = str(line).split(',')
            if line[0]==ID:
                print(line[1],'业主您好！\n\n您的信息如下：')
                print('ID: ', line[0],'姓名: ',line[1],'年龄: ',line[3],'手机号: ',line[4],'门牌号: ',line[5],'物业费(欠): ',line[6],'停车车位: ',line[7],'停车费: ',line[8])
                time.sleep(1)

def Check_Announcement_management():
    '''
    查看公告
    '''
    with io.open('Announcement.txt','r',encoding='utf-8') as f:
        print('公告'.center(50))
        for line in f:
            print(line)
    time.sleep(5)
    