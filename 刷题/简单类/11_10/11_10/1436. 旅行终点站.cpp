class Solution {
public:
	string destCity(vector<vector<string>>& paths) {
		unordered_map<string, string> um;
		for (auto vs : paths)
			um[vs[0]] = vs[1];
		auto p = um.begin()->second;
		while (um.find(p) != um.end())
			p = um[p];
		return p;
	}
};




class Solution {
public:
	string destCity(vector<vector<string>>& paths) {
		//找出出度为0的节点
		unordered_map<string, int> um;
		for (auto vs : paths)
		{
			um[vs[0]] += 1;
			um[vs[1]] += 0;
		}
		for (auto p : um)
			if (p.second == 0)
				return p.first;
		return "";
	}
};