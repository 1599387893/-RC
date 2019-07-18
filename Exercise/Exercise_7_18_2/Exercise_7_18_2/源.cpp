#if 0
#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct record
{
	//    record(string s,size_t cols,size_t counts = 1)
	//       :path(s)
	//       ,col(cols)
	//       ,count(counts){}
	string path;
	size_t col;
	size_t count;
	void Init(string s, size_t cols, size_t counts = 1)
	{
		path.swap(s);
		col = cols;
		count = counts;
	}
}record;
void addRecord(vector<record>& v, string s, size_t cols, int sit)
{
	string path = s.substr(s.find_last_of('\\') + 1);
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
	record r;
	r.Init(path, cols);
	v[sit] = r;
}
int main()
{
	vector<record> v;
	v.resize(1);
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
#endif


#include<iostream>
#include<string>
#include<vector>
using namespace std;

void addRecord(vector<string>& vStr, vector<int>& vCol, vector<int>& vCount, string s,
	size_t cols, int sit)
{
	//先取出需要的路径
	string path = s.substr(s.find_last_of('\\') + 1);
	if (path.size()>16)
		path.substr(path.size() - 15, path.size());

	//在vStr中查找将该路径
	size_t StrPos = -1;
	for (size_t i = 0; i<vStr.size(); ++i)
		if (vStr[i] == path)
			StrPos = i;
	size_t ColPos = -1;
	for (size_t i = 0; i<vCol.size(); ++i)
		if (vCol[i] == cols)
			ColPos = i;
	if (StrPos != -1 && ColPos != -1 && StrPos == ColPos)
		vCount[StrPos]++;
	else
	{
		if (sit <= 8)
		{
			vStr.push_back(path);
			vCol.push_back(cols);
			vCount.push_back(1);
		}
		else
		{
			vStr[sit].swap(path);
			vCol[sit] = cols;
			vCount[sit] = 1;
		}

		sit++;
	}
}
int main()
{
	string s;
	size_t cols = 0;
	int sit = 1;
	while (cin >> s >> cols)
	{
		vector<string> vStr;
		vector<int> vCol;
		vector<int> vCount;
		//vStr.resize(1);
		//vCol.resize(1);
		//vCount.resize(1, 1);
		sit %= 8;
		if (sit == 0)
			sit = 8;
		addRecord(vStr, vCol, vCount, s, cols, sit);
		for (size_t i = 0; i<vStr.size(); ++i)
			cout << vStr[i] << " " << vCol[i] << " " << vCount[i] << endl;
	}
	return 0;
}