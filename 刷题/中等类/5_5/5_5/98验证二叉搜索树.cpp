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
	vector<int> arr;
	void preorder(TreeNode* root)
	{
		if (root)
		{
			preorder(root->left);
			arr.push_back(root->val);
			preorder(root->right);
		}
	}
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		if (!root->left && !root->right) return true;
		//二叉搜索树中序遍历为升序序列
		preorder(root);
		for (int i = 0; i < arr.size() - 1; ++i)
			if (arr[i] >= arr[i + 1])
				return false;
		return true;

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
	bool isValidBST(TreeNode* root, long  lower, long upper)
	{
		if (!root) return true;
		if (root->val <= lower || root->val >= upper) return false;
		return isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
	}
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		if (!root->left && !root->right) return true;
		//二叉搜索树中序遍历为升序序列
		return isValidBST(root, LONG_MIN, LONG_MAX);
	}
};