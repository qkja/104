#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEAP <

typedef int HPDataType;
struct MyHeap
{
	HPDataType* elem;
	size_t size;
	size_t useSize;
};

typedef struct MyHeap MyHeap;


//extern "C" extern void InitMyHeap(MyHeap * pHeap);
//
//extern "C" extern void HeapPush(MyHeap* pHeap, HPDataType x);
//extern "C" extern bool IsFull(MyHeap* pHeap);
//extern "C" extern bool IsEmpty(MyHeap* pHeap);
//extern "C" extern int HeapSize(MyHeap* pHeap);
//
////向下调整
//extern "C" extern void adjustDown(MyHeap* pHeap);
//
////向上调整
//extern "C" extern void adjustUp(MyHeap* pHeap);
//
//extern "C" extern void Display(MyHeap* pHeap);
//
//extern "C" extern HPDataType HeapTop(MyHeap* pHeap);
//extern "C" extern void HeapPop(MyHeap* pHeap);

//初始化
//
//#ifdef __cplusplus    // C++独有的
//	#define EXTERNC extern "C"
//#else 
//	#define EXTERNC
//#endif
//
//
//EXTERNC extern void InitMyHeap(MyHeap * pHeap);
//
//EXTERNC extern void HeapPush(MyHeap* pHeap, HPDataType x);
//EXTERNC extern bool IsFull(MyHeap* pHeap);
//EXTERNC extern bool IsEmpty(MyHeap* pHeap);
//EXTERNC extern int HeapSize(MyHeap* pHeap);
//EXTERNC extern void adjustDown(MyHeap* pHeap);
//EXTERNC extern void adjustUp(MyHeap* pHeap);
//EXTERNC extern void Display(MyHeap* pHeap);
//EXTERNC extern HPDataType HeapTop(MyHeap* pHeap);
//EXTERNC extern void HeapPop(MyHeap* pHeap);


#ifdef __cplusplus
extern "C"
{
#endif

	extern void InitMyHeap(MyHeap * pHeap);

	extern void HeapPush(MyHeap* pHeap, HPDataType x);
	extern bool IsFull(MyHeap* pHeap);
	extern bool IsEmpty(MyHeap* pHeap);
	extern int HeapSize(MyHeap* pHeap);
	extern void adjustDown(MyHeap* pHeap);
	extern void adjustUp(MyHeap* pHeap);
	extern void Display(MyHeap* pHeap);
	extern HPDataType HeapTop(MyHeap* pHeap);
	extern void HeapPop(MyHeap* pHeap);
	void func(int a, double b);
#ifdef __cplusplus
}
#endif

void func(int a, double b);



