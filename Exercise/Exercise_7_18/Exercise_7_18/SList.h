#pragma once

typedef int SDataType;
//���ṹ
typedef struct SListNode
{
	SDataType _data;
	Node* _pNext;
}Node;

//����ṹ
typedef struct SList
{
	Node* _pHead;//_pList�����һ��Ԫ�صĵ�ַ
}SList;

//��ʼ��
void SListInit(SList* pl);
//����
void SListDestory(SList* pl);
//β��
void SListPushBack(SList* pl, SDataType data);
//βɾ
void SListPopBack(SList* pl);
//ͷ��
void SListPushFront(SList* pl, SDataType data);
//ͷɾ
void SListPopFront(SList* pl);
