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
	int a, b;//������
	cin >> T;
	while (T--)//T������
	{
		cin >> N >> M;
		vector<vector<int>> group(N);
		for (int i = 0; i<N; ++i)
			group[i].push_back(i + 1);
		while (M--)//M�в���
		{
			cin >> op;
			op == 1 ? cin >> a >> b : cin >> a;
			//�ϲ���������
			if (op == 1)
			{
				Find(group, a);
				Find(group, b);
				if (b == a) //��ͬһ�����ϣ�������
					continue;
				//���򣬺ϲ���������
				group[a].insert(group[a].end(), group[b].begin(), group[b].end());
				group[b].clear();
			}
			//�Ӽ�����ȡ����Ԫ��
			else if (op == 2)
			{
				int pos = a;
				Find(group, pos);
				if (group[pos].size()>1)//�����Ԫ�����ڼ��ϵ�Ԫ�ظ�������1����ô����Ԫ�ز��뵽����Ϊ�յļ�����
				{
					//��ԭ������ɾ��
					for (int i = 0; i<group[pos].size(); ++i)
						if (group[pos][i] == a)
						{
						group[pos].erase(group[pos].begin() + i);
						break;
						}
					//�����¼���
					for (auto& arr : group)
						if (arr.size() == 0)
							arr.push_back(a);
				}
			}
			//��ӡ��Ԫ�����ڼ��ϵ�Ԫ�ظ���
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
	//�ϲ���������
	if (op == 1)
	{
		Find(group, a);
		Find(group, b);
		if (b == a) //��ͬһ�����ϣ�������
			return;
		//���򣬺ϲ���������
		group[a].insert(group[a].end(), group[b].begin(), group[b].end());
		group[b].clear();
	}
	//�Ӽ�����ȡ����Ԫ��
	else if (op == 2)
	{
		int pos = a;
		Find(group, pos);
		if (group[pos].size()>1)//�����Ԫ�����ڼ��ϵ�Ԫ�ظ�������1����ô����Ԫ�ز��뵽����Ϊ�յļ�����
		{
			//��ԭ������ɾ��
			for (size_t i = 0; i<group[pos].size(); ++i)
				if (group[pos][i] == a)
				{
				group[pos].erase(group[pos].begin() + i);
				break;
				}
			//�����¼���
			for (auto& arr : group)
				if (arr.size() == 0)
					arr.push_back(a);
		}
	}
	//��ӡ��Ԫ�����ڼ��ϵ�Ԫ�ظ���
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
	int a, b;//������
	cin >> T;
	while (T--)//T������
	{
		cin >> N >> M;
		vector<vector<int>> group(N);
		for (int i = 0; i<N; ++i)
			group[i].push_back(i + 1);
		while (M--)//M�в���
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