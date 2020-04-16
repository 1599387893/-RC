class Solution {
public:
	int strToInt(string str) {
		int pos = 0;
		bool flag = true;//正负标记,默认为正
		long res = 0, n = 0;
		//先找到第一个非空字符；
		while (pos < str.size() && str[pos] == ' ')
			pos++;
		if (pos == str.size())
			return 0;
		//判断第一个有效字符是不是合法字符
		if (str[pos] != '+' && str[pos] != '-' && !isdigit(str[pos]))
			return 0;
		if (str[pos] == '+' || str[pos] == '-')
		{
			if (str[pos] == '-')
				flag = false;
			pos++;
		}
		//处理数字
		while (pos < str.size() && isdigit(str[pos]))
		{
			n = str[pos] - '0';

			//溢出判断方法一：
			if (flag && n + res * 10 > INT_MAX)
				return INT_MAX;
			if (!flag && (-1 * (n + (res * 10)) < INT_MIN))
				return INT_MIN;
			
			//溢出判断方法二：这种方法不需要将res设为long类型
			/*
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && n>7))
				return (flag ? INT_MAX : INT_MIN);
			*/
			res = res * 10 + n;
			pos++;
		}
		return flag ? res : -1 * res;
	}
};