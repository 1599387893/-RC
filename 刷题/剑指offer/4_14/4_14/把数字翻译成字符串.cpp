//------------------ע�⣺01��ʾһ���������Խ���Ϊ (0,1)��(1)

//�ݹ�
class Solution {
public:
	int translateNum(int num) {
		if (num<10)
			return 1;
		int ba = num % 100; //��ȡ�����ֵ���λ�����������жϣ�
		//�������λ����С��10���ߴ��ڵ���26����ô����λ����ֻ�ܷ����һ�ֽ����
		if (ba<10 || ba>25)
			return translateNum(num / 10);
		//�������λ�������ڵ���10����С��26����ô����λ���������ַ��뷽ʽ���ɷ�������ֽ����
		return translateNum(num / 10) + translateNum(num / 100);
	}
};


//��̬�滮

class Solution {
public:
	int translateNum(int num) {
		string s = to_string(num);
		vector<int> dp(s.size() + 1, 1);
		for (int i = 1; i<s.size(); ++i)
		{
			//�ж�i��i-1�������ֿɲ����Է�������ֽ����
			if ((s[i - 1] == '0') || (s.substr(i - 1, 2)>"25"))
				dp[i + 1] = dp[i];
			else
				dp[i + 1] = dp[i] + dp[i - 1];
		}
		return dp[dp.size() - 1];
	}
};