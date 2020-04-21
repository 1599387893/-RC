#if 0
//如果某个连续子数组中恰好有K个奇数数字，那么该子数组为优美子数组
//首先捋清一下题意，就是求包含k个奇数数字的连续子数组的个数，
//那么对于任意一段包含k个奇数数字的子数组，
//如果两边偶数的个数分别为m和n，那么存在的数组有(m + 1)·(n + 1)个，
//因为左右两边分别可以选择[0, m]个偶数和[0, n]个偶数。


class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		vector<int> odd(nums.size() + 2);
		int cnt = 0, res = 0;
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] & 1)
				odd[++cnt] = i;
		odd[0] = -1;
		odd[++cnt] = nums.size();
		for (int i = 1; i + k <= cnt; ++i)
			res += (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1]);
		return res;
	}
};


class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int>index;
		for (int i = 0; i < n; i++){
			//存奇数数字的下标
			if (nums[i] % 2)
				index.push_back(i);

		}
		if (index.size() < k) return 0;
		if (index.size() == k) return (index[0] + 1)*(n - index[k - 1]);
		int number = 0;
		for (int i = 0; i <= index.size() - k; i++){
			if (i == 0) number += (index[0] + 1)*(index[k] - index[k - 1]);
			else if (i == index.size() - k){
				number += (index[i] - index[i - 1])*(n - index[i + k - 1]);
			}
			else
				number += (index[i] - index[i - 1])*(index[i + k] - index[i + k - 1]);
		}
		return number;
	}
};

#endif