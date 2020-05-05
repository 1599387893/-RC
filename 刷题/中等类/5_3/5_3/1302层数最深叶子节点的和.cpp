#if 0
//����һ����������ĸ߶ȣ��ٸ��ݸ߶���ֵ(DFS)
class Solution {
public:
	int Level(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		if (root->left == nullptr && root->right == nullptr)
			return 1;
		int left = Level(root->left) + 1;
		int right = Level(root->right) + 1;
		return left > right ? left : right;
	}
	int DeepValue(const int& deep, int now, TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		if (deep == now)
			return root->val;
		else
			return DeepValue(deep, now + 1, root->left) + DeepValue(deep, now + 1, root->right);
	}
	int deepestLeavesSum(TreeNode* root) {
		if (root == nullptr)
			return 0;
		if (root->left == nullptr && root->right == nullptr)
			return root->val;
		int ret = 0;
		//����������Ĳ���
		int Llevel = Level(root->left);
		//����������Ĳ���
		int Rlevel = Level(root->right);
		//�����
		int deep = max(Llevel, Rlevel);
		//�ҳ��������������Ľڵ��ֵ
		ret += DeepValue(deep, 1, root->left);
		//�ҳ��������������Ľڵ��ֵ
		ret += DeepValue(deep, 1, root->right);
		return ret;
	}
};

class Solution {
public:
	int Depth(TreeNode* root)
	{
		if (!root) return 0;
		if (!root->left && !root->right) return 1;
		return 1 + max(Depth(root->left), Depth(root->right));
	}
	int GetDeepVal(TreeNode* root, const int& depth, int n)
	{
		if (root == nullptr) return 0;
		if (n == depth) return root->val;
		return GetDeepVal(root->left, depth, n + 1) + GetDeepVal(root->right, depth, n + 1);
	}
	int deepestLeavesSum(TreeNode* root) {
		if (!root) return 0;
		if (!root->left && !root->right) return root->val;
		int depth = Depth(root);
		return GetDeepVal(root, depth, 1);
	}
};

//�����������������BFS��
class Solution {
public:
	int deepestLeavesSum(TreeNode* root) {
		int res = 0, size = 0;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			res = 0;
			size = q.size();
			for (int i = 0; i < size; ++i)
			{
				res += q.front()->val;
				if (q.front()->left) q.push(q.front()->left);
				if (q.front()->right) q.push(q.front()->right);
				q.pop();
			}
		}
		return res;
	}
};
#endif