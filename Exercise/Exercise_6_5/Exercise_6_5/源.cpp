#if 0
#include<iostream>
using namespace std;

class Base
{
public:
	Base(int data)
		:_data(data)
	{
		cout << "Base(int data)" << endl;
	}
	~Base()
	{
		cout << "~Base()" << endl;
	}
	void Test()
	{
		cout << "Base::Test()" << endl;
	}
private:
	int _data;
};

class Son :public Base
{
public:
	Son(int data = 1, int son = 1)
		:Base(data)
		, _son(son)
	{
		cout << "Son(int data,int son)" << endl;
	}
	void Test()
	{
		cout << "Son::Test()" << endl;
	}
private:
	int _son;
};

int main()
{
	Base* b1 = new Son;
	b1->Test();
	system("pause");
	return 0;
}
#endif

#include<iostream>
using namespace std;

#if 0
int main()
{
	printf("%s %5.3s\n", "computer", "computer");
	system("pause");
	return 0;
}


int main()
{
	int a = 0;
	long b = 0;
	double c = 0;
	cout << typeid(a+b+'A'+c).name() << endl;
	printf(0, 1, 2, 3);
	system("pause");
	return 0;
}


int main()
{
	int a = 10;
	printf("%.2f\n", a);
	system("pause");
	return 0;
}

int add(int a = 1, int b = 1);

int add(int a , int b )
{
	return a + b;
}

int main()
{
	cout << add(1,2) << endl;
	system("pause");
	return 0;
}


int main()
{
	cout << (10 | 11) << endl;
	system("pause");
	return 0;
}

int main()
{
	char s[] = "abc";
	char* szX = "abc";
	char* szY = "abc";
	cout << &s << endl;
	cout << szX << endl;
	printf("%p\n", szX);
	cout << szY << endl;
	printf("%p\n", szY);

	system("pause");
	return 0;
}
#endif

#include<vector>
int findMinimum(int n, vector<int> left, vector<int> right) {
	// write code here
	int left_count = 14;
	int right_count = 0;
	int zero = 0;
	for (int i = 0; i<n; ++i)
	{
		if (left[i] != 0 && left[i]<left_count)
			left_count = left[i];
		if (right[i]>right_count)
		{
			if (right[i] != 0)
				right_count = right[i];
			else
				++zero;
		}
	}
	return (left_count + 1 + right_count + (n - 1 - zero));
}

int main()
{
	vector<int> left{ 0, 7, 1, 6 };
	vector<int> right{ 1, 5, 0, 6 };
	cout<<findMinimum(4, left, right)<<endl;
	system("pause");
	return 0;
}