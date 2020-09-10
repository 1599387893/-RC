#if 0
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int LCS(string str1, string str2) {
	// write code here
	int res = 0;
	vector<vector<int>> temp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
	for (int i = 1; i <= str1.size(); ++i)
	{
		for (int j = 1; j <= str2.size(); ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				temp[i][j] = temp[i - 1][j - 1] + 1;
				res = max(res, temp[i][j]);
			}
			else
				temp[i][j] = 0;
		}
	}
	return res;
}
int main()
{
	string s1 = "1AB2345CD";
	string s2 = "12345EF";
	cout << LCS(s1, s2) << endl;
	return 0;
}
#endif