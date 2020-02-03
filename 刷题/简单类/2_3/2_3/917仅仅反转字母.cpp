#if 0
class Solution {
public:
	bool IsLetter(char c)
	{
		if (!((c <= 'Z'&&c >= 'A') || (c <= 'z' && c >= 'a')))
			return false;
		return true;
	}
	string reverseOnlyLetters(string S) {
		string res(S);
		int left = 0;
		int right = res.size() - 1;
		while (left<right)
		{
			while (left<right && !IsLetter(res[left]))
				left++;
			while (left<right && !IsLetter(res[right]))
				right--;
			swap(res[left++], res[right--]);
		}
		return res;
	}
};
#endif