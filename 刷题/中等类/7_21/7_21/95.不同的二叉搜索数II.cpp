/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
	vector<TreeNode*> generate(int start, int end)
	{
		vector<TreeNode*> res;
		if (start > end)
		{
			res.emplace_back(nullptr);
			return res;
		}
		for (int i = start; i <= end; ++i)
		{
			vector<TreeNode*> left_tree = generate(start, i - 1);
			vector<TreeNode*> right_tree = generate(i + 1, end);
			for (auto& left : left_tree)
			{
				for (auto& right : right_tree)
				{
					TreeNode* root = new TreeNode(i);
					root->left = left;
					root->right = right;
					res.emplace_back(root);
				}
			}
		}
		return res;
	}
	vector<TreeNode*> generateTrees(int n) {
		if (!n) return vector<TreeNode*> {};
		return generate(1, n);
	}
};