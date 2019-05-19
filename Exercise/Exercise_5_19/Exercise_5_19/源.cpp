#include<iostream>
#include<string>
using namespace std;

#if 0
int GetPwdSecLev(string PassWord)
{
	int PWlong = 0;
	if (PassWord.size() >= 8)
		PWlong = 25;
	else if (PassWord.size() >= 5)
		PWlong = 10;
	else
		PWlong = 5;

	int PWcha = 0;
	int PWnum = 0;
	int PWsym = 0;
	int PWrew = 0;
	int retValue = 0;

	int i = 0;
	while (PassWord[i])
	{
		//ÅÐ¶Ï´óÐ¡Ð´×ÖÄ¸
		if ( PWcha == 0 &&(PassWord[i] >= 'a'&& PassWord[i] <= 'z'))
		{
			PWcha = 1;
			++i;
			continue;
		}
		if (PWcha < 2 &&(PassWord[i] >= 'A'&& PassWord[i] <= 'Z'))
		{
			PWcha = 2;
			++i;
			continue;
		}
		//ÅÐ¶ÏÊý×Ö
		if (PassWord[i] >= '1' && PassWord[i] <= '9' && PWnum < 20)
		{
			PWnum += 10;
			++i;
			continue;
		}
		//ÅÐ¶Ï·ûºÅ
		if (PWsym < 2 && ((PassWord[i] <= 47 && PassWord[i] >= 33) || (PassWord[i] >= 58 && PassWord[i] <= 64) || (PassWord[i] >= 91 && PassWord[i] <= 96) || (PassWord[i] >= 123 && PassWord[i] <= 126)))
		{
			++PWsym;
			++i;
			continue;
		}


		++i;
	}
	if (PWsym == 1)
		PWsym = 10;
	if (PWsym == 2)
		PWsym = 25;

	PWcha *= 10;

	if (PWcha == 20 && PWnum > 0 && PWsym > 0)
		PWrew = 5;
	else if (PWcha == 10 && PWnum > 0 && PWsym > 0)
		PWrew = 3;
	else if (PWcha == 0 && PWnum > 0 && PWsym > 0)
		PWrew = 2;


	retValue = PWlong + PWcha + PWnum + PWsym + PWrew;
	return retValue;
}
void Output(int SafeValue)
{

	if (SafeValue >= 90)
	{
		cout << "VERY_SECURE" << endl;	return ;
	}
	if (SafeValue >= 80)
	{ 
		cout << "SECURE" << endl;
		return ;
	}
	if (SafeValue >= 70)
	{
		cout << "VERY_STRONG" << endl;
		return ;
	}
	if (SafeValue >= 60)
	{	
		cout << "STRONG" << endl;
		return ;
	}
	if (SafeValue >= 50)
	{	
		cout << "AVERAGE" << endl;
		return ;
	}
	if (SafeValue >= 25)
	{	
		cout << "WEAK" << endl;
		return ;
	}
	if (SafeValue >= 0)
	{
		cout << "VERY_WEAK" << endl;
		return ;
	}
}

int main()
{
	string PassWord;
	getline(cin,PassWord);
	int SafeValue;
	SafeValue = GetPwdSecLev(PassWord);
	Output(SafeValue);
	system("pause");
	return 0;
} 
#endif

//ÁâÐÎÐéÄâ¼Ì³Ð
class A
{
public:
	virtual void Func1()
	{
		cout << "A::Func1()" << endl;
	}
private:
	int _a;
};
class B1:public A
{
public:
	virtual void Func1()
	{
		cout << "B1::Func1()" << endl;
	}
	virtual void FuncB1()
	{
		cout << "B1::FuncB1()" << endl;
	}
private:
	int _b1;
};
class B2 :public A
{
public:
	virtual void Func1()
	{
		cout << "B2::Func1()" << endl;
	}
	virtual void FuncB2()
	{
		cout << "B2::FuncB2()" << endl;
	}
private:
	int _b2;
};
class C :public B1, public B2
{
public:
	virtual void Func1()
	{
		cout << "C::Func1()" << endl;
	}
	virtual void FuncB1()
	{
		cout << "C::FuncB1()" << endl;
	}
	virtual void FuncB2()
	{
		cout << "C::FuncB2()" << endl;
	}
	virtual void FuncC()
	{
		cout << "C::FuncC()" << endl;
	}
private:
	int _c;
};

typedef void(*PVF)();
void PrintVF(A& a)
{
	PVF* pVF = (PVF*)(int*)&a;
	while (pVF)
	{
		(*pVF)();
		++pVF;
	}
}
int main()
{
	A a;
	B1 b1;
	B2 b2;
	C c;

	PrintVF(a);
	PrintVF(b1);
	PrintVF(b2);
	//PrintVF(c);
	return 0;
}