#pragma once
#include<iostream>
#include<vector>
using namespace std;
//����Ԫ�ؾ���Ψһ��(ɾ��λ�ò����ٴβ���Ԫ��)
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
	//����
	bool Insert(const T& data)
	{
		//0.����Ƿ���Ҫ����
		CheckCapacity();
		//1.ͨ����ϣ��������Ԫ���ڹ�ϣ���еĴ洢λ��
		size_t hashadds = HashFunc(data);
		int i = 0;

		//2.����λ���Ƿ����ֱ�Ӳ���Ԫ��
		//���������ϣ��ͻ
		while (_ht[hashadds]._state != EMPTY)
		{
			//�����Ԫ�ش��ڣ�����false
			if (_ht[hashadds]._state == EXIST && _ht[hashadds]._val == data)
				return false;
			//����λ�ñ�ռ�ã����������һ����λ�ã�����̽�⣩
			if (IsLine)
			{
				hashadds++;
				if (hashadds = _ht.capacity())
					hashadds = 0;
			}
			else//����̽��
			{
				hashadds = hashadds + 2 * i + 1;
				hashadds %= _ht.capacity();
			}

		}
		//����Ԫ��
		_ht[hashadds]._val = data;
		_ht[hashadds]._state = EXIST;
		_size++;
		return true;
	}
	//����
	size_t Find(const T& data)
	{
		size_t hashadds = HashFunc(data);
		int i = 0;
		while (_ht[hashadds]._state != EMPTY)
		{
			if (_ht[hashadds]._state == EXIST && _ht[hashadds]._val == data)
				return hashadds;

			//������̽��--ȱ�ݣ����׷������ݶѻ�--�������������̽��--H(i+1) = H(i) + i ^ 2 + 1��
			if (IsLine)
			{
				++hashadds;
				if (hashadds = _ht.capacity())
					hashadds = 0;
			}
			else//����̽�⣨ȱ�ݣ�����ЧԪ�ظ����𽥽ӽ�����ʱ���ҵ���λ�õĸ��ʻή�ͣ��ռ������ʵͣ�
			{
				hashadds = hashadds + 2 * i + 1;
				hashadds %= _ht.capacity();
			}
		}
		return -1;
	}
	//ɾ��
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
	//���ݺ���
	void CheckCapacity()
	{
		//�������ӣ���ЧԪ�ظ���/��ϣ������
		if (_size * 10 / _ht.capacity() >= 7)
		{
			HashTable<T> Newht(2 * _ht.capacity());
			//��ԭ��ϣ���д��ڵ�Ԫ�ذ��Ƶ��¹�ϣ���У�
			for (int i = 0; i < _ht.capacity(); ++i)
			{
				if (_ht[i]._state == EXIST)
					Newht.Insert(_ht[i]._val);
			}
			_ht.swap(Newht._ht);
			swap(_size, Newht._size);
		}
	}
	//��ϣ����
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