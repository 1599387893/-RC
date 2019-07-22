#if 0
#include<vector>
#include<iostream>
#include<string>
using namespace std;

int find(vector<char> v, char a)
{
	for (size_t i = 0; i<v.size(); ++i)
		if (v[i] == a)
			return i;
	return -1;
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n<1 || n>1000)
			continue;
		vector<char> v;
		char id;
		string oper;
		size_t max = 0;
		while (n--)
		{
			cin >> id >> oper;
			int pos = find(v, id);
			if (oper == "connect" && pos == -1)
				v.push_back(id);
			if (oper == "disconnect" && pos != -1)
				v.erase(v.begin() + pos);
			if (v.size()>max)
				max = v.size();
		}
		cout << max << endl;
	}
	return 0;
}
#endif

#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;

void Judge_mkdir(vector<string>& v, string ml)
{
	for (size_t i = 0; i<v.size(); ++i)
	{
		if (ml.find(v[i]) != -1)
		{
			v.erase(v.begin() + i);
			v.push_back(ml);
			return;
		}
		if (v[i].find(ml) != -1)
			return;
	}
	v.push_back(ml);
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<string> v;
		string ml;
		int i = n;
		while (i--)
		{
			cin >> ml;
			if (i == n - 1)
				v.push_back(ml);
			else
				Judge_mkdir(v, ml);
		}
		set<string> s;
		for (size_t i = 0; i<v.size(); ++i)
			s.insert(v[i]);
		for (auto& e : s)
			cout << "mkdir -p " << e << endl;
		cout << endl;
	}
	return 0;
}