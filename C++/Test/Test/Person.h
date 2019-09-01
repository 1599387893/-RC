#include<iostream>
#include<string.h>
using namespace std;


class Person
{
//private:
	char _name[20];
	int _age;
	char _gender[3];
public:
	void PersonInit(char name[], int age, char gender[]);
	void PersonShow();
};