#if 0
class Solution {
public:
	int clumsy(int N) {
		int res = 0;
		int temp = N;
		for (int i = N - 1; i >= 1; --i)
		{
			int cur = N - i;
			if (cur % 4 == 0)
			{
				res += temp;
				temp = -i;
			}
			else if (cur % 4 == 1)
				temp *= i;
			else if (cur % 4 == 2)
				temp /= i;
			else
				temp += i;
		}
		res += temp;
		return res;
	}
};



class Solution {
public:
	int clumsy1(int N) {
		int res = 0;
		int temp = N;
		for (int i = 1; i < N; ++i)
		{
			int cur = N - i;
			if (i % 4 == 0)
			{
				res += temp;
				temp = -cur;
			}
			else if (i % 4 == 1)
				temp *= cur;
			else if (i % 4 == 2)
				temp /= cur;
			else
				temp += cur;
		}
		res += temp;
		return res;
	}
};

#endif