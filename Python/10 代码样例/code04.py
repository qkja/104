"""
文件查找工具
"""
import os
# 输入要查找的路径
# 输入要搜索的文件名(或者是一部分)

# inputPath = input("请输入要搜索的路径: ")
# pattern = input("请输入文件名: ")
# E:\104\Python\10 代码样例
# for dirpath, dirnames, filenames in os.walk(inputPath):
#     print(f"dirpath: {dirpath}")
#     for name in dirnames:
#         print(f"dirnames: {name}")
#     for name in filenames:
#         print(f"filenames: {name}")


inputPath = input("请输入要搜索的路径: ")
pattern = input("请输入文件名: ")
for dirpath, dirnames, filenames in os.walk(inputPath):
    for name in filenames:
        if pattern in name:
            print(f"{dirpath}/{name}")





