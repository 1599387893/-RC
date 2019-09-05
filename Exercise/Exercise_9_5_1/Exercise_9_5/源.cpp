#include<iostream>
#include<algorithm>
#include<assert.h> 
using namespace std;

namespace RC
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		//¹¹Ôìº¯Êý
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}
		vector(size_t n, const T& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			//1.
			//reserve(n);
			//while (n-- >= 0)
			//	_start = value;

			//2.
			_start = new T[n];
			_finish = _start;
			_endOfStorage = _start + n;
			while (_finish != _endOfStorage)
			{
				*_finish = value;
				++_finish;
			}
		}
		vector(T* start, T* finish)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			//1.
			//reserve(finish - start);
			//while (_finish != _endOfStorage)
			//{
			//	(*_finish)++ = (*start)++;
			//}

			//2.
			_start = new T[finish - start];
			_finish = _start;
			_endOfStorage = _start + (finish - start);
			while (start != finish)
			{
				*_finish++ = *start++;
			}
		}
		vector(const vector<T>& v)
		{
			size_t size = v.size();
			_start = new T[size];
			_finish = _start;
			_endOfStorage = _start + size;
			for (size_t i = 0; i < size; ++i)
			{
				*_finish++ = v._start[i];
			}
		}
		vector& operator=(const vector<T>& v)
		{
			if (this != &v)
			{
				vector<T> temp(v);
				delete[] _start;
				_start = nullptr;
				_finish = nullptr;
				_endOfStorage = nullptr;

				swap(_start, temp._start);
				swap(_finish, temp._finish);
				swap(_endOfStorage, temp._endOfStorage);
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
				_endOfStorage = nullptr;
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
		//capacity
		size_t size()const
		{
			return  _finish - _start;
		}
		size_t capacity()const
		{
			return _endOfStorage - _start;
		}
		bool empty()const
		{
			if (_start)
				return false;
			return true;
		}
		void resize(size_t newsize,const T& data = T())
		{
			if (newsize > size())
			{
				if (newsize > capacity())
					reserve(newsize);
				while (_finish != _endOfStorage)
					*_finish++ = data;
			}
			_finish = _start + newsize;
		}
		void reserve(size_t newcapacity)
		{
			if (newcapacity > capacity())
			{
				iterator temp = new T[newcapacity];
				size_t size = _finish - _start;
				for (size_t i = 0; i < size; ++i)
					temp[i] = _start[i];

				delete[] _start;
				_start = temp;
				_finish = _start + size;
				_endOfStorage = _start + newcapacity;
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
			assert(_start);
			return *_start;
		}
		const T& front()const
		{
			assert(_start);
			return *_start;
		}
		T& back()
		{
			assert(_start);
			return *(_finish-1);
		}
		const T& back()const
		{
			assert(_start);
			return *(_finish-1);
		}
		//moditfy
		void Swap(RC::vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}
		void push_back(const T& data)
		{
			if (_finish == _endOfStorage)
				reserve(2*(_endOfStorage - _start));
			*_finish++ = data;
		}
		void pop_back()
		{
			if (_finish != _start)
				_finish--;
		}
		iterator insert(iterator pos, const T& data)
		{
			assert(pos || pos > _finish || pos < _start);
			if (_finish == _endOfStorage)
				reserve(2 * (_endOfStorage - _start));

			auto it = _finish;
			while (it != pos-1)
			{
				*(it + 1) = *it;
				it--;
			}
			*pos = data;
			_finish++;
			return it;
		}
		iterator erase(iterator pos)
		{
			assert(pos || pos > _finish || pos < _start);
			auto it = pos;
			while (it != _finish-1)
			{
				*it = *(it + 1);
				it++;
			}
			_finish--;
			return pos;
		}
		void clear()
		{
			_finish = _start;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endOfStorage;
	};
}

void PrintV(RC::vector<int>& v)
{
	auto it = v.begin();
	while (it != v.end())
		cout << *it++ << " ";
	cout << endl;
}
void Test()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	RC::vector<int> v1;
	RC::vector<int> v2(5,1);
	RC::vector<int> v3(arr, arr + (sizeof(arr) / sizeof(arr[0])));
	RC::vector<int> v4(v2);

	PrintV(v1);
	PrintV(v2);
	PrintV(v3);
	PrintV(v4);
	v4 = v3;
	PrintV(v4);

	
}
void TestCapacity()
{
	RC::vector<int> v(10, 1);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	
	v.resize(5, 2);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	
	v.resize(15, 3);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}
void TestAccess()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	RC::vector<int> v(arr,arr+7);
	cout << v[5] << endl;
	cout << v[2] << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;
}
void TestModity()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	RC::vector<int> v(arr, arr + 6);
	PrintV(v);
	v.push_back(7);
	v.push_back(8);
	PrintV(v);
	v.pop_back();
	v.pop_back();
	v.pop_back();
	PrintV(v);
	v.insert(v.begin(), 0);
	v.insert(v.begin()+3,11);
	PrintV(v);
	v.erase(v.begin());
	v.erase(v.begin() + 2);
	PrintV(v);
}

int main()
{
	//Test();
	//TestCapacity();
	//TestAccess();
	TestModity();
	system("pause");
	return 0;
}