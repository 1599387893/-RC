#include"SList.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//---------------------------------����ͷ�ڵ�----------------------------------------
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
//��ʼ��
void SListInit(SList* pl)
{
	assert(pl);
	pl->_pHead = NULL;
}
//����
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
//β��
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
//βɾ
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
//ͷ��
void SListPushFront(SList* pl, SDataType data)
{
	assert(pl);
	Node* newNode = BuyNewNode(data);
	newNode->_pNext = pl->_pHead;
	pl->_pHead = newNode;
}
//ͷɾ
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
//����һ��Ԫ���������е�λ��
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
//����λ�õĲ���
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
//����λ�õ�ɾ��
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
//��ӡ��������
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

//��ЧԪ�ظ���
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
//�п�
int SListEmpty(SList* pl)
{
	assert(pl);
	if (NULL == pl->_pHead)
		return 1;
	return 0;
}
//�����һ��Ԫ��
Node* SListFront(SList* pl)
{
	assert(pl);
	return pl->_pHead;
}
//�������һ��Ԫ��
Node* SlistBack(SList* pl)
{
	assert(pl);
	Node* pCur = pl->_pHead;
	while (pCur->_pNext)
		pCur = pCur->_pNext;
	return pCur;
}

//---------------------------------��ͷ�ڵ�----------------------------------------