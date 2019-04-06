#include<iostream>
using namespace std;

//class Date
//{
//	friend ostream& operator <<(ostream& out,const Date& d);
//	friend istream& operator >>(istream& in,const Date& d);
//public:
//	Date(int year=1900, int month=1, int day=1) :_year(year), _month(month), _day(day){}
//	~Date(){}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	Date& operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		return *this;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d;
//	
//}
void  Print(int* array, int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void BubbleSort(int* array, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (array[i] < array[j])
				Swap(&array[i],&array[j]);
}
int main()
{
	int array[10] = { 2, 5, 3, 0, 1, 9, 8, 4, 6, 7 };
	int size = 10;
	Print(array, size);
	BubbleSort(array, size);
	Print(array, size);

	return 0;
}