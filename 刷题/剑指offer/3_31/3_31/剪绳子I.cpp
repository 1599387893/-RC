class Solution {
public:
	int cuttingRope(int n) {
		if (n <= 3)
			return n - 1;
		int a = n / 3;
		int b = n % 3; //b=0/1/2/3;
		//当绳子的长度为3时，最终乘积最大。
		if (b == 0)
			return pow(3, a); //将绳子全部分成长度为3的子段；
		if (b == 1)
			return pow(3, a - 1) * 4; //将最后一个长度为3的绳子和剩下的长度为1的绳子合并，分为长度为2的两段绳子；
		else
			return pow(3, a) * 2;  //将绳子分为1段长度为2和多段长度为3的子段；
	}
};