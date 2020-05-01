class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> res(nums);
		int temp = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < res.size(); ++i)
		{
			temp = 0;
			for (int j = 0; j < nums.size() && res[i]>nums[j]; ++j)
				temp++;
			res[i] = temp;
		}
		return res;
	}
};

//·½·¨¶þ£º
class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> res;
		vector<int> m(101, 0);
		int temp = 0;
		for (auto a : nums)
			m[a]++;
		for (auto a : nums)
		{
			temp = 0;
			for (int i = 0; i < a; ++i)
				temp += m[i];
			res.push_back(temp);
		}
		return res;
	}
};