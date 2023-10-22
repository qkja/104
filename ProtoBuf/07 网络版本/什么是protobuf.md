## 什么是protobuf

- 和json,xml一样,都是我们序列化和放序列化的一个工具

## 其特点是

- 最大的特点是基于编译生成的头文件和源文件来使用的
- 其速度要比json快,内存占据的也少,他的存储是二进制的
- 适应多种语言,适合多种环境
- 扩展性、兼容性好

## 常见的字段

- int,sint....
- map
- 枚举
- oneof
- any

## 字段规则

- singular
- repeated

## 更新规则

- 禁止直接修改和删除老字段,使用reserved

## 未知字段

- 3.5之前直接舍弃,现在可以找到

![image-20230920155517897](https://qkj0723.oss-cn-beijing.aliyuncs.com/img/202309201555981.png)