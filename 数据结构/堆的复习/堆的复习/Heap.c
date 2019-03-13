#include"Heap.h"

//创建堆
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//向下调整(堆创建)
void AdjustDown(Heap* hp, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && hp->_array[child] > hp->_array[child + 1])
			child++;
		if (hp->_array[parent] > hp->_array[child])
			Swap(&hp->_array[parent], &hp->_array[child]);
		parent = child;
		child = parent * 2 + 1;
	}
}
void CreateHeap(Heap* hp, HPDataType* array, int size)
{
	if (array == NULL)
		return;
	int root = -1;
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)* size);
	if (NULL == hp->_array)
		assert("hp->_array Malloc Fail");
	memcpy(hp->_array, array, sizeof(HPDataType) * size);
	hp->_capacity = size;
	hp->_size = size;

	//向下调整
	root = (size - 2) / 2;
	for (; root >= 0; root--)
		AdjustDown(hp, hp->_size, root);
}
//销毁堆
void DestroyHeap(Heap* hp)
{
	if (NULL == hp->_array)
		return;
	free(hp->_array);
	hp->_capacity = 0;
	hp->_size = 0;
	hp->_array = NULL;
}
//向堆中插入元素
void CheckCapacity(Heap* hp)
{
	HPDataType* array = NULL;
	int NewCapacity = hp->_capacity * 2;
	if (hp->_capacity > hp->_size)
		return;
	if (hp->_capacity == hp->_size)
	{
		array = (HPDataType*)malloc(sizeof(HPDataType)*NewCapacity);
		if (NULL == array)
			assert("CheckCapacity Error!");
		memcpy(array, hp->_array, sizeof(HPDataType)* hp->_size);
		hp->_array = array;
		hp->_capacity = NewCapacity;
	}
}
void InsertHeap(Heap* hp, HPDataType data)
{
	int root = -1;
	if (NULL == hp->_array)
		return;
	//检查容量是否足够
	CheckCapacity(hp);

	hp->_array[hp->_size] = data;
	hp->_size++;
	//调整成小堆
	AdjustDown(hp, hp->_size, (hp->_size - 2) / 2);
}
//堆删除(删除堆顶元素)
void EraseHeapTop(Heap* hp)
{
	//先交换堆顶元素和最后一个元素
	Swap(&(hp->_array[0]), &(hp->_array[hp->_size - 1]));
	hp->_size--;
	AdjustDown(hp, hp->_size, 0);
}
//堆中元素个数
int sizeHeap(Heap* hp)
{
	if (NULL == hp->_array)
		return 0;
	return hp->_size;
}
//判空
int EmptyHeap(Heap* hp)
{
	if (0 > hp->_size)
		return -1;
	return 1;
}
//返回堆顶元素
HPDataType TopHeap(Heap* hp)
{
	if (NULL != hp->_array)
		return hp->_array[0];
	return -1;
}
//向下调整(堆排序)
void AdjsutDownSort(HPDataType* array, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && array[child] > array[child + 1])
			child += 1;
		if (array[parent] > array[child])
			Swap(&(array[parent]), &(array[child]));
		parent = child;
		child = parent * 2 + 1;
	}
}
//堆排序
void HeapSort(HPDataType* array, int size)
{
	//调整成小堆
	int root = (size - 2) / 2;
	for (; root >= 0; root--)
		AdjsutDownSort(array, size, root);
	//排序(类似堆删除)
	while (size--)
	{
		Swap(&array[0], &array[size]);
		AdjsutDownSort(array, size, 0);
	}
}