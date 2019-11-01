#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	for (size_t i = 0; i<nums.size(); ++i)
	{
		int temp = nums[i];
		int j = i + 1;
		while (j < nums.size() && nums[j] == temp)
			j++;
		nums.erase(nums.begin() + i + 1, nums.begin() + j);
	}
	return nums.size();
}

int main()
{
	vector<int> v{1,1};
	cout<<removeDuplicates(v)<<endl;
	system("pause");
	return  0;
}