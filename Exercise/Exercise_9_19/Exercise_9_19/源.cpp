#include<iostream>
#include<memory>//����ָ�붼������memory��
using namespace std;

//auto_ptrʹ��

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
	auto_ptr<Date> copy(ap);//�ڿ���֮��ǰ��Ķ�������գ�ָ��գ�

	ap->_year = 2018;
	return 0;	
}
#endif

//��ģ��auto_ptr
template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	~AutoPtr()
	{
		if (_ptr)
			delete _ptr;
	}
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = nullptr;
	}
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if (this != &ap)
		{
			if (_ptr)
				delete _ptr;
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		return *this;
	}
	T& operator*(){ return *_ptr; }
	T* operator->(){ return _ptr; }
private:
	T* _ptr;
};

//unique_ptr��ģ��ʵ��
template<class T>
class UniquePtr
{
public:
	UniquePtr(T* ptr)
		:_ptr(ptr)
	{}
	~UniquePtr()
	{
		if (_ptr)
			delete _ptr;
	}
	T& operator*(){ return *_ptr; }
	T* operator->(){ return _ptr; }
private:
	UniquePtr(UniquePtr<T>& up) = delete;
	UniquePtr& operator=(UniquePtr<T>& up) = delete;
private:
	T* _ptr;
};


int main()
{
	//AutoPtr<Date> ap(new Date);
	//AutoPtr<Date> copy(ap);
	//ap->_year = 2018;  ���ִ���

	//unique_ptrʹ��
	//unique_ptr<Date> up(new Date);
	//unique_ptr<Date> copy2(up);

	//UniquePtr<Date> up(new Date);
	//UniquePtr<Date> copy3(up);

	system("pause");
	return 0;
}