#pragma once
#include<assert.h>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int QUDataType;
typedef struct QueueNode
{
	QUDataType _data;
	struct QueueNode* _next;
}QueueNode;
typedef struct Queue
{
	QueueNode* _front; // ∂”Õ∑
	QueueNode* _rear; // ∂”Œ≤
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
void TestQueue();