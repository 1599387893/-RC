#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	vector<int> arr{-1,0,1,2,-1,4};
	set<vector<int>> res;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size() - 2; ++i)
	{
		int j = i + 1;
		int k = (int)arr.size() - 1;
		while (j < k)
		{
			int sum_two = arr[j] + arr[i];
			if (sum_two + arr[k] < 0)
				j++;
			else if (sum_two + arr[k] > 0)
				k--;
			else
			{
				res.insert(vector < int > {arr[i], arr[j], arr[k]});
				k--;
				j++;
			}
		}
	}
	for (const auto& ar : res)
	{
		for (const auto& n : ar)
			cout << n << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}