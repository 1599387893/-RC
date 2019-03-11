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
	for (int i = 1; i < size; i++)
	{
		for (int j = i - 1; j >= 0;j--)
		{
			if (array[j] > array[i])
			{
				Swap(&(array[i]), (&array[j]));
				i = j;
			}
		}
	}
}
//ϣ������
void ShellSort(int* array, int size)
{
	///*int gap = 5;
	//for (int i = 0; i < size; i++)
	//{
	//	for (int j = gap; j < size; j++)
	//	{
	//		if (j + gap < size && array[j] < array[j + gap])
	//			Swap(&array[j], &array[j + gap]);
	//	}
	//	gap--;
	//}*/
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
void QSort(int* array, int size)
{

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
