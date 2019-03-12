//#include<iostream>
//using namespace std;
//
//class Array
//{
//private:
//	int* elem;
//	int size;
//public:
//	Array(int a[], int sz):elem(a),size(sz){}
//	int GetSize(){ return size; }
//	int &operator[](int pos){ return elem[pos - 1]; }
//};
//
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5 };
//	Array obj(a, 5);
//	obj[1] = 8;
//	for (int i = 1; i <= obj.GetSize(); i++)
//		cout << obj[i] << " ";
//		
//	cout << endl;
//	system("pause");
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//
//class Complex
//{
//private:
//	double realpart;
//	double imagepart;
//public:
//	Complex(double real = 0, double image = 0) :realpart(real), imagepart(image){}
//	double Getrealpart(){ return realpart; }
//	double Getiamgepart(){ return imagepart; }
//	Complex &operator+(const Complex &a1)const
//	{
//		Complex b1;
//		b1.realpart = this->realpart + a1.realpart;
//		b1.imagepart = this->imagepart + a1.imagepart; 
//		return b1;
//	}
//	Complex &operator-(const Complex & a2)const
//	{
//		Complex b2;
//		b2.realpart = this->realpart - a2.realpart;
//		b2.imagepart = this->imagepart - a2.imagepart;
//		return b2;
//	}
//};
//
//int main()
//{
//	Complex a(1, 2), b(2, 6), c1,c2;
//	c1 = a + b;
//	cout << "a=" << a.Getrealpart() <<"+"<<a.Getiamgepart() <<"i"<< endl;
//	cout << "b= " << b.Getrealpart()<< "+" << b.Getiamgepart() << "i" << endl;
//	cout << "c= " << c1.Getrealpart() << "+" << c1.Getiamgepart() << "i" << endl; 
//	c2 = a - b;
//	cout << "a=" << a.Getrealpart() << "+" << a.Getiamgepart() << "i" << endl;
//	cout << "b= " << b.Getrealpart() << "+" << b.Getiamgepart() << "i" << endl;
//	cout << "c= " << c2.Getrealpart() << "+" << c2.Getiamgepart() << "i" << endl;
//	system("pause");
//	return 0;
//
//}

//#include<iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Great_A_Less_B
//{
//	int m_nA;
//	int m_nB;
//public:
//	Great_A_Less_B(int x, int y) :m_nA(x), m_nB(y){}
//	bool opertaor()(int c)const
//	{	return ((c > m_nA) && (c < m_nB)); }
//};
//
//class DivByA
//{
//	int m_nA;
//public:
//	DivByA(int x) :m_nA(x){}
//	bool opertaor()(int c)const
//	{
//		return (c%m_nA == 0);
//	}
//};
//
//int main()
//{
//	Great_A_Less_B obj1(4, 9);
//	DivByA obj2(2);
//	int a[] = { 1, 3, 6, 4, 7, 8, 9, 10, 23, 5 };
//	//��ӡa�д���4��С��9����
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//		//sizeof(a)/sizeof(int)Ϊ����a�е�Ԫ�ظ���
//	{
//		if (obj1(a[i]) == true) //�ж�a[i]�Ƿ����4��С��9
//		{
//			cout << a[i] << '\t';
//		}
//	}
//	cout << endl;
//
//	//��ӡa�б�2��������
//	for (i = 0; i < sizeof(a) / sizeof(int); ++i)
//		//sizeof(a)/sizeof(int)Ϊ����a�е�Ԫ�ظ���
//	{
//		if (obj2(a[i]) == true) //�ж�a[i]��2����
//		{
//			cout << a[i] << '\t';
//		}
//	}
//	cout << endl;
//	system("pause");
//	return 
//}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Great_A_Less_B  
{
	int m_nA;
	int m_nB;
public:
	Great_A_Less_B(int x, int y) : m_nA(x), m_nB(y){}
	bool operator()(int c) const //���ز�����()���ж�c�Ƿ����m_nA��С��m_nB
	{
		return ((c>m_nA) && (c<m_nB));
	}
};

class DivByA
{
	int m_nA;
public:
	DivByA(int x) : m_nA(x){}
	bool operator()(int c) const //���ز�����()���ж�c�Ƿ���Ա�m_nA����
	{
		return (c%m_nA == 0);
	}
};
int main()
{
	Great_A_Less_B obj1(4, 9);
	DivByA obj2(2);
	int a[] = { 1, 3, 6, 4, 7, 8, 9, 10, 23, 5 };
	//��ӡa�д���4��С��9����
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
		//sizeof(a)/sizeof(int)Ϊ����a�е�Ԫ�ظ���
	{
		if (obj1(a[i]) == true) //�ж�a[i]�Ƿ����4��С��9
		{
			cout << a[i] << '\t';
		}
	}
	cout << endl;

	//��ӡa�б�2��������
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
		//sizeof(a)/sizeof(int)Ϊ����a�е�Ԫ�ظ���
	{
		if (obj2(a[i]) == true) //�ж�a[i]��2����
		{
			cout << a[i] << '\t';
		}
	}
	cout << endl;
	system("pause");
	return 0;
}