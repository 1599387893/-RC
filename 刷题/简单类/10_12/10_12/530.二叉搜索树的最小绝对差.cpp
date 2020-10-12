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
	void Inorder(TreeNode* root, vector<int>& temp)
	{
		if (root)
		{
			temp.push_back(root->val);
			Inorder(root->left, temp);
			Inorder(root->right, temp);
		}
	}
	int getMinimumDifference(TreeNode* root) {
		vector<int> temp;
		Inorder(root, temp);
		sort(temp.begin(), temp.end());
		int gap = INT_MAX;
		for (int i = 1; i < temp.size(); ++i)
			gap = min(gap, temp[i] - temp[i - 1]);
		return gap;
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
	int gap;
	int pre;
	void Inorder(TreeNode* root)
	{
		if (root)
		{
			Inorder(root->left);
			if (pre != -1)
				gap = min(gap, root->val - pre);
			pre = root->val;
			Inorder(root->right);
		}
	}
	int getMinimumDifference(TreeNode* root) {
		gap = INT_MAX;
		pre = -1;
		Inorder(root);
		return gap;
	}
};

#endif
