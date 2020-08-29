#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n = 0;
	string T = "";
	cin >> n >> T;
	int start = 0, end = T.size() - 1;
	char c = 'M';
	//先处理头串
	for (int i = 0; i < (int)T.size(); ++i)
	{
		if (T[i] == c)
		{
			if (c == 'M')
				c = 'T';
			else
			{
				start = i + 1;
				break;
			}
		}
	}
	//在处理尾串
	for (int i = T.size() - 1; i >= 0; --i)
	{
		if (T[i] == c)
		{
			if (c == 'T')
				c = 'M';
			else
			{
				end = i;
				break;
			}
		}
	}
	cout << T.substr(start, end - start) << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<int> res(n, -1);
	vector<vector<int>> want(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> want[i][j];
	//先满足编号小的
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (res[want[i][j] - 1] == -1)
			{
				res[want[i][j] - 1] = i + 1;
				break;
			}
		}
	}
	for (auto pos : res)
		cout << pos << " ";
	cout << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int FindTime(int x, int y, const vector<pair<int, int>>& way, int time)
{
	if (x == y)
		return time;
	for (int i = 0; i < way.size(); ++i)
		if ((way[i].first == x && way[i].second == y) || (way[i].first == y && way[i].second == x))
			return time + 1;
	//找出x和y下一步走的地方
	int xNext = x, yNext = y;
	for (int i = 0; i < way.size(); ++i)
	{
		if (way[i].first == x)
			xNext = way[i].second;
		else if (way[i].second == x)
			xNext = way[i].first;
		if (way[i].first == y)
			yNext = way[i].second;
		else if (way[i].second == y)
			yNext = way[i].first;
	}
	return FindTime(xNext, yNext, way, time + 1);
}
int main()
{
	int n = 0, x = 0, y = 0;
	cin >> n >> x >> y;
	vector<pair<int, int>> way(n - 1);
	for (int i = 0; i < n - 1; ++i)
		cin >> way[i].first >> way[i].second;
	cout << FindTime(x, y, way, 1) << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0, m = 0, w = 0;
	cin >> n;
	vector<int> A(n + 1);
	vector<int> B(n + 1, -1);
	for (int i = 1; i <= n; ++i)
		cin >> A[i];
	cin >> m;
	int k = 0, x = 0, y = 0;
	while (m--)
	{
		cin >> w;
		if (w == 1)
		{
			cin >> k >> x >> y;
			for (int i = 0; i < k; ++i)
				B[y++] = A[x++];
		}
		else
		{
			cin >> x;
			cout << B[x] << endl;
		}
	}
	return 0;
}
#endif