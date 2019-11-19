#if 0
//1.二进制插入

class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		return (n + (m << j));
	}
};
//2.查找组成一个偶数最接近的两个素数

#include<iostream>
using namespace std;
bool IsPrime(int n)
{
	for (int i = 2; i < n; ++i)
		if (n%i == 0)
			return false;
	return true;
}
void Parse(int& n)
{
	int ret1 = n / 2;
	int ret2 = n - ret1;
	while (1)
	{
		if (IsPrime(ret1) && IsPrime(ret2))
			break;
		ret1--;
		ret2++;
	}
	cout << ret1 << endl;
	cout << ret2 << endl;
}
int main()
{
	int n;
	while (cin >> n)
		Parse(n);
	return 0;
}
#endif