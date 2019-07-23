// write your code here cpp// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;


int m, n, res = 0;
vector<vector<int>> v;
void DFS(int x, int y)
{
	if (v[x][y] == 1 || x<0 || y<0 || x >= m || y >= n)
		return;
	res++;
	v[x][y] = 1;
	DFS(x - 1, y);
	DFS(x + 1, y);
	DFS(x, y - 1);
	DFS(x, y + 1);
}

int main()
{
	while (cin >> m >> n)
	{
		v.resize(m);
		for (auto& e : v)
			e.resize(n);
		char color;
		int x = 0, y = 0;
		for (int i = 0; i<m; ++i)
		{
			for (int j = 0; j<n; ++j)
			{
				cin >> color;
				if (color != '.')
				{
					if (color == '@')
					{
						x = i;
						y = j;
						v[i][j];
						continue;
					}
					v[i][j] = 1;
				}
				else
					v[i][j] = 0;
			}
		}
		int res = 0;
		DFS(x, y);
		cout << res << endl;
		v.clear();
	}
	return 0;
}