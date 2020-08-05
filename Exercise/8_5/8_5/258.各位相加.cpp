class Solution {
public:
	int addDigits(int num) {
		int temp = 0;
		while (num > 9)
		{
			temp = 0;
			while (num)
			{
				temp += num % 10;
				num /= 10;
			}
			num = temp;
		}
		return num;
	}
};


//下面这两种解法使用了  数根的原理：
//连续自然数的数根是连续循环的，从1到9的循环

class Solution {
public:
	int addDigits(int num) {
		if (num > 9)
		{
			num %= 9;
			if (num == 0)
				return 9;
		}
		return num;
	}
};


class Solution {
public:
	int addDigits(int num) {
		return (num - 1) % 9 + 1;
	}
};