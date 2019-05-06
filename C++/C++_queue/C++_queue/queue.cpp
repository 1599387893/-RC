#include<iostream>
#include<deque>
using namespace std;

template<class T,class Con = deque<T>>
class queue
{
public:
	queue(){}
	void push(const T& data)
	{
		_c.push_back(data);
	}
	void pop()
	{
		_c.pop_front();
	}
	bool empty()
	{
		return _c.empty();
	}
	size_t size()const
	{
		return _c.size();
	}
	T& front()
	{
		return _c.front();
	}
	const T& front()const
	{
		return _c.front();
	}
	T& back()
	{
		return _c.back();
	}
	const T& back()const
	{
		return _c.back();
	}

private:
	Con _c;
};

//测试由deque实现的queue
void TestQueue()
{
	queue<int> q;
	q.push(0);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << q.size() << endl;
	cout << q.front() << endl;
	cout << q.back() << endl;

	q.pop();
	q.pop();
	cout << q.size() << endl;
	cout << q.front() << endl; 
	cout << q.back() << endl;
}

int main()
{
	TestQueue();

	return 0;
}