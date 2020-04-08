#if 0
class Solution {
public:
	//将压栈的元素按顺序压入辅助栈种
	//当辅助栈的栈顶元素和出栈序列中的pos位的元素相等，将该元素弹出，pos后移
	//最终判断pos是否指向出栈序列的mowing即可；
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (pushed.size() != popped.size())
			return false;
		stack<int> temp;
		int pos = 0;
		for (int i = 0; i < pushed.size(); ++i)
		{
			temp.push(pushed[i]);
			while (!temp.empty() && pos < popped.size() && temp.top() == popped[pos])
			{
				temp.pop();
				pos++;
			}
		}
		return temp.empty();
	}
};
#endif