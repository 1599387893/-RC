#if 0
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = 0; i < n; ++i)
			nums1[i + m] = nums2[i];
		sort(nums1.begin(), nums1.end());
	}
};
#endif

#if 0
#include<iostream>
#include<vector>
using namespace std;
#if 0
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n, int pos)
{
	if (pos < 0)
		return;
	if (m == 0)
	{
		nums1[pos] = nums2[n - 1];
		merge(nums1, m, nums2, --n, --pos);
	}
	if (n == 0)
	{
		nums1[pos] = nums1[m - 1];
		merge(nums1, --m, nums2, n, --pos);
	}
	if (nums1[m - 1] > nums2[n - 1])
	{
		nums1[pos] = nums1[m - 1];
		merge(nums1, --m, nums2, n, --pos);
	}
	else
	{
		nums1[pos] = nums2[n - 1];
		merge(nums1, m, nums2, --n, --pos);
	}
}
#endif
int main()
{
	//vector<int> nums1{1,2,3,0,0,0};
	//vector<int> nums2{ 2, 5, 6 };
	//merge(nums1, 3, nums2, 3, nums1.size() - 1);
	int n = 2;
	cout << (n += n -= n*n) << endl;
	return 0;
}
#endif