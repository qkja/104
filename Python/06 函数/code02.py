# 定义一个函数
# def test():
#     print("hello")
#     print("hello")
#     print("hello")
#
#
# # 调用函数
# test()
# test()


def calcSum(begin, end):
    theSum = 0
    for i in range(begin, end + 1):
        theSum += i
    return theSum

print(calcSum(1, 100))