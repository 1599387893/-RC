#include<iostream>
using namespace std;

#if 0
int main()
{
	int a = 1, b = 0, c = -1, d = 0; 
	d = ++a || ++b&&++c; 
	cout << a << " " << b << " " << c << endl;
	system("pause");

	return 0;
}
#endif 

template<class T> class BigNumber{
	long n;
public: 
	BigNumber(T i) :n(i)
	{} 
	BigNumber operator+(BigNumber b) 
	{ 
		return BigNumber(n + b.n); 
	}
};

int main()
{
	BigNumber<int> b1(1);
	BigNumber<int> b2(2);
	b1 + b2;
	b1 + 1;
	//1 + b1 ;
	return 0;
}