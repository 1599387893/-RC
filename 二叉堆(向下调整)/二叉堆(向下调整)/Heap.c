#include"Heap.h"

void Swap(HPDateType* child, HPDateType* parent)
{
	HPDateType temp = *child;
	*child = *parent;
	*parent = temp;
	return;
}
void AdjustDown(HPDateType* array, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//找出左右孩子中最小的孩子
		if (array[child]>array[child + 1])
			child += 1;
		if (array[child] < array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}
void CreatHeap(HpNode* hp, HPDateType* array, int size)
{
	assert(hp);
	hp->_array = malloc(size * sizeof(HPDateType));
	if (hp->_array)
	{
		hp->_capacity = size;
		hp->_size = 0;
	}
	memcpy(hp->_array, array,size * sizeof(HPDateType));
	//建立堆
	AdjustDown(&hp->_array, size, 0);
}
void HeapDestory(HPDateType* hp);
void InsertHeap(HPDateType* hp,HPDateType n);
void DesrtHeap(HPDateType* hp);
HPDateType TopHeap(HPDateType* hp)
{
	if (NULL == hp)
		return -1;
	return hp->array[hp->size];
}
int SizeHeap(HPDateType* hp)
{
	return hp->size;
}
int EmtpyHeap(HPDateType* hp)
{
	if (hp->size)
		return 1;
	else
		return 0;
}
void SdjustUp(HPDateType* array, int size, int child)
{

}