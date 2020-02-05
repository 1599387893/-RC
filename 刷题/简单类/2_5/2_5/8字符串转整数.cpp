#if 0
class Solution {
public:
	int myAtoi(string str) {
		int i = 0;
		long long res = 0;
		bool bol = true; //·ûºÅÎ»
		//È¥³ý¿Õ¸ñ
		while (i < str.size() && str[i] == ' ')
			++i;
		if (i == str.size())
			return 0;
		if (str[i] == '-')
		{
			bol = false;
			++i;
		}
		else if (str[i] == '+')
			++i;
		while (i < str.size() && str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + str[i++] - '0';
			if (res >= 2147483648)
				return bol ? INT_MAX : INT_MIN;
		}
		return bol ? res : -res;
	}
};
#endif