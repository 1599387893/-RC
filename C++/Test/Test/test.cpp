#define _CRT_SECURE_NO_WARNINGS 1

#include"Person.h"

int main()
{
	Person s;
	s.PersonInit("����", 35, "��");
	s.PersonShow();
	cout << "ʵ��������Ĵ�С��" << sizeof(s)<<endl;
	system("pause");
	return 0;

}