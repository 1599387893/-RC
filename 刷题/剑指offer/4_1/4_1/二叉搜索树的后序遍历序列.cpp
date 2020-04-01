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
		//�ж����ڵó�����������Ԫ���Ƿ���϶����ڸ��ڵ��������
		for (int i = left; i<end; ++i)
			if (root>postorder[i])
				return false;
		return Judge(postorder, begin, left - 1) && Judge(postorder, left, end - 1);
	}
	bool verifyPostorder(vector<int>& postorder) {
		//���ö��������������ԣ�
		//���Ϊ�������֣����������䣬���������䣬���ڵ����䣻
		//1.����������һ���ڵ���Ϊ���ڵ㣻
		//2.�������ҵ�һ���ȸ��ڵ��Ľڵ�(pos)��
		//3.��pos�ڵ�֮ǰ����Ϊ��������pos�ڵ㵽���ڵ�ǰΪ������
		if (postorder.size() == 0 || postorder.size() == 1)
			return true;
		return Judge(postorder, 0, postorder.size() - 1);
	}
};