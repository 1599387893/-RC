#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int LCS(string str1, string str2) {
	int m = str1.size();
	int n = str2.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
		}
	}
	return dp[str1.size()][str2.size()];
}
int main()
{
	map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(1, 5));
	string s1 = "1AB2345CD";
	string s2 = "12345EF";
	cout << LCS(s1, s2) << endl;
	return 0;
}