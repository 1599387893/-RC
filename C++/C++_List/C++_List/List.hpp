#pragma once
#include<iostream>
using namespace std;


//���ṹ
template<class T>
typedef struct ListNode
{
	//���Ĺ��캯��
	ListNode(const T& data = T())
		:_pNext(nullptr)
		, _pPre(nullptr)
		, _data(data)
	{}
	ListNode<T>*  _pNext;
	ListNode<T>*  _pPre;
	T _data;
};
namespace RC
{
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;		//ListNode<T> Node* == PNode;

	public:
		//���캯��
		list()
		{
			CreatHead();
		}
		list(size_t n, const T& data = T())
		{
			CreatHead();
			for (size_t i = 0; i < n; ++i)
				push_back(data);
		}
		list(T* first, T* last)
		{
			CreatHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(const list<T>& l)
		{
			CreatHead();
			if (this != &l)
			{
				PNode pCur = l._pHead->_pNext;
				while (pCur != l._pHead)
				{
					push_back(pCur->_data);
					pCur = pCur->_pNext;
				}
			}
			return *this;
		}
		list<T> operator=(const list<T>& l)
		{

		}
		~list()
		{
			clear();//��������е���Ч���
			delete _pHead;
			_pHead = nullptr;
		}
		//capacity
		size_t size()const
		{
			size_t count = 0;
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				++count;
				pCur = pCur->_pNext;
			}
			return count;
		}
		bool empty()const
		{
			return _pHead->_pNext == _pHead;
		}
		void resize(size_t newSize, const T& data = T())
		{
			size_t oldsize = size();
			if (oldsize < newsize)
			{
				for (size_t i = oldsize; i < newSize; ++i)
					push_back(data);
			}
			else
			{
				for (size_t i = newSize; i < oldsize; ++i)
					pop_back();
			}
		}
		//access
		T& front()
		{
			return _pHead->_pNext->_data;
		}
		const T& front()const
		{
			return _pHead->_pNext->_data;
		}
		T& back()
		{
			return _pHead->_pPre->_data;
		}
		const T& back()const
		{
			return _pHead->_pPre->_data;
		}
		//modefty
		void push_back(const T& data);
		void pop_back();
		void push_front(const T& data);
		void pop_front();
	private:
		void CreatHead()//����ͷ���
		{
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
	private:
		PNode _pHead;
	};
}