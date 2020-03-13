#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int res = 0;
		vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
		for (int i = 1; i <= s1.size(); ++i)
		{
			for (int j = 1; j <= s2.size(); ++j)
			{
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > res)
					res = dp[i][j];
			}
		}
		cout <<res << endl;
	}
	return 0;
}