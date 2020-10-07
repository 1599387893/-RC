class Solution {
public:
	//��ߵ͵��˶�����߸ߵ���û��Ӱ�죬����Ƚ���߸ߵ��˷����ڶ����У�
	//�ں�ߵ��������У������е�Ԫ�ض��Ƚ�Ҫ�����Ԫ�ش�ֻ��Ҫ��Ҫ�����Ԫ�أ�������ʵ�λ�ü��ɣ�
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(),
			[](const vector<int>& v1, const vector<int>& v2)
		{return v1[0] == v2[0] ? (v1[1] <= v2[1]) : (v1[0] > v2[0]); });
		vector<vector<int>> res;
		for (int i = 0; i < people.size(); ++i)
		{
			res.insert(res.begin() + people[i][1], people[i]);
		}
		return res;
	}
};