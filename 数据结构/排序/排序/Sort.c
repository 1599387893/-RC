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
	int begin = left;
	int end = right - 1;
	int key = array[right - 1];

	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
			begin++;
		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
			Swap(&array[begin], &array[end]);
	}
	if (array[begin] != key)
		Swap(&array[begin], &array[right - 1]);

	return begin;
}
void QSort_1(int* array, int left, int right)
{
	int mid = 0;
	if (left < right)
	{
		mid = Parition(array, left, right);
		Qsort(array, left, mid);
		Qsort(array, mid + 1, right);
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


int merge(int r[], int s[], int x1, int x2, int x3)    //自定义实现一次归并样序的函数
{
	int i, j, k;
	i = x1;    //第一部分的开始位置
	j = x2 + 1;  //第二部分的开始位置
	k = x1;
	while ((i <= x2) && (j <= x3))    //当i和j都在两个要合并的部分中时
	if (r[i] <= r[j])    //筛选两部分中较小的元素放到数组s中
	{
		s[k] = r[i];
		i++;
		k++;
	}
	else
	{
		s[k] = r[j];
		j++;
		k++;
	}
	while (i <= x2)    //将x1〜x2范围内未比较的数顺次加到数组r中
		s[k++] = r[i++];
	while (j <= x3) //将x2+l〜x3范围内未比较的数顺次加到数组r中
		s[k++] = r[j++];
	return 0;
}
int merge_sort(int r[], int s[], int m, int n)
{
	int p;
	int t[20];
	if (m == n)
		s[m] = r[m];
	else
	{
		p = (m + n) / 2;
		merge_sort(r, t, m, p);    //递归调用merge_soit()函数将r[m]〜r[p]归并成有序的t[m]〜t[p]
		merge_sort(r, t, p + 1, n);    //递归一调用merge_sort()函数将r[p+l]〜r[n]归并成有序的t[p+l]〜t[n]
		merge(t, s, m, p, n);    //调用函数将前两部分归并到s[m]〜s[n】*/
	}
	return 0;
}

//归并排序（非递归）
void MergeData(int* array, int left, int mid, int right, int* temp)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid;
	int end2 = right;
	int index = left;

	while (begin1 < end1 && begin2 < end2)
	{
		if (array[begin1] < array[begin2])
			temp[index++] = array[begin1++];
		else
			temp[index++] = array[begin2++];
	}
	while (begin1<end1)
		temp[index++] = array[begin1++];
	while (begin2<end2)
		temp[index++] = array[begin2++];



}
void MergeSortNor(int* array, int size)
{
	int* temp = (int*)malloc(sizeof(int)* 10);
	int gap = 1;
	while (gap < size)
	{
		for (int i = 0; i < size; i += gap * 2)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;

			if (mid >size)
				mid = size;
			if (right>size)
				right = size;
			MergeData(array, left, mid, right, temp);
		}
		memcpy(array, temp, sizeof(int)* 10);
		gap *= 2;
	}
}