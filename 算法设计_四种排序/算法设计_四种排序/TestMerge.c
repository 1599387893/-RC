//#include<stdio.h>
//#include<malloc.h>
//
//int* Merge(int* a, int* b, int s1, int s2)
//{
//	int* ret = (int*)malloc(sizeof(int*)* (s1 + s2));
//	int retPos = 0;
//	int aPos = 0;
//	int bPos = 0;
//	while (aPos < s1 && bPos < s2)
//	{
//		if (a[aPos] > b[bPos])
//			ret[retPos++] = b[bPos++];
//		else
//			ret[retPos++] = a[aPos++];
//	}
//	while (aPos < s1)
//		ret[retPos++] = a[aPos++];
//	while (bPos < s2)
//		ret[retPos++] = b[bPos++];
//	return ret;
//}
//
//int main()
//{
//	int a[] = { 0, 2, 4, 6, 8, 10 };
//	int b[] = { 1, 3, 5, 7, 9, 11 };
//	int aSize = sizeof(a) / sizeof(a[0]);
//	int bSize = sizeof(b) / sizeof(b[0]);
//	int* ret = NULL;
//	ret = Merge(a, b, aSize, bSize);
//
//	return 0;
//}