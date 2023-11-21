"""
学生管理系统
"""
import sys

# 这里管理所有的信息
students = []


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
            sys.exit(0)
        else:
            print('输入不合法')


main()
