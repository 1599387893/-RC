#include<iostream>
using namespace std;

class Person
{
protected:
	string _name;
	string _sex;
	int _age;
};

class Student :public Person
{
public:
	int _id;
};


void Test()
{
	Person* pptr;//�������
	Student s;//���������

	pptr = &s;
	Student* ps = (Student*)pptr;
	ps->_id = 1;
}
//void Test()
//{
//	Person p;//�������
//
//	Student s = p;
//}
//void Test()
//{
//	Student s;//���������
//
//	Person p = s;//�����������Ը�ֵ���������
//
//	Person* pptr = &s;//�����������Ը�ֵ������ָ��
//
//	Person& pref = s;//�����������Ը�ֵ����������
//}

int main()
{
	Test();

	return 0;
}