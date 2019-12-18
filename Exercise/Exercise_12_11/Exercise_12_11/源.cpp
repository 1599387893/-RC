#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#if 0
int minimumTotal(vector<vector<int> > &triangle) {
	for (size_t i = 1; i < triangle.size(); ++i)
	{
		triangle[i][0] += triangle[i - 1][0];
		triangle[i][i] += triangle[i - 1][i - 1];
	}
	for (size_t i = 2; i < triangle.size(); ++i)
	{
		for (size_t j = 1; j < triangle[i].size(); ++j)
			triangle[i][j] += min(triangle[i][j-1], triangle[i - 1][j - 1]);
	}
	int ret = triangle[triangle.size() - 1][0];
	for (size_t i = 1; i < triangle[triangle.size() - 1].size(); ++i)
		if (ret > triangle[triangle.size() - 1][i])
			ret = triangle[triangle.size() - 1][i];
	return ret;

}

int minPathSum(vector<vector<int> > &grid) {
	int raw = grid.size();
	int col = grid[0].size();
	for (int i = 1; i < raw; ++i)
		grid[0][i] += grid[0][i - 1];
	for (int i = 1; i < col; ++i)
		grid[i][0] += grid[i - 1][0];
	for (int i = 1; i<raw; ++i)
	{
		for (int j = 1; j <col; ++j)
			grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
	}
	return grid[raw - 1][col - 1];
}
#endif
int minimumTotal(vector<vector<int> > &v) {
	for (int i = v.size() - 2; i >= 0; --i){
		for (int j = 0; j < v[i].size(); ++j){
			v[i][j] += min(v[i + 1][j],v[i + 1][j + 1]);
		}
	}
	return v[0][0];
}
int main()
{
	vector<vector<int>> v = {{1}, { -5, -2}, { 3, 6, 1}, { -1, 2, 4, -3 }};
	cout << minimumTotal(v) << endl;
	//cout<<minPathSum(v) << endl;
	system("pause");
	return 0;
}