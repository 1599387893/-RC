#if 0
class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		int count = 0;
		vector<int> col, row;
		for (int i = 0; i < grid.size(); ++i)
		{
			int maxrow = -1;
			int maxcol = -1;
			//确定每行的最大值；
			for (int j = 0; j < grid[i].size(); ++j)
				if (maxrow<grid[i][j])
					maxrow = grid[i][j];
			row.push_back(maxrow);
			//确定每列的最大值；
			for (int j = 0; j < grid.size(); ++j)
				if (maxcol<grid[j][i])
					maxcol = grid[j][i];
			col.push_back(maxcol);
		}
		for (int i = 0; i < row.size(); ++i)
		{
			for (int j = 0; j < col.size(); ++j)
				count += (min(row[i], col[j]) - grid[i][j]);
		}
		return count;
	}
};
#endif