#include<iostream>
#include<vector>
using namespace std;

int TotalPath(int n, int m)
{
	vector<vector<int>>v;
	v.resize(n + 1);
	for (auto& e : v)
		e.resize(m + 1, 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			v[i][j] = v[i - 1][j] + v[i][j - 1];
	return v[n][m];
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 || m == 0)
			return 0;
		cout << TotalPath(n, m) << endl;
	}
	system("pause");
	return 0;
}