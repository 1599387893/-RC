//解法一：将链表转换成数组，将问题变为使用排序数组构建二叉平衡搜索树
#if 0
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> arr;
		ListNode* temp = head;
		while (temp)
		{
			arr.push_back(temp->val);
			temp = temp->next;
		}
		return CreateTree(arr, 0, arr.size() - 1);
	}
	TreeNode* CreateTree(vector<int>& arr, int left, int right)
	{
		if (left>right)
			return  nullptr;
		if (left == right)
			return new TreeNode(arr[left]);
		int mid = left + (right - left) / 2;
		TreeNode* root = new TreeNode(arr[mid]);
		root->left = CreateTree(arr, left, mid - 1);
		root->right = CreateTree(arr, mid + 1, right);
		return root;
	}
};
#endif

//解法二：使用快慢指针；
#if 0
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == nullptr)
			return nullptr;
		if (head->next == nullptr)
			return new TreeNode(head->val);
		return sortedListToBST(head, nullptr);
	}
	TreeNode* sortedListToBST(ListNode* head, ListNode* end)
	{
		if (head == end)
			return nullptr;
		//先使用快慢指针找到中间元素；
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != end && fast->next != end)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		TreeNode* root = new TreeNode(slow->val);
		//构建左半部分；
		root->left = sortedListToBST(head, slow);
		//构建右半部分；
		root->right = sortedListToBST(slow->next, end);
		return root;
	}

};
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head, ListNode *stop = nullptr) {
		if (!head || head == stop) return nullptr;
		auto mid = get_mid(head, stop);
		auto rt = new TreeNode(mid->val);
		if (head == mid) return rt;
		rt->left = sortedListToBST(head, mid);
		rt->right = sortedListToBST(mid->next, stop);
		return rt;
	}
	ListNode *get_mid(ListNode *head, ListNode *stop = nullptr) {
		auto f = head, s = head;
		while (f != stop && f->next != stop) {
			f = f->next->next;
			s = s->next;
		}
		return s;
	}
};

#endif

//解法三：中序遍历模拟
#if 0
class Solution {
public:
	ListNode* _root;
	TreeNode* sortedListToBST(int start, int end)
	{
		if (start>end)
			return nullptr;
		int mid = start + (end - start) / 2;
		TreeNode* left = sortedListToBST(start, mid - 1);
		TreeNode* root = new TreeNode(_root->val);
		_root = _root->next;
		root->left = left;
		root->right = sortedListToBST(mid + 1, end);
		return root;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		int count = 0;
		for (ListNode* temp = head; temp; ++count, temp = temp->next);
		_root = head;
		return sortedListToBST(0, count - 1);
	}
};

#endif