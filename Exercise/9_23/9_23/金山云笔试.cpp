#if 1
#include <iostream>
#include <vector>
using namespace std;

bool LeftRightSameWeight(vector<int> weight)
{
	int size = weight.size();
	//先找到第一个非叶子节点
	int parent = size / 2 - 1;
	int child = 0;
	while (parent >= 0)
	{
		child = parent * 2 + 1;
		if (child + 1 < size && weight[child] == weight[child + 1])
			return true;
		weight[parent] += weight[child] + weight[child + 1];
		parent--;
	}
	return false;
}
int main()
{
	int T = 0;
	cin >> T;
	int n = 0;
	vector<int> weight;
	while (cin >> n)
		weight.push_back(n);
	int size = weight.size() / T;
	for (int i = 0; i < T; ++i)
	{
		vector<int> temp;
		for (int j = 0; j < size; ++j)
			temp.push_back(weight[j + (size * i)]);
		if (LeftRightSameWeight(temp))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
#endif


#if 0
#include <iostream>
using namespace std;

int FindFive(int n)
{
	int count = 0;
	while (n)
	{
		if (n % 10 == 5)
			count++;
		n /= 10;
	}
	return count;
}
int main()
{
	int n = 0;
	cin >> n;
	int count = 0;
	for (int i = 5; i <= n; ++i)
		count += FindFive(i);
	cout << count << endl;
	return 0;
}
#endif





#include <iostream>
#include <vector>
using namespace std;

bool LeftRightSameWeight(vector<int> weight)
{
	int size = weight.size();
	int child = 0;
	for (int i = size / 2 - 1; i >= 0; --i)
	{
		child = i * 2 + 1;
		weight[i] = weight[child] + weight[child + 1];
	}
	for (int i = 0; i < size / 2 - 1; i++)
	{
		child = i * 2 + 1;
		if (weight[child] == weight[child + 1])
			return true;
	}
	return false;
}
int main()
{
	int T = 0;
	cin >> T;
	int n = 0;
	vector<int> weight;
	while (cin >> n)
		weight.push_back(n);
	int size = weight.size() / T;
	for (int i = 0; i < T; ++i)
	{
		vector<int> temp;
		for (int j = 0; j < size; ++j)
			temp.push_back(weight[j + (size * i)]);
		if (LeftRightSameWeight(temp))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}


long Fun_mn(int n, int m)
{
	long up = 1;
	long botton = 1;
	for (int i = 1; i <= n; ++i)
	{
		up *= m;
		m--;
		botton *= 1;
	}
	return up / botton;
	

}