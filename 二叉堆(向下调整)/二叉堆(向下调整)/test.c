#include"Heap.h"

int main()
{
	Heap hp;
	int array[] = { 9, 0, 5, 3, 1, 2, 4, 6, 7, 8 };
	CreatHeap(&hp, array, sizeof(array) / sizeof(int));
	printf("Top=%d\n",TopHeap(&hp));
	printf("Size=%d\n", SizeHeap(&hp));

	EraseHeap(&hp);
	printf("top=%d\n", TopHeap(&hp));
	printf("Size=%d\n", SizeHeap(&hp));

	InsertHeap(&hp, 11);
	printf("top=%d\n", TopHeap(&hp));
	printf("Size=%d\n", SizeHeap(&hp));

	HeapDestory(&hp);
	system("pause");
	return 0;
}