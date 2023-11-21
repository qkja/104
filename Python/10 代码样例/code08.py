"""
学生管理系统
"""
import os
import sys

# 这里管理所有的信息
students = []
def save():
    # 存档
    with open('record.txt', 'w', encoding='utf8') as f:
        for s in students:
            studentInfo = s['studentId'] + '\t' + s['studentName'] + '\t' + s['gender'] + '\t' + s['className'] + '\n'
            f.write(studentInfo)
    print(f'[存档成功], 共{len(students)}条数据')

def load():
    # 读档
    if not os.path.exists('record.txt'):
        return
    global students
    students = []
    with open('record.txt', 'r', encoding='utf8') as f:
        for student in f:
            # 针对这一行数据进行切分, 需要注意,我们的末尾的 \n
            student = student.strip() # strip 去掉首行和末尾的空白字符
            tokens = student.split('\t')
            if len(tokens) != 4:
                print(f"格式存在问题 student : {student}")
                continue
            studentInfo = {
                'studentId': tokens[0],
                'studentName': tokens[1],
                'gender': tokens[2],
                'className': tokens[3]
            }
            # global students
            students.append(studentInfo)
    print(f'[读档成功], 共{len(students)}条数据')


def menu():
    print("1. 新增学生")
    print("2. 显示学生")
    print("3. 查找学生")
    print("4. 删除学生")
    print("0. 退出学生")
    choice = input('请输入选项: ')
    return choice


def insert():
    # 新增函数
    print('[新增函数开始]')
    studentId = input('请输入学号: ')
    studentName = input('请输入姓名: ')
    gender = input('请输入性别: ')
    if gender not in ('男', '女'):
        print('性别不符合要求,新增失败')
        return
    className = input('请输入班级: ')

    # 使用一个字典给组合起来
    student = {
        'studentId': studentId,
        'studentName': studentName,
        'gender': gender,
        'className': className
    }
    global students
    students.append(student)

    print('[新增函数结束]')


def show():
    print('[显示函数开始]')
    for s in students:
        print(f"[{s['studentId']}]\t[{s['studentName']}]\t[{s['gender']}]\t[{s['className']}]\t")

    print(f'[显示函数结束], 共{len(students)}条数据')


def find():
    print('[查找函数开始]')
    name = input("请输入要查找的姓名: ")
    count = 0
    for s in students:
        if name == s['studentName']:
            print(f"[{s['studentId']}]\t[{s['studentName']}]\t[{s['gender']}]\t[{s['className']}]\t")
            count += 1
    print(f'[显示函数结束], 共{count}条数据')


def delete():
    print('[删除函数开始]')
    id = input("请输入要删除的学号: ")
    for s in students:
        if id == s['studentId']:
            print(f"删除 {s['studentName']} 的信息")
            students.remove(s)


def main():
    """
    入口函数
    :return:
    """
    print('--------------------------')
    print('         欢迎来到系统        ')
    print('--------------------------')
    load()
    while True:
        choice = menu()
        if choice == '1':
            insert()
        elif choice == '2':
            show()
        elif choice == '3':
            find()
        elif choice == '4':
            delete()
        elif choice == '0':
            print('goodbye')
            save()
            sys.exit(0)
        else:
            print('输入不合法')


main()
