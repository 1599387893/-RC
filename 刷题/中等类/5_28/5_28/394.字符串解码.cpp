class Solution {
public:
	string decodeString(string s) {
		int len = s.size();
		int num = 0;
		stack<int> numstack;
		stack<string> strstack;
		string cur = "";
		string result = "";
		for (int i = 0; i < len; ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
				num = 10 * num + s[i] - '0';
			else if (s[i] == '[')
			{
				numstack.push(num); // 保存重复字符串的重复次数
				strstack.push(cur); //有可能是[]的嵌套，因此cur保存之前的重复字符串
				num = 0;
				cur.clear();
			}
			else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
				cur += s[i]; //保存需要重复的字符串
			else if (s[i] == ']')
			{
				//开始构建结果
				int k = numstack.top();
				numstack.pop();
				for (int j = 0; j < k; ++j)
					strstack.top() += cur;
				cur = strstack.top();
				strstack.pop();
			}
		}
		result = result + cur;
		return result;
	}
};
