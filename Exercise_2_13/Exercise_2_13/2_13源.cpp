#include<iostream>
using namespace std;

class Staff //Ա��
{
private:
	int num; //���
	string name; //����
	float rateOfAttend; //������
	int basicSal; //��������
	int prize; //����
public:
	Staff(int nm, string na, float ra, int bs, int pr) \
		: num(nm), name(na), rateOfAttend(ra), basicSal(bs), prize(pr){}
	void Wage()const
	{
		cout << "Ա������Ϊ��" << basicSal + rateOfAttend * prize<<endl;
	}
};

class Saleman:public Staff // ����Ա
{
private:
	int deductRate; // ����Ա��ɱ��� 
	int personAmount; // �������۶�
public:
	Saleman(int nm, string na, float ra, int bs, int pr,int dr,int pa)\
		: Staff(nm, na, ra, bs, pr), deductRate(dr), personAmount(pa){}
	void Wage() const
	{
		cout << "����Ա����Ϊ��" << basicSal + rateOfAttend * prize + deductRate * personAmount<<endl;
	}
};

class Manager :public Staff
{
private:
	int totalDeductRate; //������ɱ���
	int totalAmount; //�����۶�
public:
	Manager(int nm, string na, float ra, int bs, int pr, int td,int ta)\
		: Staff(nm, na, ra, bs, pr), totalDeductRate(td), totalAmount(ta){}
	void Wage() const
	{
		cout << "������Ϊ��" << basicSal + rateOfAttend * prize + totalAmount * totalDeductRate<<endl;
	}
};

class SaleManager :public Saleman, public Manager
{
public:
	SaleManager(int nm, string na, float ra, int bs, int pr, int dr, int pa, int td, int ta)\
		: Saleman(nm, na, ra, bs, pr, dr, pa), Manager(nm, na, ra, bs, pr, td, ta){}
	void Wage() const
	{
		cout << "���۾�����Ϊ��" << basicSal + rateOfAttend * prize + totalAmount * totalDeductRate + deductRate * personAmount << endl;
	}
};

int main()
{
	Staff man1();
	Saleman man2();
	Manager man3();
	SaleManager man4();
	system("pause");
	return 0;
}