class Solution {
public:
	int StrToInt(string str) {
		long retValue = 0;
		int flag = 0;
		if (str[0] == '-')
			flag = 1;
		else if (str[0] == '+')
			flag = 2;
		for (int i = 0; i < str.size(); ++i)
		{
			if (flag != 0 && i == 0)
				continue;
			if (str[i] >= '0'&& str[i] <= '9')
				retValue = retValue * 10 + str[i] - '0';
			else
				return 0;
		}
		if (flag == 1)
			retValue = 0 - retValue;
		if (retValue > 2147483647 || retValue < -2147483648)
			return 0;
		return retValue;
	}
};