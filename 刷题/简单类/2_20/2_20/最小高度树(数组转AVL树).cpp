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
	TreeNode* sortedArrayToBST(vector<int>& nums,int left,int right)
	{
		if(left >= right)
			return nullptr;
		if(left == right)
			return new TreeNode(nums[left]);
		int mid = left+(right-left)/2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBST(nums,left,mid);
		root->right = sortedArrayToBST(nums,mid+1,right);
		return root;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if(nums.size() == 0)
			return nullptr;
		if(nums.size() == 1)
			return new TreeNode(nums[0]);
		return sortedArrayToBST(nums,0,nums.size());
	}
};
#endif

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
	TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right)
	{
		if (left > right)
			return nullptr;
		if (left == right)
			return new TreeNode(nums[left]);
		int mid = left + (right - left) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBST(nums, left, mid - 1);
		root->right = sortedArrayToBST(nums, mid + 1, right);
		return root;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
			return nullptr;
		if (nums.size() == 1)
			return new TreeNode(nums[0]);
		return sortedArrayToBST(nums, 0, nums.size() - 1);
	}
};
#endif