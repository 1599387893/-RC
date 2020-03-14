#if 0
class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& A) {
		int sum = 0;
		int part = 0, count = 0;
		for (int i = 0; i < A.size(); ++i)
			sum += A[i];
		if (sum % 3 != 0)
			return false;

		for (int i = 0; i < A.size(); ++i)
		{
			part += A[i];
			if (part == sum / 3)
			{
				part = 0;
				count++;
			}
		}
		return count == 3 || (count>3 && sum == 0);
	}
};
#endif


#if 0
class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& A) {
		int sum = 0;
		int part = 0, count = 0;
		for (int i = 0; i < A.size(); ++i)
			sum += A[i];
		if (sum % 3 != 0)
			return false;
		sum /= 3;
		if (sum == 0) count--; //防止【1，-1，1，-1】这种情况的发生  
		for (int i = 0; i < A.size(); ++i)
		{
			part += A[i];
			if (part == sum)
			{
				count++;
				if (count == 2) return true;
				part = 0;
			}
		}
		return false;
	}
};

static const auto _ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
#endif