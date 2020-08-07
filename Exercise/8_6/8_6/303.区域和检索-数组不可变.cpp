class NumArray {
public:
	vector<int> sum;
	NumArray(vector<int>& nums) {
		sum = nums;
		for (int i = 1; i < nums.size(); ++i)
			sum[i] += sum[i - 1];
	}

	int sumRange(int i, int j) {
		if (i <= 0) return sum[j];
		if (j >= sum.size()) j = sum.size() - 1;
		return sum[j] - sum[i - 1];
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */