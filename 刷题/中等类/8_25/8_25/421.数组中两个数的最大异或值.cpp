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
	{//��n��ÿ����λ�ϵ�ֵ���浽ǰ׺����
		//�ȱ����λ��ֵ
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
				if (p->next[!t])// ���t==1��̰�ĵ�ȥ��0���  ������1���
				{
					p = p->next[!t];
					temp += (1 << i);
				}
				else //���t�͵�ǰǰ׺���ڵ��ֵһ����ֱ������һ���ڵ�
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
		//�ȹ���ǰ׺��
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
		//��������,�õ�ÿ��Ԫ����ǰ׺���������Ƚ�,�õ�������ֵ
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