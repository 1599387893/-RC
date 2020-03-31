//青蛙每次可以调一阶，也可以跳两阶
#if 0
class Solution {
public:
	int numWays(int n) {
		if (n == 0)
			return 1;
		if (n == 1)
			return 1;
		int a = 1, b = 1, ret = 0;
		for (int i = 2; i <= n; ++i)
		{
			ret = (a + b) % 1000000007;
			a = b;
			b = ret;
		}
		return ret;
	}
};
#endif