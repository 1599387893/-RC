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
void PreOrder(struct TreeNode* root, int* array, int* index)
{
	if (root == NULL)
		return;
	array[*index] = root->val;
	(*index)++;
	PreOrder(root->left, array, index);
	PreOrder(root->right, array, index);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	//����ڵ����
	int index = GetNodeCount(root);
	*returnSize = index;
	//�����������ռ�
	int* array = (int*)malloc(sizeof(int)* index);
	if (NULL == array)
		return NULL;
	//ǰ�����
	index = 0;
	PreOrder(root, array, &index);
	return array;
}