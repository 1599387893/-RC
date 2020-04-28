//有两个数字出现了一次，其他的数字都出现了两次

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


//一个数字出现了一次，其他数字出现了三次

//1.使用map记录每个数字出现的次数
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
//2.位运算
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

//3.通用算法(一个数字出现一次，其他数字出现K次)
//对于nums中的所有元素，相同位上的和是3N或者3N+1；(当题目变成K次时，为K*N或者K*N+1)
//3N表示；出现一次的元素(结果)，在该二进制位上为0；
//3N+1表示：出现一次的元素(结果)，在该二进制位上为1；
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
			if (cnt % 3) //出现K次的话，使用cnt % k
				ret |= mask;
		}
		return ret;
	}
};