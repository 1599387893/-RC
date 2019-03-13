#include"Heap.h"

int main()
{
	Heap hp;
	int array[] = { 9, 0, 5, 3, 1, 2, 4, 6, 7, 8 };
	printf("�Ƿ�Ϊ��=%d\n", EmptyHeap(&hp));
	CreateHeap(&hp, array, sizeof(array) / sizeof(array[0]));
	printf("�Ѷ�Ԫ��=%d\n", TopHeap(&hp));
	InsertHeap(&hp, 11);
	EraseHeapTop(&hp);
	printf("��ЧԪ�ظ���=%d\n",sizeHeap(&hp));
	printf("�Ƿ�Ϊ��=%d\n", EmptyHeap(&hp));
	printf("�Ѷ�Ԫ��=%d\n", TopHeap(&hp));
	DestroyHeap(&hp);
	HeapSort(array, 10);

	system("pause");
	return 0;
}