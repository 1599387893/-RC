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
	vector<vector<int>> res;
	vector<int> path;
	void findSum(TreeNode* root, int sum)
	{
		if (!root)
			return;
		path.push_back(root->val);
		sum -= root->val;
		if (!root->left && !root->right && !sum) res.push_back(path);
		findSum(root->left, sum);
		findSum(root->right, sum);
		path.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		findSum(root, sum);
		return res;
	}
};
