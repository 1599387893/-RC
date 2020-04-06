//针对word1和word2的操作一共有6种，
//本质上只有三种：
//		1.在单词A中插入一个字符
//		2.在单词B中插入一个字符
//		3.修改单词A的一个字符

//动态转移方程中：
//		dp[i][j-1]+1表示在单词A的末尾添加一个字符；
//		dp[i-1][j]+1表示在单词B的末尾添加一个字符；
//		dp[i-1][j-1]表示修改单词A的字符，此时需要判断是否需要修改，如果当前A的字符和B的字符相等，那么不需要+1，否则需要给dp[i-1][j-1]+1;


class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size();
		int m = word2.size();
		if (n * m == 0)
			return n + m;
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		//初始化dp
		for (int i = 0; i <n + 1; ++i)
			dp[i][0] = i;
		for (int i = 0; i < m + 1; ++i)
			dp[0][i] = i;
		//状态转移方程
		//word1[i]==word[2]时， dp[i][j] = 1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]-1) = min(dp[i][j-1]+1,dp[i-1][j]+1,dp[i-1][j-1]) ;
		//word1[i]!=word[2]时， dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				int l = dp[i - 1][j] + 1;
				int d = dp[i][j - 1] + 1;
				int ld = dp[i - 1][j - 1];
				if (word1[i - 1] != word2[j - 1]) ld += 1;
				dp[i][j] = min(l, min(d, ld));
				//dp[i][j] = min(dp[i][j],d);
			}
		}
		return dp[n][m];
	}
};