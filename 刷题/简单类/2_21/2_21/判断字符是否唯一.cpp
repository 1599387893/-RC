#if 0
class Solution {
public:
	bool isUnique(string astr) {
		if (astr.size() == 0 || astr.size() == 1)
			return true;
		sort(astr.begin(), astr.end());
		for (int i = 0; i < astr.size() - 1; ++i)
		{
			if (astr[i] == astr[i + 1])
				return false;
		}
		return true;
	}
};
#endif
#if 0
class Solution {
public:
	bool isUnique(string astr) {
		if (astr.size() == 0 || astr.size() == 1)
			return true;
		for (int i = 0; i < astr.size() - 1; ++i)
		{
			if (count(astr.begin() + i, astr.end(), astr[i])>1)
				return false;
		}
		return true;
	}
};
#endif