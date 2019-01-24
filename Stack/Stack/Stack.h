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
void StackInit(Stack* ps);
void StackPush(Stack* ps,StackData data);
void StackPop(Stack* ps);
int StackTop(Stack* ps);
int StackSize(Stack* ps);
void StackDestroy(Stack* ps);
