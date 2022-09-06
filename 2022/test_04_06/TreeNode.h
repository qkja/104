#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

/*
* 双亲表示法  
*/

#define CAP 100
typedef int DataType;
typedef struct PTNode
{
	DataType data;
	int parent;    // 双亲节点 的位置
}PTNode;

typedef struct 
{
	PTNode nodes[CAP];
	int r;   // 根的位置
	int n;   // 节点数
};

//struct CTree
//{
//	int data;
//	//是一个顺序表  存放 堂兄弟和兄弟节点
//	struct CTree* elem;
//};
struct CTree
{
	int data;
	//是一个链表  存放 堂兄弟和兄弟节点
	struct A elem;
};

struct A
{
	struct CTree* val;
	//是一个顺序表  存放 堂兄弟和兄弟节点
	struct A* next;
};

