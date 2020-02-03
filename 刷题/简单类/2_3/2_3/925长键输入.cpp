#if 0
class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		if (name.size() > typed.size())
			return false;
		int pos = 0;
		for (int i = 0; i < typed.size(); ++i)
		{
			if (typed[i] != name[pos])
			{
				if (i - 1 >= 0 && typed[i - 1] == typed[i])
				{
					typed.erase(typed.begin() + i);
					--i;
				}
				else
					return false;
			}
			else
				pos++;
		}
		if (typed.size() == name.size())
			return true;
		return false;
	}
};
#endif

