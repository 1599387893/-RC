class Solution {
public:
	int cuttingRope(int n) {
		if (n <= 3)
			return n - 1;
		int a = n / 3;
		int b = n % 3; //b=0/1/2/3;
		//�����ӵĳ���Ϊ3ʱ�����ճ˻����
		if (b == 0)
			return pow(3, a); //������ȫ���ֳɳ���Ϊ3���ӶΣ�
		if (b == 1)
			return pow(3, a - 1) * 4; //�����һ������Ϊ3�����Ӻ�ʣ�µĳ���Ϊ1�����Ӻϲ�����Ϊ����Ϊ2���������ӣ�
		else
			return pow(3, a) * 2;  //�����ӷ�Ϊ1�γ���Ϊ2�Ͷ�γ���Ϊ3���ӶΣ�
	}
};