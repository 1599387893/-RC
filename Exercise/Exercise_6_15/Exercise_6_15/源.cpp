#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include<iostream>
#include<cmath>
using namespace std;

int l[20];//�ʺ���������
int n;//�ʺ����

void output(int n) {//���n�ʺ��ĳ����
	int i;
	for (i = 1; i <= n; i++) {
		cout << l[i];
	}
	cout << endl;
}

int place(int t, int r) {//�жϵ�r�лʺ��ܷ���ڵ�t��
	int i = 1;
	while (i<r){//�ʺ������rһ��Ҫ����i
		if (t == l[i] || abs(r - i) == abs(t - l[i])) {
			return 0;
		}
		++i;
	}
	return 1;
}

void nqueen(int m) {//�ݹ����
	int i;
	for (i = 1; i <= n; i++) {
		l[m] = i;
		if (place(i, m)) {
			if (m == n) {
				output(n);//������һ���ʺ�Ҳ������ϣ���������
			}
			else {
				nqueen(m + 1);//���򣬽�����һ���ʺ�ķ���
			}
		}
	}
}

int main() {
	cout << "������1~20���ڵ�����Ϊ�ʺ������";
	cin >> n;
	if (n > 20) {
		cout << "����ֵƫ�����������룺";
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
int vis[3][50], P[15];//�������� �I���J�ڴ��������򶼲����лʺ� 
int n, sum;

void  DFS(int row);

int main()
{
	for (n = 1; n <= 10; n++)//�ȴ��Ȼ�ᳬʱ��
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
	if (row == n + 1)//�Ѿ���n����
	{
		sum++;
		return;
	}
	for (i = 1; i <= n; i++)
	{
		if (vis[0][row - i + n] == 0 && vis[1][i] == 0 && vis[2][row + i] == 0)
		{//������ݵ�ͬѧҪ�úÿ���ѧϰѧϰ
			vis[0][row - i + n] = vis[1][i] = vis[2][row + i] = 1;//��ֵ
			DFS(row + 1);//����
			vis[0][row - i + n] = vis[1][i] = vis[2][row + i] = 0;//����
		}
	}
}