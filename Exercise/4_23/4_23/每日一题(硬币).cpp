class Solution {
public:
	vector<int> coins{ 25, 10, 5, 1 };
	int waysToChange(int n) {
		vector<int> dp(n + 1);
		dp[0] = 1;
		for (int i = 0; i < coins.size(); ++i)
			for (int j = coins[i]; j <= n; ++j)
				dp[j] = (dp[j] + dp[j - coins[i]]) % 1000000007;
		return dp[n];
	}
};

//动态规划
//先循环硬币面值，这样不会产生重复解
//dp[i] = dp[i]+dp[i-面值]