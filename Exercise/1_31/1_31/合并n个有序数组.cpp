#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
	int val;
	int col;
	int row;
	Node(int _val, int _row, int _col) 
		:val(_val)
		,row(_row)
		,col(_col)
	{}
};

//���µ���
void Adjust1(vector<int>& heap, int parent)
{
	size_t child = parent * 2 + 1;
	while (child<heap.size())
	{
		if (child + 1 < heap.size() && heap[child + 1] < heap[child])
			child++;
		if (heap[child] < heap[parent])
			swap(heap[child], heap[parent]);
		parent = child;
		child = parent * 2+1;
	}
}
void Adjust2(vector<Node*>& heap, int parent)
{
	size_t child = parent * 2 + 1;
	while (child < heap.size())
	{
		if (child + 1 < heap.size() && heap[child + 1]->val < heap[child]->val)
			child++;
		if (heap[child]->val < heap[parent]->val)
			swap(heap[child], heap[parent]);
		parent = child;
		child = parent * 2 + 1;
	}
}
void Heap_Sort(vector<int>& heap)
{
	int parent = heap.size() / 2-1;
	for (int i = parent; i >= 0; --i)
		Adjust1(heap, parent);
}
void Heap_Sort(vector<Node*>& heap)
{
	int parent = heap.size() / 2 - 1;
	for (int i = parent; i >= 0; --i)
		Adjust2(heap, parent);
}
vector<int> MergeArrays(vector<vector<int>>& arrs)
{
	vector<int> res;
	int count = 0;
	vector<Node*> heap;//����Ҳ����ʹ�����ȼ����л���set������Ҫ����Ĺ��̣�
	for (size_t i = 0; i < arrs.size(); ++i)
	{
		heap.push_back(new Node(arrs[i][0],i,0));
		count += arrs[i].size(); //����ȷ�����յ�ѭ������
	}
	//�Ƚ�����Ԫ������
	Heap_Sort(heap);
	while (count--)
	{
		//���Ѷ�Ԫ��(��Сֵ)���뵽���������
		res.push_back(heap[0]->val);
		//�ж϶Ѷ�Ԫ���ǲ�������������һ��Ԫ��
		if (heap[0]->col == arrs[heap[0]->row].size() - 1)
		{
			heap[0]->val = INT_MAX;//���Ѷ�Ԫ���滻�����ֵ��
			heap[0]->col = INT_MAX;
			heap[0]->row = INT_MAX;
		}
		else
		{
			heap[0]->val = arrs[heap[0]->row][heap[0]->col + 1];
			heap[0]->row = heap[0]->row;
			heap[0]->col = heap[0]->col + 1;
		}
		Adjust2(heap, 0);
	}
	return res;
}
int main()
{
	vector<vector<int>> arrs{ {1,2,7,9}, {5,6}, {3}, {4,8} };
	vector<int> res = MergeArrays(arrs);
	for (auto c : res)
		cout << c << " ";
	cout << endl;
	return 0;
}