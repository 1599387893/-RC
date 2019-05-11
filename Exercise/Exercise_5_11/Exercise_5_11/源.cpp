//#include<iostream>
//using namespace std;
//
//class Test
//{
//public:
//	static void Get()
//	{
//		cout << "Test()" << endl;
//	}
//private:
//	static int _data;
//};
//int Test::_data = 1;
//
//int main()
//{
//	cout << sizeof(Test) << endl;
//
//	system("pause");
//
//	return 0;
//
//}

//#include<iostream>
//using namespace std;
//
////单例模式
//
////饿汉模式
//class Singleton
//{
//public:
//	static Singleton* GetInstrance()
//	{
//		return &m_instrance;
//	}
//private:
//	Singleton(){};
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//
//	static Singleton m_instrance;
//};
//Singleton Singleton::m_instrance;
//
//#include<thread>
//#include<mutex>
////懒汉模式
//class singleton
//{
//public:
//	static singleton* GetInstrance()
//	{
//		if (m_instrance != nullptr)
//		{
//			m_tex.lock();
//			if (m_instrance != nullptr)
//			{
//				m_instrance = new singleton;
//			}
//			m_tex.unlock();
//		}
//		return m_instrance;
//	}
//	//回收类
//	class CGarbo
//	{
//	public:
//		~CGarbo()
//		{
//			if (m_instrance != nullptr)
//			{
//				delete m_instrance;
//				m_instrance = nullptr;
//			}
//		}
//	};
//	static CGarbo Garbo;
//private:
//	singleton(){};
//	singleton(const singleton&) = delete;
//	singleton& operator=(const singleton&) = delete;
//
//	static singleton* m_instrance;
//	static mutex m_tex;
//};
//singleton* singleton::m_instrance = nullptr;
//mutex singleton::m_tex;
//singleton::CGarbo Garbo;
//
//int main()
//{
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Base
//{
//public:
//	static void Test()
//	{
//		cout << "Base::Test()" << endl;
//	}
////private:
////protected:
//public:
//	static int _b1;
//	int _b2;
//};
//int Base::_b1 = 1;
//
//class Derived :private Base
//{
//public:
//	void Test()
//	{
//		cout << "Derived::Test()" << endl;
//		cout << Base::_b1 << endl;
//		cout << Base::_b2 << endl;
//	}
//private:
//	int _d;
//};
//
//int main()
//{
//	Derived d;
//	d.Test();
//	
//
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Base
//{
//public:
//	static void Test()
//	{
//		cout << "Base::Test()" << endl;
//	}
//	//private:
////protected:
//public:
//	static int _b1;
//	int _b2;
//};
//int Base::_b1 = 1;
//
//class Derived :private Base
//{
//public:
//	void Test()
//	{
//		cout << "Derived::Test()" << endl;
//		cout << Base::_b1 << endl;
//		cout << Base::_b2 << endl;
//	}
//private:
//	int _d;
//};
//
//int main()
//{
//	Derived d;
//	d.Test();
//	//d._b1;
//
//	system("pause");
//	return 0;
//}

