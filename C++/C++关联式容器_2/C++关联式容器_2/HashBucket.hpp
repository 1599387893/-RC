#pragma once
#include<vector>
#include<list>
#include<iostream>
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

template<class T>
class HashBucket
{
	typedef HashBucketNode<T> Node;
	typedef Node* PNode;
public:
	HashBucket(const size_t& capacity = 10)
		:_table(capacity)
		, _size(capacity)
	{}
	~HashBucket()
	{
		Clear();
	}
	bool Insert(T& data)
	{
		//0.����Ƿ���Ҫ����
		CheckCapacity();
		//1.���㵱ǰԪ�����ڵ�Ͱ��
		size_t bucketNo = HashFunc(data);
		//2.����Ԫ���Ƿ����
		PNode pCur = _table[bucketNo];
		while (pCur)
		{
			if (pCur->_val == data)
				return false;
			pCur = pCur->_pNext;
		}
		//3.����Ԫ�أ����������ͷ�壩
		pCur = new Node(data);
		pCur->_pNext = _table[bucketNo];
		_table[bucketNo] = pCur;
	}
	PNode Find(const T& data)
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
	bool Erase(const T& data)
	{
		size_t bucket = HashFunc(data);
		PNode pCur = _table[bucket];
		PNode pPer = nullptr;
		while (pCur)
		{
			//ɾ�������еĵ�һ�����
			if (pCur->_val == data)
			{
				if (pPer == nullptr)
					_table[bucket] = pCur->_pNext;
				else
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
	size_t size()
	{
		return _size;
	}
private:
	void CheckCapacity()
	{
		//����ЧԪ�ظ�������Ͱ�ĸ���ʱ����
		if (_size == _table.capacity())
		{
			HashBucket<T> newHB(_size * 2);
			for (size_t i = 0; i < _table.capacity(); ++i)
			{
				PNode pCur = _table[i];
				while (pCur)
				{
					//1.���㵱ǰ�ڵ����¹�ϣͰ�е�Ͱ��
					size_t newBucketNo = newHB.HashFunc(pCur->_val);
					
					//2.��pCur�Ӿɹ�ϣͰ���Ƴ�
					_table[i] = pCur->_pNext;
					
					//3.��pCurͷ�嵽�¹�ϣͰ��
					pCur->_pNext = newHB._table[newBucketNo];
					newHB._table[newBucketNo] = pCur;
					
					//4.�Ӿɹ�ϣͰ��ȡ����һ�����
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
		for (int i = 0; i < _table.capacity(); ++i)
		{
			PNode pCur = _table[i];
			while (pCur)
			{
				_table[i] = pCur->_pNext;
				delete pCur;
				pCur = _table[i];
			}
		}
	}
private:
	vector<HashBucketNode<T>*> _table;
	size_t _size;
};

void TestHashBucket()
{
	HashBucket<int> hb(10);
	cout << hb.size() << endl;
	int array[] = { 3, 8, 4, 0, 7, 13, 33 };
	for (auto& e : array)
		hb.Insert(e);
	cout << hb.size() << endl;
}