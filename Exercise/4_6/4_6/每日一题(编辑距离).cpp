//���word1��word2�Ĳ���һ����6�֣�
//������ֻ�����֣�
//		1.�ڵ���A�в���һ���ַ�
//		2.�ڵ���B�в���һ���ַ�
//		3.�޸ĵ���A��һ���ַ�

//��̬ת�Ʒ����У�
//		dp[i][j-1]+1��ʾ�ڵ���A��ĩβ���һ���ַ���
//		dp[i-1][j]+1��ʾ�ڵ���B��ĩβ���һ���ַ���
//		dp[i-1][j-1]��ʾ�޸ĵ���A���ַ�����ʱ��Ҫ�ж��Ƿ���Ҫ�޸ģ������ǰA���ַ���B���ַ���ȣ���ô����Ҫ+1��������Ҫ��dp[i-1][j-1]+1;


class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size();
		int m = word2.size();
		if (n * m == 0)
			return n + m;
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		//��ʼ��dp
		for (int i = 0; i <n + 1; ++i)
			dp[i][0] = i;
		for (int i = 0; i < m + 1; ++i)
			dp[0][i] = i;
		//״̬ת�Ʒ���
		//word1[i]==word[2]ʱ�� dp[i][j] = 1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]-1) = min(dp[i][j-1]+1,dp[i-1][j]+1,dp[i-1][j-1]) ;
		//word1[i]!=word[2]ʱ�� dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);

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