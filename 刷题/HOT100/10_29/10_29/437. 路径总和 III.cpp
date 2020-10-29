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
	int res;
	void dfs(TreeNode* root, int cur, int sum, bool is_start)
	{
		if (!root) return;
		cur += root->val;
		if (cur == sum)
			res++;
		dfs(root->left, cur, sum, false);
		dfs(root->right, cur, sum, false);
		if (is_start)
		{
			dfs(root->left, 0, sum, true);
			dfs(root->right, 0, sum, true);
		}
	}
	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;
		res = 0;
		dfs(root, 0, sum, true);
		return res;
	}
};


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
	//前缀和+DFS
	unordered_map<int, int> um;
	int sum;
	int dfs(TreeNode* root, int cur)
	{
		if (!root) return 0;
		int res = 0;
		cur += root->val;
		if (um.find(cur - sum) != um.end())
			res += um[cur - sum];
		//处理当前节点
		if (um.find(cur) == um.end())
			um.insert({ cur, 1 });
		else
			um[cur]++;

		if (root->left)
			res += dfs(root->left, cur);
		if (root->right)
			res += dfs(root->right, cur);

		um[cur]--;
		if (um[cur] == 0)
			um.erase(cur);
		return res;
	}
	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;
		um[0] = 1;
		this->sum = sum;
		return dfs(root, 0);
	}
};