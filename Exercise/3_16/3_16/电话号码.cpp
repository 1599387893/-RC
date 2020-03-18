#if 0
#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;

vector<int> pos{2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };
void GetNumber(string& str)
{
	string temp;
	for (size_t i = 0; i <str.size(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			temp += pos[str[i] - 'A'] + '0';
		else if (str[i] >= '0' && str[i] <= '9')
			temp.push_back(str[i]);
	}
	temp.insert(temp.begin() + 3, '-');
	str = temp;
}
int main()
{
	int n;
	string temp;
	while (cin >> n)
	{
		set<string> s;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			GetNumber(temp);
			s.insert(temp);
		}
		for (const auto str : s)
			cout << str << endl;
		cout << endl;
	}
	return 0;
}

#endif