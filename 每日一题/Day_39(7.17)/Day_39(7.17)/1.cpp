//数组中出现次数超过一半的数字

#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers)
{
	if (numbers.empty())
		return 0;
	if (numbers.size() == 1)
		return numbers[0];
	sort(numbers.begin(), numbers.end());
	int count = 1;
	size_t i = 1;
	for (; i<numbers.size(); ++i)
	{
		if (numbers[i] == numbers[i - 1])
			count++;
		else
			count = 1;
		if (count > numbers.size() / 2)
			break;
	}
	if (count>numbers.size() / 2)
		return numbers[i];
	return 0;

}

int main()
{
	vector<int> arr{ 1 };
	cout << MoreThanHalfNum_Solution(arr) << endl;
	return 0;
}
#endif
