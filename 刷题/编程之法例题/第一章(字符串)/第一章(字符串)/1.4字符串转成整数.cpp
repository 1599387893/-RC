#if 0

#include<iostream>
#include<string>
using namespace std;

int StrToInt(const char* str)
{
	static const int MAX_INT = (int)((unsigned)~0 >> 1);
	static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;
	unsigned int n = 0; //����ֵ

	//�п�
	if (str == nullptr) return 0;
	//�����ո�
	while (isspace(*str)) str++;
	//�ж�����
	bool minus = false;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = true;
		++str;
	}

	//ѭ���ý��
	while (isdigit(*str))
	{
		//�������
		int c = *str - '0';//��ǰλ�ϵ���ֵ
		if (!minus && ((n>MAX_INT/10) || (n==MAX_INT/10 && c>MAX_INT%10)))
		{
			n = MAX_INT;
			break;
		}
		else if (minus && ((n > (unsigned)MIN_INT / 10) || (n == (unsigned)MIN_INT / 10 && c > (unsigned)MIN_INT % 10)))
		{
			n = MIN_INT;
			break;
		}
		//δ������������������ϸ�λ
		n = n * 10 + c;
		++str;
	}
	return (minus==true ? -1*n : n);
}
int main()
{
	string str = "-2147483697";
	cout << StrToInt(str.c_str()) << endl;
	cin >> str;
	return 0;
}
#endif