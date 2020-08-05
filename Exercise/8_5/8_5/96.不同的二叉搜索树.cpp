
//ʱ�临�Ӷȹ���
class Solution {
public:
	//G(i)����ʾ��i��Ϊ���ڵ�Ķ����������ĸ���
	//���У�G(i)��ֵ�����������ĸ���(1��(i-1)�ڵ�) * �������ĸ���((i+1) �� n)
	int CountSubTree(int begin, int end, int n)
	{
		if (end < begin)
			return 1;
		int res = 0;
		//ѡȡ��ͬ��Ԫ����Ϊ���ڵ�
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
	//G(i)����ʾi���ڵ㹹�ɵĶ����������ĸ���  G(i) = F(1) + F(2) + F(3) + ... + F(n)
	//F(i): ��ʾ��i��Ϊ���ڵ�Ķ����������ĸ��� F(i) = G(i-1) * G(n-i);
	//�����ʽҲ��������������ʽ
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
