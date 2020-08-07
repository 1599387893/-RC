class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		int ans = INT_MIN;
		int max_v = 1, min_v = 1;
		for (int i = 0; i < n; ++i)
		{
			//�����ǰԪ���Ǹ�������ô�п��ܴ���Сֵ(����)������ֵ��
			if (nums[i] < 0) swap(max_v, min_v);
			max_v = max(max_v * nums[i], nums[i]);
			min_v = min(min_v * nums[i], nums[i]);
			ans = max(max_v, ans);
		}
		return ans;
	}
};

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		int res = nums[0];
		int max_v = nums[0], min_v = nums[0];
		for (int i = 1; i < n; ++i)
		{
			int ma = max_v, mi = min_v; //ʹ����ʱ����������max_v ��ֵ���ܻ��������������֮��ı�
			max_v = max(ma * nums[i], max(nums[i], mi * nums[i]));
			min_v = min(mi * nums[i], min(nums[i], ma * nums[i]));
			res = max(res, max_v);
		}
		return res;
	}
};