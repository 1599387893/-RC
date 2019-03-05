/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int GetNodeCount(struct TreeNode* root)
{
	if (NULL == root)
		return 0;
	return (GetNodeCount(root->left) + GetNodeCount(root->right) + 1);
}
void PostOreder(struct TreeNode* root, int* array, int* index)
{
	if (NULL == root)
		return;
	PostOreder(root->left, array, index);
	PostOreder(root->right, array, index);
	array[*index] = root->val;
	(*index)++;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
	int index = GetNodeCount(root);
	*returnSize = index;
	int* array = (int*)malloc(sizeof(int)* index);
	if (array == NULL)
		return NULL;
	index = 0;
	PostOreder(root, array, &index);
	return array;
}