//普通方法：没有用到二叉搜索树的性质
class Solution {
public:
	vector<int> nodeValue;
	void GetValue(TreeNode* root)
	{
		if (!root) return;
		nodeValue.push_back(root->val);
		GetValue(root->left);
		GetValue(root->right);
	}
	void UpdateNode(TreeNode* root)
	{
		if (!root) return;
		int Old = root->val;
		int New = 0;
		for (auto n : nodeValue)
			if (n >= Old)
				New += n;
		root->val = New;
		UpdateNode(root->left);
		UpdateNode(root->right);
	}
	TreeNode* bstToGst(TreeNode* root) {
		if (!root || (!root->left && !root->right)) return root;
		GetValue(root);
		sort(nodeValue.begin(), nodeValue.end());
		UpdateNode(root);
		return root;
	}
};

//高效方法：

class Solution {
public:
	int sum;
	void UpdateNode(TreeNode* root)
	{
		if (!root) return;
		if (root->right)
			UpdateNode(root->right);
		sum += root->val;
		root->val = sum;
		if (root->left)
			UpdateNode(root->left);
	}
	TreeNode* bstToGst(TreeNode* root) {
		//从该树的最大元素开始更新，保存跟新结果。
		//遍历方式就是右->根->左的顺序。
		sum = 0;
		UpdateNode(root);
		return root;
	}
};