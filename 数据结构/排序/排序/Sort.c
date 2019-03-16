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
//��������
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
			array[k + 1] = temp;//���ȼ���array[j] = temp����i��jλ���ϵ�Ԫ�ؽ���
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
		//�ҳ���Ҫת����Ԫ�ص�λ��
		while (n >= 0 && array[n] > key)
		{
			array[n + 1] = array[n];
			n--;
		}
		array[n+1] = key;
	}
}
//ϣ������
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
//ѡ������
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
		Swap(&(array[max]), &(array[last]));
		last--;
	}
}
//������
void HeapAdjust(int* array, int size, int parent)//���µ���
{
	//�ҳ�����
	int child = (parent * 2) + 1;
	while (child < size)
	{
		//�ҳ����Һ�������С��
		if (child + 1 < size && array[child] > array[child + 1])
			child += 1;
		//�жϸ��ڵ����С���ӵĴ�С
		if (array[parent] > array[child])
			Swap(&array[parent], &array[child]);
		parent = child;
		child = (parent * 2) + 1;
		
	}
}
void HeapSort(int* array, int size)
{
	int n = size - 1;
	//������(���µ���)
	int parent = 0;
	int root = (size - 2) / 2;
	for (; root >= 0; root--)
	{
		HeapAdjust(array, size, root);
	}
	//����---�ѵ�ɾ��
	while (n > 0)
	{
		Swap(&array[0], &array[n]);
		HeapAdjust(array, n, 0);
		n--;
	}
}
//ð������
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
//��������
//1.0
int Partition(int* array, int left, int right)
{

}
void QSort(int* array, int left, int right)
{
	int mid = 0;
	if (left < right)
	{
		mid = Partition(array, left, right);
		Qsort(array, 0, left - 1);
		Qsort(array, left + 1, right);
	}
	
}
//2.0 �ڿӷ�
//����ȡ�з�
int TakeMid(int a, int b, int c)
{
	if (a > b && a > c)
	{
		if (b > c)
			return b;
		else
			return c;
	}
	if (c > b && c > a)
	{
		if (a > b)
			return a;
		else
			return b;
	}
	if (b > a && b > c)
	{
		if (a > c)
			return a;
		else
			return c;
	}
}
void QSort(int* array, int begin,int end)
{
	int key = TakeMid(array[0], array[end], array[(end - 1) / 2]);

}//3.0 ǰ��ָ�뷨
//����ȡ�з�
int TakeMid(int a, int b, int c)
{
	if (a > b && a > c)
	{
		if (b > c)
			return b;
		else
			return c;
	}
	if (c > b && c > a)
	{
		if (a > b)
			return a;
		else
			return b;
	}
	if (b > a && b > c)
	{
		if (a > c)
			return a;
		else
			return c;
	}
}
void QSort(int* array, int begin ,int end)
{
	int key = TakeMid(array[0], array[begin - 1], array[(begin - 1) / 2]);
	int left = begin;
	int right = &array[end];
	while ();
}
//�鲢����
void merge(int* a, int asize, int* b, int bsize)
{

}
void MergeSort(int* array, int size)
{
	//1.0  ������ǰ�����
	//���ִ��ֽ��
	//����߽���MergeSort
	//���ұ߽���MergeSort

	//2.0
	//ֱ�Ӵ���С������й鲢

	
}
