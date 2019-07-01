#pragma once
#include<vector>
#include<list>
#include<iostream>
using namespace std;

template<class T>
struct HashBucketNode
{
	HashBucket(const T& value)
		:_pNext(nullptr)
		, _val(value)
	{}
	HashBucket<T>* _pNext;
	T _val;
};

template<class T>
class HashBucket
{
	typedef HashBucketNode<T> Node;
	typedef Node* PNode;
public:
	HashBucket(const size_t& capacity = 10)
		:_hb(capacity)
		, _size(capacity)
	{}
	bool Insert(const T& data)
	{

	}
	PNode* Find(const T& data)
	{

	}
	bool Erase(const T& data)
	{

	}
private:
	vector<PNode<T>> _hb;
	size_t _size;
};