class Solution {
public:
	//G(n): 长度为 nn 的序列能构成的不同二叉搜索树的个数。
    //F(i, n)F(i, n) : 以i为根、序列长度为n的不同二叉搜索树个数(1≤i≤n)
    //综合两个公式可以得到 卡特兰数 公式
	//	G(n) = G(0)*G(n - 1) + G(1)*(n - 2) + ... + G(n - 1)*G(0)G(n) = G(0)∗G(n−1) + G(1)∗(n−2) + ... + G(n−1)∗G(0)
	int numTrees(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; ++i)
			for (int j = 1; j <= i; ++j)
				dp[i] += dp[j - 1] * dp[i - j];
		return dp.back();
	}
};