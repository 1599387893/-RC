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
	int sumEvenGrandparent(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int ret = 0;
		if (root->val % 2 == 0)
		{
			if (root->left != nullptr)
			{
				if (root->left->left != nullptr)
					ret += root->left->left->val;
				if (root->left->right != nullptr)
					ret += root->left->right->val;
			}
			if (root->right != nullptr)
			{
				if (root->right->left != nullptr)
					ret += root->right->left->val;
				if (root->right->right != nullptr)
					ret += root->right->right->val;
			}
		}
		return (ret + sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right));
	}
};
#endif