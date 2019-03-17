#include"Sort.h"

int main()
{
	int array[] = { 9, 1, 2, 0, 7, 4, 3, 6, 8, 5 };
	Print(array, sizeof(array) / sizeof(array[0]));
	//InsertSort_2(array, sizeof(array) / sizeof(array[0]));
	//ShellSort(array, sizeof(array) / sizeof(array[0]));
	//BubbleSort(array, sizeof(array) / sizeof(array[0]));
	//HeapSort(array, sizeof(array) / sizeof(array[0]));
	//SelectionSort(array, sizeof(array) / sizeof(array[0]));
	//SelectionSort_2(array, sizeof(array) / sizeof(array[0]));
	//QSort_1(array, 0, 9);
	//QSort_2(array, 0, 9);
	//QSort_3(array, 0, 10);
	merge_sort(array, array, 0, 9);
	Print(array, sizeof(array) / sizeof(array[0]));
	system("pause");
	return 0;
}


