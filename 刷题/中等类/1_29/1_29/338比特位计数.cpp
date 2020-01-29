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


//思路：
//数字要么是奇数，要么是偶数：所以：
//奇数：二进制表示中，奇数一定比前面那个偶数多一个 1，因为多的就是最低位的 1。
//偶数：二进制表示中，偶数中 1 的个数一定和除以 2 之后的那个数一样多。因为最低位是 0，除以 2 就是右移一位，也就是把那个 0 抹掉而已，所以 1 的个数是不变的。


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




//NB解法：https://leetcode-cn.com/problems/counting-bits/solution/bi-te-wei-ji-shu-by-leetcode/
