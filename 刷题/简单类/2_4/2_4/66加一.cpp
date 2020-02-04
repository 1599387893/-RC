#if 0
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> res(digits);
		++res[res.size() - 1];
		if (res[res.size() - 1] == 10)
		{
			res[res.size() - 1] = 0;
			for (int i = res.size() - 2; i >= 0; --i)
			{
				++res[i];
				if (res[i] <= 9)
					break;
				else
					res[i] = 0;
			}
			if (res[0] == 0)
			{
				vector<int> temp{ 1 };
				temp.insert(temp.end(), res.begin(), res.end());
				res = temp;
			}
		}
		return res;
	}
};
#endif