#include<stdio.h>
#include<stdlib.h>


void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void PrintArray(int* arr, int size)
{
	
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//归并排序
void Meger(int* arr, int left, right)
{

}
void MegerSort(int* arr,int left,int right)
{
	int mid = left + (right - left) / 2;
	if (right - left > 1)
	{
		MegerSort(arr, left, mid);
		MegerSort(arr, mid, right);
		Meger(arr, left, right);
	}

}

//快速排序
int Parition(int* arr, int left, int right)
{
	int key = arr[right - 1];
	int begin = left;
	int end = right - 1;
	while (begin < end)
	{
		//从左往右找比key大的值
		while (begin < end && arr[begin] <= key)
			begin++;
		//从右往左找比key小的值
		while (begin < end && arr[end] >= key)
			end--;
		if (begin < end)
			Swap(&(arr[begin]), &(arr[end]));
	}
	if (arr[begin] != arr[right - 1])
		Swap(&(arr[begin]), &(arr[right-1]));

	return begin;
}
void Qsort(int* arr, int left,int right)
{
	int mid = 0;
	if (left + 1 < right)
	{
		mid = Parition(arr, left, right);
		Qsort(arr, left, mid - 1);
		Qsort(arr, mid + 1, right);
	}
}



int main()
{
	int arr[10] = { 2, 5, 6, 9, 4, 0, 1, 7, 3, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintArray(arr, size);
	//Qsort(arr, 0, size);
	PrintArray(arr, size);


	return 0;
}












