//暴力求解
class Solution {
public:
	int sumOddLengthSubarrays(vector<int>& arr) {
		int res = 0;
		for (int j = 0; j < arr.size(); ++j)
			for (int i = 1; j + i - 1 < arr.size(); i += 2)
				res += accumulate(arr.begin() + j, arr.begin() + i + j, 0);
		return res;
	}
}; 



//前缀和
class Solution {
public:
	int sumOddLengthSubarrays(vector<int>& arr) {
		int res = 0;
		vector<int> preSum{ 0 };
		for (auto n : arr)
			preSum.push_back(preSum.back() + n);
		for (int i = 0; i < arr.size(); ++i)
			for (int j = 1; j + i - 1 < arr.size(); j += 2)
				res += preSum[j + i] - preSum[i];
		return res;
	}
};

//O(n)解法
//一个元素出现的次数，与左边偶数个数（奇数个数）和右边的偶数个数（奇数个数）有关：left_odd * right_odd + left_even * right_even
class Solution {
public:
	//前缀和
	int sumOddLengthSubarrays(vector<int>& arr) {
		int res = 0;
		int left = 0, right = 0;
		int left_odd = 0, right_odd = 0, left_even = 0, right_even = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			left = i + 1;
			right = arr.size() - i;
			left_even = (left + 1) / 2;
			right_even = (right + 1) / 2;
			left_odd = left / 2;
			right_odd = right / 2;
			res += (left_odd * right_odd + left_even * right_even) * arr[i];
		}
		return res;
	}
};


