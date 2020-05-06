//DFS
//我们从起点00开始，对整张有向图进行深度优先遍历，同时记录途中经过的节点，当我们到达终点N-1N−1时，我们把记录的路径加入结果数组中

class Solution {
public:
	vector<vector<int>> res;
	void BackTrack(vector<vector<int>>& graph, vector<int> path, int index)
	{
		if (index == graph.size() - 1)
		{
			res.push_back(path);
			return;
		}
		for (auto n : graph[index])
		{
			path.push_back(n);
			BackTrack(graph, path, n);
			path.pop_back();
		}
	}
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<int> path;
		path.push_back(0);
		BackTrack(graph, path, 0);
		return res;
	}
};