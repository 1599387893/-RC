#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool IsUp(vector<int>& temp)
{
	size_t i = 1;
	for (; i<temp.size() && temp[i] == temp[i - 1] + 1; ++i);
	if (i == temp.size())
		return true;
	return false;
}
bool move(vector<int>& heap)
{
	if (count(heap.begin(), heap.end(), 0) == heap.size())
		return false;
	sort(heap.begin(), heap.end());
	if (heap[0] == 0 && IsUp(heap))
		return false;
	if (heap[0] - 1 >= 0)
		heap[0]--;
	else
		for (size_t i = 1; i < heap.size(); ++i)
			if (heap[i] - 1 != heap[i - 1])
				heap[i]--;
	return true;
}
int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n; //石头堆数
		bool step = 1;//起始时度度熊先走；
		vector<int> heap;
		heap.resize(n, 0);
		for (int i = 0; i< n; ++i)
			cin >> heap[i];
		while (move(heap))
			step = !step;
		step ? cout << "woman" << endl : cout << "man" << endl;
	}
	return 0;
}