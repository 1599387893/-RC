#include<iostream>
#include<deque>
using namespace std;

template<class T, class Con = deque<T>>
class stack
{
public:
	stack(){}
	void push(const T& data)
	{
		_c.push_back(data);
	}
	void pop()
	{
		_c.pop_back();
	}
	T& top()
	{
		return _c.back();
	}
	const T& top()const
	{
		return _c.back();
	}
	size_t size()const
	{
		return _c.size();
	}
	bool empty()const
	{
		return _c.empty();
	}
private:
	Con _c;
};

void Teststack()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	cout << s.size() << endl;
	cout << s.top() << endl;
	cout << s.empty() << endl;
	s.pop();
	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;
}

int main()
{
	Teststack();

	return 0;
}