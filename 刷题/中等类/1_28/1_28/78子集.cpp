//�����Ʒ�
/*
˼·��ʹ�ö���������ʾ�Ӽ���Ԫ����ԭ���ϵ��Ǽ���Ԫ�أ����磺0101(��ʾ���Ӽ�������һ���͵ڶ���Ԫ��)��
*/
#if 0
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		res.push_back({});
		int size = nums.size();
		int subsize = pow(2, size);
		int hash = 1;
		while (hash<subsize)
		{
			vector<int> temp;
			for (int k = 0; k < size; ++k)
			{
				int a = 1 << k;
				if (a&hash)
					temp.push_back(nums[k]);
			}
			res.push_back(temp);
			hash++;
		}
		return res;
	}
};
#endif

#if 0
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		res.push_back({});
		for (int i = 0; i < nums.size(); ++i)
		{
			int n = res.size();
			for (int j = 0; j < n; ++j)
			{
				vector<int> temp = res[j];
				temp.push_back(nums[i]);
				res.push_back(temp);
			}
		}
		return res;
	}
};
#endif