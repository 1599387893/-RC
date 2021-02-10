#ifdef x
class Solution {
public:
	int hammingDistance(int x, int y) {
		int count = 0;
		while (x || y)
		{
			if ((x & 1) != (y & 1))
				count++;
			x = x >> 1;
			y = y >> 1;
		}
		return count;
	}
};

class Solution {
public:
	int hammingDistance(int x, int y) {
		int count = 0;
		x = x ^ y;
		while (x)
		{
			if (x & 1)
				count++;
			x = x >> 1;
		}
		return count;
	}
};

class Solution {
public:
	int hammingDistance(int x, int y) {
		int count = 0;
		x = x ^ y;
		while (x)
		{
			count++;
			x = x & (x - 1);
		}
		return count;
	}
};
#endif