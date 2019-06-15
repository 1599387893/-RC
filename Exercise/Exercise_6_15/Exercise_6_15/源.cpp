#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include<iostream>
#include<cmath>
using namespace std;

int l[20];//皇后所在列数
int n;//皇后个数

void output(int n) {//输出n皇后的某个解
	int i;
	for (i = 1; i <= n; i++) {
		cout << l[i];
	}
	cout << endl;
}

int place(int t, int r) {//判断第r行皇后能否放在第t列
	int i = 1;
	while (i<r){//皇后的行数r一定要大于i
		if (t == l[i] || abs(r - i) == abs(t - l[i])) {
			return 0;
		}
		++i;
	}
	return 1;
}

void nqueen(int m) {//递归求解
	int i;
	for (i = 1; i <= n; i++) {
		l[m] = i;
		if (place(i, m)) {
			if (m == n) {
				output(n);//如果最后一个皇后也放置完毕，则输出结果
			}
			else {
				nqueen(m + 1);//否则，进行下一个皇后的放置
			}
		}
	}
}

int main() {
	cout << "请输入1~20以内的数作为皇后个数：";
	cin >> n;
	if (n > 20) {
		cout << "输入值偏大，请重新输入：";
		cin >> n;
	}
	nqueen(1);
	system("pause");
	return 0;
}
#endif

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int vis[3][50], P[15];//三个方向 ↖↑↗在此三个方向都不能有皇后 
int n, sum;

void  DFS(int row);

int main()
{
	for (n = 1; n <= 10; n++)//先打表不然会超时的
	{
		memset(vis, 0, sizeof(vis));
		sum = 0;
		DFS(1);
		P[n] = sum;
	}
	while (scanf("%d", &n))
	{
		printf("%d\n", P[n]);
	}
	system("pause");
	return 0;
}

void  DFS(int row)
{
	int i;
	if (row == n + 1)//已经够n行了
	{
		sum++;
		return;
	}
	for (i = 1; i <= n; i++)
	{
		if (vis[0][row - i + n] == 0 && vis[1][i] == 0 && vis[2][row + i] == 0)
		{//不会回溯的同学要好好看看学习学习
			vis[0][row - i + n] = vis[1][i] = vis[2][row + i] = 1;//变值
			DFS(row + 1);//深搜
			vis[0][row - i + n] = vis[1][i] = vis[2][row + i] = 0;//回溯
		}
	}
}