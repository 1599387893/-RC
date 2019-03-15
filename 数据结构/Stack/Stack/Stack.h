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
void StackInit(Stack* ps);//初始化
void StackPush(Stack* ps,StackData data);//入栈
void StackPop(Stack* ps);//出栈
int StackTop(Stack* ps);//获取栈顶元素
int StackSize(Stack* ps);//获取栈中有效元素个数
void StackDestroy(Stack* ps);//销毁栈
int StackEmpty(Stack* ps);//判栈空
