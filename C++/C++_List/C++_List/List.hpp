//#pragma once
//#include<iostream>
//using namespace std;
//
//
////结点结构
//template<class T>
//typedef struct ListNode
//{
//	//结点的构造函数
//	ListNode(const T& data = T())
//		:_pNext(nullptr)
//		, _pPre(nullptr)
//		, _data(data)
//	{}
//	ListNode<T>*  _pNext;
//	ListNode<T>*  _pPre;
//	T _data;
//};
//namespace RC
//{
//	template<class T>
//	class list
//	{
//		typedef ListNode<T> Node;
//		typedef Node* PNode;		//ListNode<T> Node* == PNode;
//
//	public:
//		//构造函数
//		list()
//		{
//			CreatHead();
//		}
//		list(size_t n, const T& data = T())
//		{
//			CreatHead();
//			for (size_t i = 0; i < n; ++i)
//				push_back(data);
//		}
//		list(T* first, T* last)
//		{
//			CreatHead();
//			while (first != last)
//			{
//				push_back(*first);
//				++first;
//			}
//		}
//		list(const list<T>& l)
//		{
//			CreatHead();
//			if (this != &l)
//			{
//				PNode pCur = l._pHead->_pNext;
//				while (pCur != l._pHead)
//				{
//					push_back(pCur->_data);
//					pCur = pCur->_pNext;
//				}
//			}
//			return *this;
//		}
//		list<T> operator=(const list<T>& l)
//		{
//
//		}
//		~list()
//		{
//			clear();//清空链表中的有效结点
//			delete _pHead;
//			_pHead = nullptr;
//		}
//		//capacity
//		size_t size()const
//		{
//			size_t count = 0;
//			PNode pCur = _pHead->_pNext;
//			while (pCur != _pHead)
//			{
//				++count;
//				pCur = pCur->_pNext;
//			}
//			return count;
//		}
//		bool empty()const
//		{
//			return _pHead->_pNext == _pHead;
//		}
//		void resize(size_t newSize, const T& data = T())
//		{
//			size_t oldsize = size();
//			if (oldsize < newsize)
//			{
//				for (size_t i = oldsize; i < newSize; ++i)
//					push_back(data);
//			}
//			else
//			{
//				for (size_t i = newSize; i < oldsize; ++i)
//					pop_back();
//			}
//		}
//		//access
//		T& front()
//		{
//			return _pHead->_pNext->_data;
//		}
//		const T& front()const
//		{
//			return _pHead->_pNext->_data;
//		}
//		T& back()
//		{
//			return _pHead->_pPre->_data;
//		}
//		const T& back()const
//		{
//			return _pHead->_pPre->_data;
//		}
//		//modefty
//		void push_back(const T& data)
//		{
//			PNode temp = new PNode;
//			temp->_data = data;
//			temp->_pNext = _pHead;
//			temp->_pPre = _pHead->_pPre;
//			_pHead->_pPre->_pNext = temp;
//			_pHead->_pPre = temp;
//		}
//		void pop_back()
//		{
//			if (_pHead->_pNext != _pHead)
//			{
//				PNode temp = _pHead->_pPre;
//				_pHead->_pPre = _pHead->_pPre->_pPre;
//				_pHead->_pPre->_pNext = _pHead;
//				delete temp;
//			}
//		}
//		void push_front(const T& data)
//		{
//			PNode NewNode = new PNode;
//			NewNode->_data = data;
//			NewNode->_pNext = _pHead->_pNext;
//			NewNode->_pPre = _pHead;
//			_pHead->_pNext->_pPre = NewNode;
//			_pHead->_pNext = NewNode;
//		}
//		void pop_front()
//		{
//			if (_pHead->_pNext != _pHead)
//			{
//				PNode temp = _pHead->_pNext;
//				_pHead->_pNext = _pHead->_pNext->_pNext;
//				_pHead->_pNext->_pPre = _pHead;
//				delete temp;
//			}
//		}
//	private:
//		void CreatHead()//创建头结点
//		{
//			_pHead = new Node;
//			_pHead->_pNext = _pHead;
//			_pHead->_pPre = _pHead;
//		}
//	private:
//		PNode _pHead;
//	};
//}
//void PrintList(RC::list<int>& l)
//{
//	auto it = l.front();
//	while (it != l.back())
//		cout << *it++ << " ";
//	cout << endl;
//}
//void TestList()
//{
//	RC::list<int> l1;
//	RC::list<int> l2(5, 1);
//	int array[] = { 0, 1, 2, 3, 4, 5, 6 };
//	RC::list<int> l3(array.array + sizeof(array) / sizeof(array[0]));
//	RC::list<int> l4(l3);
//	PrintList(l1);
//	PrintList(l2);
//	PrintList(l3);
//	PrintList(l4);
//	l1 = l3;
//	PrintList(l1);
//
//}
//int main()
//{
//
//
//
//	return 0;
//}