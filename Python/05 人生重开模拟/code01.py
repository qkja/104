"""
人生重开模拟器
"""

import random
import sys
import time

# 1. 欢迎界面
print('+------------------------------------+')
print('|                                    |')
print('|        花有重开日,人无再少年           |')
print('|       欢迎来到, 人生重开模拟器          |')
print('|                                    |')
print('+------------------------------------+')

# 2 初始属性
print("请设置初始属性,可用为 20")
while True:
    face = int(input("请输入颜值(1-10): "))
    strong = int(input("请输入体制(1-10): "))
    iq = int(input("请输入智力(1-10): "))
    home = int(input("请输入家境(1-10): "))

    if face < 1 or face > 10:
        print("颜值非法,")
        continue
    if strong < 1 or strong > 10:
        print("体制非法")
        continue
    if iq < 1 or iq > 10:
        print("智力非法")
        continue
    if home < 1 or home > 10:
        print("家境非法")
        continue
    if (face + strong + iq + home) > 20:
        print("总和非法")
        continue
    print("输入属性完毕")
    print(f"颜值 {face}, 体制 {strong}, 智力 {iq}, 家境 {home}")

    break

# 到这里属性已经可以了
# 生成[1, 6]的随机数
point = random.randint(1, 6)

if point % 2 == 1:
    gender = 'boy'
    print("你是个男孩")
else:
    gender = 'girl'
    print("你是个女孩")

point = random.randint(1, 3)
if home == 10:
    print("出生帝都")
    home += 1
    iq += 1
    face += 1
elif 7 <= home <= 9:
    if point == 1:
        print("出生在三线城市, 父母是医生")
        strong += 1
    elif point == 2:
        print("出生在镇上, 父母是教师")
        iq += 1
    else:
        print("出生在镇上, 父母是大学个体化")
        home += 1
elif 4 <= home <= 6:
    if point == 1:
        print("出生在大城市, 父母是公务员")
        face += 2
    elif point == 2:
        print("出生在大城市, 父母是高管")
        home += 2
    else:
        print("出生在大城市, 父母是大学教授")
        iq += 2
else:
    if point == 1:
        print("出生在农村, 父母是农名")
        strong += 1
        face -= 2
    elif point == 2:
        print("出生在穷乡僻壤, 父母是无业游民")
        home -= 2
    else:
        print("出生在镇上, 父母感情不和")
        strong -= 1
print(f"颜值 {face}, 体制 {strong}, 智力 {iq}, 家境 {home}")

# 幼年阶段
for age in range(1, 11):
    info = f'你今年 {age} 岁,'
    point = random.randint(1, 3)

    # 性别触发的时间
    if gender == 'girl' and home <= 3 and point == 1:
        info += "你的家里人重男轻女非常严重,被遗弃了"
        print(info)
        print("游戏结束")
        sys.exit(0)
    elif strong < 6 and point < 3:
        info += "你生了一场病,"
        if home >= 5:
            info += "在父母的照料下,好了,"
            home -= 1
        else:
            info += "在父母的没有照料,"
            strong -= 1
    elif face <= 4 and age >= 7:
        info += "你长的太丑了,别发的小朋友不喜欢,"
        if iq > 5:
            info += "用学习填充,"
            iq += 1
        else:
            if gender == 'boy':
                info += "经常大家,"
                strong += 1
                iq -= 1
            else:
                info += "你经常被别的小朋友欺负,"
                strong -= 1
    elif iq < 5:
        info += "你看起来傻傻的"
        if home >= 8 and age >= 6:
            info += "送到更好的学校学习,"
            iq += 1
        elif 4 <= home >= 7:
            if gender == 'boy':
                info += "多运动,"
                strong += 1
            else:
                info += "多打扮自己,"
                face += 1
        else:
            info += "经常吵架,"
            iq -= 1
    else:
        info += "无事发生,键盘成长,"
        if point == 1:
            info += "更结实了"
        elif point == 2:
            info += "好看了"
        else:
            pass

    print(info)
    print(f"颜值 {face}, 体制 {strong}, 智力 {iq}, 家境 {home}")
    print('--------------------------------------------------')
    time.sleep(1)