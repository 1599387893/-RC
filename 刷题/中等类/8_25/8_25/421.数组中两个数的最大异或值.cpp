struct Node
{
	vector<Node*> next;
	Node()
	{
		next = vector<Node*>(2, nullptr);
	}
};

class Solution {
public:
	void insert(Node* root, int num)
	{//将n上每个数位上的值保存到前缀树中
		//先保存高位的值
		for (int i = 30; i >= 0; --i)
		{
			if (!root->next[num >> i & 1])
				root->next[num >> i & 1] = new Node();
			root = root->next[num >> i & 1];
		}
	}
	int findMaximumXOR(vector<int>& nums) {
		Node* root = new Node();
		for (auto val : nums)
			insert(root, val);
		int res = 0, temp = 0;
		Node* p = root;
		for (auto val : nums)
		{
			p = root;
			temp = 0;
			for (int i = 30; i >= 0; i--)
			{
				int t = (val >> i) & 1;
				if (p->next[!t])// 如果t==1则贪心的去找0异或  否则找1异或
				{
					p = p->next[!t];
					temp += (1 << i);
				}
				else //如果t和当前前缀树节点的值一样，直接找下一个节点
					p = p->next[t];
			}
			res = max(res, temp);
		}
		return res;
	}
};





typedef struct Node
{
	vector<Node*> next;
	Node()
	{
		next = vector<Node*>(2, nullptr);
	}
}Node;

class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		Node* root = new Node();
		//先构建前缀树
		for (auto num : nums)
		{
			Node* cur = root;
			for (int i = 30; i >= 0; --i)
			{
				if (!cur->next[num >> i & 1])
					cur->next[num >> i & 1] = new Node();
				cur = cur->next[num >> i & 1];
			}
		}
		int res = 0;
		//遍历数组,拿到每个元素与前缀树进行异或比较,得到最大异或值
		for (auto num : nums)
		{
			int temp = 0;
			Node* cur = root;
			for (int i = 30; i >= 0; --i)
			{
				int t = num >> i & 1;
				if (cur->next[!t])
				{
					temp += 1 << i;
					cur = cur->next[!t];
				}
				else
					cur = cur->next[t];
			}
			res = max(res, temp);
		}
		return res;
	}
};