#if 0
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		int left = 0, right = 1;
		while (left < A.size() && right < A.size())
		{
			//找到第一个在偶数位上是奇数的值
			while (left < A.size() && A[left] % 2 == 0)
				left += 2;
			//找到第一个在奇数位上是偶数的值
			while (right < A.size() && A[right] % 2 == 1)
				right += 2;
			if (left < A.size() && right < A.size())
				swap(A[left], A[right]);
		}
		return A;
	}
};
#endif