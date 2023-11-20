"""
字典的遍历
"""

# 我们很少使用字典的遍历,它被设计的初衷是增删改查
# 如果非要遍历,那么效率要差一些,这里和哈希表的结构有关
# a = {
#     "id":1,
#     "name":"张三",
#     1:1
# }

# 下面说一下我们的遍历操作是如何编写的
# for key in a:
#     print(key, " : ", a[key])
# 注意,在python中我们做了处理,可以保证我们遍历的顺序和插入的循序是一至的
a = {
    "id":1,
    "name":"张三",
    1:1
}

# # 难道所有的key
# print(a.keys())
# # 获取所有的value
# print(a.values())
# # 获取所有的键值对
# print(a.items())
# # dict_keys(['id', 'name', 1])
# # dict_values([1, '张三', 1])
# # dict_items([('id', 1), ('name', '张三'), (1, 1)])
