class Solution {
public:
	string reverseWords(string s) {
		if (s.empty())
			return s;
		//删除前后的空格
		string temp;
		int begin = 0, end = s.size() - 1;
		while (begin < s.size() && s[begin] == ' ')
			begin++;
		while (end >= 0 && s[end] == ' ')
			end--;
		if (begin == s.size())
			return "";
		temp.push_back(s[begin]);
		for (int i = begin + 1; i <= end; ++i)
			if (s[i] != ' ' || (s[i] == ' ' && temp[temp.size() - 1] != ' '))
				temp.push_back(s[i]);
		begin = 0;
		reverse(temp.begin(), temp.end());
		auto it = temp.find(' ', begin);
		while (it != string::npos)
		{
			reverse(temp.begin() + begin, temp.begin() + it);
			begin = it + 1;
			it = temp.find(' ', begin);
		}
		reverse(temp.begin() + begin, temp.end());
		s = temp;
		return s;

	}
};