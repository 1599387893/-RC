//// write your code here cpp
#include<iostream>
using namespace std;

double literal(double n)
{
	if (n == 0 || n == 1)
		return 0;
	if (n == 2)
		return 1;
	return ((n - 1)*(literal(n - 1) + literal(n - 2)));
}
double fact(int n)
{
	double ret = 1;
	while (n)
	{
		ret *= n;
		n--;
	}
	return ret;
}
int main()
{
	double people = 0;
	while (cin >> people)
	{
		double no_prize = (literal(people) / fact(people));
		printf("%.2f%\n", no_prize * 100);
	}
	return 0;
}