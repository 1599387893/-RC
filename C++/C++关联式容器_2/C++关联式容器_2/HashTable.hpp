#pragma once
#include<vector>
#include<iostream>
using namespace std;

//假设：哈希表格中的元素具有唯一性

enum State {EMPTY,EXIST,DELETE};

template<class T>
struct Elem
{
	T _val;
	State _state;
};

template<class T>
class HashTable
{
public:
	HashTable(size_t capacity = 10)
		:_ht(capacity)
		, _size(0)
	{
		for (auto& e : _ht)
			e._state = EMPTY;
	}

	//插入
	bool Insert(const T& data)
	{
		//检测是否需要扩容
		
		//求出哈希地址
		size_t hashadds = HashFunc(data);
		
		//确定该位置为空（EMPYTY）即可插入
		while (_ht[hashadds]._state != EMPTY)
		{
			//如果该结点存在，返回false
			if (_ht[hashadds]._state == EXIST && _ht[hashadds]._val == data)
				return false;

			++hashadds;

			if (hashadds == _ht.capacity())
				hashadds = 0;
		}
		
		_ht[hashadds]._state = EXIST;
		_ht[hashadds]._val = data;
		++_size;

		return true;
	}
	int Find(const T& data)
	{
		size_t hashadds = HashFunc(data);
		//如果该位置的标记不为空（EXIST,DELETE）继续循环
		while (_ht[hashadds]._state != EMPTY)
		{
			if (_ht[hashadds]._state == EXIST && _ht[hashadds]._val == data)
				return hashadds;

			hashadds++;
			if (hashadds == _ht.capacity())
				hashadds = 0;
		}

		return -1;
	}
	bool Erase(const T& data)
	{
		int pos = Find(data);
		if (-1 != pos)
		{
			_ht[pos]._state = DELETE;
			return true;
		}
		return false;

	}

private:
	size_t HashFunc(const T& val)
	{
		return val % _ht.capacity();
	}
private:
	vector<Elem<T>> _ht;
	size_t _size;
};

void TestHashTable()
{
	HashTable<int> ht;
	int array[] = { 1, 4, 5, 6, 7, 44, 9 };
	for (auto& e : array)
		ht.Insert(e);

	cout<<ht.Erase(5)<<endl;
	cout<<ht.Find(44)<<endl;
	ht.Insert(34);

}