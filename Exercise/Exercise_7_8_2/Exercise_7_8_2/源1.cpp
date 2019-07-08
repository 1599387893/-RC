#include<iostream>
using namespace std;

bool Find(int* arr, int row, int col, int key)
{
	int r = 0;
	int c = col - 1;
	while (c >= 0 && r < 4)
	{
		int pos = arr[r*col + c];
		if (key == pos)
			return true;
		else if (key < pos)
			c--;
		else
			r++;
	}
	return false;
}
int main()
{
	int array[] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	int row = 4;
	int col = 4;
	int key;
	cin >> key;
	cout << Find(array, row, col, key)<<endl;
	return 0;
}