class Solution {
public:
	//身高低的人对于身高高的人没有影响，因此先将身高高的人放置在队伍中；
	//在后边调整过程中，队伍中的元素都比将要插入的元素大，只需要将要插入的元素，插入合适的位置即可；
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