#include<iostream>
#include<algorithm>
using namespace std;

namespace RC
{
	template<class T>
	struct ListNode
	{
		ListNode(const T& value = T())
			:_data(value)
			, _pNext(nullptr)
			, _pPre(nullptr)
		{}
		T _data;
		struct ListNode<T>* _pNext;
		struct ListNode<T>* _pPre;
	};

	template<class T>
	class list
	{
	public:
		typedef ListNode<T> Node;
		typedef ListNode<T>* PNode;
		typedef T* iterator;
	public:
		//¹¹Ôìº¯Êý
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
		list(T* start, T* finish)
		{
			CreateHead();
			while (start != finish)
				push_back(*start++);
		}
		list(const list<T>& l)
		{
			CreateHead();
			PNode it = l._head->_pNext;
			while (it != l._head)
			{
				push_back(it->_data);
				it = it->_pNext;
			}
		}
		list& operator=(const list<T>& l)
		{
			if (this != &l)
			{
				clear();
				PNode it = l._head->_pNext;
				while (it != _head)
				{
					push_back(it->_data);
					it = it->_pNext;
				}
			}
			return *this;
		}
		~list()
		{
			if (_head)
			{
				clear();
				delete _head;
				_head = nullptr;
			}
		}
		//iterator 
		PNode begin()
		{
			return _head->_pNext;
		}
		PNode end()
		{
			return _head->_pPre;
		}
		//access
		T& front()
		{
			return _head->_pNext->_data;
		}
		T& back()
		{
			return _head->_pPre->_data;
		}
		//capacity
		size_t size()
		{
			size_t count = 0;
			auto it = _head->_pNext;
			while (it != _head)
			{
				count++;
				it = it->_pNext;
			}
			return count;
		}
		bool empty()
		{
			if (_head->_pNext == _head)
				return true;
			return false;
		}
		void resize(size_t newsize,const T& data = T())
		{
			if (size() < newsize)
				for (int i = newsize - size(); i > 0; --i)
					push_back(data);
			else
				for (int i = size() - newsize; i > 0; --i)
					pop_back();
		}
		//modifiers
		void push_back(const T& data)
		{
			PNode newNode = new Node(data);
			PNode lastNode = _head->_pPre;
			newNode->_pNext = _head;
			newNode->_pPre = lastNode;
			_head->_pPre = newNode;
			lastNode->_pNext = newNode;
		}
		void pop_back()
		{
			PNode lastNode = _head->_pPre;
			_head->_pPre = lastNode->_pPre;
			lastNode->_pPre->_pNext = _head;

			delete lastNode;
			lastNode = nullptr;
		}
		void push_front(const T& data)
		{
			PNode newNode = new Node(data);
			newNode->_pNext = _head->_pNext;
			newNode->_pPre = _head;
			_head->_pNext->_pPre = newNode;
			_head->_pNext = newNode;
		}
		void pop_front()
		{
			PNode firstNode = _head->_pNext;
			_head->_pNext = firstNode->_pNext;
			firstNode->_pPre = _head;

			delete firstNode;
			firstNode = nullptr;
		}
		void Swap(list<T>& l)
		{
			swap(_head, l._head);
		}
		void clear()
		{
			PNode ptr = _head->_pNext;
			while (ptr != _head)
			{
				_head->_pNext = ptr->_pNext;
				delete ptr;
				ptr = nullptr;
				ptr = _head->_pNext;
			}
			_head->_pNext = _head;
			_head->_pPre = _head;
		}
		void PrintList()
		{
			PNode ptr = _head->_pNext;
			while (ptr != _head)
			{
				cout << ptr->_data << " ";
				ptr = ptr->_pNext;
			}
			cout << endl;
		}
	private:
		void CreateHead()
		{
			_head = new Node;
			_head->_pNext = _head;
			_head->_pPre = _head;
		}
	private:
		PNode _head;
	};
}

void TestConstuct()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	RC::list<int> l1;
	RC::list<int> l2(5, 100);
	RC::list<int> l3(arr, arr + 8);
	RC::list<int> l4(l2);
	l1.PrintList();
	l2.PrintList();
	l3.PrintList();
	l4.PrintList();
}

void Testiterator()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	RC::list<int> l(arr, arr + 8);
	l.PrintList();

	cout <<"begin() "<< l.begin()->_data << endl;
	cout << "end()   " << l.end()->_data << endl;
}

void TestAccess()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	RC::list<int> l(arr, arr + 8);
	l.PrintList();

	cout << "begin() " << l.front() << endl;
	cout << "end()   " << l.back() << endl;
}

void TestCapacity()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	RC::list<int> l(arr, arr + 5);
	cout << "size = " << l.size() << endl;
	cout << "empty = " << l.empty() << endl;
	l.PrintList();

	l.resize(10, 1);
	cout << "size = " << l.size() << endl;
	cout << "empty = " << l.empty() << endl;
	l.PrintList();

	l.resize(2);
	cout << "size = " << l.size() << endl;
	cout << "empty = " << l.empty() << endl;
	l.PrintList();

	l.resize(0);
	cout << "size = " << l.size() << endl;
	cout << "empty = " << l.empty() << endl;
	l.PrintList();
}

void TestModifiers()
{
	int arr[] = { 1, 2, 3 };
	RC::list<int> l(arr, arr + 3);

	l.PrintList();
	l.push_front(0);
	l.push_back(4);
	l.PrintList();

	l.pop_back();
	l.pop_front();
	l.PrintList();

	RC::list<int> l1(5, 10);
	l.Swap(l1);
	l.PrintList();

	l.clear();
	l.PrintList();

}

int main()
{
	//TestConstuct();
	//Testiterator();
	//TestAccess();
	//TestCapacity();
	TestModifiers();
	system("pause");
	return 0;
}