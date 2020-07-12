class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		if (grid.empty()) return 0;
		int res = 0;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[i].size(); ++j)
			{
				if (grid[i][j])
				{
					if (i == 0 || !grid[i - 1][j]) res++;
					if (j == 0 || !grid[i][j - 1]) res++;
				}
			}
		}
		return res * 2;
	}
};
class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		if (grid.empty()) return 0;
		int res = 0;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[i].size(); ++j)
			{
				if (grid[i][j])
				{
					int count = 4;
					if (i - 1 >= 0 && grid[i - 1][j])
						count--;
					if (i + 1<grid.size() && grid[i + 1][j])
						count--;
					if (j - 1 >= 0 && grid[i][j - 1])
						count--;
					if (j + 1<grid[i].size() && grid[i][j + 1])
						count--;
					res += count;
				}
			}
		}
		return res;
	}
};