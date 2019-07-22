#pragma once

//------------------------带头的双向循环链表
typedef int LTDataType;

//结点结构
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;


//链表结构
typedef struct List
{
	ListNode* _head;
}List;

//初始化
void ListInit(List* pl);
//销毁
void ListDestory(List* pl);
//头插
void ListPushFront(List* pl, LTDataType data);
//头删
void ListPopFront(List* pl);
//尾插
void ListPushBack(List* pl, LTDataType data);
//尾删
void ListPopBack(List* pl);
//查找
ListNode* ListFind(List* pl, LTDataType data);
//任意位置的插入
void ListInsert(List* pl, ListNode* pos, LTDataType data);
//任意位置的删除
void ListErase(List* pl, ListNode* pos);
//打印链表内容
void ListPrint(List* pl);
//
//
void  TestDList();

