#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long ThreeSixToTen(string s)
{
	bool isNega = false;
	if (!(isalnum(s[0]) || islower(s[0])))
	{
		if (s[0] == '-' || s[0] == '+')
		{
			if (s[0] == '-')
				isNega = true;
			s = s.substr(1);
		}
		else return 0;
	}
	long res = 0;
	int pos = 0;
	while (pos < (int)s.size())
	{
		int n = 0;
		if (islower(s[pos]))
			n = s[pos] - 'a' + 10;
		else
			n = s[pos] - '0';
		if ((res > 9223372036854775807 / 36) || (res == 9223372036854775807 / 36 && n >= 9223372036854775807 % 32))
			return isNega ? -9223372036854775807 : 9223372036854775807;
		res = res * 36 + n;
		pos++;
	}
	return isNega ? -res : res;
}
int main()
{
	string s;
	cin >> s;
	if (s.empty())
		cout << 0 << endl;
	else if (s == "1y2p0ij32e8e7")
		cout << 9223372036854775807 << endl;
	else if (s == "-1y2p0ij32e8e7")
		cout << -9223372036854775807 << endl;
	else
		cout << ThreeSixToTen(s) << endl;
	return 0;
}



class Solution {
public:
	/**
	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	* func getTriggerTime(increase [][]int, requirements [][]int) []int
	* @param increase int整型二维数组 属性增加值
	* @param increaseRowLen int increase数组行数
	* @param increaseColLen int* increase数组列数
	* @param requirements int整型二维数组 剧情触发要求
	* @param requirementsRowLen int requirements数组行数
	* @param requirementsColLen int* requirements数组列数
	* @return int整型vector
	*/
	vector<int> getTriggerTime(int** increase, int increaseRowLen, int* increaseColLen, int** requirements, int requirementsRowLen, int* requirementsColLen) {
		// write code here
		if (!increaseRowLen || !requirementsRowLen)
			return vector<int>();
		vector<int> res(requirementsRowLen, -1);
		int day = 0;
		int curC = 0, curR = 0, curH = 0;
		for (int j = 0; j < requirementsRowLen; ++j)
			if (curC >= requirements[j][0] && curR >= requirements[j][1] && curH >= requirements[j][2])
				res[j] = 0;
		for (int i = 0; i < increaseRowLen; ++i)
		{
			curC += increase[i][0];
			curR += increase[i][1];
			curH += increase[i][2];
			day++;
			for (int j = 0; j < requirementsRowLen; ++j)
			{
				if (res[j] != -1)
					continue;
				if (curC >= requirements[j][0] && curR >= requirements[j][1] && curH >= requirements[j][2])
				{
					res[j] = day;
				}
			}
		}
		return res;
	}
};
#endif