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
	int level;
	int res;
	void BottomLeftValue(TreeNode* root, int curlevel)
	{
		if (!root) return;
		if (!root->left && !root->right)
		{
			if (level == -1 || curlevel > level)
			{
				level = curlevel;
				res = root->val;
			}
			return;
		}
		BottomLeftValue(root->left, curlevel + 1);
		BottomLeftValue(root->right, curlevel + 1);
	}
	int findBottomLeftValue(TreeNode* root) {
		level = -1;
		res = -1;
		BottomLeftValue(root, 0);
		return res;
	}
};