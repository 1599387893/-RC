#if 0
#pragma once
#include<algorithm>
#include<assert.h>
#include<iostream>
using namespace std;

namespace RC
{
	template<class T>
	class vetor
	{ 
		typedef T* iterator;
	public:
		//构造函数
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

#endif


#include<iostream>
#include<assert.h>
#include<algorithm>
using namespace std;

namespace RC
{
	template<class T>
	class vector
	{
	public:
		typedef T* iteraotr;
	public:
		//构造函数
		vector() :_start(nullptr), _finish(nullptr), _endOfstorage(nullptr){}
		vector(size_t n, const T& data = T())
			:_start(new T[n])
			, _finish(_start + n)
			, _endOfstorage(_finish)
		{
			for (size_t i = 0; i < n; ++i)
				_start[i] = data;
		}
		vector(const T* first, const T* last)
			:_start(new T[first - last])
			, _finish(_start + (first - last))
			, _endOfstorage(_finish)
		{
			size_t size = first - last;
			for (size_t i = 0; i < size; ++i)
				_start[i] = first[i];
		}
		vector(const vector& v)
			:_start(new T[v.size()])
			, _finish(_start + v.size())
			, _endOfstorage(_finish)
		{
			for (size_t i = 0; i < v.size(); ++i)
				_start[i] = v[i];
		}
		vector<T>& operator=(const vector& v)
		{
			if (this != &v)
			{
				_start = new T[v.size()];
				_finish = _start + v.size();
				_endOfstorage = _finish;
				for (size_t i = 0; i < v.size(); ++i)
				_start[i] = v[i];
			}
				return *this;
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = nullptr;
				_finish = nullptr;
				_endOfstorage = nullptr;
			}
		}
		//iterator
		iteraotr begin()
		{
			return _start;
		}
		iteraotr end()
		{
			return _finish;
		}
		//capacity
		int size()const
		{
			return _start - _finish;
		}
		int capacity()const
		{
			return _start - _endOfstorage;
		}
		bool empty()const
		{
			return _start == _finish;
		}
		void resize(size_t newSize,const T& data = T())
		{
			if (size() < newSize)
			{
				if (capacity() < newSize)
					reserve(newSize);//申请空间
				for (size_t = size(); i < newSize; ++i)
					*_finish++ = data;			
					//*_finish[i] = data;???????
			}
			_finish = _start + newSize;
		}
		void reserve(size_t newCapacity)
		{
			if (newCapacity > capacity())
			{
				T* temp = new T[newCapacity];
				if (_start)
					for (size_t i = 0; i < size(); ++i)
						temp[i] = _start[i];
				
				delete[] _start;
				_start = temp;
				_finish = _start + size();//此时_start的位置已经改变，所以应该修改_finish和_endOfstorage的位置
				_endOfstorage = _start + newCapacity;
			}
		}
		//access
		T& operator[](size_t index)
		{
			assert(index < size());
			return _start[index];
		}
		const T& operator[](size_t index)const
		{
			assert(index < size());
			return _start[index];
		}
		T& front()
		{
			return _start[0];
		}
		const T& front()const
		{
			return _start[0];
		}
		T& back()
		{
			return *(_finish-1);
		}
		const T& back()const
		{
			return *(_finish-1);
		}
		//modefity
		void push_back(const T& data)
		{
			if (_finish == _endOfstorage)
				reserve(2 * capacity());

			*_finish++ = data;
		}
		void pop_back()
		{
			if (_finish - _start > 0)
				--_finish;
			reutrn;
		}
		iterator insert(iterator pos,const T& data)
		{
			if (_finish == _endOfstorage)
				reserve(2 * capacity());
			
			if (pos > size())
				*_finish++ = data;
			else
			{
				int i = size();
				for (; i > pos-_start; --i)
					_start[i] = _start[i - 1];
				*pos = data;
				_finish++;
			}
			return pos;
		}
		iterator erase(iterator pos)
		{
			if (pos > size())
				return end();

			//1.0
			for (size_t i = pos - _start; i < (size() - 1); --i)
			{
				_start[i + 1] = _start[i];
			}
			_finish--;
			
			//2.0
			/*iterator cur = pos;
			iterator curNext = cur + 1;
			while (curNext != _finish)
				*cur++ = *curNext++;

			return pos;*/
		}
		void clear()
		{
			_finish = _start;
		}
		void swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfstorage, v._endOfstorage);
		}
	private:
		T* _start;
		T* _finish;//最后一个元素的下一个位置
		T* _endOfstorage;
	};
}

void Print(RC::vector<int>& v)
{
	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{

	RC::vector<int> v2(10, 5);
	//Print(v2);
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	RC::vector<int> v3(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//Print(v3);
	RC::vector<int> v4(v3);
	//Print(v4);

	return 0;
}