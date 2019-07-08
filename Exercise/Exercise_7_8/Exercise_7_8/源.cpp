// write your code here cpp
#include<iostream>
using namespace std;

struct FestivalNode
{
	Festival(int y, int m, int d)
		:_y(y)
		, _m(m)
		, _d(d)
	{}
	void Diaplay()
	{
		cout << _y << "-";
		if (_m<10)
			cout << "0";
		cout << _m << "-";
		if (_d<10)
			cout << "0";
		cout << _d << endl;
	}
	int _y;
	int _m;
	int _d;
};

void Find_festival(int year)
{
	int flag = 0;//闰年平年标记
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		flag = 1;
	FestivalNode* newNode = new[10] FestivalNode;
	int y, m, d;
	newNode[0]
		newNode[4](year, 7, 4);
	newNode[7](year, 12, 25);


	for (auto& e : newNode)
		e.Display();
	delete newNode[];
	return;
}
int main()
{
	int year = 0;
	while (cin >> year)
		Find_festival(year);
	return 0;
}


#if 0
// write your code here cpp
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void Factor(int a)
{
	int a1 = a;
	vector<int> v;
	for (int i = 2; i <= sqrt(a1); ++i)
	{
		if (a1 % i == 0)
		{
			while (a1%i == 0)
			{
				a1 /= i;
				v.push_back(i);
			}
		}
	}
	if (a1 != 1)
		v.push_back(a1);

	cout << a << " = ";
	for (unsigned long i = 0; i<v.size() - 1; ++i)
		cout << v[i] << " * ";
	cout << v[v.size() - 1] << endl;

}
int main()
{
	int a = 0;
	while (cin >> a)
		Factor(a);
	return 0;
}
#endif
