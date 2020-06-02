//�ݹ飺
class Solution {
public:
	int sumNums(int n) {
		if (n == 0) return 0;
		return n + sumNums(n - 1);
	}
};
class Solution {
public:
	int sumNums(int n) {
		n && (n += sumNums(n - 1));
		return n;
	}
};