#include<iostream>
#include<assert.h>
using namespace std;

namespace RC
{
	template<class T>
	class vector
	{
	public:
		typedef T* Iterator;
		typedef constT* ConstIterator;
	public:
		//iterator
		Iterator begin(){
			return _start;
		}
		ConstIterator begin()const{
			return _start;
		}
		Iterator end()
		{
			return _finish;
		}
		ConstIterator end()const
		{
			return _finish;
		}
		Iterator rbegin()
		{
			return _finish;
		}
		ConstIterator rend()const
		{
			return _start;
		}
		//构造函数
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfstroage(nullptr)
		{}
		vector(int n, const T& value = T())
			:_start(nullptr)
			,_finish(nullptr)
			, _endOfstroage(nullptr)
		{
			Reserve();
			while (n--)
				PushBack(value);
		}
		vector(T* start, T* finish)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfstroage(nullptr)
		{
			Reserve(finish - start);
			while (start != finish)
			{
				*_finish = *start;
				start++;
			}
		}
		vector(vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfstroage(nullptr)
		{
			Reserve(v._finish - v._start);
			Iterator it = v._start;
			while (it != v._finish)
			{
				*_finish = *it;
				it++;
			}
		}
		vector& operator=(vector<T> v)
		{
			if (this != &v)
			{
				delete[] _start;
				Swap(v);
			}
			return *this;
		}
		//析构函数
		~Vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = nullptr;
			}
		}
		//capacity
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _endOfstroage - _start;
		}
		bool empty()
		{
			if (_start)
				return false;
			return true;
		}
		void resize(size_t n,T& value = T());
		void reserve(size_t n);
		//access
		T& operator[](size_t pos);
		T& at(size_t pos);
		T& front();
		T& back();
		//modefity
		void PushBack(T& value);
		void PopBack();
		T* Insert(T* pos,T& value = T());
		T* Erase(T* pos);
		void Swap(vector<T>& v);
		void clear();
	private:
		Iterator _start;
		Iterator _finish;
		Iterator _endOfstroage;
	};
}
