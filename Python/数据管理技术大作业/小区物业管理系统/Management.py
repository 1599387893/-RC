# -*- coding: utf-8 -*-
import os
import io
'''
1，管理物业员工信息   2. 管理业主信息
3，费用管理           4. 车位管理
5，公告管理           6. 设备维修管理
'''


def Authentication(AORO,ID,pw):  
    '''
    Admin信息格式：ID,name,pw,age,phone
    Owner信息格式：ID,name,pw,age,IDnumber,houseNumber,Property-cost,ParkSet,Park-cost
    '''
    if AORO is 'Admin':
        # 验证管理员
        with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Admin.txt','r',encoding='utf-8') as f:
            for line in f:
                line=str(line).split(',')
                if ID==line[0] and pw==line[2]:
                    return True
            return False
    else:
        #验证业主
        with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt','r',encoding='utf-8') as f:
            for line in f:
                line=str(line).split(',')
                if ID==str(line[0]):
                    return True
            return False

def Employee_management():
    '''
    管理物业员工信息(增删查改)
    '''
    peopleNumber = 1
    print('物业员工信息如下：')
    with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Admin.txt','r',encoding='utf-8') as f:
        for line in f:
            line = str(line).split(',')
            print('ID: ', line[0],'Name: ',line[1],'Age: ',line[3],'Phone: ',line[4],end='')
            peopleNumber+=1
    n = int(input('1，增加  2，修改  3.删除  4.查看 \n 请选择：'))
    if n==1: # 增加
        info = str(peopleNumber)
        info = info + ',' + str(input('输入姓名：'))
        info = info + ',' + str(input('输入密码：'))
        info = info + ',' + str(input('输入年龄：'))
        info = info + ',' + str(input('输入手机号：'))
        with open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Admin.txt', mode='a+') as f:
            f.write(info)
            f.write('\n') # 换行
        print('插入成功！！！')

    elif n == 2: # 修改
        ID = int(input('请输入要处理的员工ID ：'))
        with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\back.txt','w',encoding='utf-8') as b:
            with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Admin.txt','r',encoding='utf-8') as f:
                for line in f:
                    line = str(line).split(',')
                    if ID == int(line[0]):
                        c = int(input('请选择需要修改的信息：1.密码 2.年龄 3.手机号'))
                        if c == 1:
                            line[2] = str(input('请输入需要修改的密码：'))
                        elif c== 2 :
                            line[3] = str(input('请输入需要修改的年龄：'))
                        else:
                            line[4] = str(input('请输入需要修改的手机号：'))
                    b.write(line[0]+','+line[1]+','+line[2]+','+line[3]+','+line[4])
            os.remove('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Admin.txt')
        os.rename('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\back.txt','E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Admin.txt')

    elif n == 3: # 删除
        ID = int(input('请输入要处理的员工ID ：'))
        with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\back.txt','w',encoding='utf-8') as b:
            with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Admin.txt','r',encoding='utf-8') as f:
                for line in f:
                    line = str(line).split(',')
                    if ID == int(line[0]):
                        pass
                    else:
                        b.write(line[0]+','+line[1]+','+line[2]+','+line[3]+','+line[4])
            os.remove('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Admin.txt')
        os.rename('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\back.txt','E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Admin.txt')
          
    else: # 查看
        with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Admin.txt','r',encoding='utf-8') as f:
            for line in f:
                line = str(line).split(',')
                print('ID: ', line[0],'Name: ',line[1],'Age: ',line[3],'Phone: ',line[4])

def Owner_management():
    '''
    管理业主信息(增删查改)
    Owner信息格式：ID,name,pw,age,phone,houseNumber,Property-cost,Park,Park-cost
    '''
    peopleNumber = 1
    print('业主信息如下：')
    with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt','r',encoding='utf-8') as f:
        for line in f:
            line = str(line).split(',')
            print('ID: ', line[0],'Name: ',line[1],'Age: ',line[3],'Phone: ',line[4],'HouseNumber: ',line[5],'Property-cost: ',line[6],'Park: ',line[7],'Park-cost: ',line[8],end='')
            peopleNumber+=1
    n = int(input('1，增加  2，修改  3.删除  4.查看 \n 请选择：'))
    if n==1: # 增加
        info = str(peopleNumber)
        info = info + ',' + str(input('输入业主姓名：'))
        info = info + ',' + str(input('输入业主密码：'))
        info = info + ',' + str(input('输入业主年龄：'))
        info = info + ',' + str(input('输入业主手机号：'))
        info = info + ',' + str(input('输入业主房间号：'))
        info = info + ',' + str(input('输入业主物业费：'))
        info = info + ',' + str(input('输入业主停车位：'))
        info = info + ',' + str(input('输入业主停车费：'))
        with open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt', mode='a+') as f:
            f.write(info)
            f.write('\n') # 换行
        print('录入成功！！！')

    elif n == 2: # 修改
        ID = int(input('请输入要处理的业主ID ：'))
        with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner-back.txt','w',encoding='utf-8') as b:
            with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt','r',encoding='utf-8') as f:
                for line in f:
                    line = str(line).split(',')
                    if ID == int(line[0]):
                        c = int(input('请选择需要修改的信息：1.密码 2.年龄 3.手机号 4.房间号 5.物业费 6.停车位 7.停车费 : '))
                        if c == 1:
                            line[2] = str(input('请输入需要修改的密码：'))
                        elif c== 2 :
                            line[3] = str(input('请输入需要修改的年龄：'))
                        elif c == 3:
                            line[4] = str(input('请输入需要修改的手机号：'))
                        elif c == 4:
                            line[4] = str(input('请输入需要修改的房间号：'))
                        elif c == 5:
                            line[5] = str(input('请输入需要修改的物业费：'))
                        elif c == 6:
                            line[6] = str(input('请输入需要修改的停车位：'))
                        elif c == 7:
                            line[7] = str(input('请输入需要修改的停车费：'))
                    b.write(line[0]+','+line[1]+','+line[2]+','+line[3]+','+line[4]+','+line[5]+','+line[6]+','+line[7]+','+line[8])
            os.remove('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt')
        os.rename('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner-back.txt','E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt')

    elif n == 3: # 删除
        ID = int(input('请输入要处理的员工ID ：'))
        with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner-back.txt','w',encoding='utf-8') as b:
            with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt','r',encoding='utf-8') as f:
                for line in f:
                    line = str(line).split(',')
                    if ID == int(line[0]):
                        pass
                    else:
                        b.write(line[0]+','+line[1]+','+line[2]+','+line[3]+','+line[4]+','+line[5]+','+line[6]+','+line[7]+','+line[8])
            os.remove('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt')
        os.rename('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner-back.txt','E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt')
    
    else: # 查看
        with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt','r',encoding='utf-8') as f:
            for line in f:
                line = str(line).split(',')
                print('ID: ', line[0],'Name: ',line[1],'Age: ',line[3],'Phone: ',line[4],'HouseNumber: ',line[5],'Property-cost: ',line[6],'Park: ',line[7],'Park-cost: ',line[8])


def QSort(list_sort,n):
    

def Cost_management():
    '''
    费用管理
    '''
    while True:
        n = int(input('请选择需要查看的费用类型： 1.物业费  2.停车费 0.退出   :'))
        list_sort = []
        if n==1 :
            print('未缴纳物业费业主信息：')
            with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt','r',encoding='utf-8') as f:
                for line in f:
                    temp = str(line).split(',')
                    if int(temp[6]) > 0 :
                        list_sort.append(line)
            if len(list_sort) == 0:
                print('暂无未缴物业费业主')
                continue
            list_sort = QSort(list_sort,6)
            for info in list_sort:
                info = str(info).split(',')
                print('ID: ', line[0],'Name: ',line[1],'Phone: ',line[4],'HouseNumber: ',line[5],'Property-cost: ',line[6])

        elif n==2 :
            print('未缴纳停车费费业主信息：')
            with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt','r',encoding='utf-8') as f:
                for line in f:
                    temp = str(line).split(',')
                    if int(temp[8] > 0):
                        list_sort.append(line)
            if len(list_sort) == 0:
                print('暂无未缴停车费业主')
                continue
            list_sort = QSort(list_sort,8)
            for info in list_sort:
                info = str(info).split(',')
                print('ID: ', line[0],'Name: ',line[1],'Phone: ',line[4],'HouseNumber: ',line[5],'Park-cost: ',line[8])
        else:
            return

def Park_management():
    '''
    停车位管理
    '''
    while True:
        print('业主停车位信息：')
        with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt','r',encoding='utf-8') as f:
            for line in f:
                line = str(line).split(',')
                if int(line[7]) > 0:
                    print('ID: ', line[0],'Name: ',line[1],'Phone: ',line[4],'HouseNumber: ',line[5],'ParkSet: ',line[7])
        n = int(input('请选择： 1.修改信息   2.退出'))
        if n==1 :
            ID = input('请输入需要修改的业主ID：')
            with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\back.txt','w',encoding='utf-8') as b:
                with io.open('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt','r',encoding='utf-8') as f:
                    for line in f:
                        line = str(line).split(',')
                        if ID == int(line[0]):
                            result = str(input('请输入车位修改信息：'))
                            line[7] = result
                        b.write(line[0]+','+line[1]+','+line[2]+','+line[3]+','+line[4]+','+line[5]+','+line[6]+','+line[7]+','+line[8])
                os.remove('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt')
            os.rename('E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\back.txt','E:\\提交代码\\-RC\\Python\\数据管理技术大作业\\小区物业管理系统\\Owner.txt')
            print('信息修改成功！！！')
        else:
            return 
        

def Announcement_management():
    '''
    公告管理
    '''
    info = str(input('请输入公告标题：'))
    info += '\n' + str(input('请输入公告内容：'))
    info += '\n' + str(input('请输入公告时间：'))
    with io.open('Announcement.txt','a',encoding='utf-8') as f:
        f.writelines(info)
    
