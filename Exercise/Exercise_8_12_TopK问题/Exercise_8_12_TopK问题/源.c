#if 0

#include<stdio.h>
#include<stdbool.h>
//С����
void swap(int* a,int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void AjustDown(int* arr, int parent, int size)
{
	int children = parent * 2 + 1;
	while (children < size)
	{
		if (children + 1<size && arr[children] > arr[children + 1])
			children = children + 1;
		if (arr[parent] > arr[children])
			swap(&arr[parent], &arr[children]);
		parent = children;
		children = parent * 2 + 1;
	}

}
bool insert(int** arr,int key)
{
	//���룺
	//���뵽�������󣬽�����λ�õĸ��ڵ�������µ���
	
	return true;
}
bool erase()
{
	//ɾ����
	//����һ��Ԫ�������һ��Ԫ�ؽ�����������������һ��Ԫ��ɾ��֮�󣬴ӵ�һ��Ԫ�ص�λ�ý����������µ���
	return true;
}
int main()
{
	int arr[10] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = size / 2 - 1; i >= 0; --i)
	{
		//���µ���
		AjustDown(arr,i,size);
	}
	insert(&arr,10);
	erase();
	

	return 0;
}
#endif


