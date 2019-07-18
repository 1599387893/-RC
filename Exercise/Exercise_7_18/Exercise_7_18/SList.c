#include"SList.h"
#include<stdio.h>
#include<assert.h>

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
	return newNode;
}
//��ʼ��
void SListInit(SList* pl)
{
	assert(pl);
	pl->_pHead = NULL;
}
//����
void SListDestory(SList* pl);
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
	Node* pCur = pl->_pHead;
	Node* pPre = pCur;
	while (pCur->_pNext)
	{
		pPre = pCur;
		pCur = pCur->_pNext;
	}
	if (pCur != pl->_pHead)
		pPre->_pNext = NULL;
	free(pCur);
	pCur = NULL;

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
	Node* pCur = pl->_pHead;
	pl->_pHead = pl->_pHead->_pNext;
	free(pCur);
	pCur = NULL;
}


//---------------------------------��ͷ�ڵ�----------------------------------------
