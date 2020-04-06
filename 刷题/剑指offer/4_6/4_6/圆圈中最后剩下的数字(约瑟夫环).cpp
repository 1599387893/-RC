#if 0
class Solution {
public:
	int lastRemaining(int n, int m) {
		if (n == 1)//最终剩下一个数，下标一定为0；
			return 0;
		int x = lastRemaining(n - 1, m);
		return (m + x) % n;
	}
};
#endif