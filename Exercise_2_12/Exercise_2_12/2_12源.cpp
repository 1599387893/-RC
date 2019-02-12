#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class People
{
private:
	char name[18];
	int age;
	char sex[5];
public:
	People(char n[18], int a, char s[5]) :age(a){ strcpy(name, n); strcpy(sex, s); }
	void show() const 
	{ 
		cout << "姓名：" << name << endl; 
		cout << "年龄：" << age << endl;
		cout << "性别：" << sex << endl;
	}
};

class Teacher :public People
{
private:
	char title[10];
	
public:
	Teacher(char n[18], int a, char s[5], char t[10]) :People(n,a,s)
	{ strcpy(title, t); }
	void show()const
	{
		People::show();
		cout << "职称：" << title << endl;
	}
};

class Cadre :public People
{
private:
	char post[10];
public:
	Cadre(char n[18], int a, char s[5], char p[10]) :People(n, a, s)
	{  strcpy(post, p); }
	void show()const
	{
		People::show();
		cout << "职务：" << post << endl;
	}
};

class TeacherCadre :public Teacher, public Cadre
{
private:
	int wages;
public:
	TeacherCadre(char n[18], int a, char s[5], char t[10], char p[10], int w) \
		: Teacher(n, a, s, t), Cadre(n, a, s, t), wages(w){}
	void show()const
	{
		Teacher::show();
		Cadre::show();
		cout << "工资：" << wages << endl;
	}
};

int main()
{
	Teacher t1("zhangsan", 25, "man", "jiaoshi");
	t1.show();
	Cadre c1("lisi", 35, "women", "nianjizhuren");
	c1.show();
	TeacherCadre tc1("wangwu", 55, "man", "xiaozhang","jioashi",4500);
	tc1.show();
	system("pause");
	return 0;
}