//����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����

class Solution {
public:
	string minNumber(vector<int>& nums) {
		vector<string> strs;
		string res;
		for (auto num : nums)
			strs.push_back(to_string(num));
		sort(strs.begin(), strs.end(), compare);
		for (auto str : strs)
			res += str;
		return res;
	}
	static bool compare(const string& s1, const string& s2)
	{
		return s1 + s2 < s2 + s1;
	}
};