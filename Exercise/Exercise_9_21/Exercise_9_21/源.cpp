#include<iostream>
#include<memory>
#include<thread>
#include<mutex>
using namespace std;

//shared_ptr 的循环引用
struct ListNode
{
	int _data;
	weak_ptr<ListNode> _prev;
	weak_ptr<ListNode> _next;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};
//使用weak_ptr来解决循环引用的问题

//仿函数的删除器
template<class T>
struct FreeFunc
{
	void operator()(T* ptr)
	{
		cout << "free : " << ptr << endl;
		free(ptr);
	}
};
template<class T>
struct DeleteArrayFunc
{
	void operator()(T* ptr)
	{
		cout << "delete []" << ptr << endl;
		delete[] ptr;
	}
};
#if 0
int main()
{
	//shared_ptr<ListNode> node1(new ListNode);
	//shared_ptr<ListNode> node2(new ListNode);
	//cout << node1.use_count() << endl;
	//cout << node2.use_count() << endl;

	//node1->_next = node2;
	//node2->_prev = node1;

	//cout << node1.use_count() << endl;
	//cout << node2.use_count() << endl;

	FreeFunc<int> freeFunc;
	shared_ptr<int> sp1((int*)malloc(4),freeFunc);

	DeleteArrayFunc<int> deleteArrFunc;
	shared_ptr<int>sp2((int*)malloc(4), deleteArrFunc);

	system("pause");
	return 0;
}
#endif

//利用RAII思想来设置守卫锁


template<class Mutex>
class LockGuard
{
public:
	LockGuard(Mutex& mtx)
		:_mutex(mtx)
	{
		_mutex.lock();
	}
	~LockGuard()
	{
		_mutex.unlock();
	}
	LockGuard(const LockGuard<Mutex>&) = delete;
private:
	Mutex& _mutex;
};
mutex mtx;
static int n = 0;

void Func()
{
	for (int i = 0; i < 1000000; ++i)
	{
		LockGuard<mutex> lock(mtx);
		++n;
	}
}

int main()
{
	int begin = clock();
	thread t1(Func);
	thread t2(Func);

	t1.join();
	t2.join();

	int end = clock();

	cout << n << endl;
	cout << "cost time" <<end - begin<< endl;

	system("pause");
	return 0;
}