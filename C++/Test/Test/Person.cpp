#include"Person.h"

void Person::PersonInit(char name[] , int age, char gender[])
{
	//strcpy(_name, name);
	//strcpy(_gender, gender);
	_age = age;
}

void Person::PersonShow()
{
	cout << "Name:" << _name << "\nAge:" << _age << "\nGender:" << _gender << endl;
}