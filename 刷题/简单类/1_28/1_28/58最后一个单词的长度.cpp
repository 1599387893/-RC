#if 0
class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.size() == 0)
			return 0;
		int count = 0;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			if (s[i] != ' ')
			{
				while (i >= 0 && s[i--] != ' ')
					count++;
				break;
			}
		}
		return count;
	}
};
#endif

#if 0
class Solution {
public:
	int lengthOfLastWord(string s) {
		return lengthOfLastWord(s, false);
	}
	int lengthOfLastWord(string s, bool b)
	{
		if (s.size() == 0)
			return 0;
		if (s[s.size() - 1] != ' ')
			return 1 + lengthOfLastWord(s.substr(0, s.size() - 1), true);
		else
			if (b == true)
				return 0;
			else
				return 0 + lengthOfLastWord(s.substr(0, s.size() - 1), b);
	}
};
#endif