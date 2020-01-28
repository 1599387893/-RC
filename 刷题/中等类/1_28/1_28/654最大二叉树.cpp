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

	//�Ż�������max_element()�����ҵ�ָ�����ֵ�ĵ�����
	
	int Max(vector<int>& nums, int& left, int& right)
	{
		//�ҳ��涨��Χ�����ֵ���±�
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

//��������˳���������
/*
����һ�����鲢��ʱ���µĽڵ����������Ӧλ�ã�
�����ǰ������ֵ�������ĸ��ڵ㣬�򽫵�ǰ�ڵ���Ϊ�µĸ��ڵ㣬��ԭ�����������¸��ڵ����������
����Ļ�������ݹ�Ľ������ڵ��������������Ϊ�������ұ������µĽڵ�һ�����ұߣ���
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

		//��ǰֵ���ڵ�ǰ�����ڵ��ֵ
		if (val > root->val)
		{
			New->left = root;
			return New;
		}
		//��ǰֵС�ڵ�ǰ�����ڵ��ֵ
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