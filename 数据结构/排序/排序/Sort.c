#include"Sort.h"

void Print(int* array,int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//插入排序
void InsertSort(int* array, int size)
{
	int i = 0,j = 0,k = 0;
	for (i = 1; i < size; i++)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (array[j] < array[i])
				break;
		}
		if (j != i - 1)//?
		{
			int temp = array[i];
			for (k = i - 1; k > j; k--)
				array[k + 1] = array[k];
			array[k + 1] = temp;//不等价于array[j] = temp，将i和j位置上的元素交换
		}
		
	}
	//1.0
	//for (int i = 1; i < size; i++)
	//{
	//	for (int j = i - 1; j >= 0;j--)
	//	{
	//		if (array[j] > array[i])
	//		{
	//			Swap(&(array[i]), (&array[j]));
	//			i = j;
	//		}
	//	}
	//}
}
void InsertSort_2(int* array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = array[i];
		int n = i - 1;
		//找出需要转换的元素的位置
		while (n >= 0 && array[n] > key)
		{
			array[n + 1] = array[n];
			n--;
		}
		array[n+1] = key;
	}
}
//希尔排序
void ShellSort(int* array, int size)
{
	int gap = 3;
	int i, j, k;
	while (gap > 0)
	{
		for (i = gap; i < size; i += gap)
		{
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (array[j] < array[i])
					break;
			}
			if (j != i - gap)
			{
				int temp = array[i];
				for (k = i - gap; k > j; k-=gap)
				{
					array[k + gap] = array[k];
				}
				array[k + gap] = temp;
			}
		}
		gap--;
	}
	
}


//选择排序
void SelectionSort(int* array, int size)
{
	int max = 0;
	int last = size - 1;
	while (last)
	{
		max = 0;
		for (int i = 1; i <= last; i++)
		{
			if (array[max] < array[i])
				max = i;
		}
		if (max != last)
			Swap(&(array[max]), &(array[last]));
		last--;
	}
}
void SelectionSort_2(int* array, int size)
{
	int max = 0;
	int min = 0;
	int last = size - 1;
	int begin = 0;
	while (last >= begin)
	{
		max = begin;
		min = begin;
		for (int i = begin+1; i <= last; i++)
		{
			if (array[max] < array[i])
				max = i;
			if (array[min] > array[i])
				min = i;
		}
		if (min != begin)
			Swap(&array[min], &array[begin]);
		//判断最大和最小元素在需要互换的位置
		if (begin == max)
			max = min;

		if (max != last)
			Swap(&(array[max]), &(array[last]));
		begin++;
		last--;
	}
}
//堆排序
void HeapAdjust(int* array, int size, int parent)//向下调整
{
	//找出左孩子
	int child = (parent * 2) + 1;
	while (child < size)
	{
		//找出左右孩子中最小的
		if (child + 1 < size && array[child] > array[child + 1])
			child += 1;
		//判断根节点与较小孩子的大小
		if (array[parent] > array[child])
			Swap(&array[parent], &array[child]);
		parent = child;
		child = (parent * 2) + 1;
		
	}
}
void HeapSort(int* array, int size)
{
	int n = size - 1;
	//创建堆(向下调整)
	int parent = 0;
	int root = (size - 2) / 2;
	for (; root >= 0; root--)
	{
		HeapAdjust(array, size, root);
	}
	//排序---堆的删除
	while (n > 0)
	{
		Swap(&array[0], &array[n]);
		HeapAdjust(array, n, 0);
		n--;
	}
}


//冒泡排序
void BubbleSort(int* array, int size)
{
	int flag = 1;
	for (int i = 0; i < size-1 && flag != 0; i++)
	{
		flag = 0;
		for (int j = 0; j < size-i-1; j++)
		{
			if (array[j] > array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
				flag = 1;
			}
		}
	}

}
//快速排序

//1.0 hoare法
int Partition_1(int* array, int left, int right)
{
	int key = array[right];//取一个基准值
	int begin = left;
	int end = right;
	while (begin < end)
	{
		//从左往右找比基准值大的元素
		while (array[begin] < key)
			begin++;
		//从右往左找不基准值小的元素
		while (array[end] > key)
			end--;
		//交换
		if (begin < end)
			Swap(&(array[begin]), &(array[end]));
	}
	if (array[begin] != key)
		Swap(&(array[begin]), &key);

	return begin;
}

void QSort_1(int* array, int left, int right)
{
	int mid = 0;
	if (left < right)
	{
		mid = Partition_1(array, left, right);
		QSort_1(array, 0, left - 1);
		QSort_1(array, left + 1, right);
	}
	
}

//2.0 挖坑法
int Partition_2(int* array, int left, int right)
{
	int key = array[right];
	int begin = left;
	int end = right;
	while (begin < end)
	{
		//先从前往后找比基准值大的元素
		while (begin < end && array[begin] <= key)
			begin++;
		
		//找到了比基准值大的元素
		if (begin < end)
			//填坑
			array[end--] = array[begin];
		
		//再从后往前找比基准值小的元素
		while (end > begin && array[end] >= key)
			end--;

		if (begin < end)
			//填上一次的坑
			array[begin++] = array[end];
	}
	array[begin] = key;

	return begin;
}
void QSort_2(int* array, int left, int right)
{
	int mid = 0;
	if (left < right)
	{
		mid = Partition_2(array, left, right);
		QSort_2(array, left, mid - 1);
		QSort_2(array, mid + 1, right);
	}

}

//3.0 前后指针法
int Partition_3(int* array, int left, int right)
{
	int cur = left;
	int prev =cur - 1;
	int key = array[right-1];
	while (cur < right)
	{
		//找出比基准值小的元素,找到后++prev
		if (array[cur] < key && ++prev != cur)
			Swap(&array[cur], &array[prev]);

		++cur;
		
	}
	//防止访问越界
	if (++prev != right-1)
		Swap(&(array[prev]), &(array[right-1]));
	return prev;
}
void QSort_3(int* array, int left ,int right)
{
	while (right - left > 1)
	{
		int mid = Partition_3(array, left, right);
		QSort_3(array, left, mid);
		QSort_3(array, mid + 1, right);
	}
}




//归并排序
//void merge(int* a, int asize, int* b, int bsize)
//{
//
//}
//void MergeSort(int* array, int size)
//{
//	//1.0  类似于前序遍历
//	//险种处分界点
//	//将左边进行MergeSort
//	//将右边进行MergeSort
//
//	//2.0
//	//直接从最小分组进行归并
//
//	
//}





















////三数取中法
//int TakeMid(int a, int b, int c)
//{
//	if (a > b && a > c)
//	{
//		if (b > c)
//			return b;
//		else
//			return c;
//	}
//	if (c > b && c > a)
//	{
//		if (a > b)
//			return a;
//		else
//			return b;
//	}
//	if (b > a && b > c)
//	{
//		if (a > c)
//			return a;
//		else
//			return c;
//	}
//}
