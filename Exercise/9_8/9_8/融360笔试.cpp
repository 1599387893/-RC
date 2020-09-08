#if 0
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int CheckPassWord(string& s)
{
	if (s.size() < 8 || s.size() > 120)
		return 1;
	unordered_map<int, bool> type; //记录不同类型
	type[0] = false;//数字
	type[1] = false;//符号
	type[2] = false;//大写字母
	type[3] = false;//小写字母
	int countType = 0;
	for (auto c : s)
	{
		if (isdigit(c))
		{
			if (type[0] == false)
			{
				type[0] = true;
				countType++;
			}
		}
		else if (isupper(c))
		{
			if (type[2] == false)
			{
				type[2] = true;
				countType++;
			}
		}
		else if (islower(c))
		{
			if (type[1] == false)
			{
				type[1] = true;
				countType++;
			}
		}
		else
		{
			if (type[3] == false)
			{
				type[3] = true;
				countType++;
			}
		}
		if (countType == 4)
			break;
	}
	return countType == 4 ? 0 : 2;
}
int main()
{
	string s;
	while (cin >> s)
		cout << CheckPassWord(s) << endl;
	return 0;
}


#include <iostream>
#include <string>
using namespace std;

int main()
{
	strig str;
	cin >> str;
	cout << true << endl;
	return 0;
}
#endif

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool InMap(vector<vector<char>>& arr, string& s, int strPos, int row, int col)
{
	if (strPos == s.size())
		return true;
	if (row < 0 || row >= arr.size() || col < 0 || col >= arr[0].size())
		return false;
	if (row >= 0 && row < arr.size() && col >= 0 && row < arr[0].size())
		if (arr[row][col] != s[strPos])
			return false;
	char temp = arr[row][col];
	arr[row][col] = '0';
	if (row + 1 < arr.size())
		if (InMap(arr, s, strPos + 1, row + 1, col))
			return true;
	if (row - 1 >= 0)
		if (InMap(arr, s, strPos + 1, row - 1, col))
			return true;
	if (col + 1 < arr[0].size())
		if (InMap(arr, s, strPos + 1, row, col + 1))
			return true;
	if (row - 1 >= 0)
		if (InMap(arr, s, strPos + 1, row, col - 1))
			return true;
	arr[row][col] = temp;
	return false;
}
int main()
{
	vector<vector<char>> arr{ { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } };
	string str;
	cin >> str;
	for (int i = 0; i < arr.size(); ++i)
		for (int j = 0; j < arr[0].size(); ++j)
			if (arr[i][j] == str[0])
				if (InMap(arr, str, 0, i, j))
				{
					cout << "true" << endl;
					return 0;
				}
	cout << "false" << endl;
	return 0;
}