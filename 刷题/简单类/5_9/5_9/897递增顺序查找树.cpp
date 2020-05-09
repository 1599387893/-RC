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
	vector<TreeNode*> temp;
	void Inorder(TreeNode* root)
	{
		if (root)
		{
			TreeNode* left = root->left;
			TreeNode* right = root->right;
			root->left = nullptr;
			root->right = nullptr;
			Inorder(left);
			temp.push_back(root);
			Inorder(right);
		}
	}
	TreeNode* increasingBST(TreeNode* root) {
		if (!root || (!root->left && !root->right)) return root;
		Inorder(root);
		root = temp[0];
		TreeNode* pos = root;
		for (int i = 1; i < temp.size(); ++i)
		{
			pos->right = temp[i];
			pos = pos->right;
		}
		return root;
	}
};

//使用中序遍历的特点
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
	TreeNode* pre;
	void Inorder(TreeNode* root)
	{
		if (!root) return;
		Inorder(root->left);
		root->left = nullptr;
		pre->right = root;
		pre = pre->right; //pre = root;
		Inorder(root->right);
	}
	TreeNode* increasingBST(TreeNode* root) {
		if (!root || (!root->left && !root->right)) return root;
		TreeNode* res = new TreeNode(0);
		pre = res;
		Inorder(root);
		return res->right;
	}
};
