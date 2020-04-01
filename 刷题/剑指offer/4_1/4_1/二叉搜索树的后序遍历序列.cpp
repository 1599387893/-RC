class Solution {
public:
#define MAX_INT 216474000;
	bool verifyPostorder(vector<int>& postorder) {
		stack<int> sta;
		int root = MAX_INT;
		for (int i = postorder.size() - 1; i >= 0; --i)
		{
			if (postorder[i] > root)
				return false;
			while (!sta.empty() && sta.top() > postorder[i])
			{
				root = sta.top();
				sta.pop();
			}
			sta.push(postorder[i]);
		}
		return true;
	}
};

class Solution {
public:
	bool Judge(vector<int>& postorder, int begin, int end)
	{
		if (begin >= end)
			return true;
		int root = postorder[end];
		int left = begin;
		for (; left < end && postorder[left] < root; left++);
		//判断现在得出的右子树中元素是否符合都大于根节点这个条件
		for (int i = left; i<end; ++i)
			if (root>postorder[i])
				return false;
		return Judge(postorder, begin, left - 1) && Judge(postorder, left, end - 1);
	}
	bool verifyPostorder(vector<int>& postorder) {
		//利用二叉搜索树的特性；
		//会分为三个部分：左子树区间，右子树区间，根节点区间；
		//1.将区间的最后一个节点作为根节点；
		//2.从左到右找第一个比根节点大的节点(pos)；
		//3.将pos节点之前的作为左子树，pos节点到根节点前为右子树
		if (postorder.size() == 0 || postorder.size() == 1)
			return true;
		return Judge(postorder, 0, postorder.size() - 1);
	}
};