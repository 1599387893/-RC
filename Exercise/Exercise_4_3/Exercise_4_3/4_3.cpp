#include<iostream>
using namespace std;

void Print(int* array, int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}

//归并排序
//void MergeData(int* array, int left, int mid, int right, int* temp)
//{
//	int begin1 = left;
//	int end1 = mid;
//	int begin2 = mid;
//	int end2 = right;
//	int index = left;
//
//	while (begin1 < end1 && begin2 < end2)
//	{
//		if (array[begin1] < array[begin2])
//			temp[index++] = array[begin1++];
//		else
//			temp[index++] = array[begin2++];
//	}
//	while (begin1<end1)
//		temp[index++] = array[begin1++];
//	while (begin2<end2)
//		temp[index++] = array[begin2++];
//
//
//
//}
//void MergeSort(int* array, int size)
//{
//	int* temp = (int*)malloc(sizeof(int)* 10);
//	int gap = 1;
//	while (gap < size)
//	{
//		for (int i = 0; i < size; i += gap * 2)
//		{
//			int left = i;
//			int mid = left + gap;
//			int right = mid + gap;
//
//			if (mid >size)
//				mid = size;
//			if (right>size)
//				right = size;
//			MergeData(array, left, mid, right, temp);
//		}
//		memcpy(array, temp, sizeof(int)* 10);
//		gap *= 2;
//	}
//}


//快速排序
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//左右交换法
//int Parition_1(int* array, int left, int right)
//{
//	int begin = left;
//	int end = right - 1;
//	int key = array[right - 1];
//
//	while (begin < end)
//	{
//		while (begin < end && array[begin] <= key)
//			begin++;
//		while (begin < end && array[end] >= key)
//			end--;
//
//		if (begin < end)
//			Swap(&array[begin], &array[end]);
//	}
//	if (array[begin] != key)
//		Swap(&array[begin], &array[right - 1]);
//
//	return begin;
//}
//void Qsort_1(int* array, int left, int right)
//{
//	int mid = 0;
//	if (left < right)
//	{
//		mid = Parition_1(array, left, right);
//		Qsort_1(array, left, mid);
//		Qsort_1(array, mid + 1 , right);
//	}
//}

//int Parition_2(int* array, int left, int right)
//{
//	int begin = left;
//	int end = right - 1;
//	int key = array[right - 1];
//	int pt = right - 1;
//
//	while (begin < end)
//	{
//		while (begin < end && array[begin] <= key)
//			begin++;
//
//		if (begin < end)
//		{
//			array[pt] = array[begin];
//			pt = begin;
//		}
//
//		while (begin < end && array[end] >= key)
//			end--;
//
//		if (begin < end)
//		{
//			array[pt] = array[end];
//			pt = end;
//		}
//	}
//	array[begin] = key;
//
//	return begin;
//}
//void Qsort_2(int* array, int left, int right)
//{
//	int mid = 0;
//	if (left < right)
//	{
//		mid = Parition_2(array, left, right);
//		Qsort_2(array, left, mid);
//		Qsort_2(array, mid + 1, right);
//	}
//}

void heapst(int* array, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 <size && array[child] > array[child + 1])
			child ++;
		if (array[parent] > array[child])
			Swap(&array[parent], &array[child]);

		parent = child;
		child = parent * 2 + 1;
	}
}
void HeapSort(int* array, int size)
{
	int parent = (size-2) / 2;
	for (int i = parent; i >= 0; i--)
	{
		heapst(array, size, i);
	}
	for (int i = size - 1; i > 0; i--)
	{
		Swap(&array[0], &array[i]);
		heapst(array, i, 0);
	}
}


int main()
{
	int array[10] = { 3, 0, 9, 6, 1, 7, 2, 4, 8, 5 };
	int size = sizeof(array) / sizeof(array[0]);

	Print(array, size);
	//MergeSort(array, size);
	//Qsort_2(array, 0, size);
	HeapSort(array, size);
	Print(array, size);

	return 0;
}


 