#include<iostream>
#include<memory>
#include<thread>
#include<mutex>
using namespace std;

class Date
{
public:
	Date(int year = 2019, int month = 10, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
//模拟shared_ptr
template<class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		:_ptr(ptr)
		, _useCount(new int(1))
		, _pMutex(new mutex)
	{
		if (nullptr == _ptr)
			*_useCount = 0;
	}
	~SharedPtr()
	{
		Release();
	}
	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _useCount(sp._useCount)
		, _pMutex(sp._pMutex)
	{
		if (_ptr)
			AddCount();
	}
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			//释放资源
			Release();

			_ptr = sp._ptr;
			_useCount = sp._useCount;
			_pMutex = sp._pMutex;
			
			if (_ptr)
				AddCount();
		}
		return *this;
	}
	T& operator*(){ return *_ptr; }
	T* operator->() { return _ptr; }
	int UseCount()
	{
		return *_useCount;
	}
	T* Get()
	{
		return _ptr;
	}
	int AddCount()
	{
		_pMutex->lock();
		++(*_useCount);
		_pMutex->unlock();

		return *_useCount;
	}
	int SubCount()
	{
		_pMutex->lock();
		--(*_useCount);
		_pMutex->unlock();
		return *_useCount;
	}
private:
	void Release()
	{
		if (_ptr && SubCount() == 0)
		{
			delete _ptr;
			delete _useCount;
		}
	}
private:
	T* _ptr = nullptr;
	int* _useCount;//引用计数
	mutex* _pMutex;
};
int main()
{
	//shared_ptr的使用
	/*shared_ptr<Date> sp1(new Date);
	cout <<"copy befor:"<< sp1.use_count() << endl;

	shared_ptr<Date> sp2(sp1);
	cout << "copy after:" << endl;
	cout<<sp1.use_count() << endl;
	cout << sp2.use_count() << endl;*/

	SharedPtr<int> sp1(new int);
	SharedPtr<int> sp2(sp1);
	//*sp2 = 20;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl<<endl;

	SharedPtr<int> sp3(new int(10));
	sp2 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl<<endl;

	sp1 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;

	system("pause");
	return 0;
}