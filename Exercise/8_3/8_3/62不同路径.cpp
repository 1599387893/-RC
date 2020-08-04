class Solution {
public:
	int uniquePaths(int m, int n) {
		int res = 0;
		vector<int> prePath(m, 1);
		while (--n)
		{
			for (int i = 1; i < m; ++i)
			{
				prePath[i] += prePath[i - 1];
			}
		}
		return prePath[prePath.size() - 1];
	}
};


class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m == 1 || n == 1)
			return 1;
		if (m > n)
			swap(m, n);//保证m<=n
		//计算阶乘：不用调用函数，节省空间
		unsigned long long int temp = 1;
		unsigned long long int result = 1;
		for (int i = 1; i <= m - 1; i++)
		{
			temp *= i;
		}
		for (int i = n; i <= m + n - 2; i++)
		{
			result *= i;
		}
		result = result / temp;
		return result;
	}
};
