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
	void dfs(TreeNode* root, vector<int>& seq)
	{
		if (!root) return;
		if (!root->left && !root->right)
		{
			seq.push_back(root->val);
			return;
		}
		dfs(root->left, seq);
		dfs(root->right, seq);
	}
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> seq1;
		vector<int> seq2;
		dfs(root1, seq1);
		dfs(root2, seq2);
		if (seq1.size() != seq2.size())
			return false;
		for (int i = 0; i < seq1.size(); ++i)
			if (seq1[i] != seq2[i])
				return false;
		return true;
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
	string dfs(TreeNode* root)
	{
		string res = "";
		if (!root) return res;
		if (!root->left && !root->right)
		{
			res += to_string(root->val) + "."; //加上分隔符，处理71，4 和7，14的情况
			return res;
		}
		res += dfs(root->left);
		res += dfs(root->right);
		return res;
	}
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		if (dfs(root1) == dfs(root2))
			return true;
		return false;
	}
};