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
		if (child + 1 <size && array[child]>array[child + 1])
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
void CreatHeap(Heap* hp, HPDateType* array, int size)
{
	assert(hp);
	int root = -1;
	hp->_array = malloc(size * sizeof(HPDateType));
	if (hp->_array)
	{
		hp->_capacity = size;
		hp->_size = 0;
	}
	memcpy(hp->_array, array,size * sizeof(HPDateType));
	hp->_size = size;
	//找到第一个非叶子结点
	root = (size - 2) / 2;
	for (; root >= 0; --root)//一直调整到根的位置
	{
		AdjustDown(hp->_array, size, root);
	}
}
void HeapDestory(Heap* hp)
{
	if (hp->_array)
	{
		free(hp->_array);
		hp->_capacity = 0;
		hp->_size = 0;
	}
}
void CheckCapacity(Heap* hp)
{
	HPDateType* array = (HPDateType*)malloc(sizeof(HPDateType)* hp->_capacity * 2);
	if (NULL == array)
		return;
	hp->_capacity *= 2;
	memcpy(array, hp->_array, hp->_capacity);

}
void InsertHeap(Heap* hp, HPDateType n)
{
	assert(hp);
	//检查容量
	if (hp->_size == hp->_capacity)
		//扩容
		CheckCapacity(hp);
	hp->_array[hp->_size] = n;
	hp->_size++;
	AdjustDown(hp->_array,hp->_size,0);
}
void EraseHeap(Heap* hp)
{
	assert(hp);
	if (0 == hp->_size)
		return;
	//将堆顶元素和最后一个元素交换
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_array, hp->_size, 0);
}
HPDateType TopHeap(Heap* hp)
{
	if (NULL == hp->_array)
		return -1;
	return hp->_array[0];
}
int SizeHeap(Heap* hp)
{
	return hp->_size;
}
int EmtpyHeap(Heap* hp)
{
	if (hp->_size)
		return 1;
	else
		return 0;
}
void AdjustUp(Heap* array, int size, int child)
{
	
}