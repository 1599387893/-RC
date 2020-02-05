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
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (root == nullptr)
			return new TreeNode(val);
		if (val > root->val)
			root->right = insertIntoBST(root->right, val);
		if (val < root->val)
			root->left = insertIntoBST(root->left, val);
		return root;
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
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (root == nullptr)
			return new TreeNode(val);
		TreeNode* temp = root;
		TreeNode* node = new TreeNode(val);
		while (temp)
		{
			if (temp->val < val)
				if (temp->right == nullptr)
				{
				temp->right = node;
				break;
				}
				else
					temp = temp->right;
			else
				if (temp->left == nullptr)
				{
				temp->left = node;
				break;
				}
				else
					temp = temp->left;
		}
		return  root;
	}
};
#endif
