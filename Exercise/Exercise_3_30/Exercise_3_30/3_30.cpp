#include<iostream>
using namespace std;

//class Date
//{
//
//public:
//	Date(int year = 1900, int month = 1, int day = 1) :_year(year), _month(month), _day(day){}
// 
//	Date(const Date& d) = delete;
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//	Date& operator=(const Date& d) = delete;
//	/*{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(2019, 3, 30);
//	Date d3(2019,3,31);
//	d3 = d1;
//
//	return 0;
//}
//typedef long Align;
//union header {
//	struct {
//		union header *ptr;
//		unsigned size;
//	} s;
//	Align x;
//};
//int main()
//{
//	cout << sizeof(header)<<endl;
//
//	return 0;
//}
//
//int main()
//{
//	int* memaddr = (int*)malloc(1000);
//	printf("释放内存前未使用内存空间大小为：%lu\n", coreleft());
//	free(memaddr);
//	printf("释放内存后未使用内存空间大小为：%lu\n", coreleft());
//
//	return 0;
//}
void Print(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] <<" ";
	}
	cout << endl;
}
void MergeData(int* array, int left, int mid, int right, int* temp)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid;
	int end2 = right;
	int index = left;

	while (begin1 < end1 && begin2 < end2)
	{
		if (array[begin1] <= array[begin2])
			temp[index++] = array[begin1++];
		else
			temp[index++] = array[begin2++];
	}
	while (begin1 < end1)
		temp[index++] = array[begin1++];
	while (begin2 < end2)
		temp[index++] = array[begin2++];
}
void MergeSort(int* array, int size)
{
	int* temp = (int*)malloc(sizeof(array[0])*size);

	int gap = 1;
	while (gap < size)
	{
		for (int i = 0; i < size; i += gap * 2)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;

			if (mid>size)
				mid = size;
			if (right>size)
				right = size;
			MergeData(array, left, mid, right, temp);
		}
		memcpy(array, temp, sizeof(array)*size);
		gap *= 2;
	}
	free(temp);
}

int main()
{
	int array[10] = { 2, 6, 9, 4, 0, 3, 7, 5, 1, 8 };
	int size = sizeof(array) / sizeof(array[0]);
	Print(array, size);
	MergeSort(array, size);
	Print(array, size);
	return 0;
}