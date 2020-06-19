#if 0
class Solution {
public:
	void combine(vector<vector<int>>& res, vector<int>& arr, int n, int k, int level)
	{
		if (arr.size() == k)
		{
			res.push_back(arr);
			return;
		}
		if (level > n)
			return;
		//选择该元素
		arr.push_back(level);
		combine(res, arr, n, k, level + 1);
		//不选择该元素
		arr.pop_back();
		combine(res, arr, n, k, level + 1);
	}
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> arr;
		combine(res, arr, n, k, 1);
		return res;
	}
};
#endif

#if 0
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i;
			else if (i == k - 1) result.push_back(p);
			else {
				++i;
				p[i] = p[i - 1];
			}
		}
		return result;
	}
};

#endif


#if 0
class Solution {
public:
	vector<int> temp; // 作用相当于索引

	bool IsKBit(vector<int>& res, int num, int k, int n)
	{
		res.clear();
		for (int i = 0; i < n; ++i)
		{
			if ((1 << i)&num)//若该二进制位为1，将该二进制位上的元素保存到结果中
				res.push_back(temp[i]);
			if (res.size()>k) //当结果的元素个数超出要求时，直接返回
				return false;
		}
		if (res.size() != k)
			return false;
		return true;
	}
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ret;
		for (int i = 1; i <= n; ++i)
			temp.push_back(i);
		int subsize = pow(2, n);
		vector<int> res;//用来保存每一次的结果
		for (int i = 0; i < subsize; ++i)
			if (IsKBit(res, i, k, n))//若结果符合要求，将结果保存到结果集中
				ret.push_back(res);
		return ret;
	}
};
#endif