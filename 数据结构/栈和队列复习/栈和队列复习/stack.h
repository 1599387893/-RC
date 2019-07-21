#pragma once

#define MAX 100

typedef int DataType;

typedef struct Stack
{
	DataType* _array;
	int _top;
	int _capacity;
}Stack;

//初始化
void StackInit(Stack* s);
//压栈
void StackPush(Stack* s);
//出栈
void StackPop(Stack* s);
//获取栈顶元素
DataType StackTop(Stack* s);
//获取栈内有效元素个数
int StackSize(Stack* s);
//判空
int StackEmpty(Stack* s);
//销毁
void StackDestory(Stack* s);