//�������㷨
class Solution {
public:
	double myPow(double x, int n) {
		double sum = 1.0;
		int temp = n;
		while (temp != 0) {
			if ((temp & 1) != 0) {
				sum *= x;
			}
			temp /= 2;  // ��ָ��������λ
			x *= x;               // ��base�Ĵ�����2�ı�������
		}
		return n<0 ? 1 / sum : sum;
	}
};