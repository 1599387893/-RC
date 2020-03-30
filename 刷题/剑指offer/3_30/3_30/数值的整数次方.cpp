//快速幂算法
class Solution {
public:
	double myPow(double x, int n) {
		double sum = 1.0;
		int temp = n;
		while (temp != 0) {
			if ((temp & 1) != 0) {
				sum *= x;
			}
			temp /= 2;  // 对指数进行移位
			x *= x;               // 让base的次幂以2的倍数增长
		}
		return n<0 ? 1 / sum : sum;
	}
};