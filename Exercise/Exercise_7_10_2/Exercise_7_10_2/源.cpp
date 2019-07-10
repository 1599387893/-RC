#if 0
#include<map>
#include<iostream>
using namespace std;

int main()
{
	int y1, y2, m1, m2, d1, d2;
	int norM[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int money = 0;
	while (cin >> y1 >> m1 >> d1)
	{
		cin >> y2 >> m2 >> d2;
		for (int year = y1; year <= y2 - 1; year++)
		{
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
				money += 580;
			else
				money += 579;
		}
		if (y1 == y2)
			if ((y1 % 4 == 0 && y1 % 100 != 0)||(y1 % 400 == 0))
				money += 1;
		int temp = 0;
		for (int month = 0; month < m1 - 1; month++)//减去多加的部分
		{
			if ( month == 1 || month == 2 || month == 4 || month == 4 || month == 10)//month从0号下标开始
				temp += norM[month] * 2;
			else
				temp += norM[month];
		}
		int m = m1 - 1;
		if ( m == 3 || m == 5 || m == 7 || m == 8 || m == 9 || m == 11)
			temp += (d1 - 1) * 2;//当天也是挣了钱的，所以需要减去
		else
			temp += d1 - 1;
		money -= temp;
		temp = 0;
		for (int month = 1; month < m2 - 1; month++)//加上少加的部分
		{
			if (month == 2 || month == 3 || month == 5 || month == 7 || month == 11)//month从0号下标开始
				temp += norM[month] * 2;
			else
				temp += norM[month];
		}
		m = m2 - 1;
		if (m == 0 || m == 3 || m == 5 || m == 7 || m == 8 || m == 9 || m == 11)
			temp += d2 * 2;
		else
			temp += d2;//利润上需要加上最后一天的
		money += temp;
		cout << money << endl;
	}
	return 0;
}


#include<iostream>
#include<math.h>
using namespace std;

int count_div(int num)
{
	int ret = 0;
	for (int i = 2; i <= sqrt(num); ++i)
	{
		//if(num&i)
		if ((num&i) == 0)
		{
			while ((num&i) == 0)
				num /= i;
			ret++;
		}
		if (num != 1)
			ret++;
	}
	return ret;
}
int main()
{
	int num,ret,i;
	while (cin >> num)
	{
		ret = 0;
		for (i = 2; i <= sqrt(num); ++i){
			//if(num&i)
			if ((num%i) == 0){
				while ((num%i) == 0)
				{
					num /= i;
				}
				ret++;
			}
		}
		if (num != 1)
			ret++;
		cout<<ret<<endl;
	}
	return 0;
}

#endif
#if 0
#include <iostream> 
#include<math.h> 
using namespace std; 
int main() 
{
int n, k, i; 
while (cin >> n)
{ 
		k = 0; 
		for (i = 2; i <= sqrt(n); i++) 
		{ 
			if ((n % i) == 0) 
			{ 
				while ((n % i) == 0)
				{ 
					n = n / i; 
				}
				k++; 
			} 
		}
		if (n != 1) 
			k++; 
		cout << k << endl; 
}
return 0; 
}
#endif

