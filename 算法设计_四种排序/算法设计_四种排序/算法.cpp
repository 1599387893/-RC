#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>


//辅助函数
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Print(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

//堆排序
//向下调整
void AdjustDown(int* array, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//找到左右孩子最小的
		if (child + 1 < size && array[child] > array[child + 1])
		{
			child++;
		}
		//判断最小孩子与双亲结点的大小
		if (array[parent] > array[child])
			Swap(&(array[parent]), &(array[child]));
		parent = child;
		child = parent * 2 + 1;
	}
}
void HeapSort(int* array, int size)
{
	//找到最后一个非叶子结点
	int root = (size - 2) / 2;
	//向下调整(调用一次调整一次)
	for (; root >= 0;root--)
		AdjustDown(array, size, root);

	//排序(堆删除)
	while (size > 0)
	{
		Swap(&(array[0]), &(array[--size]));
		AdjustDown(array, size, 0);
	}
}
//归并排序
//原型
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
//
//	return ret;
//}


void Merge(int* array,int left,int right,int mid)
{
	int* temp = (int*)malloc(sizeof(int)*(right - left + 1));

	if (NULL == temp)
		assert("mlloc fail!\n");

	int left1 = left;
	int right1 = mid;//前半部分
	int left2 = mid + 1;
	int right2 = right;//后半部分

	int Pos1 = left;//前半部分的位置标记
	int Pos2 = mid + 1;//后半部分的位置标记
	int Pos = 0;

	int size1 = right1 - left1;//前半部分的长度
	int size2 = right2 - left2;//后半部分的长度

	while (left1 <= right1 && left2 <= right2)
	{
		if (array[left1] >= array[left2])
			temp[Pos++] = array[left2++];
		else
			temp[Pos++] = array[left1++];
	}
	while (left1 <= right1)
		temp[Pos++] = array[left1++];
	while (left2 <= right2)
		temp[Pos++] = array[left2++];
	//array数组中的元素已经按照次序排进temp数组中
	
	memcpy(array, temp, sizeof(int)* (right - left + 1));
	free(temp);
	temp = NULL;

	return;
}
void GergeSort(int* array, int left, int right)
{
	
	if (left < right)
	{
		int mid = (left + right) / 2;
		GergeSort(array, 0,mid);
		GergeSort(array, mid + 1, right);
		Merge(array, left, right, mid);
	}
}
//希尔排序
void ShellSort(int* array, int size)
{
	int gap = 3;
	while (gap)
	{
		for (int i = gap; i < size; i+=gap)
		{
			int cur = array[i];
			int j = i - gap;
			//找到再i之前拍好序列中比待插入值小的位置
			for (; j >= 0 && array[j] > cur; j-=gap)
				Swap(&(array[j]), &(array[j + gap]));
			//找到位置后插入
			array[j + gap] = cur;
		}
		gap--;
	}
	
}
//快速排序
int Partition(int* array, int left, int right)
{
	int key = array[right-1];
	int begin = left;
	int end = right-1;
	while (begin < end)
	{
		//先从左向右找出比基准值大的元素
		while (array[begin] < key)
			begin++;
		//从右向左找出比基准值小的元素
		while (array[end]>key)
			end--;
		if (begin < end)
			Swap(&(array[begin]), &(array[end]));
	}
	if (array[begin] != key)
		//Swap(&(array[begin]), &(array[right - 1]));
		Swap(&(array[begin]), &key);
	return begin;

}
void QuickSort(int* array, int left,int right)
{
	int mid = 0;
	if (left < right)
	{
		mid = Partition(array,left, right);
		QuickSort(array, 0, mid-1);
		QuickSort(array, mid + 1,right);
	}
}


int main()
{
	int array[] = { 0, 8, 4, 9, 6, 1, 3, 7, 2, 5 };
	int size = sizeof(array) / sizeof(array[0]);
	Print(array, size);
	//堆排序
	//HeapSort(array, size);
	//Print(array, size);

	//归并排序
	//GergeSort(array, 0,size );
	//Print(array, size);

	//希尔排序
	//ShellSort(array, size);
	//Print(array, size);

	//快速排序
	QuickSort(array, 0, size);
	Print(array, size);

	system("pause");
	return 0;
}