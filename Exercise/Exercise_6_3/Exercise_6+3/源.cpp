#include<iostream>
#include<string>
#include<vector>
using namespace std;

//xcopy /s c:\\ d:\\
//xcopy /s "c:\\" "d:\\"
int main()
{
	string s;
	getline(cin, s);
	vector<string>v;
	v.resize(4);
	for (auto e : v)
		e.resize(1);
	v[0] = "xcopy";
	v[1] = "/s";
	for (int i = 9; s[i] != ' '; ++i)
	{
		if (s[i] == '"')
			continue;
		v[2] += s[i];
	}
	int i = 9 + v[2].size() + 1;
	if (s[9] == '"')
		i = 9 + v[2].size() + 3;
	for (; i<s.size(); ++i)
	{
		if (s[i] == '"')
			continue;
		v[3] += s[i];
	}
	if (v[2][v[2].size()-1] == '\"')
	{
		v[2].erase(v[2].size() - 1, 1);
	}
	if (v[3][v[2].size()-1] == '\"')
	{
		v[3].erase(v[3].size() - 1, 1);
	}
	cout << "4" << endl;
	for (int i = 0; i<4; ++i)
		cout << v[i] << endl;

	system("pause");
	return 0;
}