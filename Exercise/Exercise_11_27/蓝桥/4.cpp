#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int ret = 0;
		int i = 0;
		while(n)
		{
			ret += (n%m)* pow(10,i);
			n /= m;
			i++;
		}
		cout << ret << endl;
	}
	return 0;
}