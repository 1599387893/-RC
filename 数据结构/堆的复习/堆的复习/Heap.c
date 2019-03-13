#include"Heap.h"

//������
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//���µ���(�Ѵ���)
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

	//���µ���
	root = (size - 2) / 2;
	for (; root >= 0; root--)
		AdjustDown(hp, hp->_size, root);
}
//���ٶ�
void DestroyHeap(Heap* hp)
{
	if (NULL == hp->_array)
		return;
	free(hp->_array);
	hp->_capacity = 0;
	hp->_size = 0;
	hp->_array = NULL;
}
//����в���Ԫ��
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
	//��������Ƿ��㹻
	CheckCapacity(hp);

	hp->_array[hp->_size] = data;
	hp->_size++;
	//������С��
	AdjustDown(hp, hp->_size, (hp->_size - 2) / 2);
}
//��ɾ��(ɾ���Ѷ�Ԫ��)
void EraseHeapTop(Heap* hp)
{
	//�Ƚ����Ѷ�Ԫ�غ����һ��Ԫ��
	Swap(&(hp->_array[0]), &(hp->_array[hp->_size - 1]));
	hp->_size--;
	AdjustDown(hp, hp->_size, 0);
}
//����Ԫ�ظ���
int sizeHeap(Heap* hp)
{
	if (NULL == hp->_array)
		return 0;
	return hp->_size;
}
//�п�
int EmptyHeap(Heap* hp)
{
	if (0 > hp->_size)
		return -1;
	return 1;
}
//���ضѶ�Ԫ��
HPDataType TopHeap(Heap* hp)
{
	if (NULL != hp->_array)
		return hp->_array[0];
	return -1;
}
//���µ���(������)
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
//������
void HeapSort(HPDataType* array, int size)
{
	//������С��
	int root = (size - 2) / 2;
	for (; root >= 0; root--)
		AdjsutDownSort(array, size, root);
	//����(���ƶ�ɾ��)
	while (size--)
	{
		Swap(&array[0], &array[size]);
		AdjsutDownSort(array, size, 0);
	}
}