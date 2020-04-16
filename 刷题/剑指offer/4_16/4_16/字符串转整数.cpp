class Solution {
public:
	int strToInt(string str) {
		int pos = 0;
		bool flag = true;//�������,Ĭ��Ϊ��
		long res = 0, n = 0;
		//���ҵ���һ���ǿ��ַ���
		while (pos < str.size() && str[pos] == ' ')
			pos++;
		if (pos == str.size())
			return 0;
		//�жϵ�һ����Ч�ַ��ǲ��ǺϷ��ַ�
		if (str[pos] != '+' && str[pos] != '-' && !isdigit(str[pos]))
			return 0;
		if (str[pos] == '+' || str[pos] == '-')
		{
			if (str[pos] == '-')
				flag = false;
			pos++;
		}
		//��������
		while (pos < str.size() && isdigit(str[pos]))
		{
			n = str[pos] - '0';

			//����жϷ���һ��
			if (flag && n + res * 10 > INT_MAX)
				return INT_MAX;
			if (!flag && (-1 * (n + (res * 10)) < INT_MIN))
				return INT_MIN;
			
			//����жϷ����������ַ�������Ҫ��res��Ϊlong����
			/*
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && n>7))
				return (flag ? INT_MAX : INT_MIN);
			*/
			res = res * 10 + n;
			pos++;
		}
		return flag ? res : -1 * res;
	}
};