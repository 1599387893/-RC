#include"Heap.h"

int main()
{
	int i = 0;
	Heap hp;
	int array[] = { 9, 0, 5, 3, 1, 2, 4, 6, 7, 8 };
	CreatHeap(&hp, array, sizeof(array) / sizeof(int));
	printf("Top=%d\n", TopHeap(&hp));
	//printf("Size=%d\n", SizeHeap(&hp));


	EraseHeap(&hp);
	printf("\n");
	HeapSort(array,10);//∂—≈≈–Ú≤‚ ‘
	
	//EraseHeap(&hp);
	//printf("Top=%d\n", TopHeap(&hp));
	////printf("Size=%d\n", SizeHeap(&hp));

	//InsertHeap(&hp, 0);
	//printf("Top=%d\n", TopHeap(&hp));
	////printf("Size=%d\n", SizeHeap(&hp));

	HeapDestory(&hp);
	system("pause");
	return 0;
}