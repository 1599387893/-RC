#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> arr{4,3,2,7,8,2,3,1};
	for (int i = 0; i < arr.size(); ++i)
		arr[abs(arr[i] - 1)] = -abs(arr[abs(arr[i])-1]);
	vector<int> res;
	for (int i = 0; i < arr.size(); ++i)
		if (arr[i])
			res.push_back(i + 1);
	return 0;
}