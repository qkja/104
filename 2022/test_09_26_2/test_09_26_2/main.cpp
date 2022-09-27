#define _CRT_SECURE_NO_WARNINGS 1
// C++ 没有垃圾回收器 JC C语言关注性能
// Java 简单的学习成本低,深处成本很高
// new 了 即使 delete 也会出现问题 异常打破点东西
// 异常的处理  智能指针
// 托管资源 释放资源
// 返回 堆空间的 指针 如何 保证 不会受异常影响

// 智能指针的拷贝
// C98 的 神操作
// 直接用 有可能被间接包了
// 不让拷贝  只声明不实现 (老六)+ private
// C++11 delete
// 赋值也要给封掉
// 类内的私有可以 突破类域实现吗

//
//shared_ptr<T>& operator=(const shared_ptr<T>& sp)
//{
//	if (sp._ptr == _ptr)
//		return *this;
//
//	// 这里  原本的 --
//	(*_pcount)--;
//	if (*_pcount == 0)
//	{
//		// 
//		delete _ptr;
//		_ptr = nullptr;
//		delete _pcount;
//	}
//	_ptr = sp._ptr;
//	_count = sp._pcount;
//	(*_pcount)++;
//	return *this;
//}