//#include<iostream>
//#include<cstring>
//using namespace std;
//
//void Print(int* array, int size)
//{
//	for (int i = 0; i < size; i++)
//		cout << array[i]<<" ";
//	cout << endl;
//}
//void MergeData(int* array, int left, int mid, int right, int* temp)
//{
//	int begin1 = left;
//	int end1 = mid;
//	int begin2 = mid;
//	int end2 = right;
//	int index = left;
//
//	while (begin1 < end1 && begin2 < end2)
//	{
//		if (array[begin1] < array[begin2])
//			temp[index++] = array[begin1++];
//		else
//			temp[index++] = array[begin2++];
//	}
//	while (begin1 < end1)
//		temp[index++] = array[begin1++];
//	while (begin2 < end2)
//		temp[index++] = array[begin2++];
//
//}
//void MergeSortNor(int* array, int size)
//{
//	int* temp = new int[10];
//	//int* temp = (int*)malloc(sizeof(int)* 10);
//	int gap = 1;
//
//	while (gap < size)
//	{
//		for (int i = 0; i < size; i += gap * 2)
//		{
//			int left = i;
//			int mid = left + gap;
//			int right = mid + gap;
//
//			if (mid > size)
//				mid = size;
//			if (right > size)
//				right = size;
//			MergeData(array, left, mid, right, temp);
//		}
//		memcpy(array, temp, sizeof(int)* 10);
//		gap *= 2;
//	}
//	/*free(temp);
//	temp = nullptr;*/
//	delete[] temp;
//}
//int main()
//{
//	int* array = new int[10]{0, 2, 5, 1, 9, 6, 3, 7, 4, 8};
//	//int array[10] = { 0, 2, 5, 1, 9, 6, 3, 7, 4, 8 };
//	int size = 10;
//	Print(array, size);
//	MergeSortNor(array, size);
//
//
//	delete[] array;
//	return 0;
//}


#include<iostream>
using namespace std;

//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _data;
//	
//	void* operator new(size_t n)
//	{
//		void* p = nullptr; 
//		p = allocator<ListNode>().allocate(1);
//		cout << "memory pool allocator" << endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//	}
//};
//
//class List
//{
//public:
//	List()
//	{
//		_head = new ListNode;
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//	~List()
//	{
//		ListNode* cur = _head->_next;
//		while (cur != _head)
//		{
//			ListNode* next = cur->_next;
//			delete cur;
//			cur = next;
//		}
//		delete _head;
//		_head = nullptr;
//	}
//private:
//	ListNode* _head;
//};
//
//int main()
//{
//	List l;
//
//	return 0;
//}


//class Test
//{
//public:
//	Test() :_data(0)
//	{
//		cout << "Test()" << this << endl;
//	}
//	~Test()
//	{
//		cout << "~Test()" << this << endl;
//	}
//private:
//	int _data;
//};
//
//void TestFun()
//{
//	Test* pt = (Test*)malloc(sizeof(Test));
//	new(pt) Test;
//}



////创建一个类，使其只能在对上使用空间
//class HeapOnly
//{
//
//public:
//	static HeapOnly* CreateOject()
//	{
//		return	new HeapOnly();
//	}
//private:
//	HeapOnly(){}
//
//	HeapOnly(const HeapOnly&);
//	HeapOnly(const HeapOnly&) = delete;
//};



//创建一个类，使其只能在只能在栈上申请空间
//class StackOnly
//{
//public:
//	static StackOnly CreateObject()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly();
//};
//
//
//int main()
//{
//	
//}

//单例模式
//1.饿汉模式
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	Singleton(){};
	Singleton(const Singleton&) = delete;
	Singleton& operator=(Singleton const &) = delete;

	static Singleton m_instance;
};

Singleton Singleton::m_instance;