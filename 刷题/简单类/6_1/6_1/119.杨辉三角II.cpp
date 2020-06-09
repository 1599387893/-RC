class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res{ 1 };
		vector<int> temp{ 1, 1 };
		if (rowIndex == 0) return res;
		if (rowIndex == 1) return temp;
		for (int i = 1; i <= rowIndex; ++i)
		{
			res = temp;
			for (int j = 1; j < i; ++j)
				temp[j] = res[j - 1] + res[j];
			temp.push_back(1);
		}
		return temp;
	}
};