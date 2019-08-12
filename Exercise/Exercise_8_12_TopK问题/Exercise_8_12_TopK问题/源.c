#if 0

#include<stdio.h>
#include<stdbool.h>
//小根堆
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
	//插入：
	//插入到数组的最后，将插入位置的父节点进行向下调整
	
	return true;
}
bool erase()
{
	//删除：
	//将第一个元素与最后一个元素交换，将交换后的最后一个元素删除之后，从第一个元素的位置进行依次向下调整
	return true;
}
int main()
{
	int arr[10] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = size / 2 - 1; i >= 0; --i)
	{
		//向下调整
		AjustDown(arr,i,size);
	}
	insert(&arr,10);
	erase();
	

	return 0;
}
#endif


