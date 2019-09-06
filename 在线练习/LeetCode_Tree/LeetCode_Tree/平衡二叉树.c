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
bool isBalanced(struct TreeNode* root)
{
	if (NULL == root)
		return true;

	if (root->left == NULL && root->right == NULL)
		return true;

	return (abs(maxDepth(root->left) - maxDepth(root->right)) < 2) && isBalanced(root->left) && (isBalanced(root->right));
}