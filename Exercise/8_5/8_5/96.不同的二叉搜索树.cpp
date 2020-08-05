
//时间复杂度过大
class Solution {
public:
	//G(i)：表示以i作为根节点的二叉搜索数的个数
	//其中：G(i)的值就是左子树的个数(1到(i-1)节点) * 右子树的个数((i+1) 到 n)
	int CountSubTree(int begin, int end, int n)
	{
		if (end < begin)
			return 1;
		int res = 0;
		//选取不同的元素作为根节点
		for (int i = begin; i <= end; ++i)
			res += (CountSubTree(begin, i - 1, n) * CountSubTree(i + 1, end, n));
		return res;
	}
	int numTrees(int n) {
		return CountSubTree(1, n, n);
	}
};

class Solution {
public:
	//G(i)：表示i个节点构成的二叉搜索树的个数  G(i) = F(1) + F(2) + F(3) + ... + F(n)
	//F(i): 表示以i作为根节点的二叉搜索数的个数 F(i) = G(i-1) * G(n-i);
	//这个公式也叫做卡特兰数公式
	int numTrees(int n) {
		vector<int> dp(n + 1);
		dp[0] = 1;
		dp[1] = 1;

		for (int i = 2; i < n + 1; i++)
			for (int j = 1; j < i + 1; j++)
				dp[i] += dp[j - 1] * dp[i - j];

		return dp[n];
	}
};
