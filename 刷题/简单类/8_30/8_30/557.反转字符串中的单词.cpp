#if 0
class Solution {
public:
	string reverseWords(string s) {
		string ret;
		int start = 0, end = 0;
		end = s.find(' ');
		while (end != string::npos)
		{
			reverse(s.begin() + start, s.begin() + end);
			start = end + 1;
			end = s.find(' ', start);
		}
		reverse(s.begin() + start, s.end());
		return s;
	}
};
#endif