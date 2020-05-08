#if 0
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> res(2, 0);
		int sum = 0;
		for (auto n : nums)
			sum ^= n;
		int pos = 1;
		while (!(sum&pos))
			pos <<= 1;
		for (auto n : nums)
			n & pos ? res[0] ^= n : res[1] ^= n;
		return res;
	}
};
#endif