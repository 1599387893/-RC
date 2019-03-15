#include"Stack.h"

int main()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 0);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPop(&s);
	printf("栈顶元素为=%d \n", StackTop(&s));
	printf("栈中有效元素个数=%d \n", StackSize(&s));
	printf("判栈空=%d \n", StackEmpty(&s));
	system("pause");
	StackDestroy(&s);




	return 0;
}