"""
上下文管理器
"""
# 解决容易文件忘记关闭的问题,这个非常的复杂
# def func():
#     当我们with的代码快执行完毕,字节close
#     with open('E:/104/Python/09 文件相关/test.txt', 'r',encoding='utf8') as f:
