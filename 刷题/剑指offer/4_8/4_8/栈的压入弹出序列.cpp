#if 0
class Solution {
public:
	//��ѹջ��Ԫ�ذ�˳��ѹ�븨��ջ��
	//������ջ��ջ��Ԫ�غͳ�ջ�����е�posλ��Ԫ����ȣ�����Ԫ�ص�����pos����
	//�����ж�pos�Ƿ�ָ���ջ���е�mowing���ɣ�
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