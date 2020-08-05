class Solution {
public:
	bool isUgly(int num) {
		if (num == 1) return true;
		while (num % 5 == 0)
			num /= 5;
		while (num % 3 == 0)
			num /= 3;
		while (num % 2 == 0)
			num >>= 1;
		return num == 1;
	}
};

class Solution {
public:
	bool isUgly(int num) {
		if (num == 1) return true;
		while (num != 1)
		{
			if (num % 2 == 0) num >>= 1;
			else if (num % 3 == 0) num /= 3;
			else if (num % 5 == 0) num /= 5;
			else return false;
		}
		return true;
	}
};