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
	printf("ջ��Ԫ��Ϊ=%d \n", StackTop(&s));
	printf("ջ����ЧԪ�ظ���=%d \n", StackSize(&s));
	printf("��ջ��=%d \n", StackEmpty(&s));
	system("pause");
	StackDestroy(&s);




	return 0;
}