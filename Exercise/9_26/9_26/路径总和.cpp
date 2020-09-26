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
	void FindWay(TreeNode* root, const int& sum, vector<int> cur, int curSum)
	{
		if (!root) return;
		curSum += root->val;
		cur.push_back(root->val);
		if (sum == curSum)
			if (!root->left && !root->right)
				res.push_back(cur);
		FindWay(root->left, sum, cur, curSum);
		FindWay(root->right, sum, cur, curSum);
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> cur;
		FindWay(root, sum, cur, 0);
		return res;
	}
};