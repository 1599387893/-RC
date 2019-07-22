#pragma once

#define MAXSIZE 100
typedef int DataType;
//静态顺序表结构
//struct SeqList
//{
//	DataType array[MAXSIZE];
//	int size;
//};
//动态顺序表结构
typedef int size_t;
typedef struct SeqList
{
	DataType* _array;
	size_t _size;
	size_t _capacity;
}SeqList, *PSeqList;


void SeqListInit(PSeqList ps);
void SeqListDestory(PSeqList ps);

//头插
void SeqListPushFront(PSeqList ps, DataType data);
//头删
void SeqListPopFront(PSeqList ps);
//尾插
void SeqListPushBack(PSeqList ps, DataType data);
//尾删
void SeqListPopBack(PSeqList ps);
//任意位置插入
void Insert(PSeqList ps, DataType data, int pos);
//任意位置删除
void Erase(PSeqList ps, size_t pos);
//判空
int Empty(PSeqList ps);
//有效元素个数
size_t Size(PSeqList ps);
//任意位置元素访问
DataType find_elem(PSeqList ps, size_t pos);
//打印顺序表内容
void Print1(PSeqList ps);
void TestSeqList();