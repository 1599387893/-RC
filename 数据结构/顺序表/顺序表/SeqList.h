#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
//��̬
//typedef MAXSIZE 100
//typedf struct SeqList
//{
//	int data[MAXSIZE];
//	int sz;
//}SeqList;

//��̬
typedef int DataType;
typedef struct SeqList
{
	DataType* data;
	int capacity;
	int sz;
}SeqList,*PSeqList;

void InitSeqList(PSeqList ps);//��ʼ��
void DestroySeqList(PSeqList ps);//�ͷſռ�
void SeqListPushBack(PSeqList ps, DataType data);//β��
void SeqListPopBack(PSeqList ps);//βɾ
void SeqListPushFront(PSeqList ps, DataType data);//ͷ��
void SeqListPopFront(PSeqList ps);//ͷɾ
void SeqListInsert(PSeqList ps, int pos, DataType datda);//����λ�ò���
void SeqListErase(PSeqList ps, int pos);//����λ��ɾ��
int SeqListFind(PSeqList ps, DataType data);// ���data�Ƿ���˳����� 
void SeqListRemove(PSeqList ps, DataType data);// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemoveAll(PSeqList ps, DataType data);// �Ƴ�˳���������ֵΪdata��Ԫ��
int SeqListSize(PSeqList ps);// ��ȡ˳�����ЧԪ�ظ��� 
int SeqListCapacity(PSeqList ps);// ��ȡ˳�������� 
int SeqListEmpty(PSeqList ps);// ���˳����Ƿ�Ϊ��
DataType SeqListFront(PSeqList ps);// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListBack(PSeqList ps);// ��ȡ˳��������һ��Ԫ��
////////////////////////////////////// 
void PrintSeqList(PSeqList ps);