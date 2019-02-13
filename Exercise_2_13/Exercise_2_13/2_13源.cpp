#include<iostream>
using namespace std;

class Staff //员工
{
private:
	int num; //编号
	string name; //姓名
	float rateOfAttend; //出勤率
	int basicSal; //基本工资
	int prize; //奖金
public:
	Staff(int nm, string na, float ra, int bs, int pr) \
		: num(nm), name(na), rateOfAttend(ra), basicSal(bs), prize(pr){}
	void Wage()const
	{
		cout << "员工工资为：" << basicSal + rateOfAttend * prize<<endl;
	}
};

class Saleman:public Staff // 销售员
{
private:
	int deductRate; // 销售员提成比例 
	int personAmount; // 个人销售额
public:
	Saleman(int nm, string na, float ra, int bs, int pr,int dr,int pa)\
		: Staff(nm, na, ra, bs, pr), deductRate(dr), personAmount(pa){}
	void Wage() const
	{
		cout << "销售员工资为：" << basicSal + rateOfAttend * prize + deductRate * personAmount<<endl;
	}
};

class Manager :public Staff
{
private:
	int totalDeductRate; //经理提成比例
	int totalAmount; //总销售额
public:
	Manager(int nm, string na, float ra, int bs, int pr, int td,int ta)\
		: Staff(nm, na, ra, bs, pr), totalDeductRate(td), totalAmount(ta){}
	void Wage() const
	{
		cout << "经理工资为：" << basicSal + rateOfAttend * prize + totalAmount * totalDeductRate<<endl;
	}
};

class SaleManager :public Saleman, public Manager
{
public:
	SaleManager(int nm, string na, float ra, int bs, int pr, int dr, int pa, int td, int ta)\
		: Saleman(nm, na, ra, bs, pr, dr, pa), Manager(nm, na, ra, bs, pr, td, ta){}
	void Wage() const
	{
		cout << "销售经理工资为：" << basicSal + rateOfAttend * prize + totalAmount * totalDeductRate + deductRate * personAmount << endl;
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