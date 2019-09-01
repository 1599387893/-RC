#define _CRT_SECURE_NO_WARNINGS 1

#include"Person.h"

int main()
{
	Person s;
	s.PersonInit("老王", 35, "男");
	s.PersonShow();
	cout << "实例化对象的大小：" << sizeof(s)<<endl;
	system("pause");
	return 0;

}