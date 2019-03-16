#include"Sort.h"

int main()
{
	int array[] = { 9, 1, 2, 5, 7, 4, 3, 6, 8, 0 };
	Print(array, sizeof(array) / sizeof(array[0]));
	InsertSort_2(array, sizeof(array) / sizeof(array[0]));
	//ShellSort(array, sizeof(array) / sizeof(array[0]));
	//BubbleSort(array, sizeof(array) / sizeof(array[0]));
	//HeapSort(array, sizeof(array) / sizeof(array[0]));
	//SelectionSort(array, sizeof(array) / sizeof(array[0]));
	Print(array, sizeof(array) / sizeof(array[0]));
	system("pause");
	return 0;
}