#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define max_size 1000
typedef char Datatypedef;
//����
typedef struct Queue 
{
	Datatypedef _data[max_size];
	int _head;
	int	_tail;
	int _size;
}Queue;
//ջ
typedef struct Stack
{
	Queue _q1; 
	Queue _q2;
	int _size;
}Stack;

void StackInit(Stack* s);//��ʼ��ջ
void StackDestory(Stack* s);//����ջ
void StackPush(Stack* s, Datatypedef val);//��ջ
void StackPop(Stack* s);//��ջ
int StackSize(Stack* s);//ջ��Ԫ�ظ���
Datatypedef StackTop(Stack* s);//ջ��Ԫ��
