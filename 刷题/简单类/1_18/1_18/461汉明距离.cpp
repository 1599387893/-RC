#if 0
class Solution {
public:
	int hammingDistance(int x, int y) {
		int count = 0;
		for (int i = 0; i < 32; ++i)
			if (((x >> i) & 1) ^ ((y >> i) & 1))
				count++;
		return count;
	}
};
class Solution {
public:
	int hammingDistance(int x, int y) {
		int i = x ^ y;
		int count = 0;
		while (i)
		{
			count++;
			i &= (i - 1);
		}
		return  count;
	}
};
#endif
