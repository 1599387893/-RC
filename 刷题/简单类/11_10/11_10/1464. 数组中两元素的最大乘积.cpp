class Solution {
public:
	int maxProduct(vector<int>& nums) {
		//找到最大的两个数
		priority_queue<int> pq;
		for (auto n : nums)
			pq.push(n);
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		return (a - 1) * (b - 1);
	}
};