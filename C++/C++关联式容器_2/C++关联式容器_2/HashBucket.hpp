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

//�º���
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
		//2.return (ÿ���ַ�ASCIIֵ֮��)
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
				//ɾ�������еĵ�һ�����
				if (pPer == nullptr)
					_table[bucket] = pCur->_pNext;
				else//ɾ������ǵ�һ���Ľ��
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
		//����ЧԪ�ظ�������Ͱ�ĸ���ʱ����
		if (_size == _table.capacity())
		{
			HashBucket<T> newHB(GetNextPrime(_table.capacity()));
			//��0��ʼ����Ϊ_table�ײ�ṹΪvector;
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