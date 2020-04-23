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

//��̬�滮
//��ѭ��Ӳ����ֵ��������������ظ���
//dp[i] = dp[i]+dp[i-��ֵ]