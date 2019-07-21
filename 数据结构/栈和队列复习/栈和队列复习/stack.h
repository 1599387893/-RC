#pragma once

#define MAX 100

typedef int DataType;

typedef struct Stack
{
	DataType* _array;
	int _top;
	int _capacity;
}Stack;

//��ʼ��
void StackInit(Stack* s);
//ѹջ
void StackPush(Stack* s);
//��ջ
void StackPop(Stack* s);
//��ȡջ��Ԫ��
DataType StackTop(Stack* s);
//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* s);
//�п�
int StackEmpty(Stack* s);
//����
void StackDestory(Stack* s);