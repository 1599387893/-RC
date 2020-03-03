// write your code here cpp
#include<iostream>
using namespace std;

int WeekDay(int y, int m)
{
	/*int month1[13] = { 0, 5, 1, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	int month2[13] = { 0, 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		return month1[m];
	return month2[m];
	*/
	int d = 1;
	return ((d + 2 * m + 3 * (m + 1)/ 5 + y + y / 4 - y / 100 + y / 400) % 7);
}
int main()
{
	int year;
	int fristDay;
	int day;
	while (cin >> year)
	{
		//Ԫ����
		cout << year << "-01-01" << endl;
		//1�µĵ���������һ��
		fristDay = WeekDay(year, 1);
		day = 1;
		for (int i = 0; i < 3;)
		{
			if (fristDay == 1)
				i++;
			fristDay++;
			day++;
			if (fristDay > 7)
				fristDay = 1;
		}
		if (day > 9)
			cout << year << "-01-" <<day << endl;
		else
			cout << year << "-01-0" << day << endl;

		//2�µĵ���������һ��
		fristDay = WeekDay(year, 2);
		day = 1;
		for (int i = 0; i < 3;)
		{
			if (fristDay == 1)
				i++;
			fristDay++;
			day++;
			if (fristDay > 7)
				fristDay = 1;
		}
		if (day > 9)
			cout << year << "-02-" << day << endl;
		else
			cout << year << "-02-0" << day << endl;
		//5�µ����һ������һ��
		fristDay = WeekDay(year, 6); fristDay--;
		fristDay = fristDay == 0 ? 1 : fristDay;
		day = 31;
		for (int i = 0; i < 8; ++i)
		{
			if (fristDay  == 1)
				break;
			fristDay--;
			day--;
			fristDay = fristDay == 0 ? 1 : fristDay;
		}
		if (day > 9)
			cout << year << "-05-" << day << endl;
		else
		cout << year << "-05-0" << day << endl;
		//7��4�գ�
		cout << year << "-07-04" << endl;
		//9�µĵ�һ������һ��
		fristDay = WeekDay(year, 9);
		day = 1;
		for (int i = 0; i < 8; ++i)
		{
			if (fristDay== 1)
				break;
			fristDay++;
			day++;
			if (fristDay > 7)
				fristDay = 1;
		}
		if (day > 9)
			cout << year << "-09-" << day << endl;
		else
		cout << year << "-09-0" << day << endl;
		//11�µĵ��ĸ������ģ�
		fristDay = WeekDay(year, 11);
		day = 1;
		for (int i = 0; i < 4;)
		{
			if (fristDay == 4)
				i++;
			fristDay++;
			day++;
			if (fristDay > 7)
				fristDay = 1;
		}
		if (day > 9)
			cout << year << "-11-" << day << endl;
		else
		cout << year << "-11-0" << day << endl;
		//12��25�գ�
		cout << year << "-12-25" << endl;
	}
	return 0;
}