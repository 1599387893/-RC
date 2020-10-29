#if 0
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	unordered_map<TreeNode*, int> f, g; //f：表示选择该节点， g：表示不选择该节点
	void dfs(TreeNode* root)
	{
		if (!root) return;
		dfs(root->left);
		dfs(root->right);
		f[root] = root->val + g[root->left] + g[root->right];
		g[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right]);
	}
	int rob(TreeNode* root) {
		if (!root) return 0;
		dfs(root);
		return max(f[root], g[root]);
	}
};

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	pair<int, int> dfs(TreeNode* root)
	{
		if (!root) return pair<int, int>{};
		auto left = dfs(root->left);
		auto right = dfs(root->right);
		pair<int, int> temp;
		temp.second = root->val + left.first + right.first;
		temp.first = max(left.first, left.second) + max(right.first, right.second);
		return temp;
	}
	int rob(TreeNode* root) {
		if (!root) return 0;
		auto ret = dfs(root);
		return max(ret.first, ret.second);
	}
};
#endif