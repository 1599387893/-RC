//class CQueue {
//public:
//	stack<int> s1;
//	stack<int> s2;
//	CQueue() {
//	}
//
//	void appendTail(int value) {
//		s1.push(value);
//	}
//
//	int deleteHead() {
//		if (s1.empty() && s2.empty())
//			return -1;
//		int ret = 0;
//		if (!s2.empty())
//		{
//			ret = s2.top();
//			s2.pop();
//			return ret;
//		}
//		while (!s1.empty())
//		{
//			s2.push(s1.top());
//			s1.pop();
//		}
//		ret = s2.top();
//		s2.pop();
//		return ret;
//
//	}
//};
//
///**
//* Your CQueue object will be instantiated and called as such:
//* CQueue* obj = new CQueue();
//* obj->appendTail(value);
//* int param_2 = obj->deleteHead();
//*/