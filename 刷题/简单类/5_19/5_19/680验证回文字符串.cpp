//遇到不相等的字符时，判断其子串([i+1,j]或[i,j-1])是否为回文串

class Solution {
public:
	bool isHoloBack(string& s, int left, int right)
	{
		while ((left < right) && (s[left] == s[right]))
		{
			left++;
			right--;
		}
		return left >= right ? true : false;
	}
	bool validPalindrome(string s) {
		if (s.empty() || s.size() == 1) return true;
		int left = 0, right = s.size() - 1;
		while ((left < right) && (s[left] == s[right]))
		{
			left++;
			right--;
		}
		if (left >= right || left + 1 == right)
			return true;
		return isHoloBack(s, left + 1, right) || isHoloBack(s, left, right - 1);
	}
};