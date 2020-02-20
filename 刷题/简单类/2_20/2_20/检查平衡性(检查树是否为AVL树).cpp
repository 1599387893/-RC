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
	int TreeHigh(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		if (root->left == nullptr && root->right == nullptr)
			return 1;
		return max(TreeHigh(root->left), TreeHigh(root->right)) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (root == nullptr || (root->left == nullptr && root->right == nullptr))
			return true;
		int left = TreeHigh(root->left);
		int right = TreeHigh(root->right);
		if (abs(left - right) <= 1)
			return (isBalanced(root->left) && isBalanced(root->right));
		else
			return false;
	}
};
#endif

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
	int TreeHigh(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		if (root->left == nullptr && root->right == nullptr)
			return 1;
		return max(TreeHigh(root->left), TreeHigh(root->right)) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (root == nullptr || (root->left == nullptr && root->right == nullptr))
			return true;
		return (abs(TreeHigh(root->left) - TreeHigh(root->right)) <= 1) && (isBalanced(root->left) && isBalanced(root->right));
	}
};
#endif