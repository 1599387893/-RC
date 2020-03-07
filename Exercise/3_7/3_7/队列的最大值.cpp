class MaxQueue {
public:
	queue<int> q;
	queue<int> max;
	MaxQueue() {

	}

	int max_value() {
		if (max.size() == 0)
			return -1;
		return max.back();
	}

	void push_back(int value) {
		q.push(value);
		if (max.size() == 0 || value > max.back())
			max.push(value);
		else
			max.push(max.back());
	}

	int pop_front() {
		if (q.size() == 0)
			return -1;
		int ret = q.front();
		q.pop();
		max.pop();
		return ret;
	}
};

/**
* Your MaxQueue object will be instantiated and called as such:
* MaxQueue* obj = new MaxQueue();
* int param_1 = obj->max_value();
* obj->push_back(value);
* int param_3 = obj->pop_front();
*/