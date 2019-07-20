#include"SList.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//---------------------------------不带头节点----------------------------------------
Node* BuyNewNode(SDataType data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}
	newNode->_data = data;
	newNode->_pNext = NULL;
	return newNode;
}
//初始化
void SListInit(SList* pl)
{
	assert(pl);
	pl->_pHead = NULL;
}
//销毁
void SListDestory(SList* pl)
{
	assert(pl);
	if (NULL == pl->_pHead)
		return;
	Node* pCur = pl->_pHead;
	while (pCur->_pNext)
	{
		pl->_pHead = pl->_pHead->_pNext;
		free(pCur);
		pCur = pl->_pHead;
	}
	free(pl->_pHead);
	pl->_pHead = NULL;
}
//尾插
void SListPushBack(SList* pl, SDataType data)
{
	assert(pl);
	Node* newNode = BuyNewNode(data);
	if (NULL == pl->_pHead)
		pl->_pHead = newNode;
	else
	{
		Node* pCur = pl->_pHead;
		while (pCur->_pNext)
			pCur = pCur->_pNext;
		pCur->_pNext = newNode;
	}
}
//尾删
void SListPopBack(SList* pl)
{
	assert(pl);
	if (NULL == pl->_pHead)
		return;
	if (NULL == pl->_pHead->_pNext)
	{
		free(pl->_pHead);
		pl->_pHead = NULL;
		return;
	}
	Node* pPre = pl->_pHead;
	Node* pCur = pPre->_pNext;
	while (pCur->_pNext)
	{
		pPre = pCur;
		pCur = pCur->_pNext;
	}
	free(pCur);
	pCur = NULL;
	pPre->_pNext = NULL;
}
//头插
void SListPushFront(SList* pl, SDataType data)
{
	assert(pl);
	Node* newNode = BuyNewNode(data);
	newNode->_pNext = pl->_pHead;
	pl->_pHead = newNode;
}
//头删
void SListPopFront(SList* pl)
{
	assert(pl);
	if (NULL == pl->_pHead)
		return;
	Node* pCur = pl->_pHead;
	pl->_pHead = pl->_pHead->_pNext;
	free(pCur);
	pCur = NULL;
}
//查找一个元素在链表中的位置
Node* Find(SList* pl, SDataType data)
{
	assert(pl);
	if (NULL == pl->_pHead)
		return NULL;
	Node* pCur = pl->_pHead;
	while (pCur)
	{
		if (data == pCur->_data)
			return pCur;
		pCur = pCur->_pNext;
	}
	return NULL;
}
//任意位置的插入
void SListInsert(SList* pl,Node* pos, SDataType data)
{
	assert(pl);
	if (NULL == pl->_pHead || NULL == pos)
		return;
	Node* newNode = BuyNewNode(data);
	if (pos == pl->_pHead)
	{
		pos->_pNext = pl->_pHead;
		pl->_pHead = pos;
	}
	Node* pPre = pl->_pHead;
	Node* pCur = pPre->_pNext;
	while (pCur->_pNext)
	{
		if (pCur == pos)
			break;
		pPre = pCur;
		pCur = pCur->_pNext;
	}
	if ( NULL == pCur->_pNext)
		return;
	newNode->_pNext = pCur;
	pPre->_pNext = newNode;
}
//任意位置的删除
void SListErase(SList* pl,Node* pos)
{
	assert(pl);
	if (NULL == pl->_pHead || NULL  == pos)
		return;
	if (pos == pl->_pHead)
	{
		pl->_pHead = pl->_pHead->_pNext;
		free(pos);
		pos = NULL;
	}
	Node* pCur = pl->_pHead;
	while (pCur)
	{
		if (pCur->_pNext == pos)
			break;
		pCur = pCur->_pNext;
	}
	if (NULL == pCur)
		return;
	pCur->_pNext = pos->_pNext;
	free(pos);
	pos = NULL;
}
//打印链表内容
void Print(SList* pl)
{
	Node* pCur = pl->_pHead;
	while (pCur)
	{
		printf("%d--->", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}

//有效元素个数
int SListSize(SList* pl)
{
	assert(pl);
	if (NULL == pl->_pHead)
		return 0;
	int count = 1;
	Node* pCur = pl->_pHead;
	while (pCur->_pNext)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}
//判空
int SListEmpty(SList* pl)
{
	assert(pl);
	if (NULL == pl->_pHead)
		return 1;
	return 0;
}
//链表第一个元素
Node* SListFront(SList* pl)
{
	assert(pl);
	return pl->_pHead;
}
//链表最后一个元素
Node* SlistBack(SList* pl)
{
	assert(pl);
	Node* pCur = pl->_pHead;
	while (pCur->_pNext)
		pCur = pCur->_pNext;
	return pCur;
}

//---------------------------------带头节点----------------------------------------