#include<iostream>
#include<string>
using namespace std;

#if 0
int main()
{
	//string s1 = "abcdefghij";
	//string s2 = s1.substr(0,2);
	//cout << s1 << endl;
	//cout << s2 << endl;
	string s1 = "abcdI am your friend";
	auto pos = s1.find(' ');
	while (pos != string::npos)
	{
		cout << pos << endl;
		//pos = s1.find();
	}
	system("pause");
	return 0;
}
#endif

class Base
{
public:
	int _b;
};
class Dervied :virtual public Base
{
public:
	int _d;
	Dervied()
	{}
	~Dervied()
	{}
};

int main()
{
	Dervied d;
	d._b = 1;
	d._d = 2;

	return 0;
}