#include"stack.h"


//��ʼ��
void StackInit(Stack* s)
{
	assert(s);
	s->_array = (DataType*)malloc(sizeof(DataType)*5);
	s->_capacity = 5;
	s->_top = 0;
}
void CheckCapacity(Stack* s)
{
	if (s->_top == s->_capacity)
	{
		int newCapacity = s->_capacity * 2;
		DataType* newArr = (DataType*)malloc(sizeof(DataType)*newCapacity);
		if (newArr == NULL)
			assert("malloc faild\n");
		memcpy(newArr,s->_array, sizeof(DataType)*s->_top);
		free(s->_array);
		s->_array = newArr;
		s->_capacity = newCapacity;
	}
}
//ѹջ
void StackPush(Stack* s,DataType data)
{
	assert(s);
	CheckCapacity(s);
	s->_array[s->_top] = data;
	s->_top++;
}
//��ջ
void StackPop(Stack* s)
{
	assert(s);
	if (s->_top == 0)
		return;
	s->_top--;
}
//��ȡջ��Ԫ��
DataType StackTop(Stack* s)
{
	assert(s);
	if (s->_top == 0)
		return -1;
	return s->_array[s->_top-1];
}
//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}
//�п�
int StackEmpty(Stack* s)
{
	assert(s);
	if (s->_top == 0)
		return 1;
	else
		return 0;
}
//����
void StackDestory(Stack* s)
{
	assert(s);
	if (s->_array)
	{
		free(s->_array);
		s->_array = NULL;
		s->_capacity = 0;
		s->_top = 0;

	}
}

int main()
{
	Stack s;
	StackInit(&s);
	printf("Empty = %d\n", StackEmpty(&s));

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	printf("Top = %d\n", StackTop(&s));
	StackPush(&s, 6);
	printf("Top = %d\n", StackTop(&s));
	StackPop(&s);
	printf("Top = %d\n", StackTop(&s));
	StackPop(&s);
	printf("Top = %d\n", StackTop(&s));
	printf("Size = %d\n", StackSize(&s));
	printf("Empty = %d\n", StackEmpty(&s));
	StackDestory(&s);
	printf("Empty = %d\n", StackEmpty(&s));
	printf("Size = %d\n", StackSize(&s));

	return 0;
}