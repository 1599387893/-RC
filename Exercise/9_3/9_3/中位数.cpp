#if 0
class MedianFinder {
public:
	/** initialize your data structure here. */
	priority_queue<int> maxHeap;  //大根堆(保存小数)
	priority_queue<int, vector<int>, greater<int>> minHeap;  //小根堆(保存大数)
	int size;
	MedianFinder() {
		size = 0;
	}

	void addNum(int num) {
		size++;
		maxHeap.push(num);
		minHeap.push(maxHeap.top());
		maxHeap.pop();

		if (maxHeap.size() < minHeap.size())
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}

	double findMedian() {
		if (size == 0) return 0;
		if (size % 2)
			return (double)maxHeap.top();
		return (maxHeap.top() + minHeap.top()) / 2.0;
	}
};



/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder* obj = new MedianFinder();
* obj->addNum(num);
* double param_2 = obj->findMedian();
*/
#endif



#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

#if 0
int main()
{
	vector<int> arr{ 9, 5, 1, 0, 7, 3, 4, 6, 2, 8 };
	priority_queue<int> pq; //大根堆
	int n = arr.size() % 2 ? arr.size() / 2 : arr.size() / 2 + 1;
	for (int i = 0; i < n; ++i)
		pq.push(arr[i]);
	for (int i = n; i < arr.size(); ++i)
	{
		if (arr[i] < pq.top())
		{
			pq.pop();
			pq.push(arr[i]);
		}
	}
	int res = pq.top();
	if (arr.size() % 2 == 0)
	{
		pq.pop();
		res += pq.top();
	}
	cout << res << endl;
	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	int a = 0;
	cin >> a;
	int res = 0;
	while (a)
	{
		//a - 1 ; 该数字二进制位上最右边的1变成0，这个1后边的所有0都变成了1
		//a & (a - 1)：最后一个1之前的所有1都没有变化，只有最后一个1变成了0
		a = a&(a - 1);
		res++;
	}
	cout << res << endl;
	return 0;
}
#endif