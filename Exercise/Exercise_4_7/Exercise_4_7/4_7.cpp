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
//	cout <<"成员b的偏移量为："<< offsetof(test,b) << endl;
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<mutex>
using namespace std;

//饿汉模式
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
//懒汉模式
class Singleton
{
public:
	static Singleton* GetInstance() 
	{
		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
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
	// 实现一个内嵌垃圾回收类 
	class CGarbo {
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};
	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	static CGarbo Garbo;
private:
	// 构造函数私有
	Singleton(){};
	// 防拷贝
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;

	static Singleton* m_pInstance; // 单例对象指针
	static mutex m_mtx; //互斥锁
};


Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;