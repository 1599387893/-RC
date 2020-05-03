class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		//��̬�滮
		//����ÿһ��Ԫ�أ�ѡ���Ƿ����������飬���ߵ�����Ϊ�����飬ȡ���ڼ��Ϻ�������Ƿ����ӡ�
		int res = INT_MIN, temp = 0;
		for (const auto x : nums)
		{
			temp = max(temp + x, x);
			res = max(res, temp);
		}
		return res;
	}
};