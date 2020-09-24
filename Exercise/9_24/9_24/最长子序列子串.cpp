#include <iostream>
#include <string>
#include <vector>
using namespace std;

//最长公共子序列
string LCSeq(string& s1, string& s2)
{
	return "";
}

//最长公共子串
string LCSub(string& s1, string& s2)
{
	if (s1.empty() || s2.empty()) return "";
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
	int pos = 0;
	int size = 0;
	for (int i = 0; i < s1.size(); ++i)
	{
		for (int j = 0; j < s2.size(); ++j)
		{
			if (s1[i] == s2[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = 0;
			if (dp[i + 1][j + 1] > size)
			{
				size = dp[i + 1][j + 1];
				pos = i;
			}
		}
	}
	return s1.substr(pos - size + 1, size);
}



int main()
{
	string s1 = "1A2C3D4B56";
	string s2 = "1A23CA45B6A";
	cout << LCSeq(s1, s2) << endl;
	cout << LCSub(s1, s2) << endl;

	return 0;
}