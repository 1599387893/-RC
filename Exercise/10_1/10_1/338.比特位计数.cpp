class Solution {
public:
	int CountOne(int i)
	{
		int count = 0;
		while (i)
		{
			count++;
			i &= (i - 1);
		}
		return count;
	}
	vector<int> countBits(int num) {
		vector<int> res;
		res.push_back(0);
		if (num == 0) return res;
		for (int i = 1; i <= num; ++i)
			res.push_back(CountOne(i));
		return res;
	}
};


class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res(num + 1);
		res[0] = 0;
		for (int i = 1; i <= num; ++i)
			res[i] = res[i & (i - 1)] + 1;
		return res;
	}
};