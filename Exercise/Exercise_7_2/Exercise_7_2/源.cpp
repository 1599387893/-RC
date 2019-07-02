#include<iostream>
#include<string>
using namespace std;

int find_root(int& num)
{
	int root = 0;
	while (num >= 10)
	{
		root = 0;
		while (num)
		{
			root += num % 10;
			num /= 10;
		}
		num = root;
	}
	return root;
}

int main()
{
	string num;
	while (cin >> num)
	{
		int sum = 0;
		for (auto t = num.begin(); t != num.end(); t++) {
			sum = sum + (*t) - '0';
		cout << find_root(sum) << endl;
	}

	return 0;
}