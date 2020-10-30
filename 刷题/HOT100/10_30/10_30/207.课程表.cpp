class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		//有向图判环
		unordered_map<int, int> um;
		for (auto arr : prerequisites)
			um[arr[0]] = arr[1];
		unordered_map<int, bool> temp;
		int pre = 0;
		for (auto arr : prerequisites)
		{
			temp.clear();
			temp[arr[0]] = true;
			pre = arr[1];
			while (um.find(pre) != um.end())
			{
				if (temp.find(um[pre]) != temp.end())
					return false;
				pre = um[pre];
				temp[pre] = true;
			}
		}
		return true;
	}
};


//拓扑排序：统计每个节点的出度节点以及该出度节点的入度数；
//			循环的记录入度为0的节点，并删除该节点，同时调整其他节点的入度数
//			最终如果有图中没有节点，则表示有向图无环，否则表示有环。
class Solution {
public:
	vector<vector<int>> edges;
	vector<int> indeg;

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		edges.resize(numCourses);
		indeg.resize(numCourses);
		for (const auto& info : prerequisites)
		{
			edges[info[1]].push_back(info[0]); //记录每个课程的后修课
			++indeg[info[0]]; //并记录每个课程的后修课的个数
		}
		queue<int> q;
		for (int i = 0; i < numCourses; ++i)
			if (indeg[i] == 0) //先将后修课为0的课程保存到队列中
				q.push(i);

		int visited = 0; //统计不构成环的节点的个数
		while (!q.empty())
		{
			++visited;
			int u = q.front();
			q.pop();
			for (int v : edges[u])
			{
				//将u的所有相邻节点v的入度减少1
				--indeg[v];
				//某个相邻节点v的入度变为0，那么我们就将v放入队列中
				if (indeg[v] == 0)
					q.push(v);
			}
		}
		return visited == numCourses;
	}
};