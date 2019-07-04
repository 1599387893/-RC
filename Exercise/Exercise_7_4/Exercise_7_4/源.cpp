#include<iostream>
#include<vector>
using namespace std;

void oddInOddEvenInEven(vector<int>& arr, int len) {
	int odd = 1;
	int even = 0;
	while (odd < len && even < len)
	{
		while (odd<len)
		{
			if (arr[odd] % 2 == 0)
				break;
			odd += 2;
		}
		while (even < len)
		{
			if (arr[even] % 2 == 1)
				break;
			even += 2;
		}
		swap(arr[odd], arr[even]);
		odd += 2;
		even += 2;
	}
}
int main()
{
	vector<int>v{1,2,3,4,5};
	for (auto& e : v)
		cout << e << " ";
	cout << endl;
	oddInOddEvenInEven(v,v.size());
	for (auto& e : v)
		cout << e << " ";
	cout << endl;

	return 0;

}