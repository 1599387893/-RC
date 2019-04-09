#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

//����ģʽ-����ģʽ
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

//����ģʽ-����ģʽ
class singleton
{
public:
	static singleton* GetInstance()
	{
		//ʹ��double-check�ķ�ʽ
		if (nullptr == m_pInstance)
		{
			m_mtx.lock();//����
			if (nullptr == m_pInstance)
			{
				m_pInstance = new singleton();
			}
			m_mtx.unlock();//����
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
	singleton(const singleton&) = delete;//������
	singleton& operator=(const singleton&) = delete;
	static singleton* m_pInstance;//����ָ�����
	static mutex m_mtx;//������
};
singleton* singleton::m_pInstance = nullptr;
mutex singleton::m_mtx;
singleton::CGarbo Garbo;