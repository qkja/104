"""
函数形参的默认值
"""

# def add(x, y):
#     return x + y
#
#
# print(add(10, 20))
# def add(x = 10, y = 2):
#     return x + y
#
#
# print(add())

# def add(x, y = 2):
#     return x + y
# print(add(1))

# 这个和C++是一样的,我们的参数的缺省值
# 规则也是一样的

# def add(x, y, debug = False):
#     if debug:
#         print(f"x = {x}, y = {y}")
#     return x + y
#
# print(add(1, 2))


# 函数的关键字参数
# 传入参数是按照位置开始传入的,我们也是按照位置得到的
# add(x, y)
# add(10, 20)
# 这里默认是x = 10, y = 20
# 这种参数的风格是 位置参数,是很多编程语言中最普遍的方式
# python提供了一个关键字传入参数

# def test(x, y):
#     print(f"x = {x}")
#     print(f"x = {y}")
#
# test(10, 20)

# def test(x, y):
#     print(f"x = {x}")
#     print(f"x = {y}")
#
# test(x = 10, y = 20)

# def test(x, y):
#     print(f"x = {x}")
#     print(f"x = {y}")
#
# test(y = 10, x = 20)

# 这个最大的意义是明显地告诉程序员我们的参数要传给谁
# 另外可以无视我们形参和实参的顺序


# 注意,位置参数和关键字参数可以混着用,要求是位置参数在前,关键字参数在后面
# 这个方式还是挺常见的,一般关键字参数是搭配默认参数使用的


# 这里先不详细的展开