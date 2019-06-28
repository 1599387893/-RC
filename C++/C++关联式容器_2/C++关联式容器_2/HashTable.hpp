#pragma once
#include<vector>

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
		:_ht(10)
		, _size(0)
	{
		for (auto& e : _ht)
			e._state = EMPTY;
	}

	//≤Â»Î
	bool Insert(const T& data)
	{
		size_t hashadds = HashFunc(data);
		
	}
	int Find(const T& key)
	{

	}
	bool Erase(const T& data)
	{

	}

private:
	T& HashFunc(T& val)
	{
		return val % _ht.capacity();
	}
private:
	vector<Elem<T>> _ht;
	size_t _size;
};