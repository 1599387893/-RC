#include"Stack.h"

void StackInit(Stack* ps)
{
	ps->array = (StackData*)malloc(sizeof(StackData)* 3);
	ps->Capacity = 3;
	ps->size = 0;
}
void CheckStack(Stack*ps)
{
	assert(ps);
	int NewCapacity = 2 * ps->Capacity;
	if (ps->Capacity == ps->size)
	{
		StackData* NewArray = (StackData*)malloc(sizeof(StackData)* (NewCapacity));
		if (NewArray == NULL)
		{
			perror("À©ÈÝÊ§°Ü!\n");
			return;
		}
		memcpy(NewArray, ps->array, sizeof(StackData)*ps->size);
		ps->array = NewArray;
		ps->Capacity = NewCapacity;
	}
}
void StackPush(Stack* ps, StackData data)
{
	assert(ps);
	CheckStack(ps);
	ps->array[ps->size] = data;
	ps->size++;
	return;
}
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->size != 0)
		ps->size--;
}
int StackTop(Stack* ps)
{
	assert(ps);
		return ps->array[ps->size-1];
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == -1; 
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->array != NULL)
	{
		free(ps->array);
		ps->array = NULL;
		ps->Capacity = 0;
		ps->size = 0;
	}
}
