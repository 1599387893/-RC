#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1.不要二
int CountCake(vector<vector<int>>& box, int w, int h)
{
	int count = 0;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (((i % 4 == 0 || i % 4 == 1) && (j % 4 == 2 || j % 4 == 3)) || ((i % 4 == 2 || i % 4 == 3) && (j % 4 == 0 || j % 4 == 1)))
				box[i][j] = 0;
		}
		count += ((int)std::count(box[i].begin(), box[i].end(), 1));
	}
	return count;
}
int main()
{
	int w, h;
	vector<vector<int>> box;
	while (cin >> w >> h)
	{
		box.resize(h);
		for (int i = 0; i < h; ++i)
			box[i].resize(w, 1);
		cout << CountCake(box, w, h) << endl;
	}
	return 0;
}
//2.把字符串转成整数
//int StrToInt(string str) {
//	if (str.size() == 0)
//		return 0;
//	if (str.size() == 1)
//	{
//		if (str[0] >= '1' && str[0] <= '9')
//			return str[0] - '0';
//		else
//			return 0;
//	}
//	int ret = 0;
//	bool flag = false;
//	if (str[0] == '-')
//		flag = true;
//	if (str[0] >= '1' && str[0] <= '9')
//		ret += str[0] - '0';
//	for (int i = 1; i < str.size(); ++i)
//	{
//		if (str[i]<'0' || str[i]>'9')
//			return 0;
//		else
//			ret = ret * 10 + str[i] - '0';
//	}
//	if (flag)
//		ret = 0 - ret;
//	return ret;
//}
//
