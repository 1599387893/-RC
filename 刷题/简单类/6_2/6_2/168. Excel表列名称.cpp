
class Solution {
public:
	string convertToTitle(int n) {
		//ʮ����ת��ʮ������
		string res;
		while (n>0)
		{
			n -= 1;
			res.insert(res.begin(), 'A' + n % 26);
			n /= 26;
		}
		return res;
	}
};
