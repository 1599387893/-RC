//ื๎ะกีป
#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {}

	void push(int x) {
		if (_data.empty() || x <= _minData.top())
			_minData.push(x);

		_data.push(x);
	}

	void pop() {
		if (_data.top() == _minData.top())
			_minData.pop();
		_data.pop();
	}

	int top() {
		return _data.top();
	}

	int getMin() {
		return _minData.top();
	}
	stack<int> _data;
	stack<int> _minData;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/

