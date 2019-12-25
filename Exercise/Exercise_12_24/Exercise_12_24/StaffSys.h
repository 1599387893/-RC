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
/*-------------------------------------ȫ�ֱ���-------------------------------------*/
/*������ͷ�ļ��е�ȫ�ֱ�����ÿ��#includeһ�Σ��ͻᱻ��������һ��,����һ�����ڴ�*/
static int g_num_t;	//��ʦ������
static int g_num_w;	//ְ��������
static int g_age_t = 0;	//��ʦ������
static int g_age_w = 0;	//ְ��������

/*-------------------------------------�� �� ��-------------------------------------*/
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
	int GetAge() const;		//����������˶����꣬����������
	bool Chack();			//������������Ƿ�Ϸ�
};

/*��������Ԫ�ķ�ʽʵ��������������ʽ*/
istream & operator>>(istream &in, Date &date);
ostream & operator<<(ostream &out, const Date &date);

/*-------------------------------------�� �� ��-------------------------------------*/
class Person//������ 
{
protected:
	int		number;		//��� 
	int		salary;		//����
	int		age;		//���� 
	string	name;		//���� 
	string	sex;		//�Ա�
	string  post;		//��λ
	Date	birthtime;	//����ʱ��
	Date	worktime;	//�μӹ���
public:
	//virtual bool display();		//�����Ա��Ϣ
};

/*------------------------�� ʦ ��--------------------------------------*/
class Teacher : public Person		//��ʦ�� 
{
protected:
	string position;	//ְ��
	string department;	//����ϵ
public:

	Teacher(){}
	~Teacher() {}
	string Name()	const;		//��ȡ����		���ڰ���������
	int    Number()	const;		//��ȡ���		���ڰ���Ų��� ������Ƿ�������ȷ
	void   display()const;		//��ʾ������Ϣ
	int    Getage()	const;		//�������      ������ƽ������
	int    Getnum() const;		//��ñ��		������Ƿ�������ȷ
	bool CheckBirthData();		//�������ĳ��������Ƿ�Ϸ�
	bool CheckWorkData();		//�������Ĳμӹ��������Ƿ�Ϸ�
	istream & operator>>(istream &in);
	ostream & operator<<(ostream &out) const;

};

istream & operator>>(istream &in, Teacher &teacher);
ostream & operator<<(ostream &out, const Teacher &teacher);

/*------------------------ְ �� ��--------------------------------------*/
class Worker : public Person		//ְ���� 
{
protected:
	string Technical;	//������
	string department;	//����
public:
	Worker() {}
	~Worker() {}
	string Name()	const;		//��ȡ����		���ڰ���������
	int	   Number()	const;		//��ȡ���		���ڰ���Ų���
	void   display()const;		//��ʾ������Ϣ
	int    Getage()	const;		//�������      ������ƽ������
	bool CheckBirthData();		//�������ĳ��������Ƿ�Ϸ�
	bool CheckWorkData();		//�������Ĳμӹ��������Ƿ�Ϸ�
	istream & operator>>(istream &in);
	ostream & operator<<(ostream &out) const;

};

istream & operator>>(istream &in, Worker &worker);
ostream & operator<<(ostream &out, const Worker &worker);
/*------------------------�� �� ��--------------------------------------*/
class Manage
{
private:
	vector<Teacher*> Teachdata;
	vector<Worker* > Workdata;
public:
	Manage() { LoadData(); }
	~Manage()
	{
		SaveData();			//��������	���������˳��Żᱣ������
		FreeTeacher();		//�ͷ�new���Ķѿռ�
		FreeWorker();
	}

	void SaveData() const;	//��������
	void LoadData();		//��������
	void MainMenu();		//���˵�

	bool AddTeacher();		//���ӽ�ʦ
	bool AddWorker();		//����ְ��
	void DelItemTeacher();	//ɾ����ʦ
	void DelItemWorker();	//ɾ��ְ��
	bool FindTeacher_name(string _name);	//���ҽ�ʦ-������
	bool FindWorker_name(string _name);		//����ְ��-������
	bool FindTeacher_num(int _num);			//���ҽ�ʦ-�����
	bool FindWorker_num(int _num);			//����ְ��-�����
	void UpdateTeacher();	//�޸Ľ�ʦ
	void UpdateWorker();	//�޸�ְ��
	void ShowDataTeacher()const;	//�����ʦ
	void ShowDataWorker()const;		//���ְ��
	void Aver_ageTeacher();		//�����ʦƽ������
	void Aver_ageWorker();		//���ְ��ƽ������
	void MangeTeacher();		//�����˵����������ʦ	ʵ�ֶԽ�ʦ����ɾ��Ĺ���
	void MangeWorker();			//�����˵���������ְ��	ʵ�ֶ�ְ������ɾ��Ĺ���
	void FreeTeacher();			//�ͷ�new���Ŀռ�
	void FreeWorker();			//�ͷ�new���Ŀռ� 
	/* ˵����vector�洢�Ķ���ָ�룬�����Ӷ���ʱ�õ�new������������ʱ��Ҫ�ֶ��ͷ�new���Ŀռ� */
};


/*   �������ʾ  ���ڵ����������Ӧ�������  �ɲ������������� */
void Format_t();
void Format_w();
/*  �ɲ���MangeTeacher()��MangeWorker()�� */
void TeacherMenu();		//��ʦ�˵�
void WorkerMenu();		//ְ���˵�