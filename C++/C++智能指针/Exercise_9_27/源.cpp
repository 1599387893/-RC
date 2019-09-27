#include<iostream>
#include<memory>
#include<string>
using namespace std;

//智能指针：管理指针，自动释放资源
//智能指针没有申请资源的权力

//----------------------------------------------auto_ptr模拟------------------------
//原理：资源转移，RAII
//1.0
template<class T>
class AutoPtr
{
private:
	T* _ptr;
private:
	void Release()
	{
		if (_ptr)
			delete _ptr;
	}
public:
	AutoPtr(T* ptr == nullptr)
		:_ptr(ptr)
	{}
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = nullptr;
	}
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if (this != &ap)
		{
			Release();
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		return *this;
	}
	~AutoPtr()
	{
		Release();
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
};

//2.0
//auto_ptr的问题就是使用者会在不经意间将对象的资源控制权转移出去，而造成后边的访问出现问题；
//改进方法：添加一个成员变量：<bool owner>用来控制资源控制权的归属者（该方法仍有问题：如果拷贝给一个局部变量，可能会造成野指针的问题）
//所以C++标准委员会不建议使用auto_ptr;

//-----------------------------------------------unique_ptr模拟----------------------------
//原理：auto_ptr的基础上加上两个要求：独立管理资源，不可以进行拷贝和赋值（在成员函数中将这两种方法delete）
template<class T>
class UniquePtr
{
private:
	T* _ptr;
public:
	UniquePtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	~UniquePtr()
	{
		if (_ptr)
			delete _ptr;
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
	UniquePtr(UniquePtr<T>&) = delete;
	UniquePtr<T>& operator=(UniquePtr<T>&) = delete;
};
//unique_ptr的缺陷就是：对象之间不可以共享资源；


//----------------------------------------------shared_ptr 模拟---------------------------
//原理：RAII+指针操作方法+引用计数
template<class T>
//添加仿函数的模板template<class T,class DF = DFDel<T>>
class SharedPtr
{
private:
	T* _ptr;
	int* _count;
private:
	void Release()
	{
		if (_ptr && ((*_count--) == 0))
		{
			delete _ptr;
			delete _count;

			//仿函数：DF()(_ptr);
			//DF:  这是一种类型
			//DF():这是一个匿名对象
		}
	}
	void AddCount(SharedPtr<T>& sp)
	{
		_ptr = sp._ptr;
		_count = sp._count;
		if (_ptr)
			(*_count)++;
	}
public:
	SharedPtr(T* ptr = nullptr)
		:_ptr(ptr)
		, _count(nullptr)
	{
		if (_ptr)
			_count = new int(1);
	}
	SharedPtr(SharedPtr<T>& sp)
	{
		AddCount(sp);
	}
	SharedPtr<T>& operator=(SharedPtr<T>& sp)
	{
		if (this != &sp)
		//优化：if(_ptr != sp._ptr)
		{
			Release();
			AddCount(sp);
		}
		return *this;
	}
	~SharedPtr()
	{
		Release();
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	int Use_count()
	{
		return *_count;
	}
};
//shared_ptr缺陷1:当new对象时，使用malloc申请空间，或者使用文件指针
//shared_ptr缺陷2:可能会产生循环引用的问题
//缺陷1的解决方法：仿函数------使用：SharedPtr<int,Free<int>>  + DF()(_ptr);
/*
-----------------------------------------------------------------定制删除器
		template<class T>-------用 new申请出来的
		class DFDel
		{
			public:
				void operator()(T*& ptr)
				{
					delete ptr;
					ptr = nullptr;
				}
		}
		template<class T>-------用 malloc申请出来的
		class Free
		{
			public:
				void operator()(T*& ptr)
				{
					free(ptr);
					ptr = nullptr;
				}
		}
		-------------------------用 FIFE申请出来的
		class Close
		{
			public:
				void operator()(FIFE*& ptr)
				{
					fclose(ptr);
					ptr = nullptr;
				}
		}
*/


//-----------------------------------------------weak_ptr模拟-------------------------------------
template<class T>
class WeakPtr
{
private:
	T* _ptr;
};













int main()
{
	auto_ptr<string> ap1(new string{ "str1" });
	auto_ptr<string> ap2(ap1);
	system("pause");
	return 0;
}