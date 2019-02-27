#include"Heap.h"

void CreatHeap(HpNode* hp, HPDateType* array, int size)
{
	assert(hp);
	hp->_array = malloc(size * sizeof(HPDateType));
	if (hp->_array)
	{
		hp->_capacity = size;
		hp->_size = 0;
	}
	memcpy(hp->_array, array);

}
void HeapDestory(HPDateType* hp);
void InsertHeap(HPDateType* hp);
void DesrtHeap(HPDateType* hp);
int SizeHeap(HPDateType* hp);
int EmtpyHeap(HPDateType* hp);