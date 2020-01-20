#if 0
class Solution {
public:
	bool IsSelfDiv(int i)
	{
		int temp = i;
		while (temp)
		{
			if (temp % 10 != 0)
			{
				if (i % (temp % 10) != 0)
					return false;
			}
			else
				return false;
			temp /= 10;
		}
		return true;
	}
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> ret;
		if (left == 0)
			left = 1;
		for (int i = left; i <= right; ++i)
		{
			if (i % 10 == 0)
				continue;
			if (IsSelfDiv(i))
				ret.push_back(i);
		}
		return ret;
	}
};
#endif