#if 0
#include<iostream>
using namespace std;

int main()
{
	int array[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 0 };
	int len = sizeof(array) / sizeof(array[0]);
	int gap = 3;
	while (gap >= 1)
	{
		for (int i = 0; i < len; i += gap)
		{
			int end = i - gap;
			int key = array[i];
			while (key < array[end] && end >= 0)
			{
				array[end + gap] = array[end];
				end-=gap;
			}
			array[end + gap] = key;
		}
		gap--;
	}
	for (int i = 0; i < len; ++i)
		cout << array[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
#endif