#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<cstring>
using namespace std;


//1.Fibonacci数列
int MinStep(int& n)
{
	if (n <= 3)
		return 0;
	int left = 3;
	int right = 5;
	int temp;
	while (!((left <= n) && (right >= n)))
	{
		temp = left;
		left = right;
		right += temp;
	}
	return ((n - left) < (right - n) ? (n - left) : (right - n));
}
void Test1()
{
	int n;
	while (cin >> n)
		cout << MinStep(n) << endl;
}



//2.合法括号序列判断
bool chkParenthesis(string A, int n) {
	// write code here
	if (n % 2 != 0)
		return false;
	stack<char> st;
	for (int i = 0; i < A.size(); ++i)
	{
		if (A[i] != '(' && A[i] != ')')
			return false;
		if (st.empty())
		{
			if (A[i] == ')')
				return false;
			st.push(A[i]);
		}
		else
		{
			if (st.top() == '(' && A[i] == ')')
			{
				st.pop();
				continue;
			}
			else
				st.push(A[i]);
		}
	}
	return st.empty();
}
void Test2()
{
	string s;
	while (getline(cin, s))
	{
		cout << chkParenthesis(s, s.size()) << endl;
	}
}

/*
int main()
{
	Test1();
	Test2();
	system("pause");
	return 0;
}*/