#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct DList
{
	DataType data;
	struct DList* pNext;
	struct DList* pPer;
}DList;

void DListInit(DList* s);//��ʼ��
void DListPushBack(DList* s, DataType data);//β��
void DListPopBack(DList* s);//βɾ

void DListPushFront(DList* s,DataType data);//ͷ��
void DLIstPopFront(DList* s);//ͷɾ
void DListInsertAfter(DList* pos, DataType data);// ������posλ�ú������Ϊdata�Ľڵ�
void DListErase(DList* s, DataType data);// ɾ��������ֵΪdata�Ľڵ�
void DListEraseALL(DList* s, DataType data);// ɾ������������ֵΪdata�Ľڵ� 
DList* DListFind(DList* s, DataType data);// �������в���ֵΪdata�Ľڵ㣬�ҵ����ظýڵ�ĵ�ַ�����򷵻ؿ� 
int DListSize(DList* s);// ��ȡ��������Ч�ڵ�ĸ���
int DListEmpty(DList* s);// ��������Ƿ�Ϊ�� 
DList* DListFront(DList* s);// ��ȡ����ĵ�һ���ڵ� 
DList* DListBack(DList* s);// ��ȡ����ĵڶ����ڵ� 

void PrintDList(DList* s);//��ʾ��������
void DListDestroy(DList* s);//��������