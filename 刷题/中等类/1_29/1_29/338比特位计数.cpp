#if 0
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res{ 0 };
		int count = 0;
		int  temp = 0;
		for (int i = 1; i <= num; ++i)
		{
			temp = i;
			while (temp)
			{
				count++;
				temp &= (temp - 1);
			}
			res.push_back(count);
			count = 0;
		}
		return res;
	}
};
#endif


//˼·��
//����Ҫô��������Ҫô��ż�������ԣ�
//�����������Ʊ�ʾ�У�����һ����ǰ���Ǹ�ż����һ�� 1����Ϊ��ľ������λ�� 1��
//ż���������Ʊ�ʾ�У�ż���� 1 �ĸ���һ���ͳ��� 2 ֮����Ǹ���һ���ࡣ��Ϊ���λ�� 0������ 2 ��������һλ��Ҳ���ǰ��Ǹ� 0 Ĩ�����ѣ����� 1 �ĸ����ǲ���ġ�


#if 0
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res(num + 1);
		res[0] = 0;
		for (int i = 1; i <= num; ++i)
		{
			if (i % 2 == 1)
				res[i] = res[i - 1] + 1;
			else
				res[i] = res[i / 2];
		}
		return res;

	}
};
#endif




//NB�ⷨ��https://leetcode-cn.com/problems/counting-bits/solution/bi-te-wei-ji-shu-by-leetcode/
