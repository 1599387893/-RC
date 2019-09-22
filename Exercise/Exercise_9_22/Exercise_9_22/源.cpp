#if 0
#include<iostream>
using namespace std;


//键值对
template<class T1,class T2>
struct Pair
{
	typedef T1 first_type;
	typedef T2 second_type;
	T1 first;
	T2 second;

	Pair()
		:first(T1())
		, second(T2())
	{}

	Pair(const T1& a,const T2& b)
		:first(a)
		, second(b)
	{}
	friend ostream& operator<<(ostream& out,const Pair<T1, T2>& p);
};
template<class T1,class T2>
ostream& operator<<(ostream& out, const Pair<int, int>& p)
{
	out << p.first << "-" << p.second;
	return out;
}

int main()
{
	Pair<int, int> p;
	cout << p << endl;
	system("pause");
	return 0;
}
#endif

#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	map<string, string> m1;
	map<string, string> m2{ { "apple", "苹果" },
	{ "banan", "香蕉" },
	{ "orange", "橘子" },
	{ "peach", "桃子" },
	{ "waterme", "水蜜桃" } };

	 cout << m2["apple"] << endl;
	 cout << m2["waterme"] << endl;
	 cout << m2["苹果"] << endl;

	 cout<< m2.size() << endl;
	system("pause");
	return 0;
}