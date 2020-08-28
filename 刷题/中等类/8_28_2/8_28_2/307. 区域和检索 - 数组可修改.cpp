#if 0
class NumArray {
public:
	vector<int> arr;
	NumArray(vector<int>& nums) {
		arr = nums;
	}

	void update(int i, int val) {
		arr[i] = val;
	}

	int sumRange(int i, int j) {
		int res = 0;
		for (int pos = i; pos <= j; ++pos)
			res += arr[pos];
		return res;
	}
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* obj->update(i,val);
* int param_2 = obj->sumRange(i,j);
*/
#endif