//��������һ����������һ�Σ�������������������

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, int> m;
		int res;
		for (auto c : nums)
			m[c]++;
		for (auto it = m.begin(); it != m.end(); ++it)
			if ((*it).second == 1)
			{
			res = (*it).first;
			break;
			}
		return res;
	}
};