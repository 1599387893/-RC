//#include<iostream>
//#include<ctime>
//using namespace std;
//
//#if 0
//namespace N1
//{
//	int a;
//	int b;
//	int ADD(int num1,int num2)
//	{
//		return num1 + num2;
//	}
//}
//namespace N1
//{
//	int c;
//	int d;
//	int SUB(int num1, int num2)
//	{
//		return num1 - num2;
//	}
//}
//using N1::b;
//using namespace N1;
//int main()
//{
//	cout << clock() << endl;
//	cout << a << endl;
//	cout << b << endl;
//	cout << clock() << endl;
//
//
//	return 0;
//}
//#endif
//
//
//#if 0
//int main()
//{
//	const char&& pc = 'c';
//
//
//
//	const int a = 10;
//	int* pa = (int*)&a;
//	*pa = 100;
//	cout << a << endl;
//	cout << *pa << endl;
//	return 0;
//}
//#endif 
//
//#if 0
//int main()
//{
//	auto a = 1;
//	auto b = 1.0;
//	auto c = a+b;
//	 
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//
//	return 0;
//}
//#endif
//
//#if 0
//int main()
//{
//	int a = 10;
//	auto pa1 = &a;
//	auto* pa2 = &a;
//	auto& pa3 = a;
//	auto b = a;
//
//	cout << a << endl;
//	cout << &a << endl;
//	cout << pa1 << endl;
//	cout << pa2 << endl;
//	cout << pa3 << endl;
//	cout << b << endl;
//
//	cout << typeid(pa1).name() << endl;
//	cout << typeid(pa2).name() << endl;
//	cout << typeid(pa3).name() << endl;
//	cout << typeid(b).name() << endl;
//
//	return 0;
//}
//#endif
//
//
//#if 0
//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
//		array[i] *= 2;
//	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); p++)
//		cout << *p << endl;
//
//	for (auto& e : array)
//		e *= 2;
//	for (auto e : array)
//		cout << e << endl;
//
//
//	return 0;
//}
//#endif
//
//
//#if 0
////只能在堆上申请空间
//class HeapOnly
//{
//public:
//	static HeapOnly* CreateObject()
//	{
//		return new HeapOnly();
//	}
//private:
//	HeapOnly();
//};
////只能在栈上申请空间
//class StackOnly
//{
//public:
//	static StackOnly CreateObject()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly();
//	void* operator new(size_t size);
//	void operator delete(void* p);
//	void* operator new[](size_t size);
//	void operator delete[](void* p);
//};
//#endif
//
//
//#if 0
////饿汉模式
//class Singleton
//{
//public:
//	static Singleton* Getinstance()
//	{
//		return &m_instance;
//	}
//private:
//	Singleton(){};
//	Singleton( Singleton const&) = delete;
//	Singleton operator=(const Singleton&) = delete;
//
//
//	static Singleton m_instance;
//};
//Singleton Singleton::m_instance;
//#endif
//
//#if 0
//#include<mutex>
//#include<thread>
////懒汉模式
//class Singleton
//{
//public:
//	static Singleton* GetInstance() 
//	{
//		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
//		if (nullptr == m_pInstance) 
//		{
//			m_mtx.lock();
//			if (nullptr == m_pInstance) 
//			{
//					m_pInstance = new Singleton();
//			}
//			m_mtx.unlock();
//		}
//		return m_pInstance;
//	}
//	// 实现一个内嵌垃圾回收类 
//	class CGarbo {
//	public:
//		~CGarbo()
//		{
//			if (Singleton::m_pInstance)
//				delete Singleton::m_pInstance;
//		}
//	};
//	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
//	static CGarbo Garbo;
//private:
//	// 构造函数私有
//	Singleton(){};
//	// 防拷贝
//	Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//	static Singleton* m_pInstance; // 单例对象指针
//	static mutex m_mtx; //互斥锁
//};
//
//
//Singleton* Singleton::m_pInstance = nullptr;
//Singleton::CGarbo Garbo;
//mutex Singleton::m_mtx;
//
//#endif
//
//
//#if 0
//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _data;
//
//	ListNode(int data = 0) :_data(data), _next(nullptr), _prev(nullptr)
//	{
//		cout << "ListNode()" << this << endl;
//	}
//	~ListNode()
//	{
//		cout << "~ListNode()" << this << endl;
//	}
//
//	void* operator new(size_t size)
//	{
//		void* p = nullptr;
//		p = allocator<ListNode>().allocate(1);
//		cout << "memery pool allocator" << endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memery pool deallocate" << endl;
//	}
//};
//
//
//class List 
//{
//public:
//	List()
//	{
//		_head = new ListNode;
//		_head->_next = nullptr;
//		_head->_prev = nullptr;
//	}
//	~List()
//	{
//		if (_head->_next)
//		{
//			ListNode* cur = _head->_next;
//			while (cur != _head)
//			{
//				ListNode* next = cur->_next;
//				delete cur;
//				cur = next;
//			}
//		}
//		delete _head;
//		_head = nullptr;
//	}
//private:
//	ListNode* _head;
//};
//
//int main()
//{
//	List l;
//
//	return 0;
//}
//#endif
//
//#if 0
////#define new new(_FILE_,_FUNCTION_,_LINE_)
//#define new new(__FILE__, __FUNCTION__, __LINE__) 
////void* operator new(size_t size, char* fileName, char* funcName, int lineNo)
//void* operator new(size_t size,char* fileName,char* funcName,int lineNo)
//{
//	cout << fileName << "-" << funcName << "-" << lineNo << ";" << size << endl;
//
//	return malloc(size);
//}
//
//int main()
//{
//	int* p = new int;
//	delete p;
//
//	return 0;
//}
//#endif
//
//
//#if 0
////定位new
//class Test
//{
//public:
//	Test(int data= 0)
//	{
//		cout << "Test()" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test()" << this << endl;	
//	}
//private:
//	int _data;
//};
//
//int main()
//{
//	Test* pt = (Test*)malloc(sizeof(Test));
//	new (pt) Test(10);
//
//	delete pt;
//
//
//	int array[10];
//	array[0] = 0;
//	new(array + 3) int(3);	
//
//	return 0;
//
//}
//#endif
//

#if 0
#include<iostream>
using namespace std;

template <class T>
T ADD(T left, T right)
{
	cout << typeid(right).name() << endl;
	return left + right;
}

int main()
{
	cout << ADD(1, 2) << endl;
	cout << ADD(1.1, 2.2) << endl;
	cout << ADD('c', 'd') << endl;
	cout << ADD((double)1, 2.0) << endl;
	cout << ADD<double>(1.1, 2) << endl;

	return 0;
}

#endif