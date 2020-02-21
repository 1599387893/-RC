#if 0
class SortedStack {
public:
	stack<int> s;
	stack<int> sta;
	SortedStack() {
	}

	void push(int val) {
		s.push(val);
	}

	void pop() {
		int temp = s.top();
		while (!s.empty())
		{
			temp = (s.top()<temp ? s.top() : temp);
			sta.push(s.top());
			s.pop();
		}
		while (!sta.empty())
		{
			if (temp == sta.top())
			{
				sta.pop();
				continue;
			}
			s.push(sta.top());
			sta.pop();
		}
	}

	int peek() {
		if (s.empty())
			return -1;
		int temp = s.top();
		while (!s.empty())
		{
			temp = (s.top()<temp ? s.top() : temp);
			sta.push(s.top());
			s.pop();
		}
		while (!sta.empty())
		{
			s.push(sta.top());
			sta.pop();
		}
		return temp;
	}

	bool isEmpty() {
		return s.empty();
	}
};

/**
* Your SortedStack object will be instantiated and called as such:
* SortedStack* obj = new SortedStack();
* obj->push(val);
* obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->isEmpty();
*/
#endif