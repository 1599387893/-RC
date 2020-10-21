#if 0
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int k = 0, n = 0;
	cin >> k;
	map<int, bool> m;
	while (cin >> n)
		m[n] = true;
	auto p = m.end();
	for (int i = k; k > 0; --k, p--);
	cout << p->first << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> pq;
	unordered_map<int, bool> um;
	int n;
	while (cin >> n)
	{
		if (um.find(n) != um.end())
			continue;
		pq.push(n);
		um[n] = true;
	}
	for (int i = 0; i < 3 && !pq.empty(); ++i)
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	return 0;
}
#endif


#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string GetBinaryCode(int n)
{
	string code;
	string res;
	while (n)
	{
		code += to_string(n % 2);
		n /= 2;
	}
	int pos = code.size() - 1 - 7;
	bool odd = false;
	for (int i = 0; i < code.size(); ++i)
	{
		if (i % 8 == 7)
		{
			if (i == 7 && i + 1 < code.size())
				res += '1';
			else
				res += '0';
			res += code[i];
			//odd = code[i] == '1' ? true : false;
		}
		else
		{
			res += code[i];
			/*
			if (code[i] == '0')
			{
				res += odd ? '1' : '0';
				odd = false;
			}
			else
			{
				if (odd)
					res += '0';
				else
				{
					res += '1';
					odd = false;
				}
			}*/
		}
	}
	if (odd)
		res += '1';
	while (res.size() % 8 != 0)
	{
		res += '0';
	}
	if (res.size() == 8)
		res[7] = '1';
	reverse(res.begin(), res.end());
	return res;
}
int main()
{
	int n = 0;
	cin >> n;
	cout << GetBinaryCode(n) << endl;
	return 0;
}

#endif

#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	string str;
	cin >> str;
	stack<char> sta;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			sta.push(str[i]);
		else if (str[i] == ')')
		{
			if (!sta.empty() && sta.top() == '(')
				sta.pop();
			else
				break;
		}
		else if (!sta.empty() && str[i] == ']')
		{
			if (sta.top() == '[')
				sta.pop();
			else
				break;
		}
		else if (!sta.empty() && str[i] == '}')
		{
			if (sta.top() == '{')
				sta.pop();
			else
				break;
		}
	}
	cout << (sta.empty() ? "true" : "false") << endl;
	return 0;
}
