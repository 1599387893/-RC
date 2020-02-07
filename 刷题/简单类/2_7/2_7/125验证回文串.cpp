#if 0
class Solution {
public:
	bool isPalindrome(string s) {
		string temp;
		for (int i = 0; i < s.size(); ++i)
			if (isalnum(s[i]))
				temp += tolower(s[i]);
		int left = 0, right = temp.size() - 1;
		while (left<right)
			if (temp[left++] != temp[right--])
				return false;
		return true;
	}
};
#endif