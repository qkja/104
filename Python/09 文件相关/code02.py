"""
文件操作
打开/关闭
读文件/写文件
"""


# 1. 打开文件 open 打开一个文件
# r: 打开方式
# w: 写方式打开
# a: 追加方式
# 返回值: 是一个文件对象
# filename = 'E:/104/Python/09 文件相关/code01.py'
# f = open(filename, 'r')
# print(f.name)
# print(f)
# print(type(f))

# 在打开文件存在时,是否是存在的,会影响我们的操作



# 关闭文件: 文件在打开完之后,一定要关闭的, 这是为了释放资源

# f.close()

# while True:
#     filename = 'E:/104/Python/09 文件相关/code01.py'
#     f = open(filename, 'r')

# f.close()
# filst = []
# count = 0
# while True:
#     filename = 'E:/104/Python/09 文件相关/code01.py'
#     f = open(filename, 'r')
#     filst.append(f)
#     count += 1
#     print(f"count: {count}")


# 写文件

# filename = 'E:/104/Python/09 文件相关/test.txt'
# f = open(filename, 'a')
# f.write("3333")
# f.close()


# 读文件
#
# filename = 'E:/104/Python/09 文件相关/test.txt'
# f = open(filename, 'r')
# 读前两个字符
# 'gbk' codec can't decode byte 0xa2 in  这是字符编码的问题
# result = f.read(2)
# print(result)





# filename = 'E:/104/Python/09 文件相关/test.txt'
# f = open(filename, 'r', encoding='utf8')
# result = f.read(2000)
# print(result)
# f.close()
# 按照行读取
# filename = 'E:/104/Python/09 文件相关/test.txt'
# f = open(filename, 'r', encoding='utf8')
# line = ''
# for i in f:
#     line += i
#
# print(f"lien = {line}")
# f.close()

# filename = 'E:/104/Python/09 文件相关/test.txt'
# f = open(filename, 'r', encoding='utf8')
# for lien in f:
#     print(f"lien = {lien}", end='')
# f.close()

# 读取所有的内容
filename = 'E:/104/Python/09 文件相关/test.txt'
f = open(filename, 'r', encoding='utf8')
print(f.readlines())
f.close()