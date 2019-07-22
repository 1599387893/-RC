#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

//---------------------------------用链表实现循环队列
typedef int QDataType;

typedef struct Queue
{
	QDataType* _array;
	QDataType* _capacity;
	QDataType* _size;
}Queue;

//初始化
void QueueInit(Queue* q);
//入队列
void QueuePush(Queue* q, QDataType data);
//出队列
void QueuePop(Queue* q);
//队内有效元素个数
int QueueSize(Queue* q);
//判空
int QueueEmpty(Queue* q);
//队头元素
QDataType QueueFront(Queue* q);
//队尾元素
QDataType QueueBack(Queue* q);