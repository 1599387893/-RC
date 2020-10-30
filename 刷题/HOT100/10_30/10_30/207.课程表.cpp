class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		//����ͼ�л�
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


//��������ͳ��ÿ���ڵ�ĳ��Ƚڵ��Լ��ó��Ƚڵ���������
//			ѭ���ļ�¼���Ϊ0�Ľڵ㣬��ɾ���ýڵ㣬ͬʱ���������ڵ�������
//			���������ͼ��û�нڵ㣬���ʾ����ͼ�޻��������ʾ�л���
class Solution {
public:
	vector<vector<int>> edges;
	vector<int> indeg;

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		edges.resize(numCourses);
		indeg.resize(numCourses);
		for (const auto& info : prerequisites)
		{
			edges[info[1]].push_back(info[0]); //��¼ÿ���γ̵ĺ��޿�
			++indeg[info[0]]; //����¼ÿ���γ̵ĺ��޿εĸ���
		}
		queue<int> q;
		for (int i = 0; i < numCourses; ++i)
			if (indeg[i] == 0) //�Ƚ����޿�Ϊ0�Ŀγ̱��浽������
				q.push(i);

		int visited = 0; //ͳ�Ʋ����ɻ��Ľڵ�ĸ���
		while (!q.empty())
		{
			++visited;
			int u = q.front();
			q.pop();
			for (int v : edges[u])
			{
				//��u���������ڽڵ�v����ȼ���1
				--indeg[v];
				//ĳ�����ڽڵ�v����ȱ�Ϊ0����ô���Ǿͽ�v���������
				if (indeg[v] == 0)
					q.push(v);
			}
		}
		return visited == numCourses;
	}
};