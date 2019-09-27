#include<iostream>
#include<memory>
#include<string>
using namespace std;

//����ָ�룺����ָ�룬�Զ��ͷ���Դ
//����ָ��û��������Դ��Ȩ��

//----------------------------------------------auto_ptrģ��------------------------
//ԭ����Դת�ƣ�RAII
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
//auto_ptr���������ʹ���߻��ڲ�����佫�������Դ����Ȩת�Ƴ�ȥ������ɺ�ߵķ��ʳ������⣻
//�Ľ����������һ����Ա������<bool owner>����������Դ����Ȩ�Ĺ����ߣ��÷����������⣺���������һ���ֲ����������ܻ����Ұָ������⣩
//����C++��׼ίԱ�᲻����ʹ��auto_ptr;

//-----------------------------------------------unique_ptrģ��----------------------------
//ԭ��auto_ptr�Ļ����ϼ�������Ҫ�󣺶���������Դ�������Խ��п����͸�ֵ���ڳ�Ա�����н������ַ���delete��
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
//unique_ptr��ȱ�ݾ��ǣ�����֮�䲻���Թ�����Դ��


//----------------------------------------------shared_ptr ģ��---------------------------
//ԭ��RAII+ָ���������+���ü���
template<class T>
//��ӷº�����ģ��template<class T,class DF = DFDel<T>>
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

			//�º�����DF()(_ptr);
			//DF:  ����һ������
			//DF():����һ����������
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
		//�Ż���if(_ptr != sp._ptr)
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
//shared_ptrȱ��1:��new����ʱ��ʹ��malloc����ռ䣬����ʹ���ļ�ָ��
//shared_ptrȱ��2:���ܻ����ѭ�����õ�����
//ȱ��1�Ľ���������º���------ʹ�ã�SharedPtr<int,Free<int>>  + DF()(_ptr);
/*
-----------------------------------------------------------------����ɾ����
		template<class T>-------�� new���������
		class DFDel
		{
			public:
				void operator()(T*& ptr)
				{
					delete ptr;
					ptr = nullptr;
				}
		}
		template<class T>-------�� malloc���������
		class Free
		{
			public:
				void operator()(T*& ptr)
				{
					free(ptr);
					ptr = nullptr;
				}
		}
		-------------------------�� FIFE���������
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


//-----------------------------------------------weak_ptrģ��-------------------------------------
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