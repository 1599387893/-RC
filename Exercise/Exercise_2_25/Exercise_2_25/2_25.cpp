#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define PI 3.1415

class Shape
{
private:
	int Cx;
	int Cy;
public:
	Shape(int a, int b) :Cx(a), Cy(b){}
	int GetCx()const{ return Cx; }
	int GetCy()const{ return Cy; }
	virtual void Area()
	{
		cout << "���ĵ������Ϊ��" << Cx << "," << Cy << endl;
		cout << endl;
	}
};

class Circle :public Shape
{
private:
	int r;
public:
	Circle(int a, int b, int c) :Shape(a, b), r(c){}
	void Area()const
	{
		cout << "Բ������ǣ�" << r*r*PI << endl;
		cout << "Բ���ܳ�Ϊ��" << fixed << setprecision(2) << r * 2 * PI << endl;
	}
};

class Square :public Shape
{
private:
	int x;
	int y;
public:
	Square(int a, int b, int a1, int b1) :Shape(a, b), x(a1), y(b1){}
	void Area()const
	{
		int a;
		if (x > Shape::GetCx())
			a = 2 * (x - Shape::GetCx());
		else
			a = 2 * (Shape::GetCx() - x);

		cout << "�����ε��ܳ�Ϊ��" << fixed << setprecision(2) << 4 * a << endl;
		cout << "�����ε����Ϊ��" << a*a << endl;
		cout << endl;
	}
};

int main()
{
	Circle c(0, 0, 2);
	Square s(0, 0, 1, 1);
	c.Area();
	s.Area();
	system("pause");
	return 0;

}