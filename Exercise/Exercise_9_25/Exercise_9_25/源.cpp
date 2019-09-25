#if 0
#include<iostream>
using namespace std;

int Add(int n1, int n2)
{
	int sum, jw;
	while (n2)
	{
		sum = n1 ^ n2;
		jw = (n1 & n2) << 1;
		n1 = sum;
		n2 = jw;
	}
	return n1;
}
int main()
{
	int n1, n2;
	while (cin >> n1 >> n2)
		cout << n1 << " + " << n2 << " = " << Add(n1, n2) << endl;
	return 0;
}
#endif