#if 0
class MinStack {

public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		s.push(x);
		if (temp.empty())
			temp.push(x);
		else
		{
			if (x < temp.top())
				temp.push(x);
			else
			{
				int n = temp.top();
				temp.push(n);
			}
		}
	}

	void pop() {
		temp.pop();
		s.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return temp.top();
	}
private:
	stack<int> s;
	stack<int> temp;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/
#endif