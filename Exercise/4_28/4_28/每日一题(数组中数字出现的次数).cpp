//���������ֳ�����һ�Σ����������ֶ�����������

class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int temp = 0, pos = 0;
		vector<int> res(2);
		for (const auto a : nums)
			temp ^= a;
		while (!((temp >> pos) & 1))
			pos++;
		for (auto a : nums)
		{
			if (a >> pos & 1)
				res[0] ^= a;
			else
				res[1] ^= a;
		}
		return res;
	}
};


//һ�����ֳ�����һ�Σ��������ֳ���������

//1.ʹ��map��¼ÿ�����ֳ��ֵĴ���
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		map<int, int> m;
		int res = 0;
		for (auto a : nums)
			m[a]++;
		for (auto it = m.begin(); it != m.end(); ++it)
			if ((*it).second == 1)
			{
			res = (*it).first;
			break;
			}
		return res;
	}
};
//2.λ����
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int one = 0, two = 0;
		for (auto a : nums)
		{
			one = one ^ a & ~two;
			two = two ^ a & ~one;
		}
		return one;
	}
};

//3.ͨ���㷨(һ�����ֳ���һ�Σ��������ֳ���K��)
//����nums�е�����Ԫ�أ���ͬλ�ϵĺ���3N����3N+1��(����Ŀ���K��ʱ��ΪK*N����K*N+1)
//3N��ʾ������һ�ε�Ԫ��(���)���ڸö�����λ��Ϊ0��
//3N+1��ʾ������һ�ε�Ԫ��(���)���ڸö�����λ��Ϊ1��
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (int i = 0; i < 32; ++i)
		{
			int mask = 1 << i;
			int cnt = 0;
			for (int j = 0; j < nums.size(); ++j)
				if (nums[j] & mask)
					cnt++;
			if (cnt % 3) //����K�εĻ���ʹ��cnt % k
				ret |= mask;
		}
		return ret;
	}
};