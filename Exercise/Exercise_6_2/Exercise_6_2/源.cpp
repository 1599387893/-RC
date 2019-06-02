#if 0
#include<iostream>
using namespace std;

int find(int a,int b)
{
		if (a == b)
			return a;
		int minchild = 0;
		int grechild = 0;
		if (a<b)
		{
			minchild = a;
			grechild = b;
		}
		else
		{
			minchild = b;
			grechild = a;
		}
		int ca = minchild;
		while (ca != 1)
		{
			int gParent = (grechild / 2);
			while (ca < gParent)
				gParent /= 2;
			if (ca == gParent)
				break;
			ca /= 2;
		}
		return ca;

};

#include<iostream>
using namespace std;

int count_one(int n)
{
	int ret = 0;
	int temp = 0;
	while (n)
	{
		temp = 0;
		while (n % 2 == 1)
		{
			++temp;
			n /= 2;
		}
		if (temp>ret)
			ret = temp;
		n /= 2;
	}
	return ret;
}

int main()
{
	int number = 0;
	int count = 0;
	while (cin >> number)
	{
		count = count_one(number);
		cout << count << endl;
	}
	return 0;
}

int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int a;
	int b;
	while (cin >> a >> b)
	{
		int ret = find(a, b);
		cout << ret << endl;
	}
	int ret = find(2, 3);
	cout << ret << endl;

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
#include<memory>
using namespace std;



class Date
{
public:
	Date(){ cout << "Date()" << endl; }
	~Date(){ cout << "~Date()" << endl; }

	int _year;
	int _month;
	int _day;
};
#if 0
int main()
{
	auto_ptr<Date> ap(new Date);
	auto_ptr<Date> copy(ap);
	ap->_year = 2019;
	system("pause");
	return 0;
}


template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr = NULL)
		:_ptr(ptr)
	{}
	~AutoPtr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = NULL;
	}
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if (this != ap)
		{
			if (_ptr)
				delete _ptr;
			
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

int main()
{
	AutoPtr<Date> ap(new Date);
	AutoPtr<Date> copy(ap);
	ap->_year = 2019;
	system("pause");
	return 0;
}


int main()
{
	unique_ptr<Date> up(new Date);
	//unique_ptr<Date> copy(up);
	system("pause");
	return 0;
}
#endif

template<class T>
class uniquePtr
{
public:
	uniquePtr(T* ptr)
		:_ptr(ptr)
	{}
	~uniquePtr()
	{
		if (_ptr)
			delete _ptr;
	}
	T& operator* ()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}

private:
	uniquePtr(uniquePtr<T> const &) = delete;
	uniquePtr& operator=(uniquePtr<T>const &) = delete;


	T* _ptr;
};
#if 0
int main()
{
	uniquePtr<Date> up(new Date);
	//uniquePtr<Date> coyp(up);
	system("pause");
	return 0;
}
#endif

int main()
{
	shared_ptr<Date> sp(new Date);
	shared_ptr<Date> copy(sp);

	cout << "ref count:" << sp.use_count() << endl;
	cout << "ref count:" << copy.use_count() << endl;

	system("pause");
	return 0;
}
#endif


#if 0
#include<thread>
#include<mutex>
#include<iostream>
using namespace std;

template<class T>
class shareptr
{
public:
	shareptr(T* ptr = nullptr)
		:_ptr(ptr)
		, _prefcount(new int(1))
		, _pmutex(new muntex)
	{
		if (_ptr == nullptr)
			*_prefcount = 0;
	}
	~sharedptr()
	{
		Release();
	}
	sharedptr(const sharedptr<T>& sp)
		:_ptr(sp._ptr)
		, _prefcount(sp._prefcount)
		, _pmutex(sp._pmutex)
	{
		if (_ptr)
			AddRefCount();
	}
	sharedptr& operator=(const sharedptr<T>& sp)
	{
		if (this != &sp)
		{
			Release();
			_ptr = sp._ptr;
			_prefcount = sp._prefcount;
			_pmutex = sp._pmutex;

			if (_ptr)
				AddRefCount();
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	int UseCount()
	{
		return *_prefcount;
	}
	T* Get()
	{
		return _ptr;
	}
	int AddRefcount()
	{
		_pmutex->lock();
		++(*_prefcount);
		_pmutex->unlock();

		return *_prefcount;
	}
	int subRefCount()
	{
		_pmutex->lock();
		--(*_prefcoount);
		_pmutex->unlock();

		return *_prefcount;
	}
private:
	void Release()
	{
		if (_ptr && SubRefCount == 0)
		{
			delete _ptr;
			delete _prefcount;
		}
	}
private:
	T* _ptr;
	int* _prefcount;
	mutex _pmutex;
};

int main()
{
	shareptr<int> sp1(new int(10));
	shareptr<int> sp2(sp1);
	*sp2 = 20;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	system("pause");
	return 0;
}
#endif

#include<iostream>
#include <thread>
#include <mutex>
using namespace std;

template <class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{
		// 如果是一个空指针对象，则引用计数给0
		if (_ptr == nullptr)
			*_pRefCount = 0;
	}
	~SharedPtr() { Release(); }
	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		// 如果是一个空指针对象，则不加引用计数，否则才加引用计数
		if (_ptr)
			AddRefCount();
	}
	// sp1 = sp2
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		//if (this != &sp)
		if (_ptr != sp._ptr)
		{
			// 释放管理的旧资源
			Release();
			// 共享管理新对象的资源，并增加引用计数
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;
			if (_ptr)
				AddRefCount();
		}
		return *this;
	}
	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }
	int UseCount() { return *_pRefCount; }
	T* Get() { return _ptr; }
	int AddRefCount()
	{
		// 加锁或者使用加1的原子操作
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
		return *_pRefCount;
	}
	int SubRefCount()
	{
		// 加锁或者使用减1的原子操作
		_pMutex->lock();
		--(*_pRefCount);
		_pMutex->unlock();
		return *_pRefCount;
	}
private:
	void Release()
	{
		// 引用计数减1，如果减到0，则释放资源
		if (_ptr && SubRefCount() == 0)
		{
			delete _ptr;
			delete _pRefCount;
		}
	}
private:
	int* _pRefCount; // 引用计数
	T* _ptr; // 指向管理资源的指针 
	mutex* _pMutex; // 互斥锁
};
int main()
{
	SharedPtr<int> sp1(new int(10));
	SharedPtr<int> sp2(sp1);
	*sp2 = 20;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	SharedPtr<int> sp3(new int(10));
	sp2 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	sp1 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	return 0;
}