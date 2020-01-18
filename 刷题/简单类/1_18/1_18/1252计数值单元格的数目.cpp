#if 0
class Solution {
public:
	int oddCells(int n, int m, vector<vector<int>>& indices) {
		vector<vector<int>> ret;
		ret.resize(n, vector<int>(m, 0));
		//for(auto i = 0;i < n;++i)
		//   ret[i].resize(m,0);
		int row, col;
		for (int i = 0; i < indices.size(); ++i)
		{
			row = indices[i][0];
			col = indices[i][1];
			for (auto j = 0; j < m; ++j)
				ret[row][j]++;
			for (auto j = 0; j < n; ++j)
				ret[j][col]++;
		}
		int count = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (ret[i][j] % 2 == 1)
					count++;
		return count;
	}
};
#endif

#include<vector>
using namespace std;
class Solution {
public:
	int oddCells(int n, int m, vector<vector<int>>& indices) {
		int count = 0;
		vector<int> row(n);
		vector<int> col(m);
		for (auto ind : indices)
		{
			row[ind[0]]++;
			col[ind[1]]++;
		}
		for (auto i = 0; i < n; ++i)
			for (auto j = 0; j < m; ++j)
				if ((row[i] + col[j]) % 2 != 0)
					count++;
		return count;
	}
};