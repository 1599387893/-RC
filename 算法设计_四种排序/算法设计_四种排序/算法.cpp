#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>
#include<stdlib.h>


//��������
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

//������
//���µ���
void AdjustDown(int* array, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//�ҵ����Һ�����С��
		if (child + 1 < size && array[child] > array[child + 1])
		{
			child++;
		}
		//�ж���С������˫�׽��Ĵ�С
		if (array[parent] > array[child])
			Swap(&(array[parent]), &(array[child]));
		parent = child;
		child = parent * 2 + 1;
	}
}
void HeapSort(int* array, int size)
{
	//�ҵ����һ����Ҷ�ӽ��
	int root = (size - 2) / 2;
	//���µ���(����һ�ε���һ��)
	for (; root >= 0;root--)
		AdjustDown(array, size, root);

	//����(��ɾ��)
	while (size > 0)
	{
		Swap(&(array[0]), &(array[--size]));
		AdjustDown(array, size, 0);
	}
}
//�鲢����
//ԭ��
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
	int right1 = mid;//ǰ�벿��
	int left2 = mid + 1;
	int right2 = right;//��벿��

	int Pos1 = left;//ǰ�벿�ֵ�λ�ñ��
	int Pos2 = mid + 1;//��벿�ֵ�λ�ñ��
	int Pos = 0;

	int size1 = right1 - left1;//ǰ�벿�ֵĳ���
	int size2 = right2 - left2;//��벿�ֵĳ���

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
	//array�����е�Ԫ���Ѿ����մ����Ž�temp������
	
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
//ϣ������
void ShellSort(int* array, int size)
{
	int gap = 3;
	while (gap)
	{
		for (int i = gap; i < size; i+=gap)
		{
			int cur = array[i];
			int j = i - gap;
			//�ҵ���i֮ǰ�ĺ������бȴ�����ֵС��λ��
			for (; j >= 0 && array[j] > cur; j-=gap)
				Swap(&(array[j]), &(array[j + gap]));
			//�ҵ�λ�ú����
			array[j + gap] = cur;
		}
		gap--;
	}
	
}
//��������
int Partition(int* array, int left, int right)
{
	int key = array[right-1];
	int begin = left;
	int end = right-1;
	while (begin < end)
	{
		//�ȴ��������ҳ��Ȼ�׼ֵ���Ԫ��
		while (array[begin] < key)
			begin++;
		//���������ҳ��Ȼ�׼ֵС��Ԫ��
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
	//������
	//HeapSort(array, size);
	//Print(array, size);

	//�鲢����
	//GergeSort(array, 0,size );
	//Print(array, size);

	//ϣ������
	//ShellSort(array, size);
	//Print(array, size);

	//��������
	QuickSort(array, 0, size);
	Print(array, size);

	system("pause");
	return 0;
}