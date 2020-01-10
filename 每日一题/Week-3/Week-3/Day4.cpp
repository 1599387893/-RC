//1.INOC产品部--完全数计算
#if 0
#include<iostream>
#include<vector>
using namespace std;

bool IsPerfectNum(int n)
{
	int count = 0;
	for (int i = 1; i <= n / 2; ++i)
		if (n%i == 0)
			count += i;
	if (count == n)
		return true;
	return false;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 1; i <= n; ++i)
			if (IsPerfectNum(i))
				count++;
		cout << count << endl;
	}
	return 0;
}
#endif