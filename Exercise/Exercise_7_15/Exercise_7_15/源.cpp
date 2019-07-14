#include<iostream>
using namespace std;

void swap(int& a, int& b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}
void print(int* array, int len)
{
	for (int i = 0; i < len; ++i)
		cout << array[i] << " ";
	cout << endl;
}
void BoolenSort(int* array,int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = i; j < len; ++j)
		{
			if (array[i]>array[j])
				swap(array[i], array[j]);
		}
	}
}
int Partion(int* array)
{

}
void Qsort(int* array, int start,int end)
{
	int key = Partion(array);
	Qsort(array, start, key - 1);
	Qsort(array, key + 1,end);
}
int main()
{
	int array[] = { 5, 4, 7, 0, 9, 6, 1, 8, 2, 3 };
	int len = sizeof(array) / sizeof(array[0]);
	print(array, len);
	BoolenSort(array, len);
	print(array, len);
	return 0;
}