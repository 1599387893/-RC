#if 0
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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
	}

	//优化：利用max_element()函数找到指向最大值的迭代器
	
	int Max(vector<int>& nums, int& left, int& right)
	{
		//找出规定范围内最大值的下标
		int max = left;
		for (int i = left + 1; i <= right; ++i)
			if (nums[max] < nums[i])
				max = i;
		return max;
	}
	TreeNode* constructMaximumBinaryTree(vector<int>& nums, int left, int right)
	{
		if (left > right)
			return nullptr;
		if (left == right)
			return new TreeNode(nums[left]);
		int max = Max(nums, left, right);
		TreeNode* root = new TreeNode(nums[max]);
		root->left = constructMaximumBinaryTree(nums, left, max - 1);
		root->right = constructMaximumBinaryTree(nums, max + 1, right);
		return root;
	}
};
#endif

//方法二：顺序遍历数组
/*
遍历一次数组并随时将新的节点插入树的相应位置，
如果当前遍历的值大于树的根节点，则将当前节点作为新的根节点，将原来的树当作新根节点的左子树，
否则的话，将其递归的交给根节点的右子树处理（因为从左向右遍历，新的节点一定在右边）。
*/

#if 0
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
	TreeNode* BuildTree(TreeNode* root, int val)
	{
		TreeNode* New = new TreeNode(val);
		if (root == nullptr)
			return New;

		//当前值大于当前树根节点的值
		if (val > root->val)
		{
			New->left = root;
			return New;
		}
		//当前值小于当前树根节点的值
		else
		{
			root->right = BuildTree(root->right, val);
			return root;
		}
	}
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.size() == 0)
			return nullptr;
		TreeNode* root = nullptr;
		for (int i = 0; i < nums.size(); ++i)
			root = BuildTree(root, nums[i]);
		return root;
	}
};
#endif