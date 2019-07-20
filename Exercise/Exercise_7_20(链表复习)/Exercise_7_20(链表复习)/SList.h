#pragma once

typedef int SDataType;
//结点结构
typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _pNext;
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
//查找一个元素在链表中的位置
Node* Find(SList* pl, SDataType data);
//任意位置的插入
void SListInsert(SList* pl,Node* pos, SDataType data);
//任意位置的删除
void SListErase(SList* pl,Node* pos);
//打印链表内容
void Print(SList* pl);
//有效元素个数
int SListSize(SList* pl);
//判空
int SListEmpty(SList* pl);
//链表第一个元素
Node* SListFront(SList* pl);
//链表最后一个元素
Node* SlistBack(SList* pl);