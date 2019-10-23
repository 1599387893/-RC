#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> s1;
	stack<int> min;
	MinStack() {
	}

	void push(int x) {
		s1.push(x);
		if (min.empty() || x <= min.top())
			min.push(x);
	}

	void pop() {
		s1.pop();
		if (s1.top() == min.top())
			min.pop();
	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return min.top();
	}
}; 

int main()
{
	MinStack* minStack = new MinStack();
	minStack->push(-2);
	minStack->push(0);
	minStack->push(-3);
	cout<<minStack->getMin()<<endl;
	minStack->pop();
	minStack->pop();
	cout << minStack->getMin() << endl;

	system("pause");
	return 0;
}