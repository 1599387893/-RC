#include"Stack(queue).h"

int main()
{
	Stack stack;
	//≥ı ºªØ
	StackInit(&stack);
	StackPush(&stack, 'a');
	StackPush(&stack, 'b');
	StackPush(&stack, 'c');
	StackPush(&stack, 'd');
	StackPush(&stack, 'e');
	StackPush(&stack, 'f');

	printf("%d\n",StackSize(&stack));
	printf("%c\n", StackTop(&stack)); 
	

	StackPop(&stack);
	StackPop(&stack);
	StackPop(&stack);

	printf("%d\n", StackSize(&stack));
	printf("%c\n",StackTop(&stack));

	//StackDestory(&stack);
	system("pause");
	return 0;
}