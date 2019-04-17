#include<iostream>
using namespace std;

#if 0
//饿汉模式
class singleton
{
public:
	static singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	singleton();
	singleton(const singleton&) = delete;
	singleton& operator=(const singleton&) = delete;

	static singleton m_instance;
};
singleton singleton::m_instance;
#endif


#include<mutex>
#include<thread>
//懒汉模式
class singleton
{
public:
	static singleton* getInstance()
	{
		//double-check
		if (m_instance == nullptr)
		{
			m_mux.lock();
			if (m_instance == nullptr)
				 m_instance = new singleton;
			m_mux.unlock();
		}
		return m_instance;
	}
	//回收类
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (singleton::m_instance)
				delete singleton::m_instance;
		}
	};
	static CGarbo Garbo;
private:
	singleton();
	singleton(const singleton&) = delete;
	singleton& operator=(const singleton&) = delete;

	static singleton* m_instance;
	static mutex m_mux;
};
singleton* singleton::m_instance = nullptr;
mutex singleton::m_mux;
singleton::CGarbo Garbo;


int main()
{
	 cout << singleton::getInstance() << endl;

	return 0;
}
