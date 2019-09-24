//不使用加减乘除做加法
#include<iostream>
using namespace std;

int Add(int number1, int number2)
{
	int sum, carry;
	do{
		sum = number1 ^ number2;
		carry = (number1 & number2) << 1;
		number1 = sum;
		number2 = carry;
	} while (number2 != 0);
	
	return number1;
}
int main()
{
	int a = 0;
	int b = 0;
	while (cin >> a >> b)
		cout << Add(a,b) << endl;
	system("pause");
	return 0;
}
