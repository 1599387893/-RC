#if 0
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res;
		res.push_back({});
		if (nums.size() == 0)
			return res;
		int size = nums.size();
		int end = pow(2, size);
		vector<int> temp;
		for (int i = 1; i <= end; ++i)
		{
			temp.clear();
			for (int j = 0; j < size; ++j)
				if (i&(1 << j))
					temp.push_back(nums[j]);
			if (Find(res, temp))
				res.push_back(temp);
		}
		return res;
	}
};
#endif