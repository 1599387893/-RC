//#include<iostream>
//using namespace std;
//
//class People
//{
//protected:
//	int age;
//	int height;
//	int weight;
//	static int num;
//public:
//	People(int a, int h, int w) :age(a), height(h), weight(w) { num++; };
//	void Eatting(){ weight++; };
//	void Sporting(){ height++; };
//	void Sleep(){ age++; weight++, height++; };
//	void Show();
//	static void ShowNum(){ cout << "������Ϊ��" << num << endl; };
//};
//int People::num = 0;
//void People::Show()
//{
//	cout << "����Ϊ��" << age << endl;
//	cout << "����Ϊ��" << weight << endl;
//	cout << "���Ϊ��" << height << endl;
//}
//
//int main()
//{
//	People p1 = { 12, 175, 110 };
//	People p2 = { 13, 185, 120 };
//	People p3 = { 14, 195, 130 };
//	/*p1.Show();
//	p2.Show();
//	p3.Show();
//	p3.ShowNum();*/
//	p1.Eatting();
//	p1.Eatting();
//	p1.Eatting();
//	p1.Show();
//	p1.Sleep();
//	p1.Show();
//	p1.Sporting();
//	p1.Show();
//	system("pause");
//	return 0;
//}

#define  _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//using namespace std;
//
//class Student
//{
//private:
//	char name[18];
//	int num;
//	int mathScore;
//	int englishScore;
//	static int count;
//	static int mathTotalScore;
//	static int englishTotalScore;
//public:
//	Student(char n[18], int nm, int m, int e);
//	void ShowBase();
//	static void ShowStatic();
//};
//
//int Student::count = 0;
//int Student::mathTotalScore = 0;
//int Student::englishTotalScore = 0;
//
//Student::Student(char n[18], int nm, int m, int e)
//{
//	count++;
//	strcpy(name, n);
//	num = nm;
//	mathScore = m;
//	englishScore = e;
//	mathTotalScore += mathScore;
//	englishTotalScore += englishScore;
//}
//void Student::ShowBase()
//{
//	cout << "����Ϊ��" << name << endl;
//	cout << "����Ϊ��" << num << endl;
//	cout << "��ѧ�ɼ�Ϊ��" << mathScore << endl;
//	cout << "Ӣ��ɼ�Ϊ��" << englishScore << endl;
//}
//void Student::ShowStatic()
//{
//	cout << "������Ϊ��" << count << endl;
//	cout << "����ѧ�ɼ�Ϊ��" << mathTotalScore << endl;
//	cout << "��Ӣ��ɼ�Ϊ��" << englishTotalScore << endl;
//}
//
//int main()
//{
//	Student s1 = { "rencheng", 1705, 80, 90 };
//	Student s2 = { "zoulei", 2705, 80, 90 };
//	Student s3 = { "zhaokai", 3705, 80, 90 };
//	s1.ShowBase();
//	s2.ShowBase();
//	s3.ShowBase();
//
//	s1.ShowStatic();
//	s3.ShowStatic();
//
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;

class 