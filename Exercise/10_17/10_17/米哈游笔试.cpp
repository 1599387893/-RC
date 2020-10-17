#if 0
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int GetNumber(string& str, int& pos)
{
	int res = 0;
	int prePos = -1;
	if (str[pos] == '-')
	{
		prePos = pos;
		pos++;
	}
	while (pos < (int)str.size() && isdigit(str[pos]))
	{
		res = res * 10 + str[pos] - '0';
		pos++;
	}
	return prePos == -1 ? res : -1 * res;
}
int main()
{
	string str;
	int res = 0;
	cin >> str;
	if (str.size() == 1)
		cout << str << endl;
	else
	{
		stack<int> sta;
		stack<char> op;
		int pos = 0;
		while (pos < (int)str.size())
		{
			if (sta.empty())
			{
				int num = GetNumber(str, pos);
				sta.push(num);
			}
			if (pos < (int)str.size() && str[pos] == '+' || str[pos] == '*' || str[pos] == '(' || str[pos] == ')')
			{
				if (str[pos] == ')' && op.top() == '(')
					op.pop();
				else
					op.push(str[pos]);
				pos++;
			}
			if (pos < (int)str.size() && isdigit(str[pos]) || str[pos] == '-')
			{
				sta.push(GetNumber(str, pos));
			}
			while (sta.size() >= 2 && op.top() != '(')
			{
				int a = sta.top(); sta.pop();
				int b = sta.top(); sta.pop();
				if (op.top() == '+')
					sta.push(a + b);
				else if (op.top() == '*')
					sta.push(a * b);
				op.pop();
			}
		}
		cout << sta.top() << endl;
	}
	return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> Month{ { 0, 30, 27, 30, 29, 30, 29, 30, 30, 29, 30, 29, 30 }, \
						   { 0, 30, 28, 30, 29, 30, 29, 30, 30, 29, 30, 29, 30 } };
bool isLeapYear(int y)
{
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		return true;
	return false;
}
int Days(int year, int month, int day)
{
	int sum = 0;
	for (int i = 0; i < year; ++i)
	{
		if (isLeapYear(i))
			sum += 366;
		else
			sum += 365;
	}
	for (int i = 1; i < month; ++i)
		sum += Month[isLeapYear(year)][i];
	sum += day;
	return sum;
}
int DayGap(int y1, int m1, int d1, int y2, int m2, int d2)
{
	return abs(Days(y1, m1, d1) - Days(y2, m2, d2));
}
int main()
{
	int y1, m1, d1, w1;
	int y2, m2, d2;
	cin >> y1 >> m1 >> d1 >> w1 >> y2 >> m2 >> d2;
	int Day = DayGap(y1, m1, d1, y2, m2, d2);
	cout << Day % 7 + w1 << endl;
	return 0;
}
#endif