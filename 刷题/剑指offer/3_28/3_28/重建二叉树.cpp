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
	TreeNode* buildTree(vector<int>& pre, vector<int>& inorder, int pos, int start, int end)
	{
		if (start > end)
			return nullptr;
		TreeNode* root = new TreeNode(pre[pos]);
		int i = start;
		while (i < end && pre[pos] != inorder[i])
			++i;
		root->left = buildTree(pre, inorder, pos + 1, start, i - 1);
		root->right = buildTree(pre, inorder, pos + 1 + i - start, i + 1, end);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder, inorder, 0, 0, inorder.size() - 1);
	}
};


//方法二
class Solution {
public:
	TreeNode* Build(vector<int>::iterator preBegin, vector<int>::iterator preEnd, vector<int>::iterator inBegin, vector<int>::iterator inEnd)
	{
		if (inEnd == inBegin)   //此时子树区间为0，直接返回空
			return nullptr;
		TreeNode* root = new TreeNode(*preBegin);
		//在中序遍历结果中找到当前的根节点(root)所在的位置
		auto pos = find(inBegin, inEnd, *preBegin);
		root->left = Build(preBegin + 1, preBegin + (pos - inBegin) + 1, inBegin, pos);
		root->right = Build(preBegin + (pos - inBegin) + 1, preEnd, pos + 1, inEnd);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return Build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}
};