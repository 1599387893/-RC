//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int x = 1;
//	char i = *(char*)&x;
//
//	cout << i << endl;
//	return 0;
//}

#include<iostream>
using namespace std;

////单例模式——饿汉模式
//class singleton
//{
//public:
//	static singleton& GetInstance()
//	{
//		return m_instance;
//	}
//private:
//	singleton();
//	singleton(const singleton&) = delete;
//	singleton& operator=(const singleton&) = delete;
//	static singleton m_instance;
//};
//static singleton m_instance;


#include<thread>
#include<mutex>
//单例模式——懒汉模式
class singleton
{
public:
	static singleton* GetInstance()
	{
		if (nullptr == m_instance)
		{
			m_mtx.lock();
			if (nullptr == m_instance)
				m_instance = new singleton;
			m_mtx.unlock();
		}
		return m_instance;
	}
	class CGbar
	{
	public:
		~CGbar()
		{
			if (nullptr != singleton::m_instance)
				delete singleton::m_instance;
		}
	};
	static CGbar bar;
private:
	singleton();
	singleton(const singleton&) = delete;
	singleton& operator=(const singleton&) = delete;
	static mutex m_mtx;
	static singleton* m_instance;
};
singleton* singleton::m_instance = nullptr;
mutex singleton::m_mtx;
singleton::CGbar bar;




#include<crtdbg.h>

//_CtrDumpMemeryLeaks();检测内存泄漏