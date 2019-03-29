//#include<stdio.h>
//
//
//
//void Merge(int* array, int left, int mid, int right, int* temp)
//{
//	int begin1 = left;
//	int end1 = mid;
//	int begin2 = mid;
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
//int main()
//{
//	int array[10] = { 0,2,4,6,8,1,3,5,7,9 };
//	int size = sizeof(array) / sizeof(array[0]);
//	int temp[10] = { 0 };
//	Merge(array, 0,5,size,temp);
// 
//
//	return 0;
//}