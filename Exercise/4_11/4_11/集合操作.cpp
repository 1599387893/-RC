#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Find(vector<vector<int>>& group, int& a)
{
	for (int i = 0; i < group.size(); ++i)
	{
		if (find(group[i].begin(), group[i].end(), a) != group[i].end())
		{
			a = i;
			break;
		}
	}
}
int main()
{
	int T, N, M;
	int op;
	int a, b;//操作数
	cin >> T;
	while (T--)//T组数据
	{
		cin >> N >> M;
		vector<vector<int>> group(N);
		for (int i = 0; i<N; ++i)
			group[i].push_back(i + 1);
		while (M--)//M行操作
		{
			cin >> op;
			op == 1 ? cin >> a >> b : cin >> a;
			//合并两个集合
			if (op == 1)
			{
				Find(group, a);
				Find(group, b);
				if (b == a) //在同一个集合，不处理
					continue;
				//否则，合并两个集合
				group[a].insert(group[a].end(), group[b].begin(), group[b].end());
				group[b].clear();
			}
			//从集合中取出该元素
			else if (op == 2)
			{
				int pos = a;
				Find(group, pos);
				if (group[pos].size()>1)//如果该元素所在集合的元素个数大于1，那么将该元素插入到其他为空的集合中
				{
					//从原集合中删除
					for (int i = 0; i<group[pos].size(); ++i)
						if (group[pos][i] == a)
						{
						group[pos].erase(group[pos].begin() + i);
						break;
						}
					//插入新集合
					for (auto& arr : group)
						if (arr.size() == 0)
							arr.push_back(a);
				}
			}
			//打印该元素所在集合的元素个数
			else //op==3
			{
				Find(group, a);
				group[a].size() == 0 ? cout << 1 << endl : cout << group[a].size() << endl;
			}
		}
	}
	return 0;
}






























#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Find(vector<vector<int>>& group, int& a)
{
	for (size_t i = 0; i < group.size(); ++i)
	{
		if (find(group[i].begin(), group[i].end(), a) != group[i].end())
		{
			a = i;
			break;
		}
	}
}
void Option(vector<vector<int>>& group, int& op, int a, int b)
{
	//合并两个集合
	if (op == 1)
	{
		Find(group, a);
		Find(group, b);
		if (b == a) //在同一个集合，不处理
			return;
		//否则，合并两个集合
		group[a].insert(group[a].end(), group[b].begin(), group[b].end());
		group[b].clear();
	}
	//从集合中取出该元素
	else if (op == 2)
	{
		int pos = a;
		Find(group, pos);
		if (group[pos].size()>1)//如果该元素所在集合的元素个数大于1，那么将该元素插入到其他为空的集合中
		{
			//从原集合中删除
			for (size_t i = 0; i<group[pos].size(); ++i)
				if (group[pos][i] == a)
				{
				group[pos].erase(group[pos].begin() + i);
				break;
				}
			//插入新集合
			for (auto& arr : group)
				if (arr.size() == 0)
					arr.push_back(a);
		}
	}
	//打印该元素所在集合的元素个数
	else //op==3
	{
		Find(group, a);
		group[a].size() == 0 ? cout << 1 << endl : cout << group[a].size() << endl;
	}
}
int main()
{
	int T, N, M;
	int op;
	int a, b;//操作数
	cin >> T;
	while (T--)//T组数据
	{
		cin >> N >> M;
		vector<vector<int>> group(N);
		for (int i = 0; i<N; ++i)
			group[i].push_back(i + 1);
		while (M--)//M行操作
		{
			cin >> op;
			if (op == 1)
			{
				cin >> a >> b;
				Option(group, op, a, b);
			}
			else
			{
				cin >> a;
				Option(group, op, a, 0);
			}
		}
	}
	return 0;
}