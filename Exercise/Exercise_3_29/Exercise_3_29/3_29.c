//#include<stdio.h>
//
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
////练习2
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};
////练习3
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
////练习4-结构体嵌套问题
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	printf("%d\n", sizeof(struct S3));
//	printf("%d\n", sizeof(struct S4));
//
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//void MergeData(int* array, int left, int mid, int right, int* temp)
//{
//	int begin1 = left;
//	int end1 = mid;
//	int begin2 = mid ;
//	int end2 = right;
//	int index = left;
//
//	while (begin1 < end1 && begin2 < end2)
//	{
//		if (array[begin1] <= array[begin2])
//			temp[index++] = array[begin1++];
//		else
//			temp[index++] = array[begin2++];
//	}
//	while (begin1 < end1)
//		temp[index++] = array[begin1++];
//	while (begin2 < end2)
//		temp[index++] = array[begin2++];
//}
//
//void _MergeSort(int* array, int left, int right, int* temp)
//{
//	if (left +1  < right)
//	{
//		int mid = left + (right - left) / 2;
//		_MergeSort(array, left, mid, temp);
//		_MergeSort(array,mid, right, temp);
//		MergeData(array, left, mid, right, temp);
//		memcpy(array + left, temp + left,(right - left));
//	}
//}
//
//void MergeSort(int* array, int size)
//{
//	int* temp = (int*)malloc(sizeof(array[0])*size);
//	_MergeSort(array, 0, size, temp);
//	free(temp);
//}
//
//void Print(int* array, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int array[10] = { 2, 6, 9, 1, 7, 0, 5, 3, 4, 8 };
//	int size = sizeof(array) / sizeof(array[0]);
//	Print(array, size);
//	MergeSort(array, size);
//	Print(array, size);
//
//	return 0;
//}

#include<stdio.h>
#include<malloc.h>
#include<string.h>

void Print(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void MergeData(int* array, int left, int mid, int right, int* temp)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid ;
	int end2 = right;
	int index = left;

	while (begin1 < end1 && begin2 < end2)
	{
		if (array[begin1] <= array[begin2])
			temp[index++] = array[begin1++];
		else
			temp[index++] = array[begin2++];
	}

	while (begin1 < end1)
		temp[index++] = array[begin1++];

	while (begin2 < end2)
		temp[index++] = array[begin2++];
}
void MergeSortNor(int* array, int size)
{
	int* temp = (int*)malloc(sizeof(array[0])*size);

	int gap = 1;
	while (gap < size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;

			//防止越界
			if (mid > size)
				mid = size;
			if (right > size)
				right = size;

			MergeData(array, left, mid, right, temp);
		}
		memcpy(array, temp, size*sizeof(array[0]));
		gap *= 2;
	}
	free(temp);
}

int main()
{
	int array[10] = { 2, 6, 9, 1, 7, 0, 5, 3, 4, 8 };
	int size = sizeof(array) / sizeof(array[0]);
	Print(array, size);
	MergeSortNor(array, size);
	Print(array, size);

	return 0;
}
