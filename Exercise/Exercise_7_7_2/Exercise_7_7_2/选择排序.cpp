#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int array[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 0 };
	int len = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < len; ++i)
	{
		int min = i;
		for (int j = i + 1; j < len; ++j)
			if (array[min]>array[j])
				min = j;
		if (min != i)
			std::swap(array[min], array[i]);
	}
	for (int i = 0; i < len; ++i)
		cout << array[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}