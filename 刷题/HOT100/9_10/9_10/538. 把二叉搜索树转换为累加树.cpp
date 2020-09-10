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
	int pre;
	TreeNode* convertBST(TreeNode* root) {
		pre = 0;
		return ConvertBST(root);
	}
	TreeNode* ConvertBST(TreeNode* root)
	{
		if (!root)
			return root;
		ConvertBST(root->right);
		root->val += pre;
		pre = root->val;
		ConvertBST(root->left);
		return root;
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
	TreeNode* convertBST(TreeNode* root) {
		if (!root || (!root->left && !root->right)) return root;
		int temp = 0;
		TreeNode* node = root;
		stack<TreeNode*> sta;
		while (!sta.empty() || node)
		{
			while (node)
			{
				sta.push(node);
				node = node->right;
			}
			node = sta.top();
			node->val += temp;
			temp = node->val;
			sta.pop();
			node = node->left;
		}
		return root;
	}
};
#endif