//方法一
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
		return true;

	if (p == NULL || q == NULL)
		return false;

	if (p->val == q->val && p != NULL && q != NULL)
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

	return false;

}
bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
	if (s == NULL && t == NULL)
		return true;

	if (NULL == s || NULL == t)
		return false;

	if ((s->val == t->val) && (isSameTree(s, t)))
		return true;

	return isSubtree(s->left, t) || isSubtree(s->right, t);
}

//方法二
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
		return 1;

	if (p == NULL || q == NULL)
		return 0;

	if (p->val == q->val && p != NULL && q != NULL)
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

	return 0;

}
bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
	int ret = 0;
	if (s == NULL && t == NULL)
		return true;

	if (NULL == s || NULL == t)
		return false;

	if (s->val == t->val)
		ret = isSameTree(s, t);

	if (ret == 1)
		return true;

	return ret || isSubtree(s->left, t) || isSubtree(s->right, t);
}