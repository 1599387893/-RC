// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> v;
int find_way(int row, int col, char from)
{
	if (row == 9 && col == 8)
		return 1;
	int left = 0, right = 0, up = 0, down = 0;
	if (from != 'l' && col + 1<10 && v[row][col + 1] != '#')
		right = find_way(row, col + 1, 'l');
	if (from != 'r' && col - 1 >= 0 && v[row][col - 1] != '#')
		left = find_way(row, col - 1, 'r');
	if (from != 'd' && row + 1<10 && v[row + 1][col] != '#')
		down = find_way(row + 1, col, 'u');
	if (from != 'u' && row - 1 >= 0 && v[row - 1][col] != '#')
		up = find_way(row - 1, col, 'd');
	if (right == left == up == down == 0)
		return -1;
	//判断其中三条路径中的最小值；
	int min = 100;
	if (left>0 && left<min)
		min = left;
	if (right>0 && right<min)
		min = right;
	if (up>0 && up<min)
		min = up;
	if (down>0 && down<min)
		min = down;
	return min + 1;
}
int main()
{
	string row;
	while (cin >> row)
	{
		v.push_back(row);
		for (int i = 1; i<10; ++i)
		{
			cin >> row;
			v.push_back(row);
		}
		cout << find_way(0, 1, 'u') << endl;
		v.clear();
	}
}