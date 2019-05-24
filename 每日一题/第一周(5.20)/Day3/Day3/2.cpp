//2
//输出N个数字中出现次数大于等于N/2次的数字
//输入示例：
//			3 9 2 3 8 3 9 6 1 0 3 3
//输出示例：
//			3

#if 0
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>v;
	vector<int>temp;
	int n = 0;
	int retNumber = 0;
	
	int i = 0;
	while (cin >> n)
	{
		v.resize(i + 1);
		v[i++] = n;
	}
	temp.resize(v.size());
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = i + 1; j < v.size(); ++j)
		{
			if (v[i] == v[j])
				++temp[i];
		}
		if (temp[i] >= n / 2)
		{
			cout << v[i] << endl;
			break;
		}
	}
	system("pause");
	return 0;
}
#endif

#if 0
//解法二
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int>v;
	int n;
	
	while (cin >> n)
		v.push_back(n);
	sort(v.begin(), v.end());
	cout << v[v.size() / 2 - 1] << endl;
	system("pause");
	return 0;
}
#endif

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	while (cin >> n)
		v.push_back(n);

	int count = 1;
	int temp = v[0];
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i] == temp)
			++count;
		else
			--count;

		if (count == 0)
		{
			temp = v[i];
			count++;
		}
	}
	cout << temp << endl;
	system("pause");

	return 0;
}