//二分查找法
#if 0
class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		int l = 0, r = A.size() - 1;
		while (l<r)
		{
			int mid = l + (r - l) / 2;
			if (A[mid]<A[mid + 1])
				l = mid + 1;
			else
				r = mid;
		}
		return l;
	}
};
#endif
//遍历法
#if 0
class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		int i = 0;
		while(A[i]<A[i+1])
			i++;
		return i;
	}
};
#endif