#if 0
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		set<int> s;
		for (int i = 0; i < nums.size(); ++i)
			s.insert(nums[i]);
		if (s.size()<3)
			return *(--s.end());
		auto it = s.end();
		for (int i = 0; i < 3; ++i)
			--it;
		return *it;
	}
};
#endif



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> nums{4,2,3,1};
	sort(nums.begin(), nums.end());
	int flag = 1;
	for (int i = nums.size() - 2; i >= 0; --i)
	{
		if (nums[i] != nums[i - 1])
			flag++;
		if (flag == 3)
			cout<<nums[i]<<endl;
	}
	cout<< nums[nums.size() - 1]<<endl;
	return 0;
}
