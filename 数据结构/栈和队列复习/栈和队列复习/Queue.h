#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

//---------------------------------������ʵ��ѭ������
typedef int QUDataType;

typedef struct QueueNode
{
	struct QueueNode* _pNext;
	QUDataType data;
}Node;

typedef struct Queue
{
	Node* _front;
	Node* _rear;
}Queue;

//��ʼ��
void QueueInit(Queue* pq);
//����
void QueueDestory(Queue* pq);
//�����½��
Node* BuyQueueNode(QUDataType x);
//�����
void QueuePush(Queue* pq, QUDataType x);
//������
void QueuePop(Queue* pq);
//�����ͷԪ��
QUDataType QueueFront(Queue* pq);
//�����βԪ��
QUDataType QueueBack(Queue* pq);
//�п�
int QueueEmpty(Queue* pq);
//�����е���ЧԪ�ظ���
int QueueSize(Queue* pq);
void TestQueue();