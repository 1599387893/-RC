//DFS
//���Ǵ����00��ʼ������������ͼ����������ȱ�����ͬʱ��¼;�о����Ľڵ㣬�����ǵ����յ�N-1N�6�11ʱ�����ǰѼ�¼��·��������������

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