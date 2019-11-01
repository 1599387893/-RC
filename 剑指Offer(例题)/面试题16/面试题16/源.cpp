//������16����ֵ�������η�

//ע��㣺ע����ֵ�ʹη���������

#include<iostream>
using namespace std;

//��ͨ�ⷨ
double PowerWithUnsignedExponent1(double base, unsigned int exponent)
{
	double ret = 1.0;
	for (int i = 0; i < exponent; ++i)
		ret *= base;
	return ret;
}
//��Ч�ⷨ
double PowerWithUnsignedExponent2(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double ret = PowerWithUnsignedExponent2(base, exponent >> 2);
	ret *= ret;
	if ((exponent & 0x1) == 1) //�Ƚ�exponent����ż
		ret *= base;

	return ret;
}
double Power(double base,int exponent)
{
	if (base == 0)
		return 0;
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double ret = 1.0;
	bool posit = true;
	bool recip = false;
	if (base < 0 && (exponent % 2 == 1))
	{
		posit = false;
		base = -base;
	}
	if (exponent < 0)
	{
		recip = true;
		exponent = -exponent;
	}

	//ret = PowerWithUnsignedExponent1(base, exponent);
	ret = PowerWithUnsignedExponent2(base, exponent);

	if (!posit)
		ret = -ret;
	if (recip)
		ret = 1 / ret;
	
	return ret;		
}
int main()
{
	cout << Power(-5,-1) << endl;
	system("pause");
	return 0;
}