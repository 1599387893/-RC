//变态跳台阶
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#if 0
int jumpFloorII(int number) {
	if (number <= 1)
		return number;
	int total = 1;
	for (int i = 1; i<number; ++i)
		total *= 2;
	return total;
}
int jumpFloorIII(int number)
{
	class Solution {
	public:
		int jumpFloorII(int number) {
			return 1 << (--number);
		}
	};
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << jumpFloorII(n) << endl;
	}
}

#endif
//最大连续子数组和
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int maxsum = array[0];
		int sumi = array[0];
		for (int i = 1; i < array.size(); ++i)
		{
			sumi = max(sumi + array[i], array[i]);
			if (sumi > maxsum)
				maxsum = sumi;
		}
		return maxsum;
	}
};


//