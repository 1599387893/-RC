#pragma once
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
//-------------------------��ͷ�ڵ�---------------------
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

//��ʼ��
void SListInit(SList* pl);
//����
void SListDestory(SList* pl);
//ͷ��
void SListPushFront(SList* pl,SDataType data);
//ͷɾ
void SListPopFront(SList* pl);
//β��
void SListPushBack(SList* pl,SDataType data);
//βɾ
void SListPopBack(SList* pl);
//����λ�ò���
void SListInsert(SList* pl,Node* pos, SDataType data);
//����λ��ɾ��
void SListErase(SList* pl, Node* pos);
//��ЧԪ�ظ���
int SListSize(SList* pl);
//�п�
int SListEmpty(SList* pl);
//����ֵΪData��Ԫ��
Node* SListFind(SList* pl, SDataType data);
//ɾ������ֵΪData��Ԫ��
void SListRemoveAll(SList* pl, SDataType data);
//��ӡ�����е����н��
void Print2(SList* pl);
