// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	vector<long> arr{ 1, 2 };
	while (cin >> n)
	{
		if (n>arr.size() && n < 5)
			for (int i = arr.size(); i <= n; ++i)
				arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2]);
		else if (n>arr.size() && n>5)
			for (int i = arr.size(); i <= n; ++i)
				arr.push_back(arr[arr.size() - 1] + 2 * arr[arr.size() - 2]);
		cout << arr[n - 1] << endl;
	}
	return 0;
}