# def isOdd(num):
#     """
#     判定是不是奇数
#     :param num: 判定的数字
#     :return:  返回true或者是false
#     """
#     if num % 2 == 1:
#         return True
#     else:
#         return False
#
#
# if isOdd(10) == True:
#     print("奇数")
# else:
#     print("偶数")


# def test():
#     return 1, 2,3
# a, b, c = test()
#
# print(a)
# print(b)
# print(c)


# def test():
#     return 1, 2
# _, b = test()
#
# print(b)

# 变量的的作用域
# def getPoint():
#     x = 10
#     y = 20
#     return x + y
#
# x = 1
# print(x)

# if 1 == 1:
#     gener = 'a'
# else:
#     gener = 'b'
# print(gener)

x = 10
def test():
    x = 1
    print(x)
test()
print(x)
