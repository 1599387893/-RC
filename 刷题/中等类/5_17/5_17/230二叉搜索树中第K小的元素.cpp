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
	int n;
	int res;
	void InOrder(TreeNode* root, const int k)
	{
		if (root)
		{
			InOrder(root->left, k);
			n++;
			if (n == k)
			{
				res = root->val;
				return;
			}
			InOrder(root->right, k);
		}
	}
	int kthSmallest(TreeNode* root, int k) {
		n = 0;
		//ÖÐÐò±éÀú
		InOrder(root, k);
		return res;
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
	vector<int> arr;
	void InOrder(TreeNode* root)
	{
		if (root)
		{
			InOrder(root->left);
			arr.push_back(root->val);
			InOrder(root->right);
		}
	}
	int kthSmallest(TreeNode* root, int k) {
		InOrder(root);
		return arr[k - 1];
	}
};