/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int maxDepth(struct TreeNode* root)
{
	int lD = 0;
	int rD = 0;

	if (root == NULL)
		return 0;

	lD = maxDepth(root->left);
	rD = maxDepth(root->right);

	return (lD > rD ? lD + 1 : rD + 1);
}