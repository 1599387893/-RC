class Solution {
public:
	int add(int a, int b) {
		int sum, carry;
		while (b)
		{
			sum = a ^ b;
			carry = (unsigned int)(a & b) << 1; //保存进位的结果，当不再需要进位时，求和结束
			a = sum;
			b = carry;
		}
		return a;
	}
};