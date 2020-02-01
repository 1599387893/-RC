#if 0
class Solution {
public:
	string toLowerCase(string str) {
		string res(str);
		for (int i = 0; i < res.size(); ++i)
			res[i] |= 32;
		return res;
	}
};
#endif


#if 0
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		if (nums.size() == 0 || nums.size() == 1 || nums.size() == k)
			return;
		vector<int> temp;
		temp.insert(temp.begin(), nums.end() - k, nums.end());
		nums.erase(nums.end() - k, nums.end());
		nums.insert(nums.begin(), temp.begin(), temp.end());
	}
};
#endif

#if 0
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		if (nums.size() == 0 || nums.size() == 1 || nums.size() == k)
			return;
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};
#endif

#if 0
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		if (nums.size() == 0 || nums.size() == 1 || nums.size() == k)
			return;
		vector<int> temp;
		temp.resize(nums.size());
		int start = 0;
		for (int i = nums.size() - k; i<nums.size(); ++i)
			temp[start++] = nums[i];
		for (int i = 0; i < nums.size() - k; ++i)
			temp[start++] = nums[i];
		nums = temp;
	}
};
#endif

#if 0
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		if (nums.size() == 0 || nums.size() == 1 || nums.size() == k || k == 0)
			return;
		int n = nums.size();
		for (int start = 0; start < nums.size() && k != 0; n -= k, start += k, k %= n)
			for (int i = 0; i < k; i++)
				swap(nums[start + i], nums[nums.size() - k + i]);
	}
};
#endif

#if 0
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> nums{ 1, 2, 3, 4, 5, 6, 7 };
	int k = 3;
	k %= nums.size();
	if (nums.size() == 0 || nums.size() == 1 || nums.size() == k || k == 0)
		return 1;
	int n = nums.size();
	for (int start = 0; start < nums.size() && k != 0; n -= k, start += k, k %= n)
		for (int i = 0; i < k; i++)
			swap(nums[start + i], nums[nums.size() - k + i]);
	return 0;
}
#endif