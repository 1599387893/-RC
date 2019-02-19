#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define max_size 1000
typedef char Datatypedef;
//队列
typedef struct Queue 
{
	Datatypedef _data[max_size];
	int _head;
	int	_tail;
	int _size;
}Queue;
//栈
typedef struct Stack
{
	Queue _q1; 
	Queue _q2;
	int _size;
}Stack;

void StackInit(Stack* s);//初始化栈
void StackDestory(Stack* s);//销毁栈
void StackPush(Stack* s, Datatypedef val);//入栈
void StackPop(Stack* s);//出栈
int StackSize(Stack* s);//栈内元素个数
Datatypedef StackTop(Stack* s);//栈顶元素
