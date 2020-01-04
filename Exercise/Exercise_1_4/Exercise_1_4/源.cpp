#if 0
#include<iostream>
using namespace std;

void print(char* s)
{
	if (*s)
	{
		print(++s);
		cout << *s;
	}
}

class Base
{
public :
	virtual int foo(int x)
	{
		return x * 10;
	}
	int foo(char* x)
	{
		return sizeof(x) + 10;
	}
};
class Derived : public Base
{
	int foo(int x)
	{
		return x * 20;
	}
	virtual int foo(char* x)
	{
		return sizeof(x) + 20;
	}
};
int main()
{
#if 0
	char str[] = "Geneius";
	print(str);
#endif
	Derived d;
	Base* pb = &d;

	char x[10];
	cout << (pb->foo(100)+pb->foo(x)) << endl;
	system("pause");
	return 0;
}


#include<iostream>
#include<vector>
using namespace std;
int FindNumber(int& n)
{
	if (n < 0 || n>500000)
		return -1;
	int count = 0;
	for (int i = 2; i <= n; ++i)
	{
		int sum = 0;
		for (int j = 2; j <= sqrt(i); ++j)
		{
			if (i%j == 0)
			{
				if (i / j == j)
					sum += j;
				else
					sum += j + (i / j);
			}
		}
		if (sum+1 == i)
			count++;
	}
	return count;
}
int main()
{
	int n;
	while (cin>>n)
		cout << FindNumber(n) << endl;
	system("pause");
	return 0;
}
#endif


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		if (str.find("joker JOKER") != string::npos)
			cout << "joker JOKER" << endl;
		else
		{
			string s1 = str.substr(0,str.find('-'));
			string s2 = str.substr(str.find('-')+1);
			int count1 = count(s1.begin(), s1.end(), ' ');
			int count2 = count(s2.begin(), s2.end(), ' ');
			if (count1 == count2)
			{
				if (s1[0] > s2[0])
					cout << s1 << endl;
				else
					cout << s2 << endl;
			}
			else
			{
				if (count1 == 3)
					cout << s1 << endl;
				else if (count2 == 3)
					cout << s2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
	return 0;
}