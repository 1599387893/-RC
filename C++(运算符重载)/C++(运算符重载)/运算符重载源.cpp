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


#include<iostream>
using namespace std;

class Complex
{
private:
	double realpart;
	double imagepart;
public:
	Complex(double real = 0, double image = 0) :realpart(real), imagepart(image){}
	double Getrealpart(){ return realpart; }
	double Getiamgepart(){ return imagepart; }
	Complex &operator+(const Complex &a)const
	{
		Complex b;
		b.realpart = this->realpart + a.realpart;
		b.imagepart = this->imagepart + a.imagepart; 
		return b;
	}
};

int main()
{
	Complex a(1, 2), b(2, 6), c;
	c = a + b;
	cout << "a=" << a.Getrealpart() <<"+"<<a.Getiamgepart() <<"i"<< endl;
	cout << "b= " << b.Getrealpart()<< "+" << b.Getiamgepart() << "i" << endl;
	cout << "c= " << c.Getrealpart() << "+" << c.Getiamgepart() << "i" << endl;
	system("pause");
	return 0;

}