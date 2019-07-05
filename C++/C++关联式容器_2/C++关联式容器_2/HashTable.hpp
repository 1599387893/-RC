#pragma once
#include<iostream>
#include<vector>
using namespace std;
//插入元素具有唯一性(删除位置不能再次插入元素)
enum State {EMPTY,EXIST,DELETE};

template<class T>
struct Elem
{
	T _val;
	State _state;
};

template<class T,bool IsLine = true>
class HashTable
{
public:
	HashTable(size_t capacity = 10)
		:_ht(capacity)
		, _size(0)
	{}
	//插入
	bool Insert(const T& data)
	{
		//0.检测是否需要扩容
		CheckCapacity();
		//1.通过哈希函数计算元素在哈希表中的存储位置
		size_t hashadds = HashFunc(data);
		int i = 0;

		//2.检测该位置是否可以直接插入元素
		//如果发生哈希冲突
		while (_ht[hashadds]._state != EMPTY)
		{
			//如果该元素存在，返回false
			if (_ht[hashadds]._state == EXIST && _ht[hashadds]._val == data)
				return false;
			//若该位置被占用，则向后找下一个空位置（线性探测）
			if (IsLine)
			{
				hashadds++;
				if (hashadds = _ht.capacity())
					hashadds = 0;
			}
			else//二次探测
			{
				hashadds = hashadds + 2 * i + 1;
				hashadds %= _ht.capacity();
			}

		}
		//插入元素
		_ht[hashadds]._val = data;
		_ht[hashadds]._state = EXIST;
		_size++;
		return true;
	}
	//查找
	size_t Find(const T& data)
	{
		size_t hashadds = HashFunc(data);
		int i = 0;
		while (_ht[hashadds]._state != EMPTY)
		{
			if (_ht[hashadds]._state == EXIST && _ht[hashadds]._val == data)
				return hashadds;

			//（线性探测--缺陷：容易发生数据堆积--解决方法：二次探测--H(i+1) = H(i) + i ^ 2 + 1）
			if (IsLine)
			{
				++hashadds;
				if (hashadds = _ht.capacity())
					hashadds = 0;
			}
			else//二次探测（缺陷：当有效元素个数逐渐接近容量时，找到空位置的概率会降低；空间利用率低）
			{
				hashadds = hashadds + 2 * i + 1;
				hashadds %= _ht.capacity();
			}
		}
		return -1;
	}
	//删除
	bool Erase(const T& data)
	{
		size_t hashadds = Find(data);
		if (-1 != hashadds)
		{
			_ht[hashadds]._state = DELETE;
			_size--;
			return true;
		}
		return false;
	}
private:
	//扩容函数
	void CheckCapacity()
	{
		//负载因子：有效元素个数/哈希表容量
		if (_size * 10 / _ht.capacity() >= 7)
		{
			HashTable<T> Newht(2 * _ht.capacity());
			//将原哈希表中存在的元素搬移到新哈希表中；
			for (int i = 0; i < _ht.capacity(); ++i)
			{
				if (_ht[i]._state == EXIST)
					Newht.Insert(_ht[i]._val);
			}
			_ht.swap(Newht._ht);
			swap(_size, Newht._size);
		}
	}
	//哈希函数
	int HashFunc(int data)
	{
		return data % _ht.capacity();
	}
private:
	vector<Elem<T>> _ht;
	size_t _size;
};

void TestHashTable()
{
	HashTable<int> ht;
	int array[] = { 4,7,8,27,9,5,3,1};
	for (auto& e : array)
		ht.Insert(e);

	ht.Erase(5);
	ht.Insert(34);

}