class Solution {
public:
	int sumNums(int n) {
		n && (n += sumNums(n - 1));
		return n;
	}
};


class Solution {
public:
	int sumNums(int n) {
		return ((int)pow(n, 2) + n) >> 1;
	}
};