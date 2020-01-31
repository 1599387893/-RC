//方法一
#if 0
class Solution {
public:
	void reverseString(vector<char>& s) {
		reverse(s.begin(),s.end());
	}
};
#endif

//方法二
#if 0
class Solution {
public:
	void reverseString(vector<char>& s) {
		for (int i = 0; i < s.size() / 2; ++i)
		{
			swap(s[i], s[s.size() - 1 - i]);
		}
	}
};
#endif