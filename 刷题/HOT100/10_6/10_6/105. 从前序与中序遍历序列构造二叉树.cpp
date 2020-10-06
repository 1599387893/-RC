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
	TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight)
	{
		if (preLeft > preRight || inLeft > inRight)
			return nullptr;
		TreeNode* root = new TreeNode(preorder[preLeft]);
		int pos = inLeft;
		while (inorder[pos] != preorder[preLeft])
			pos++;
		root->left = buildTree(preorder, preLeft + 1, preLeft + (pos - inLeft), inorder, inLeft, pos - 1);
		root->right = buildTree(preorder, preLeft + (pos - inLeft) + 1, preRight, inorder, pos + 1, inRight);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
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
	unordered_map<int, int> um;
	TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight)
	{
		if (preLeft > preRight || inLeft > inRight)
			return nullptr;
		TreeNode* root = new TreeNode(preorder[preLeft]);
		int pos = um[preorder[preLeft]];
		root->left = buildTree(preorder, preLeft + 1, preLeft + (pos - inLeft), inorder, inLeft, pos - 1);
		root->right = buildTree(preorder, preLeft + (pos - inLeft) + 1, preRight, inorder, pos + 1, inRight);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		for (int i = 0; i < inorder.size(); ++i)
			um[inorder[i]] = i;
		return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
};



