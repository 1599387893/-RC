#pragma once
#include<vector>
#include<list>
#include<iostream>
#include<string>
#include"Common.h"
using namespace std;

template<class T>
struct HashBucketNode
{
	HashBucketNode(const T& value)
		:_pNext(nullptr)
		, _val(value)
	{}
	HashBucketNode<T>* _pNext;
	T _val;
};

//仿函数
template<class T>
class D2INT
{
public:
	T operator()(const T& data)
	{
		return data;
	}
};
template<class T>
class String2INT
{
public:
	size_t operator()(const string& s)
	{
		//1.return s[0];
		//2.return (每个字符ASCII值之和)
		//3.return (size_t)s.c_str();
		//4.
		return BKDRHash(s.c_str());
	}
};

template<class T>
class HashBucket
{
	typedef HashBucketNode<T> Node;
	typedef Node* PNode;
public:
	HashBucket(const size_t& capacity = 10)
		:_table(GetNextPrime(capacity),nullptr)
		, _size(0)
	{}
	~HashBucket()
	{
		Clear();
	}
	bool Insert(T& data)
	{
		//0.检测是否需要扩容
		CheckCapacity();
		//1.计算当前元素所在的桶号
		size_t bucketNo = HashFunc(data);
		//2.检测该元素是否存在
		PNode pCur = _table[bucketNo];
		while (pCur)
		{
			if (pCur->_val == data)
				return false;
			pCur = pCur->_pNext;
		}
		//3.插入元素（类似链表的头插）
		pCur = new Node(data);
		pCur->_pNext = _table[bucketNo];
		_table[bucketNo] = pCur;
		_size++;
		return true;
	}
	PNode Find(T data)
	{
		size_t bucket = HashFunc(data);
		PNode pCur = _table[bucket];
		while (pCur)
		{
			if (pCur->_val == data)
				return pCur;
			pCur = pCur->_pNext;
		}
		return nullptr;
	}
	bool Erase(T data)
	{
		size_t bucket = HashFunc(data);
		PNode pCur = _table[bucket];
		PNode pPer = nullptr;
		while (pCur)
		{
			if (pCur->_val == data)
			{
				//删除链表中的第一个结点
				if (pPer == nullptr)
					_table[bucket] = pCur->_pNext;
				else//删除链表非第一个的结点
					pPer->_pNext = pCur->_pNext;
				delete pCur;
				pCur = nullptr;
				--_size;
				return true;
			}
			pPer = pCur;
			pCur = pCur->_pNext;
		}
		return false;
	}
	size_t Size()
	{
		return _size;
	}
	void Print()
	{
		PNode pCur = nullptr;
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo)
		{
			cout << "H[" << bucketNo << "]:";
			pCur = _table[bucketNo];
			while (pCur)
			{
				cout << pCur->_val << "--->";
				pCur = pCur->_pNext;
			}
			cout <<"NULL"<< endl;
		}
		
	}
private:
	void CheckCapacity()
	{
		//当有效元素个数等于桶的个数时扩容
		if (_size == _table.capacity())
		{
			HashBucket<T> newHB(GetNextPrime(_table.capacity()));
			//从0开始是因为_table底层结构为vector;
			for (size_t i = 0; i < _table.capacity(); ++i)
			{
				PNode pCur = _table[i];
				while (pCur)
				{
					//1.计算当前节点在新哈希桶中的桶号
					size_t newBucketNo = newHB.HashFunc(pCur->_val);
					
					//2.将pCur从旧哈希桶中移除
					_table[i] = pCur->_pNext;
					
					//3.将pCur头插到新哈希桶中
					pCur->_pNext = newHB._table[newBucketNo];
					newHB._table[newBucketNo] = pCur;
					
					//4.从旧哈希桶中取出下一个结点
					pCur = _table[i];
				}
			}
			_table.swap(newHB._table);
			swap(newHB._size, _size);
		}
	}
	size_t HashFunc(T& data)
	{
		return data % _table.capacity();
	}
	void Clear()
	{
		for (size_t i = 0; i < _table.capacity(); ++i)
		{
			PNode pCur = _table[i];
			while (pCur)
			{
				_table[i] = pCur->_pNext;
				delete pCur;
				pCur = _table[i];
			}
		}
		_size = 0;
	}
private:
	vector<PNode> _table;
	size_t _size;
};

void TestHashBucket()
{
	HashBucket<int> hb(10);
	cout << hb.Size() << endl;
	int array[] = { 3, 8, 4, 0, 7, 13, 33 };
	for (auto& e : array)
		hb.Insert(e);
	cout << hb.Size() << endl;
	hb.Print();
	hb.Erase(11);
	hb.Erase(33);
	if (nullptr == hb.Find(33))
		cout << "33 is not in HashBucket" << endl;
	hb.Print();
	hb.~HashBucket();
	cout<<hb.Size();
}