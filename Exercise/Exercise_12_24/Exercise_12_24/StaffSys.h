#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream> 
#include <string>
#include <ctime>
#include <conio.h>
#include <vector>
#include <fstream> 
#include <iomanip>
using namespace std;
#define SIZE 5
/*-------------------------------------全局变量-------------------------------------*/
/*定义在头文件中的全局变量，每被#include一次，就会被声明定义一次,申请一块新内存*/
static int g_num_t;	//教师总人数
static int g_num_w;	//职工总人数
static int g_age_t = 0;	//教师总年龄
static int g_age_w = 0;	//职工总年龄

/*-------------------------------------日 期 类-------------------------------------*/
class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int y = 1919, int m = 1, int d = 1) :year(y), month(m), day(d) {}
	~Date() {}
	istream & operator>>(istream &in);
	ostream & operator<<(ostream &out) const;
	int GetAge() const;		//返回至今过了多少年，用于求年龄
	bool Chack();			//检查输入日期是否合法
};

/*避免用友元的方式实现运算符的输出方式*/
istream & operator>>(istream &in, Date &date);
ostream & operator<<(ostream &out, const Date &date);

/*-------------------------------------共 有 类-------------------------------------*/
class Person//公有类 
{
protected:
	int		number;		//编号 
	int		salary;		//工资
	int		age;		//年龄 
	string	name;		//姓名 
	string	sex;		//性别
	string  post;		//岗位
	Date	birthtime;	//出生时间
	Date	worktime;	//参加工作
public:
	//virtual bool display();		//输出成员信息
};

/*------------------------教 师 类--------------------------------------*/
class Teacher : public Person		//教师类 
{
protected:
	string position;	//职称
	string department;	//所在系
public:

	Teacher(){}
	~Teacher() {}
	string Name()	const;		//获取姓名		用于按姓名查找
	int    Number()	const;		//获取编号		用于按编号查找 检查编号是否输入正确
	void   display()const;		//显示个人信息
	int    Getage()	const;		//获得年龄      用于求平均年龄
	int    Getnum() const;		//获得编号		检查编号是否输入正确
	bool CheckBirthData();		//检查输入的出生日期是否合法
	bool CheckWorkData();		//检查输入的参加工作日期是否合法
	istream & operator>>(istream &in);
	ostream & operator<<(ostream &out) const;

};

istream & operator>>(istream &in, Teacher &teacher);
ostream & operator<<(ostream &out, const Teacher &teacher);

/*------------------------职 工 类--------------------------------------*/
class Worker : public Person		//职工类 
{
protected:
	string Technical;	//技术级
	string department;	//部门
public:
	Worker() {}
	~Worker() {}
	string Name()	const;		//获取姓名		用于按姓名查找
	int	   Number()	const;		//获取编号		用于按编号查找
	void   display()const;		//显示个人信息
	int    Getage()	const;		//获得年龄      用于求平均年龄
	bool CheckBirthData();		//检查输入的出生日期是否合法
	bool CheckWorkData();		//检查输入的参加工作日期是否合法
	istream & operator>>(istream &in);
	ostream & operator<<(ostream &out) const;

};

istream & operator>>(istream &in, Worker &worker);
ostream & operator<<(ostream &out, const Worker &worker);
/*------------------------管 理 类--------------------------------------*/
class Manage
{
private:
	vector<Teacher*> Teachdata;
	vector<Worker* > Workdata;
public:
	Manage() { LoadData(); }
	~Manage()
	{
		SaveData();			//保存数据	程序正常退出才会保存数据
		FreeTeacher();		//释放new出的堆空间
		FreeWorker();
	}

	void SaveData() const;	//保存数据
	void LoadData();		//加载数据
	void MainMenu();		//主菜单

	bool AddTeacher();		//增加教师
	bool AddWorker();		//增加职工
	void DelItemTeacher();	//删除教师
	void DelItemWorker();	//删除职工
	bool FindTeacher_name(string _name);	//查找教师-按姓名
	bool FindWorker_name(string _name);		//查找职工-按姓名
	bool FindTeacher_num(int _num);			//查找教师-按编号
	bool FindWorker_num(int _num);			//查找职工-按编号
	void UpdateTeacher();	//修改教师
	void UpdateWorker();	//修改职工
	void ShowDataTeacher()const;	//输出教师
	void ShowDataWorker()const;		//输出职工
	void Aver_ageTeacher();		//输出教师平均年龄
	void Aver_ageWorker();		//输出职工平均年龄
	void MangeTeacher();		//二级菜单——管理教师	实现对教师的增删查改功能
	void MangeWorker();			//二级菜单——管理职工	实现对职工的增删查改功能
	void FreeTeacher();			//释放new出的空间
	void FreeWorker();			//释放new出的空间 
	/* 说明：vector存储的对象指针，在增加对象时用到new构建对象，析构时需要手动释放new出的空间 */
};


/*   输入框提示  便于调整表格以适应数据输出  可并入各输出函数中 */
void Format_t();
void Format_w();
/*  可并入MangeTeacher()和MangeWorker()中 */
void TeacherMenu();		//教师菜单
void WorkerMenu();		//职工菜单