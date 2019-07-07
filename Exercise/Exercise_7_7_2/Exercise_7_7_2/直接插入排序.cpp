//÷±Ω”≤Â»Î≈≈–Ú
#if 0
#include<iostream>
using namespace std;

int main()
{
	int array[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3 ,0};
	int len = sizeof(array) / sizeof(array[0]);
	for (int i = 1; i < len; ++i)
	{
		int end = i - 1;
		int key = array[i];
		while(key < array[end] && end >= 0)
		{
			array[end+1] = array[end];
			end--;
		}
		array[end+1] = key;
	}
	for (int i = 0; i < len; ++i)
		cout << array[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
#endif