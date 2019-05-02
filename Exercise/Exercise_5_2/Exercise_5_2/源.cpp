#include<iostream>
#include<assert.h>
using namespace std;

namespace RC
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		//ππ‘Ï
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
		{
			size_t size = last - first;
			_start = new T[size];
			for (size_t i = 0; i < size; ++i)
				_start[i] = first[i];
			_finish = _start + size;
			_endOfstorage = _finish;
		}
		vector(const T& v)
		{
			size_t size = v.size();
			_start = new T[size];
			for (size_t i = 0; i < size; ++i)
				_start[i] = v[i];
			_finish = _start + size;
			_endOfstorage = _finish;
		}
		vector<T> operator=(const vector& v)
		{
			if (this != &v)
			{
				size_t size = v.size();
				_start = new T[size];
				for (size_t i = 0; i < size; ++i)
					_start[i] = v[i];
				_finish = _start + size;
				_endOfstorage = _finish;
			}
			return *this;
		}
		~vector()
		{
			if (_start != _finish)
			{
				delete[] _start;
				_start = nullptr;
				_finish = nullptr;
				_endOfstorage = nullptr;
			}
		}
		//iterator
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		iterator rbegin()
		{
			return _finish;
		}
		iterator rend()
		{
			return _start;
		}
		//capacity
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _endOfstorage - _start;
		}
		bool empty()const
		{
			return _start == _finish;
		}
		void resize(size_type newSize,T& c = T())
		{
			if (newSize > size())
			{
				if (newSize > capacity())
					reserve(newSize);

				size_t addSize = newSize - size();
				memset(_start + size(), c, sizeof(_start) / sizeof(_start[0])*addSize);
			}
			_finish = _start + newSize;
		}
		void reserve(size_type newCapacity)
		{
			if (newCapacity > capacity())
			{
				T* temp = new T[newCapacity];
				memcpy(temp, _start, (sizeof(_start) / sizeof(_start[0]))*sizeof(_start[0]));

				delete[] _start;
				_start = temp;
				_capacity = newCapacity;
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
		T& back()
		{
			return _start[size()-1];
		}
		//modefity
		void push_back(const T& c)
		{
			if (_finish == _endOfstorage)
				reserve(2 * capacity());
			_start[size()] = c;
			_finish++;
		}
		void pop_back()
		{
			--_finish;
		}
		void swap(vector<T>& vec)
		{
			swap(_start, vec._start);
			swap(_finish, vec._finish);
			swap(_endOfstorage, vec._endOfstorage);
		}
		void clear()
		{
			if (_start != _finish)
			{
				delete[] _start;
				_start = nullptr;
				_finish = nullptr;
				_endOfstorage = nullptr;
			}
		}
	private:
		T* _start;
		T* _finish;
		T* _endOfstorage;
	};
}
void testvector()
{
	RC::vector<int> v1;
	RC::vector<int> v2(10, 2);
	RC::vector<int> v3(v2);
	v1 = v3;
}

int main()
{
	testvector();

	return 0;
}
