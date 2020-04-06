class Solution {
public:
	int add(int a, int b) {
		int sum, carry;
		while (b)
		{
			sum = a ^ b;
			carry = (unsigned int)(a & b) << 1; //�����λ�Ľ������������Ҫ��λʱ����ͽ���
			a = sum;
			b = carry;
		}
		return a;
	}
};