// write your code here cpp
#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;

int main()
{
	int num;
	vector<int> fib{ 1, 2, 3, 5, 8, 13, 21, 34, 55 };
	while (cin >> num)
	{
		if (num < fib.size())
			cout << fib[num - 1] << endl;
		else
		{
			int a = fib[fib.size() - 2], b = fib[fib.size() - 1];
			for (int i = fib.size(); i < num; ++i)
			{
				fib.push_back((a + b) % 1000000);
				a = b;
				b = fib[fib.size() - 1];
			}
			if (num<37)
				cout << fib[num - 1] << endl;
			else
				cout << setfill('0') << setw(6) << fib[num - 1] << endl;
		}
	}
	return 0;
}