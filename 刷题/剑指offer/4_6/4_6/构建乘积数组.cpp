class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		vector<int> res;
		if (a.empty())
			return res;
		res.resize(a.size());
		int temp = 1;
		for (int i = 0; i < a.size(); ++i)
		{
			res[i] = temp;
			temp *= a[i];
		}
		temp = 1;
		for (int i = a.size() - 1; i >= 0; --i)
		{
			res[i] *= temp;
			temp *= a[i];
		}
		return res;
	}
};

class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		vector<int> L(a.size(), 1);
		vector<int> R(a.size(), 1);
		for (int i = 1; i<a.size(); ++i)
			L[i] = L[i - 1] * a[i - 1];
		for (int i = a.size() - 2; i >= 0; --i)
			R[i] = R[i + 1] * a[i + 1];
		for (int i = 0; i < a.size(); ++i)
			L[i] *= R[i];
		return L;
	}
};