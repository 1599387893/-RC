//��̬�滮
//ÿ������������һ����С�ĳ���*2/*3/*5������
class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> uglyArr(n);
		uglyArr[0] = 1;
		int a = 0, b = 0, c = 0; //�������λ
		int temp, n2, n3, n5;
		for (int i = 1; i < n; ++i)
		{
			n2 = uglyArr[a] * 2;
			n3 = uglyArr[b] * 3;
			n5 = uglyArr[c] * 5;
			uglyArr[i] = min(min(n2, n3), n5);
			if (uglyArr[i] == n2) a++;
			if (uglyArr[i] == n3) b++;
			if (uglyArr[i] == n5) c++;
		}
		return uglyArr[n - 1];
	}
};