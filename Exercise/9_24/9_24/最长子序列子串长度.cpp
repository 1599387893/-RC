#if 0
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//最长公共子序列
int LCSeqL(string& s1, string& s2)
{
	if (s1.empty() || s2.empty()) return 0;
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
	for (int i = 1; i <= s1.size(); ++i)
	{
		for (int j = 1; j <= s2.size(); ++j)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp.back().back();
}

//最长公共子串
int LCSubL(string& s1, string& s2)
{
	if (s1.empty() || s2.empty()) return 0;
	int res = 0;
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
	for (int i = 0; i < s1.size(); ++i)
	{
		for (int j = 0; j < s2.size(); ++j)
		{
			if (s1[i] == s2[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = 0;
			res = max(res, dp[i + 1][j + 1]);
		}
	}
	return res;
}

int main()
{
	string s1 = "1A2C3D4B56";
	string s2 = "1A23CA45B6A";
	cout << LCSeqL(s1, s2) << endl;
	cout << LCSubL(s1, s2) << endl;

	return 0;
}


#endif