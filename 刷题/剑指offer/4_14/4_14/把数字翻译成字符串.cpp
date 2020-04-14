//------------------注意：01表示一个数不可以解析为 (0,1)和(1)

//递归
class Solution {
public:
	int translateNum(int num) {
		if (num<10)
			return 1;
		int ba = num % 100; //获取该数字的两位余数，进行判断；
		//如果这两位余数小于10或者大于等于26，那么这两位数字只能翻译出一种结果；
		if (ba<10 || ba>25)
			return translateNum(num / 10);
		//如果这两位余数大于等于10并且小于26，那么这两位数字有两种翻译方式，可翻译出两种结果；
		return translateNum(num / 10) + translateNum(num / 100);
	}
};


//动态规划

class Solution {
public:
	int translateNum(int num) {
		string s = to_string(num);
		vector<int> dp(s.size() + 1, 1);
		for (int i = 1; i<s.size(); ++i)
		{
			//判断i和i-1两个数字可不可以翻译成两种结果；
			if ((s[i - 1] == '0') || (s.substr(i - 1, 2)>"25"))
				dp[i + 1] = dp[i];
			else
				dp[i + 1] = dp[i] + dp[i - 1];
		}
		return dp[dp.size() - 1];
	}
};