#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

//---------------------------------������ʵ��ѭ������
typedef int QDataType;

typedef struct Queue
{
	QDataType* _array;
	QDataType* _capacity;
	QDataType* _size;
}Queue;

//��ʼ��
void QueueInit(Queue* q);
//�����
void QueuePush(Queue* q, QDataType data);
//������
void QueuePop(Queue* q);
//������ЧԪ�ظ���
int QueueSize(Queue* q);
//�п�
int QueueEmpty(Queue* q);
//��ͷԪ��
QDataType QueueFront(Queue* q);
//��βԪ��
QDataType QueueBack(Queue* q);