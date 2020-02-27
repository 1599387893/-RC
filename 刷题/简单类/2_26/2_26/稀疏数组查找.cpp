#if 0
class Solution {
public:
	int findString(vector<string>& words, string s) {
		if (words.size() == 0)
			return -1;
		for (int i = 0; i < words.size(); ++i)
			if (words[i] == s)
				return i;
		return -1;
	}
};
#endif
#if 0
class Solution {
public:
	int findString(vector<string>& words, string s) {
		if (words.size() == 0)
			return -1;
		auto pos = find(words.begin(), words.end(), s);
		if (pos == words.end())
			return -1;
		return pos - words.begin();
	}
};
#endif
#if 0
class Solution {
public:
	int findString(vector<string>& words, string s) {
		int left = 0, right = words.size() - 1;
		while (left <= right)
		{
			while (words[left] == "")
				left++;
			while (words[right] == "")
				right--;
			if (words[left] == s)
				return left;
			if (words[right] == s)
				return right;
			left++;
			right--;
		}
		return -1;
	}
};
#endif