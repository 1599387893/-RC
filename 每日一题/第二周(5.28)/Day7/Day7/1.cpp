//1
//fibonacci数列（输入一个数，最少多少步可以将该数++或--成Fibonacci数）
//输入示例：
//			15
//输出示例：
//			2


#if 0
//标准答案
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	int lessN = 0;
	int greaN = 0;
	int f, f0 = 0, f1 = 1;
	cin >> N;

	while (1)
	{
		f = f0 + f1;
		f0 = f1;
		f1 = f;

		if (f < N)
			lessN = N - f;
		else
		{
			greaN = f - N;
			break;
		}
	}
	cout << min(lessN, greaN) << endl;
	system("pause");
	return 0;
}


#include<iostream>
using namespace std;

int fibonacci(int n)
{
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main()
{
	int step = 0;
	int N;
	cin >> N;
	if (N<1 || N>1000000)
		return 0;
	int lesN = 0;
	int greN = 0;
	int i = 0;
	for (i = 0; greN<N; ++i)
		greN = fibonacci(i);

	lesN = fibonacci(i-2);
	(greN - N)>(N - lesN) ? step = N - lesN : step = greN - N;

	cout << step << endl;
	system("pause");
	return 0;
}
#endif