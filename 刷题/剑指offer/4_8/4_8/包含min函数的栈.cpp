#if 0
class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> st;
	stack<int> temp;
	MinStack() {
	}

	void push(int x) {
		st.push(x);
		if (temp.empty() || x <= temp.top())
			temp.push(x);
		else
			temp.push(temp.top());
	}

	void pop() {
		temp.pop();
		st.pop();
	}

	int top() {
		return st.top();
	}

	int min() {
		return temp.top();
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->min();
*/





class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> st;
	stack<int> temp;
	MinStack() {
	}

	void push(int x) {
		st.push(x);
		if (temp.empty() || x <= temp.top())
			temp.push(x);
	}

	void pop() {
		if (st.top() == temp.top())
			temp.pop();
		st.pop();
	}

	int top() {
		return st.top();
	}

	int min() {
		return temp.top();
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->min();
*/
#endif