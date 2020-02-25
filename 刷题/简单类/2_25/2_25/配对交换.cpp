#if 0
class Solution {
public:
	int exchangeBits(int num) {
		int first = 0, second = 0;
		for (int i = 0; i < 32; i += 2)
		{
			first = num >> i & 1;
			second = num >> i + 1 & 1;
			if (first != second)
			{
				if (first == 1)
				{
					num -= 1 << i;
					num += 1 << (i + 1);
				}
				else
				{
					num -= 1 << (i + 1);
					num += 1 << i;
				}
			}
		}
		return num;
	}
};
#endif

#if 0
class Solution {
public:
	int exchangeBits(int num) {
		int odd = num & 0x55555555;
		int even = num & 0xaaaaaaaa;
		odd <<= 1;
		even >>= 1;
		return odd | even;
	}
};
#endif