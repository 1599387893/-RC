#if 0

#include<iostream>
#include<vector>
using namespace std;

double FindWay(vector<vector<int>>& board, bool touch, int n, int m)
{
	if (touch && ((n == 0 && m == 0) || board[n][m] != 0))
		return 0;
	if (n == 0 && m == 0)
		return 0;
	else if ((m == 0 && n == 1) || (n == 0 && m == 1))
		return 1;
	else if (n == 0 && m>1)
		return FindWay(board, touch, n, m - 1);
	else if (m == 0 && n>1)
		return FindWay(board, touch, n - 1, m);
	return FindWay(board, touch, n - 1, m) + FindWay(board, touch, n, m - 1);
}
int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		vector<vector<int>> board;// (n, vector < int > {});
		board.resize(n, vector<int>{});
		for (int i = 0; i < n; ++i)
			board[i].resize(m, 0);
		int x, y;
		while (k--)
		{
			cin >> x >> y;
			board[x - 1][y - 1] = 1;
		}
		double all = FindWay(board, false, n, m);
		double noTouch = FindWay(board, true, n, m);
		printf("%.2f\n", noTouch / all);
	}
	return 0;
}

//排列方法 C（m+n,n);

//如果当棋盘中出现了P(k, h)不能走的情况：那么就分步骤；先算没有P有多少种假设为：M；算出（0，0）到P有m1种；然后算出P到（m, n）有m2种；
//用M - (m1*m2); 就是最后的种数；

//上述方法有问题 因为每走一步都有概率的变化，不可以用总路线数来计算

//以下为正确解法

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		vector<vector<int>> table((n + 1), vector<int>(m + 1, 0));//草地
		vector<vector<double>> p((n + 1), vector<double>(m + 1, 0));//保存走到每个位置的概率
		int x, y;
		while (k--)
		{
			cin >> x >> y;
			table[x][y] = 1;
		}
		p[1][1] = 1.0;//起点的概率为 1
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (!(i == 1 && j == 1))
				{
					//p[i][j]该点有可能从左边或者上边来，
					//因此该节点的概率为 : (p[i-1][j] + p[i][j-1])/2;不是边界节点
					//或者：(p[i-1][j] + p[i][j-1]/2);最后一列的节点
					//或者：(p[i-1][j]/2 + p[i][j-1]);最后一行的节点；
					p[i][j] = p[i - 1][j] * (j == m ? 1 : 0.5) + p[i][j - 1] * (i == n ? 1 : 0.5);
					if (table[i][j] == 1)  //判断该店是否有蘑菇，有蘑菇的话不能走，概率为0
						p[i][j] = 0;
				}
			}
		}
		printf("%.2f\n", p[n][m]);
	}
	return 0;
}

#endif




