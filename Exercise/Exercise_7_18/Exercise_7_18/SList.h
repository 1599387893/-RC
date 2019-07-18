#pragma once

typedef int SDataType;
//结点结构
typedef struct SListNode
{
	SDataType _data;
	Node* _pNext;
}Node;

//链表结构
typedef struct SList
{
	Node* _pHead;//_pList保存第一个元素的地址
}SList;

//初始化
void SListInit(SList* pl);
//销毁
void SListDestory(SList* pl);
//尾插
void SListPushBack(SList* pl, SDataType data);
//尾删
void SListPopBack(SList* pl);
//头插
void SListPushFront(SList* pl, SDataType data);
//头删
void SListPopFront(SList* pl);
