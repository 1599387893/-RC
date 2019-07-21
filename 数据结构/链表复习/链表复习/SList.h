#pragma once
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
//-------------------------带头节点---------------------
typedef int SDataType;
typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _pNext;
}Node;

typedef struct SList
{
	Node* _pHead;
}SList;

//初始化
void SListInit(SList* pl);
//销毁
void SListDestory(SList* pl);
//头插
void SListPushFront(SList* pl,SDataType data);
//头删
void SListPopFront(SList* pl);
//尾插
void SListPushBack(SList* pl,SDataType data);
//尾删
void SListPopBack(SList* pl);
//任意位置插入
void SListInsert(SList* pl,Node* pos, SDataType data);
//任意位置删除
void SListErase(SList* pl, Node* pos);
//有效元素个数
int SListSize(SList* pl);
//判空
int SListEmpty(SList* pl);
//查找值为Data的元素
Node* SListFind(SList* pl, SDataType data);
//删除所有值为Data的元素
void SListRemoveAll(SList* pl, SDataType data);
//打印链表中的所有结点
void Print2(SList* pl);
