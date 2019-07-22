#pragma once

#define MAXSIZE 100
typedef int DataType;
//��̬˳���ṹ
//struct SeqList
//{
//	DataType array[MAXSIZE];
//	int size;
//};
//��̬˳���ṹ
typedef int size_t;
typedef struct SeqList
{
	DataType* _array;
	size_t _size;
	size_t _capacity;
}SeqList, *PSeqList;


void SeqListInit(PSeqList ps);
void SeqListDestory(PSeqList ps);

//ͷ��
void SeqListPushFront(PSeqList ps, DataType data);
//ͷɾ
void SeqListPopFront(PSeqList ps);
//β��
void SeqListPushBack(PSeqList ps, DataType data);
//βɾ
void SeqListPopBack(PSeqList ps);
//����λ�ò���
void Insert(PSeqList ps, DataType data, int pos);
//����λ��ɾ��
void Erase(PSeqList ps, size_t pos);
//�п�
int Empty(PSeqList ps);
//��ЧԪ�ظ���
size_t Size(PSeqList ps);
//����λ��Ԫ�ط���
DataType find_elem(PSeqList ps, size_t pos);
//��ӡ˳�������
void Print1(PSeqList ps);
void TestSeqList();