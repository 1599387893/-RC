//1
//排列n组队伍（3人一组）的水平，使得所有队伍中的第二高水平人的和最大；
//输入示例：
//			2
//			1 2 3 2 3 2
//输出示例：
//			4

#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;//队伍数
	vector<int> v;//存放队员
	v.resize(n * 3);
	int sum = 0;//输出值

	for (int i = 0; i < 3 * n; ++i)
		cin >> v[i];

	std::sort(v.begin(), v.end());
	for (int i = n; i < 3 * n; i += 2)
		sum += v[i];

	cout << sum << endl;

	system("pause");
	return 0;

}
#endif


