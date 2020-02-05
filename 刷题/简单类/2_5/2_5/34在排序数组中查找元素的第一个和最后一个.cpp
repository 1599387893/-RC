#if 0
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int Count = count(nums.begin(), nums.end(), target);
		if (Count == 0)
			return vector<int>{-1, -1};
		vector<int> res;
		size_t pos = find(nums.begin(), nums.end(), target) - nums.begin();
		res.push_back(pos);
		res.push_back(pos + Count - 1);
		return res;
	}
};
#endif 