#if 0
// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

int MinPage(int& wage)
{
	int res = 0;
	vector<int> worth{ 100, 50, 20, 10, 5, 2, 1 };
	int pos = 0;
	while (pos < worth.size() - 1)
	{
		while (wage >= worth[pos])
		{
			wage -= worth[pos];
			res++;
		}
		pos++;
	}
	return res + wage;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		int res = 0;
		int wage = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> wage;
			res += MinPage(wage);
		}
		cout << res << endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());
	auto pos = 0;
	while (pos != string::npos)
	{
		auto next = s.find(' ', pos);
		if (next == string::npos)
			break;
		reverse(s.begin() + pos, s.begin() + next);
		pos = next + 1;
	}
	reverse(s.begin() + pos, s.end());
	cout << s << endl;
	return 0;
}
#endif 


#include <iostream>
#include <string>
using namespace std;

void Release(string& str)
{
	for (auto& n : str)
	{
		if (n >= 'A' && n <= 'Z')
		{
			if (n >= 'F')
				n -= 5;
			else
				n = 'Z' - (4 - (n - 'A'));
		}
	}
}
int main()
{
	string str;
	while (getline(cin, str))
	{
		if (str == "ENDOFINPUT")
			break;
		getline(cin, str);//接收密文
		Release(str);
		cout << str << endl;
		getline(cin, str);//接收END
	}
	return 0;
}