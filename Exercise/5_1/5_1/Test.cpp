#include<iostream>
#include<map>
#include<string>
using namespace std;
#if 0
int main()
{
	map<int, string> m;
	map<int, string>::iterator it;
	m.insert(map<int,string>::value_type(2,"C++"));
	m.insert(make_pair(3,"##"));
	m.insert(make_pair(1, "C"));
	it = m.upper_bound(2);
	cout<<it->first<<" " << it->second << endl;
	cin >> it->second;
	return 0;

}

class A
{
	int x, y;
public:
	A(int m, int n) :x(m), y(n){}
	void f(){
		cout << x << "_" << y << endl;
	}
};
int main()
{
	A o1[3] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	o1[0].f();
	o1[1].f();
	o1[2].f();
	int a;
	cin >> a;
	return 0;
}
#include<fstream>
int main()
{
	ofstream file2("test.txt",ios::binary);
	file2 << "一二三";
	file2.seekp(ios::beg);
	file2 << "四";
	file2 << "四";
	file2.close();
	return 0;
}
#include<vector>
#include<algorithm>
#include<iterator>
int main()
{
	int iarray[] = { 1, 2, 3 };
	vector<int> ivector(iarray, iarray + sizeof(iarray) / sizeof(int));
	vector<int> ivector1(2);
	sort(ivector.begin(), ivector.end());
	vector<int> ivector2(5);
	merge(ivector.begin(),ivector.end(),ivector1.begin(),ivector1.end(),ivector2.begin());
	copy(ivector2.begin(),ivector2.end(),ostream_iterator<int>(cout,", "));
	cout << endl;
	system("pause");
	return 0;
}
#endif

class A
{
public:
	A(){ p(); }
	virtual void p(){ cout << "A" << endl; }
	virtual ~A(){ p(); }
};
class B
{
public:
	B(){ p(); }
	void p(){ cout << "B" << endl; }
	~B(){ p(); }
};

int main()
{
	A* a = (A*)new B();
	delete a;
	int c;
	cin >> c;
	return 0;
}