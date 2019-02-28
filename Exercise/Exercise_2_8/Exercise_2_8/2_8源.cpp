//#include<iostream>
//#include<cstdlib>
//using namespace std;
//
//class Point
//{
//private:
//	int x, y;
//public:
//	//Point(int a, int b) :x(a), y(b){}
//	Point(int a, int b) {x = a; y = b; }
//	void SetPoint(int a,int b );
//	int GetX() const { return x; }
//	int Gety() const { return y; }
//};
//
//void Point::SetPoint(int a, int b)
//{
//	x = a;
//	y = b;
//}
//
//void ShowPoint(const Point &pt)
//{
//	cout << pt.GetX() << "  " << pt.Gety() << endl;
//}
//
//int main()
//{
//	Point a[5] = { Point(0, 0), Point(1, 1), Point(2, 2), Point(3, 3), Point(1, 4) };
//	Point* p = a;
//	p->SetPoint(5, 9);
//	a[3].SetPoint(6, 6);
//	for (int i = 0; i < 5; i++)
//	{
//		ShowPoint(*p++);
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//private:
//	int year;
//	int month;
//	int day;
//public:
//	Date(int y = 2008, int m = 1, int d = 1);
//	friend void Show(const Date &dt);
//};
//
//Date::Date(int y, int m, int d)
//{
//	this->year = y;
//	this->month = m;
//	this->day = d;
//}
//void Show(const Date &dt)
//{
//	cout << dt.year << "/" << dt.month << "/" << dt.day << endl;
//}
//
//int main()
//{
//	Date d1(2019, 2, 5),\
//		d2(2019, 2, 4),\
//		d3(2019, 2, 3),\
//		d4(2019, 2, 2),\
//		d5(2019, 2, 1);
//	Show(d1);
//	Show(d2);
//	Show(d3);
//	Show(d4);
//	Show(d5);
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Test
//{
//private:
//	static int count;
//public:
//	Test(){ count++; }
//	static void Show(){ cout << "共有" << count << "个对象" << endl; }
//};
//
////void Test::Show()
////{
////	cout << "共有" << count << "个对象" << endl;
////}
//
//int count = 0;
//
//int main()
//{
//	Test obj1,obj2,obj3;
//	Test::Show();
//	system("pause");
//	return 0;
//}

//#include <iostream>				// 预处理命令
//using namespace std;				// 使用标准命名空间std
//
//// 测试静态成员类
//class Test
//{
//private:
//	static int count;				// 对象数
//
//public:
//	Test(){ count++; } 			// 构造函数, 实现对对象进行计数
//	static void Show(){ cout << "共有" << count << "个对象!" << endl; }
//};
//
//int  Test::count = 0;					// 为静态数据成员赋初值
//
//int main()
//{
//	Test obj1, obj2, obj3;			// 定义对象
//	Test::Show();					// 显示对象数
//	system("pause");
//	return 0;                    	// 返回值0,返回操作系统
//}

#include <iostream>			 						
using namespace std;							
											
class Test
{
public:
	 Test(){ cout << "构造函数运行" << endl; }
	 ~Test(){ cout << "析造函数运行" << endl; }
};

int main()
{
	Test obj;					// 定义对象							
	return 0;
}