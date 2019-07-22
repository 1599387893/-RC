#pragma once

//------------------------��ͷ��˫��ѭ������
typedef int LTDataType;

//���ṹ
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;


//����ṹ
typedef struct List
{
	ListNode* _head;
}List;

//��ʼ��
void ListInit(List* pl);
//����
void ListDestory(List* pl);
//ͷ��
void ListPushFront(List* pl, LTDataType data);
//ͷɾ
void ListPopFront(List* pl);
//β��
void ListPushBack(List* pl, LTDataType data);
//βɾ
void ListPopBack(List* pl);
//����
ListNode* ListFind(List* pl, LTDataType data);
//����λ�õĲ���
void ListInsert(List* pl, ListNode* pos, LTDataType data);
//����λ�õ�ɾ��
void ListErase(List* pl, ListNode* pos);
//��ӡ��������
void ListPrint(List* pl);
//
//
void  TestDList();

