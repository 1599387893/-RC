#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define max_size 1000

typedef int Datatypedef;
typedef struct Stack
{
	Datatypedef _data[max_size];
	int _sizeStack;
}Stack;
typedef struct Queue
{
	Stack _s1;
	Stack _s2;
	Datatypedef _front;
	Datatypedef _rear;
	int _sizeQueue;
}Queue;

void QueueInit(Queue* q);
void QueueDestroy(Queue* q);
void QueuePush(Queue* q,Datatypedef val);
void QueuePop(Queue* q);
Datatypedef QueueFront(Queue* q);
Datatypedef QueueRear(Queue* q);
int QueueSize(Queue* q);