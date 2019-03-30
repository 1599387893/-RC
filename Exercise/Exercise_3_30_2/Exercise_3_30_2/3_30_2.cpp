#include<iostream>
using namespace std;

struct ListNode
{
	ListNode* _next;
	ListNode* _prev;

	void* operator new (size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}
};


class Test
{
public:
	int _data;

	void Display()
	{
		cout << "Display()" << endl;
	}
};
int main()
{
	ListNode l1;
	l1._prev = nullptr;

	Test t;
	t._data = 11;
	return 0;
}