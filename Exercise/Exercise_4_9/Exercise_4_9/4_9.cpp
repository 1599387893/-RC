#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

//单例模式-饿汉模式
//class singleton
//{
//public:
//	static singleton& Getsingleton()
//	{
//		return m_instance;
//	}
//private:
//	singleton(){};
//	singleton(const singleton&) = delete;
//	singleton& operator=(const singleton&) = delete;
//	static singleton m_instance;
//};
//singleton singleton::m_instance;

//单例模式-懒汉模式
class singleton
{
public:
	static singleton* GetInstance()
	{
		//使用double-check的方式
		if (nullptr == m_pInstance)
		{
			m_mtx.lock();//加锁
			if (nullptr == m_pInstance)
			{
				m_pInstance = new singleton();
			}
			m_mtx.unlock();//解锁
		}
		return m_pInstance;
	}
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (singleton::m_pInstance)
				delete singleton::m_pInstance;
		}
	};
	static CGarbo Garbo;
private:
	singleton(){};
	singleton(const singleton&) = delete;//防拷贝
	singleton& operator=(const singleton&) = delete;
	static singleton* m_pInstance;//单例指针对象
	static mutex m_mtx;//互斥锁
};
singleton* singleton::m_pInstance = nullptr;
mutex singleton::m_mtx;
singleton::CGarbo Garbo;