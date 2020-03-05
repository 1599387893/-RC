#if 0
// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<long> fib{ 1, 1, 2, 3, 5 };
	int from, to;
	while (cin >> from >> to)
	{
		long sum = 0;
		if (to > fib.size())
			for (int i = fib.size(); i<to; ++i)
				fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
		for (int i = from - 1; i < to; ++i)
			sum += fib[i];
		cout << sum << endl;
	}
	return 0;
}


// write your code here cpp
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int from, to;
	while (cin >> from >> to)
	{
		long sum = 0, a = 1, b = 1;
		for (int i = 0; i < to; ++i)
		{
			if (i >= from - 1)
				sum += a;
			swap(a, b);
			b += a;
		}
		cout << sum << endl;
	}
	return 0;
}
#endif