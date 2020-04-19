//使用mulitset
class MedianFinder {
public:
	/** initialize your data structure here. */
	multiset<int> s;
	MedianFinder() {

	}

	void addNum(int num) {
		s.insert(num);
	}

	double findMedian() {
		double res = 0;
		auto it = s.begin();
		for (int i = 0; i < (s.size() - 1) / 2; ++i)
			it++;
		res = *it;
		cout << "Judge befor " << res;
		if (s.size() % 2 == 0)
		{
			it++;
			res += *it;
			res /= 2;
		}
		cout << "Judge after:" << res << endl;
		return res;
	}
};

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder* obj = new MedianFinder();
* obj->addNum(num);
* double param_2 = obj->findMedian();
*/

class MedianFinder {
public:
	/** initialize your data structure here. */
	multiset<int> ms; //保存所有的数据
	multiset<int>::iterator mid;//保存中位数的位置
	MedianFinder() {

	}

	void addNum(int num) {
		ms.insert(num);
		if (ms.size() == 1)
			mid = ms.begin();
		else
		{
			if (*mid > num && ms.size() % 2 == 0)
				mid--;
			else if (*mid <= num && ms.size() % 2 == 1)
				mid++;
		}
	}

	double findMedian() {
		if (ms.empty()) return -1;
		if (ms.size() % 2 == 1) return *mid;
		else
		{
			double res = *(++mid);
			res += *(--mid);
			return res / 2.0;
		}
	}
};
