class Solution {
public:
	int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		int res = arr1.size();
		for (auto x : arr1)
			for (auto y : arr2)
				if (abs(x - y) <= d)
				{
			res--;
			break;
				}
		return res;
	}
};