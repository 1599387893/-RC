
// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> board;

bool fourDire(char color, int row, int col)
{
	if (row + 5<20 && col - 5 >= 0 && (board[row][col] == board[row + 1][col - 1] == board[row + 2][col - 2] == board[row + 3][col - 3] == board[row + 4][col - 1] == color))
		return true;
	if (row + 5<20 && (board[row][col] == board[row + 1][col] == board[row + 2][col] == board[row + 3][col] == board[row + 4][col] == color))
		return true;
	if (row + 5<20 && col + 5<20 && (board[row][col] == board[row + 1][col + 1] == board[row + 2][col + 2] == board[row + 3][col + 3] == board[row + 4][col + 4] == color))
		return true;
	if (col + 5<20 && (board[row][col] == board[row][col + 1] == board[row][col + 1] == board[row][col + 1] == board[row][col + 1] == color))
		return true;
	return false;
}
bool Judge_five(char color, int row, int col)
{
	if (fourDire(color, row, col))
		return true;
	int sit = board[row].find(col);
	if (sit == -1)
		return false;
	return Judge_five(color, row, col + 1);
}
int main()
{
	string cp;
	while (cin >> cp)
	{
		board.push_back(cp);
		bool ret = false;
		for (int i = 1; i<20; ++i)
		{
			cin >> cp;
			board.push_back(cp);
		}
		int black, white;
		//先找到第一个棋子
		for (int i = 0; i<20; ++i)
		{
			black = board[i].find('*');
			white = board[i].find('+');
			//判断该棋子的左下，下，右下，右这四个方向的棋子能否满足五子；
			if (black != -1)
			{
				ret = Judge_five('*', i, black);
				if (ret == true)
					break;
			}
			if (white != -1)
			{
				ret = Judge_five('+', i, white);
				if (ret == true)
					break;
			}
		}
		if (ret == true)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		board.clear();
	}
	return 0;
}

#if 0
// write your code here cpp
#include<iostream>
#include<stack>
#include<string>
using namespace std;

long oper(int a, int b, char c)
{
	if (c == '+')
		return a + b;
	if (c == '-')
		return a - b;
	if (c == '/')
	{
		if (b == 0)
			return -1;
		return a / b;
	}
	return a*b;

}
int main()
{
	int n;
	while (cin >> n)
	{
		string c;
		bool flag = true;
		stack<long int> s;
		while (n--)
		{
			cin >> c;
			if (c[0] == '+' || c[0] == '-' || c[0] == '*' || c[0] == '/')
			{
				if (s.size() >= 2)
				{
					long int a = s.top(); s.pop();
					long int b = s.top(); s.pop();
					s.push(oper(a, b, c[0]));
				}
				else
				{
					flag = false;
					break;
				}
			}
			else
				s.push(stoi(c.c_str()));
		}
		if (flag == false)
			cout << "-1" << endl;
		else
			cout << s.top() << endl;
	}
	return 0;
}
#endif
