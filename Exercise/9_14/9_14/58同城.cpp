#include <iostream>
#include <vector>
#include <map>
using namespace std;

void SetZero(vector<vector<int>>& Map, int row, int col)
{
	if (row<0 || col <0 || row >= Map.size() || col >= Map[0].size())
		return;
	if (Map[row][col] == 0)
		return;
	Map[row][col] = 0;
	SetZero(Map, row + 1, col);
	SetZero(Map, row - 1, col);
	SetZero(Map, row, col + 1);
	SetZero(Map, row, col - 1);
}
int main()
{
	int n = 0, m = 0;
	int res = 0;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m,0);
	for (int i = 0; i < n * m; ++i)
		cin >> arr[i/m][i%m];
	for (int i = 0; i < n; ++i)
		for(int j = 0; j < m;++j)
			if (arr[i][j])
			{
				DFS(arr,i,j);
				res++;
			}
	cout << res << endl;
}	


int firstMissingPositive(int* nums, int numsLen) {
	// write code here
	map<int, bool> um;
	for (int i = 0; i < numsLen; ++i)
		um[nums[i]] = true;
	for (int i = 0; i < numsLen; ++i)
		if (!nums[i])
			return i;
	return numsLen + 1;
}
int main()
{
	
	int m = 0, n = 0;
	int res = 0;
	cin >> m >> n;
	vector<vector<int>> Map(m, vector<int>(n, 0));
	for (int i = 0; i < n * m; ++i)
		cin >> Map[i / n][i % n];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (Map[i][j])
			{
		res++;
		SetZero(Map, i, j);
			}
	cout << res << endl;
	
	int a[5] = {1,-1,2,5,4};
	firstMissingPositive(a, 5);
	return 0;
}
