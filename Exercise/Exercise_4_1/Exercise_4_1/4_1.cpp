#include<iostream>
using namespace std;


void Print(int* array, int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}
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

	while (begin1 < end1)
		temp[index++] = array[begin1++];
	while (begin2 < end2)
		temp[index++] = array[begin2++];
}
void MergeSort(int* array, int size)
{
	int* temp = new int[10];
	int gap = 1;
	while (gap < size)
	{
		for (int i = 0; i < size; i += gap * 2)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;

			if (mid > size)
				mid = size;
			if (right > size)
				right = size;

			MergeData(array, left, mid, right, temp);

		}
		memcpy(array, temp, sizeof(int)*size);
		gap *= 2;
	}
	delete[] temp;
	temp = nullptr;
}
int main()
{
	int* array = new int[10]{2,0,3,9,5,6,1,7,4,8};
	int size = 10;
	Print(array, size);
	MergeSort(array, size);
	Print(array, size);


	delete[] array;

	return 0;
}
