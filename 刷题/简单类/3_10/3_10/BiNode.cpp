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
	TreeNode* prev;
	void Inorder(TreeNode* root)
	{
		if (root)
		{
			Inorder(root->left);
			prev->right = root;
			root->left = nullptr;
			prev = prev->right;
			Inorder(root->right);
		}
	}
	TreeNode* convertBiNode(TreeNode* root) {
		if (root == nullptr || (root->left == nullptr && root->right == nullptr))
			return root;
		prev = new TreeNode(0);
		TreeNode* head = prev;
		Inorder(root);
		return head->right;
	}
};
#endif

//·ÇµÝ¹é
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
	TreeNode* convertBiNode(TreeNode* root) {
		if (root == nullptr)
			return root;
		stack<TreeNode*> mySta;
		while (root)
		{
			mySta.push(root);
			root = root->right;
		}
		TreeNode* head = mySta.top();
		while (!mySta.empty())
		{
			TreeNode* leftNode = mySta.top();
			mySta.pop();
			TreeNode* node = leftNode->right;
			while (node)
			{
				mySta.push(node);
				node = node->left;
			}
			leftNode->left = nullptr;
			leftNode->right = mySta.empty() ? nullptr : mySta.top();
		}
		return head;
	}
};
#endif