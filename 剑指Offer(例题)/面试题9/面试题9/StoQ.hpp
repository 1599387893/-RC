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
	void Push(T data)
	{
		s1.push(data);
	}
	T Pop()
	{
		if (s2.empty() && s1.empty())
			throw new exception("Queue Pop Error :Queue Is Empty()");
		if (s2.empty())
			move();
		int ret = s2.top();
		s2.pop();
		return ret;
	}
	~Queue<T>(){}
};



