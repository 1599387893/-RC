////#include<iostream>
////#include<string>
////using namespace std;
////
////bool chkParenthesis(string A, int n) 
////{
////	if (n % 2 == 1)
////		return false;
////	string s = "";
////	for (int i = 0; i < A.size(); ++i)
////	{
////		if ((s.size()>0 && s[s.size() - 1] == '(' && A[i] == ')') || (s.size()>0 && s[s.size() - 1] == ')' && A[i] == '('))
////			s.resize(s.size() - 1);
////		else
////			s.push_back(A[i]);
////	}
////	if (s.size() == 0)
////		return true;
////	return false;
////}
////
////int main()
////{
////	string a = "()()()(";
////	int n;
////	//getline(cin, a);
////	//cin >> n;
////	cout << chkParenthesis(a, 6);
////	system("pause");
////	return 0;
////
////}
//
//#include<iostream>
//using namespace std;
//
//int fibonacci(int n)
//{
//	if (n == 0)
//		return 0;
//	if (n == 1 || n == 2)
//		return 1;
//	return (fibonacci(n - 1) + fibonacci(n - 2));
//}
//
//int main()
//{
//	int step = 0;
//	int N;
//	cin >> N;
//	if (N<1 || N>1000000)
//		return 0;
//	int lesN = 0;
//	int greN = 0;
//	int i = 0;
//	for (i = 0; greN<N; ++i)
//		greN = fibonacci(i);
//
//	lesN = fibonacci(i-2);
//	(greN - N)>(N - lesN) ? step = N - lesN : step = greN - N;
//
//	cout << step << endl;
//	system("pause");
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;


#if 0
int main()
{
	int a[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = a;
	cout << p[0][0] << endl;
	cout << *(p[0]+1) << endl;
	cout << (*p)[2] << endl;
	system("pause");
	return 0;
}


int main()
{
	int a = 0;
	float b = 0, c = 0;
	scanf("%2d%3f%4f", a, b, c);
	printf("\na=%d,b=%d,c=%f\n", a, b, c);
	system("pause");
	return 0;
}


class A
{
public:
	void test(float a)
	{
		cout << "1" << endl;
	}
};
class B :public A
{
public:
	void test(int a)
	{
		cout << "20" << endl;
	}
};

int main()
{
	A *a = new A;
	B *b = new B;
	a = b;
	a->test(1.1);
	system("pause");
	return 0;
}
#endif

int main()
{
	int m = 0123;
	int n = 123;
	printf("%o,%o\n", m, n);
	cout << m << endl << n << endl;
	system("pause");
	return 0;
}