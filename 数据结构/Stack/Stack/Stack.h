#include<assert.h>
#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

typedef int StackData;
typedef struct Stack
{
	StackData* array;
	int Capacity;
	int size;
}Stack;
void StackInit(Stack* ps);//��ʼ��
void StackPush(Stack* ps,StackData data);//��ջ
void StackPop(Stack* ps);//��ջ
int StackTop(Stack* ps);//��ȡջ��Ԫ��
int StackSize(Stack* ps);//��ȡջ����ЧԪ�ظ���
void StackDestroy(Stack* ps);//����ջ
int StackEmpty(Stack* ps);//��ջ��
