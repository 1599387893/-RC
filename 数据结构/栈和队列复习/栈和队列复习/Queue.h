#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

//---------------------------------用链表实现循环队列
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

//初始化
void QueueInit(Queue* pq);
//销毁
void QueueDestory(Queue* pq);
//创建新结点
Node* BuyQueueNode(QUDataType x);
//入队列
void QueuePush(Queue* pq, QUDataType x);
//出队列
void QueuePop(Queue* pq);
//输出队头元素
QUDataType QueueFront(Queue* pq);
//输出队尾元素
QUDataType QueueBack(Queue* pq);
//判空
int QueueEmpty(Queue* pq);
//队列中的有效元素个数
int QueueSize(Queue* pq);
void TestQueue();