//#include<stddef.h>
//#include<iostream>
//using namespace std;
//
//
//struct test
//{	int a;
//	double b;
//	char c;
//};
//
//int main()
//{
//	cout <<"��Աb��ƫ����Ϊ��"<< offsetof(test,b) << endl;
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<mutex>
using namespace std;

//����ģʽ
class singleton
{
public:
	static singleton* Getinstance()
	{
		return &m_instance;
	}
private:
	singleton(){};
	singleton(const singleton& s) = delete;
	singleton& operator=(const singleton& s) = delete;

	static singleton m_instance;
};
singleton m_instance;
//����ģʽ
class Singleton
{
public:
	static Singleton* GetInstance() 
	{
		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
		if (nullptr == m_pInstance) 
		{
			m_mtx.lock();
			if (nullptr == m_pInstance) 
			{
					m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}
	// ʵ��һ����Ƕ���������� 
	class CGarbo {
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
	static CGarbo Garbo;
private:
	// ���캯��˽��
	Singleton(){};
	// ������
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;

	static Singleton* m_pInstance; // ��������ָ��
	static mutex m_mtx; //������
};


Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;