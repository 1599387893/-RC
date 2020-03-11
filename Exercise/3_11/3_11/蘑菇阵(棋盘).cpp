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

//���з��� C��m+n,n);

//����������г�����P(k, h)�����ߵ��������ô�ͷֲ��裻����û��P�ж����ּ���Ϊ��M�������0��0����P��m1�֣�Ȼ�����P����m, n����m2�֣�
//��M - (m1*m2); ��������������

//�������������� ��Ϊÿ��һ�����и��ʵı仯������������·����������

//����Ϊ��ȷ�ⷨ

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		vector<vector<int>> table((n + 1), vector<int>(m + 1, 0));//�ݵ�
		vector<vector<double>> p((n + 1), vector<double>(m + 1, 0));//�����ߵ�ÿ��λ�õĸ���
		int x, y;
		while (k--)
		{
			cin >> x >> y;
			table[x][y] = 1;
		}
		p[1][1] = 1.0;//���ĸ���Ϊ 1
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (!(i == 1 && j == 1))
				{
					//p[i][j]�õ��п��ܴ���߻����ϱ�����
					//��˸ýڵ�ĸ���Ϊ : (p[i-1][j] + p[i][j-1])/2;���Ǳ߽�ڵ�
					//���ߣ�(p[i-1][j] + p[i][j-1]/2);���һ�еĽڵ�
					//���ߣ�(p[i-1][j]/2 + p[i][j-1]);���һ�еĽڵ㣻
					p[i][j] = p[i - 1][j] * (j == m ? 1 : 0.5) + p[i][j - 1] * (i == n ? 1 : 0.5);
					if (table[i][j] == 1)  //�жϸõ��Ƿ���Ģ������Ģ���Ļ������ߣ�����Ϊ0
						p[i][j] = 0;
				}
			}
		}
		printf("%.2f\n", p[n][m]);
	}
	return 0;
}

#endif




