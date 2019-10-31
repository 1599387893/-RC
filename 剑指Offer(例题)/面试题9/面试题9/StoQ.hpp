//面试题9：用两个栈实现队列

//解题思路：用栈1作为接收栈，用栈2作为弹出栈

#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

template<class T>
class Queue
{
private:
	stack<T> s1;
	stack<T> s2;
private:
	void move()
	{
		if (!s2.empty())
			return;
		int s = s1.size();
		for (int i = 0; i < s; ++i)
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
public:
	Queue<T>()
	{}
	bool Empty()
	{
		return s1.empty() && s2.empty();
	}
	size_t size()
	{
		return s1.size() + s2.size();
	}
	//T& Front()
	//{
	//	if (Empty())
	//		throw ( "Expression:deque iterator not dereferencable!");
	//	if (s2.empty())
	//		move();
	//	return s2.top();
	//}
	//T& Back()
	//{
	//	if (Empty())
	//		throw("Expression:deque iterator not dereferencable!");
	//	if (s1.empty())
	//		return s2.top();
	//	return s1.top();
	//}


	//T& Front()
	//{
	//	if (Empty())
	//		throw new exception("Expression:deque iterator not dereferencable!");
	//	move();
	//	if (s2.empty())
	//		return s1.top();
	//	return s2.top();
	//}
	//T& Back()
	//{
	//	if (Empty())
	//		throw new exception("Expression:deque iterator not dereferencable!");
	//	return s1.top();
	//}
	void Push(T data)
	{
		s1.push(data);
	}
	T& Pop()
	{
		if(Empty())
			throw("Expression:deque empty before pop!");
		move();
		int ret;
		if(s2.empty())
			ret = s2.top();
		else 
			ret = s1.pop();
		return ret;
	}
	~Queue<T>(){}
};

