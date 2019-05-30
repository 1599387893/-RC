//2
//最小公倍数
#include<iostream>
using namespace std;

int fun(int n, int m)
{
	while (n%m)
	{
		int temp = n;
		n = m;
		m = temp % m;
	}
	return m;
}
int main()
{
	int n, m;
	cin >> n >> m;
	cout << (n*m) / fun(n, m) << endl;
	system("pause");
	return 0;
}