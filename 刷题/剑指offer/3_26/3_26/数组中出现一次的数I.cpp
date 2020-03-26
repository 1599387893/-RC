//数组中有两个数出现了一次，其他的数出现了两次

class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		vector<int> res(2, 0);
		int temp = 0;
		for (int i = 0; i < nums.size(); ++i)
			temp ^= nums[i];
		temp &= (-temp); //得到这两个不同的数不同的最低位，以此作为划分数组的条件，将数组分为两组。
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] & temp)
				res[0] ^= nums[i];
			else
				res[1] ^= nums[i];
		}
		return res;
	}
};



class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		vector<int> res;
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); ++i)
			m[nums[i]]++;
		for (auto it = m.begin(); it != m.end(); ++it)
			if ((*it).second == 1)
				res.push_back((*it).first);
		return res;
	}
};