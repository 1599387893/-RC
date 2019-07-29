#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct record
{
	record(string s, size_t cols, size_t counts = 1)
		:path(s)
		, col(cols)
		, count(counts){}
	string path;
	size_t col;
	size_t count;
}record;
void addRecord(vector<record>& v, string s, size_t cols, int sit)
{
	string path = s.substr(s.find_last_of('\\'));
	if (path.size()>16)
		path.substr(path.size() - 15, path.size());
	for (auto& e : v)
	{
		if (e.path == path && e.col == cols)
		{
			e.count++;
			break;
		}
	}
	record r(path, cols);
	v[sit] = r;
}
int main()
{
	vector<record> v;
	v.resize(8);
	string s;
	size_t cols = 0;
	int sit = 1;
	while (cin >> s >> cols)
	{
		sit %= 8;
		addRecord(v, s, cols, sit);
		for (auto& e : v)
			cout << e.path << " " << e.col << " " << e.count << endl;
		v.clear();
	}
	return 0;
}