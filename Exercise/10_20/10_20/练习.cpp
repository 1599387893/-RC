#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
using namespace std;

class A
{
public:
	//virtual void print();
	static A* create();
private:
	//char m_a;
	//double m_b;
	//float m_c;
	char* m_c1;
};


struct BaseUserInfo
{
	char m_szUserName[16];
	char m_szPassword[16];
	BaseUserInfo()
	{
		m_szUserName[0] = '\0';
		m_szPassword[0] = '\0';
	}
	void Print(){
		PrintUserInfo();
	}
	virtual void PrintUserInfo()
	{
		printf(m_szUserName);
	}
};

struct VIPInfo : public BaseUserInfo
{
	VIPInfo(const char* pUserName, const char* pPassword)
	{
		strcpy(m_szUserName, pUserName);
		strcpy(m_szPassword, pPassword);
	}
	virtual void PrintUserInfo()
	{
		printf(" %s", m_szPassword);
	}
};
int main()
{

	VIPInfo vip("user", "password");
	BaseUserInfo uesr;
	memcpy(&uesr, &vip, sizeof(BaseUserInfo));
	uesr.PrintUserInfo();
	uesr.Print();
	char* b;
	cout << sizeof(b) << endl;
	cout << sizeof(A) << endl;
	struct {
		int i;
		union U
		{
			char buff[13];
			int i;
		}u;
		void foo();
		typedef char* (*f) (void*);
		enum{red, green, blue} color;
	}a;
	cout << sizeof(a) << endl;
	return 0;
}