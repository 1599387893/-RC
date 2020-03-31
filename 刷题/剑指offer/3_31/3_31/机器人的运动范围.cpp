class Solution {
public:
	int M, N, K;
	vector<vector<int>> arr;
	int CountStep(int row, int col)
	{
		if (row<0 || col <0 || row >= M || col >= N || arr[row][col] == 1)
			return 0;
		if ((row % 10 + row / 10 + col % 10 + col / 10) > K)
			return 0;
		arr[row][col] = 1;
		return 1 + CountStep(row + 1, col) + CountStep(row - 1, col) + CountStep(row, col + 1) + CountStep(row, col - 1);
	}
	int movingCount(int m, int n, int k) {
		M = m;
		N = n;
		K = k;
		arr.resize(m, vector<int>(n, 0));
		return CountStep(0, 0);
	}
};