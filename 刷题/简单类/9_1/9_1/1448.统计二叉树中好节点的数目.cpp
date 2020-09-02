/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	int res;
	void CountGoodNodes(TreeNode* root, int pathMax)
	{
		if (!root) return;
		if (root->val >= pathMax)
		{
			pathMax = root->val;
			res++;
		}
		CountGoodNodes(root->left, pathMax);
		CountGoodNodes(root->right, pathMax);
	}
	int goodNodes(TreeNode* root) {
		if (!root) return 0;
		if (!root->left && !root->right) return 1;
		//深度优先遍历时，带着当前路径的最大值进入
		res = 0;
		CountGoodNodes(root, INT_MIN);
		return res;
	}
};