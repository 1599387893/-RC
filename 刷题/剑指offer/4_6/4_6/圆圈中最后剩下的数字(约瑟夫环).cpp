#if 0
class Solution {
public:
	int lastRemaining(int n, int m) {
		if (n == 1)//����ʣ��һ�������±�һ��Ϊ0��
			return 0;
		int x = lastRemaining(n - 1, m);
		return (m + x) % n;
	}
};
#endif