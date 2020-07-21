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
	vector<string> res;
	void FindWay(TreeNode* root, string s)
	{
		if (!root->left && !root->right)
		{
			if (s.size() != 0) s += "->";
			s += to_string(root->val);
			res.push_back(s);
			return;
		}
		if (s.size() != 0) s += "->";
		s += to_string(root->val);
		if (root->left) FindWay(root->left, s);
		if (root->right) FindWay(root->right, s);
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		if (!root) return res;
		string s = "";
		FindWay(root, s);
		return res;
	}
};