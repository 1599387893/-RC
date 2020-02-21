#if 0
class MyQueue {
public:
	stack<int> sta1;
	stack<int> sta2;
	/** Initialize your data structure here. */
	MyQueue() {
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		sta1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int temp = 0;
		while (sta1.empty())
		{
			temp = sta1.top();
			sta2.push(temp);
			sta1.pop();
		}
		int ret = sta2.top(); sta2.pop();
		while (sta2.empty())
		{
			temp = sta2.top();
			sta1.push(temp);
			sta2.pop();
		}
		return ret;
	}

	/** Get the front element. */
	int peek() {
		int ret;
		int temp = 0;
		while (sta1.empty())
		{
			temp = sta1.top();
			sta2.push(temp);
			sta1.pop();
		}
		ret = sta2.top();
		while (sta2.empty())
		{
			temp = sta2.top();
			sta1.push(temp);
			sta2.pop();
		}
		return ret;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return sta1.empty();
	}
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->empty();
*/
#endif

#include<queue>
#include<stack>
using namespace std;
int main()
{
	stack<int> sta1;
	stack<int> sta2;
	sta1.push(1);
	sta1.push(2);
	sta1.push(3);
	sta1.push(4);
	sta2.push(sta1.top()); sta1.pop();
	sta2.push(sta1.top()); sta1.pop();
	sta2.push(sta1.top()); sta1.pop();
	return 0;
}