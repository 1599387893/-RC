class Solution {
public:
	int maximum69Number(int num) {
		//将值为6的最高位修改即可；
		string str = to_string(num);
		int i = 0;
		for (i = 0; i < str.size(); ++i)
			if (str[i] == '6')
				break;
		if (i == str.size()) return num;
		return num + 3 * pow(10, str.size() - i - 1);
	}
};