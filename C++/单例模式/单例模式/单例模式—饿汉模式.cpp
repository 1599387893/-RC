#include<iostream>
using namespace std;

//¶öººÄ£Ê½
class Singleton
{
public:
	static Singleton* Getinstance()
	{
		return &m_instance;
	}
private:
	Singleton(){};
	Singleton(Singleton const&) = delete;
	Singleton operator=(const Singleton&) = delete;


	static Singleton m_instance;
};
Singleton Singleton::m_instance;