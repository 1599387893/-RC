#pragma once
#include<iostream>
using namespace std;

namespace RC
{
	template<class T>
	class vetor
	{ 
		typedef T* iterator;
	public:
		//¹¹Ôìº¯Êý
		vector() 
			:_start(nullptr)
			,_finish(nullptr)
			, _endOfStorage(nullptr)
		{}
		
		vector(size_t n, T& value = T()) 
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			_start = new T[n];
			_endOfStorage = _start + n;
			for (int i = n; i > 0; --i)
				_start[i] = value;
			_finish = _start + n;
		}
		
		vector(T* first, T* last)
		{
			size_t size = last - first;
			_start = new T[size];
			for (size_t i = 0; i < size; ++i)
				_start[i] = first[i];

			_finish = _endOfStorage = _start + size;
		}

		vector(const vector& v)
		{
			_start = new T[v.size()];
			for (size_t i = 0; i < v.size(); ++i)
			{
				_start[i] = v[i];
			}
			_finish = _start + v.size();
			_endOfStorage = _finish;
		}
		vector(const T* arr, size_t size);
		~vector();
		/////////////////////////////////////////////////////////////////////////
		//iterator
		iterator begin();
		iterator end();
		iterator rbegin();
		iterator rend();
		/////////////////////////////////////////////////////////////////////////
		//capacity
		size_t Size()const
		{
			return _start - _finish;
		}
		size_t Capacity()const 
		{
			return _start - _endOfStorage;
		}
		bool Empty()const
		{
			return _start == _finish;
		}
		void Resize();
		void Reserve();
		/////////////////////////////////////////////////////////////////////////
		//access
		T& operator[](size_t index)
		{
			assert(index < this.size());
			return _start[index];
		}
		const T& operator[](size_t index)const
		{
			assert(index < this.size());
			return _start[index];
		}
		//at 
		T& Front()
		{
			if (_start != _finish)
				return _start[0];
		}
		const T& Front()const
		{
			if (_start != _finish)
				return _start[0];
		}
		T& Back()
		{
			return _finish[-1];
		}
		const T& Back()const
		{
			return _finish[-1];
		}
		/////////////////////////////////////////////////////////////////////////
		//modifiers
		void Push_Back(const T& data)
		{
			if (_start == _finish)
				Reserve(2 * this.size());
			_start[this.size()] = data;
			_endOfStorage = ++_finish;
		}
		void Pop_Back()
		{
			if (_start != _finish)
				--_finish;
		}
		iterator Insert(iterator pos,const T& x);
		iterator Erase(iterator pos);
		void Swap(vector<T>& v);
		void clear();
		/////////////////////////////////////////////////////////////////////////
		//allocator

	private:
		T* _start;
		T* _finish;
		T* _endOfStorage;
	};
}
void Testvector_GZ();
void Testvector_iterator();
void Testvector_capacity();
void Testvector_access();
void Testvector_modifiers();
void Testvector_allcator();

int main()
{

}