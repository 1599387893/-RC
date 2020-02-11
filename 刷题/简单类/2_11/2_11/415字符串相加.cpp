#if 0
class Solution {
public:
	string addStrings(string num1, string num2) {
		string res;
		if (num1.size()>num2.size())
			num1.swap(num2);
		while (num1.size()<num2.size())
			num1.insert(num1.begin(), '0');
		res.resize(num1.size(), 0);
		int flag = 0; //½øÎ»
		int temp = 0;
		for (int i = num1.size() - 1; i >= 0; --i)
		{
			temp = num1[i] - '0' + num2[i] - '0' + flag;
			flag = temp / 10;
			res[i] = temp % 10 + '0';
		}
		if (flag != 0)
			res.insert(res.begin(), flag + '0');
		return res;
	}
};
#endif