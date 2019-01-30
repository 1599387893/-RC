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
	printf("%d \n", StackTop(&s));
	printf("%d \n", StackSize(&s));
	system("pause");
	StackDestroy(&s);




	return 0;
}