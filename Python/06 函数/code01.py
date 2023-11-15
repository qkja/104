# theSum = 0
# for i in range(1, 101):
#     theSum += i
# print(theSum)

# 求i到j的和[i, j]

# 1. 定义一个求和函数
def calcSum(begin, end):
    # 这是函数体
    theSum = 0
    for i in range(begin, end + 1):
        theSum += i
    print(theSum)

# 调用函数
calcSum(1, 100)