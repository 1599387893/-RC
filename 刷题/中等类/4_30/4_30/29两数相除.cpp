class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) return 0;
		if (dividend >= INT_MAX) dividend = INT_MAX;
		if (dividend <= INT_MIN) dividend = INT_MIN;
		if (divisor == 1 || divisor == -1) return divisor == 1 ? dividend : -dividend;
		int flag = 0;
		int res = 0;
		if (dividend < 0)
		{
			flag++;
			dividend = dividend == INT_MIN ? INT_MAX : -dividend;
		}
		if (divisor < 0)
		{
			flag++;
			divisor = divisor == INT_MIN ? INT_MAX : -divisor;
		}
		while (dividend >= divisor)
		{
			res++;
			dividend -= divisor;
		}
		return (flag % 2 == 0 ? res : -res);
	}
};