//������9��չ������������ʵ��һ��ջ

//����˼·�����ǿն����е�Ԫ��ת�Ƶ��ն��У�ֻ�����һ��Ԫ����Ϊ����ջ��Ԫ��;
//			Ҫ��֤������ʱ��������һ������Ϊ�ա�

#include<iostream>
#include<queue>
using namespace std;

template<class T>
class Stack
{
private:
	queue<T> q1;
	queue<T> q2;
private:
	void move()
	{
		if (q1.empty())
		{
			int s = q2.size();
			for (int i = 1; i < s; ++i)
			{
				q1.push(q2.front());
				q2.pop();
			}
		}
		else
		{
			int s = q1.size();
			for (int i = 1; i < s; ++i)
			{
				q2.push(q1.front());
				q1.pop();
			}
		}
	}
public:
	Stack<T>(){}
	bool Empty()
	{
		return q1.empty() && q2.empty();
	}
	size_t size()
	{
		return q1.size() + q2.size();
	}
	void Push(T data)
	{
		if (q1.empty())
			q2.push(data);
		else
			q1.push(data);
	}
	void  Pop()
	{
		if (Empty())
			throw new exception("Stack Pop Error��Stack Is Empty!");
		if (q1.empty())
		{
			move();
			q2.pop();
		}
		else
		{
			move();
			q1.pop();
		}
	}
	T Top()
	{
		if (Empty())
			throw new exception("Stack Top Error: Stack Is Empty!");
		if (q1.empty())
			return q2.back();
		else
			return q1.back();
	}
	~Stack<T>(){}
};
