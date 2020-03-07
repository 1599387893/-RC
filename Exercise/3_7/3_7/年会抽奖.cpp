// write your code here cpp

//´íÅÅ¹«Ê½£º wrong[n] = (n-1)*(wrong[n-1]+wrong[n-2]);
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	double n;
	vector<double> nowin{ 0, 0, 1 };
	vector<double> all{ 0, 1, 2 };
	for (int i = 3; i <= 20; ++i)
	{
		nowin.push_back((i - 1)*(nowin[i - 1] + nowin[i - 2]));
		all.push_back(all[i - 1] * i);
	}
	while (cin >> n)
		printf("%.2f%%\n", nowin[n] / all[n] * 100);
	return 0;
}