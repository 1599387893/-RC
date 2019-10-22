#include<iostream>
#include<stack>
#include<string>
using namespace std;

int ate(string s) 
{
	stack<char> st;
	int size = s.size();
	for (int i = 0; i<size; ++i)
	{
		if (s[i] == '+' && s[i + 1] != '(')
		{
			int temp = st.top()-48 + s[i+1]-48;
			st.pop();
			st.push(temp+48);
			++i;
		}
		else if (s[i] == '-' && s[i + 1] != '(')
		{
			int temp = st.top()-48 - s[i+1]-48;
			st.pop();
			st.push(temp+48);
			++i;
		}
		else if (s[i] == ')')
		{
			int temp = st.top()-48;
			st.pop();
			st.pop();
			temp += (st.top()-48);
			st.pop();
			st.push(temp+48);
		}
		else
			st.push(s[i]);
	}
	return st.top() - 48;
}

int main()
{
	string s = "1 + 1";
	cout << ate(s) << endl;
	system("pause");
}