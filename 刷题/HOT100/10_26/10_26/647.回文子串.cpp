#if 0
class Solution {
public:
	bool isLoop(string& s, int start, int end)
	{
		while (start < end)
		{
			if (s[start] != s[end])
				return false;
			start++;
			end--;
		}
		return true;
	}
	int countSubstrings(string s) {
		int count = s.size();
		for (int i = 0; i < (int)s.size(); ++i)
			for (int j = i + 1; j < (int)s.size(); ++j)
				if (isLoop(s, i, j))
					count++;
		return count;
	}
};


class Solution {
public:
	int CountSubLoop(string& s, int pos)
	{
		int res = 0;
		//将pos位置的元素(子串长度为奇数)作为中间元素进行统计
		int start = pos - 1;
		int end = pos + 1;
		while (start >= 0 && end < (int)s.size())
		{
			if (s[start] != s[end])
				break;
			res++;
			start--;
			end++;
		}
		start = pos;
		end = pos + 1;
		//子串长度为偶数
		while (start >= 0 && end < (int)s.size())
		{
			if (s[start] != s[end])
				break;
			res++;
			start--;
			end++;
		}
		return res;
	}
	int countSubstrings(string s) {
		int count = s.size();
		for (int i = 0; i < (int)s.size() - 1; ++i)
			count += CountSubLoop(s, i);
		return count;
	}
};

#endif
