#include"Heap.h"

int main()
{
	Heap hp;
	int array[] = { 9, 0, 5, 3, 1, 2, 4, 6, 7, 8 };
	printf("是否为空=%d\n", EmptyHeap(&hp));
	CreateHeap(&hp, array, sizeof(array) / sizeof(array[0]));
	printf("堆顶元素=%d\n", TopHeap(&hp));
	InsertHeap(&hp, 11);
	EraseHeapTop(&hp);
	printf("有效元素个数=%d\n",sizeHeap(&hp));
	printf("是否为空=%d\n", EmptyHeap(&hp));
	printf("堆顶元素=%d\n", TopHeap(&hp));
	DestroyHeap(&hp);
	HeapSort(array, 10);

	system("pause");
	return 0;
}