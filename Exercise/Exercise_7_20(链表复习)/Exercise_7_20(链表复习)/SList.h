#pragma once

typedef int SDataType;
//���ṹ
typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _pNext;
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
//����һ��Ԫ���������е�λ��
Node* Find(SList* pl, SDataType data);
//����λ�õĲ���
void SListInsert(SList* pl,Node* pos, SDataType data);
//����λ�õ�ɾ��
void SListErase(SList* pl,Node* pos);
//��ӡ��������
void Print(SList* pl);
//��ЧԪ�ظ���
int SListSize(SList* pl);
//�п�
int SListEmpty(SList* pl);
//�����һ��Ԫ��
Node* SListFront(SList* pl);
//�������һ��Ԫ��
Node* SlistBack(SList* pl);