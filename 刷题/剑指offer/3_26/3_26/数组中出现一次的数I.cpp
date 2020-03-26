//��������������������һ�Σ�������������������

class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		vector<int> res(2, 0);
		int temp = 0;
		for (int i = 0; i < nums.size(); ++i)
			temp ^= nums[i];
		temp &= (-temp); //�õ���������ͬ������ͬ�����λ���Դ���Ϊ����������������������Ϊ���顣
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] & temp)
				res[0] ^= nums[i];
			else
				res[1] ^= nums[i];
		}
		return res;
	}
};



class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		vector<int> res;
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); ++i)
			m[nums[i]]++;
		for (auto it = m.begin(); it != m.end(); ++it)
			if ((*it).second == 1)
				res.push_back((*it).first);
		return res;
	}
};