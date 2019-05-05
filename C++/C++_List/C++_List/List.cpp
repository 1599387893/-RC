#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

//结点结构
template<class T>
struct ListNode
{
	ListNode<T>* _pNext;
	ListNode<T>* _pPre;
	T _data;
	//结点的构造函数
	ListNode(const T& data = T())
		:_pNext(nullptr)
		, _pPre(nullptr)
		, _data(data)
	{}
};
namespace RC
{
	template<class T>
	struct ListIterator
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
		typedef ListIterator<T> Self;

		ListIterator(PNode pNode = nullptr)
			:_pNode(pNode)
		{}
		ListIterator(const Self& s)
			:_pNode(s.pNode)
		{}
		T& operator*()
		{
			return _pNode->_data;
		}
		T* operator->()
		{
			return &(_pNode->_data);
		}
		Self& operator++()
		{
			_pNode = _pNode->_pNext;
			return *this;
		}
		Self operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}
		Self& operator--()
		{
			_pNode = _pNode->_pPre;
			return *this;
		}
		Self operator--(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pPre;
			return temp;
		}
		bool operator!=(const Self& s)const
		{
			return _pNode != s._pNode;
		}
		bool operator==(const Self& s)const
		{
			return _pNode == s._pNode;
		}
	private:
		PNode _pNode;
	};
	
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	
	//43:00
	public:
		list()
		{
			CreateHead();
		}
		list(size_t n, const T& data = T())
		{
			CreateHead();
			for (size_t i = 0; i < n; ++i)
				push_back(data);
		}
		list(T* first, T* last)
		{
			CreateHead();
			while (first != last)
				push_back(*first++);
		}
		//  ?
		list(const list<T>& l)
		{
			CreateHead();
			PNode pCur = l._pHead->_pNext;
			while (pCur != l._pHead)
			{
				push_back(pCur->_data);
				pCur = pCur->_pNext;
			}
		}
		list<T>& operator=(const list<T>& l)
		{
			if (this != &l)
			{
				CreateHead();
				PNode ptr = l._pHead->_pNext;
				while (ptr != l._pHead)
				{
					push_back(ptr->_data);
					ptr = ptr->_pNext;
				}
			}
			return *this;
		}
		
		~list()
		{
			clear(); 
			delete _pHead;
			_pHead = nullptr;
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////
		//iterator
		/*iterator begin()
		{
			return iterator(_pHead->_pNext);
		}
		iterator end()
		{
			return iterator(_pHead);
		}
		//iterator rbegin(); 
		//iterator rend();*/
		/////////////////////////////////////////////////////////////////////////////////////////////////
		//capacity
		size_t size()const
		{
			size_t  count = 0;
			PNode ptr = _pHead->_pNext;
			while (ptr != _pHead)
			{
				count++;
				ptr = ptr->_pNext;
			}
			return count;
		}
		bool empty()const
		{
			return _pHead->_pNext == _pHead;
		}
		void resize(size_t newSize, const T& data = T())
		{
			size_t oldSize = size();
			if (oldSize < newSize)
			{
				for (size_t i = oldSize; i < newSize; ++i)
					push_back(data);
			}
			else
				for (size_t i = oldSize; i > newSize; --i)
					pop_back();
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////
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
		/////////////////////////////////////////////////////////////////////////////////////////////////
		//modifites
		void push_back(const T& data)
		{
			PNode pNewNode = new Node(data);
			pNewNode->_pNext = _pHead;
			pNewNode->_pPre = _pHead->_pPre;
			_pHead->_pPre->_pNext = pNewNode;
			_pHead->_pPre = pNewNode;
		}
		void pop_back()
		{
			PNode ptr = _pHead->_pPre;
			_pHead->_pPre->_pPre->_pNext = _pHead;
			_pHead->_pPre = _pHead->_pPre->_pPre;
			//_pHead->_pPre = ptr->_pPre;
			//ptr->_pPre->_pNext = _pHead;
			delete ptr;
			ptr = nullptr;
		}
		void push_front(const T& data)
		{
			PNode pNewNode = new Node(data);
			pNewNode->_pNext = _pHead->_pNext;
			pNewNode->_pPre = _pHead;
			_pHead->_pNext = pNewNode;
			pNewNode->_pNext->_pPre = pNewNode;
		}
		void pop_front()
		{
			PNode pDelNode = _pHead->_pNext;
			_pHead->_pNext = _pHead->_pNext->_pNext;
			pDelNode->_pNext->_pPre = _pHead;
			delete pDelNode;
			pDelNode = nullptr;
		}
		void Swap(list<T>& l)
		{
			swap(_pHead, l._pHead);
		}
		void clear()
		{
			PNode ptr = _pHead->_pNext;
			while (ptr != _pHead)
			{
				_pHead->_pNext = ptr->_pNext;
				delete ptr;
				ptr = _pHead->_pNext;
			}
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
		//iterator insert(iterator position, const T& x);//01:45:50
		//iterator erase(iterator pos);//01:53:58
		/////////////////////////////////////////////////////////////////////////////////////////////////
		void PrintList()
		{
			PNode ptr = _pHead->_pNext;
			while (ptr != _pHead)
			{
				cout << ptr->_data << " ";
				ptr = ptr->_pNext;
			}
			cout << endl;
		}
	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
	private:
		PNode _pHead;
	};
}

void testList()
{
	RC::list<int> l1;
	l1.PrintList();

	RC::list<int> l2(5, 1);
	l2.PrintList();

	int array[] = { 1, 2, 3 };
	RC::list<int> l3(array,array+sizeof(array)/sizeof(array[0]));
	l3.PrintList();

	RC::list<int> l4(l2);
	l4.PrintList();
	
	l1 = l3;
	l1.PrintList();

}
void test_capacity()
{
	int array[] = { 1, 2, 3 ,4};
	RC::list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	cout<<l.size()<<endl;
	cout << l.empty() << endl;
	l.resize(2);
	l.PrintList();
	l.resize(6);
	l.PrintList();
}
void test_modifiers()
{
	int array[] = { 1, 2, 3 };
	RC::list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	l.PrintList();

	l.push_back(4);
	l.PrintList();
	
	l.pop_back();
	l.PrintList();

	l.push_front(0);
	l.PrintList();

	l.pop_front();
	l.PrintList();

	l.clear();
	l.PrintList();

	RC::list<int> l1(5, 1);
	l.Swap(l1);
	l.PrintList();
	l1.PrintList();
}
void test_access()
{
	int array[] = { 1, 2, 3 };
	RC::list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	l.PrintList();

	cout << l.front() << endl;
	cout << l.back() << endl;
}
int main()
{
	//testList();
	//test_capacity();
	//test_modifiers();
	//test_access();

	return 0;
}