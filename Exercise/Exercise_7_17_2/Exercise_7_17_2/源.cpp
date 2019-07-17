#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers)
{
	if (numbers.empty())
		return 0;
	if (numbers.size() == 1)
		return numbers[0];
	sort(numbers.begin(), numbers.end());
	int count = 1;
	size_t i = 1;
	for (; i<numbers.size(); ++i)
	{
		if (numbers[i] == numbers[i - 1])
			count++;
		else
			count = 1;
		if (count > numbers.size() / 2)
			break;
	}
	if (count>numbers.size() / 2)
		return numbers[i];
	return 0;

}

int main()
{
	vector<int> arr{1};
	cout<<MoreThanHalfNum_Solution(arr)<<endl;
	return 0;
}
#endif

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