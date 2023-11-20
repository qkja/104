"""
可哈希类型
"""
# 什么类型可以做为key,只有可以计算哈希值的才可以
# 为了方便判断,python专门提供了一个函数,可以计算哈希值

# 这些都可以
# print(hash(0))
# print(hash(3.14))
# print(hash(-1))
# print(hash("aaa"))
# print(hash(True))
# print(hash((1,2,3)))

# 下面的就不可以
# print(hash([1,2]))
# print(hash({}))

# 一般而言,不可变的对象就是可哈希的
# 可变的对象,一般是不可哈希的
